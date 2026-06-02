// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "CPP_Bullet.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	BulletSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Bullet Spawn Point"));
	BulletSpawnLocation->SetupAttachment(RootComponent);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsShooting)
	{
		SetActorRotation(ShootRot);
	}
	else
	{
		SetActorRotation(MoveRot);
	}
}

float ABaseCharacter::TakeDamage
(
	float DamageAmount,
	struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator,
	AActor* DamageCauser
)
{
	HP -= DamageAmount;

	if (HP <= 0.0f)
	{
		Destroy();
	}

	return DamageAmount;
}

void ABaseCharacter::MoveInDirection(const FVector& Direction, float ScaleValue)
{
	if (Direction.IsNearlyZero())
	{
		return;
	}

	MoveRot = Direction.Rotation();
	AddMovementInput(Direction, MovementSpeed * ScaleValue, false);
}

AActor* ABaseCharacter::ShootBullet(const FVector& Direction)
{
	if (Direction.IsNearlyZero())
	{
		return nullptr;
	}

	ShootRot = Direction.Rotation();

	if (!CanFire)
	{
		return nullptr;
	}

	if (!BulletToSpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("BulletToSpawn is not set on %s"), *GetName());
		return nullptr;
	}

	if (!BulletSpawnLocation)
	{
		UE_LOG(LogTemp, Warning, TEXT("BulletSpawnLocation is missing on %s"), *GetName());
		return nullptr;
	}

	CanFire = false;

	FTimerHandle FireRateTimerHandle;
	GetWorldTimerManager().SetTimer
	(
		FireRateTimerHandle,
		this,
		&ABaseCharacter::ResetCanFire,
		FireRate,
		false
	);

	SetShootingTrue();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = this;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* SpawnedActor = GetWorld()->SpawnActor<ACPP_Bullet>
	(
		BulletToSpawn,
		BulletSpawnLocation->GetComponentLocation(),
		ShootRot,
		SpawnParams
	);

	if (!SpawnedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to spawn bullet on %s"), *GetName());
	}

	FTimerHandle ShootingFalseTimerHandle;
	GetWorldTimerManager().SetTimer
	(
		ShootingFalseTimerHandle,
		this,
		&ABaseCharacter::SetShootingFalse,
		0.2f,
		false
	);

	return SpawnedActor;
}

void ABaseCharacter::SetShootingTrue()
{
	IsShooting = true;
}

void ABaseCharacter::SetShootingFalse()
{
	IsShooting = false;
}

void ABaseCharacter::ResetCanFire()
{
	CanFire = true;
}

FVector ABaseCharacter::CalculateMovementBlending() const
{
	FVector Movement = MoveRot.Vector();
	FVector Shooting = ShootRot.Vector();

	float DotProd = FVector::DotProduct(Movement, Shooting);

	FVector BlendVector = Movement - Shooting * DotProd;

	FVector OutputVector = FVector(DotProd, BlendVector.Length(), 0.0f);
	return OutputVector * 50.0f;
}


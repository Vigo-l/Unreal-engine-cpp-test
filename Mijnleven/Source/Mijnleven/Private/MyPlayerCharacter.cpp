// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"
#include "CPP_Bullet.h"
#include "MijnlevenCharacter.h"
#include "Weapon.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
	// create the spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));

	SpringArm->TargetArmLength = 2000.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.0f;
	
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	// create the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Camera->SetFieldOfView(75.0f);
	
	Weapon = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(),TEXT("HandGrip_R"));
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BulletSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Bullet Spawn Point"));
	BulletSpawnLocation->SetupAttachment(GetMesh());

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AWeapon* weaponpntr = Cast<AWeapon>(Weapon->GetChildActor());
	if (weaponpntr)
	{
		weaponpntr->SetPlayerPointer(this);
	}
	
}

float AMyPlayerCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	HP -= DamageAmount;
	if (HP <= 0)
	{
		Destroy();
	}
	return DamageAmount;
	
	
}


AActor* AMyPlayerCharacter::ShootBullet()
{
	
	SetShootingTrue();
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = this;
	FVector testvelocity = GetActorForwardVector() * BulletSpeed;
	
	AActor* SpawnedActor = GetWorld()->SpawnActor<ACPP_Bullet>(
		BulletToSpawn,
		BulletSpawnLocation->GetComponentLocation(),
		GetActorRotation(),
		SpawnParams );
	
	FTimerHandle timerHandle;
	FTimerDelegate delegate = FTimerDelegate::CreateUObject(this, &AMijnlevenCharacter::SetShootingFalse);
	GetWorldTimerManager().SetTimer(timerHandle, delegate, .2f, false);
	
	return SpawnedActor;
}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

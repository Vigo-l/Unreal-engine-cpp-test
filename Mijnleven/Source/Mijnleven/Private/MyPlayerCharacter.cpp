// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"

#include "CPP_Bullet.h"
#include "Weapon.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

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


AActor* AMyPlayerCharacter::ShootBullet()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = this;
	
	AActor* SpawnedActor = GetWorld()->SpawnActor<ACPP_Bullet>(
		BulletToSpawn,
		BulletSpawnLocation->GetComponentLocation(),
		GetActorRotation(),
		SpawnParams );
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

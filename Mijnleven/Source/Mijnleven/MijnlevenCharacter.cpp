// Copyright Epic Games, Inc. All Rights Reserved.

#include "MijnlevenCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

AMijnlevenCharacter::AMijnlevenCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;


	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AMijnlevenCharacter::BeginPlay()
{
	Super::BeginPlay();

	// stub
}

void AMijnlevenCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	// stub
}

void AMijnlevenCharacter::SetShootingTrue()
{
	IsShooting = true;
}

void AMijnlevenCharacter::SetShootingFalse()
{
	IsShooting =false;
}

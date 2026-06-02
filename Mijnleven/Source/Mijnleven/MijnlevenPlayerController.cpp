// Copyright Epic Games, Inc. All Rights Reserved.

#include "MijnlevenPlayerController.h"
#include "GameFramework/Pawn.h"

#include "Engine/World.h"
#include "EnhancedInputComponent.h"


#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Mijnleven.h"


void AMijnlevenPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<AMyPlayerCharacter>(GetPawn());
}

AMijnlevenPlayerController::AMijnlevenPlayerController()
{
}

void AMijnlevenPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Only set up input on local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}

		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			// Movement bindings
			EnhancedInputComponent->BindAction(MovementInput, ETriggerEvent::Triggered, this, &AMijnlevenPlayerController::Move);
		
			// Shooting bindings
			EnhancedInputComponent->BindAction(ShootInput, ETriggerEvent::Triggered, this, &AMijnlevenPlayerController::FireBullet);
			EnhancedInputComponent->BindAction(ShootInput, ETriggerEvent::Started, this, &AMijnlevenPlayerController::SetShootingTrue);
			EnhancedInputComponent->BindAction(ShootInput, ETriggerEvent::Completed, this, &AMijnlevenPlayerController::SetShootingFalse);
		}
		else
		{
			UE_LOG(LogMijnleven, Error, TEXT("'%s' Failed to find an Enhanced Input Component!"), *GetNameSafe(this));
		}
	}
}

void AMijnlevenPlayerController::Move(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Move(Value);
	}
}

void AMijnlevenPlayerController::FireBullet(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->FireBullet(Value);
	}
}

void AMijnlevenPlayerController::SetShootingTrue()
{
	if (PlayerCharacter)
	{
		PlayerCharacter->SetShootingTrue();
	}
}

void AMijnlevenPlayerController::SetShootingFalse()
{
	if (PlayerCharacter)
	{
		PlayerCharacter->SetShootingFalse();
	}
}


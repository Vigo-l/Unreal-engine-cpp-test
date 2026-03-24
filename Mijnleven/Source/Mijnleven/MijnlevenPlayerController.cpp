// Copyright Epic Games, Inc. All Rights Reserved.

#include "MijnlevenPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "NiagaraFunctionLibrary.h"

#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "Navigation/PathFollowingComponent.h"

#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Mijnleven.h"

AMijnlevenPlayerController::AMijnlevenPlayerController()
{
	speed = 1.0f;
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
			EnhancedInputComponent->BindAction(MovementInput, ETriggerEvent::Triggered, this, &AMijnlevenPlayerController::Move);
		}
		else
		{
			UE_LOG(LogMijnleven, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
		}
	}
}


//Move the character
void AMijnlevenPlayerController::Move(const FInputActionValue &Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>(); //Transform the input action value to a vector 2d
	FVector InputVector = FVector(MovementVector, 0 ); // Transform the vector 2d to a vector 3d for the 3d space

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(InputVector, speed, false); // add the input with the speed to the character movement
	}
}


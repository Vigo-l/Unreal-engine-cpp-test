// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
//#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "MyPlayerCharacter.h"
#include "MijnlevenPlayerController.generated.h"

class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;
class UPathFollowingComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  Player controller for a top-down perspective game.
 *  Implements point and click based controls
 */
UCLASS(abstract)
class AMijnlevenPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	/** MappingContext */
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext; //gets the default input context
	
	UPROPERTY(EditAnywhere, Category="Input") 
	TObjectPtr<UInputAction> MovementInput; //create the movement input that calls the function
	

	UPROPERTY(EditAnywhere, Category="Input") 
	TObjectPtr<UInputAction> ShootInput;
	

	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	/** Set to true if we're using touch input */
	uint32 bIsTouch : 1;

	/** Saved location of the character movement destination */
	FVector CachedDestination;

	/** Time that the click input has been pressed */
	float FollowTime = 0.0f;

public:

	/** Constructor */
	AMijnlevenPlayerController();
	
protected:

	/** Initialize input bindings */
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditAnywhere)
	float speed; // variable to change the speed
	
	void Move(const FInputActionValue &Value);//function that gets called when the move input is triggers

	void FireBullet(const FInputActionValue &Value);
	
	class AMyPlayerCharacter* PlayerCharacter;
};



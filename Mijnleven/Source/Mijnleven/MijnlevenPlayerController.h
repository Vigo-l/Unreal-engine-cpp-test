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
 *  Handles player input and forwards it to the controlled character.
 */
UCLASS(abstract)
class AMijnlevenPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, Category="Input") 
	TObjectPtr<UInputAction> MovementInput;
	
	UPROPERTY(EditAnywhere, Category="Input") 
	TObjectPtr<UInputAction> ShootInput;

public:
	/** Constructor */
	AMijnlevenPlayerController();

protected:
	/** Initialize input bindings */
	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& Value);

	void FireBullet(const FInputActionValue& Value);
	
	class AMyPlayerCharacter* PlayerCharacter;
	
	void SetShootingTrue();

	void SetShootingFalse();
};



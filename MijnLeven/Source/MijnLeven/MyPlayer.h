// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "MyPlayer.generated.h"



UCLASS()
class MIJNLEVEN_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Main Actor camera
	UPROPERTY(EditAnywhere) UCameraComponent* Camera;
	UPROPERTY(EditAnywhere) UStaticMeshComponent* CameraMesh;
	

	

public:
	
	//EnhancedInputAction Mappings
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input") 
	UInputMappingContext * InputMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Enhanced Input")
	UInputAction* inputToMove;
	
	UFUNCTION()
	void EnhancedInputMove(const FInputActionValue& Value);
	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

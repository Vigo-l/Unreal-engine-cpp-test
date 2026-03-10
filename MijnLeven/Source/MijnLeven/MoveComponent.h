// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Movement), meta=(BlueprintSpawnableComponent) )
class MIJNLEVEN_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	//Parameter
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;
	
	//Speed
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f;
	
	
	//Locations
	FVector StartRelativeLocation;
	FVector MoveOffsetNorm;
	float maxDistance = 0.0f;
	float curDistance = 0.0f;
	int moveDirection = 1;
	

		
};

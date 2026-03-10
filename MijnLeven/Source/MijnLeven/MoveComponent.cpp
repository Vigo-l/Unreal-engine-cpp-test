// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set start location
	StartRelativeLocation = GetRelativeLocation();
	
	//Compute normalized movement
	MoveOffsetNorm = MoveOffset;
	MoveOffsetNorm.Normalize();
	maxDistance = MoveOffset.Length();	
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Speed++;
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	curDistance += DeltaTime * Speed * 10 * moveDirection;
	
	if (curDistance > maxDistance || curDistance < 0)
	{
		moveDirection *= -1;
	}

	// Compute and set current location
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * curDistance);
}


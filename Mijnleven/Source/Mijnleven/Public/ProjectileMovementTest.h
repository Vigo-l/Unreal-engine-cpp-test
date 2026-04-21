// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileMovementTest.generated.h"

UCLASS()
class MIJNLEVEN_API AProjectileMovementTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileMovementTest();

protected:
	// Called when the game starts or when spawned
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditDefaultsOnly)
	class UProjectileMovementComponent* projectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

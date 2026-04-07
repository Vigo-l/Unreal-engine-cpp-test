// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"


#include "CPP_Bullet.generated.h"

UCLASS()
class MIJNLEVEN_API ACPP_Bullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Bullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

UPROPERTY(EditAnywhere);
	class UNiagaraComponent* BulletFX;
	UPROPERTY(EditAnywhere);
	class USphereComponent* CollisionSphere;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

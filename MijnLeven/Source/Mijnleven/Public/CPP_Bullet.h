// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MijnlevenPlayerController.h"
#include "Components/SphereComponent.h"




#include "CPP_Bullet.generated.h"

UCLASS()
class MIJNLEVEN_API ACPP_Bullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Bullet();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditDefaultsOnly)
	class UProjectileMovementComponent* projectileMovement;
	
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex,
		bool bFromSweep, 
		const FHitResult& SweepResult);
	
	virtual void BulletHit();
	
	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* ImpactParticles;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

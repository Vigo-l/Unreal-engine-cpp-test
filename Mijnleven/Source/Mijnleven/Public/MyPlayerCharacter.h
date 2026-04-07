
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "GameFramework/Character.h"
#include "MyPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MIJNLEVEN_API AMyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	

	
public:
	// Sets default values for this character's properties
	AMyPlayerCharacter();
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/** Camera boom spring arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Player Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	UChildActorComponent* Weapon;


	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ACPP_Bullet> BulletToSpawn;
	
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* BulletSpawnLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AActor* ShootBullet();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

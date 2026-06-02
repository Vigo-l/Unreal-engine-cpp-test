// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class ACPP_Bullet;

UCLASS()
class MIJNLEVEN_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	) override;

	void MoveInDirection(const FVector& Direction, float ScaleValue = 1.0f);

	AActor* ShootBullet(const FVector& Direction);

	void SetShootingTrue();

	void SetShootingFalse();

	UFUNCTION(BlueprintPure)
	FVector CalculateMovementBlending() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float HP = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float FireRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<ACPP_Bullet> BulletToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	USceneComponent* BulletSpawnLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	bool IsShooting = false;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool CanFire = true;

	UPROPERTY(BlueprintReadOnly, Category = "Rotation")
	FRotator MoveRot;

	UPROPERTY(BlueprintReadOnly, Category = "Rotation")
	FRotator ShootRot;

	UFUNCTION()
	void ResetCanFire();
};

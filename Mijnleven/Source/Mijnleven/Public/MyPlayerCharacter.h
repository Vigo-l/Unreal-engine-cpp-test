
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "MyPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class MIJNLEVEN_API AMyPlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

	

	
public:
	AMyPlayerCharacter();

protected:
	virtual void BeginPlay() override;
	
	/** Camera boom spring arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Player Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	UChildActorComponent* Weapon;

public:	
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value);

	void FireBullet(const FInputActionValue& Value);
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

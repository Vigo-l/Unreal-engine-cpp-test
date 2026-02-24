// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"




// Sets default values
AMyPlayer::AMyPlayer()
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Camera Mesh"));
	
	//Setup Camera
	Camera->FieldOfView = 110.0f;
	Camera-> SetupAttachment(CameraMesh);
	Camera->SetRelativeLocation(FVector(-200.0f,0.0f,0.0f));
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	enhancedInputComponent->BindAction(inputToMove, ETriggerEvent::Triggered, this, &AMyPlayer::EnhancedInputMove);
	

}

void AMyPlayer::EnhancedInputMove(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	
	if (moveVector.X > 0.05f || moveVector.X < -0.05f)
	{
		FVector newLocation = GetActorLocation();
		SetActorLocation(newLocation);
	}
	
	if (moveVector.Y > 0.05f || moveVector.Y < -0.05f)
	{
		FVector newLocation = GetActorLocation();
		SetActorLocation(newLocation);
	}
}




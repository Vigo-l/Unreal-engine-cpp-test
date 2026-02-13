// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

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
	Camera->SetRelativeLocation(FVector(0.0f,0.0f,100.0f));
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
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

}


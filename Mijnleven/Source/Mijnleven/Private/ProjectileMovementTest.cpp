// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileMovementTest.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectileMovementTest::AProjectileMovementTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->ProjectileGravityScale = 0;
	projectileMovement->MaxSpeed = 1000;
	projectileMovement->InitialSpeed = 1000;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComponent);
}

// Called when the game starts or when spawned
void AProjectileMovementTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileMovementTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


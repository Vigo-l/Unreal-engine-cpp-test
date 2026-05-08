// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Bullet.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "kismet/gameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ACPP_Bullet::ACPP_Bullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->ProjectileGravityScale = 0;
	projectileMovement->MaxSpeed = 1000;
	projectileMovement->InitialSpeed = 1000;
	projectileMovement->Velocity = FVector(100,100,100);
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComponent);
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(StaticMeshComponent);

}

// Called when the game starts or when spawned
void ACPP_Bullet::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this,&ACPP_Bullet::BeginOverlap);
	
}

void ACPP_Bullet::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ImpactParticles, GetActorLocation());
	BulletHit();
	AController* PlayerC = GetInstigator()->GetController();
	UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, PlayerC, this, DamageType);
	Destroy();
	
	
}

void ACPP_Bullet::BulletHit()
{
	
}

// Called every frame
void ACPP_Bullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


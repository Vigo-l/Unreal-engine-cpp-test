#include "MyPlayerCharacter.h"
#include "Weapon.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"

AMyPlayerCharacter::AMyPlayerCharacter()
{
	// create the spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));

	SpringArm->TargetArmLength = 2000.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.0f;
	
	// create the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Camera->SetFieldOfView(75.0f);
	
	Weapon = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("HandGrip_R"));

	BulletSpawnLocation->SetupAttachment(GetMesh());
}

void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AWeapon* weaponpntr = Cast<AWeapon>(Weapon->GetChildActor());
	if (weaponpntr)
	{
		weaponpntr->SetPlayerPointer(this);
	}
}

void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	FVector InputVector = FVector(MovementVector, 0.0f);

	MoveInDirection(InputVector);
}

void AMyPlayerCharacter::FireBullet(const FInputActionValue& Value)
{
	FVector Direction = FVector(Value.Get<FVector2D>(), 0.0f);

	if (Direction.IsNearlyZero())
	{
		Direction = GetActorForwardVector();
	}

	ShootBullet(Direction);
}

void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


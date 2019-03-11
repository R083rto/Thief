// Fill out your copyright notice in the Description page of Project Settings.

#include "TECharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TEArrow.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ATECharacter::ATECharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATECharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATECharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATECharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATECharacter::HandleForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATECharacter::HandleRight);

	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &ATECharacter::HandleJump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATECharacter::HandleFire);
	PlayerInputComponent->BindAction("Sneak", IE_Pressed, this, &ATECharacter::HandleSneak);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ATECharacter::HandleRun);

	PlayerInputComponent->BindAction("Disarm", IE_Pressed, this, &ATECharacter::ToggleDisarm);
	PlayerInputComponent->BindAction("Sword", IE_Pressed, this, &ATECharacter::ToggleSword);
	PlayerInputComponent->BindAction("BlackJack", IE_Pressed, this, &ATECharacter::ToggleBlackjack);
	PlayerInputComponent->BindAction("WaterArrow", IE_Pressed, this, &ATECharacter::ToggleWaterArrow);
	PlayerInputComponent->BindAction("MossArrow", IE_Pressed, this, &ATECharacter::ToggleMossArrow);
	PlayerInputComponent->BindAction("DamageArrow", IE_Pressed, this, &ATECharacter::ToggleDamageArrow);
	PlayerInputComponent->BindAction("RopeArrow", IE_Pressed, this, &ATECharacter::ToggleRopeArrow);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void ATECharacter::HandleForward(float Value)
{
	if (Value != 0.f)
	{
		if (GetCharacterMovement()->MovementMode == MOVE_Flying)
		{
			AddMovementInput(GetActorUpVector(), Value);
			return;
		}

		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATECharacter::HandleRight(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ATECharacter::HandleJump()
{
	if (GetCharacterMovement()->MovementMode == MOVE_Flying)
	{
		FVector LadderDash = Controller->GetControlRotation().Vector();
		LadderDash = LadderDash.GetSafeNormal() * GetCharacterMovement()->JumpZVelocity*2;
		LaunchCharacter(LadderDash, false, false);
	}
	ACharacter::Jump();
}

void ATECharacter::HandleFire()
{
	if (WeaponState == ECHOSENWEAPON::Disarm)
		return;
	if (WeaponState == ECHOSENWEAPON::Blackjack || WeaponState == ECHOSENWEAPON::Sword)
		MeleeAttack();
	else
		RangedAttack();
}

void ATECharacter::HandleSneak()
{

}

void ATECharacter::HandleRun()
{

}

void ATECharacter::ToggleSword()
{
	WeaponState = ECHOSENWEAPON::Sword;
}

void ATECharacter::ToggleBlackjack()
{
	WeaponState = ECHOSENWEAPON::Blackjack;
}

void ATECharacter::ToggleWaterArrow()
{
	if (WaterArrows == 0)
		return;
	ChangeWeapon(ECHOSENWEAPON::WaterArrow);
}

void ATECharacter::ToggleMossArrow()
{
	if (MossArrows == 0)
		return;

	ChangeWeapon(ECHOSENWEAPON::MossArrow);
}

void ATECharacter::ToggleDamageArrow()
{
	if (DamageArrows == 0)
		return;

	ChangeWeapon(ECHOSENWEAPON::Disarm);
}

void ATECharacter::ToggleRopeArrow()
{
	if (RopeArrow == 0)
		return;
	ChangeWeapon(ECHOSENWEAPON::RopeArrow);
}

void ATECharacter::ToggleDisarm()
{
	ChangeWeapon(ECHOSENWEAPON::Disarm);
}

void ATECharacter::ChangeWeapon(ECHOSENWEAPON NextWeapon)
{
	WeaponState = NextWeapon;
}

void ATECharacter::MeleeAttack()
{

}

void ATECharacter::RangedAttack()
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	//FVector Direction = GetActorLocation() - PlayerController->PlayerCameraManager->GetCameraRotation();
	GetWorld()->SpawnActor<ATEArrow>(ArrowClass, GetActorLocation(), PlayerController->PlayerCameraManager->GetCameraRotation());
}

ECHOSENWEAPON ATECharacter::GetWeaponState()
{
	return WeaponState;
}
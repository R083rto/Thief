// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TECharacter.generated.h"

UENUM()
enum class ECHOSENWEAPON : uint8
{
	Disarm,
	WaterArrow,
	MossArrow,
	DamageArrow,
	RopeArrow,
	Blackjack,
	Sword
};


UCLASS()
class THIEF_API ATECharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATECharacter();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ATEArrow> ArrowClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ECHOSENWEAPON GetWeaponState();
private:

	int32 WaterArrows = 10;
	int32 DamageArrows = 10;
	int32 MossArrows = 10;
	int32 RopeArrow = 10;

	ECHOSENWEAPON WeaponState = ECHOSENWEAPON::Disarm;

	void HandleForward(float Value);
	void HandleRight(float Value);
	void HandleJump();
	void HandleFire();
	void HandleSneak();
	void HandleRun();

	void ToggleSword();
	void ToggleBlackjack();
	void ToggleWaterArrow();
	void ToggleMossArrow();
	void ToggleDamageArrow();
	void ToggleRopeArrow();
	void ToggleDisarm();

	void ChangeWeapon(ECHOSENWEAPON NextWeapon);
	void MeleeAttack();
	void RangedAttack();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TEAI.generated.h"


UCLASS()
class THIEF_API ATEAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATEAI();

	UPROPERTY(EditAnywhere, Category = Behavior)
	class UBehaviorTree* BotBehavior;

	UPROPERTY(EditInstanceOnly, Meta = (MakeEditWidget = true))
	class ATEPatrolPath* PatrolPath;

	UPROPERTY(EditAnywhere)
	float WaitTime = 1.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

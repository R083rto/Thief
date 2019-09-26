// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TEReddickAI.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API ATEReddickAI : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	class UBlackboardComponent* BlackboardComp;

	UPROPERTY(Transient)
		class UBehaviorTreeComponent* BehaviorComp; 
public:
	ATEReddickAI();

	virtual void Possess(APawn* InPawn) override;

	uint8 EnemyID;
};

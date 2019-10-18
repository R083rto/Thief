// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_InRange.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API UBTDecorator_InRange : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	//virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BB_Target;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	float Distance;
};

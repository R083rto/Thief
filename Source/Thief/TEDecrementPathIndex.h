// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TEDecrementPathIndex.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API UTEDecrementPathIndex : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector BB_Direction;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector BB_PathIndex;
};

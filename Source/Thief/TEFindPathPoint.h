// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TEFindPathPoint.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API UTEFindPathPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UTEFindPathPoint();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BB_PathVector;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BB_PathIndex;
};

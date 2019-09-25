// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TELoopPath.generated.h"

UCLASS()
class THIEF_API UTELoopPath : public UBTTaskNode
{
	GENERATED_BODY()
public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BB_Looping;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BB_PathIndex;
};

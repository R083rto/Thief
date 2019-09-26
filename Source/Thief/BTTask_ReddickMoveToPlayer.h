// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ReddickMoveToPlayer.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API UBTTask_ReddickMoveToPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
};

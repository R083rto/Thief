// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TETestTask.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API UTETestTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent & OwnerComp,uint8 * NodeMemory);

	
};

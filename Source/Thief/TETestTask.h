// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "TETestTask.generated.h"

UCLASS()
class THIEF_API UTETestTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UTETestTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;



};


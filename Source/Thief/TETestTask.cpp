// Fill out your copyright notice in the Description page of Project Settings.

#include "TETestTask.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "TEAIController.h"

UTETestTask::UTETestTask()
{

}

EBTNodeResult::Type UTETestTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UBehaviorTreeComponent* MyComp = &OwnerComp;
	ATEAIController* MyController = MyComp ? Cast<ATEAIController>(MyComp->GetOwner()) : NULL;
	if (MyController)
	{
		return EBTNodeResult::Failed;
	}
	UE_LOG(LogTemp,Warning, TEXT("it works! IT WORKS!!!"));
	return EBTNodeResult::Succeeded;
}


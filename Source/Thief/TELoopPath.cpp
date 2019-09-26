// Fill out your copyright notice in the Description page of Project Settings.

#include "TELoopPath.h"
#include "TEAIController.h"
#include <BehaviorTree/BehaviorTreeComponent.h>
#include <BehaviorTree/BlackboardComponent.h>

EBTNodeResult::Type UTELoopPath::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* MyBlackBoard = OwnerComp.GetBlackboardComponent();
	if (MyBlackBoard->GetValueAsBool(BB_Looping.SelectedKeyName))
	{
		MyBlackBoard->SetValueAsInt(BB_Direction.SelectedKeyName, 1);
		MyBlackBoard->SetValueAsInt(BB_PathIndex.SelectedKeyName, 0);
		UE_LOG(LogTemp, Warning, TEXT("reset to 0 in loop path"));
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}

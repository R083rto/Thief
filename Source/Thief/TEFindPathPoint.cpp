// Fill out your copyright notice in the Description page of Project Settings.

#include "TEFindPathPoint.h"
#include "TEAIController.h"
#include "TEAI.h"
#include <BehaviorTree/BlackboardComponent.h>
#include "TEPatrolPath.h"
#include "GameFramework/Actor.h"


UTEFindPathPoint::UTEFindPathPoint()
{

}

EBTNodeResult::Type UTEFindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* MyComp = &OwnerComp;
	ATEAIController* MyController = MyComp ? Cast<ATEAIController>(MyComp->GetOwner()) : NULL;
	if (MyController)
	{
		ATEAI* MyPawn = MyController ? Cast<ATEAI>(MyController->GetPawn()) : NULL;
		if (MyPawn)
		{
			UBlackboardComponent* MyBlackBoard = OwnerComp.GetBlackboardComponent();
			int PathIndex = MyBlackBoard->GetValueAsInt(BB_PathIndex.SelectedKeyName);
			ATEPatrolPath* PatrolPath = Cast<ATEPatrolPath>(MyPawn->PatrolPath);
			FVector NewLocation = PatrolPath->GetActorLocation() * PatrolPath->GetPatrolPoint(PathIndex);
			MyBlackBoard->SetValueAsVector(BB_PathVector.SelectedKeyName,NewLocation);

			return EBTNodeResult::Succeeded;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No pawn or pawn not deriving from correct class"));
			return EBTNodeResult::Failed;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No controller or controller not deriving from correct class"));
		return EBTNodeResult::Failed;
	}
}

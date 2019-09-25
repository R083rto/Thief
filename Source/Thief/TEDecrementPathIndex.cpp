// Fill out your copyright notice in the Description page of Project Settings.
#include "TEDecrementPathIndex.h"
#include "TEFindPathPoint.h"
#include "TEAIController.h"
#include "TEAI.h"
#include <BehaviorTree/BlackboardComponent.h>
#include "TEPatrolPath.h"
#include "GameFramework/Actor.h"

EBTNodeResult::Type UTEDecrementPathIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* MyComp = &OwnerComp;
	ATEAIController* MyController = MyComp ? Cast<ATEAIController>(MyComp->GetOwner()) : NULL;

	if (MyController)
	{
		UBlackboardComponent* MyBlackBoard = OwnerComp.GetBlackboardComponent();
		int Direction = MyBlackBoard->GetValueAsInt(BB_Direction.SelectedKeyName);

		//Check if this script is moving the ai in correct direction
		if (Direction == -1)
		{
			ATEAI* MyPawn = MyController ? Cast<ATEAI>(MyController->GetPawn()) : NULL;

			if (MyPawn)
			{
				int PathIndex = MyBlackBoard->GetValueAsInt(BB_PathIndex.SelectedKeyName);
				ATEPatrolPath* PatrolPath = Cast<ATEPatrolPath>(MyPawn->PatrolPath);

				//check if at end off the path so i know if i can continue or turn back
				if (PathIndex + 1 >= 0)
				{
					MyBlackBoard->SetValueAsInt(BB_Direction.SelectedKeyName, -1);
					MyBlackBoard->SetValueAsInt(BB_PathIndex.SelectedKeyName, PathIndex - 1);
					return EBTNodeResult::Succeeded;
				}
				else
				{
					MyBlackBoard->SetValueAsInt(BB_Direction.SelectedKeyName, 1);
					return EBTNodeResult::Failed;
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("No pawn or pawn not deriving from correct class"));
				return EBTNodeResult::Failed;
			}
		}
		else
		{
			return EBTNodeResult::Failed;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No controller or controller not deriving from correct class"));
		return EBTNodeResult::Failed;
	}
}

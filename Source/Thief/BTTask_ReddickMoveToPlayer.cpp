// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_ReddickMoveToPlayer.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "TEReddickAI.h"
#include "ReddickCharacter.h"
#include "TECharacter.h"

EBTNodeResult::Type UBTTask_ReddickMoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ATEReddickAI* EnemyPC = Cast<ATEReddickAI>(OwnerComp.GetAIOwner());

	ATECharacter* Player = Cast<ATECharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyID));

	if (EnemyPC)
	{
		EnemyPC->MoveToActor(Player, 5.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}

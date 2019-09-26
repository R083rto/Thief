// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_ReddickCheckForPlayer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "TECharacter.h"
#include "ReddickCharacter.h"
#include "TEReddickAI.h"
#include "Engine/World.h"
#include <BehaviorTree/BTNode.h>

UBTService_ReddickCheckForPlayer::UBTService_ReddickCheckForPlayer()
{
	bCreateNodeInstance = true;
}

void UBTService_ReddickCheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ATEReddickAI * EnemyPC = Cast<ATEReddickAI>(OwnerComp.GetAIOwner());

	if (EnemyPC)
	{
		ATECharacter* Player = Cast<ATECharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

		if (Player)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyID,Player);
		}
	}
}

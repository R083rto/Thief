// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_HasTarget.h"
#include <BehaviorTree/BehaviorTreeTypes.h>
#include <GameFramework/Controller.h>
#include "GameFramework/Actor.h"
#include "AIController.h"
#include <BehaviorTree/BlackboardComponent.h>

bool UBTDecorator_HasTarget::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (OwnerComp.GetBlackboardComponent()->GetValueAsObject(BB_Target.SelectedKeyName))
	{
		return true;
	}
	else
	{

		return false;
	}
}

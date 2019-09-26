// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_ReddickCheckForPlayer.generated.h"

/**
 * 
 */
UCLASS()
class THIEF_API UBTService_ReddickCheckForPlayer : public UBTService
{
	GENERATED_BODY()
	

public:

	UBTService_ReddickCheckForPlayer();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TEAIController.generated.h"


UCLASS()
class THIEF_API ATEAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	ATEAIController();

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behaviour;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAIPerceptionComponent* AIPerception = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAISenseConfig_Sight* Sight = nullptr;

	virtual void BeginPlay() override;
};

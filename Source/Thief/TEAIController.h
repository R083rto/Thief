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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAIPerceptionComponent* AIPerception = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAISenseConfig_Sight* Sight = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAISenseConfig_Hearing* Hearing = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	UBehaviorTree* Behaviour;

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	FName LoopName = "Loop";

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	FName DirectionName = "Direction";

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	FName WaitTimeName = "WaitTime";

	class ATEAI* AIContolledPawn;

	virtual void BeginPlay() override;
};

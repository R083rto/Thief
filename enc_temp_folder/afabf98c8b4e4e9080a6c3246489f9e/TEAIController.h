// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "TEAIController.generated.h"


UCLASS()
class THIEF_API ATEAIController : public AAIController
{
	GENERATED_BODY()
	

	UPROPERTY(Transient)
	class UBlackboardComponent* BlackboardComp;
	
	UPROPERTY(Transient)
	class UBehaviorTreeComponent* BehaviourComp;

public:

	ATEAIController();

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAIPerceptionComponent* AIPerception;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAISenseConfig_Sight* Sight;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	class UAISenseConfig_Hearing* Hearing;

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	FName LoopName = "Loop";

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	FName DirectionName = "Direction";
	
	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
	FName WaitTimeName = "WaitTime";


	virtual void Possess(APawn* PossessedPawn) override;

	virtual void BeginPlay() override;

};

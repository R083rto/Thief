// Fill out your copyright notice in the Description page of Project Settings.

#include "TEAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISightTargetInterface.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include <BehaviorTree/BlackboardComponent.h>
#include "TEAI.h"
#include "TEPatrolPath.h"
#include <AIController.h>


ATEAIController::ATEAIController()
{
	
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Sense"));
	if (Sight)
	{
		// Sight configuration
		Sight->SightRadius = 500;
		Sight->LoseSightRadius = 600;
		Sight->PeripheralVisionAngleDegrees = 180.0f;
		Sight->DetectionByAffiliation.bDetectEnemies = true;
		Sight->DetectionByAffiliation.bDetectNeutrals = true;
		Sight->DetectionByAffiliation.bDetectFriendlies = true;
		
		AIPerception->ConfigureSense(*Sight);
	}

	Hearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Sense"));
	if (Hearing)
	{

		AIPerception->ConfigureSense(*Hearing);
	}
	
}

void ATEAIController::BeginPlay()
{
	Super::BeginPlay();

	if (Behaviour)
	{
		RunBehaviorTree(Behaviour);
		AIContolledPawn = Cast<ATEAI>(GetPawn());
		ATEPatrolPath* Path = Cast<ATEPatrolPath>(AIContolledPawn->PatrolPath);
		UBlackboardComponent* MyBlackBoard = GetBlackboardComponent();
		MyBlackBoard->SetValueAsBool(LoopName, Path->IsLooping);
		MyBlackBoard->SetValueAsInt(DirectionName, 1);
		MyBlackBoard->SetValueAsFloat(WaitTimeName, AIContolledPawn->WaitTime);

	}
	else
		UE_LOG(LogTemp, Error, TEXT("NO BEHAVIOUR TREE HAS BEEN ASIGNED TO THE AI CONTROLLER"));
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TEAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"


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
}



void ATEAIController::BeginPlay()
{
	Super::BeginPlay();

	if(Behaviour)
		RunBehaviorTree(Behaviour);
	else
		UE_LOG(LogTemp, Error, TEXT("NO BEHAVIOUR TREE HAS BEEN ASIGNED TO THE AI CONTROLLER"));
}
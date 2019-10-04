// Fill out your copyright notice in the Description page of Project Settings.

#include "TEAIController.h"
#include "Perception/AISightTargetInterface.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "behaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "TEAI.h"
#include "TEPatrolPath.h"
#include <AIController.h>
#include <GameFramework/Actor.h>
#include "TECharacter.h"



ATEAIController::ATEAIController()
{
	//initializing behavior stuff
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComp"));
	BehaviourComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SetPerceptionComponent(*AIPerception);
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

void ATEAIController::ActorsPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	// updating perception of players
	for(AActor* actor : UpdatedActors)
	{
		ATECharacter* player = actor ? Cast<ATECharacter>(actor) : NULL;
		if (player)
		{
			BlackboardComp->SetValueAsObject(PlayerName, player);
		}
	}
}

void ATEAIController::Possess(APawn* PossessedPawn)
{
	Super::Possess(PossessedPawn);

	ATEAI* Char = Cast<ATEAI>(PossessedPawn);
	if (Char && Char->BotBehavior)
	{
		BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		ATEPatrolPath* Path = Cast<ATEPatrolPath>(Char->PatrolPath);

		BlackboardComp->SetValueAsBool(LoopName, Path->IsLooping);
		BlackboardComp->SetValueAsInt(DirectionName, 1);
		BlackboardComp->SetValueAsFloat(WaitTimeName, Char->WaitTime);

		BehaviourComp->StartTree(*Char->BotBehavior);
		RunBehaviorTree(Char->BotBehavior);
	}
}

void ATEAIController::BeginPlay()
{
	Super::BeginPlay();

}

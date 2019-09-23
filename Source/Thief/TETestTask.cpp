// Fill out your copyright notice in the Description page of Project Settings.

#include "TETestTask.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

UTETestTask::UTETestTask()
{

}

EBTNodeResult::Type UTETestTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	
	return EBTNodeResult::Succeeded;
}


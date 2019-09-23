// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TEPatrolPath.generated.h"

UCLASS()
class THIEF_API ATEPatrolPath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATEPatrolPath();

	UPROPERTY(EditInstanceOnly, Meta = (MakeEditWidget = true))
	TArray<FVector> PatrolPath;

	UPROPERTY(EditInstanceOnly)
	bool IsLooping = false;

};

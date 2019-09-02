// Fill out your copyright notice in the Description page of Project Settings.

#include "TEAI.h"
#include "TEPatrolPath.h"

// Sets default values
ATEAI::ATEAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATEAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATEAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATEAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


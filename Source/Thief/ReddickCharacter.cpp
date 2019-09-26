// Fill out your copyright notice in the Description page of Project Settings.

#include "ReddickCharacter.h"

// Sets default values
AReddickCharacter::AReddickCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReddickCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReddickCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AReddickCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


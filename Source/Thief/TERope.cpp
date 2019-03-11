// Fill out your copyright notice in the Description page of Project Settings.

#include "TERope.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TECharacter.h"

// Sets default values
ATERope::ATERope()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RopeHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RopeHitBox"));

	RootComponent = RootScene;
	RopeHitBox->SetupAttachment(RootScene);
	RopeHitBox->OnComponentBeginOverlap.AddDynamic(this, &ATERope::RopeStartOverlap);
	RopeHitBox->OnComponentEndOverlap.AddDynamic(this, &ATERope::RopeEndOverlap);
}

// Called when the game starts or when spawned
void ATERope::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATERope::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATERope::ExtendRope(float Length)
{
}

void ATERope::RopeStartOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (ATECharacter* Player = Cast<ATECharacter>(OtherActor))
	{
		Player->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
}

void ATERope::RopeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ATECharacter* Player = Cast<ATECharacter>(OtherActor))
	{
		Player->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}
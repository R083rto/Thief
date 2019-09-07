// Fill out your copyright notice in the Description page of Project Settings.

#include "TEArrow.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TERope.h"
#include "TECharacter.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATEArrow::ATEArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArrowHead = CreateDefaultSubobject<USceneComponent>(TEXT("ArrowHead"));
	ArrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArrowMesh"));
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	RootComponent = ArrowMesh;

	ArrowHead->SetupAttachment(RootComponent);

	ArrowMesh->OnComponentHit.AddDynamic(this, &ATEArrow::OnArrowHit);
}

// Called when the game starts or when spawned
void ATEArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATEArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATEArrow::OnArrowHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ATECharacter* Player = Cast<ATECharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	{
		switch (Player->GetWeaponState())
		{
		case ECHOSENWEAPON::WaterArrow:
			WaterEvent(Hit);
			break;
		case ECHOSENWEAPON::DamageArrow:
			DamageEvent(Hit);
			break;
		case ECHOSENWEAPON::MossArrow:
			MossEvent(Hit);
			break;
		case ECHOSENWEAPON::RopeArrow:
			RopeEvent(Hit);
			break;
		default:
			break;
		}
	}
}

void ATEArrow::WaterEvent(FHitResult Hit)
{

}

void ATEArrow::DamageEvent(FHitResult Hit)
{

}

void ATEArrow::MossEvent(FHitResult Hit)
{

}

void ATEArrow::RopeEvent(FHitResult Hit)
{
	GetWorld()->SpawnActor<ATERope>(RopeClass,FVector(Hit.Location.X, Hit.Location.Y, Hit.Location.Z-15.f),FRotator(0));
}
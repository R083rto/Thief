// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TERope.generated.h"

UCLASS()
class THIEF_API ATERope : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATERope();

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* RopeHitBox;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ExtendRope(float Length);

	UFUNCTION()
	void RopeStartOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void RopeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};

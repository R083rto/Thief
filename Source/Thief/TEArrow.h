// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TEArrow.generated.h"

class ATERope;

UCLASS()
class THIEF_API ATEArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATEArrow();

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* ArrowHead;
	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ArrowMesh;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATERope> RopeClass;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnArrowHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
private:
	void WaterEvent(FHitResult Hit);
	void DamageEvent(FHitResult Hit);
	void MossEvent(FHitResult Hit);
	void RopeEvent(FHitResult Hit);

};

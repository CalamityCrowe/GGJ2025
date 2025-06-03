// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowSplineComponent.generated.h"
class ASplineActor

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ_2025_API UFollowSplineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFollowSplineComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AutoFindSpline();
	FVector GetForwardVector() const;
	void GetDistanceAlongSpline();
	void UpdateDestination();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category = "Spline", meta = (AllowPrivateAccess = true))
	TObjectPtr<ASplineActor> SplineActor;

	float DistanceAlongSpline;
	float PercentAlongSpline;
	FVector DestinationLocation;
};

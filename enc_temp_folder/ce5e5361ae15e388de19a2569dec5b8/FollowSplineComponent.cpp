// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowSplineComponent.h"
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/KismetMathLibrary.h>
#include "Actor/SplineActor.h"
#include "Components/SplineComponent.h"
#include "Dragon/DragonCharacter.h"
// Sets default values for this component's properties
UFollowSplineComponent::UFollowSplineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFollowSplineComponent::BeginPlay()
{
	Super::BeginPlay();
	if(!SplineActor)
	{
		AutoFindSpline();
	}
	// ...
	
}


// Called every frame
void UFollowSplineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFollowSplineComponent::AutoFindSpline()
{
	if(bAutoFindSpline)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASplineActor::StaticClass(), FoundActors);
		if (FoundActors.Num() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("No spline actors found in the world."));
			return;
		}
		float NearestDistance = FLT_MAX;
		if (SplineActor = Cast<ASplineActor>(UGameplayStatics::FindNearestActor(GetForwardAimVector(), FoundActors, NearestDistance))) 
		{
			UE_LOG(LogTemp, Log, TEXT("Found spline actor: %s"), *SplineActor->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No suitable spline actor found."));
		}
	}
}

FVector UFollowSplineComponent::GetForwardAimVector() const
{
	
	FVector OwnerLocation = GetOwner()->GetActorLocation();
	FVector ForwardVector = GetOwner()->GetActorForwardVector() * AimDistance;
	return OwnerLocation + ForwardVector;
}

void UFollowSplineComponent::GetDistanceAlongSpline()
{
	if (!SplineActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("SplineActor is not set. Cannot calculate distance along spline."));
		return;
	}
	FVector OwnerLocation = GetOwner()->GetActorLocation();
	float SplineLength = SplineActor->GetSplineComponent()->GetSplineLength();
	DistanceAlongSpline = SplineActor->GetSplineComponent()->FindInputKeyClosestToWorldLocation(OwnerLocation);
	PercentAlongSpline = DistanceAlongSpline / SplineLength;
}

void UFollowSplineComponent::UpdateDestination()
{
	DestinationLocation = SplineActor->GetSplineComponent()->FindLocationClosestToWorldLocation(GetForwardAimVector(), ESplineCoordinateSpace::World);
}

void UFollowSplineComponent::ProceedToDestination(float DeltaTime)
{
	if (ADragonCharacter* Dragon = Cast<ADragonCharacter>(GetOwner())) 
	{
		FVector Location = GetOwner()->GetActorLocation();
		FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(Location, DestinationLocation);
		Dragon->AddMovementInput(LookAtRot.Vector(), 1.0f, false);
	}
}


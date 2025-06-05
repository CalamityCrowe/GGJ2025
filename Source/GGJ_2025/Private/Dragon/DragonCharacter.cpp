// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon/DragonCharacter.h"
#include "Actor/SplineActor.h"
#include "Components/SplineComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FollowSplineComponent.h"

// Sets default values
ADragonCharacter::ADragonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FollowSplineComponent = CreateDefaultSubobject<UFollowSplineComponent>(TEXT("FollowSplineComponent"));

	DragonEyeIndex = FMath::RandRange(0, 4); // Randomly select an eye index
	DragonSkinIndex = FMath::RandRange(0, 4);  // Randomly select a skin index
}

// Called when the game starts or when spawned
void ADragonCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxSwimSpeed = FMath::RandRange(150, 300); 
	RandomSplineTimer();
}

// Called every frame
void ADragonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(FollowSplineComponent && FollowSplineComponent->GetSplineActor())
	{
		FollowSplineComponent->GetDistanceAlongSpline();
		FollowSplineComponent->UpdateDestination();
		FollowSplineComponent->ProceedToDestination(DeltaTime);
	}
	
}

// Called to bind functionality to input
void ADragonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}



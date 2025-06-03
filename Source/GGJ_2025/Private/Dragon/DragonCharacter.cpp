// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon/DragonCharacter.h"
#include "Actor/SplineActor.h"
#include "Components/SplineComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ADragonCharacter::ADragonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DragonEyeIndex = FMath::RandRange(0, 4); // Randomly select an eye index
	DragonSkinIndex = FMath::RandRange(0, 4);  // Randomly select a skin index
}

// Called when the game starts or when spawned
void ADragonCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (SplineActor)
	{
		SplineDuration = SplineActor->GetSplineComponent()->GetSplineLength();
		TimeOnSpline = FMath::RandRange(0.0f, SplineDuration);
		GetCharacterMovement()->MaxSwimSpeed = FMath::RandRange(100.0f, 300.0f); // Random swim speed between 100 and 200
		bDirection = FMath::RandBool(); // Randomly set direction
	}
}

// Called every frame
void ADragonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void ADragonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


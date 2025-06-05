// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DragonCharacter.generated.h"

class UFollowSplineComponent;

UCLASS()
class GGJ_2025_API ADragonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADragonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	int GetDragonSkinIndex() const { return DragonSkinIndex; }
	UFUNCTION(BlueprintPure)
	int GetDragonEyeIndex() const { return DragonEyeIndex; }

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<UFollowSplineComponent> FollowSplineComponent;

	float TimeOnSpline = 0.0f;
	float SplineDuration = 0.0f;

	int DragonSkinIndex = 0;
	int DragonEyeIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	bool bDirection; 

	float TimeSinceLastUpdate = 0.0f;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BubblePlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCharacterMovementComponent;

class UInputData;

UCLASS()
class ABubblePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABubblePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> BubbleMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCharacterMovementComponent> MovementComponent;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Inputs", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputData> Inputs;

private:
	UFUNCTION()
	virtual void Move(const FInputActionValue& Value);
	UFUNCTION()
	virtual void Look(const FInputActionValue& Value);
	UFUNCTION()
	virtual void FloatUp(const FInputActionValue& Value);
	UFUNCTION()
	virtual void FloatDown(const FInputActionValue& Value);
};

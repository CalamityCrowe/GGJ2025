// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ_2025_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Subtract(); 

	bool IsAlive() { return bAlive;  }

private:

	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Stats", meta = (AllowPrivateAccess  =true))
	int Health;
	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = true))
	bool bAlive; 

};

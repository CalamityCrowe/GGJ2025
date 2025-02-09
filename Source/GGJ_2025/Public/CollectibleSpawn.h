// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleSpawn.generated.h"

class ACollectible; 
UCLASS()
class GGJ_2025_API ACollectibleSpawn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACollectibleSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SpawnNewBubble(); 

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Spawn Actor")
	TSubclassOf<ACollectible> CollectRef; 

	

};

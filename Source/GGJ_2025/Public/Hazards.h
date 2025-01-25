// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hazards.generated.h"

class UCapsuleComponent; 
class UStaticMeshComponent; 

UCLASS()
class GGJ_2025_API AHazards : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHazards();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetMesh() const { return Mesh;  }
	UCapsuleComponent* GetCollider() const { return Collider;  }
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true),Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> Mesh; 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true), Category = "Collision")
	TObjectPtr<UCapsuleComponent> Collider;


};

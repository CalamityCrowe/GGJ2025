// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleSpawn.h"
#include "Collectible.h"
// Sets default values
ACollectibleSpawn::ACollectibleSpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACollectibleSpawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACollectibleSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectibleSpawn::SpawnNewBubble()
{
	if (CollectRef)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
		GetWorld()->SpawnActor<ACollectible>(CollectRef, GetActorLocation(), FRotator(), SpawnParams);
	}
}


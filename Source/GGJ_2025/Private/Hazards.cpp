// Fill out your copyright notice in the Description page of Project Settings.


#include "Hazards.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AHazards::AHazards()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(FName("Hazard"));

	Collider = CreateOptionalDefaultSubobject<UCapsuleComponent>(TEXT("Collider")); 
	RootComponent = Collider; 

	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider); 

}

// Called when the game starts or when spawned
void AHazards::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHazards::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


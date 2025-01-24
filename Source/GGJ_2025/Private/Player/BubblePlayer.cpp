// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BubblePlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABubblePlayer::ABubblePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	BubbleMesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("BubbleMesh"));
	SetRootComponent(BubbleMesh);

	SpringArm = CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Camera);

	Camera = CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	MovementComponent = CreateOptionalDefaultSubobject<UCharacterMovementComponent>(TEXT("MovementComponent"));

	GetMesh()->DestroyComponent();
	GetCapsuleComponent()->DestroyComponent();
	GetCharacterMovement()->DestroyComponent();

}

// Called when the game starts or when spawned
void ABubblePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABubblePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABubblePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


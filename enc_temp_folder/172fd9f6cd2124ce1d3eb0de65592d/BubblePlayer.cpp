// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BubblePlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "InputData.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"


// Sets default values
ABubblePlayer::ABubblePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	BubbleMesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("BubbleMesh"));
	BubbleMesh->SetupAttachment(GetRootComponent());

	SpringArm = CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BubbleMesh);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bUsePawnControlRotation = true;


	Camera = CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->DestroyComponent();
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Swimming);

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

	if (PlayerInputComponent)
	{
		if (APlayerController* PC = Cast<APlayerController>(Controller))
		{
			if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
			{
				if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
				{
					InputSystem->AddMappingContext(Inputs->Context, 0); // this is erroring due to not setting the data asset that contains the context, this can be fixed by either setting a null check or actually setting the input
				}
			}
		}
	}

	if (UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{

		PEI->BindAction(Inputs->MovementActions[0], ETriggerEvent::Triggered, this, &ABubblePlayer::Move); 
		PEI->BindAction(Inputs->MovementActions[1], ETriggerEvent::Triggered, this, &ABubblePlayer::Look);
		PEI->BindAction(Inputs->MovementActions[2], ETriggerEvent::Triggered, this, &ABubblePlayer::FloatUp);

	}

}

void ABubblePlayer::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	if (Controller) 
	{
		AddMovementInput(Camera->GetForwardVector()* 100, Input.Y); 
		AddMovementInput(Camera->GetRightVector() * 100, Input.X);

	}
}

void ABubblePlayer::Look(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerPitchInput(Input.Y);
		AddControllerYawInput(Input.X);
	}

}

void ABubblePlayer::FloatUp(const FInputActionValue& Value)
{
	if (Controller)
	{
		AddMovementInput(FVector::UpVector * 100, 1);
		UE_LOG(LogTemp, Warning, TEXT("Floating Up"));
	}
}


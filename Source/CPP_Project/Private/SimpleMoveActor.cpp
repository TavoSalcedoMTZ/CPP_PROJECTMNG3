// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleMoveActor.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include <GameFramework/PlayerController.h>
#include <Engine/LocalPlayer.h>
#include <Engine/World.h>

// Sets default values
ASimpleMoveActor::ASimpleMoveActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASimpleMoveActor::BeginPlay()
{
	Super::BeginPlay();

	SetUpInputComponent();
}

void ASimpleMoveActor::SetUpInputComponent()
{
	APlayerController* pc = GetWorld()->GetFirstPlayerController();

	if (!pc) {
		return;
	}

	EnableInput(pc);

	ULocalPlayer* localplayer = pc->GetLocalPlayer();

	if (localplayer)
	{
		UEnhancedInputLocalPlayerSubsystem* inputSubsystem =
			localplayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

		if (inputSubsystem != nullptr && _context != nullptr)
		{
			if (!inputSubsystem->HasMappingContext(_context))
			{
				inputSubsystem->AddMappingContext(_context, 0);
			}
		}
	}

	UEnhancedInputComponent* inComp = Cast<UEnhancedInputComponent>(InputComponent);

	if (inComp && _moveAction)
	{
		inComp->BindAction(
			_moveAction,
			ETriggerEvent::Triggered,
			this,
			&ASimpleMoveActor::Move
		);
	}
}

// Called every frame
void ASimpleMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASimpleMoveActor::Move(const FInputActionValue& actionValue)
{
	FVector2D moveValue = actionValue.Get<FVector2D>();
	FVector moveVector = FVector::ZeroVector;

	moveValue *= _speed;

	moveVector.X = moveValue.X;
	moveVector.Y = moveValue.Y;

	AddActorWorldOffset(moveVector, true);
}
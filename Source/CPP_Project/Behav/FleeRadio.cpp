// Fill out your copyright notice in the Description page of Project Settings.


#include "Behav/FleeRadio.h"

// Sets default values for this component's properties
UFleeRadio::UFleeRadio()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFleeRadio::BeginPlay()
{
	Super::BeginPlay();

	SelfActor = GetOwner();
	// ...
	
}


// Called every frame
void UFleeRadio::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!SelfActor || !TargetActor)
	{
		return;
	}

	const FVector SelfLocation = SelfActor->GetActorLocation();
	const FVector TargetLocation = TargetActor->GetActorLocation();

	FVector ToThreat = TargetLocation - SelfLocation;
	float distance = ToThreat.Length();


	if (distance > AcceptanceRadius)
	{
		currentVelocity = FVector::ZeroVector;
		return;
	}

	FVector dir = (SelfLocation - TargetLocation).GetSafeNormal();

	currentVelocity = dir * MaxSpeed;

	SelfActor->SetActorLocation(SelfLocation + currentVelocity * DeltaTime);

	// ...
}


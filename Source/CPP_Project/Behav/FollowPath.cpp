// Fill out your copyright notice in the Description page of Project Settings.


#include "Behav/FollowPath.h"

// Sets default values for this component's properties
UFollowPath::UFollowPath()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFollowPath::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SelfActor = GetOwner();
	
}


// Called every frame
void UFollowPath::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SelfActor == nullptr || PathPoints.Num() == 0)
	{
		return;
	}
	const FVector SelfLocation = SelfActor->GetActorLocation();
	const FVector TargetLocation = PathPoints[nextPathIndex]->GetActorLocation();

	const FVector ToTarget = TargetLocation - SelfLocation;

	if (ToTarget.Length() <= 10.0f)
	{
		currentPathIndex = nextPathIndex;
		nextPathIndex = (nextPathIndex + 1) % PathPoints.Num();
		return;
	}

	const FVector DesiredVelocity = ToTarget.GetSafeNormal() * currentSpeed;

	SelfActor->SetActorLocation(SelfLocation + DesiredVelocity * DeltaTime);

}


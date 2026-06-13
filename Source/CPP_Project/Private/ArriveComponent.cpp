#include "ArriveComponent.h"

UArriveComponent::UArriveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UArriveComponent::BeginPlay()
{
	Super::BeginPlay();

	SelfActor = GetOwner();
}

void UArriveComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!SelfActor || !TargetActor)
	{
		return;
	}

	const FVector SelfLocation = SelfActor->GetActorLocation();
	const FVector TargetLocation = TargetActor->GetActorLocation();

	const FVector ToTarget = TargetLocation - SelfLocation;

	Distance = ToTarget.Length();

	if (Distance <= AcceptanceRadius)
	{
		CurrentVelocity = FVector::ZeroVector;
		CurrentSpeed = 0.f;
		return;
	}

	float DesiredSpeed;

	if (Distance < SlowRadius)
	{
		DesiredSpeed = MaxSpeed * (Distance / SlowRadius);
	}
	else
	{
		DesiredSpeed = MaxSpeed;
	}

	const FVector DesiredVelocity =
		ToTarget.GetSafeNormal() * DesiredSpeed;

	const FVector Steering =
		DesiredVelocity - CurrentVelocity;

	CurrentVelocity += Steering * DeltaTime;

	CurrentSpeed = CurrentVelocity.Length();

	const FVector NewLocation =
		SelfLocation + CurrentVelocity * DeltaTime;

	SelfActor->SetActorLocation(NewLocation);
}
#include "ActorComponent/PlataformMovement.h"

// Sets default values
UPlataformMovement::UPlataformMovement()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlataformMovement::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
}

void UPlataformMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Points.Num() == 0) return;

	AActor* Owner = GetOwner();
	if (!Owner) return;

	FVector CurrentLocation = Owner->GetActorLocation();

	FVector TargetLocation = Points[CurrentPointIndex];

	FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();

	FVector NewLocation = CurrentLocation + Direction * Speed * DeltaTime;

	Owner->SetActorLocation(NewLocation);


	
	float Distance = FVector::Dist(CurrentLocation, TargetLocation);
	if (Distance < 10.0f)
	{
		CurrentPointIndex++;

		if (CurrentPointIndex >= Points.Num())
		{
			CurrentPointIndex = 0;
		}
	}
}
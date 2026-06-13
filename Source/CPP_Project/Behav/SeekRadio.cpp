// Fill out your copyright notice in the Description page of Project Settings.


#include "Behav/SeekRadio.h"

// Sets default values for this component's properties
USeekRadio::USeekRadio()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USeekRadio::BeginPlay()
{
	Super::BeginPlay();

	// ...

	SelfActor = GetOwner();
	
}


// Called every frame
void USeekRadio::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SelfActor == nullptr || TargetActor == nullptr)
	{
		return;
	}



	FVector ToTarget = TargetActor->GetActorLocation() - SelfActor->GetActorLocation();
	float Distance = ToTarget.Length();

	if(Distance <= AcceptanceRadius)
	{
		currentVelocity = FVector::ZeroVector;
		return;
	}
	
	FVector Dir = ToTarget.GetSafeNormal();

	currentVelocity = Dir * MaxSpeed;

	FVector NewLocation = SelfActor->GetActorLocation() + currentVelocity * DeltaTime;

	SelfActor->SetActorLocation(NewLocation);

}


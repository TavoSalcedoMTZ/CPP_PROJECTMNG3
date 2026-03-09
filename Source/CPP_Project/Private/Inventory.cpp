// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{

}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventory::AddCoints_Implementation(int32 Amount)
{
	Coints += Amount;
	OnCountUpdated.Broadcast(Coints);
}

void UInventory::RemoveCoints(int32 Amount)
{
	Coints -= Amount;
}

void UInventory::AddHealth(float Amount)
{
	Health += Amount;
}

void UInventory::RemoveHealth(float Amount)
{
	Health -= Amount;
}


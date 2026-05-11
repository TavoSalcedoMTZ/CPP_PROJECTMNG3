// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IProjectilDamagable.h"
#include "DamagableActor.generated.h"

UCLASS()
class CPP_PROJECT_API ADamagableActor : public AActor , public IIProjectilDamagable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamagableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ReceiveProjectileDamage_Implementation(const float& damage) override;

};
	
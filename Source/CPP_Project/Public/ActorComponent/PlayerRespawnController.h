// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerRespawnController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_PROJECT_API UPlayerRespawnController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerRespawnController();

	FVector currentCheckpointLocation;

	UFUNCTION(BlueprintCallable, Category = "Respawn")
	void RespawnPlayer();
	UFUNCTION(BlueprintCallable, Category = "Respawn")
	void SetCheckPoint();

		
};

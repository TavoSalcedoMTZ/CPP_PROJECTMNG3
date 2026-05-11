// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"

#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPP_PROJECT_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<UInputMappingContext*> InputMappings;

	virtual void SetupInputComponent()override;

	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

void ACustomPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (IsLocalController())
    {
        // Add Input Mapping Context
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
        {
            for (UInputMappingContext* CurrentContext : InputMappings)
            {
                Subsystem->AddMappingContext(CurrentContext, 0);
            }
        }
    }
}

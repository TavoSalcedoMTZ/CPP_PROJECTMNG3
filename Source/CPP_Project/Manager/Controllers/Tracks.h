#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Tracks.generated.h"

// This macro allows the enum to be used in Blueprints
UENUM(BlueprintType)
enum class ETracks : uint8
{
    Main    UMETA(DisplayName = "Main"),
    Music   UMETA(DisplayName = "Music"),
	SFX     UMETA(DisplayName = "SFX")  
};
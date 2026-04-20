// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CAudioLibrary.generated.h"


class USoundBase;

UENUM(BlueprintType)
enum class ETag : uint8
{
	Town1 UMETA(DisplayName = "Town 1"),
	Town2 UMETA(DisplayName = "Town 2")
};



USTRUCT(BlueprintType)
struct FLibraryEntry
{
    GENERATED_BODY();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    ETag Tag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TObjectPtr<USoundBase> Sound;
};






/**
 * 
 */
UCLASS()
class CPP_PROJECT_API UCAudioLibrary : public UPrimaryDataAsset
{
	GENERATED_BODY()

   
public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FLibraryEntry> LibraryEntry;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class USoundBase;
class UAudioComponent;

#include "CoreMinimal.h"
#include "Tracks.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioManager.generated.h"

/**
 * 
 */
UCLASS()
class CPP_PROJECT_API UAudioManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;
	virtual void Deinitialize() override;


	UFUNCTION(BlueprintCallable)
	void SetVolume(float vol, ETracks track);
	UFUNCTION(BlueprintCallable)
	void PlayMusic(USoundBase* sound, bool loop, float pitch);



	 float mainVolume = 1;
	 float musicVolume = 1;
	 float sfxVolume = 1;


	 UPROPERTY() 
	 TObjectPtr<UAudioComponent> _audioComp;


	
};

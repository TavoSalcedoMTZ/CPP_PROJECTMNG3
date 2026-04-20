// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Tracks.h"
#include "Data/CAudioLibrary.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioManager.generated.h"

class USoundBase;
class UAudioComponent;
class UCAudioLibrary;


//quiero pene ahhhhhh
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


	UFUNCTION(BlueprintCallable)
	float GetVolume(ETracks _track);

	UFUNCTION(BlueprintCallable)
	void SetAudioLibrary(UCAudioLibrary * _lib);

	UFUNCTION(BlueprintCallable)
	void PlayMusicLibrary(FName name, bool loop, float pitch);



	 float mainVolume = 1;
	 float musicVolume = 1;
	 float sfxVolume = 1;

	 TObjectPtr<UCAudioLibrary> _library;

	 UPROPERTY() 
	 TObjectPtr<UAudioComponent> _audioComp;


	
};

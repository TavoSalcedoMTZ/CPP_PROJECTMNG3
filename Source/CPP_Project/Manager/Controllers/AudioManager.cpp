// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Manager/Controllers/AudioManager.h"

void UAudioManager::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);
}

void UAudioManager::Deinitialize()
{
}


void UAudioManager::SetVolume(float vol, ETracks track)
{
	switch (track)
	{
	case ETracks::Main:
		mainVolume = vol;
		break;
	case ETracks::Music:
		musicVolume = vol;
		break;
	default:
		break;		
	}


}

void UAudioManager::PlayMusic(USoundBase* Sound, bool bLoop, float Pitch)
{
    if (!Sound || !GetWorld()) return;

    if (!_audioComp)
    {
        _audioComp = UGameplayStatics::SpawnSound2D(
            GetWorld(),
            Sound,
            1.0f,   
            Pitch,
            0.0f,   
            nullptr, 
            bLoop   
        );
    }
    else
    {
       
        _audioComp->SetSound(Sound);
        _audioComp->SetPitchMultiplier(Pitch);
        _audioComp->Play();
        _audioComp->bIsUISound = true;
    }
}

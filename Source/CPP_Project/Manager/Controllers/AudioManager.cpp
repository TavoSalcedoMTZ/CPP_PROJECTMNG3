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
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Valor cambiado en ")+ UEnum::GetValueAsString(track)+ TEXT(" a ") + FString::SanitizeFloat(vol));

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

	float UAudioManager::GetVolume(ETracks _track)
	{
		switch (_track)
		{
		case ETracks::Main:
			return mainVolume;
		case ETracks::Music:
			return musicVolume;
		case ETracks::SFX:
			return sfxVolume;
		default:
			return 0.0f;


		}
	}

	void UAudioManager::SetAudioLibrary(UCAudioLibrary * _lib)
	{
		if (_lib != nullptr) {

			_library = _lib;
		}
	}

	void UAudioManager::PlayMusicLibrary(FName name, bool loop, float pitch)
	{
		if (_library) {


			for (const auto& entry : _library->LibraryEntry) {
				{
					if (entry.Name == name)
					{
						PlayMusic(entry.Sound, loop, pitch);
					}
				}
			}


		}
	}

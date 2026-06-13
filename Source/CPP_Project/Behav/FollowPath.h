// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowPath.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_PROJECT_API UFollowPath : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFollowPath();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	TArray<AActor*> PathPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	float currentSpeed = 100.0;


private:
	int32 currentPathIndex = 0;
	int32 nextPathIndex = 1;
	AActor* SelfActor = nullptr;
};

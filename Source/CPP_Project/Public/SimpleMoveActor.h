// Fill out your copyright notice in the Description page of Project Settings.
//Soy puto


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <EnhancedInputLibrary.h>
#include "SimpleMoveActor.generated.h"

class UInputAction;
class UInputMappingContext;
class UInputComponents;
class UCameraComponent;




UCLASS()
class CPP_PROJECT_API ASimpleMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable)
	void SetUpInputComponent(); 


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> _context;


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> _moveAction;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Input")
	float _speed = 100;

	void Move(const FInputActionValue& actionValue);

};

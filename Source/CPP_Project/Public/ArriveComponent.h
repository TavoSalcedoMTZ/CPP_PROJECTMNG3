#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArriveComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPP_PROJECT_API UArriveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UArriveComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	AActor* TargetActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	float MaxSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	float SlowRadius = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrive")
	float AcceptanceRadius = 20.f;

	UPROPERTY(BlueprintReadOnly, Category = "Arrive")
	float Distance = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Arrive")
	float CurrentSpeed = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Arrive")
	FVector CurrentVelocity = FVector::ZeroVector;

private:
	AActor* SelfActor = nullptr;
};
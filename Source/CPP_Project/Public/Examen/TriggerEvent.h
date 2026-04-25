#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ShapeComponent.h"
#include "TriggerEvent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnTriggerEventDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTriggerEventDynamic);

UENUM(BlueprintType)
enum class ETriggerShape : uint8
{
	Sphere,
	Box
};

UCLASS()
class CPP_PROJECT_API ATriggerEvent : public AActor
{
	GENERATED_BODY()

public:
	ATriggerEvent();

protected:
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
	ETriggerShape TriggerShapeType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trigger")
	UShapeComponent* ShapeComponent;

	FOnTriggerEventDelegate OnTriggerEvent;

	UPROPERTY(BlueprintAssignable, Category = "Trigger")
	FOnTriggerEventDynamic OnTriggerEventBP;

	UFUNCTION()
	void OnOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
};
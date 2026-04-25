#include "Examen/TriggerEvent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"

ATriggerEvent::ATriggerEvent()
{
	PrimaryActorTick.bCanEverTick = false;

	
	TriggerShapeType = ETriggerShape::Sphere;


	if (TriggerShapeType == ETriggerShape::Sphere)
	{
		USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
		Sphere->InitSphereRadius(100.f);
		ShapeComponent = Sphere;
	}
	else
	{
		UBoxComponent* Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
		Box->SetBoxExtent(FVector(100.f));
		ShapeComponent = Box;
	}

	RootComponent = ShapeComponent;

	ShapeComponent->SetCollisionProfileName(TEXT("Trigger"));
	ShapeComponent->SetGenerateOverlapEvents(true);

	ShapeComponent->OnComponentBeginOverlap.AddDynamic(this, &ATriggerEvent::OnOverlap);
}

void ATriggerEvent::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerEvent::OnOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this)
		return;

	if (OtherActor->ActorHasTag("Player"))
	{
		OnTriggerEvent.Broadcast();
		OnTriggerEventBP.Broadcast();
	}
}
#include "PickupKey.h"

APickupKey::APickupKey()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;

	SphereCollision->InitSphereRadius(100.f);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	KeyMesh->SetupAttachment(SphereCollision);
}

void APickupKey::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &APickupKey::OnOverlapBegin);
}

void APickupKey::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
	



		if (OtherActor->GetClass()->ImplementsInterface(UPlayerInterface::StaticClass()))
		{


			if (autoOpen)
			{
				CallEvent();
				return;
			}
			else {

				IPlayerInterface::Execute_HasKey(OtherActor, true);
				IPlayerInterface::Execute_SendKeyReference(OtherActor, this);

			}
		}
	}
}

void APickupKey::CallEvent()
{
	OnKeyCollected.Broadcast();
	Destroy();
}
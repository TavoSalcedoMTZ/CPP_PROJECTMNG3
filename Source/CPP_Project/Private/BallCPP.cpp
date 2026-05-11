// Fill out your copyright notice in the Description page of Project Settings.

#include "IProjectilDamagable.h"
#include "BallCPP.h"

// Sets default values
ABallCPP::ABallCPP()
{
	PrimaryActorTick.bCanEverTick = true;

	// Sphere Collider
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	RootComponent = SphereCollider;

	SphereCollider->InitSphereRadius(32.f);
	SphereCollider->SetCollisionProfileName(TEXT("Trigger"));

	// Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SphereCollider);

	// Projectile Movement
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->InitialSpeed = 1500.f;
	Projectile->MaxSpeed = 1500.f;
	Projectile->bRotationFollowsVelocity = true;

	// Bind Overlap Event
	SphereCollider->OnComponentBeginOverlap.AddDynamic(
		this,
		&ABallCPP::OnOverlapBegin
	);
}

// Called when the game starts or when spawned
void ABallCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallCPP::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->Implements<UIProjectilDamagable>())
	{
		IIProjectilDamagable::Execute_ReceiveProjectileDamage(OtherActor, 5);
	}
}

#include "UpElevatorState.h"
#include "StateMachineController.h"
#include "GameFramework/Actor.h"

void UpElevatorState::onEnter()
{
    FVector Start = Controller->GetOwner()->GetActorLocation();
    TargetLocation = Start + FVector(0.f, 0.f, ZOffset);
}

EElevatorStateID UpElevatorState::StateTick(float DeltaTime)
{
    AActor* Owner = Controller->GetOwner();
    FVector  Current = Owner->GetActorLocation();
    FVector  Next = FMath::VInterpConstantTo(Current, TargetLocation, DeltaTime, Speed);
    Owner->SetActorLocation(Next);

    if (FVector::Dist(Next, TargetLocation) < 1.f)
    {
        Owner->SetActorLocation(TargetLocation);
        return EElevatorStateID::Idle;
    }

    return EElevatorStateID::Up;
}

void UpElevatorState::onExit() {}
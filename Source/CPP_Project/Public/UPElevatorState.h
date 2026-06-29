#pragma once
#include "StateBase.h"
#include "CoreMinimal.h"

class CPP_PROJECT_API UpElevatorState : public StateBase
{
public:
    float ZOffset = 300.f;
    float Speed = 150.f;

    void onEnter() override;
    EElevatorStateID StateTick(float DeltaTime) override;
    void onExit() override;

private:
    FVector TargetLocation;
};
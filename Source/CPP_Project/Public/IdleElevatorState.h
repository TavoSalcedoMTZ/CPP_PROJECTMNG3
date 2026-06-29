#pragma once
#include "StateBase.h"
#include "CoreMinimal.h"

class CPP_PROJECT_API IdleElevatorState : public StateBase
{
public:
    bool bNextIsUp = true;
    bool bTriggered = false;

    void onEnter() override;
    EElevatorStateID StateTick(float DeltaTime) override;
    void onExit() override;

    void Trigger();
};
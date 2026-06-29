#include "IdleElevatorState.h"

void IdleElevatorState::onEnter()
{
    bTriggered = false;
}

EElevatorStateID IdleElevatorState::StateTick(float DeltaTime)
{
    if (!bTriggered) return EElevatorStateID::Idle;

    return bNextIsUp ? EElevatorStateID::Up : EElevatorStateID::Down;
}

void IdleElevatorState::onExit()
{
    bNextIsUp = !bNextIsUp;
}

void IdleElevatorState::Trigger()
{
    bTriggered = true;
}
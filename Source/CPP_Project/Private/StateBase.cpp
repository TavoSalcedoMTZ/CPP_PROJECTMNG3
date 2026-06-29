#include "StateBase.h"

StateBase::StateBase() {}
StateBase::~StateBase() {}

void StateBase::Init(UStateMachineController* stmachine)
{
    Controller = stmachine;
}

void StateBase::onEnter() {}

EElevatorStateID StateBase::StateTick(float DeltaTime)
{
    return EElevatorStateID::Idle;
}

void StateBase::onExit() {}
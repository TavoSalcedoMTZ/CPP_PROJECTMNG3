#include "ElevatorStateMachine.h"
#include "IdleElevatorState.h"
#include "UpElevatorState.h"
#include "DownElevatorState.h"

void UElevatorStateMachine::InitStates()
{
    States.Add(EElevatorStateID::Idle, MakeShared<IdleElevatorState>());
    States.Add(EElevatorStateID::Up, MakeShared<UpElevatorState>());
    States.Add(EElevatorStateID::Down, MakeShared<DownElevatorState>());

    InitializedMap();
    SetInitialState(EElevatorStateID::Idle);
}

void UElevatorStateMachine::ActivateElevator()
{
    TSharedPtr<StateBase>* Found = States.Find(EElevatorStateID::Idle);
    if (!Found || !Found->IsValid()) return;

    static_cast<IdleElevatorState*>(Found->Get())->Trigger();
}
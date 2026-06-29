#include "StateMachineController.h"

UStateMachineController::UStateMachineController()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UStateMachineController::BeginPlay()
{
    Super::BeginPlay();
    InitStates();
}

void UStateMachineController::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!CurrentState.IsValid()) return;

    EElevatorStateID NextID = CurrentState->StateTick(DeltaTime);

    if (NextID != CurrentStateID)
    {
        TSharedPtr<StateBase>* Next = States.Find(NextID);
        if (!Next || !Next->IsValid()) return;

        Exit();
        CurrentStateID = NextID;
        CurrentState = *Next;
        Enter();
    }
}

void UStateMachineController::SetInitialState(EElevatorStateID ID)
{
    TSharedPtr<StateBase>* Found = States.Find(ID);
    if (!Found || !Found->IsValid()) return;

    CurrentStateID = ID;
    CurrentState = *Found;
    Enter();
}

void UStateMachineController::InitializedMap()
{
    for (auto& Pair : States)
    {
        if (Pair.Value.IsValid())
        {
            Pair.Value->Init(this);
        }
    }
}

void UStateMachineController::InitStates()
{
    InitializedMap();
}

void UStateMachineController::Enter()
{
    if (CurrentState.IsValid()) CurrentState->onEnter();
}

void UStateMachineController::Exit()
{
    if (CurrentState.IsValid()) CurrentState->onExit();
}
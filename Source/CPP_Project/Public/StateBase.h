#pragma once
#include "CoreMinimal.h"
#include "ElevatorStateID.h"

class UStateMachineController;

class CPP_PROJECT_API StateBase
{
public:
    StateBase();
    virtual ~StateBase();

    UStateMachineController* Controller;

    void Init(UStateMachineController* stmachine);

    virtual void onEnter();
    virtual EElevatorStateID StateTick(float DeltaTime);
    virtual void onExit();
};
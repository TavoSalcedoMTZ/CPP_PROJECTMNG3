#pragma once
#include "StateMachineController.h"
#include "ElevatorStateMachine.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPP_PROJECT_API UElevatorStateMachine : public UStateMachineController
{
    GENERATED_BODY()

public:
    virtual void InitStates() override;

    UFUNCTION(BlueprintCallable)
    void ActivateElevator();
};
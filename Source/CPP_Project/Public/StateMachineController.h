#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateBase.h"
#include "ElevatorStateID.h"
#include "StateMachineController.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPP_PROJECT_API UStateMachineController : public UActorComponent
{
    GENERATED_BODY()

public:
    UStateMachineController();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;

    TMap<EElevatorStateID, TSharedPtr<StateBase>> States;
    TSharedPtr<StateBase> CurrentState;
    EElevatorStateID CurrentStateID;

    void Enter();
    void Exit();

    void SetInitialState(EElevatorStateID ID);
    virtual void InitStates();
    void InitializedMap();
};
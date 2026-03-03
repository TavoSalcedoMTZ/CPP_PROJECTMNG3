#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

class CPP_PROJECT_API IPlayerInterface
{
	GENERATED_BODY()

public:

	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player")
	void Interact();
};
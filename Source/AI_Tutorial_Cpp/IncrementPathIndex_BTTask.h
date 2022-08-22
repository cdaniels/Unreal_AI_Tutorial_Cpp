// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "IncrementPathIndex_BTTask.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AI_TUTORIAL_CPP_API UIncrementPathIndex_BTTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UIncrementPathIndex_BTTask(FObjectInitializer const& object_initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

private:
	enum class EDirectionType
	{
		Forward, Reverse
	};

	EDirectionType direction = EDirectionType::Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	bool bidirectional = true;
};

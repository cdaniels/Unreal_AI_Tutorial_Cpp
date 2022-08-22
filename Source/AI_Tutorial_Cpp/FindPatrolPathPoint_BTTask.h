// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FindPatrolPathPoint_BTTask.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AI_TUTORIAL_CPP_API UFindPatrolPathPoint_BTTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	UFindPatrolPathPoint_BTTask(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;
};

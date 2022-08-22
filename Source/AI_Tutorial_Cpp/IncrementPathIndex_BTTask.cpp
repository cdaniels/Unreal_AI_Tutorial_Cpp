// Fill out your copyright notice in the Description page of Project Settings.


#include "IncrementPathIndex_BTTask.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC.h"
#include "blackboard_keys.h"
#include <cmath>


UIncrementPathIndex_BTTask::UIncrementPathIndex_BTTask(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UIncrementPathIndex_BTTask::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	// get the AI controller
	ANPC_AIController* const controller = Cast<ANPC_AIController>(owner_comp.GetAIOwner());
	ANPC* const npc = Cast<ANPC>(controller->GetPawn());
	int const no_of_points = npc->GetPatrolPath()->Num();
	int const min_index = 0;
	int const max_index = no_of_points - 1;

	// get and set the black board index key
	int index = controller->get_blackboard()->GetValueAsInt(bb_keys::patrol_path_index);
	if (bidirectional)
	{
		if (index >= max_index && direction == EDirectionType::Forward)
		{
			direction = EDirectionType::Reverse;
		}
		else if (index == min_index && direction == EDirectionType::Reverse)
		{
			direction = EDirectionType::Forward;
		}
	}
	// "std::abs(...)" here prevents negative values from causing a crash
	controller->get_blackboard()->SetValueAsInt(bb_keys::patrol_path_index,
		(direction == EDirectionType::Forward ? std::abs(++index) : std::abs(--index)) % no_of_points);


	// finish with success
	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

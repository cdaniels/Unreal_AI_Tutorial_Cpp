// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPatrolPathPoint_BTTask.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC.h"
#include "blackboard_keys.h"

UFindPatrolPathPoint_BTTask::UFindPatrolPathPoint_BTTask(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Pantrol Path Point");
}

EBTNodeResult::Type UFindPatrolPathPoint_BTTask::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	// get the AI controller for the patrolling NPC
	ANPC_AIController* const controller = Cast<ANPC_AIController>(owner_comp.GetAIOwner());

	// get the current patrol path index from the blackboard
	int const index = controller->get_blackboard()->GetValueAsInt(bb_keys::patrol_path_index);

	// use the index to get the current patrol path from the NPC's reference to the patrol path
	ANPC* const npc = Cast<ANPC>(controller->GetPawn());
	FVector const point = npc->GetPatrolPath()->GetPatrolPoint(index);

	// transform this point to world space using its parent
	FVector const global_point = npc->GetPatrolPath()->GetActorTransform().TransformPosition(point);

	// write the current global path point to the blackboard
	controller->get_blackboard()->SetValueAsVector(bb_keys::patrol_path_vector, global_point);

	// finish with success
	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

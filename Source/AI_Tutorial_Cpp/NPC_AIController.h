// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "NPC_AIController.generated.h"

/**
 * 
 */
UCLASS()
class AI_TUTORIAL_CPP_API ANPC_AIController : public AAIController
{
	GENERATED_BODY()

public:
	ANPC_AIController(FObjectInitializer const& object_initializer = FObjectInitializer::Get());

	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
	class UBlackboardComponent* get_blackboard() const;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* btree_component;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess = "true"))
	class UBehaviorTree* btree;

	class UBlackboardComponent* blackboard;

	class UAISenseConfig_Sight* sight_config;

	UFUNCTION()
	void on_target_detected(AActor* actor, FAIStimulus const stimulus);

	// UFUNCTION()
	// void on_updated(TArray<AActor*> const& updated_actor);

	void setup_perception_system();
};

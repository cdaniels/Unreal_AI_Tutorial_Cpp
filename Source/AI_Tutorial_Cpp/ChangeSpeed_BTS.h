// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "ChangeSpeed_BTS.generated.h"

/**
 * 
 */
UCLASS()
class AI_TUTORIAL_CPP_API UChangeSpeed_BTS : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UChangeSpeed_BTS();
	void OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;

protected:
	FString GetStaticServiceDescription() const override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	float speed = 600.0f;
};

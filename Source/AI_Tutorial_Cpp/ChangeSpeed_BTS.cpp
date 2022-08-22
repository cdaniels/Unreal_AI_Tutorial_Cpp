// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeSpeed_BTS.h"
#include "NPC.h"
#include "AIController.h"

#include "GameFramework/CharacterMovementComponent.h"

UChangeSpeed_BTS::UChangeSpeed_BTS()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Change Speed");
}

void UChangeSpeed_BTS::OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	Super::OnBecomeRelevant(owner_comp, node_memory);
	auto const cont = owner_comp.GetAIOwner();
	ANPC* const npc = Cast<ANPC>(cont->GetPawn());
	npc->GetCharacterMovement()->MaxWalkSpeed = speed;
}

FString UChangeSpeed_BTS::GetStaticServiceDescription() const
{
	return FString("Change the NPC speed");
}

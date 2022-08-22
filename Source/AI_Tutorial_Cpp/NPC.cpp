// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

// user includes
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// rotation fix
	bUseControllerRotationYaw = false;
	// GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

int ANPC::MeleeAttack_Implementation()
{
	if (montage)
	{
		PlayAnimMontage(montage);
	}
	return 0;
}

UAnimMontage* ANPC::GetMontage() const
{
	return montage;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
	// set material color of character
	UMaterialInstanceDynamic* const material_instance = UMaterialInstanceDynamic::Create(GetMesh()->GetMaterial(0), this);
	if(material_instance)
	{
		material_instance->SetVectorParameterValue("BodyColor", FLinearColor(1.0f, 0.0f, 0.0f, 1.0f));
		GetMesh()->SetMaterial(0, material_instance);
	}

}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

APatrolPath* ANPC::GetPatrolPath()
{
	return patrol_path;
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// generated includes
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolPath.h"
#include "CombatInterface.h"
#include "Animation/AnimMontage.h"
#include "NPC.generated.h"


UCLASS()
class AI_TUTORIAL_CPP_API ANPC : public ACharacter, public ICombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APatrolPath* GetPatrolPath();

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	//int MeleeAttack();

	int MeleeAttack_Implementation() override;

	UAnimMontage* GetMontage() const;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	APatrolPath* patrol_path;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* montage;

};

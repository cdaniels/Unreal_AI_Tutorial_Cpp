// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_Tutorial_CppGameMode.h"
#include "AI_Tutorial_CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_Tutorial_CppGameMode::AAI_Tutorial_CppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

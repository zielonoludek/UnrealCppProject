// Copyright Epic Games, Inc. All Rights Reserved.

#include "CppProjectGameMode.h"
#include "CppProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACppProjectGameMode::ACppProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

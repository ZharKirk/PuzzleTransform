// Copyright Epic Games, Inc. All Rights Reserved.

#include "PuzzleTransformGameMode.h"
#include "PuzzleTransformCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzleTransformGameMode::APuzzleTransformGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
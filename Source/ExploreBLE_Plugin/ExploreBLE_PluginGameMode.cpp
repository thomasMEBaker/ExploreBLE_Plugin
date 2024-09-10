// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExploreBLE_PluginGameMode.h"
#include "ExploreBLE_PluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExploreBLE_PluginGameMode::AExploreBLE_PluginGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

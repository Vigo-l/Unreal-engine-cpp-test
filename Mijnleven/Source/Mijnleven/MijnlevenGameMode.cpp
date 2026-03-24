// Copyright Epic Games, Inc. All Rights Reserved.

#include "MijnlevenGameMode.h"
#include "MijnlevenPlayerController.h"
#include "MyPlayerCharacter.h"

AMijnlevenGameMode::AMijnlevenGameMode()
{
	DefaultPawnClass = AMyPlayerCharacter::StaticClass();
	PlayerControllerClass = AMijnlevenPlayerController::StaticClass();
}

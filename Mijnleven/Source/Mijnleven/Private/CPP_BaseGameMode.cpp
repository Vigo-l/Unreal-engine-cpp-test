// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseGameMode.h"
#include "MijnlevenPlayerController.h"
#include "MyPlayerCharacter.h"

ACPP_BaseGameMode::ACPP_BaseGameMode()
{
	DefaultPawnClass = AMyPlayerCharacter::StaticClass();
	PlayerControllerClass = AMijnlevenPlayerController::StaticClass();
}


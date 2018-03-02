// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
AMainGameMode::AMainGameMode()
{
	ConstructorHelpers::FClassFinder<ACharacter> CharacterFinder(TEXT("/Game/Character/Blueprint/BP_XCharacter"));
	DefaultPawnClass = CharacterFinder.Class;
	PlayerControllerClass = AXPlayerController::StaticClass();
	
}





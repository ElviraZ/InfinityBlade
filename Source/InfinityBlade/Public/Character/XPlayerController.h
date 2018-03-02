// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XCharacter.h"
#include "UI/MainUserWidget.h"
#include "XPlayerController.generated.h"

/**
 * Ö÷½ÇµÄ¿ØÖÆÆ÷
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY()
	AXCharacter* XCharacter;

public:
	virtual  void   SetupInputComponent()  override   ;
	UPROPERTY()
		UMainUserWidget* MainUserWidget;
	virtual void  BeginPlay()  override;
	UFUNCTION()
		void  MoveForward(float speed);
	UFUNCTION()
		void  MoveRight(float speed);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/Image.h"
#include"Components/Button.h"
#include"Components/ProgressBar.h"
#include"Components/EditableTextBox.h"
#include "MainUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
		UProgressBar*  ProgressBarHP;
	UPROPERTY()
		UProgressBar*  ProgressBarMP;
	UPROPERTY()
		UProgressBar*  ProgressBarMax;
		UPROPERTY()
		UButton*  RankButton;
	UPROPERTY()
		UButton*  PackageButton;
	UPROPERTY()
		UButton* SettiingButton;
	UPROPERTY()
		UButton*  AttackButton;
	UPROPERTY()
		UButton*  IceStoneButton;
	UPROPERTY()
		UButton*  CureButton;
	UPROPERTY()
		UButton*  ThunderButton;
	UPROPERTY()
		UButton*  XBladeButton;
public:  
	virtual  bool  Initialize() override;

};

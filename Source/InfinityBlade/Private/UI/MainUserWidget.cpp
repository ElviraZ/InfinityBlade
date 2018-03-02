// Fill out your copyright notice in the Description page of Project Settings.

#include "MainUserWidget.h"

bool UMainUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	//注册按钮以及点击事件绑定
	ProgressBarHP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_HP")));
	ProgressBarMP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_MP")));
	ProgressBarMax = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_Max")));

	RankButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Rank")));
	PackageButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Package")));
	SettiingButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Setting")));
	AttackButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Attack")));
	IceStoneButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_IceStone")));
	CureButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Cure")));
	ThunderButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Thunder")));
	XBladeButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_XBlade")));

	return true;
}



// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"

void AStartGameMode::BeginPlay()
{
	Startwidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartUserWidget.BP_StartUserWidget_c'")));
	if (Startwidget != NULL)
	{
		Startwidget->AddToViewport();
	Startwidget->RegisterBtn->OnClicked.AddDynamic(this, &AStartGameMode::RegisterBtnClickEvent);
	Startwidget->StartBtn->OnClicked.AddDynamic(this, &AStartGameMode::StartBtnClickEvent);
	}
	Registerwidget = CreateWidget<URegisterUserWidget>(GetGameInstance(), LoadClass<URegisterUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_RegisterUserWidget.BP_RegisterUserWidget_c'")));
	if (Registerwidget!=NULL)
	{
	Registerwidget->BackBtn->OnClicked.AddDynamic(this, &AStartGameMode::BackBtnClickEvent);

	}
	Loginwidget = CreateWidget<ULoginUserWidget>(GetGameInstance(), LoadClass<ULoginUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_LoginUserWidget.BP_LoginUserWidget_c'")));
	if (Loginwidget != NULL)
	{
		Loginwidget->BackBtn->OnClicked.AddDynamic(this, &AStartGameMode::LoginBackBtnClickEvent);

	}
}

//ע�ᰴť����¼�
void AStartGameMode::RegisterBtnClickEvent()
{
		Registerwidget->AddToViewport();
		//�Ƴ�StartWidget
		Startwidget->RemoveFromParent();
}

//Back��ť����¼�
void AStartGameMode::BackBtnClickEvent()
{
		Startwidget->AddToViewport();
		//�Ƴ�StartWidget
		Registerwidget->RemoveFromParent();
	}

void AStartGameMode::LoginBackBtnClickEvent()
{
	Startwidget->AddToViewport();
	//�Ƴ�StartWidget
	Loginwidget->RemoveFromParent();
}

//Back��ť����¼�
void AStartGameMode::StartBtnClickEvent()
{
	//�Ƴ�StartWidget
	Startwidget->RemoveFromParent();

	Loginwidget->AddToViewport();
}






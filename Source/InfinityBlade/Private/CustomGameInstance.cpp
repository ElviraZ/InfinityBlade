// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"
#include"Runtime/MoviePlayer/Public/MoviePlayer.h"

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
	loaduserwidget = CreateWidget<ULoadUserWidget>(this, LoadClass<ULoadUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_LoadUserWidget.BP_LoadUserWidget_c'")));
}

//��ͼ��ʼ����
void UCustomGameInstance::PreLoadMap(const  FString& map)
{
	if (map.Equals("/Game/Map/Map_Main"))
	{
		/** ����һ����Ļ�������Զ��� */
		FLoadingScreenAttributes LoadingAttr;
		/** �ֶ��ĵ���������� */
		LoadingAttr.bWaitForManualStop = true;
		/** ���ü��ص�Widget */
		LoadingAttr.WidgetLoadingScreen = loaduserwidget->TakeWidget();
		/** ���ü�����Ļ */
		GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);

	}

	
//	loaduserwidget->AddToViewport();
}

//��ͼ���ؽ���
void UCustomGameInstance::PostLoadMap(UWorld*  world)
{

//	loaduserwidget->LoadComplete();
}

/** �Ƿ������� */
bool UCustomGameInstance::GetLoadStatus()
{
	/** �����Ƿ��Ѿ��������SS */
	return GetMoviePlayer()->IsLoadingFinished();
}

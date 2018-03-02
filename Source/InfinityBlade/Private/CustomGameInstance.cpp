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

//地图开始加载
void UCustomGameInstance::PreLoadMap(const  FString& map)
{
	if (map.Equals("/Game/Map/Map_Main"))
	{
		/** 创建一个屏幕加载属性对象 */
		FLoadingScreenAttributes LoadingAttr;
		/** 手动的点击跳过加载 */
		LoadingAttr.bWaitForManualStop = true;
		/** 设置加载的Widget */
		LoadingAttr.WidgetLoadingScreen = loaduserwidget->TakeWidget();
		/** 设置加载屏幕 */
		GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);

	}

	
//	loaduserwidget->AddToViewport();
}

//地图加载结束
void UCustomGameInstance::PostLoadMap(UWorld*  world)
{

//	loaduserwidget->LoadComplete();
}

/** 是否加载完成 */
bool UCustomGameInstance::GetLoadStatus()
{
	/** 返回是否已经加载完成SS */
	return GetMoviePlayer()->IsLoadingFinished();
}

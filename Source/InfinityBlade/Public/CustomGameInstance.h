// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include"Runtime/MoviePlayer/Public/MoviePlayer.h"

#include "UI/LoadUserWidget.h"
#include "CustomGameInstance.generated.h"

/**
 * 游戏实例
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
		//集合
		TMap<FString, FString>  ContextMap;
		UPROPERTY()
			ULoadUserWidget *  loaduserwidget;

public:
	  //初始化的方法
	virtual void  Init() override;
	UFUNCTION()
		void  PreLoadMap(const  FString& map);
	UFUNCTION()
		void  PostLoadMap(UWorld*  world);
	/** 是否加载完成 */
	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		bool GetLoadStatus();
};

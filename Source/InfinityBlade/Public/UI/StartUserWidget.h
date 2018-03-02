// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/Button.h"
#include"Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include"Runtime/Engine/Classes/Engine/Engine.h"
#include "StartUserWidget.generated.h"

/**
 * 游戏开始界面
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	//开始游戏按钮
	UPROPERTY()
	UButton *  StartBtn;
	UPROPERTY()
	UButton *  RegisterBtn;
	UPROPERTY()
	UButton *  QuitBtn;
	//创建控件完成后初始化方法
	virtual  bool  Initialize() override;

	UFUNCTION(BlueprintCallable, Category = "BtnClickEvent")
		void   StartBtnClickEvent();
	UFUNCTION(BlueprintCallable, Category = "BtnClickEvent")
		void   RegisterBtnClickEvent();
	UFUNCTION(BlueprintCallable, Category = "BtnClickEvent")
		void   QuitBtnClickEvent();
	
};

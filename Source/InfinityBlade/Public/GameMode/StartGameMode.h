// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UI/StartUserWidget.h"
#include "UI/LoginUserWidget.h"
#include "UI/RegisterUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * 游戏开始界面的游戏模式
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		UStartUserWidget*  Startwidget;
	UPROPERTY()
		URegisterUserWidget*  Registerwidget;
	UPROPERTY()
		ULoginUserWidget*  Loginwidget;
public:
	virtual void BeginPlay()  override;
	//注册账号按钮点击事件
	UFUNCTION()
		void  RegisterBtnClickEvent();
	UFUNCTION()
		void  BackBtnClickEvent();

	UFUNCTION()
		void  StartBtnClickEvent();
	UFUNCTION()
		void  LoginBackBtnClickEvent();
	
};

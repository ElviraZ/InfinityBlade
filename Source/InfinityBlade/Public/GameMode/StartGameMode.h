// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UI/StartUserWidget.h"
#include "UI/LoginUserWidget.h"
#include "UI/RegisterUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * ��Ϸ��ʼ�������Ϸģʽ
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
	//ע���˺Ű�ť����¼�
	UFUNCTION()
		void  RegisterBtnClickEvent();
	UFUNCTION()
		void  BackBtnClickEvent();

	UFUNCTION()
		void  StartBtnClickEvent();
	UFUNCTION()
		void  LoginBackBtnClickEvent();
	
};

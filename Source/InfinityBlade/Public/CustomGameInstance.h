// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include"Runtime/MoviePlayer/Public/MoviePlayer.h"

#include "UI/LoadUserWidget.h"
#include "CustomGameInstance.generated.h"

/**
 * ��Ϸʵ��
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
		//����
		TMap<FString, FString>  ContextMap;
		UPROPERTY()
			ULoadUserWidget *  loaduserwidget;

public:
	  //��ʼ���ķ���
	virtual void  Init() override;
	UFUNCTION()
		void  PreLoadMap(const  FString& map);
	UFUNCTION()
		void  PostLoadMap(UWorld*  world);
	/** �Ƿ������� */
	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		bool GetLoadStatus();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/Button.h"
#include"Components/TextBlock.h"
#include "MessageUserWidget.generated.h"

/**
 * 提示框UI
 */
UCLASS()
class INFINITYBLADE_API UMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()
	public:
		UPROPERTY()
		UButton *  CloseBtn;
	UPROPERTY()
		UTextBlock *  TextMsg;
	
	//创建控件完成后初始化方法
	virtual  bool  Initialize() override;
	UFUNCTION(BlueprintCallable, Category = "BtnClickEvent")
		void   CloseBtnClickEvent();
};

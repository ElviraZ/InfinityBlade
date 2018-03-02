// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/Image.h"
#include"Components/TextBlock.h"
#include"Components/CircularThrobber.h"
#include "LoadUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API ULoadUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
		UTextBlock*   NextText;
	UPROPERTY()
		UTextBlock*   loadingText;
	UPROPERTY()
		UCircularThrobber *  CircularThrobber_Loading;
	
	//创建控件完成后初始化方法
	virtual  bool  Initialize() override;
	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		void   LoadComplete();
};

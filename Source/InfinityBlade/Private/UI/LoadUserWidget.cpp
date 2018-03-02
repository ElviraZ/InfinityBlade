// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadUserWidget.h"


bool ULoadUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//退出按钮以及点击事件绑定
	NextText = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Next")));
	loadingText = Cast<UTextBlock>(GetWidgetFromName(TEXT("loadingText")));
	CircularThrobber_Loading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("Loading")));
	return true;
}

void ULoadUserWidget::LoadComplete()
{
	CircularThrobber_Loading->SetVisibility(ESlateVisibility::Hidden);
	NextText->SetVisibility(ESlateVisibility::Visible);
	loadingText->SetVisibility(ESlateVisibility::Hidden);
}


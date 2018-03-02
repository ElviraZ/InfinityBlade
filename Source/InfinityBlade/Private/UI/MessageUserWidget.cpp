// Fill out your copyright notice in the Description page of Project Settings.

#include "MessageUserWidget.h"


bool UMessageUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//注册按钮以及点击事件绑定
	CloseBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Close")));
	CloseBtn->OnClicked.AddDynamic(this, &UMessageUserWidget::CloseBtnClickEvent);
	TextMsg = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Msg")));
	return true;
}

void UMessageUserWidget::CloseBtnClickEvent()
{
	this->SetVisibility(ESlateVisibility::Hidden);

}

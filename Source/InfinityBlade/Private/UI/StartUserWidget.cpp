// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"

//创建控件完成后初始化方法
bool UStartUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
			return false;
	}
	//开始按钮以及点击事件绑定
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));
	StartBtn->OnClicked.AddDynamic(this, &UStartUserWidget::StartBtnClickEvent);
	//注册按钮以及点击事件绑定
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	RegisterBtn->OnClicked.AddDynamic(this, &UStartUserWidget::RegisterBtnClickEvent);
	//退出按钮以及点击事件绑定
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));
	QuitBtn->OnClicked.AddDynamic(this, &UStartUserWidget::QuitBtnClickEvent);
	return true;

}

void UStartUserWidget::StartBtnClickEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f,FColor::Red, TEXT("Button_Start"));
	 //UE_LOG(LogTemp, Warning, TEXT("StartBtnClick"));

}
void UStartUserWidget::RegisterBtnClickEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("RegisterBtnClick"));
	//UE_LOG(LogTemp, Warning, TEXT("RegisterBtnClick"));
}
void UStartUserWidget::QuitBtnClickEvent()
{
	//退出游戏
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("QuitBtnClick"));
	//	UE_LOG(LogTemp, Warning, TEXT("QuitBtnClick"));
	UKismetSystemLibrary::QuitGame(GetWorld(),NULL,EQuitPreference::Quit);
}

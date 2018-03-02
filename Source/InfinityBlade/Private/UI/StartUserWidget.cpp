// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"

//�����ؼ���ɺ��ʼ������
bool UStartUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
			return false;
	}
	//��ʼ��ť�Լ�����¼���
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));
	StartBtn->OnClicked.AddDynamic(this, &UStartUserWidget::StartBtnClickEvent);
	//ע�ᰴť�Լ�����¼���
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	RegisterBtn->OnClicked.AddDynamic(this, &UStartUserWidget::RegisterBtnClickEvent);
	//�˳���ť�Լ�����¼���
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
	//�˳���Ϸ
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("QuitBtnClick"));
	//	UE_LOG(LogTemp, Warning, TEXT("QuitBtnClick"));
	UKismetSystemLibrary::QuitGame(GetWorld(),NULL,EQuitPreference::Quit);
}

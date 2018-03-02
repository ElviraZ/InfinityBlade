// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/Button.h"
#include"Components/EditableTextBox.h"
#include "UI/MessageUserWidget.h"
#include"Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include"Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include"Components/CircularThrobber.h"
#include"Runtime/Online/HTTP/Public/HttpModule.h"
#include"Runtime/Engine/Classes/Engine/Engine.h"
#include "RegisterUserWidget.generated.h"

/**
 * ע�����Widget
 */
UCLASS()
class INFINITYBLADE_API URegisterUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:


	UPROPERTY()
		UButton *  RegisterBtn;
	UPROPERTY()
		UButton *  BackBtn;
	UPROPERTY()
		UEditableTextBox *  NickName;
	UPROPERTY()
		UEditableTextBox *  Password;
		UPROPERTY()
			UEditableTextBox *  RePassword;
		UPROPERTY()
			UMessageUserWidget*   messageUserWidget;
		UPROPERTY()
	UCircularThrobber *  CircularThrobber_Loading;
		
	//�����ؼ���ɺ��ʼ������
	virtual  bool  Initialize() override;


	UFUNCTION(BlueprintCallable, Category = "BtnClickEvent")
		void   RegisterBtnClickEvent();
	UFUNCTION(BlueprintCallable, Category = "BtnClickEvent")
		void   BackBtnClickEvent();
	UFUNCTION()
		bool   CheckInput(FString& s1, FString& s2, FString&  s3);
	//���ݿ�ע���˺�
	void   AccountRegisterToServer(FString& name, FString& password);

	void  AccountRegisterResponse(FHttpRequestPtr   requestPtr,FHttpResponsePtr   responsePtr,bool  bIsSuccess );
};

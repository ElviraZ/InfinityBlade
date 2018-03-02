// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/Button.h"
#include"Components/EditableTextBox.h"
#include "UI/MessageUserWidget.h"
#include "CustomGameInstance.h"
#include"Components/CircularThrobber.h"
#include"Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include"Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include"Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include"Runtime/Engine/Classes/Engine/Engine.h"
#include"Runtime/Online/HTTP/Public/HttpModule.h"
#include "LoginUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
		UPROPERTY()
		UButton *  BackBtn;
		UPROPERTY()
			UButton *  LoginBtn;
	UPROPERTY()
		UEditableTextBox *  NickName;
	UPROPERTY()
		UEditableTextBox *  Password;
	UPROPERTY()
		UMessageUserWidget*   messageUserWidget;


	UPROPERTY()
		UCircularThrobber *  CircularThrobber_Loading;
	//创建控件完成后初始化方法
	virtual  bool  Initialize() override;


	UFUNCTION()
		void  LoginBtnClickEvent();


	UFUNCTION()
		void  AccountLoginToServer(FString nameStr, FString passwordStr);
	void AccountLoginResponse(FHttpRequestPtr requestPtr, FHttpResponsePtr responsePtr, bool bIsSuccess);
};

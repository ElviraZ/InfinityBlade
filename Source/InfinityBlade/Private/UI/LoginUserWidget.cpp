// Fill out your copyright notice in the Description page of Project Settings.

#include "LoginUserWidget.h"
bool ULoginUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//退出按钮以及点击事件绑定
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	LoginBtn->OnClicked.AddDynamic(this, &ULoginUserWidget::LoginBtnClickEvent);
	NickName = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_NickName")));
	Password = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	messageUserWidget = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageUserWidget")));
	CircularThrobber_Loading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Loading222")));
	return true;
}
//登陆账号
void ULoginUserWidget::LoginBtnClickEvent()
{
	FString  nameinfo = NickName->GetText().ToString();
	FString  passwordinfo = Password->GetText().ToString();
	//校验名字长度
	if (nameinfo.IsEmpty())
	{
		messageUserWidget->SetVisibility(ESlateVisibility::Visible);
		messageUserWidget->TextMsg->SetText(FText::FromString("Name Cann't null"));
		return;
	}
	if (passwordinfo.IsEmpty())
	{
		messageUserWidget->SetVisibility(ESlateVisibility::Visible);
		messageUserWidget->TextMsg->SetText(FText::FromString("Passwords Cann't null"));
		return;
	}
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, nameinfo + "    " + passwordinfo);
	AccountLoginToServer(nameinfo, passwordinfo);
	CircularThrobber_Loading->SetVisibility(ESlateVisibility::Visible);
	LoginBtn->SetIsEnabled(false);
}
void ULoginUserWidget::AccountLoginToServer(FString nameStr, FString passwordStr)
{

	//1、设置http
	TSharedRef< IHttpRequest>    httpRequest = FHttpModule::Get().CreateRequest();
	httpRequest->SetVerb("POST");
	httpRequest->SetURL("http://192.168.30.2:8888/user/login-user?nickname=" + nameStr + "&password=" + passwordStr);
	httpRequest->OnProcessRequestComplete().BindUObject(this, &ULoginUserWidget::AccountLoginResponse);
	//2、请求
	httpRequest->ProcessRequest();
}
void ULoginUserWidget::AccountLoginResponse(FHttpRequestPtr requestPtr, FHttpResponsePtr responsePtr, bool bIsSuccess)
{
	CircularThrobber_Loading->SetVisibility(ESlateVisibility::Hidden);
	LoginBtn->SetIsEnabled(true);
	if (!EHttpResponseCodes::IsOk(responsePtr->GetResponseCode()))
		return;
	FString  Data = responsePtr->GetContentAsString();
	TSharedPtr<FJsonObject>  JsonObject;
	TSharedRef<TJsonReader<TCHAR>>  JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
	bool  bIsParse = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	if (bIsParse)
	{
		FString  msg = JsonObject->GetStringField("msg");
		TSharedPtr<FJsonObject> jsondata = JsonObject->GetObjectField("data");
		FString  id = jsondata->GetStringField("id");
		FString  name = jsondata->GetStringField("nickname");
		if (!name.IsEmpty())
		{
			UCustomGameInstance*    GameInstance = Cast<UCustomGameInstance>(GetWorld()->GetGameInstance());
			GameInstance->ContextMap.Add("id", id);
			//登陆成功，切换关卡
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Map/Map_Main"));
		}
		else
		{
			messageUserWidget->SetVisibility(ESlateVisibility::Visible);
			messageUserWidget->TextMsg->SetText(FText::FromString(msg));
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterUserWidget.h"

bool URegisterUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	//注册按钮以及点击事件绑定
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	RegisterBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::RegisterBtnClickEvent);
	//退出按钮以及点击事件绑定
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	BackBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::BackBtnClickEvent);

	NickName = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_NickName")));
	Password = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	RePassword = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_RePassword")));
	CircularThrobber_Loading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("Loading")));

	messageUserWidget = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageUserWidget")));
	return true;
}

void URegisterUserWidget::RegisterBtnClickEvent()
{
	FString  name = NickName->GetText().ToString();
	FString  password = Password->GetText().ToString();
	FString  repassword = RePassword->GetText().ToString();


	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, name+"   "+ password +"   "+ repassword);
	//校验名字长度
	if (name.Len()<2 || name.Len()>6)
	{
		messageUserWidget->SetVisibility(ESlateVisibility::Visible);
		messageUserWidget->TextMsg->SetText(FText::FromString("Name Length is illegal"));
		return;
	}
	if ( password.Len() <= 0 || repassword.Len() <= 2)
	{
		messageUserWidget->SetVisibility(ESlateVisibility::Visible);
		messageUserWidget->TextMsg->SetText(FText::FromString("Passwords Cann't null"));
		return;
	}
	//校验两次密码是否相等
	if (!password.Equals(repassword))
	{
		messageUserWidget->SetVisibility(ESlateVisibility::Visible);
		messageUserWidget->TextMsg->SetText(FText::FromString("Passwords Are Not Same"));
		return;
	}

	CircularThrobber_Loading->SetVisibility(ESlateVisibility::Visible);
	RegisterBtn->SetIsEnabled(false);
	AccountRegisterToServer(name, password);
}


void URegisterUserWidget::BackBtnClickEvent()
{



}



bool URegisterUserWidget::CheckInput(FString& s1, FString& s2, FString&  s3)
{


	return  true;


}

void URegisterUserWidget::AccountRegisterToServer(FString& name, FString& password)
{
	
	//1、生成json格式数据
	//FString   RegisterInfo;
	//TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>>    JsonWriter=   TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	////开始写入数据
	//JsonWriter->WriteObjectStart();
	//JsonWriter->WriteValue("nickname", name);
	//JsonWriter->WriteValue("password", password);
	//JsonWriter->WriteObjectEnd();
	//JsonWriter->Close();
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, RegisterInfo);

	//2、设置http
	TSharedRef< IHttpRequest>    httpRequest = FHttpModule::Get(). CreateRequest();
	httpRequest->SetVerb("POST");
	httpRequest->SetURL("http://192.168.30.2:8888/user/register-user?nickname="+name+"&password="+password);


	httpRequest->OnProcessRequestComplete().BindUObject(this, &URegisterUserWidget::AccountRegisterResponse);

	//3、请求
	httpRequest->ProcessRequest();
}

void URegisterUserWidget::AccountRegisterResponse(FHttpRequestPtr requestPtr, FHttpResponsePtr responsePtr, bool bIsSuccess)
{
	CircularThrobber_Loading->SetVisibility(ESlateVisibility::Hidden);
	RegisterBtn->SetIsEnabled(true);
	if (!EHttpResponseCodes::IsOk(responsePtr->GetResponseCode()))
		return;
	 FString  Data= responsePtr->GetContentAsString();
TSharedPtr<FJsonObject>  JsonObject;
TSharedRef<TJsonReader<TCHAR>>  JsonReader=	 TJsonReaderFactory<TCHAR>::Create(Data);
bool  bIsParse=  FJsonSerializer::Deserialize(JsonReader, JsonObject);
if (bIsParse)
{
	FString  Status=JsonObject->GetStringField("status");
	FString  Msg = JsonObject->GetStringField("msg");
	//FString  Status = JsonObject->GetObjectField("data");
	messageUserWidget->SetVisibility(ESlateVisibility::Visible);
	messageUserWidget->TextMsg->SetText(FText::FromString(Msg));
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, Status+"    "+Msg);
}
}

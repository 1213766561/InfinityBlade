// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Register.h"
#include"Engine/Engine.h"
#include"JsonWriter.h"
#include"HttpModule.h"
#include"Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include"Runtime/Json/Public/Serialization/JsonSerializer.h"


bool UUserWidget_Register::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	/* ��ʼ�����ذ�ť*/
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	/* ��ʼ���ǳ������*/
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	/* ��ʼ�����������*/
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	/* ��ʼ���ٴ����������*/
	RePasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_RePassword")));
	/* ��ʼ��ע�ᰴť*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	/* ע�ᰴť����¼��ص�*/
	RegisterBtn->OnClicked.AddDynamic(this, &UUserWidget_Register::RegisterBtnOnClickedEvent);

	return true;
}




/* ע�ᰴť����¼�*/
void UUserWidget_Register::RegisterBtnOnClickedEvent()
{
	/* ��ȡ�ǳ�*/
	FString Nickname = NicknameInput->GetText().ToString();
	/* ��ȡ����*/
	FString Password = PasswordInput->GetText().ToString();
	/* ����ظ�����*/
	FString RePassword = RePasswordInput->GetText().ToString();

	/* �ǳƵĳ����Ƿ�һ��2~6*/
	if (Nickname.Len()<2||Nickname.Len()>6)
	{
		GEngine->AddOnScreenDebugMessage(-1,2.f, FColor::Red, TEXT("Nickname too Long,2~6"));
		return;
	}

	/* ��������������Ƿ�һ��*/
	if (!RePassword.Equals(Password))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Second Password is not Same"));
		return;
	}
	/* �����˺ŵ�ע��*/
	AccountRegisterFromServer(Nickname, Password);

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Nickname + "=" + Password + "=" + RePassword);
}

/* �˺�ע�᷽��*/
void UUserWidget_Register::AccountRegisterFromServer(FString & Nickname, FString & Password)
{
	/* ����Ҫ�ύ��JSon�ַ�*/
	FString RegisterInfo;
	/* ��������JSonд����*/
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR> >> TargetJson = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	/* ��ʼд������*/
	TargetJson->WriteObjectStart();
	/* д���ǳƵ�JSon*/
	TargetJson->WriteValue("nickname",Nickname);
	/* д�����뵽JSon*/
	TargetJson->WriteValue("password",Password);
	/* �ر�JSonд��*/
	TargetJson->WriteObjectEnd();
	/* �ر�JSonд����*/
	TargetJson->Close();

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, RegisterInfo);

	/* ���JSonInfo��HTTP����*/
	TSharedRef< IHttpRequest> TargetRequest = FHttpModule::Get().CreateRequest();
	/* ��������ʽ*/
	TargetRequest->SetVerb("POST");
	/* ��������ͷ*/
	TargetRequest->SetHeader("Content-Type", "application/json;charset=utf-8");
	/* ��������URL*/
	TargetRequest->SetURL("");
	/* �����ϴ�������*/
	TargetRequest->SetContentAsString(RegisterInfo);
	/* ��������ɹ���ί�еķ���*/
	TargetRequest->OnProcessRequestComplete().BindUObject(this, &UUserWidget_Register::RequestComplete);
	/* ���������*/
	TargetRequest->ProcessRequest();


}
/* ������Ӧ����*/
void UUserWidget_Register::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{
		/* ������δ��Ӧ*/
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Loss the Services"));
		return;
	}
	/* ��ȡ���ص�ֵ*/
	FString Data = ResponsePtr->GetContentAsString();
	/* ����һ��JSon�Ķ���*/
	TSharedPtr<FJsonObject> JsonObject;
	/* ����JSon������*/
	TSharedRef<TJsonReader<TCHAR >> CompleteJson = TJsonReaderFactory<TCHAR>::Create(Data);
	/* JSon�����л�*/
	bool BIsParse = FJsonSerializer::Deserialize(CompleteJson, JsonObject);
	/* �Ƿ�����ɹ�*/
	if (BIsParse)
	{
		FString Status = JsonObject->GetStringField("status");
		FString Msg = JsonObject->GetStringField("msg");
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Status);
	}
	/* ����ʧ��*/
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Loss the Status"));
}


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
	/* 初始化返回按钮*/
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	/* 初始化昵称输入框*/
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	/* 初始化密码输入框*/
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	/* 初始化再次输入密码框*/
	RePasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_RePassword")));
	/* 初始化注册按钮*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	/* 注册按钮点击事件回调*/
	RegisterBtn->OnClicked.AddDynamic(this, &UUserWidget_Register::RegisterBtnOnClickedEvent);

	return true;
}




/* 注册按钮点击事件*/
void UUserWidget_Register::RegisterBtnOnClickedEvent()
{
	/* 获取昵称*/
	FString Nickname = NicknameInput->GetText().ToString();
	/* 获取密码*/
	FString Password = PasswordInput->GetText().ToString();
	/* 获得重复密码*/
	FString RePassword = RePasswordInput->GetText().ToString();

	/* 昵称的长度是否一致2~6*/
	if (Nickname.Len()<2||Nickname.Len()>6)
	{
		GEngine->AddOnScreenDebugMessage(-1,2.f, FColor::Red, TEXT("Nickname too Long,2~6"));
		return;
	}

	/* 两次输入的密码是否一致*/
	if (!RePassword.Equals(Password))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Second Password is not Same"));
		return;
	}
	/* 进行账号的注册*/
	AccountRegisterFromServer(Nickname, Password);

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Nickname + "=" + Password + "=" + RePassword);
}

/* 账号注册方法*/
void UUserWidget_Register::AccountRegisterFromServer(FString & Nickname, FString & Password)
{
	/* 创建要提交的JSon字符*/
	FString RegisterInfo;
	/* 创建共享JSon写入器*/
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR> >> TargetJson = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	/* 开始写入数据*/
	TargetJson->WriteObjectStart();
	/* 写入昵称到JSon*/
	TargetJson->WriteValue("nickname",Nickname);
	/* 写入密码到JSon*/
	TargetJson->WriteValue("password",Password);
	/* 关闭JSon写入*/
	TargetJson->WriteObjectEnd();
	/* 关闭JSon写入器*/
	TargetJson->Close();

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, RegisterInfo);

	/* 输出JSonInfo到HTTP请求*/
	TSharedRef< IHttpRequest> TargetRequest = FHttpModule::Get().CreateRequest();
	/* 设置请求方式*/
	TargetRequest->SetVerb("POST");
	/* 设置请求头*/
	TargetRequest->SetHeader("Content-Type", "application/json;charset=utf-8");
	/* 设置请求URL*/
	TargetRequest->SetURL("");
	/* 设置上传的数据*/
	TargetRequest->SetContentAsString(RegisterInfo);
	/* 设置请求成功后委托的方法*/
	TargetRequest->OnProcessRequestComplete().BindUObject(this, &UUserWidget_Register::RequestComplete);
	/* 请求服务器*/
	TargetRequest->ProcessRequest();


}
/* 请求响应方法*/
void UUserWidget_Register::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{
		/* 服务器未响应*/
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Loss the Services"));
		return;
	}
	/* 获取返回的值*/
	FString Data = ResponsePtr->GetContentAsString();
	/* 创建一个JSon的对象*/
	TSharedPtr<FJsonObject> JsonObject;
	/* 创建JSon解析器*/
	TSharedRef<TJsonReader<TCHAR >> CompleteJson = TJsonReaderFactory<TCHAR>::Create(Data);
	/* JSon反序列化*/
	bool BIsParse = FJsonSerializer::Deserialize(CompleteJson, JsonObject);
	/* 是否解析成功*/
	if (BIsParse)
	{
		FString Status = JsonObject->GetStringField("status");
		FString Msg = JsonObject->GetStringField("msg");
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Status);
	}
	/* 解析失败*/
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Loss the Status"));
}


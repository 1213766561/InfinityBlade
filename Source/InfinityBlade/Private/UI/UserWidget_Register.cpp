// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Register.h"
#include"Engine/Engine.h"

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

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Nickname + "=" + Password + "=" + RePassword);
}

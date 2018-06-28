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
	NicknameInput = Cast<UTextBlock>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	/* 初始化密码输入框*/
	PasswordInput = Cast<UTextBlock>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	/* 初始化再次输入密码框*/
	RePasswordInput = Cast<UTextBlock>(GetWidgetFromName(TEXT("EditableTextBox_RePassword")));
	/* 初始化注册按钮*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	return true;
}

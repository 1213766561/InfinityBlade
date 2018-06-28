// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Register.h"
#include"Engine/Engine.h"

bool UUserWidget_Register::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	/* ��ʼ�����ذ�ť*/
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	/* ��ʼ���ǳ������*/
	NicknameInput = Cast<UTextBlock>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	/* ��ʼ�����������*/
	PasswordInput = Cast<UTextBlock>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	/* ��ʼ���ٴ����������*/
	RePasswordInput = Cast<UTextBlock>(GetWidgetFromName(TEXT("EditableTextBox_RePassword")));
	/* ��ʼ��ע�ᰴť*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	return true;
}

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

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Nickname + "=" + Password + "=" + RePassword);
}

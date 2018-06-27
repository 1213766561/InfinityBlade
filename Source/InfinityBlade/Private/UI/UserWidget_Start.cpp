// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Start.h"

bool UUserWidget_Start::Initialize()
{
	/* �жϰ�ť�Ƿ����*/
	if (!Super::Initialize())
	{
		return false;
	}
	
	/* ��ʼ����Ϸ��ʼ��ť*/
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));
	/* ��ʼ��ע����Ϸ��ť*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	/* ��ʼ���˳���Ϸ��ť*/
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	return true;
}

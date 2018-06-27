// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Start.h"
#include"Math/Color.h"
#include"Engine/Engine.h"

bool UUserWidget_Start::Initialize()
{
	/* 判断按钮是否存在*/
	if (!Super::Initialize())
	{
		return false;
	}
	
	/* 初始化游戏开始按钮*/
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));
	/* 初始化注册游戏按钮*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	/* 初始化退出游戏按钮*/
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));
	/* 退出游戏点击事件*/
	QuitBtn->OnClicked.AddDynamic(this, &UUserWidget_Start::QuitBtnOnClickedEvent);

	return true;
}
/* 退出游戏点击函数*/
void UUserWidget_Start::QuitBtnOnClickedEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("QuitGame"));
}
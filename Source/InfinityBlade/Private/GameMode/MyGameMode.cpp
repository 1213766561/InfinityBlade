// Fill out your copyright notice in the Description page of Project Settings.

#include"MyGameMode.h"
#include "LinkerLoad.h"
#include"UserWidget.h"
//#include "..\..\Public\GameMode\MyGameMode.h"
//#include"Math/Color.h"
//#include"Engine/Engine.h"


void AMyGameMode::BeginPlay()
{
/* 初始化初始界面*/
	StartWidget = CreateWidget<UUserWidget_Start>(GetGameInstance(),LoadClass<UUserWidget_Start>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Start.BP_Widget_Start_C'"))
);
	/* 添加到视口*/
	StartWidget->AddToViewport();
	/* 注册账号按钮的点击事件回调*/
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AMyGameMode::RegisterBtnOnClickedEvent);
	/* 初始化注册界面*/
	RegisterWidget = CreateWidget<UUserWidget_Register>(GetGameInstance(), LoadClass<UUserWidget_Register>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Register.BP_Widget_Register_C'")));
	/* 返回按钮点击事件回调*/
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this, &AMyGameMode::BackBtnOnClickedEvent);
}

/* 注册按钮点击事件*/
void AMyGameMode::RegisterBtnOnClickedEvent()
{
	/* 游戏开始界面移除*/
	StartWidget->RemoveFromViewport();
	/* 添加游戏注册界面*/
	RegisterWidget->AddToViewport();


}

void AMyGameMode::BackBtnOnClickedEvent()
{
	/* 注册界面移除*/
	RegisterWidget->RemoveFromViewport();
	/* 添加开始界面*/
	StartWidget->AddToViewport();

}


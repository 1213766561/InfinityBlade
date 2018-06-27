// Fill out your copyright notice in the Description page of Project Settings.

#include"MyGameMode.h"
#include "LinkerLoad.h"
#include"UserWidget.h"
//#include"Math/Color.h"
//#include"Engine/Engine.h"


void AMyGameMode::BeginPlay()
{
/* 初始化初始界面*/
	StartWidget = CreateWidget<UUserWidget_Start>(GetGameInstance(),LoadClass<UUserWidget_Start>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Start.BP_Widget_Start_C'"))
);
	/* 添加到视口*/
	StartWidget->AddToViewport();
}


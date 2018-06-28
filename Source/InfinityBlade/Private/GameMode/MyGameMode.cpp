// Fill out your copyright notice in the Description page of Project Settings.

#include"MyGameMode.h"
#include "LinkerLoad.h"
#include"UserWidget.h"
//#include "..\..\Public\GameMode\MyGameMode.h"
//#include"Math/Color.h"
//#include"Engine/Engine.h"


void AMyGameMode::BeginPlay()
{
/* ��ʼ����ʼ����*/
	StartWidget = CreateWidget<UUserWidget_Start>(GetGameInstance(),LoadClass<UUserWidget_Start>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Start.BP_Widget_Start_C'"))
);
	/* ��ӵ��ӿ�*/
	StartWidget->AddToViewport();
	/* ע���˺Ű�ť�ĵ���¼��ص�*/
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AMyGameMode::RegisterBtnOnClickedlEvent);
	/* ��ʼ��ע�����*/
	RegisterWidget = CreateWidget<UUserWidget_Register>(GetGameInstance(), LoadClass<UUserWidget_Register>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Register.BP_Widget_Register_C'")));

	
}

/* ע�ᰴť����¼�*/
void AMyGameMode::RegisterBtnOnClickedlEvent()
{
	/* ��Ϸ��ʼ�����Ƴ�*/
	StartWidget->RemoveFromViewport();
	/* �����Ϸע�����*/
	RegisterWidget->AddToViewport();


}


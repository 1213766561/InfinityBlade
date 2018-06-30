// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Start.h"
#include"Math/Color.h"
#include"Engine/Engine.h"
#include"Kismet/KismetSystemLibrary.h"

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
	/* �˳���Ϸ����¼�*/
	QuitBtn->OnClicked.AddDynamic(this, &UUserWidget_Start::QuitBtnOnClickedEvent);
	/* ��ʾ���*/
	
	return true;
}
/* �˳���Ϸ�������*/
void UUserWidget_Start::QuitBtnOnClickedEvent()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit);
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("QuitGame"));
}
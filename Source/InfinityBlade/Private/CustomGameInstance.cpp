// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"


//��ʼ������

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	//��ʼ��LoadingMap
	LoadingMap = CreateWidget<UUserWidget_LoadingMap>(this, LoadClass<UUserWidget_LoadingMap>(this,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Loading.BP_Widget_Loading_C'")));
	//��ʼ�����й�
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	//���������й�
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
}

void UCustomGameInstance::PreLoadMap(const FString& Map)
{
	//ͨ��Map�ж��Ƿ����Loading
	if (Map.Equals("/Game/Map/Map_Game"))
	{
		//��ü���Loading��Ĭ��API
		FLoadingScreenAttributes LoadingAttr;
		//�����Ƿ��ֶ��˳�Loading����
		LoadingAttr.bWaitForManualStop = true;
		//�Լ��ؽ����API�ṩ�Ľӿ����Widget
		LoadingAttr.WidgetLoadingScreen = LoadingMap->TakeWidget();
		//����Loading����
		GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);
		return;
	}
	
	//��Ϊ��ת�ؿ��س���vieport����Ӵ����ʹ��
	//LoadingMap->AddToViewport();
	return;
}

void UCustomGameInstance::PostLoadMap(UWorld * World)
{
	//���ؼ���Loading
	LoadingMap->CircularLoading->SetVisibility(ESlateVisibility::Hidden);
	//���ؼ����ı�
	LoadingMap->LoadingText->SetVisibility(ESlateVisibility::Hidden);
	//��ʾ���سɹ����ı�
	LoadingMap->SuccessText->SetVisibility(ESlateVisibility::Visible);
	//LoadingMap->RemoveFromViewport();
}


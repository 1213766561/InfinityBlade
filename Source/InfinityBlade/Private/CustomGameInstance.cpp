// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"


//初始化方法

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	//初始化LoadingMap
	LoadingMap = CreateWidget<UUserWidget_LoadingMap>(this, LoadClass<UUserWidget_LoadingMap>(this,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Loading.BP_Widget_Loading_C'")));
	//开始加载托管
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	//结束加载托管
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
}

void UCustomGameInstance::PreLoadMap(const FString& Map)
{
	//通过Map判断是否加载Loading
	if (Map.Equals("/Game/Map/Map_Game"))
	{
		//虚幻加载Loading的默认API
		FLoadingScreenAttributes LoadingAttr;
		//设置是否手动退出Loading界面
		LoadingAttr.bWaitForManualStop = true;
		//对加载界面的API提供的接口添加Widget
		LoadingAttr.WidgetLoadingScreen = LoadingMap->TakeWidget();
		//加载Loading界面
		GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);
		return;
	}
	
	//因为跳转关卡回撤销vieport，所哟不能使用
	//LoadingMap->AddToViewport();
	return;
}

void UCustomGameInstance::PostLoadMap(UWorld * World)
{
	//隐藏加载Loading
	LoadingMap->CircularLoading->SetVisibility(ESlateVisibility::Hidden);
	//隐藏加载文本
	LoadingMap->LoadingText->SetVisibility(ESlateVisibility::Hidden);
	//显示加载成功的文本
	LoadingMap->SuccessText->SetVisibility(ESlateVisibility::Visible);
	//LoadingMap->RemoveFromViewport();
}


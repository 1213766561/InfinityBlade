// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"


//初始化方法

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	//开始加载托管
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	//结束加载托管
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
}

void UCustomGameInstance::PreLoadMap(const FString& Map)
{

}

void UCustomGameInstance::PostLoadMap(UWorld * World)
{

}


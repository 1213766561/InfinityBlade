// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"


//��ʼ������

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	//��ʼ�����й�
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	//���������й�
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
}

void UCustomGameInstance::PreLoadMap(const FString& Map)
{

}

void UCustomGameInstance::PostLoadMap(UWorld * World)
{

}


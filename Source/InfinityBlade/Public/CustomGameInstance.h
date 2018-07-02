// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "UserWidget_LoadingMap.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"


/**
 * GameInstanceBase
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	//存储数据
	//TMap<FString, FString> ContexMap;
	UPROPERTY()
	FString CurrentPlayerName;

	//声明加载地图的Widget
	UPROPERTY()
		UUserWidget_LoadingMap* LoadingMap;

public:
	//初始化方法
	virtual void Init() override;


	//加载开始的函数
	UFUNCTION()
		void PreLoadMap(const FString& Map);
	//结束加载的函数
	UFUNCTION()
		void PostLoadMap(UWorld* World);
	
};
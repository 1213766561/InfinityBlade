// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include"UserWidget_Start.h"
#include"UserWidget_Register.h"
#include "MyGameMode.generated.h"

/**
 * 创建GameMode

 */
UCLASS()
class INFINITYBLADE_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	/* 游戏开始界面*/
	UPROPERTY()
		UUserWidget_Start* StartWidget;
	/* 游戏注册界面*/
	UPROPERTY()
	UUserWidget_Register* RegisterWidget;


public:
	/* 游戏开始调用方法*/
	virtual void BeginPlay() override;
	/* 注册按钮点击事件*/
	UFUNCTION()
		void RegisterBtnOnClickedlEvent();
	
};

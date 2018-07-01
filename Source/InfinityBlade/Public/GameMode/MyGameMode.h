// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include"UserWidget_Start.h"
#include"UserWidget_Register.h"
#include "UserWidget_Login.h"
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
	//申明游戏登陆界面
	UPROPERTY()
		UUserWidget_Login* LoginWidget;


public:
	/* 游戏开始调用方法*/
	virtual void BeginPlay() override;
	/* 注册按钮点击事件*/
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	/* 返回按钮点击事件*/
	UFUNCTION()
		void BackBtnOnClickedEvent();
	UFUNCTION()
		//开始按钮点击事件
		void StartBtnOnClikedEvent();
	UFUNCTION()
		//输入界面返回按钮事件
		void BlackBtnOnClickedEvent();
	/*开始打算写在GamoMode里面
	UFUNCTION()
		//进入游戏按钮点击事件声明
		void StarGameBtnOnClickedEvent();

	*/
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UserWidget_Start.generated.h"

/**
 * 创建UI控件
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Start : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/* 开始游戏按钮*/
	UPROPERTY()
		UButton* StartBtn;
	UPROPERTY()
		UButton* RegisterBtn;
	UPROPERTY()
		UButton* QuitBtn;

	
	
public:
	/* 判断按钮是否存在*/
	virtual bool  Initialize() override;
	/* 退出游戏点击函数*/
	UFUNCTION()
		void QuitBtnOnClickedEvent();

};

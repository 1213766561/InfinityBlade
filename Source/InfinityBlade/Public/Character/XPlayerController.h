// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCharacter.h"
#include "UserWidget_Game.h"
#include "XPlayerController.generated.h"

/**
 * 主角英雄控制器
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AXCharacter * XCharacter;
	//定义游戏界面UI
	UPROPERTY()
		UUserWidget_Game* MainUserWidget;
	
public:
	//游戏开始调用方法
	virtual void BeginPlay() override;
	//绑定输入控件
	virtual void SetupInputComponent() override;
	//绑定前后移动和左右移动的方法
	UFUNCTION()
		void MoveeForward(float Speed);
	UFUNCTION()
		void MoveRight(float Speed);
	

};

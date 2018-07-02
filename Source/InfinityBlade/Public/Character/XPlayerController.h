// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCharacter.h"
#include "UserWidget_Game.h"
#include "Weapon.h"
#include "Character/XAnimInstance.h"
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
	//武器对象
	UPROPERTY()
		AWeapon* XWeapon;
	//英雄角色动画实例
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	

	
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
	//攻击按钮点击事件
	UFUNCTION()
		void AttackBtnOnClickedEvent();
	//控件按钮初始化方法
	UFUNCTION()
		void InitWidgetEvent();
	


};

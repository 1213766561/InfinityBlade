// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCharacter.h"
#include "UserWidget_Game.h"
#include "Weapon.h"
#include "Character/XAnimInstance.h"
#include "XplayerState.h"
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
	UPROPERTY()
		AXPlayerState* XPlayerState;
	

	
public:
	//游戏开始调用方法
	virtual void BeginPlay() override;
	//possPlayeer实例
	virtual void Possess(APawn* aPawn) override;
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

	//初始化玩家的状态
		void SetupPlayerState();
	//初始化UI
		void InitUI();
	//武器伤害
		UFUNCTION()
			void WeaponOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};

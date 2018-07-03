// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"Character/XPlayerState.h"
#include "Animation/AnimInstance.h"
#include "XAnimInstance.generated.h"

/**
 * 动画实例
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	//定义速度变量
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	UPROPERTY()
		//声明PlayerState
		 AXPlayerState* PlayerState;
	UPROPERTY()
		//普通攻击的基本攻击
		 float NormalAttackDamage;
public:
	UFUNCTION()
		//重置普通攻击方法
		void RestAttackDamage();
		//连击加成伤害
	UFUNCTION()
		void UpdateSerialAttackDamage();
	//初始化PlayerState静态实例
	UFUNCTION()
		void InitPlayerState();

public:
	//更新人物的速度
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();
	//判断是否处于播放状态
public:
	UPROPERTY()
	bool bIsPlaying;
	//是否进入第二次连击
	bool bInEnableScondAttack;
	//是否进入第3次连击
	bool bInEnableThreeAttack;
	//是否进入第4次连击
	bool bInEnableFourAttack;
	//是否进入第5次连击
	bool bInEnableFiveAttack;


public:
	//初始化动作事件重载
	virtual void NativeInitializeAnimation() override;
	//开始播放蒙太奇
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);
	UFUNCTION()
	//结束播放蒙太奇
		void AnimNotify_PlayEnd(UAnimNotify* Notify);

	UFUNCTION()
			//重置连击状态
		void AnimNotify_ReseetAttackInput(UAnimNotify* Notify);
	//进入第二次连击
	UFUNCTION()
		void AnimNotify_SecondAttackInput(UAnimNotify* Notify);
	//进入第3次连击
	UFUNCTION()
		void AnimNotify_ThreeAttackInput(UAnimNotify* Notify);
	//进入第4次连击
	UFUNCTION()
		void AnimNotify_FourAttackInput(UAnimNotify* Notify);
	//进入第5次连击
	UFUNCTION()
		void AnimNotify_FiveAttackInput(UAnimNotify* Notify);
};

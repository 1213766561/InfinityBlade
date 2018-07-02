// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	//开始播放蒙太奇
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);
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

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIAnimInstance.generated.h"

/**
 * AI动画实例
 */
UCLASS()
class INFINITYBLADE_API UAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	//定义速度变量
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	//声明是否在攻击ing
	UPROPERTY()
		bool bIsAttack;
		




public:
	//更新速度
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();
	//攻击开始事件
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);
	UFUNCTION()
		//结束播放蒙太奇
		void AnimNotify_PlayEnd(UAnimNotify* Notify);


	
	
};

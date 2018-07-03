// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XPlayerState.generated.h"

/**
 * 玩家数据
 */
UCLASS()
class INFINITYBLADE_API AXPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	//普通攻击伤害
	float AttackDamage;
	//当前血量
	float CurrentHP;
	//当前的魔法值
	float CurrentMP;


public:
	
	//设置当前的血量
	FORCEINLINE float SetCurrentHP(float CurrentHP) {return this->CurrentHP = CurrentHP; };
	//获得当前的血量
	FORCEINLINE float GetCurrentHP() { return CurrentHP; };
	//设置当前的魔法值
	FORCEINLINE float SetCurrentMP(float CurrentMP) {return this->CurrentMP = CurrentMP; };
	//获得当前的魔法值
	FORCEINLINE float GetCurrentMP() { return CurrentMP; };
	//设置攻击伤害
	FORCEINLINE float SetAttackDamage(float AttackDamage) {return this->AttackDamage = AttackDamage;};
	//返回攻击伤害
	FORCEINLINE float GetAttackDamage() { return AttackDamage; };
	
	
};

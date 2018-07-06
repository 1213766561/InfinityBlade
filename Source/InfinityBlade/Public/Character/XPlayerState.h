// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XPlayerState.generated.h"

/**
 * �������
 */
UCLASS()
class INFINITYBLADE_API AXPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	//��ͨ�����˺�
	float AttackDamage;
	//��ǰѪ��
	float CurrentHP;
	//��ǰ��ħ��ֵ
	float CurrentMP;


public:
	
	//���õ�ǰ��Ѫ��
	FORCEINLINE float SetCurrentHP(float CurrentHP) {return this->CurrentHP = CurrentHP; };
	//��õ�ǰ��Ѫ��
	FORCEINLINE float GetCurrentHP() { return CurrentHP; };
	//���õ�ǰ��ħ��ֵ
	FORCEINLINE float SetCurrentMP(float CurrentMP) {return this->CurrentMP = CurrentMP; };
	//��õ�ǰ��ħ��ֵ
	FORCEINLINE float GetCurrentMP() { return CurrentMP; };
	//���ù����˺�
	FORCEINLINE float SetAttackDamage(float AttackDamage) {return this->AttackDamage = AttackDamage;};
	//���ع����˺�
	FORCEINLINE float GetAttackDamage() { return AttackDamage; };
	
	
};

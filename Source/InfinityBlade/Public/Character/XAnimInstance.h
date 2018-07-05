// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"Character/XPlayerState.h"
#include "Animation/AnimInstance.h"
#include "XAnimInstance.generated.h"

/**
 * ����ʵ��
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	//�����ٶȱ���
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	UPROPERTY()
		//����PlayerState
		 AXPlayerState* PlayerState;
	UPROPERTY()
		//��ͨ�����Ļ�������
		 float NormalAttackDamage;
public:
	UFUNCTION()
		//������ͨ��������
		void RestAttackDamage();
		//�����ӳ��˺�
	UFUNCTION()
		void UpdateSerialAttackDamage();
	//��ʼ��PlayerState��̬ʵ��
	UFUNCTION()
		void InitPlayerState();

public:
	//����������ٶ�
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();
	//�ж��Ƿ��ڲ���״̬
public:
	UPROPERTY()
	bool bIsPlaying;
	//�Ƿ����ڶ�������
	bool bInEnableScondAttack;
	//�Ƿ�����3������
	bool bInEnableThreeAttack;
	//�Ƿ�����4������
	bool bInEnableFourAttack;
	//�Ƿ�����5������
	bool bInEnableFiveAttack;


public:
	//��ʼ�������¼�����
	virtual void NativeInitializeAnimation() override;
	//��ʼ������̫��
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);
	UFUNCTION()
	//����������̫��
		void AnimNotify_PlayEnd(UAnimNotify* Notify);

	UFUNCTION()
			//��������״̬
		void AnimNotify_ReseetAttackInput(UAnimNotify* Notify);
	//����ڶ�������
	UFUNCTION()
		void AnimNotify_SecondAttackInput(UAnimNotify* Notify);
	//�����3������
	UFUNCTION()
		void AnimNotify_ThreeAttackInput(UAnimNotify* Notify);
	//�����4������
	UFUNCTION()
		void AnimNotify_FourAttackInput(UAnimNotify* Notify);
	//�����5������
	UFUNCTION()
		void AnimNotify_FiveAttackInput(UAnimNotify* Notify);
};

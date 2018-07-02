// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	//��ʼ������̫��
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);
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

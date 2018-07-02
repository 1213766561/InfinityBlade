// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"
#include "../../Public/Character/XAnimInstance.h"

void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner()!=NULL)
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

//��ʼ������̫��
void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify * Notify)
{
	bIsPlaying = true;
}

//����������̫��
void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify * Notify)
{
	bIsPlaying = false;


}

//��������״̬
void UXAnimInstance::AnimNotify_ReseetAttackInput(UAnimNotify * Notify)
{
	bInEnableScondAttack = false;
	bInEnableThreeAttack = false;
	bInEnableFourAttack = false;
	bInEnableFiveAttack = false;

}

void UXAnimInstance::AnimNotify_SecondAttackInput(UAnimNotify * Notify)
{
	bInEnableScondAttack = true;
	
}

void UXAnimInstance::AnimNotify_ThreeAttackInput(UAnimNotify * Notify)
{
	bInEnableThreeAttack = true;
}

void UXAnimInstance::AnimNotify_FourAttackInput(UAnimNotify * Notify)
{
	bInEnableFourAttack = true;
}

void UXAnimInstance::AnimNotify_FiveAttackInput(UAnimNotify * Notify)
{
	bInEnableFiveAttack = true;
}

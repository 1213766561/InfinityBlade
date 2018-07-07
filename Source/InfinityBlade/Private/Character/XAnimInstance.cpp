// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"
#include"Character/XPlayerController.h"
#include "../../Public/Character/XAnimInstance.h"


//������Anim��ʼ�¼�
void UXAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	InitPlayerState();
}


void UXAnimInstance::RestAttackDamage()
{
	InitPlayerState();
	if (PlayerState != nullptr)
	{
		//������ͨ�����˺�
		PlayerState->SetAttackDamage(NormalAttackDamage);
	}
}

//���мӳ��˺�
void UXAnimInstance::UpdateSerialAttackDamage()
{
	if (PlayerState != nullptr)
	{
		//�ӳ��˺�
		PlayerState->SetAttackDamage(PlayerState->GetAttackDamage() + 10.f);
	}
}

void UXAnimInstance::InitPlayerState()
{
	if (PlayerState != nullptr)
	{
		//��ȡController
		AXPlayerController* PlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
		//��ȡ״̬
		if (PlayerController != nullptr)
		{
			PlayerState = Cast<AXPlayerState>(PlayerController->PlayerState);
			//��ʼ����ͨ�������˺�
			NormalAttackDamage = PlayerState->GetAttackDamage();
		}
		
	}

}

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
	RestAttackDamage();

}

void UXAnimInstance::AnimNotify_SecondAttackInput(UAnimNotify * Notify)
{
	bInEnableScondAttack = true;
	//��ͨ�����˺�+10
	UpdateSerialAttackDamage();
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SecondSerialAttackDamageIs" + FString::SanitizeFloat(PlayerState->GetAttackDamage()));
}

void UXAnimInstance::AnimNotify_ThreeAttackInput(UAnimNotify * Notify)
{
	bInEnableThreeAttack = true;
	//��ͨ�����˺�+20
	UpdateSerialAttackDamage();
}

void UXAnimInstance::AnimNotify_FourAttackInput(UAnimNotify * Notify)
{
	bInEnableFourAttack = true;
	//��ͨ�����˺�+30
	UpdateSerialAttackDamage();
}

void UXAnimInstance::AnimNotify_FiveAttackInput(UAnimNotify * Notify)
{
	bInEnableFiveAttack = true;
	//��ͨ�����˺�+40
	UpdateSerialAttackDamage();
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SecondSerialAttackDamageIs" + FString::SanitizeFloat(PlayerState->GetAttackDamage()));
}

void UXAnimInstance::AnimNotify_BIsAttack(UAnimNotify * Notify)
{
	BIsAttack = true;
}

void UXAnimInstance::AnimNotify_BIsNotAttack(UAnimNotify * Notify)
{
	BIsAttack = false;
}

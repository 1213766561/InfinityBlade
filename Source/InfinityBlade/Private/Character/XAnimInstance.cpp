// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"
#include"Character/XPlayerController.h"
#include "../../Public/Character/XAnimInstance.h"


//重载下Anim开始事件
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
		//重置普通攻击伤害
		PlayerState->SetAttackDamage(NormalAttackDamage);
	}
}

//连招加成伤害
void UXAnimInstance::UpdateSerialAttackDamage()
{
	if (PlayerState != nullptr)
	{
		//加成伤害
		PlayerState->SetAttackDamage(PlayerState->GetAttackDamage() + 10.f);
	}
}

void UXAnimInstance::InitPlayerState()
{
	if (PlayerState != nullptr)
	{
		//获取Controller
		AXPlayerController* PlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
		//获取状态
		if (PlayerController != nullptr)
		{
			PlayerState = Cast<AXPlayerState>(PlayerController->PlayerState);
			//初始化普通攻击的伤害
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



//开始播放蒙太奇
void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify * Notify)
{
	bIsPlaying = true;
}

//结束播放蒙太奇
void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify * Notify)
{
	bIsPlaying = false;
}

//重置连击状态
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
	//普通攻击伤害+10
	UpdateSerialAttackDamage();
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SecondSerialAttackDamageIs" + FString::SanitizeFloat(PlayerState->GetAttackDamage()));
}

void UXAnimInstance::AnimNotify_ThreeAttackInput(UAnimNotify * Notify)
{
	bInEnableThreeAttack = true;
	//普通攻击伤害+20
	UpdateSerialAttackDamage();
}

void UXAnimInstance::AnimNotify_FourAttackInput(UAnimNotify * Notify)
{
	bInEnableFourAttack = true;
	//普通攻击伤害+30
	UpdateSerialAttackDamage();
}

void UXAnimInstance::AnimNotify_FiveAttackInput(UAnimNotify * Notify)
{
	bInEnableFiveAttack = true;
	//普通攻击伤害+40
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

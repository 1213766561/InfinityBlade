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
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SerialAttackDamageIs" + FString::SanitizeFloat(PlayerState->GetAttackDamage()));
	}
}

//连招加成伤害
void UXAnimInstance::UpdateSerialAttackDamage()
{
	if (PlayerState != nullptr)
	{
		//加成伤害
<<<<<<< HEAD
		NormalAttackDamage += 10.f;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SerialAttackDamageIs" + FString::SanitizeFloat(NormalAttackDamage));
=======
		PlayerState->SetAttackDamage(PlayerState->GetAttackDamage() + 10.f);
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2
	}
}

//初始化攻击伤害
void UXAnimInstance::InitPlayerState()
{
<<<<<<< HEAD
	if (TryGetPawnOwner())
=======
	if (PlayerState != nullptr)
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2
	{
		//获取Controller
		AXPlayerController* PlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
		//获取状态
		if (PlayerController)
		{
			PlayerState = Cast<AXPlayerState>(PlayerController->XPlayerState);
			//初始化普通攻击的伤害
			NormalAttackDamage = PlayerState->GetAttackDamage();
		}

		if (PlayerState)
		{
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
	
}

void UXAnimInstance::AnimNotify_BIsAttack(UAnimNotify * Notify)
{
	BIsAttack = true;
}

void UXAnimInstance::AnimNotify_BIsNotAttack(UAnimNotify * Notify)
{
	BIsAttack = false;
}



void UXAnimInstance::AnimNotify_SpwanIceStone(UAnimNotify * Notify)
{

	XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	
	if (XCharacter != nullptr)
	{
			//获得Spawn的location
			FVector TargetLocation = XCharacter->GetMesh()->GetSocketLocation("Right_Skill_Scoket");
			//获得XCharacter的Rotation
			
			FRotator TargetRotator = XCharacter->GetActorRotation();
			//XCharacter->GetMesh()->GetSocketRotation("Right_Skill_Scoket");
			
			//生成SkillParticle
			Skill_IceStone_Particle = GetWorld()->SpawnActor<ASkill_IceStone>(XCharacter->IceStoneSkillParticle, TargetLocation, TargetRotator);
			//设置速度
			Skill_IceStone_Particle->Shoot(XCharacter->GetActorForwardVector());                    //Shoot(TargetRotator.Vector());

	}

	
}

void UXAnimInstance::AnimNotify_BIsAttack(UAnimNotify * Notify)
{
	BIsAttack = true;
}

void UXAnimInstance::AnimNotify_BIsNotAttack(UAnimNotify * Notify)
{
	BIsAttack = false;
}

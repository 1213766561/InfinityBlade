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
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SerialAttackDamageIs" + FString::SanitizeFloat(PlayerState->GetAttackDamage()));
	}
}

//���мӳ��˺�
void UXAnimInstance::UpdateSerialAttackDamage()
{
	if (PlayerState != nullptr)
	{
		//�ӳ��˺�
<<<<<<< HEAD
		NormalAttackDamage += 10.f;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "SerialAttackDamageIs" + FString::SanitizeFloat(NormalAttackDamage));
=======
		PlayerState->SetAttackDamage(PlayerState->GetAttackDamage() + 10.f);
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2
	}
}

//��ʼ�������˺�
void UXAnimInstance::InitPlayerState()
{
<<<<<<< HEAD
	if (TryGetPawnOwner())
=======
	if (PlayerState != nullptr)
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2
	{
		//��ȡController
		AXPlayerController* PlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
		//��ȡ״̬
		if (PlayerController)
		{
			PlayerState = Cast<AXPlayerState>(PlayerController->XPlayerState);
			//��ʼ����ͨ�������˺�
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
			//���Spawn��location
			FVector TargetLocation = XCharacter->GetMesh()->GetSocketLocation("Right_Skill_Scoket");
			//���XCharacter��Rotation
			
			FRotator TargetRotator = XCharacter->GetActorRotation();
			//XCharacter->GetMesh()->GetSocketRotation("Right_Skill_Scoket");
			
			//����SkillParticle
			Skill_IceStone_Particle = GetWorld()->SpawnActor<ASkill_IceStone>(XCharacter->IceStoneSkillParticle, TargetLocation, TargetRotator);
			//�����ٶ�
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

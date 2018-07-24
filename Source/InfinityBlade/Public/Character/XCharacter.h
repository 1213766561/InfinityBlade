// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include"Camera/CameraComponent.h"
#include "Weapon.h"
#include "Character/Skill/Skill_IceStone.h"
#include"Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "XCharacter.generated.h"


/* 英雄角色类*/

UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	
	/* Camera组件创建*/
	UPROPERTY(EditAnywhere)
		UCameraComponent* CurrentCameraComponent;
	//声明武器
	UPROPERTY(EditAnywhere, Category = "weapon")
		TSubclassOf<AWeapon> XWeapon;
	//播放动画蒙太奇
	UPROPERTY(EditAnywhere, Category = "montage")
		UAnimMontage* SerialAttachMontage;
	//寒冰之石蒙太奇
	UPROPERTY(EditAnywhere, Category = "montage")
		UAnimMontage* IceStoneSkillMontage;
	//寒冰之石特效Class
	UPROPERTY(EditAnywhere, Category = "SkillParticle")
		TSubclassOf<ASkill_IceStone> IceStoneSkillParticle;
	UPROPERTY(EditAhywhere, Category = "The light of recovery")
		UAnimMontage* RecoverLightSkillMontage;

	//指定默认血量
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalHP;
	//指定默认MP
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalMP;
	//指定默认伤害
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float AttackDamage;



public:
	//构造方法
	AXCharacter();

public:
	//游戏开始调用
	virtual void BeginPlay() override;
<<<<<<< HEAD
	//定义伤害函数
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
=======

>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2


	
	
};

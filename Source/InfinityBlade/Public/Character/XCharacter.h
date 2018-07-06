// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include"Camera/CameraComponent.h"
#include "Weapon.h"
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



public:
	//构造方法
	AXCharacter();

protected:
	//游戏开始调用
	virtual void BeginPlay() override;



	
	
};

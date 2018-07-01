// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include"Camera/CameraComponent.h"
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



public:
	//构造方法
	AXCharacter();

protected:
	//游戏开始调用
	virtual void BeginPlay() override;



	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CoreMinimal.h"
#include"UserWidget_Start.h"
#include "MyGameMode.generated.h"

/**
 * 创建GameMode

 */
UCLASS()
class INFINITYBLADE_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	/* 游戏开始界面*/
	UPROPERTY()
		UUserWidget_Start* StartWidget;

public:
	/* 游戏开始调用方法*/
	virtual void BeginPlay() override;
	
	
};

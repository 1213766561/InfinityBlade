// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CoreMinimal.h"
#include"UserWidget_Start.h"
#include "MyGameMode.generated.h"

/**
 * ����GameMode

 */
UCLASS()
class INFINITYBLADE_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	/* ��Ϸ��ʼ����*/
	UPROPERTY()
		UUserWidget_Start* StartWidget;

public:
	/* ��Ϸ��ʼ���÷���*/
	virtual void BeginPlay() override;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include"UserWidget_Start.h"
#include"UserWidget_Register.h"
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
	/* ��Ϸע�����*/
	UPROPERTY()
	UUserWidget_Register* RegisterWidget;


public:
	/* ��Ϸ��ʼ���÷���*/
	virtual void BeginPlay() override;
	/* ע�ᰴť����¼�*/
	UFUNCTION()
		void RegisterBtnOnClickedlEvent();
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UserWidget_Start.generated.h"

/**
 * ����UI�ؼ�
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Start : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/* ��ʼ��Ϸ��ť*/
	UPROPERTY()
		UButton* StartBtn;
	UPROPERTY()
		UButton* RegisterBtn;
	UPROPERTY()
		UButton* QuitBtn;

	
	
public:
	/* �жϰ�ť�Ƿ����*/
	virtual bool  Initialize() override;
	/* �˳���Ϸ�������*/
	UFUNCTION()
		void QuitBtnOnClickedEvent();

};

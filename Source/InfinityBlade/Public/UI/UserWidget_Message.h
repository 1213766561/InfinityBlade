// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Button.h"
#include "TextBlock.h"
#include "UserWidget_Message.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Message : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/* ��ʼ���ı���*/
	UPROPERTY()
		UTextBlock* MessageText;
	/* ��ʼ���رհ�ť*/
	UPROPERTY()
		UButton* CloseBtn;

public:
	virtual bool Initialize() override;
	/* ���ùرհ�ť�¼�*/
	UFUNCTION()
	void ClosButtonOnClickedEvent();
	
	
	
};

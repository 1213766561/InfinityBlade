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
	/* 初始化文本框*/
	UPROPERTY()
		UTextBlock* MessageText;
	/* 初始化关闭按钮*/
	UPROPERTY()
		UButton* CloseBtn;

public:
	virtual bool Initialize() override;
	/* 设置关闭按钮事件*/
	UFUNCTION()
	void ClosButtonOnClickedEvent();
	
	
	
};

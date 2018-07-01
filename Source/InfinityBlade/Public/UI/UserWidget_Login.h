// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include"UserWidget_Message.h"
#include "EditableTextBox.h"
#include "UserWidget_Login.generated.h"

/**
 * 输入账号界面
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Login : public UUserWidget
{
	GENERATED_BODY()

public:
	//返回按键声明
	UPROPERTY()
		UButton* BlackBtn;
	//进入游戏按键声明
	UPROPERTY()
		UButton* AgreeBtn;
	//姓名框声明
	UPROPERTY()
		UEditableTextBox* NicknameInput;
	//声明Message框
	UPROPERTY()
		UUserWidget_Message* MessageBox;

public:
	virtual bool Initialize() override;

	//声明进入游戏按钮点击事件
	UFUNCTION()
	void StarGameBtnOnClickedEvent();


};

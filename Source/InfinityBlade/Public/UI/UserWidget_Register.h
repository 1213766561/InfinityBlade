// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Button.h"
#include"EditableTextBox.h"
#include"Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include"IHttpRequest.h"
#include"Runtime/UMG/Public/Components/CircularThrobber.h"
#include "UserWidget_Message.h"
#include "UserWidget_Register.generated.h"

/**
 * 创建注册UI
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Register : public UUserWidget
{
	
	GENERATED_BODY()

public:
	/* 创建回退按钮变量*/
	UPROPERTY()
		UButton* BackBtn;
	/* 创建注册账号按钮变量*/
	UPROPERTY()
		UButton* RegisterBtn;
	/* 创建昵称输入框变量*/
	UPROPERTY()
	UEditableTextBox* NicknameInput;
	/* 创建密码输入框变量*/
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	/* 创建再次输入密码输入框变量*/
	UPROPERTY()
		UEditableTextBox* RePasswordInput;
	/* 创建Loading效果*/
	UPROPERTY()
		UCircularThrobber* CircularThrobber;
	UPROPERTY()
		/* 初始化Message框*/
		UUserWidget_Message* MessageWidget;

	
		

public:
	/* 判断变量以上变量是否加载成功*/
	virtual bool Initialize() override;
	/* 注册按钮点击事件*/
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	/* 账号注册方法*/
	void AccountRegisterFromServer(FString&Nickname, FString&Password);
	/* 请求响应方法*/
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};

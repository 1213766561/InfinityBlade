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
 * ����ע��UI
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Register : public UUserWidget
{
	
	GENERATED_BODY()

public:
	/* �������˰�ť����*/
	UPROPERTY()
		UButton* BackBtn;
	/* ����ע���˺Ű�ť����*/
	UPROPERTY()
		UButton* RegisterBtn;
	/* �����ǳ���������*/
	UPROPERTY()
	UEditableTextBox* NicknameInput;
	/* ����������������*/
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	/* �����ٴ�����������������*/
	UPROPERTY()
		UEditableTextBox* RePasswordInput;
	/* ����LoadingЧ��*/
	UPROPERTY()
		UCircularThrobber* CircularThrobber;
	UPROPERTY()
		/* ��ʼ��Message��*/
		UUserWidget_Message* MessageWidget;

	
		

public:
	/* �жϱ������ϱ����Ƿ���سɹ�*/
	virtual bool Initialize() override;
	/* ע�ᰴť����¼�*/
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	/* �˺�ע�᷽��*/
	void AccountRegisterFromServer(FString&Nickname, FString&Password);
	/* ������Ӧ����*/
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};

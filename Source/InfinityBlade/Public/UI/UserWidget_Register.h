// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Button.h"
#include"EditableTextBox.h"
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

public:
	/* �жϱ������ϱ����Ƿ���سɹ�*/
	virtual bool Initialize() override;
	/* ע�ᰴť����¼�*/
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	
};

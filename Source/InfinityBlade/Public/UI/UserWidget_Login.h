// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include"UserWidget_Message.h"
#include "EditableTextBox.h"
#include "UserWidget_Login.generated.h"

/**
 * �����˺Ž���
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Login : public UUserWidget
{
	GENERATED_BODY()

public:
	//���ذ�������
	UPROPERTY()
		UButton* BlackBtn;
	//������Ϸ��������
	UPROPERTY()
		UButton* AgreeBtn;
	//����������
	UPROPERTY()
		UEditableTextBox* NicknameInput;
	//����Message��
	UPROPERTY()
		UUserWidget_Message* MessageBox;

public:
	virtual bool Initialize() override;

	//����������Ϸ��ť����¼�
	UFUNCTION()
	void StarGameBtnOnClickedEvent();


};

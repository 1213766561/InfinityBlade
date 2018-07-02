// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCharacter.h"
#include "UserWidget_Game.h"
#include "Weapon.h"
#include "Character/XAnimInstance.h"
#include "XPlayerController.generated.h"

/**
 * ����Ӣ�ۿ�����
 */


UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AXCharacter * XCharacter;
	//������Ϸ����UI
	UPROPERTY()
		UUserWidget_Game* MainUserWidget;
	//��������
	UPROPERTY()
		AWeapon* XWeapon;
	//Ӣ�۽�ɫ����ʵ��
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	

	
public:
	//��Ϸ��ʼ���÷���
	virtual void BeginPlay() override;
	//������ؼ�
	virtual void SetupInputComponent() override;
	//��ǰ���ƶ��������ƶ��ķ���

	UFUNCTION()
		void MoveeForward(float Speed);
	UFUNCTION()
		void MoveRight(float Speed);
	//������ť����¼�
	UFUNCTION()
		void AttackBtnOnClickedEvent();
	//�ؼ���ť��ʼ������
	UFUNCTION()
		void InitWidgetEvent();
	


};

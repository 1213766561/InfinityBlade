// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCharacter.h"
#include "UserWidget_Game.h"
#include "Weapon.h"
#include "Character/XAnimInstance.h"
#include "XplayerState.h"
#include "XPlayerController.generated.h"

/**
 * ����Ӣ�ۿ�����
 */


UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY()
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
	//����PlayerState
	UPROPERTY()
		AXPlayerState* XPlayerState;
	
	//AI����
	UPROPERTY()
		TArray<AActor*>AIArray;    //ָ����Ҫ�����������棻
	

	
public:
	//��Ϸ��ʼ���÷���
	virtual void BeginPlay() override;
	//possPlayeerʵ��
	virtual void Possess(APawn* aPawn) override;
	//������ؼ�
	virtual void SetupInputComponent() override;
	//��ǰ���ƶ��������ƶ��ķ���

	UFUNCTION()
		void MoveeForward(float Speed);
	UFUNCTION()
		void MoveRight(float Speed);

	//����Ұ����
	UFUNCTION()
		void Trun(float Speed);
	UFUNCTION()
		void Lookup(float Speed);

	//����AI
	UFUNCTION()
		void LockEnemy(float HitRadius);

	//������ť����¼�
	UFUNCTION()
		void AttackBtnOnClickedEvent();
	//����֮ʯ����¼���
	UFUNCTION()
		void IceStoneOnClickedEvent();
	//�ؼ���ť��ʼ������
	UFUNCTION()
		void InitWidgetEvent();

	//��ʼ����ҵ�״̬
		void SetupPlayerState();
	
	//�����˺�
		UFUNCTION()
			void WeaponOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	//����״̬
		UFUNCTION()
			void UpdatePlayerState(float UpdateHP, float UpdateMP);
	//����UI
		void UpdateUI();

};

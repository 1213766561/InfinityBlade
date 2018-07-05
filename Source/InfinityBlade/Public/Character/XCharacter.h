// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include"Camera/CameraComponent.h"
#include "Weapon.h"
#include"Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "XCharacter.generated.h"


/* Ӣ�۽�ɫ��*/

UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()
public:

	/* Camera�������*/
	UPROPERTY(EditAnywhere)
		UCameraComponent* CurrentCameraComponent;
	//��������
	UPROPERTY(EditAnywhere, Category = "weapon")
		TSubclassOf<AWeapon> XWeapon;
	//���Ŷ�����̫��
	UPROPERTY(EditAnywhere, Category = "montage")
		UAnimMontage* SerialAttachMontage;
	//ָ��Ĭ��Ѫ��
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalHP;
	//ָ��Ĭ��MP
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalMP;
	//ָ��Ĭ���˺�
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float AttackDamage;



public:
	//���췽��
	AXCharacter();

protected:
	//��Ϸ��ʼ����
	virtual void BeginPlay() override;



	
	
};

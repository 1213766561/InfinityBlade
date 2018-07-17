// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "UserWidget_HPBar.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Weapon/Weapon.h"
#include "AICharacter.generated.h"


//AI��

UCLASS()
class INFINITYBLADE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// ���췽��
	AAICharacter();

	//���WidgetUI���
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWidgetComponent* HPWidget;
	//����HP
	UPROPERTY(EditAnywhere, category = "State",BlueprintReadOnly)
		float TotalHP;
	//����BaseDamage
	UPROPERTY(EditAnywhere, category = "State", BlueprintReadOnly)
		float BaseDamage;
	//������ǰ��HP
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentHP;
	//�Ƿ�����
	UPROPERTY()
		bool bIsDead;
<<<<<<< HEAD
	//������Ϊ��
	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* UsBehaviorTree;
	//�������������
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AWeapon> WeaponClass;
// 	���Ź���������̫��
	UPROPERTY(EditAnywhere, Category = "montage")
 		TArray<UAnimMontage*> AISerialAttachMontage;    //�������ʹ����Ϊ�������PlayAnim
		
=======
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2

	/*UPROPERTY()
		//����HPBar�Ŀؼ�
		UUserWidget_HPBar* HP_Bar;*/

	/*UPROPERTY()
		//����HPBar�Ŀؼ�
		UUserWidget_HPBar* HP_Bar;*/

public:
	// ��Ϸ��ʼ���÷���
	virtual void BeginPlay() override;		
	//�˺���������
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	UFUNCTION(BlueprintImplementableEvent, Category = "States")
		//��Ϸ��ʼ��������
		void UpdateHP(float Damage);

public:
	// ��Ϸ��ʼ���÷���
	virtual void BeginPlay() override;		
	//�˺���������
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	UFUNCTION(BlueprintImplementableEvent, Category = "States")
		//��Ϸ��ʼ��������
		void UpdateHP(float Damage);

	
	
	
	
};

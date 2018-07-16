// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI/AICharacter.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Weapon/Weapon.h"
#include "MonsterController.generated.h"

/**
 * AIControllerʵ��
 */
UCLASS()
class INFINITYBLADE_API AMonsterController : public AAIController
{
	GENERATED_BODY()
	
public:
	//������Ϊ��
			UPROPERTY()
				UBehaviorTreeComponent* BehaviorTreeComponent;
	//�����ڰ�
			UPROPERTY()
				UBlackboardComponent* BlackboardComponent;
	//����Weapon
			UPROPERTY()
				AWeapon* CurrentWeapon;
	//����AIʵ��
			UPROPERTY()
				AAICharacter* Monster;



public:
	AMonsterController();
	//Characteerʵ���Ŀ���
	virtual void Possess(APawn* InPawn) override;
	//��ײ�¼�����
	UFUNCTION()
	void CurrentWeaponBeginOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	
	
};

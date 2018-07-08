// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include"Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"
#include"Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Skill_IceStone.generated.h"

UCLASS()
class INFINITYBLADE_API ASkill_IceStone : public AActor
{
	GENERATED_BODY()




public:
	//������ײ
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* CapsuleComponent;
	//������Ч���
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* ParticleComponent;
	//�����������˶����
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* ProjectileMovementComponent;
	//�����ƻ������Ч
	UPROPERTY(EditAnywhere, category = "Particle")
		UParticleSystem* Particle;




public:	
	// ���캯��
	ASkill_IceStone();

public:
	/*UFUNCTION(BlueprintImplementableEvent)
	//������ײ����
		void HasHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit );*/
	UFUNCTION()
		//����BeginOverlap�¼�
		void HasOverLap(UPrimitiveComponent* OvrlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult& HitResult);
	
	
	//�����˶�����
	UFUNCTION()
		void Shoot(FVector Derection);
	




protected:
	// ��ʼ������
	virtual void BeginPlay() override;




	
	
};

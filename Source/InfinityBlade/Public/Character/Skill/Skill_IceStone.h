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
	//声明碰撞
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* CapsuleComponent;
	//声明特效组件
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* ParticleComponent;
	//声明抛物线运动组件
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* ProjectileMovementComponent;
	//声明破环后的特效
	UPROPERTY(EditAnywhere, category = "Particle")
		UParticleSystem* Particle;




public:	
	// 构造函数
	ASkill_IceStone();

public:
	/*UFUNCTION(BlueprintImplementableEvent)
	//重载碰撞函数
		void HasHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit );*/
	UFUNCTION()
		//重载BeginOverlap事件
		void HasOverLap(UPrimitiveComponent* OvrlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult& HitResult);
	
	
	//抛物运动函数
	UFUNCTION()
		void Shoot(FVector Derection);
	




protected:
	// 初始化函数
	virtual void BeginPlay() override;




	
	
};

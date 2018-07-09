// Fill out your copyright notice in the Description page of Project Settings.

#include "Skill_IceStone.h"
#include "AI/AICharacter.h"
#include "Character/XCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "../../../Public/Character/Skill/Skill_IceStone.h"


// 构造函数
ASkill_IceStone::ASkill_IceStone()
{
	//初始化碰撞组件
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	//设置根组件
	CapsuleComponent->SetupAttachment(RootComponent);

	//碰撞事件回调
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASkill_IceStone::HasOverLap);


	//初始化粒子组件
	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	//挂载粒子组件
	ParticleComponent->SetupAttachment(CapsuleComponent);
	//初始化抛物线运动组件
	ProjectileMovementComponent= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	//挂载抛物线运动组件
	ProjectileMovementComponent->SetUpdatedComponent(RootComponent);
	//声明生命周期
	InitialLifeSpan = 2.f;
	
	
}









void ASkill_IceStone::HasOverLap(UPrimitiveComponent * OvrlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult & HitResult)
{
	
	if (OtherActor)
	{
		UGameplayStatics::ApplyPointDamage(OtherActor, 20.f, HitResult.ImpactNormal, HitResult, nullptr, this, nullptr);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, OtherActor->GetActorLocation());
		this->Destroyed();  //Destroyed 失效，在蓝图中重载
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "HasOverLap");
	}
	
}

void ASkill_IceStone::Shoot(FVector Derection)
{
	ProjectileMovementComponent->Velocity = Derection * ProjectileMovementComponent->InitialSpeed;
}

// 初始化函数
void ASkill_IceStone::BeginPlay()
{
	Super::BeginPlay();
	
}




// Fill out your copyright notice in the Description page of Project Settings.

#include "Skill_IceStone.h"
#include "AI/AICharacter.h"
#include "Character/XCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "../../../Public/Character/Skill/Skill_IceStone.h"


// ���캯��
ASkill_IceStone::ASkill_IceStone()
{
	//��ʼ����ײ���
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	//���ø����
	CapsuleComponent->SetupAttachment(RootComponent);

	//��ײ�¼��ص�
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASkill_IceStone::HasOverLap);


	//��ʼ���������
	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	//�����������
	ParticleComponent->SetupAttachment(CapsuleComponent);
	//��ʼ���������˶����
	ProjectileMovementComponent= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	//�����������˶����
	ProjectileMovementComponent->SetUpdatedComponent(RootComponent);
	//������������
	InitialLifeSpan = 2.f;
	
	
}









void ASkill_IceStone::HasOverLap(UPrimitiveComponent * OvrlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult & HitResult)
{
	
	if (OtherActor)
	{
		UGameplayStatics::ApplyPointDamage(OtherActor, 20.f, HitResult.ImpactNormal, HitResult, nullptr, this, nullptr);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, OtherActor->GetActorLocation());
		this->Destroyed();  //Destroyed ʧЧ������ͼ������
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "HasOverLap");
	}
	
}

void ASkill_IceStone::Shoot(FVector Derection)
{
	ProjectileMovementComponent->Velocity = Derection * ProjectileMovementComponent->InitialSpeed;
}

// ��ʼ������
void ASkill_IceStone::BeginPlay()
{
	Super::BeginPlay();
	
}




// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterController.h"
#include "AI/AICharacter.h"

AMonsterController::AMonsterController()
{
	//��ʼ����Ϊ���ؼ�
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	//��ʼ���ڰ�ؼ�
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

}


//Characteerʵ���Ŀ���
void AMonsterController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	//����AIʵ��
	 Monster = Cast<AAICharacter>(InPawn);
	//����Weapon
	if (Monster->WeaponClass)
	{
		//����Weapon
		CurrentWeapon = GetWorld()->SpawnActor<AWeapon>(Monster->WeaponClass);
		//��Weapon
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget,true);
		CurrentWeapon->WeaponComponent ->AttachToComponent(Monster->GetMesh(), AttachRules, TEXT("hand_rSocket"));
		//������ײ�¼��ص�
		CurrentWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMonsterController::CurrentWeaponBeginOverlapEvent);

		if (Monster->BehaviorTree)
		{
			//������Ϊ��
			BehaviorTreeComponent->StartTree(*(Monster->BehaviorTree));
			//��ʼ���ڰ�
			BlackboardComponent->InitializeBlackboard(*(Monster->BehaviorTree->BlackboardAsset));

		}

	}
	
	
	
}

//Weapon��ײ�¼�����
void AMonsterController::CurrentWeaponBeginOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (Monster)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, FString::SanitizeFloat(Monster->BaseDamage));

		}
	}
}

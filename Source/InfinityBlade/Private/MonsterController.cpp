// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AI/AICharacter.h"
#include "Character/XCharacter.h"

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
		CurrentWeapon->WeaponOwner = Monster;
		//��ʼ��Aim
		MonsterAim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
		//������ײ�¼��ص�
		CurrentWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMonsterController::CurrentWeaponBeginOverlapEvent);

	}
	
// 	if (Monster->UsBehaviorTree)
// 	{
// 		//������Ϊ��
// 		BehaviorTreeComponent->StartTree(*(Monster->UsBehaviorTree));
// 		//��ʼ���ڰ�
// 		BlackboardComponent->InitializeBlackboard(*(Monster->UsBehaviorTree->BlackboardAsset));
// 
// 	}
	
}

//Weapon��ײ�¼�����
void AMonsterController::CurrentWeaponBeginOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AXCharacter* TargetCharacter = Cast<AXCharacter>(OtherActor);
	if (TargetCharacter)
	{
		if (MonsterAim->bIsAttack == true)
		{
			UGameplayStatics::ApplyDamage(TargetCharacter, Monster->BaseDamage, this, Monster, nullptr);
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, FString::SanitizeFloat(Monster->BaseDamage));
		}
	}

	
// 	if (MonsterAim->bIsAttack == true)
// 		{
// 			
// 		}

	

		/*DmagedCharacter = Cast<ACharacter>(SweepResult->Break->GetHit);
		if (DmagedCharacter != nullptr && DmagedCharacter != WeaponOwner)
		{
		DmagedCharacter->TakeDamage(XPlayerState->GetAttackDamage(), FDamageEvent::)
		}*/

	
}

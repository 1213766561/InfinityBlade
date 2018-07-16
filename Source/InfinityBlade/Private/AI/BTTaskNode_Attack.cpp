// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNode_Attack.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"



//���ع�������
EBTNodeResult::Type UBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory); 
	//��ʼ��Controlleer
		AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	//��ʼ��AI�Լ�Anim
		AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
		UAIAnimInstance* MonsterAim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
	//���Ź���Montage
		if (Monster)
		{
			uint8 TargetMontage = FMath::RandRange(0, Monster->AISerialAttachMontage.Num());
			if (MonsterAim)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::SanitizeFloat(TargetMontage));
				MonsterAim->Montage_Play(Monster->AISerialAttachMontage[TargetMontage]);
				return EBTNodeResult::Succeeded;
			}
			return EBTNodeResult::Failed;
		}

	return EBTNodeResult::Failed;
	
}

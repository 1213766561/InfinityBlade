// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNode_Attack.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"



//���ع�������
EBTNodeResult::Type UBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//��ʼ��Controlleer
		AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
		if (MonsterController)
		{
			//��ʼ��AI
			AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
			if (Monster)
			{
				//��ʼ��Aim
				UAIAnimInstance* MonsterAim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());

				if (MonsterAim->bIsAttack == false)
				{
					//��������AttackMontage
					float TargetMontage = FMath::RandRange(0.f, Monster->AISerialAttachMontage.Num()*1.f);
					//���Ź���Montage
					GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::SanitizeFloat(TargetMontage));
					MonsterAim->Montage_Play(Monster->AISerialAttachMontage[TargetMontage]);
					if (MonsterAim->Montage_IsPlaying(Monster->AISerialAttachMontage[TargetMontage])==false)
					{
						return EBTNodeResult::Succeeded;
					}
					return EBTNodeResult::Failed;
				}
				return EBTNodeResult::Failed;
			}
			return EBTNodeResult::Failed;
		}

	return EBTNodeResult::Failed;
	
}

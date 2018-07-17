// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNode_Attack.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"



//重载攻击方法
EBTNodeResult::Type UBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//初始化Controlleer
		AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
		if (MonsterController)
		{
			//初始化AI
			AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
			if (Monster)
			{
				//初始化Aim
				UAIAnimInstance* MonsterAim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());

				if (MonsterAim->bIsAttack == false)
				{
					//获得随机的AttackMontage
					float TargetMontage = FMath::RandRange(0.f, Monster->AISerialAttachMontage.Num()*1.f);
					//播放攻击Montage
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

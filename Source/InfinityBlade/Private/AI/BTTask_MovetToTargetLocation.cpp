// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MovetToTargetLocation.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"
#include "../../Public/AI/BTTask_MovetToTargetLocation.h"



//��дTask����

EBTNodeResult::Type UBTTask_MovetToTargetLocation::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	//��ȡConttroller
		AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
// 		//��ȡMonster
// 		AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
// 		//��ȡ����ʵ��
// 		UAIAnimInstance* MonsterAnim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
// 		//��ȡ�ڰ�
		UBlackboardComponent* MonsterBlackboard = MonsterController->BlackboardComponent;
// 		//���TargetLocation
// 		FVector TargetLocation = MonsterBlackboard->GetValueAsVector(TEXT("TargetLocation"));
// 		//�������
// 		float Distance = FVector::Distance(MonsterController->GetPawn()->GetActorLocation(), TargetLocation);
// 		//�жϾ���
	if (MonsterController)
	{
		if (MonsterBlackboard->GetValueAsFloat(TEXT("Distance")) <= Dir)
		{
			MonsterController->MoveToLocation(MonsterBlackboard->GetValueAsVector(TEXT("TargetLocation")), 20.f, true, true, true);
			return EBTNodeResult::Succeeded;
		}

		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Failed;
}

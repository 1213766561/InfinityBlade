// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_DistanceTo.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"
#include "../../Public/AI/BTDecorator_DistanceTo.h"

bool UBTDecorator_DistanceTo::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
// 	//��ȡConttroller
	AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
// 	//��ȡMonster
// 	AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
// 	//��ȡ����ʵ��
// 	UAIAnimInstance* MonsterAnim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
// 	//��ȡ�ڰ�
	UBlackboardComponent* MonsterBlackboard = MonsterController->BlackboardComponent;
// 	//���TargetLocation
// 	FVector TargetLocation = MonsterBlackboard->GetValueAsVector(TEXT("TargetLocation"));
// 	//�������
// 	float Distance = FVector::Distance(MonsterController->GetPawn()->GetActorLocation(), TargetLocation);
	//�жϾ���
	if (MonsterController)
	{
		if (MonsterBlackboard->GetValueAsFloat(TEXT("Distance")) <= Distance)
		{
			return true;
		}
		return false;
	}
	return false;
}

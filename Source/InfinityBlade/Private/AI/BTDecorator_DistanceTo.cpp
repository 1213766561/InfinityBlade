// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_DistanceTo.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"
#include "../../Public/AI/BTDecorator_DistanceTo.h"

bool UBTDecorator_DistanceTo::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
// 	//获取Conttroller
	AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
// 	//获取Monster
// 	AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
// 	//获取动画实例
// 	UAIAnimInstance* MonsterAnim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
// 	//获取黑板
	UBlackboardComponent* MonsterBlackboard = MonsterController->BlackboardComponent;
// 	//获得TargetLocation
// 	FVector TargetLocation = MonsterBlackboard->GetValueAsVector(TEXT("TargetLocation"));
// 	//计算距离
// 	float Distance = FVector::Distance(MonsterController->GetPawn()->GetActorLocation(), TargetLocation);
	//判断距离
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

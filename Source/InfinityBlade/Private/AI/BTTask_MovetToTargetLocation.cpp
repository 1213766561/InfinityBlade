// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MovetToTargetLocation.h"
#include "MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"
#include "../../Public/AI/BTTask_MovetToTargetLocation.h"



//重写Task方法

EBTNodeResult::Type UBTTask_MovetToTargetLocation::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	//获取Conttroller
		AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
// 		//获取Monster
// 		AAICharacter* Monster = Cast<AAICharacter>(MonsterController->GetPawn());
// 		//获取动画实例
// 		UAIAnimInstance* MonsterAnim = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
// 		//获取黑板
		UBlackboardComponent* MonsterBlackboard = MonsterController->BlackboardComponent;
// 		//获得TargetLocation
// 		FVector TargetLocation = MonsterBlackboard->GetValueAsVector(TEXT("TargetLocation"));
// 		//计算距离
// 		float Distance = FVector::Distance(MonsterController->GetPawn()->GetActorLocation(), TargetLocation);
// 		//判断距离
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

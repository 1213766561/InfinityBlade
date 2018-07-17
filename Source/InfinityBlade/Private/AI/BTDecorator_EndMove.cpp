// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_EndMove.h"
#include "MonsterController.h"
#include "../../Public/AI/BTDecorator_EndMove.h"

bool UBTDecorator_EndMove::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	//获得Controller
	AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	//获得Blackboard实例
	UBlackboardComponent* Blackboard = Cast<UBlackboardComponent>(MonsterController->GetBlackboardComponent());
	if (MonsterController)
	{
		if (Blackboard->GetValueAsFloat(TEXT("Distance")) <= Dir)
		{
			return false;
		}
		return true;
	}
	return true;
}

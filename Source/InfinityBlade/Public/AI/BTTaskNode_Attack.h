// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_Attack.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UBTTaskNode_Attack : public UBTTaskNode
{
	GENERATED_BODY()



public:
	//÷ÿ‘ÿ∫Ø ˝
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;

	

	
	
	
};

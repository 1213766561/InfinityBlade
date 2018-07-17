// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MovetToTargetLocation.generated.h"

/**
 * 
 *AI移动Task
 */
UCLASS()
class INFINITYBLADE_API UBTTask_MovetToTargetLocation : public UBTTaskNode
{
	GENERATED_BODY()


public:
	//最大感应距离
	UPROPERTY(EditAnywhere, Category = "Direction")
		float Dir;

public:
	//重写Task方法
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_ConeCheckEnemy.generated.h"

/**
 * 检测黑板的service
 */
UCLASS()
class INFINITYBLADE_API UBTService_ConeCheckEnemy : public UBTService
{
	GENERATED_BODY()
	
public:
	//重写心跳节点
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MovetToTargetLocation.generated.h"

/**
 * 
 *AI�ƶ�Task
 */
UCLASS()
class INFINITYBLADE_API UBTTask_MovetToTargetLocation : public UBTTaskNode
{
	GENERATED_BODY()


public:
	//����Ӧ����
	UPROPERTY(EditAnywhere, Category = "Direction")
		float Dir;

public:
	//��дTask����
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_DistanceTo.generated.h"

/**
 * �ж�Distance��Decorator
 */
UCLASS()
class INFINITYBLADE_API UBTDecorator_DistanceTo : public UBTDecorator
{
	GENERATED_BODY()
	
		//
public:
	//�жϵľ���
	UPROPERTY(EditAnywhere, Category = "Prop")
		float Distance;

public:
	//�жϾ���ķ���
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;

	
	
	
};

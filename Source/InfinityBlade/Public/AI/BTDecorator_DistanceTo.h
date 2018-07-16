// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_DistanceTo.generated.h"

/**
 * ÅÐ¶ÏDistanceµÄDecorator
 */
UCLASS()
class INFINITYBLADE_API UBTDecorator_DistanceTo : public UBTDecorator
{
	GENERATED_BODY()
	
		//
public:
	//ÅÐ¶ÏµÄ¾àÀë
	UPROPERTY(EditAnywhere, Category = "Prop")
		float Distance;

public:
	//ÅÐ¶Ï¾àÀëµÄ·½·¨
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;

	
	
	
};

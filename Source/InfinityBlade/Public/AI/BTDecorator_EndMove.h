// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_EndMove.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UBTDecorator_EndMove : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Distance")
		float Dir;

public:
	//ÖØÐ´º¯Êý
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "MonsterController.generated.h"

/**
 * AIController实例
 */
UCLASS()
class INFINITYBLADE_API AMonsterController : public AAIController
{
	GENERATED_BODY()
	
public:
	//声明行为树
			UPROPERTY()
				UBehaviorTreeComponent* BehaviorTreeComponent;
	//声明黑板
			UPROPERTY()
				UBlackboardComponent* BlackboardComponent;

public:
	AMonsterController();
	//Characteer实例的控制
	virtual void Possess(APawn* InPawn) override;

	
	
	
};

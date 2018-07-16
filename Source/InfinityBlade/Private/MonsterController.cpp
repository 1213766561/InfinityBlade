// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterController.h"
#include "AI/AICharacter.h"

AMonsterController::AMonsterController()
{
	//初始化行为树控件
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	//初始化黑板控件
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

}


//Characteer实例的控制
void AMonsterController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	//创建AI实例
	AAICharacter* Monster = Cast<AAICharacter>(InPawn);

	if (Monster->BehaviorTree)
	{
		//初始化黑板
		BlackboardComponent-> InitializeBlackboard(*((Monster->BehaviorTree->BlackboardAsset)));
		//启动行为树
		BehaviorTreeComponent->StartTree(*(Monster->BehaviorTree));
	}

}

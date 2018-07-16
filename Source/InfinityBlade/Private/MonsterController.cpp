// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterController.h"
#include "AI/AICharacter.h"

AMonsterController::AMonsterController()
{
	//��ʼ����Ϊ���ؼ�
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	//��ʼ���ڰ�ؼ�
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

}


//Characteerʵ���Ŀ���
void AMonsterController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	//����AIʵ��
	AAICharacter* Monster = Cast<AAICharacter>(InPawn);

	if (Monster->BehaviorTree)
	{
		//��ʼ���ڰ�
		BlackboardComponent-> InitializeBlackboard(*((Monster->BehaviorTree->BlackboardAsset)));
		//������Ϊ��
		BehaviorTreeComponent->StartTree(*(Monster->BehaviorTree));
	}

}

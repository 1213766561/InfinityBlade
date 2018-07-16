// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_ConeCheckEnemy.h"
#include "MonsterController.h"
#include "Components/ArrowComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AI/AICharacter.h"
#include "Components/MeshComponent.h"
#include "Character/XCharacter.h"



//��д�����ڵ�
void UBTService_ConeCheckEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp,NodeMemory, DeltaSeconds);
	//��ȡConttroller
	AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	//��ȡ�ڰ�
	UBlackboardComponent* MonsterBlackboard = MonsterController->BlackboardComponent;

	//����SelfLocation
	MonsterBlackboard->SetValueAsVector(TEXT("SelfLocation"), MonsterController->GetPawn()->GetActorLocation());
	//��ȡAI��ɫ
	AAICharacter* Monster;
	Monster = Cast<AAICharacter>(MonsterController->GetPawn());
	//��ȡ����
	FRotator TargetRotator = Monster->GetArrowComponent()->GetComponentRotation();
	//����SelfDirection
	MonsterBlackboard->SetValueAsVector(TEXT("SelfDirection"), TargetRotator.Vector());
	//��ȡ��ҵ�λ��
	FVector TargetPlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	//����TargetLocation
	MonsterBlackboard->SetValueAsVector(TEXT("TargetLocation"), TargetPlayerLocation);


}

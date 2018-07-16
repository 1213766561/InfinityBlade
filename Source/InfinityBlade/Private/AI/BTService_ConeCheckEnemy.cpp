// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_ConeCheckEnemy.h"
#include "MonsterController.h"
#include "Components/ArrowComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AI/AICharacter.h"
#include "Components/MeshComponent.h"
#include "Character/XCharacter.h"



//重写心跳节点
void UBTService_ConeCheckEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp,NodeMemory, DeltaSeconds);
	//获取Conttroller
	AMonsterController* MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	//获取黑板
	UBlackboardComponent* MonsterBlackboard = MonsterController->BlackboardComponent;

	//设置SelfLocation
	MonsterBlackboard->SetValueAsVector(TEXT("SelfLocation"), MonsterController->GetPawn()->GetActorLocation());
	//获取AI角色
	AAICharacter* Monster;
	Monster = Cast<AAICharacter>(MonsterController->GetPawn());
	//获取朝向
	FRotator TargetRotator = Monster->GetArrowComponent()->GetComponentRotation();
	//设置SelfDirection
	MonsterBlackboard->SetValueAsVector(TEXT("SelfDirection"), TargetRotator.Vector());
	//获取玩家的位置
	FVector TargetPlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	//设置TargetLocation
	MonsterBlackboard->SetValueAsVector(TEXT("TargetLocation"), TargetPlayerLocation);


}

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
	 Monster = Cast<AAICharacter>(InPawn);
	//创建Weapon
	if (Monster->WeaponClass)
	{
		//生成Weapon
		CurrentWeapon = GetWorld()->SpawnActor<AWeapon>(Monster->WeaponClass);
		//绑定Weapon
		FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget,true);
		CurrentWeapon->WeaponComponent ->AttachToComponent(Monster->GetMesh(), AttachRules, TEXT("hand_rSocket"));
		//武器碰撞事件回调
		CurrentWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMonsterController::CurrentWeaponBeginOverlapEvent);

		if (Monster->BehaviorTree)
		{
			//启动行为树
			BehaviorTreeComponent->StartTree(*(Monster->BehaviorTree));
			//初始化黑板
			BlackboardComponent->InitializeBlackboard(*(Monster->BehaviorTree->BlackboardAsset));

		}

	}
	
	
	
}

//Weapon碰撞事件函数
void AMonsterController::CurrentWeaponBeginOverlapEvent(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (Monster)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, FString::SanitizeFloat(Monster->BaseDamage));

		}
	}
}

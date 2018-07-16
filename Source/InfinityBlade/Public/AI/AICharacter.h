// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "UserWidget_HPBar.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "AICharacter.generated.h"


//AI类

UCLASS()
class INFINITYBLADE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// 构造方法
	AAICharacter();

	//添加WidgetUI组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWidgetComponent* HPWidget;
	//声明HP
	UPROPERTY(EditAnywhere, category = "State",BlueprintReadOnly)
		float TotalHP;
	//声明BaseDamage
	UPROPERTY(EditAnywhere, category = "State", BlueprintReadOnly)
		float BaseDamage;
	//声明当前的HP
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentHP;
	//是否死亡
	UPROPERTY()
		bool bIsDead;
	//声明行为树
	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* BehaviorTree;
	
		


	/*UPROPERTY()
		//声明HPBar的控件
		UUserWidget_HPBar* HP_Bar;*/


public:
	// 游戏开始调用方法
	virtual void BeginPlay() override;		
	//伤害函数声明
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	UFUNCTION(BlueprintImplementableEvent, Category = "States")
		//游戏开始函数声明
		void UpdateHP(float Damage);


	
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "UserWidget_HPBar.h"
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
	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* HPWidget;
	//声明HP
	UPROPERTY(EditAnywhere, category = "State")
		float TotalHP;
	//声明BaseDamage
	UPROPERTY(EditAnywhere, category = "State")
		float BaseDamage;
	//声明当前的HP
	UPROPERTY(Blueprintable)
		float CurrentHP;






	
	
};

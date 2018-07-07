// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "UserWidget_HPBar.h"
#include "AICharacter.generated.h"


//AI��

UCLASS()
class INFINITYBLADE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// ���췽��
	AAICharacter();

	//���WidgetUI���
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UWidgetComponent* HPWidget;
	//����HP
	UPROPERTY(EditAnywhere, category = "State", BlueprintReadOnly)
		float TotalHP;
	//����BaseDamage
	UPROPERTY(EditAnywhere, category = "State", BlueprintReadOnly)
		float BaseDamage;
	//������ǰ��HP
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentHP;
	UPROPERTY()
		UUserWidget_HPBar* BPBar;



/*public:
	virtual void BeginPlay() override;*/


	
	
};

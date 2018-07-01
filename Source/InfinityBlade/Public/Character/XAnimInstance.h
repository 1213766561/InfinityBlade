// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "XAnimInstance.generated.h"

/**
 * ����ʵ��
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	//�����ٶȱ���
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;

public:
	//����������ٶ�
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();

		
	
	
};

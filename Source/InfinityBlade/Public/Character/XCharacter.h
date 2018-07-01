// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include"Camera/CameraComponent.h"
#include "XCharacter.generated.h"


/* Ӣ�۽�ɫ��*/

UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()
public:

	/* Camera�������*/
	UPROPERTY(EditAnywhere)
		UCameraComponent* CurrentCameraComponent;



public:
	//���췽��
	AXCharacter();

protected:
	//��Ϸ��ʼ����
	virtual void BeginPlay() override;



	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "XCharacter.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"

//���췽�����൱��ConstructEvent
AXCharacter::AXCharacter()
{

	//��ʼ��������
	CurrentCameraComponent = UObject::CreateDefaultSubobject<UCameraComponent>("CurrentCameraComponent");
	//��������
	CurrentCameraComponent->SetupAttachment(RootComponent);
	//���ý�ɫ�ƶ��ĳ���
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//���ý�ɫ�������ĳ���
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//�����ɫ����������
	CurrentCameraComponent->bUsePawnControlRotation = true;
}

// //��Ϸ��ʼ����
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "XCharacter.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"

//���췽�����൱��ConstructEvent
AXCharacter::AXCharacter()
{

	//��ʼ��������
	CurrentCameraComponent = UObject::CreateDefaultSubobject<UCameraComponent>("CurrentCameraComponent");
	//��ʼ�������
	//SpringArm = UObject::CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//��������
	//SpringArm->SetupAttachment(GetMesh());

	CurrentCameraComponent->SetupAttachment(GetMesh());//AttachToComponent(SpringArm,FAttachmentTransformRules::KeepWorldTransform);
	//���ý�ɫ�ƶ��ĳ���
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//���ý�ɫ�������ĳ���
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//�����ɫ����������
	CurrentCameraComponent->bUsePawnControlRotation = false;
}

// //��Ϸ��ʼ����
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


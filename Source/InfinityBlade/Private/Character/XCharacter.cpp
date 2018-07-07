// Fill out your copyright notice in the Description page of Project Settings.

#include "XCharacter.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"

//构造方法，相当于ConstructEvent
AXCharacter::AXCharacter()
{

	//初始化相机组件
	CurrentCameraComponent = UObject::CreateDefaultSubobject<UCameraComponent>("CurrentCameraComponent");
	//初始化相机架
	//SpringArm = UObject::CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//绑定相机组件
	//SpringArm->SetupAttachment(GetMesh());

	CurrentCameraComponent->SetupAttachment(GetMesh());//AttachToComponent(SpringArm,FAttachmentTransformRules::KeepWorldTransform);
	//设置角色移动的朝向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//设置角色控制器的朝向
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//相机角色控制器朝向
	CurrentCameraComponent->bUsePawnControlRotation = false;
}

// //游戏开始调用
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


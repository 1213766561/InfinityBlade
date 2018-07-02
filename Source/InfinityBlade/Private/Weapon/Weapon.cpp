// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include"Runtime/CoreUObject/Public/UObject/Object.h"


// Sets default values
AWeapon::AWeapon()
{
	//��ʼ��SceneComponent
	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	//Debug:������Mesh����Ϊ��Ŀ¼
	//��ʼ��SkeletalMesh
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponComponent"));
	//���������ĸ����
	WeaponComponent->SetupAttachment(RootComponent);
	//��ʼ��CapsuleComponent
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	//������������ײ��ĸ����
	CapsuleComponent->SetupAttachment(WeaponComponent);


}




// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include"Runtime/CoreUObject/Public/UObject/Object.h"


// Sets default values
AWeapon::AWeapon()
{
	//初始化SceneComponent
	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	//Debug:将武器Mesh设置为根目录
	//初始化SkeletalMesh
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponComponent"));
	//设置武器的父组件
	WeaponComponent->SetupAttachment(RootComponent);
	//初始化CapsuleComponent
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	//设置武器的碰撞体的父组件
	CapsuleComponent->SetupAttachment(WeaponComponent);


}




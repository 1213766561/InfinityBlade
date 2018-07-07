// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Weapon.generated.h"




//武器类

UCLASS()
class INFINITYBLADE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	//UPROPERTY(VisibleAnywhere)
		//USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* WeaponComponent;
	UPROPERTY()
		ACharacter* WeaponOwner;
		


	
public:	
	// 构造方法
	AWeapon();


	
	
};

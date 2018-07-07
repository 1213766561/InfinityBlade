// Fill out your copyright notice in the Description page of Project Settings.

#include "AICharacter.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "../../Public/AI/AICharacter.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"



// 构造方法
AAICharacter::AAICharacter()
{
	//初始化WidgetComponent
	HPWidget = UObject::CreateAbstractDefaultSubobject<UWidgetComponent>(TEXT("WidgeetHP"));
	HPWidget->SetupAttachment(GetMesh());

}






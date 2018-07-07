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
	//BPBar = Cast<UUserWidget_HPBar>(HPWidget->GetUserWidgetObject()->GetWidgetFromName(TEXT("BP_Widget_HPBar")));
	
	
}

/*void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = TotalHP;
	if (!BPBar) return;
	BPBar->ProgressBar_HP->SetPercent(CurrentHP / TotalHP);
	BPBar->TextBlock_CurrentHP->SetText(FText::FromString(FString::SanitizeFloat(CurrentHP)));
	BPBar->TextBlock_TotalHP->SetText(FText::FromString(FString::SanitizeFloat(TotalHP)));

	GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,FString::SanitizeFloat(CurrentHP / TotalHP));
}*/




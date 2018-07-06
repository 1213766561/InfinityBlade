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

// 游戏开始调用方法
void AAICharacter::BeginPlay()
{


	HP_Bar = Cast<UUserWidget_HPBar>(HPWidget->GetUserWidgetObject());
	//初始化CurrentHP
	CurrentHP = TotalHP;
	
	if (HP_Bar!=nullptr)
	{
		//初始化HPBar
		HP_Bar->UpdateHP(CurrentHP, TotalHP);
		//HP_Bar->HPBar->SetPercent(CurrentHP / TotalHP);
		//初始化HPTextBox
		//HP_Bar->CurrentHPTextBox->SetText(FText::AsPercent(CurrentHP));
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Success");
		//HP_Bar->TotalHPTextBar->SetText(FText::AsPercent(TotalHP));

	}
}


float AAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//Damamage逻辑
	CurrentHP -= BaseDamage;
	if (HP_Bar != nullptr)
	{
		//updateHP
		HP_Bar->UpdateHP(CurrentHP, TotalHP);
		//HP_Bar->HPBar->SetPercent(CurrentHP / TotalHP);
		//初始化HPTextBox
		//HP_Bar->CurrentHPTextBox->SetText(FText::AsPercent(CurrentHP));
		//HP_Bar->TotalHPTextBar->SetText(FText::AsPercent(TotalHP));

		return BaseDamage;
	}
	return BaseDamage;
}


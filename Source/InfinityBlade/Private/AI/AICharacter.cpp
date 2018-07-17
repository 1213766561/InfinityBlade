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
<<<<<<< HEAD

=======
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2
	
}

// 游戏开始调用方法
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = TotalHP;
	this->UpdateHP(0.f);

	/*HP_Bar = Cast<UUserWidget_HPBar>(HPWidget->GetUserWidgetObject());
	//初始化CurrentHP
	CurrentHP = TotalHP;
	
	if (HP_Bar!=nullptr)
	{
		//初始化HPBar
		
		HP_Bar->HPBar->SetPercent(CurrentHP / TotalHP);
		//初始化HPTextBox
		HP_Bar->CurrentHPTextBox->SetText(FText::AsPercent(CurrentHP));

		HP_Bar->TotalHPTextBar->SetText(FText::AsPercent(TotalHP));

	}*/
}


float AAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	this->UpdateHP(Damage);
	return Damage;
}



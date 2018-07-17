// Fill out your copyright notice in the Description page of Project Settings.

#include "AICharacter.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "../../Public/AI/AICharacter.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"



// ���췽��
AAICharacter::AAICharacter()
{

	//��ʼ��WidgetComponent
	HPWidget = UObject::CreateAbstractDefaultSubobject<UWidgetComponent>(TEXT("WidgeetHP"));
	HPWidget->SetupAttachment(GetMesh());
<<<<<<< HEAD

=======
>>>>>>> 4e395bded63bb5df97693e00099dbb11422e7fd2
	
}

// ��Ϸ��ʼ���÷���
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = TotalHP;
	this->UpdateHP(0.f);

	/*HP_Bar = Cast<UUserWidget_HPBar>(HPWidget->GetUserWidgetObject());
	//��ʼ��CurrentHP
	CurrentHP = TotalHP;
	
	if (HP_Bar!=nullptr)
	{
		//��ʼ��HPBar
		
		HP_Bar->HPBar->SetPercent(CurrentHP / TotalHP);
		//��ʼ��HPTextBox
		HP_Bar->CurrentHPTextBox->SetText(FText::AsPercent(CurrentHP));

		HP_Bar->TotalHPTextBar->SetText(FText::AsPercent(TotalHP));

	}*/
}


float AAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	this->UpdateHP(Damage);
	return Damage;
}



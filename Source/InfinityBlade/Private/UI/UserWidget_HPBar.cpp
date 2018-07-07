// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_HPBar.h"

bool UUserWidget_HPBar::Initialize()
{
	if (Super::Initialize())
	{
		return false;
	}

	//初始化HPBar
	HPBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_HP")));

	//初始化HPText
	CurrentHPTextBox = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_CurrentHP")));
	TotalHPTextBar = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_TotalHP")));
	
	return true;

}

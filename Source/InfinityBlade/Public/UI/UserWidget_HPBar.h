// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBar.h"
#include "TextBlock.h"
#include "UserWidget_HPBar.generated.h"

/**
 * HPBar UI
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_HPBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
		//ÉùÃ÷HPBar
		UProgressBar * HPBar;
	UPROPERTY()
		//ÉùÃ÷CurrentHP Text
		UTextBlock* CurrentHPTextBox;
	UPROPERTY()
		//ÉùÃ÷TotlalHP Text
		UTextBlock* TotalHPTextBar;

public:
	virtual bool Initialize() override;

	UFUNCTION()
		//UpdateHP
		void UpdateHP(float CurrentHP,float TotalHP);

	
	
};

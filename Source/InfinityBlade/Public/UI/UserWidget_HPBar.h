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
	UPROPERTY(Meta = (BindWidget),BlueprintReadWrite)
		//����HPBar
		UProgressBar * ProgressBar_HP;
	UPROPERTY(Meta = (BindWidget),BlueprintReadWrite)
		//����CurrentHP Text
		UTextBlock* TextBlock_CurrentHP;
	UPROPERTY(Meta = (BindWidget),BlueprintReadWrite)
		//����TotlalHP Text
		UTextBlock* TextBlock_TotalHP;




	
	
};

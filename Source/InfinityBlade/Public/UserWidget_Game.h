// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "ProgressBar.h"
#include "UserWidget_Game.generated.h"

/**
 * Ö÷½çÃæUI
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Game : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//ÉùÃ÷ÆÕÍ¨¹¥»÷Button
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Attack;
	//ÉùÃ÷HP
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* ProgressBar_HP;
	//ÉùÃ÷MP
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* ProgressBar_MP;
	//ÉùÃ÷º®±ùÖ®Ê¯button
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_IceStone;
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_RecoverLightSkill;
	
	
};

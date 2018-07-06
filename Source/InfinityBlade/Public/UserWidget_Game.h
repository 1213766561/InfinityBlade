// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "UserWidget_Game.generated.h"

/**
 * 主界面UI
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Game : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//声明普通攻击Button
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Attack;


	
	
};

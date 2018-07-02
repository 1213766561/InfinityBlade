// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "UserWidget_Game.generated.h"

/**
 * ������UI
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_Game : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//������ͨ����Button
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Attack;


	
	
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CircularThrobber.h"
#include "TextBlock.h"
#include "UserWidget_LoadingMap.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UUserWidget_LoadingMap : public UUserWidget
{
	GENERATED_BODY()
	
	//声明需要控制的控件
public:
	UPROPERTY()
		UTextBlock* SuccessText;
	UPROPERTY()
		UTextBlock* LoadingText;
	UPROPERTY()
		UCircularThrobber* CircularLoading;

public:
	virtual bool Initialize() override;

	
	
};

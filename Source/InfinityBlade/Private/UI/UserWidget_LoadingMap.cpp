// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_LoadingMap.h"

bool UUserWidget_LoadingMap::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//��ʼ�����Loading
	SuccessText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_SuccessText")));
	SuccessText->SetVisibility(ESlateVisibility::Hidden);
	//��ʼ��Loading����
	CircularLoading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Loading")));
	CircularLoading->SetVisibility(ESlateVisibility::Visible);
	LoadingText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Loading")));
	LoadingText->SetVisibility(ESlateVisibility::Visible);

	return true;
}



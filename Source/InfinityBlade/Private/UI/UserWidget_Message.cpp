// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Message.h"




bool UUserWidget_Message::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	/* �����ı���*/
	MessageText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Message")));
	
	/* �����رհ�ť*/
	CloseButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_MessageClose")));
	/* ���ùرհ�ť�ûص�*/
	CloseButton->OnClicked.AddDynamic(this,&UUserWidget_Message::ClosButtonOnClickedEvent);
	
	return true;
}

void UUserWidget_Message::ClosButtonOnClickedEvent()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

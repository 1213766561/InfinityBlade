// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Message.h"




bool UUserWidget_Message::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	/* 创建文本框*/
	MessageText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Message")));
	
	/* 创建关闭按钮*/
	CloseButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_MessageClose")));
	/* 设置关闭按钮得回调*/
	CloseButton->OnClicked.AddDynamic(this,&UUserWidget_Message::ClosButtonOnClickedEvent);
	
	return true;
}

void UUserWidget_Message::ClosButtonOnClickedEvent()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

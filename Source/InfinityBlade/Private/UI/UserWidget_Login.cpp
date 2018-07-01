// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidget_Login.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"

bool UUserWidget_Login::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//初始化返回按钮
	BlackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	//初始化开始按钮
	AgreeBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	//初始化姓名框
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	//初始化Message框
	MessageBox = Cast<UUserWidget_Message>(GetWidgetFromName(TEXT("BP_Widget_Message")));
	MessageBox->SetVisibility(ESlateVisibility::Hidden);
	//进入游戏按钮点击事件回调
	AgreeBtn->OnClicked.AddDynamic(this, &UUserWidget_Login::StarGameBtnOnClickedEvent);

	return true;

}

//进入游戏之前的校验，因为服务器的原因，先只验证用户名不为空
void UUserWidget_Login::StarGameBtnOnClickedEvent()
{
	FString Nickname = NicknameInput->GetText().ToString();
	if (Nickname.IsEmpty())
	{
		MessageBox->MessageText->SetText(FText::FromString("Name is Empty!"));
		MessageBox->SetVisibility(ESlateVisibility::Visible);

		return;
	}
	//获取到对应的GameInstance
	UCustomGameInstance* GameInstance = Cast<UCustomGameInstance>(GetWorld()->GetGameInstance());
	//保存数据在GameInstance
	GameInstance->CurrentPlayerName = Nickname;
	//关卡加载
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Map/Map_Game"));
	  

}

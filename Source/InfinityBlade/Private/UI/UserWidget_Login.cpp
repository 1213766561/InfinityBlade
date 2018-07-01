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
	//��ʼ�����ذ�ť
	BlackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	//��ʼ����ʼ��ť
	AgreeBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	//��ʼ��������
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	//��ʼ��Message��
	MessageBox = Cast<UUserWidget_Message>(GetWidgetFromName(TEXT("BP_Widget_Message")));
	MessageBox->SetVisibility(ESlateVisibility::Hidden);
	//������Ϸ��ť����¼��ص�
	AgreeBtn->OnClicked.AddDynamic(this, &UUserWidget_Login::StarGameBtnOnClickedEvent);

	return true;

}

//������Ϸ֮ǰ��У�飬��Ϊ��������ԭ����ֻ��֤�û�����Ϊ��
void UUserWidget_Login::StarGameBtnOnClickedEvent()
{
	FString Nickname = NicknameInput->GetText().ToString();
	if (Nickname.IsEmpty())
	{
		MessageBox->MessageText->SetText(FText::FromString("Name is Empty!"));
		MessageBox->SetVisibility(ESlateVisibility::Visible);

		return;
	}
	//��ȡ����Ӧ��GameInstance
	UCustomGameInstance* GameInstance = Cast<UCustomGameInstance>(GetWorld()->GetGameInstance());
	//����������GameInstance
	GameInstance->CurrentPlayerName = Nickname;
	//�ؿ�����
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Map/Map_Game"));
	  

}

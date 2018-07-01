// Fill out your copyright notice in the Description page of Project Settings.

#include"MyGameMode.h"
#include "LinkerLoad.h"
#include"UserWidget.h"
#include "Runtime/Slate/Public/Framework/Application/SlateApplication.h"
#include "../../Public/GameMode/MyGameMode.h"
//#include "..\..\Public\GameMode\MyGameMode.h"
//#include"Math/Color.h"
//#include"Engine/Engine.h"


void AMyGameMode::BeginPlay()
{

	/* ��ʼ����ʼ����*/
	StartWidget = CreateWidget<UUserWidget_Start>(GetGameInstance(), LoadClass<UUserWidget_Start>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Start.BP_Widget_Start_C'")));
	//��ʼ����Ϸ��½����
	LoginWidget = CreateWidget<UUserWidget_Login>(GetGameInstance(), LoadClass<UUserWidget_Login>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Login.BP_Widget_Login_C'")));
	/* ��ʼ��ע�����*/
	RegisterWidget = CreateWidget<UUserWidget_Register>(GetGameInstance(), LoadClass<UUserWidget_Register>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Register.BP_Widget_Register_C'")));
	/* ��ӵ��ӿ�*/
	StartWidget->AddToViewport();
	/* ע���˺Ű�ť�ĵ���¼��ص�*/
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AMyGameMode::RegisterBtnOnClickedEvent);
	/* ���ذ�ť����¼��ص�*/
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this, &AMyGameMode::BackBtnOnClickedEvent);
	/* �����ʼ��Ϸ�¼���*/
	StartWidget->StartBtn->OnClicked.AddDynamic(this, &AMyGameMode::StartBtnOnClikedEvent);
	//������淵�ذ�ť�¼��ص�
	LoginWidget->BlackBtn->OnClicked.AddDynamic(this, &AMyGameMode::BlackBtnOnClickedEvent);
	
	/*������Ϸ��ť�¼��ص�����ʼ����д��Game Mode����
	LoginWidget->AgreeBtn->OnClicked.AddDynamic(this, &AMyGameMode::StarGameBtnOnClickedEvent);
	*/
}

/* ע�ᰴť����¼�*/
void AMyGameMode::RegisterBtnOnClickedEvent()
{
	/* ��Ϸ��ʼ�����Ƴ�*/
	StartWidget->RemoveFromViewport();
	/* �����Ϸע�����*/
	RegisterWidget->AddToViewport();


}


/* ���ذ�ť����¼�*/
void AMyGameMode::BackBtnOnClickedEvent()
{
	/* ע������Ƴ�*/
	RegisterWidget->RemoveFromViewport();
	/* ��ӿ�ʼ����*/
	StartWidget->AddToViewport();

}

//��ʼ��Ϸ��ť����¼�
void AMyGameMode::StartBtnOnClikedEvent()
{
	
	//��������˺Ž���
	LoginWidget->AddToViewport();
	//�Ƴ���ʼ��Ϸ����
	StartWidget->RemoveFromViewport();
}

//��½���淵�ذ�ť����¼�
void AMyGameMode::BlackBtnOnClickedEvent()
{
	//�Ƴ��������
	LoginWidget->RemoveFromViewport();
	//��ӿ�ʼ����
	StartWidget->AddToViewport();
}

/*��ʼ��д��GameMode����
//������Ϸ��ť����¼�
void AMyGameMode::StarGameBtnOnClickedEvent()
{
	//����Ӧ����У�飬��Ϊ��������ԭ��ֻУ������
	FString Nickname;
	Nickname = LoginWidget->NicknameInput->GetText().ToString();
	if (Nickname.IsEmpty())
	{
		LoginWidget->MessageBox->SetVisibility(ESlateVisibility::Visible);
	}
}
*/

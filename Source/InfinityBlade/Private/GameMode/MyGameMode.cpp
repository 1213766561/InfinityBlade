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

	/* 初始化初始界面*/
	StartWidget = CreateWidget<UUserWidget_Start>(GetGameInstance(), LoadClass<UUserWidget_Start>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Start.BP_Widget_Start_C'")));
	//初始化游戏登陆界面
	LoginWidget = CreateWidget<UUserWidget_Login>(GetGameInstance(), LoadClass<UUserWidget_Login>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Login.BP_Widget_Login_C'")));
	/* 初始化注册界面*/
	RegisterWidget = CreateWidget<UUserWidget_Register>(GetGameInstance(), LoadClass<UUserWidget_Register>(this, TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Register.BP_Widget_Register_C'")));
	/* 添加到视口*/
	StartWidget->AddToViewport();
	/* 注册账号按钮的点击事件回调*/
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AMyGameMode::RegisterBtnOnClickedEvent);
	/* 返回按钮点击事件回调*/
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this, &AMyGameMode::BackBtnOnClickedEvent);
	/* 点击开始游戏事件绑定*/
	StartWidget->StartBtn->OnClicked.AddDynamic(this, &AMyGameMode::StartBtnOnClikedEvent);
	//输入界面返回按钮事件回调
	LoginWidget->BlackBtn->OnClicked.AddDynamic(this, &AMyGameMode::BlackBtnOnClickedEvent);
	
	/*进入游戏按钮事件回调，开始打算写在Game Mode里面
	LoginWidget->AgreeBtn->OnClicked.AddDynamic(this, &AMyGameMode::StarGameBtnOnClickedEvent);
	*/
}

/* 注册按钮点击事件*/
void AMyGameMode::RegisterBtnOnClickedEvent()
{
	/* 游戏开始界面移除*/
	StartWidget->RemoveFromViewport();
	/* 添加游戏注册界面*/
	RegisterWidget->AddToViewport();


}


/* 返回按钮点击事件*/
void AMyGameMode::BackBtnOnClickedEvent()
{
	/* 注册界面移除*/
	RegisterWidget->RemoveFromViewport();
	/* 添加开始界面*/
	StartWidget->AddToViewport();

}

//开始游戏按钮点击事件
void AMyGameMode::StartBtnOnClikedEvent()
{
	
	//添加输入账号界面
	LoginWidget->AddToViewport();
	//移除开始游戏界面
	StartWidget->RemoveFromViewport();
}

//登陆界面返回按钮点击事件
void AMyGameMode::BlackBtnOnClickedEvent()
{
	//移除输入界面
	LoginWidget->RemoveFromViewport();
	//添加开始界面
	StartWidget->AddToViewport();
}

/*开始想写在GameMode里面
//进入游戏按钮点击事件
void AMyGameMode::StarGameBtnOnClickedEvent()
{
	//本来应该有校验，因为服务器的原因，只校验名字
	FString Nickname;
	Nickname = LoginWidget->NicknameInput->GetText().ToString();
	if (Nickname.IsEmpty())
	{
		LoginWidget->MessageBox->SetVisibility(ESlateVisibility::Visible);
	}
}
*/

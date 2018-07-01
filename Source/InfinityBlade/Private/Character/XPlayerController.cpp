// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "LinkerLoad.h"
#include "../../Public/Character/XPlayerController.h"


//绑定输入控件

void AXPlayerController::BeginPlay()
{
	//初始化Character
	XCharacter = Cast<AXCharacter>(GetPawn());
	//初始化游戏主UI
	MainUserWidget = CreateWidget<UUserWidget_Game>(GetGameInstance(), LoadClass<UUserWidget_Game>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Game.BP_Widget_Game_C'")));
	MainUserWidget->AddToViewport();
}

void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveeForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
}

//前后移动
void AXPlayerController::MoveeForward(float Speed)
{
	FRotator ControllerRotation = GetControlRotation();
	FRotator ControllerYawRotation (0.f, ControllerRotation.Yaw,0.f);

	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	//获取移动方法
	XCharacter->AddMovementInput(Direction, Speed);
}

//左右移动
void AXPlayerController::MoveRight(float Speed)
{
	FRotator ControllerRotation = GetControlRotation();
	FRotator ControllerYawRotation(0.f, ControllerRotation.Yaw, 0.f);

	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);
	//获取移动方法
	XCharacter->AddMovementInput(Direction, Speed);
}

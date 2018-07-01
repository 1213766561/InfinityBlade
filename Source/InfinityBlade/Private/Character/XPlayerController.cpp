// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "LinkerLoad.h"
#include "../../Public/Character/XPlayerController.h"


//������ؼ�

void AXPlayerController::BeginPlay()
{
	//��ʼ��Character
	XCharacter = Cast<AXCharacter>(GetPawn());
	//��ʼ����Ϸ��UI
	MainUserWidget = CreateWidget<UUserWidget_Game>(GetGameInstance(), LoadClass<UUserWidget_Game>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Game.BP_Widget_Game_C'")));
	MainUserWidget->AddToViewport();
}

void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveeForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
}

//ǰ���ƶ�
void AXPlayerController::MoveeForward(float Speed)
{
	FRotator ControllerRotation = GetControlRotation();
	FRotator ControllerYawRotation (0.f, ControllerRotation.Yaw,0.f);

	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	//��ȡ�ƶ�����
	XCharacter->AddMovementInput(Direction, Speed);
}

//�����ƶ�
void AXPlayerController::MoveRight(float Speed)
{
	FRotator ControllerRotation = GetControlRotation();
	FRotator ControllerYawRotation(0.f, ControllerRotation.Yaw, 0.f);

	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);
	//��ȡ�ƶ�����
	XCharacter->AddMovementInput(Direction, Speed);
}

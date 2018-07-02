// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "LinkerLoad.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "../../Public/Character/XPlayerController.h"


//绑定输入控件

void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true; 
	//初始化Character
	XCharacter = Cast<AXCharacter>(GetPawn());
	//初始化游戏主UI
	MainUserWidget = CreateWidget<UUserWidget_Game>(GetGameInstance(), LoadClass<UUserWidget_Game>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Game.BP_Widget_Game_C'")));
	MainUserWidget->AddToViewport();
	//初始化动画实例
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//初始化普攻按钮函数调用
	InitWidgetEvent();

	
	//判断武器类是否有效
	if (XCharacter->XWeapon)
	{
		//生成一个武器对象
		XWeapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeapon);
		//绑定规则
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		//绑定武器
		XWeapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
	}
	


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



//控件按钮初始化方法
void AXPlayerController::InitWidgetEvent()
{
	if (MainUserWidget->Button_Attack)
	{
		MainUserWidget->Button_Attack->OnClicked.AddDynamic(this, &AXPlayerController::AttackBtnOnClickedEvent);
	}
}



//攻击按钮点击事件
void AXPlayerController::AttackBtnOnClickedEvent()
{
	
	//判断是否正在播放
	if (XAnimInstance->bIsPlaying)
	{
		return;
	}
	//获得连击动画
	UAnimMontage* SerialAttachMontage = XCharacter->SerialAttachMontage;
	//获得当前播放的节点
	FName CurrentSection =XAnimInstance->Montage_GetCurrentSection(SerialAttachMontage);
	//判断
	if (CurrentSection.IsNone())
	{
		//默认播放第一节
		XAnimInstance->Montage_Play(SerialAttachMontage);
		
	}
	else if (CurrentSection.IsEqual(FName("FirstSection")) && XAnimInstance->bInEnableScondAttack)
	{
		
		//默认播放第二节
		XAnimInstance->Montage_JumpToSection(FName("SecondSection"), SerialAttachMontage);
		
	}
	else if (CurrentSection.IsEqual(FName("SecondSection")) && XAnimInstance->bInEnableThreeAttack)
	{
		//默认播放第3节
		XAnimInstance->Montage_JumpToSection(FName("ThreeSection"), SerialAttachMontage);
		

	}
	else if (CurrentSection.IsEqual(FName("ThreeSection")) && XAnimInstance->bInEnableFourAttack)
	{
		//默认播放第4节
		XAnimInstance->Montage_JumpToSection(FName("FourSection"), SerialAttachMontage);
		

	}
	else if (CurrentSection.IsEqual(FName("FourSection")) && XAnimInstance->bInEnableFiveAttack)
	{
		//默认播放第5节
		XAnimInstance->Montage_JumpToSection(FName("FiveSection"), SerialAttachMontage);
	}
	
}


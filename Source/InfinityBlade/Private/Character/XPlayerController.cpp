// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "LinkerLoad.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "../../Public/Character/XPlayerController.h"


//������ؼ�

void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true; 
	
	

	//��ʼ����Ϸ��UI
	MainUserWidget = CreateWidget<UUserWidget_Game>(GetGameInstance(), LoadClass<UUserWidget_Game>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Game.BP_Widget_Game_C'")));
	MainUserWidget->AddToViewport();
	//��ʼ��UI
	InitUI();
	//��ʼ���չ���ť��������
	InitWidgetEvent();



	
	//�ж��������Ƿ���Ч
	if (XCharacter->XWeapon)
	{
		//����һ����������
		XWeapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeapon);
		//�󶨹���
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		//������
		XWeapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
	}
	
	//�������˺��¼��ص�
	XWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AXPlayerController::WeaponOverlapEvent);

}

//possPlayeerʵ��
void AXPlayerController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);

	//aPawn = GetPawn();
	//��ʼ��Character
	XCharacter = Cast<AXCharacter>(aPawn);
	//��ʼ������ʵ��
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//��ʼ��PlayerState;
	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
	//��ʼ����ҵ�״̬
	SetupPlayerState();
}


//��ʼ����ҵ�״̬

void AXPlayerController::SetupPlayerState()
{
	//���õ�ǰ��HP
	XPlayerState->SetCurrentHP(XCharacter->TotalHP);
	//���õ�ǰ��MP
	XPlayerState->SetCurrentMP(XCharacter->TotalMP);
	//���õ�ǰ���չ��˺�
	XPlayerState->SetAttackDamage(XCharacter->AttackDamage);
}

void AXPlayerController::InitUI()
{
	//����HP
	if (MainUserWidget->ProgressBar_HP)
	{
		MainUserWidget->ProgressBar_HP->SetPercent(1.0 - (XPlayerState->GetCurrentHP() / XCharacter->TotalHP));
	}
	//����MP
	if (MainUserWidget->ProgressBar_MP)
	{
		
		MainUserWidget->ProgressBar_MP->SetPercent(1.0 - (XPlayerState->GetCurrentMP() / XCharacter->TotalMP));

	}
}

void AXPlayerController::WeaponOverlapEvent(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Overlap");

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



//�ؼ���ť��ʼ������
void AXPlayerController::InitWidgetEvent()
{
	if (MainUserWidget->Button_Attack)
	{
		MainUserWidget->Button_Attack->OnClicked.AddDynamic(this, &AXPlayerController::AttackBtnOnClickedEvent);
	}
}




//������ť����¼�
void AXPlayerController::AttackBtnOnClickedEvent()
{
	
	
	//�ж��Ƿ����ڲ���
	if (XAnimInstance->bIsPlaying)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "True");
		return;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "False");

	//�����������
	UAnimMontage* SerialAttachMontage = XCharacter->SerialAttachMontage;
	//��õ�ǰ���ŵĽڵ�
	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttachMontage);
	//�ж�
	if (CurrentSection.IsNone())
	{
		//Ĭ�ϲ��ŵ�һ��
		XAnimInstance->Montage_Play(SerialAttachMontage);
		
	}
	else if (CurrentSection.IsEqual(FName("FirstSection")) && XAnimInstance->bInEnableScondAttack)
	{
		
		//Ĭ�ϲ��ŵڶ���
		XAnimInstance->Montage_JumpToSection(FName("SecondSection"), SerialAttachMontage);
		
	}
	else if (CurrentSection.IsEqual(FName("SecondSection")) && XAnimInstance->bInEnableThreeAttack)
	{
		//Ĭ�ϲ��ŵ�3��
		XAnimInstance->Montage_JumpToSection(FName("ThreeSection"), SerialAttachMontage);
		

	}
	else if (CurrentSection.IsEqual(FName("ThreeSection")) && XAnimInstance->bInEnableFourAttack)
	{
		//Ĭ�ϲ��ŵ�4��
		XAnimInstance->Montage_JumpToSection(FName("FourSection"), SerialAttachMontage);
		

	}
	else if (CurrentSection.IsEqual(FName("FourSection")) && XAnimInstance->bInEnableFiveAttack)
	{
		//Ĭ�ϲ��ŵ�5��
		XAnimInstance->Montage_JumpToSection(FName("FiveSection"), SerialAttachMontage);
	}
	
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "LinkerLoad.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AI/AICharacter.h"
#include "../../Public/Character/XPlayerController.h"


//������ؼ�

void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true; 
	
	

	//��ʼ����Ϸ��UI
	MainUserWidget = CreateWidget<UUserWidget_Game>(GetGameInstance(), LoadClass<UUserWidget_Game>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Game.BP_Widget_Game_C'")));
	MainUserWidget->AddToViewport();
	//��ʼ��UI
	UpdateUI();
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
		XWeapon->WeaponComponent->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		//��WeaponOwner
		XWeapon->WeaponOwner = XCharacter;
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

//����HP��MP����

void AXPlayerController::UpdatePlayerState(float UpdateHP, float UpdateMP)
{

	XPlayerState->SetCurrentHP(XPlayerState->GetCurrentHP() - UpdateHP);
	XPlayerState->SetCurrentMP(XPlayerState->GetCurrentMP()- UpdateMP);

}

void AXPlayerController::UpdateUI()
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
	if (XWeapon->WeaponOwner)
	{
		if (XAnimInstance->BIsAttack)
		{
			UGameplayStatics::ApplyDamage(OtherActor, XAnimInstance->NormalAttackDamage, this, XCharacter, nullptr);
		}

		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::SanitizeFloat(XPlayerState->GetAttackDamage()));

		/*DmagedCharacter = Cast<ACharacter>(SweepResult->Break->GetHit);
		if (DmagedCharacter != nullptr && DmagedCharacter != WeaponOwner)
		{
			DmagedCharacter->TakeDamage(XPlayerState->GetAttackDamage(), FDamageEvent::)
		}*/
		
	}
}




void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveeForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AXPlayerController::Trun);
	InputComponent->BindAxis("Lookup", this, &AXPlayerController::Lookup);
}


//ǰ���ƶ�
void AXPlayerController::MoveeForward(float Speed)
{
	FRotator ControllerRotation = GetControlRotation(); // this->GetActorRotation();
	FRotator ControllerYawRotation (0.f, ControllerRotation.Yaw,0.f);
	//FRotator ControllerYawRotation(0.f,0.f, ControllerRotation.Yaw);
	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	//FVector Direction = ControllerYawRotation->GetForwardVector()
	//��ȡ�ƶ�����
	if (XCharacter)
	{
		XCharacter->AddMovementInput(Direction, Speed);
	}

}

//�����ƶ�
void AXPlayerController::MoveRight(float Speed)
{
	FRotator ControllerRotation = GetControlRotation();
	FRotator ControllerYawRotation(0.f, ControllerRotation.Yaw, 0.f);
	//FRotator ControllerYawRotation(0.f, 0.f, ControllerRotation.Yaw);
	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);
	//��ȡ�ƶ�����
	if (XCharacter)
	{
		XCharacter->AddMovementInput(Direction, Speed);
	}
	
}

void AXPlayerController::Trun(float Speed)
{
	if (XCharacter)
	{
		XCharacter->AddControllerYawInput(Speed);
	}

}

void AXPlayerController::Lookup(float Speed)
{
	if (XCharacter)
	{
		XCharacter->AddControllerPitchInput(Speed);
	}

}


//��������
void AXPlayerController::LockEnemy(float HitRadius)
{
	//����Լ���λ��
	FVector USLocation = XCharacter->GetActorLocation();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICharacter::StaticClass(), AIArray);
	int AINum = AIArray.Num();
	if (AINum>0)
	{
		AActor* MinActor = AIArray[0];
		float MinDistance = FVector::Dist(USLocation, AIArray[0]->GetActorLocation());
		
		for (int i = 1; i < AINum; i++)
		{
			if (Cast<AAICharacter>(AIArray[i])->bIsDead)
			{
				//�����˴�ѭ����������һ��ѭ��
				continue;
			}
			//��þ���
			float TmpDistance = FVector::Dist(USLocation, AIArray[i]->GetActorLocation());
			if (MinDistance > TmpDistance)
			{
				MinDistance = TmpDistance;
				MinActor = AIArray[i];
			}

		}
		//�ж���С�����С
		if (MinDistance<= HitRadius)
		{
			//���㳯�򣬳�������ĵ���
			FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(USLocation, MinActor->GetActorLocation());
			//�޸ĳ���
			TargetRotation.Roll = XCharacter->GetCapsuleComponent()->GetComponentRotation().Roll;
			TargetRotation.Pitch = XCharacter->GetCapsuleComponent()->GetComponentRotation().Pitch;
			//���ó���
			XCharacter->GetCapsuleComponent()->SetWorldRotation(TargetRotation);
		

		}


	}
}



//�ؼ���ť��ʼ������
void AXPlayerController::InitWidgetEvent()
{
	if (MainUserWidget->Button_Attack)
	{
		MainUserWidget->Button_Attack->OnClicked.AddDynamic(this, &AXPlayerController::AttackBtnOnClickedEvent);
	}
	if (MainUserWidget->Button_IceStone)
	{
		MainUserWidget->Button_IceStone->OnClicked.AddDynamic(this, &AXPlayerController::IceStoneOnClickedEvent);
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

	LockEnemy(400.f);

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

void AXPlayerController::IceStoneOnClickedEvent()
{

	LockEnemy(1500.f);
	if (XPlayerState->GetCurrentMP()>=10.f)
	{
		if (XCharacter != nullptr)
		{
			if (XAnimInstance->bIsPlaying)
			{
				return;
			}

			UpdatePlayerState(0.f, 10.f);
			UpdateUI();
			XCharacter->PlayAnimMontage(XCharacter->IceStoneSkillMontage);
			return;
		}
		return;
	}
	
}


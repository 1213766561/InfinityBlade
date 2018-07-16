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


//绑定输入控件

void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true; 
	
	

	//初始化游戏主UI
	MainUserWidget = CreateWidget<UUserWidget_Game>(GetGameInstance(), LoadClass<UUserWidget_Game>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_Widget_Game.BP_Widget_Game_C'")));
	MainUserWidget->AddToViewport();
	//初始化UI
	UpdateUI();
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
		XWeapon->WeaponComponent->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		//绑定WeaponOwner
		XWeapon->WeaponOwner = XCharacter;
	}
	
	//绑定武器伤害事件回调
	XWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AXPlayerController::WeaponOverlapEvent);

}

//possPlayeer实例
void AXPlayerController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);

	//aPawn = GetPawn();
	//初始化Character
	XCharacter = Cast<AXCharacter>(aPawn);
	//初始化动画实例
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//初始化PlayerState;
	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
	//初始化玩家的状态
	SetupPlayerState();
}


//初始化玩家的状态

void AXPlayerController::SetupPlayerState()
{
	//设置当前的HP
	XPlayerState->SetCurrentHP(XCharacter->TotalHP);
	//设置当前的MP
	XPlayerState->SetCurrentMP(XCharacter->TotalMP);
	//设置当前的普攻伤害
	XPlayerState->SetAttackDamage(XCharacter->AttackDamage);
}

//更新HP，MP函数

void AXPlayerController::UpdatePlayerState(float UpdateHP, float UpdateMP)
{

	XPlayerState->SetCurrentHP(XPlayerState->GetCurrentHP() - UpdateHP);
	XPlayerState->SetCurrentMP(XPlayerState->GetCurrentMP()- UpdateMP);

}

void AXPlayerController::UpdateUI()
{
	//更新HP
	if (MainUserWidget->ProgressBar_HP)
	{
		MainUserWidget->ProgressBar_HP->SetPercent(1.0 - (XPlayerState->GetCurrentHP() / XCharacter->TotalHP));
	}
	//更新MP
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


//前后移动
void AXPlayerController::MoveeForward(float Speed)
{
	FRotator ControllerRotation = GetControlRotation(); // this->GetActorRotation();
	FRotator ControllerYawRotation (0.f, ControllerRotation.Yaw,0.f);
	//FRotator ControllerYawRotation(0.f,0.f, ControllerRotation.Yaw);
	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	//FVector Direction = ControllerYawRotation->GetForwardVector()
	//获取移动方法
	if (XCharacter)
	{
		XCharacter->AddMovementInput(Direction, Speed);
	}

}

//左右移动
void AXPlayerController::MoveRight(float Speed)
{
	FRotator ControllerRotation = GetControlRotation();
	FRotator ControllerYawRotation(0.f, ControllerRotation.Yaw, 0.f);
	//FRotator ControllerYawRotation(0.f, 0.f, ControllerRotation.Yaw);
	FVector Direction = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);
	//获取移动方法
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


//锁定敌人
void AXPlayerController::LockEnemy(float HitRadius)
{
	//获得自己的位置
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
				//跳出此次循环，进行下一次循环
				continue;
			}
			//获得距离
			float TmpDistance = FVector::Dist(USLocation, AIArray[i]->GetActorLocation());
			if (MinDistance > TmpDistance)
			{
				MinDistance = TmpDistance;
				MinActor = AIArray[i];
			}

		}
		//判断最小距离大小
		if (MinDistance<= HitRadius)
		{
			//计算朝向，朝向最近的敌人
			FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(USLocation, MinActor->GetActorLocation());
			//修改朝向
			TargetRotation.Roll = XCharacter->GetCapsuleComponent()->GetComponentRotation().Roll;
			TargetRotation.Pitch = XCharacter->GetCapsuleComponent()->GetComponentRotation().Pitch;
			//设置朝向
			XCharacter->GetCapsuleComponent()->SetWorldRotation(TargetRotation);
		

		}


	}
}



//控件按钮初始化方法
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




//攻击按钮点击事件
void AXPlayerController::AttackBtnOnClickedEvent()
{
	
	
	//判断是否正在播放
	if (XAnimInstance->bIsPlaying)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "True");
		return;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "False");

	LockEnemy(400.f);

	//获得连击动画
	UAnimMontage* SerialAttachMontage = XCharacter->SerialAttachMontage;
	//获得当前播放的节点
	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttachMontage);
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


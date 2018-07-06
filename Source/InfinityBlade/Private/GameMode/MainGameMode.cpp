// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"



//���췽��
AMainGameMode::AMainGameMode()
{
	/* �ҵ���Դ�е�Ĭ��CharacterClass����������ΪĬ��*/
	ConstructorHelpers::FClassFinder<ACharacter> CharacterFinder(TEXT("/Game/Character/BP_XCharacter"));
	DefaultPawnClass = CharacterFinder.Class;
	//����PlayerController
	PlayerControllerClass = AXPlayerController::StaticClass();
	//����PlayerState
	PlayerStateClass = AXPlayerState::StaticClass();
}

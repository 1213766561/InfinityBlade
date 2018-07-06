// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"



//构造方法
AMainGameMode::AMainGameMode()
{
	/* 找到资源中的默认CharacterClass并将其设置为默认*/
	ConstructorHelpers::FClassFinder<ACharacter> CharacterFinder(TEXT("/Game/Character/BP_XCharacter"));
	DefaultPawnClass = CharacterFinder.Class;
	//设置PlayerController
	PlayerControllerClass = AXPlayerController::StaticClass();
	//设置PlayerState
	PlayerStateClass = AXPlayerState::StaticClass();
}

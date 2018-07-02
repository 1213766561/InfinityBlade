// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "UserWidget_LoadingMap.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"


/**
 * GameInstanceBase
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	//�洢����
	//TMap<FString, FString> ContexMap;
	UPROPERTY()
	FString CurrentPlayerName;

	//�������ص�ͼ��Widget
	UPROPERTY()
		UUserWidget_LoadingMap* LoadingMap;

public:
	//��ʼ������
	virtual void Init() override;


	//���ؿ�ʼ�ĺ���
	UFUNCTION()
		void PreLoadMap(const FString& Map);
	//�������صĺ���
	UFUNCTION()
		void PostLoadMap(UWorld* World);
	
};
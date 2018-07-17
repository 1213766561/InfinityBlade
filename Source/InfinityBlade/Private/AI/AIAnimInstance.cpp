// Fill out your copyright notice in the Description page of Project Settings.

#include "AIAnimInstance.h"
#include "AI/AICharacter.h"
#include "../../Public/AI/AIAnimInstance.h"

void UAIAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner())
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}		
}

void UAIAnimInstance::AnimNotify_PlayStart(UAnimNotify* Notify)
{
	bIsAttack = true;
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, "Attack");
}

void UAIAnimInstance::AnimNotify_PlayEnd(UAnimNotify* Notify)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Black, "No Attack");

	bIsAttack = false;

}

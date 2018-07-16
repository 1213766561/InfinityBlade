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

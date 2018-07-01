// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"
#include "../../Public/Character/XAnimInstance.h"

void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner()!=NULL)
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"


void UXAnimInstance::UpdateSpeed()
{

	if (TryGetPawnOwner()!=nullptr)
	{
		speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

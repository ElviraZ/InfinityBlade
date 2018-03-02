// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "XAnimInstance.generated.h"

/**
 * Ó¢ÐÛµÄ¶¯»­ÊµÀý
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float speed;
	UFUNCTION(BlueprintCallable)
		void  UpdateSpeed();
};

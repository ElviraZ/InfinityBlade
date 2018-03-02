// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include"Runtime/Engine/Classes/Camera/CameraComponent.h"
#include"GameFramework/CharacterMovementComponent.h"
#include "XCharacter.generated.h"
/**
*
*Ó¢ÐÛ½ÇÉ«Àà
*
*
*/
UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AXCharacter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent*  CameraComponent;

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	
	
};

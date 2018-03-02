// Fill out your copyright notice in the Description page of Project Settings.

#include "XCharacter.h"



// Sets default values
AXCharacter::AXCharacter()
{//设置角色的朝向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//设置角色控制的朝向
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}




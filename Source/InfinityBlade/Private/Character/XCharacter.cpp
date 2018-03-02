// Fill out your copyright notice in the Description page of Project Settings.

#include "XCharacter.h"



// Sets default values
AXCharacter::AXCharacter()
{//���ý�ɫ�ĳ���
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//���ý�ɫ���Ƶĳ���
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




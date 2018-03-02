// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"


void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);

}

void AXPlayerController::BeginPlay()
{
	XCharacter = Cast<AXCharacter>(GetPawn());
	MainUserWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/UI/BP_MainUserWidget.BP_MainUserWidget_c'")));
	if (MainUserWidget!=NULL)
	{
		MainUserWidget->AddToViewport();
	}
}

void AXPlayerController::MoveForward(float speed)
{
	FRotator  Rotation = GetControlRotation();
	FRotator  yawRotation(0.f, Rotation.Yaw, 0.f);

	FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	XCharacter->AddMovementInput(direction, speed);


}

void AXPlayerController::MoveRight(float speed)
{
	FRotator  Rotation = GetControlRotation();
	FRotator  yawRotation(0.f, Rotation.Yaw, 0.f);

	FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	XCharacter->AddMovementInput(direction, speed);
}

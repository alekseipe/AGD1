// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AGDPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAGDPlayerCharacter::AAGDPlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	bAttackAllowed = true;
	bForceRotate = false;
	AttackCombo = 0;

}

void AAGDPlayerCharacter::SetAttackAllowed(bool bAllowAttack)
{
	bAttackAllowed = bAllowAttack;
}

const bool AAGDPlayerCharacter::GetAttackAllowed()
{
	return bAttackAllowed;
}

void AAGDPlayerCharacter::SetForceRotate(bool bShouldRotate)
{
	bForceRotate = bShouldRotate;
}

const bool AAGDPlayerCharacter::GetForceRotate()
{
	return bForceRotate;
}
void AAGDPlayerCharacter::SetAttackCombo(int NewAttackCombo)
{
	AttackCombo = NewAttackCombo;
}

const int AAGDPlayerCharacter::GetAttackCombo()
{
	return AttackCombo;
}

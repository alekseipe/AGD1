// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGDCharacter.h"
#include "AGDPlayerCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class PROJECT_1_API AAGDPlayerCharacter : public AAGDCharacter
{
	GENERATED_BODY()

public:
	AAGDPlayerCharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category="Components");
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category="Components");
	UCameraComponent* CameraComponent;

	//only let the player attack if its true
	bool bAttackAllowed;

	//force rotation to the camera
	bool bForceRotate;

	//the combo of the attack animation
	int AttackCombo;

public:
	/* Set the boolean attack allowed */
	UFUNCTION(BlueprintCallable, Category = Combat)
	void SetAttackAllowed(bool bAllowAttack);

	/* Get the boolean attack allowed */
	UFUNCTION(BlueprintPure, Category = Combat)
	const bool GetAttackAllowed();

	/* Set the boolean force rotate */
	UFUNCTION(BlueprintCallable, Category = Rotation)
	void SetForceRotate(bool bShouldRotate);

	/* Get the boolean force rotate */
	UFUNCTION(BlueprintPure, Category = Rotation)
	const bool GetForceRotate();

	/* Set the INT attack combo */
	UFUNCTION(BlueprintCallable, Category = Combat)
	void SetAttackCombo(int NewAttackCombo);

	/* Get the INT attack combo */
	UFUNCTION(BlueprintPure, Category = Combat)
	const int GetAttackCombo();
};

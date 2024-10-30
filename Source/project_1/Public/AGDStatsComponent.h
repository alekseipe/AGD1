// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AGDStatsComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_1_API UAGDStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAGDStatsComponent();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Health);
	float MaxHealth;

	float Health;

	UPROPERTY(EditDefaultsOnly, Category = Energy);
	float MaxEnergy;

	float Energy;

	UPROPERTY(EditDefaultsOnly, Category = Damage);
	int MinBaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = Damage);
	int MaxBaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Additional Stats");
	float AttackSpeed;

	int CharacterLevel;

	UPROPERTY(EditAnywhere, Category = Level)
	int Experience;

	UPROPERTY(EditDefaultsOnly, Category = Level)
	TArray<int> ExperiencePerLevel;
	
	int GetMaxExperience();

	void HandleLevelUp();

	bool bStatsInitialised;
public:	
	UFUNCTION(BlueprintPure, Category = Health)
	float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable, Category = Health)
	void SetMaxHealth(float NewMax) { MaxHealth = NewMax; }

	UFUNCTION(BlueprintPure, Category = Energy)
	float GetMaxEnergy() const { return MaxEnergy; }

	UFUNCTION(BlueprintCallable, Category = Energy)
	void SetMaxEnergy(float NewMax) { MaxEnergy = NewMax; }

	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, Category = Health)
	void SetHealth(float NewHealth) { Health = NewHealth; }

	UFUNCTION(BlueprintPure, Category = Energy)
	float GetEnergy() const { return Energy; }

	UFUNCTION(BlueprintCallable, Category = Energy)
	void SetEnergy(float NewEnergy) { Energy = NewEnergy; }

	UFUNCTION(BlueprintPure, Category = Damage)
	int GetBaseDamage() const { return FMath::RandRange(MinBaseDamage, MaxBaseDamage); }

	UFUNCTION(BlueprintCallable, Category = Damage)
	void SetBaseDamage(int Min, int Max) { MinBaseDamage = Min; MaxBaseDamage = Max; }

	UFUNCTION(BlueprintPure, Category = "Additional Stats")
	float GetAttackSpeed() const { return AttackSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Additional Stats")
	void SetAttackSpeed(float newAttackSpeed) { AttackSpeed = newAttackSpeed; }
	// Levelling functions
	UFUNCTION(BlueprintCallable, Category = Level)
	void UpdateLevel();

	UFUNCTION(BlueprintCallable, Category = Level)
	void AddExperience(int Amount);

	UFUNCTION(BlueprintImplementableEvent, Category = Level)
	void OnAddExperience(int Amount);

	UFUNCTION(BlueprintCallable, Category = Level)
	void SetExperience(int NewExperience);

	UFUNCTION(BlueprintImplementableEvent, Category = Level)
	void OnLevelUp(int Level, bool bAreStatsInitialised);

	UFUNCTION(BlueprintPure, Category = Level)
	void GetTrueLevelInfo(int& TrueLevel, int& TrueExperience) {
		TrueLevel = CharacterLevel;
		TrueExperience = Experience;
	}

	UFUNCTION(BlueprintPure, Category = Level)
	void GetDisplayLevelInfo(int& DisplayLevel, int& DisplayExperience);

	UFUNCTION(BlueprintPure, Category = Level)
	TArray<int> GetExperiencePerLevel() const { return ExperiencePerLevel; }
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "AGDStatsComponent.h"

// Sets default values for this component's properties
UAGDStatsComponent::UAGDStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxHealth = 100.0f;
	MaxHealth = MaxHealth;
	MaxEnergy = 100.0f;
	Energy = MaxEnergy;

	MinBaseDamage = 1;
	MaxBaseDamage = 3;

	AttackSpeed = 1.0f;

	CharacterLevel = 0;
	Experience = 0;

	// Set experience per level
	for (int i = 1; i < 10; i++) {
		ExperiencePerLevel.Add(i * 1000);
	}
	// ...
}


// Called when the game starts
void UAGDStatsComponent::BeginPlay()
{
	Health = MaxHealth;
	Energy = MaxEnergy;

	Super::BeginPlay();

	UpdateLevel();

	bStatsInitialised = true;
	
}


int UAGDStatsComponent::GetMaxExperience()
{
	int MaxExperience = 0;

	// Add all experience for each level together
	for (int LevelExperience : ExperiencePerLevel) {
		MaxExperience += LevelExperience;
	}

	return MaxExperience;
}


void UAGDStatsComponent::UpdateLevel()
{
	if (CharacterLevel + 1 > ExperiencePerLevel.Num()) {
		return;
	}

	int NewLevel = 0;
	int CollectiveExperience = 0;

	for (int LevelExperience : ExperiencePerLevel) {
		CollectiveExperience += LevelExperience;

		if (Experience < CollectiveExperience) {
			break;
		}

		NewLevel++;

		if (NewLevel > CharacterLevel) {
			HandleLevelUp();
		}
	}

	if (NewLevel != CharacterLevel) {
		CharacterLevel = NewLevel;
	}
}


void UAGDStatsComponent::AddExperience(int Amount)
{
	int NewExperience = FMath::Clamp(Experience + Amount, 0, GetMaxExperience());

	SetExperience(NewExperience);

	OnAddExperience(NewExperience);
}

void UAGDStatsComponent::SetExperience(int NewExperience)
{
	int LocalExperience = FMath::Clamp(NewExperience, 0, GetMaxExperience());

	Experience = LocalExperience;

	UpdateLevel();
}

void UAGDStatsComponent::GetDisplayLevelInfo(int& DisplayLevel, int& DisplayExperience)
{
	DisplayLevel = CharacterLevel + 1;
	DisplayExperience = Experience;
	if (CharacterLevel <= 0) {
		return;
	}
	if (DisplayExperience >= GetMaxExperience()) {
		DisplayExperience = 0;
		return;
	}
	for (int i = 0; i < CharacterLevel; i++) {
		DisplayExperience -= ExperiencePerLevel[i];
	}
}


void UAGDStatsComponent::HandleLevelUp()
{
	SetMaxHealth(MaxHealth * 2);
	SetHealth(MaxHealth);

	SetMaxEnergy(MaxEnergy + 10);
	SetEnergy(MaxEnergy);

	int NewMinDamage = MinBaseDamage + 5;
	int NewMaxDamage = NewMinDamage + (3 + CharacterLevel);

	SetBaseDamage(NewMinDamage, NewMaxDamage);

	SetAttackSpeed(AttackSpeed + 0.1f);

	// Run blueprint event
	OnLevelUp(CharacterLevel, bStatsInitialised);
}

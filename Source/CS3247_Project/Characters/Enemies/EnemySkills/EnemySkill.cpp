// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySkill.h"

TArray<FGameplayEffectDescriptor> UEnemySkill::ToGameplayEffects() const {
	TArray<FGameplayEffectDescriptor> GameplayEffects = {};
	for (auto& Action : Effects) {
		GameplayEffects.Add(Action->ToGameplayEffect());
	}
	
	return GameplayEffects;
}

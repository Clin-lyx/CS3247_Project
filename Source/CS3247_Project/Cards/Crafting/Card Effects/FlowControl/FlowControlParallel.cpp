// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowControlParallel.h"

TArray<TObjectPtr<UCardEffect>> UFlowControlParallel::Combine(UCardEffect* Left, UCardEffect* Right) {
	const double Multiplier = FMath::Max(1 + this->ModifierEffect / 100.0, 0);
	Left->BaseDamage * Multiplier;
	Left->HealAmount * Multiplier;
	for (auto& ExtraDamage : Left->ExtraDamageEffects) {
		Left->ExtraDamageEffects[ExtraDamage.Key] *= Multiplier;
	}

	Right->BaseDamage * Multiplier;
	Right->HealAmount * Multiplier;
	for (auto& ExtraDamage : Right->ExtraDamageEffects) {
		Right->ExtraDamageEffects[ExtraDamage.Key] *= Multiplier;
	}
	
	return {Left, Right};
}

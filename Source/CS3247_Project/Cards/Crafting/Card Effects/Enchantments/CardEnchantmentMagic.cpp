// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentMagic.h"

UCardEffect* UCardEnchantmentMagic::ComposeTo(UCardEffect* Effect) {
	const double ExtraDamageAmount = Effect->BaseDamage.DamageValue * this->Strength / 100.0;
	if (Effect->ExtraDamageEffects.Contains(this->EnchantmentType)) {
		Effect->ExtraDamageEffects[this->EnchantmentType] += ExtraDamageAmount;
	} else {
		const FDamageData Dmg = FDamageData(this->EnchantmentType, ExtraDamageAmount);
		Effect->ExtraDamageEffects.Add(this->EnchantmentType, Dmg);
	}

	return Effect;
}


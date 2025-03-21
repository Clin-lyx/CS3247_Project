// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentComposite.h"

UCardEffect* UCardEnchantmentComposite::ComposeTo(UCardEffect* Effect, double Multiplier) {
	for (auto& Enchantment : this->Enchantments) {
		Effect = Enchantment.Get()->ComposeTo(Effect, Multiplier);	
	}
	
	return Effect;
}


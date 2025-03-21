// Fill out your copyright notice in the Description page of Project Settings.


#include "EnchantNode.h"

TArray<UCardEffect*> UEnchantNode::Build(UCard* OwningCard) {
	TArray<UCardEffect*> SuccessorEffects = this->FirstSuccessor->Build(OwningCard);
	TArray<UCardEffect*> CardEffects = {};
	for (const auto& CardEffect : SuccessorEffects) {
		CardEffects.Add(this->Enchantment.Get()->ComposeTo(CardEffect));
	}
	
	return CardEffects;
}

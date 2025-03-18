// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributeSet.h"

void UPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	switch (Attribute) {
	case Mana:
		NewValue = FMath::Clamp(NewValue, 0.0f, this->GetMaxMana());
		break;
	case MaxMana:
		NewValue = FMath::Max(NewValue, 0.0f);
		break;
	default:
		break;
	}
	
	Super::PreAttributeChange(Attribute, NewValue);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttributeSet.h"

void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	switch (Attribute) {
		case Health:
			NewValue = FMath::Clamp(NewValue, 0.0f, this->GetMaxHealth());
			break;
		case MaxHealth:
			NewValue = FMath::Max(NewValue, 0.0f);
			break;
		case Defence:
			NewValue = FMath::Max(NewValue, 0.0f);
			break;
		default:
			break;
	}

	Super::PreAttributeChange(Attribute, NewValue);
}

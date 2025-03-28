// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttributeSet.h"

void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	TArray<FGameplayAttribute> Attributes = {};
	GetAttributesFromSetClass(this->GetClass(), Attributes);
	const float OldValue = Attributes.FindByKey(Attribute)->GetNumericValue(this);
	float MaxValue = 100.0f;
	if (Attribute == this->GetHealthAttribute()) {
		MaxValue = this->GetMaxHealth();
	} else if (Attribute == this->GetMaxHealthAttribute() || Attribute == this->GetDefenceAttribute()) {
		MaxValue = static_cast<float>(INT32_MAX);
	}

	NewValue = FMath::Clamp(NewValue, 0.0f, MaxValue);
	
	Super::PreAttributeChange(Attribute, NewValue);
	this->OnAttributeChanged.Broadcast(Attribute, OldValue, NewValue);
}

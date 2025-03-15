// Fill out your copyright notice in the Description page of Project Settings.


#include "AtomicCardEffect.h"
void UAtomicCardEffect::ScaleStrength(const double Ratio) {}

FString UAtomicCardEffect::ToString_Implementation() const {
	return this->GetName();
}

FText UAtomicCardEffect::ToText_Implementation() const {
	return FText::FromString(this->ToString());
}

FText UAtomicCardEffect::ToRichText_Implementation() const {
	return this->ToText();
}

void UAtomicCardEffect::OffsetStrength(const double Offset) {}

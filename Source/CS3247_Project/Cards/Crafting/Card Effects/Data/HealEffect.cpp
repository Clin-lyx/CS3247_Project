// Fill out your copyright notice in the Description page of Project Settings.


#include "HealEffect.h"

#include "CS3247_Project/UI/Texts/Text.h"

FString UHealEffect::ToString() const {
	return FString::Printf(TEXT("Effect: heal %lf"), this->HealAmount);
}

FText UHealEffect::ToText() const {
	return FText::FromString(FString::Printf(TEXT("Heals %d HP"), this->GetHealAmount()));
}

FText UHealEffect::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("Heals {0} HP")),
		UText::Green(FString::FromInt(this->GetHealAmount())));
}

UHealEffect* UHealEffect::operator+(const double Offset) const {
	UHealEffect* NewEffect = NewObject<UHealEffect>(this->GetOuter());
	NewEffect->HealAmount = this->HealAmount + Offset;
	return NewEffect;
}

UHealEffect* UHealEffect::operator-(const double Offset) const {
	return *this + (-Offset);
}

UHealEffect* UHealEffect::operator*(const double Factor) const {
	UHealEffect* NewEffect = NewObject<UHealEffect>(this->GetOuter());
	NewEffect->HealAmount = this->HealAmount * Factor;
	return NewEffect;
}

UHealEffect* UHealEffect::operator+=(const double Offset) const {
	return *this + Offset;
}

UHealEffect* UHealEffect::operator-=(const double Offset) const {
	return *this - Offset;
}

UHealEffect* UHealEffect::operator*=(const double Factor) const {
	return *this * Factor;
}

bool UHealEffect::operator==(const int32 Value) const {
	return this->GetHealAmount() == Value;
}

bool UHealEffect::operator!=(const int32 Value) const {
	return this->GetHealAmount() != Value;
}

bool UHealEffect::operator>=(const int32 Value) const {
	return this->GetHealAmount() >= Value;
}

bool UHealEffect::operator<=(const int32 Value) const {
	return this->GetHealAmount() <= Value;
}

bool UHealEffect::operator>(const int32 Value) const {
	return this->GetHealAmount() > Value;
}

bool UHealEffect::operator<(const int32 Value) const {
	return this->GetHealAmount() < Value;
}

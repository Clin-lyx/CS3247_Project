// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageEffect.h"

#include "../../../../UI/Texts/Text.h"

FString UDamageEffect::ToString() const {
	return FString::Printf(TEXT("%s damage: %lf"),
		*this->DamageType.GetTagName().ToString(), this->DamageValue);
}

FText UDamageEffect::ToText() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		this->GetDamageValue(), this->DamageType.ToString());
}

FText UDamageEffect::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		UText::Red(FString::FromInt(this->GetDamageValue())),
		UText::BfIt(this->DamageType.ToString()));
}

UDamageEffect* UDamageEffect::operator+(const double Offset) const {
	UDamageEffect* NewEffect = NewObject<UDamageEffect>();
	NewEffect->DamageType = this->DamageType;
	NewEffect->DamageValue = this->DamageValue + Offset;
	return NewEffect;
}

UDamageEffect* UDamageEffect::operator-(const double Offset) const {
	return *this + (-Offset);
}

UDamageEffect* UDamageEffect::operator*(const double Factor) const {
	UDamageEffect* NewEffect = NewObject<UDamageEffect>();
	NewEffect->DamageType = this->DamageType;
	NewEffect->DamageValue = this->DamageValue * Factor;
	return NewEffect;
}

UDamageEffect* UDamageEffect::operator+=(const double Value) const {
	return *this + Value;
}

UDamageEffect* UDamageEffect::operator-=(const double Value) const {
	return *this - Value;
}

UDamageEffect* UDamageEffect::operator*=(const double Value) const {
	return *this * Value;
}

bool UDamageEffect::operator>(const int32 Value) const {
	return this->GetDamageValue() > Value;
}

bool UDamageEffect::operator<(const int32 Value) const {
	return this->GetDamageValue() < Value;
}

bool UDamageEffect::operator==(const int32 Value) const {
	return this->GetDamageValue() == Value;
}

bool UDamageEffect::operator!=(const int32 Value) const {
	return this->GetDamageValue() != Value;
}

bool UDamageEffect::operator>=(const int32 Value) const {
	return this->GetDamageValue() >= Value;
}

bool UDamageEffect::operator<=(const int32 Value) const {
	return this->GetDamageValue() <= Value;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ManaCostEffect.h"

#include "CS3247_Project/UI/Texts/Text.h"

FString UManaCostEffect::ToString() const {
	return FString::Printf(TEXT("Effect: use %d mana"), this->ManaCost);
}

FText UManaCostEffect::ToText() const {
	return FText::FromString(FString::FromInt(this->ManaCost));
}

FText UManaCostEffect::ToRichText() const {
	return UText::Bf(FString::FromInt(this->ManaCost));
}

UManaCostEffect* UManaCostEffect::operator+(const double Offset) const {
	UManaCostEffect* NewEffect = NewObject<UManaCostEffect>(this->GetOuter());
	NewEffect->ManaCost = this->ManaCost + Offset;
	return NewEffect;
}

UManaCostEffect* UManaCostEffect::operator-(const double Offset) const {
	return *this + (-Offset);
}

UManaCostEffect* UManaCostEffect::operator*(const double Factor) const {
	UManaCostEffect* NewEffect = NewObject<UManaCostEffect>(this->GetOuter());
	NewEffect->ManaCost = this->ManaCost * Factor;
	return NewEffect;
}

UManaCostEffect* UManaCostEffect::operator+=(const double Value) const {
	return *this + Value;
}

UManaCostEffect* UManaCostEffect::operator-=(const double Value) const {
	return *this - Value;
}

UManaCostEffect* UManaCostEffect::operator*=(const double Value) const {
	return *this * Value;
}

bool UManaCostEffect::operator>(const int32 Value) const {
	return this->GetManaCost() > Value;
}

bool UManaCostEffect::operator<(const int32 Value) const {
	return this->GetManaCost() < Value;
}

bool UManaCostEffect::operator==(const int32 Value) const {
	return this->GetManaCost() == Value;
}

bool UManaCostEffect::operator!=(const int32 Value) const {
	return this->GetManaCost() != Value;
}

bool UManaCostEffect::operator>=(const int32 Value) const {
	return this->GetManaCost() >= Value;
}

bool UManaCostEffect::operator<=(const int32 Value) const {
	return this->GetManaCost() <= Value;
}

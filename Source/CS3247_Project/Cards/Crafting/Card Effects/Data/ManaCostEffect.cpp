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

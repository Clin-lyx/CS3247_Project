// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffect.h"

FString UCardEffect::ToString_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Entry.Value->ToString());
	}

	return Sb.Join(Lines, '\n').ToString();
}


FText UCardEffect::ToText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Entry.Value->ToText().ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCardEffect::ToRichText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Entry.Value->ToRichText().ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

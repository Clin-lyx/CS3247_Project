// Fill out your copyright notice in the Description page of Project Settings.


#include "EnchantmentDamageEffect.h"

#include "../../../../UI/Texts/Text.h"

FString UEnchantmentDamageEffect::ToString() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	for (auto& Entry : this->EnchantmentDamages) {
		Sb.Appendf(TEXT("%s enchantment damage: %lf\n"), Entry.Key.GetTagName(), Entry.Value);
	}
	
	return Sb.ToString();	
}

FText UEnchantmentDamageEffect::ToText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->EnchantmentDamages) {
		Lines.Add(FString::Printf(TEXT("%d %s enchantment damage"),
			FMath::CeilToInt32(Entry.Value), *Entry.Key.GetTagName().ToString()));
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}
FText UEnchantmentDamageEffect::ToRichText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->EnchantmentDamages) {
		Lines.Add(FText::Format(FTextFormat::FromString("{0} {1} damage"),
			UText::Red(FString::FromInt(FMath::CeilToInt32(Entry.Value))),
			UText::BfIt(Entry.Key.GetTagName().ToString())).ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

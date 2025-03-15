// Fill out your copyright notice in the Description page of Project Settings.


#include "CardIngredient.h"
#include "../Card Effects/Data/CardEffect.h"
#include "../../../Cards/Card.h"

UCardNode* UCardIngredient::WrapIntoNode(UActorComponent* CardCrafter) {
	return nullptr;
}

FString UCardIngredient::ToString() const {
	return this->Name.ToString();
}

FText UCardIngredient::ToText() const {
	return FText::FromString(this->ToString());
}

FText UCardIngredient::ToRichText() const {
	return this->ToText();
}

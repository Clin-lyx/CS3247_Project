// Fill out your copyright notice in the Description page of Project Settings.


#include "CardIngredient.h"
#include "../Card Effects/Data/CardEffect.h"
#include "../../../Cards/Card.h"

UCardEffect* UCardIngredient::Apply(UCard* OwningCard) {
	return NewObject<UCardEffect>(OwningCard);
}

UCardEffect* UCardIngredient::ComposeTo(UCardEffect* Current) {
	return Current;
}

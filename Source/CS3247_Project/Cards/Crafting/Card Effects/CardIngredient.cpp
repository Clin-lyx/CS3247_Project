// Fill out your copyright notice in the Description page of Project Settings.


#include "CardIngredient.h"
#include "CardEffect.h"

UCardEffect* UCardIngredient::Apply() {
	return NewObject<UCardEffect>();
}

UCardEffect* UCardIngredient::ComposeTo(UCardEffect* Current) {
	return Current;
}

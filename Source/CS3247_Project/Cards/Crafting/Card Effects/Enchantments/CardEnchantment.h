// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3247_Project/UI/Texts/Localisable.h"
#include "CS3247_Project/UI/Texts/Printable.h"
#include "CardEnchantment.generated.h"

class UCardIngredient;

/**
 * An enchantment ingredient for card crafting.
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UCardEnchantment : public UCardIngredient, public IPrintable, public ILocalisable {
	GENERATED_BODY()
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "UObject/Object.h"
#include "ManaCostEffect.generated.h"

/**
 * A card effect to use mana.
 */
UCLASS()
class CS3247_PROJECT_API UManaCostEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UManaCostEffect() : ManaCost(0) {}

	explicit UManaCostEffect(const int Cost) : ManaCost(Cost) {}
	
	UPROPERTY(BlueprintReadOnly)
	int32 ManaCost;

	virtual FString ToString() const override;

	virtual FText ToText() const override;
	
	virtual FText ToRichText() const override;
};

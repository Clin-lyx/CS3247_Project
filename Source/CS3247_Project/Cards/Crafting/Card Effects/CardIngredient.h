// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardIngredient.generated.h"

class UCardEffect;
/**
 * The abstract base class for all card ingredients in crafting.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardIngredient : public UDataAsset {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Desc;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	TSoftObjectPtr<UTexture2D> Icon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	double UseCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 CraftCost;

	/**
	 * Create a new card effect based on the effects of this ingredient.
	 * @return The new effect.
	 */
	virtual UCardEffect* Apply();

	/**
	 * Modify an existing card effect based on the effects of this ingredient.
	 * @param Current The current effect. 
	 * @return The new effect.
	 */
	virtual UCardEffect* ComposeTo(UCardEffect* Current);
};

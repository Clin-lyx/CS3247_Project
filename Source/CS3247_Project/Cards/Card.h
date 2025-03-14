// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.generated.h"

class ILocalisable;
class UCardRecipe;
class UCardEffect;

#define DURABILITY_COEFFICIENT 100.0
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCard : public UObject, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	int Cost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	int Durability;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(ExposeOnSpawn))
	TArray<TObjectPtr<UCardEffect>> Effects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	TObjectPtr<UCardRecipe> Recipe;
	
	UCard();

	UFUNCTION(BlueprintCallable)
	virtual FText GetDescription() const override;

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction = "true"))
	void GetCardInfo(FText& CardName, FText& Desc, int& UseCost, int& CardDurability, TArray<UCardEffect*>& CardEffects) const;

	UFUNCTION(BlueprintCallable, Category = "Card Info")
	FORCEINLINE void GetCardData(int& UseCost, int& CardDurability, TArray<TObjectPtr<UCardEffect>>& CardEffects) const {
		UseCost = this->Cost;
		CardDurability = this->Durability;
		CardEffects = this->Effects;
	}
};

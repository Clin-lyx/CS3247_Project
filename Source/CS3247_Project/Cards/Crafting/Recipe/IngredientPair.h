#pragma once

#include "CoreMinimal.h"
#include "IngredientPair.generated.h"

class UCardIngredient;

USTRUCT(BlueprintType)
struct FIngredientPair {
	GENERATED_BODY()

public:
	FIngredientPair() : First(nullptr), Second(nullptr) {}
	
	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Pair")
	TObjectPtr<UCardIngredient> First;

	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Pair")
	TObjectPtr<UCardIngredient> Second;
};

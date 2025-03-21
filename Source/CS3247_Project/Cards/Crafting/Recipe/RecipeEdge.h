#pragma once

#include "CoreMinimal.h"
#include "RecipeEdge.generated.h"

class UCardIngredient;

USTRUCT(BlueprintType)
struct FRecipeEdge {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Edge")
	TObjectPtr<UCardIngredient> From;

	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Edge")
	TObjectPtr<UCardIngredient> To;
};

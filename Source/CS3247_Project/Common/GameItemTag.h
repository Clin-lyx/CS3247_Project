#pragma once

#include "CoreMinimal.h"
#include "GameItemTag.generated.h"

UENUM(BlueprintType)
enum class EGameItemTag : uint8 {
	CardIngredient UMETA(DisplayName = "Card Ingredient"),
	Resource       UMETA(DisplayName = "Resource"),
	SoulFragment  UMETA(DisplayName = "Soul Fragment")
};
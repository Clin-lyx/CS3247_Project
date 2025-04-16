#pragma once

#include "CoreMinimal.h"
#include "Inventory.generated.h"

class UGameItem;
class UCardIngredient;

USTRUCT(BlueprintType)
struct FInventory {
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<UGameItem*, int32> Items;

	FInventory() : Items({}) {}

	explicit FInventory(TMap<UGameItem*, int32> Items) : Items(Items) {}
};
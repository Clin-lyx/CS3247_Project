#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EnemyAttack.generated.h"

class UCardIngredient;

USTRUCT(BlueprintType)
struct FEnemyAttack {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Category = "GameData.DamageType"))
	FGameplayTag DamageType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Value;
	
	FEnemyAttack() : DamageType(FGameplayTag::RequestGameplayTag(FName("GameData.Damage"))), Value(0) {}
};
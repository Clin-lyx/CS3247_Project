#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectDescriptor.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FGameplayEffectDescriptor {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsReflexive;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> GameplayEffectType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag DataTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag AssetTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Magnitude;
};

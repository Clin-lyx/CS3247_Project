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

	FGameplayEffectDescriptor() : bIsReflexive(false), GameplayEffectType(nullptr), DataTag(FGameplayTag::EmptyTag), AssetTag(FGameplayTag::EmptyTag), Magnitude(0) {}
	FGameplayEffectDescriptor(const bool bCond, const TSubclassOf<UGameplayEffect>& Class, const FGameplayTag GameplayTag, const FGameplayTag DamageType, const int32 Magnitude) :
		bIsReflexive(bCond), GameplayEffectType(Class), DataTag(GameplayTag), AssetTag(DamageType), Magnitude(Magnitude) {};
};

#pragma once

#include "CoreMinimal.h"
#include "../../../GameplayAbilities/GameplayEffectDescriptor.h"
#include "AiDecision.generated.h"

class ABasicCharacter;
class UEnemyAction;

USTRUCT(BlueprintType)
struct FAiDecision {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FGameplayEffectDescriptor> SkillEffects;

	// The target of the action. Use this to check if the skill should be reflexive.
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<ABasicCharacter> Target;
};

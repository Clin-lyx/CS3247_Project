#pragma once

#include "CoreMinimal.h"
#include "AiDecision.generated.h"

class UEnemySkill;
class ABasicCharacter;
class UEnemyAction;

USTRUCT(BlueprintType)
struct FAiDecision {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<UEnemySkill> SkillToUse;

	// The target of the action. Use this to check if the skill should be reflexive.
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<ABasicCharacter> Target;
};

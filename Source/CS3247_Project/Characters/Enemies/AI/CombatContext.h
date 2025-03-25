#pragma once

#include "CoreMinimal.h"
#include "CombatContext.generated.h"

class AEnemyCharacter;
class APlayerCharacter;

USTRUCT(BlueprintType)
struct FCombatContext {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AEnemyCharacter> SelfData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerCharacter> PlayerData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AEnemyCharacter*> Enemies;
};

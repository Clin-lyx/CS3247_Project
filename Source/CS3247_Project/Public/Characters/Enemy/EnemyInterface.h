// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)  // or Blueprintable if you prefer
class CS3247_PROJECT_API UEnemyInterface : public UInterface
{
    GENERATED_BODY()
};

class CS3247_PROJECT_API IEnemyInterface
{
    GENERATED_BODY()

public:
    // Example function signatures that any "enemy" class must implement.

    // Called when the enemy decides on an action (e.g. attack, guard, heal).
    UFUNCTION(BlueprintCallable, Category = "Enemy")
    virtual void DecideAction() = 0;

    // Called when the enemy receives damage.
    UFUNCTION(BlueprintCallable, Category = "Enemy")
    virtual void ReceiveDamage(int32 DamageAmount) = 0;

    // Called when the enemy should die (e.g. health <= 0).
    UFUNCTION(BlueprintCallable, Category = "Enemy")
    virtual void Die() = 0;
};
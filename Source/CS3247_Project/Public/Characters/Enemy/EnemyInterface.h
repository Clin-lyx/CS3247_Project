// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"


class APlayerCharacter;

UINTERFACE()
class CS3247_PROJECT_API UEnemyInterface : public UInterface
{
    GENERATED_BODY()
};

class CS3247_PROJECT_API IEnemyInterface
{
    GENERATED_BODY()

public:
    // Example function signatures that any "enemy" class must implement.

    virtual void DecideAction() = 0;

    virtual void ReceiveDamage(int32 DamageAmount) = 0;

    virtual void SetPlayer(APlayerCharacter* playerCharacter) = 0;

    virtual void Die() = 0;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "CoreMinimal.h"
#include "HealAction.h"
#include "HealAllAction.generated.h"

/**
 * A variant of HealAction that considers *all* allies in AlliesData.
 */
UCLASS()
class CS3247_PROJECT_API UHealAllAction : public UHealAction
{
    GENERATED_BODY()

public:
    UHealAllAction();

    // Evaluate how urgent a "Heal All" is by summing the total missing health among all allies
    virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const override;
};

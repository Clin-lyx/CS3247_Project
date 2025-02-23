﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CardEffect.h"
#include "CardEnchantment.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UCardEnchantment : public UDataAsset {
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual TSoftObjectPtr<UCardEffect> Enchant(TSoftObjectPtr<UCardEffect> Effect);
};

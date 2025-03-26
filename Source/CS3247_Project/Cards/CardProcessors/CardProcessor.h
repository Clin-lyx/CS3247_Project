// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CardProcessor.generated.h"

class UCard;
class ABasicCharacter;
/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class CS3247_PROJECT_API UCardProcessor : public UObject {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ProcessCard(UCard* Card, ABasicCharacter* SourceCharacter, ABasicCharacter* TargetCharacter);
};

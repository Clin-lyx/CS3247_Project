// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerDeckSubsystem.generated.h"

class UCard;
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UPlayerDeckSubsystem : public UGameInstanceSubsystem {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TArray<UCard*> Deck;
	UPROPERTY(BlueprintReadOnly)
	TArray<UCard*> DiscardPile;
	UPROPERTY(BlueprintReadOnly)
	TArray<UCard*> InitialCards;
	UPROPERTY()
	TArray<UCard*> Hand;
};

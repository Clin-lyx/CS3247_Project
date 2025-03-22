// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataManager.h"
#include "Engine/GameInstance.h"
#include "BasicGameInstance.generated.h"

struct FGameplayTag;
/**
 * 
 */
UCLASS(Blueprintable)
class CS3247_PROJECT_API UBasicGameInstance : public UGameInstance, public IDataManager {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, FName> GameplayTagLocalisations;

	UFUNCTION(BlueprintCallable)
	virtual FName GetName_Implementation(const FGameplayTag Tag) const override;
};

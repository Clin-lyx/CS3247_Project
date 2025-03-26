// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "DataManager.h"
#include "Engine/GameInstance.h"
#include "BasicGameInstance.generated.h"

class UGameItem;
struct FGameplayTag;
/**
 * 
 */
UCLASS(Blueprintable)
class CS3247_PROJECT_API UBasicGameInstance : public UGameInstance, public IDataManager {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Localisations")
	TMap<FGameplayTag, FName> GameplayTagLocalisations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Settings")
	TMap<FGameplayAttribute, FGameplayTag> AttributesToTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute Settings")
	TMap<FGameplayTag, FGameplayAttribute> ResistanceTypes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Initial Status")
	TMap<UGameItem*, int32> StartingInventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default Settings")
	int32 DefaultNewCardMaxDurability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default Settings")
	int32 DefaultNewCardMinDurability;

	UFUNCTION(BlueprintCallable)
	virtual FName GetName_Implementation(const FGameplayTag Tag) const override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FGameplayTag AttributeToAssetTag(const FGameplayAttribute Attribute) {
		return this->AttributesToTags[Attribute];
	};
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3247_Project/UI/Texts/Localisable.h"
#include "UObject/Object.h"
#include "CardRecipe.generated.h"

class UCardEffect;
class UDeckComponent;
struct FRecipeEdge;
class UCardIngredient;
class ILocalisable;
class UCard;
class UCardNode;
/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UCardRecipe : public UObject, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UCardNode> Source;

	UFUNCTION(BlueprintCallable)
	UCard* Forge(UDeckComponent* PlayerDeckComponent) const;

	UFUNCTION(BlueprintCallable)
	TArray<FRecipeEdge> ToEdgeList();

	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
	
	bool operator==(const UCardRecipe& Other) const;

	FORCEINLINE bool operator!=(const UCardRecipe& Other) const { return !(*this == Other); }

	friend int32 GetTypeHash(UCardRecipe& Recipe);
private:
	TArray<FRecipeEdge> Edges;
};

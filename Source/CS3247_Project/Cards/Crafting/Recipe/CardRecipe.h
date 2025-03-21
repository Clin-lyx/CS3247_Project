// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CardRecipe.generated.h"

struct FRecipeEdge;
class UCardIngredient;
class ILocalisable;
class UCard;
class UCardNode;
/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UCardRecipe : public UObject {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UCardNode> Source;

	UFUNCTION(BlueprintCallable)
	UCard* Forge(UActorComponent* PlayerDeckComponent) const;

	/**
	 * Retrieve the edges in the recipe. The edges are collected by level-traversal,
	 * so the first edge is guaranteed to be from the source and deeper edges will
	 * appear later in the list.
	 * @return List of edges in the recipe.
	 */
	UFUNCTION(BlueprintCallable)
	TMap<UCardIngredient*, FIngredientPair> ToMap() const;

	bool operator==(const UCardRecipe& Other) const;

	FORCEINLINE bool operator!=(const UCardRecipe& Other) const { return !(*this == Other); }

	friend int32 GetTypeHash(UCardRecipe& Recipe);
	TArray<FRecipeEdge> ToEdgeList();

private:
	TArray<FRecipeEdge> Edges;
};

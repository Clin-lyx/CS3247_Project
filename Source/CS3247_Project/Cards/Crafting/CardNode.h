// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card Effects/CardEffect.h"
#include "Card Effects/CardIngredient.h"
#include "Card Effects/Enchantments/CardEnchantment.h"
#include "Card Effects/Impacts/CardImpact.h"
#include "CS3247_Project/UI/Texts/Localisable.h"
#include "UObject/Object.h"
#include "CardNode.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardNode : public UDataAsset, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	UCardIngredient* Ingredient;

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	FORCEINLINE bool CanInsertNodeAfter() const {
		return this->Ingredient->IsA(UCardEnchantment::StaticClass());
	}

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	FORCEINLINE bool IsTerminal() const {
		return this->FirstSuccessor == nullptr && this->SecondSuccessor == nullptr;
	}

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	bool AddSuccessor(UCardNode* Node, FText& ErrorMsg);

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	bool BreakLinkWith(UCardNode* Node, FText& ErrorMsg);

	UFUNCTION(BlueprintCallable, Category= "Node Connections")
	void BreakAllLinks();

	UFUNCTION(BlueprintCallable)
	TArray<UCardEffect*> Build();

	UFUNCTION(BlueprintCallable)
	virtual FORCEINLINE FText ToText() const override {
		return FText::FromString("[" + this->Ingredient->GetName() + "]");
	}
private:
	UPROPERTY()
	TObjectPtr<UCardNode> Predecessor;

	UPROPERTY()
	TObjectPtr<UCardNode> FirstSuccessor;

	UPROPERTY()
	TObjectPtr<UCardNode> SecondSuccessor;
};

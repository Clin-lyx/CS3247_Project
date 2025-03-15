// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Card Effects/CardIngredient.h"
#include "../../../UI/Texts/Localisable.h"
#include "UObject/Object.h"
#include "CardNode.generated.h"
/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class CS3247_PROJECT_API UCardNode : public UDataAsset, public IPrintable, public ILocalisable {
	GENERATED_BODY()

public:
	FORCEINLINE bool IsTerminal() const {
		return !IsValid(this->FirstSuccessor) && !IsValid(this->SecondSuccessor);
	}

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	bool AddSuccessor(UCardNode* Node, FText& ErrorMsg);

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	bool BreakLinkWith(UCardNode* Node, FText& ErrorMsg);

	UFUNCTION(BlueprintCallable, Category= "Node Connections")
	void BreakAllLinks();
	
	virtual TArray<TObjectPtr<UCardEffect>> Build(UCard* OwningCard);

	virtual FORCEINLINE FString ToString() const override { return TEXT("Card Node"); }
	
	virtual FORCEINLINE FText ToText() const override { return FText::FromString(this->ToString()); }
	
	virtual FORCEINLINE FText ToRichText() const override { return this->ToText(); }
protected:
	UPROPERTY()
	TObjectPtr<UCardNode> Predecessor;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCardNode> FirstSuccessor;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCardNode> SecondSuccessor;
};

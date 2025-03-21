// Fill out your copyright notice in the Description page of Project Settings.


#include "CardRecipe.h"

#include "IngredientPair.h"
#include "../Nodes/CardNode.h"
#include "../../Card.h"

UCard* UCardRecipe::Forge(UActorComponent* PlayerDeckComponent) const {
	UCard* Card = NewObject<UCard>(PlayerDeckComponent);
	Card->Effects = this->Source.Get()->Build(Card);
	return Card;
}

TMap<UCardIngredient*, FIngredientPair> UCardRecipe::ToMap() const {
	TMap<UCardIngredient*, FIngredientPair> Map = {};
	TQueue<UCardNode*> Queue = {};
	Queue.Enqueue(this->Source);
	UCardNode* Curr;
	while (!Queue.Dequeue(Curr)) {
		UCardIngredient* Ingredient = Curr->Unpack();
		if (!Map.Contains(Ingredient)) {
			Map.Add(Ingredient, FIngredientPair());
		}

		for (auto& Successor : Curr->GetSuccessors()) {
			if (!Map[Ingredient].First) {
				Map[Ingredient].First = Successor->Unpack();
			} else if (!Map[Ingredient].Second) {
				Map[Ingredient].Second = Successor->Unpack();
			}

			Queue.Enqueue(Successor);
		}
	}

	return Map;
}

bool UCardRecipe::operator==(const UCardRecipe& Other) const {
	return this->Source == Other.Source;
}

int32 GetTypeHash(UCardRecipe& Recipe) {
	return GetTypeHash(Recipe.Source);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "CardRecipe.h"
#include "../Nodes/CardNode.h"
#include "../../Card.h"

UCard* UCardRecipe::Forge(UActorComponent* PlayerDeckComponent) const {
	UCard* Card = NewObject<UCard>(PlayerDeckComponent);
	Card->Effects = this->Source.Get()->Build(Card);
	return Card;
}

TMap<UCardIngredient*, TArray<UCardIngredient*>> UCardRecipe::ToMap() const {
	TMap<UCardIngredient*, TArray<UCardIngredient*>> Map = {};
	TQueue<UCardNode*> Queue = {};
	Queue.Enqueue(this->Source);
	UCardNode* Curr;
	while (!Queue.Dequeue(Curr)) {
		UCardIngredient* Ingredient = Curr->Unpack();
		if (!Map.Contains(Ingredient)) {
			Map.Add(Ingredient, {});
		}

		for (auto& Successor : Curr->GetSuccessors()) {
			Map[Ingredient].Add(Successor->Unpack());
			Queue.Enqueue(Successor);
		}
	}

	return Map;
}

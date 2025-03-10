// Fill out your copyright notice in the Description page of Project Settings.


#include "CardRecipe.h"
bool UCardRecipe::IsValidRecipe() const {
	return true;
	/*this->Source != nullptr &&
		this->Source->CountBuildableConnectedNodes() == this->Nodes.Num();*/
}

bool UCardRecipe::RemoveNode(UCardNode* Node) {
	if (this->Nodes.Remove(Node)) {
		Node->BreakAllLinks();
		return true;
	}

	return false;
}

UCard* UCardRecipe::Forge() {
	UCard* Card = NewObject<UCard>();
	//Card->Effects = this->Source->GetRoot()->Build();
	for (const auto& Node : this->Nodes) {
		Card->Cost += Node->Ingredient->UseCost;
	}
	
	Card->Name = FText::FromString(TEXT("New Card"));
	return Card;
}

FText UCardRecipe::GetDescription() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	for (const auto& Node : this->Nodes) {
		Sb.Appendf(TEXT("%s "), *Node.Get()->Ingredient->GetName());
	}

	return FText::FromString(Sb.ToString());
}

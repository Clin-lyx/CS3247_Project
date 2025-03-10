// Fill out your copyright notice in the Description page of Project Settings.


#include "CardNode.h"
#include "Card Effects/Enchantments/CardEnchantment.h"

bool UCardNode::AddSuccessor(UCardNode* Node) {
	if (!IsValid(Node)) {
		return false;
	}
	
	// If the node already has a predecessor, cannot link.
	if (IsValid(Node->Predecessor)) {
		return false;
	}

	// If the node is already a successor, cannot re-link.
	if (Node == this->FirstSuccessor || Node == this->SecondSuccessor) {
		return false;
	}

	if (!IsValid(this->FirstSuccessor)) {
		this->FirstSuccessor = Node;
		Node->Predecessor = this;
		return true;
	}

	if (!IsValid(this->SecondSuccessor)) {
		this->SecondSuccessor = Node;
		Node->Predecessor = Node;
		return true;
	}
	
	return false;
}

bool UCardNode::BreakLinkWith(UCardNode* Node) {
	if (!IsValid(Node)) {
		return false;
	}

	if (Node == this->Predecessor) {
		return Node->BreakLinkWith(this);
	}

	if (Node == this->FirstSuccessor && this == Node->Predecessor) {
		this->FirstSuccessor = nullptr;
		Node->Predecessor = nullptr;
		return true;
	}

	if (Node == this->SecondSuccessor && this == Node->Predecessor) {
		this->SecondSuccessor = nullptr;
		Node->Predecessor = nullptr;
		return true;
	}
	
	return false;
}

void UCardNode::BreakAllLinks() {
	if (IsValid(this->Predecessor)) {
		this->Predecessor->BreakLinkWith(this);
	}

	this->FirstSuccessor->BreakLinkWith(this);
	this->SecondSuccessor->BreakLinkWith(this);
}

TArray<UCardEffect*> UCardNode::Build() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Building from ") + this->Ingredient->GetName());
	if (this->IsTerminal()) {
		return {this->Ingredient->Apply()};
	}

	TArray<UCardEffect*> CardEffects = {};
	
	if (this->Ingredient->IsA(UCardEnchantment::StaticClass())) {
		UCardEnchantment* Enchantment = Cast<UCardEnchantment>(this->Ingredient);
		for (const auto& Successor : this->Successors) {
			for (const auto& CardEffect : Successor->Build()) {
				CardEffects.Add(Enchantment->Enchant(CardEffect));
			}
		}
		
		return CardEffects;
	}

	for (const auto& Successor : this->Successors) {
		CardEffects.Append(Successor->Build());
	}
	
	return CardEffects;
}

UCardNode* UCardNode::GetRoot() {
	if (!IsValid(this->Predecessor)) {
		return this;
	}

	return this->Predecessor->GetRoot();
}


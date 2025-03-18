// Fill out your copyright notice in the Description page of Project Settings.


#include "BranchNode.h"

TArray<UCardEffect*> UBranchNode::Build(UCard* OwningCard) {
	TArray<UCardEffect*> CardEffects = this->FirstSuccessor->Build(OwningCard);
	this->Brancher->Merge(CardEffects, this->SecondSuccessor->Build(OwningCard));
	return CardEffects;
}

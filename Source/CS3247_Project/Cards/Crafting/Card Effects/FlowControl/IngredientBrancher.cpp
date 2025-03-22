// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientBrancher.h"

#include "../Data/CardEffect.h"
#include "../../Nodes/BranchNode.h"

UCardNode* UIngredientBrancher::WrapIntoNode(UActorComponent* CardCrafter) {
	UBranchNode* Node = NewObject<UBranchNode>(CardCrafter);
	Node->Brancher = this;
	return Node;
}

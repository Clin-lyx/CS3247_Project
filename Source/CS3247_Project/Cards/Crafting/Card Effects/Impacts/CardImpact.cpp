// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpact.h"

#include "../../Nodes/ImpactNode.h"

UCardEffect* UCardImpact::Apply(UCard* OwningCard) {
	return nullptr;
}

UCardNode* UCardImpact::WrapIntoNode(UActorComponent* CardCrafter) {
	UImpactNode* Node = NewObject<UImpactNode>(CardCrafter);
	Node->Impact= this;
	return Node;
}

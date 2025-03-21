// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCrafterComponent.h"

#include "CS3247_Project/Cards/Crafting/Card Effects/CardIngredient.h"
#include "CS3247_Project/Cards/Crafting/Recipe/RecipeEdge.h"
#include "CS3247_Project/Cards/Crafting/Recipe/IngredientWrappers/IngredientKey.h"


// Sets default values for this component's properties
UCardCrafterComponent::UCardCrafterComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCardCrafterComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}

void UCardCrafterComponent::LoadRecipe(TArray<FRecipeEdge> EdgeList) {
	if (EdgeList.IsEmpty()) {
		return;
	}

	TMap<FIngredientKey, UCardNode*> NodeMap = {};
	for (const auto& Edge : EdgeList) {
		/*UCardIngredient* Parent = Edge.From;
		UCardIngredient* Child = Edge.To;
		this->CurrentRecipe.Ad*/
	}
}

TArray<FRecipeEdge> UCardCrafterComponent::ParseRecipe() {
	return {};
}


// Called every frame
void UCardCrafterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


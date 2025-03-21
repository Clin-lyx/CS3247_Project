// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CardCrafterComponent.generated.h"


struct FRecipeEdge;
class UCardRecipe;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UCardCrafterComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCardCrafterComponent();

protected:
	UPROPERTY()
	TObjectPtr<UCardRecipe> CurrentRecipe;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	void LoadRecipe(TArray<FRecipeEdge> EdgeList);

	TArray<FRecipeEdge> ParseRecipe();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

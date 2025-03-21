// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../../Cards/Card.h"
#include "DeckComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UDeckComponent : public UActorComponent {
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddCardDispatcher, const UCard*, Card);
	
	// Sets default values for this component's properties
	UDeckComponent();

protected:
	UPROPERTY()
	TArray<UCard*> Deck;
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnAddCardDispatcher OnAddCard;
	
	void AddCard(UCard& Card);
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

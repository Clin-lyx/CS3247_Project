// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../../Cards/Card.h"
#include "CS3247_Project/Common/PlayerDeckSubsystem.h"
#include "DeckComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UDeckComponent : public UActorComponent {
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddCardDispatcher, const UCard*, Card);
	
	// Sets default values for this component's properties
	UDeckComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Deck")
	FOnAddCardDispatcher OnAddCard;

	/**
	 * Add a card to the player's deck and broadcast an "OnAddCard" event.
	 * @param Card The new card added.
	 */
	UFUNCTION(BlueprintCallable)
	void AddCard(UCard* Card);

	UFUNCTION(BlueprintCallable)
	UCard* RandomDraw();

	UFUNCTION(BlueprintCallable)
	void Discard(UCard* Card);

	UFUNCTION(BlueprintCallable)
	void Reshuffle(); 
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

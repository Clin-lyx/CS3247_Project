// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckComponent.h"


// Sets default values for this component's properties
UDeckComponent::UDeckComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UDeckComponent::BeginPlay() {
	TArray<UCard*> Cards = this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards;
	for (const auto& Card : this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards) {
		this->OnAddCard.Broadcast(Card);
	}

	Cards = this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck;
	for (const auto& Card : this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck) {
		this->OnAddCard.Broadcast(Card);
	}

	Super::BeginPlay();
}

void UDeckComponent::AddCard(UCard* Card) {
	if (Card->bIsDefault) {
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards.Add(Card);
	} else {
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Add(Card);
	}
	
	this->OnAddCard.Broadcast(Card);
}

UCard* UDeckComponent::RandomDraw() {
	if (this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.IsEmpty()) {
		for (auto& Card : this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->DiscardPile) {
			this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Add(Card);
		}

		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->DiscardPile.Empty();
	}

	if (this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Num() > 0) {
		UCard* Card = this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck[FMath::RandRange(0, this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Num() - 1)];
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Remove(Card);
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Hand.Add(Card);
		return Card;
	}
	
	return this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards[FMath::RandRange(0, this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards.Num() - 1)];
}

void UDeckComponent::Discard(UCard* Card) {
	if (Card->bIsDefault) {
		return;
	}
	
	const int32 Durability = FMath::CeilToInt32(Card->Durability);
	this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Hand.Remove(Card);
	if (Durability > 1) {
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->DiscardPile.Add(Card);
		Card->Durability -= 1;
	}
}

void UDeckComponent::Reshuffle() {
	for (auto& Card : this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->DiscardPile) {
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Add(Card);
	}

	for (auto& Card : this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Hand) {
		if (Card->bIsDefault) {
			continue;
		}

		if (FMath::CeilToInt32(Card->Durability) > 1) {
			this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Add(Card);
		}
	}

	this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Hand.Empty();
	this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->DiscardPile.Empty();
}


// Called every frame
void UDeckComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


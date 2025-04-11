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
	Super::BeginPlay();

	// ...
	
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
		this->Reshuffle();
	}

	if (this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Num() > 0) {
		UCard* Card = this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck[FMath::RandRange(0, this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Num() - 1)];
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->Deck.Remove(Card);
		return Card;
	}
	
	return this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards[FMath::RandRange(0, this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->InitialCards.Num() - 1)];
}

void UDeckComponent::Discard(UCard* Card) {
	if (Card->bIsDefault) {
		return;
	}
	
	const int32 Durability = FMath::CeilToInt32(Card->Durability);
	if (Durability > 1) {
		this->GetOwner()->GetGameInstance()->GetSubsystem<UPlayerDeckSubsystem>()->DiscardPile.Add(Card);
		Card->Durability -= 1;
	}
}


// Called every frame
void UDeckComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


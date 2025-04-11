// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "CS3247_Project/Common/GameItem.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}

int32 UInventoryComponent::RemoveItem(const UGameItem* Item, const int32 Quantity) {
	if (this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory.Contains(Item->ItemType)) {
		if (this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType].Contains(Item)) {
			this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType][Item] -= Quantity;
			const int32 Remaining = this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType][Item];
			if (Remaining <= 0) {
				this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType].Remove(Item);
			}
			
			return Remaining;
		}

		return 0;
	}

	return 0;
}

int32 UInventoryComponent::AddItem(UGameItem* Item, const int32 Quantity) {
	if (this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory.Contains(Item->ItemType)) {
		if (this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType].Contains(Item)) {
			this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType][Item] += Quantity;
			return this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType][Item];
		}

		this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType].Add(Item, Quantity);
		return Quantity;
	}

	this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory.Add(Item->ItemType, {{ Item, Quantity }});
	return Quantity;
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


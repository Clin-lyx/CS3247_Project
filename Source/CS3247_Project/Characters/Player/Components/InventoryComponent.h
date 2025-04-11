// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../../Common/GameItemTag.h"
#include "../../../Common/GameItem.h"
#include "../../../Common/InventorySubsystem.h"
#include "InventoryComponent.generated.h"


class UGameItem;

UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UInventoryComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int32 AddItem(UGameItem* Item, int32 Quantity);

	UFUNCTION(BlueprintCallable)
	int32 RemoveItem(const UGameItem* Item, int32 Quantity);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE TMap<UGameItem*, int32> FetchAllOfType(const EGameItemTag ItemType) const {
		if (!this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory.Contains(ItemType)) {
			return {};
		}
		
		return this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[ItemType];
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool HasEnough(UGameItem* Item, const int32 Quantity) const {
		return this->Count(Item) >= Quantity;
	}
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	FORCEINLINE int32 Count(UGameItem* Item) const {
		if (!this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory.Contains(Item->ItemType)) {
			return 0;
		}
		
		if (!this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType].Contains(Item)) {
			return 0;
		}
		
		return this->GetOwner()->GetGameInstance()->GetSubsystem<UInventorySubsystem>()->Inventory[Item->ItemType][Item];
	}
};

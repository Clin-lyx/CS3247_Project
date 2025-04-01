// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../../Common/GameItemTag.h"
#include "InventoryComponent.generated.h"


class UGameItem;

UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UInventoryComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	TMap<EGameItemTag, TMap<UGameItem*, int32>> Inventory;
	
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int32 AddItem(UGameItem* Item, int32 Quantity);

	UFUNCTION(BlueprintCallable)
	int32 RemoveItem(const UGameItem* Item, int32 Quantity);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE TMap<UGameItem*, int32> FetchAllOfType(const EGameItemTag ItemType) const { return this->Inventory[ItemType]; };
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

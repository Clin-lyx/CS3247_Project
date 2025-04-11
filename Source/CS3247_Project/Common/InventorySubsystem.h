// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameItemTag.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "InventorySubsystem.generated.h"

class UGameItem;
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UInventorySubsystem : public UGameInstanceSubsystem {
	GENERATED_BODY()

public:
	TMap<EGameItemTag, TMap<UGameItem*, int32>> Inventory;
};

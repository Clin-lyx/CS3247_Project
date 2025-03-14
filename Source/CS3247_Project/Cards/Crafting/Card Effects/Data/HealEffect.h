// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "HealEffect.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UHealEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintGetter = GetHealAmount)
	double HealAmount;

	UHealEffect() : HealAmount(0) {}

	FORCEINLINE int32 GetHealAmount() const { return FMath::CeilToInt32(this->HealAmount); }

	virtual FString ToString() const override;
	
	virtual FText ToText() const override;
	
	virtual FText ToRichText() const override;

	UHealEffect* operator+(const double Offset) const;

	UHealEffect* operator-(const double Offset) const;

	UHealEffect* operator*(const double Factor) const;

	UHealEffect* operator+=(const double Offset) const;

	UHealEffect* operator-=(const double Offset) const;

	UHealEffect* operator*=(const double Factor) const;

	bool operator==(const int32 Value) const;

	bool operator!=(const int32 Value) const;

	bool operator>=(const int32 Value) const;

	bool operator<=(const int32 Value) const;

	bool operator>(const int32 Value) const;

	bool operator<(const int32 Value) const;
};

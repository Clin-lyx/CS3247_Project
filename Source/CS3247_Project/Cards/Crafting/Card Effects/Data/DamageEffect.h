// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "DamageEffect.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UDamageEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayTag DamageType;
	
	UPROPERTY(BlueprintGetter = GetDamageValue)
	double DamageValue;
	
	UDamageEffect() : DamageValue(0) {}
	

	FORCEINLINE int32 GetDamageValue() const { return FMath::CeilToInt(DamageValue); }

	virtual FString ToString() const override;

	virtual FText ToText() const override;
	
	virtual FText ToRichText() const override;
	
	UDamageEffect* operator+ (const double Offset) const; 

	UDamageEffect* operator- (const double Offset) const;

	UDamageEffect* operator* (const double Factor) const;

	UDamageEffect* operator+= (const double Value) const;

	UDamageEffect* operator-= (const double Value) const;

	UDamageEffect* operator*= (const double Value) const;

	bool operator> (const int32 Value) const;

	bool operator< (const int32 Value) const;

	bool operator== (const int32 Value) const;

	bool operator!= (const int32 Value) const;

	bool operator>= (const int32 Value) const;

	bool operator<= (const int32 Value) const;
};

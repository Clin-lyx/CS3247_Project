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
	
	UPROPERTY(BlueprintReadOnly)
	double DamageValue;
	
	UDamageEffect() : DamageValue(0) {}
	
	UDamageEffect(const FGameplayTag DamageType, const double DamageValue) :
		DamageType(DamageType), DamageValue(DamageValue) {}
	
	
	UDamageEffect operator+ (const double Offset) const; 

	UDamageEffect operator- (const double Offset) const;

	UDamageEffect operator* (const double Factor) const;

	UDamageEffect operator+= (const double Value) const;

	UDamageEffect operator-= (const double Value) const;

	UDamageEffect operator*= (const double Value) const;

	bool operator> (const int Value) const;

	bool operator< (const int Value) const;

	bool operator== (const int Value) const;

	bool operator!= (const int Value) const;

	bool operator>= (const int Value) const;

	bool operator<= (const int Value) const;
};

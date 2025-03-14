#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EnchantmentDamageData.generated.h"

USTRUCT(BlueprintType)
struct FEnchantmentDamageData {
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayTag DamageType;
	
	UPROPERTY(BlueprintReadOnly)
	double DamageValue;
	
	FEnchantmentDamageData() : DamageValue(0) {}
	
	FEnchantmentDamageData(const FGameplayTag DamageType, const double DamageValue) :
		DamageType(DamageType), DamageValue(DamageValue) {}
	
	FString ToString() const;

	FString ToRichText() const;
	
	FEnchantmentDamageData operator+ (const double Offset) const; 

	FEnchantmentDamageData operator- (const double Offset) const;

	FEnchantmentDamageData operator* (const double Factor) const;

	FEnchantmentDamageData operator+= (const double Value) const;

	FEnchantmentDamageData operator-= (const double Value) const;

	FEnchantmentDamageData operator*= (const double Value) const;

	bool operator> (const int Value) const;

	bool operator< (const int Value) const;

	bool operator== (const int Value) const;

	bool operator!= (const int Value) const;

	bool operator>= (const int Value) const;

	bool operator<= (const int Value) const;
};

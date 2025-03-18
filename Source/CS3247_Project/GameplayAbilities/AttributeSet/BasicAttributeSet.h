// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BasicAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UBasicAttributeSet : public UAttributeSet {
	GENERATED_BODY()

public:
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Defence)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MagicResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, WaterResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, FireResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, AirResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, EarthResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, SliceResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, ProjectileResistance)
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, ExplosionResistance)
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Defence;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData MagicResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData WaterResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData FireResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData AirResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData EarthResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData SliceResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData ProjectileResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes/Resistances")
	FGameplayAttributeData ExplosionResistance;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};

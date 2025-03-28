// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UHealAction.h"
#include "HealAction.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UHealAction : public UHealAction {
	GENERATED_BODY()

public:
	UHealAction();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Amount;
	
	virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const override;
	
	virtual FORCEINLINE bool IsReflexive() const override { return this->bIsReflexive; }

	virtual FORCEINLINE FGameplayEffectDescriptor ToGameplayEffect() const override {
		return FGameplayEffectDescriptor(
			this->IsReflexive(),
			this->GameplayEffectType,
			FGameplayTag::RequestGameplayTag(FName("GameplayEffect.Combat.Healing")),
			FGameplayTag::EmptyTag,
			this->Amount);	
	}
protected:
	// If reflexive, this effect is always applied to the enemy itself regardless of which target it chooses.
	UPROPERTY(EditDefaultsOnly)
	bool bIsReflexive;

};

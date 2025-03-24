// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAction.h"
#include "HealAction.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UHealAction : public UEnemyAction {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Amount;
	
	virtual float Evaluate(const FAiDecisionContext& Context) const override;

	UFUNCTION(BlueprintCallable)
	virtual FORCEINLINE bool IsReflexive() const override { return this->bIsReflexive; }
protected:
	UPROPERTY(EditDefaultsOnly)
	bool bIsReflexive;

};

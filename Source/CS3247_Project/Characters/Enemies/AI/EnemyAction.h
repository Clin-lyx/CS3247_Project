// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyMove.h"
#include "UObject/Object.h"
#include "EnemyAction.generated.h"

struct FUtilityScore;
struct FAiDecisionContext;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, DefaultToInstanced, EditInlineNew)
class CS3247_PROJECT_API UEnemyAction : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	EEnemyMove ActionName;
	
	UEnemyAction() : ActionName(EEnemyMove::Attack), RandomnessAllowance(0.1f) {};

	/**
	 * Evaluate the raw score of the action, normalised to [0, 1].
	 * @param Context An AI decision context containing essential data for decision-making.
	 * @return 
	 */
	virtual float Evaluate(const FAiDecisionContext& Context) const;

	FORCEINLINE virtual bool IsHostile() const { return false; }

	FORCEINLINE virtual bool IsReflexive() const { return false; }
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	FRuntimeFloatCurve EvaluationCurve;

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	float RandomnessAllowance;
};

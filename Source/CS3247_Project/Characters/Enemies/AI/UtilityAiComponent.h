// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UtilityAiComponent.generated.h"


struct FUtilityScore;
class UEnemySkill;
struct FCombatContext;
struct FAiDecision;
class UEnemyAction;
struct FAiDecisionContext;

UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UUtilityAiComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUtilityAiComponent();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true", ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float RandomnessAllowance;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TArray<UEnemySkill*> StrategySpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TMap<TSubclassOf<UEnemyAction>, FRuntimeFloatCurve> EvaluationCurves;
	
	// Called when the game starts
	virtual void BeginPlay() override;

	/**
	 * Evaluate the normalised utility score of an action.
	 * @param Action The skill to use.
	 * @param Context Essential contextual data for decision-making.
	 * @return A normalised utility score.
	 */
	float Evaluate(const UEnemySkill& Action, const FAiDecisionContext& Context) const;

public:
	UFUNCTION(BlueprintCallable)
	FAiDecision Decide(const FCombatContext& Context) const;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAiComponent.h"

#include "AiDecision.h"
#include "AiDecisionContext.h"
#include "CombatContext.h"
#include "../Enemy.h"
#include "../EnemyCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "../EnemySkills/EnemySkill.h"

// Sets default values for this component's properties
UUtilityAiComponent::UUtilityAiComponent(): RandomnessAllowance(0) {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UUtilityAiComponent::BeginPlay() {
	Super::BeginPlay();
	TSet<UEnemySkill*> EnemySkills = Cast<AEnemyCharacter>(this->GetOwner())->EnemyData.Get()->Skills;
	for (auto& Skill : EnemySkills) {
		this->StrategySpace.Add(Skill);
	}
}

float UUtilityAiComponent::Evaluate(const UEnemySkill& Action, const FAiDecisionContext& Context) const {
	const float RandomMultiplier = FMath::RandRange(1.0f - this->RandomnessAllowance, 1.0f + this->RandomnessAllowance);
	float Total = 0.0f;
	float Max = -1.0f;
	for (auto& Effect : Action.Effects) {
		// For each action effect, normalise its raw utility to [0, 1].
		const float EffectRawScore = Effect->Evaluate(Context) * RandomMultiplier;
		const float EffectScore = this->EvaluationCurves[Effect->GetClass()].GetRichCurveConst()->Eval(EffectRawScore);
		Total += EffectScore;
		Max = FMath::Max(Max, EffectScore);
	}

	// Formula suggested by ChatGPT >.<
	return Max + (1.0f - Max) * Total / Action.Effects.Num();
}

FAiDecision UUtilityAiComponent::Decide(const FCombatContext& Context) const {
	AEnemyCharacter* Self = Context.SelfData;
	APlayerCharacter* Player = Context.PlayerData;
	TArray<AEnemyCharacter*> Enemies = Context.Enemies;

	float MaxScore = -1;
	FAiDecision BestDecision;
	// Evaluate each possible skill.
	for (auto& Skill : this->StrategySpace) {
		if (Skill->IsApplicableTo(Self, Player)) {
			// If the skill is meant to attack the player, only consider the player as the target.
			FAiDecisionContext DecisionContext = FAiDecisionContext(Self, Player, Player);
			const float Score = this->Evaluate(*Skill, DecisionContext);
			if (Score > MaxScore) {
				MaxScore = Score;
				BestDecision = FAiDecision(Skill, Player);
			}
		} else {
			// If the skill is meant to be used on allies, consider all allies including the enemy itself.
			for (auto& Enemy : Enemies) {
				if (!Skill->IsApplicableTo(Self, Enemy)) {
					continue;
				}
				
				FAiDecisionContext DecisionContext = FAiDecisionContext(Self, Player, Enemy);
				const float Score = this->Evaluate(*Skill, DecisionContext);
				if (Score > MaxScore) {
					MaxScore = Score;
					BestDecision = FAiDecision(Skill, Enemy);
				}
			}
		}
	}
	
	return BestDecision;
}

// Called every frame
void UUtilityAiComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


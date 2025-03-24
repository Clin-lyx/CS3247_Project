// Fill out your copyright notice in the Description page of Project Settings.


#include "HealAction.h"
#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../../GameplayAbilities/AttributeSet/BasicAttributeSet.h"

float UHealAction::Evaluate(const FAiDecisionContext& Context) const {
	const ABasicCharacter* Target = this->IsReflexive() ? Context.SelfData : Context.TargetData;
	const UBasicAttributeSet* AttributeSet = Cast<UBasicAttributeSet>(
		Target->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	return AttributeSet->GetHealth() / AttributeSet->GetMaxHealth();
}

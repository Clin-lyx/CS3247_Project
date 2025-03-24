// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAction.h"
#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../../GameplayAbilities/AttributeSet/BasicAttributeSet.h"

float UGuardAction::Evaluate(const FAiDecisionContext& Context) const {
	const ABasicCharacter* Target = this->IsReflexive() ? Context.SelfData : Context.TargetData;
	const UBasicAttributeSet* AttributeSet = Cast<UBasicAttributeSet>(
		Target->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	return AttributeSet->GetHealth() / AttributeSet->GetMaxHealth();
}

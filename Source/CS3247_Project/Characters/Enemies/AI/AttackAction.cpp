// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackAction.h"

#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "../../../Common/BasicGameInstance.h"
#include "Kismet/GameplayStatics.h"

float UAttackAction::Evaluate(const FAiDecisionContext& Context) const {
	UBasicGameInstance* GameInstance = Cast<UBasicGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	// You can only attack the player. Otherwise, something wild is happening.
	const ABasicCharacter* Target = Context.TargetData;
	const UAbilitySystemComponent* TargetAbilitySystem = Target->GetAbilitySystemComponent();
	const UBasicAttributeSet* TargetAttributes = Cast<UBasicAttributeSet>(
		Target->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	int32 ActualDamage = this->DamageData.Value;
	if (GameInstance->ResistanceTypes.Contains(this->DamageData.DamageType)) {
		const int32 TargetResistance = TargetAbilitySystem->GetNumericAttribute(
			GameInstance->ResistanceTypes[this->DamageData.DamageType]);
		ActualDamage *= ((100 - TargetResistance) / 100.0);
	}
	
	return ActualDamage / TargetAttributes->GetHealth();
}

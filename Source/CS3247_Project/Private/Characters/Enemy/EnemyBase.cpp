// Fill out your copyright notice in the Description page of Project Settings.


#include "CS3247_Project/Public/Characters/Enemy/EnemyBase.h"
#include "CS3247_Project/Characters/Player/PlayerCharacter.h"
#include "Engine/Engine.h"         
#include "Kismet/GameplayStatics.h" 
#include "Math/UnrealMathUtility.h"

// EnemyBase.cpp

AEnemyBase::AEnemyBase()
{
    CurrentHP = 0;
    MaxHP = 10;
    AttackDamage = 4;

    AvailableActions.Add(EEnemyActions::Attack);
    AvailableActions.Add(EEnemyActions::Guard);
    AvailableActions.Add(EEnemyActions::Heal);

}

void AEnemyBase::BeginPlay()
{
    Super::BeginPlay();

    // Initialize HP at spawn
    CurrentHP = MaxHP;
}

void AEnemyBase::SetPlayer(APlayerCharacter* playerCharacter)
{
    player = playerCharacter;
}

void AEnemyBase::ReceiveDamage(int damage) {
    if (isGuard) {
        isGuard = false;
        damage = damage / 2 + 1;
    }
    CurrentHP -= damage;
    if (CurrentHP <= 0) {
        CurrentHP = 0;
        isDead();
    }
}

void AEnemyBase::isDead() {
    UE_LOG(LogTemp, Log, TEXT("Enemy is dead."));
    Destroy();
}

float AEnemyBase::ScoreAttack() const
{
    float Score = 5.f;
    int playerHealth = player->GetPlayerHealth();
    if (playerHealth < 3 * AttackDamage) {
        Score += 5.f;
        if (playerHealth < AttackDamage) Score += 5.f;
    }

    return Score;
}

float AEnemyBase::ScoreGuard() const
{
    float Score = 2.f;
    if (CurrentHP < MaxHP * 0.4) {
        Score += 10.f;
    }
    return Score;
}

float AEnemyBase::ScoreHeal() const
{
    float healthRatio = (float)CurrentHP / (float)MaxHP;

    return  (1 - healthRatio) * 15;
}

void AEnemyBase::DecideAction()
{
    // If no actions available, bail out
    if (AvailableActions.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No actions available!"));
        return;
    }

    float BestScore = -FLT_MAX;
    EEnemyActions BestAction = EEnemyActions::Attack; // default fallback

    // Compute utility scores for each possible action
    for (EEnemyActions Action : AvailableActions)
    {
        float Score = 0.f;
        switch (Action)
        {
        case EEnemyActions::Attack:
            Score = ScoreAttack();
            break;
        case EEnemyActions::Guard:
            Score = ScoreGuard();
            break;
        case EEnemyActions::Heal:
            Score = ScoreHeal();
            break;
        default:
            break;
        }

        // Track highest
        if (Score > BestScore)
        {
            BestScore = Score;
            BestAction = Action;
        }
    }

    // Execute the best action
    switch (BestAction)
    {
    case EEnemyActions::Attack:
        PerformAttack();
        break;
    case EEnemyActions::Guard:
        PerformGuard();
        break;
    case EEnemyActions::Heal:
        PerformHeal();
        break;
    default:
        break;
    }
}

void AEnemyBase::PerformAttack()
{
    UE_LOG(LogTemp, Log, TEXT("Enemy is ATTACKING!"));
    player->ReceiveDamage(AttackDamage);
    // Apply damage, show animation, etc.
}

void AEnemyBase::PerformGuard()
{
    UE_LOG(LogTemp, Log, TEXT("Enemy is GUARDING!"));
    isGuard = true;
    // Set guard flags, reduce incoming damage next turn, etc.
}

void AEnemyBase::PerformHeal()
{
    UE_LOG(LogTemp, Log, TEXT("Enemy is HEALING!"));
    CurrentHP = FMath::Clamp(CurrentHP + (MaxHP * 0.2f), 0, MaxHP);
    // Possibly remove Heal from AvailableActions if it's a one-time ability
}

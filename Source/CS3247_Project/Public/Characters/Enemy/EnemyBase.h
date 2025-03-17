#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActions.h"
#include "EnemyBase.generated.h"

class APlayerCharacter;

UCLASS()
class CS3247_PROJECT_API AEnemyBase : public AActor
{
    GENERATED_BODY()

public:
    AEnemyBase();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Main function to pick an action via utility scoring
    UFUNCTION(BlueprintCallable, Category = "AI")
    void DecideAction();

    UFUNCTION(BlueprintCallable)
    void SetPlayer(APlayerCharacter* playerCharacter);

    UFUNCTION(BlueprintCallable, Category = "Health")
    void ReceiveDamage(int damage);

    UFUNCTION(BlueprintCallable, Category = "status")
    void isDead();

    UPROPERTY()
    APlayerCharacter* player;

protected:

    // Potential health or other stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int CurrentHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MaxHP;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
    int AttackDamage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
    bool isGuard;

    // Example set of allowed actions
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TArray<EEnemyActions> AvailableActions;

    // Action implementations
    void PerformAttack();
    void PerformGuard();
    void PerformHeal();

    // The utility scoring methods
    float ScoreAttack() const;
    float ScoreGuard() const;
    float ScoreHeal() const;
};

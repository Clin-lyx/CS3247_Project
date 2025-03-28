// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrHP = 0;
	MaxHP = 20;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay() {
	Super::BeginPlay();
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	if (IsValid(AbilitySystem)) {
		this->AttributeSet = AbilitySystem->GetSet<UPlayerAttributeSet>();
	}

	CurrHP = MaxHP;
}

int APlayerCharacter::GetPlayerHealth() const {
	return CurrHP;
}

void APlayerCharacter::ReceiveDamage(int damage) {
	CurrHP -= damage;

	if (CurrHP <= 0) {
		CurrHP = 0;
		PlayerIsDead();
	}
}

void APlayerCharacter::PlayerIsDead() {
	UE_LOG(LogTemp, Log, TEXT("Player is Dead!"));
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::SignalAttributeChange(const FGameplayAttribute& Attribute) const
{
    // Retrieve the player's AbilitySystemComponent.
    const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
    if (!AbilitySystem)
    {
        UE_LOG(LogTemp, Warning, TEXT("AbilitySystemComponent not found on %s"), *GetName());
        return;
    }

    // Retrieve the current value for the attribute.
    bool bFound = false;
    const float CurrentValue = AbilitySystem->GetGameplayAttributeValue(Attribute, bFound);
    if (!bFound)
    {
        UE_LOG(LogTemp, Warning, TEXT("Attribute %s not found on %s"), *Attribute.GetName(), *GetName());
        return;
    }

    // Default max value if we can't determine it.
    float MaxValue = 100.f;

    // Try to cast to your basic attribute set.
    const UBasicAttributeSet* PlayerAttributeSet = Cast<UBasicAttributeSet>(
        AbilitySystem->GetAttributeSet(UBasicAttributeSet::StaticClass()));
    if (PlayerAttributeSet && (Attribute == PlayerAttributeSet->GetHealthAttribute()))
    {
        MaxValue = PlayerAttributeSet->GetMaxHealth();
    }

    // Broadcast the attribute update event.
    OnAttributeUpdated.Broadcast(Attribute, CurrentValue, MaxValue);
}
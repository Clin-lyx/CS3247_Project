// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/BaseCharacter.h"

ABaseCharacter::ABaseCharacter() {
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay() {
	Super::BeginPlay();
}

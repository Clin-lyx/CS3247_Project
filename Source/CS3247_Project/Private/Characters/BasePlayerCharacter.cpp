// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BasePlayerCharacter.h"


// Sets default values
ABasePlayerCharacter::ABasePlayerCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABasePlayerCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


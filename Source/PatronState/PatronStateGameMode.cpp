// Copyright Epic Games, Inc. All Rights Reserved.

#include "PatronStateGameMode.h"
#include "PatronStateCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Enemigo.h"

APatronStateGameMode::APatronStateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APatronStateGameMode::BeginPlay()
{
	Super::BeginPlay();
	dragon = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), FVector(1208, 1610, 700), FRotator::ZeroRotator);
	dragon->InicializarEnemigo(100);
	dragon->Ataque();
	dragon->Moverse();
}

void APatronStateGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	segundos += DeltaTime;
	if (segundos >= 2) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("puntos actuales del dragon: %d"), dragon->GetEnergia()));
	}
}

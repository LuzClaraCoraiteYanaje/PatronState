// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoPatrullando.h"
#include "Enemigo.h"

// Sets default values
AEstadoPatrullando::AEstadoPatrullando()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoPatrullando::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoPatrullando::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoPatrullando::SetEnemigo(AEnemigo* _enemigo)
{
	enemigo = _enemigo;
}

FString AEstadoPatrullando::GetEstado()
{
	return "Patrullando";
}

void AEstadoPatrullando::moverse()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald,
		FString::Printf(TEXT("El enemigo se esta patrullando la zona")));
}

void AEstadoPatrullando::RecuperarEnergia()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald,
		FString::Printf(TEXT("El enemigo se esta esta recuperando")));
}


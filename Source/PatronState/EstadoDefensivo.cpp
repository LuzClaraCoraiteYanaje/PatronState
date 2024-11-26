// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoDefensivo.h"
#include "Enemigo.h"

// Sets default values
AEstadoDefensivo::AEstadoDefensivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoDefensivo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoDefensivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoDefensivo::SetEnemigo(AEnemigo* _enemigo)
{
	enemigo = _enemigo;
}

FString AEstadoDefensivo::GetEstado()
{
	return "Defensivo";
}

void AEstadoDefensivo::moverse()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue,
		FString::Printf(TEXT("El enemigo se esta moviendo en mode defensivo")));
}

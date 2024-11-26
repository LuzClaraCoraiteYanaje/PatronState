// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoPersiguiendo.h"
#include "Enemigo.h"

// Sets default values
AEstadoPersiguiendo::AEstadoPersiguiendo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoPersiguiendo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoPersiguiendo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoPersiguiendo::SetEnemigo(AEnemigo* _enemigo)
{
	enemigo = _enemigo;
}

FString AEstadoPersiguiendo::GetEstado()
{
	return "Persiguiendo";
}

void AEstadoPersiguiendo::atacar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("El enemigo se esta moviendo  en estado persiguiendo")));
}

void AEstadoPersiguiendo::moverse()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("El enemigo se esta  te esta persiguiendo ")));

}


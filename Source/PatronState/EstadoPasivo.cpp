// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoPasivo.h"
#include "Enemigo.h"

// Sets default values
AEstadoPasivo::AEstadoPasivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoPasivo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoPasivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoPasivo::SetEnemigo(AEnemigo* _enemigo)
{
	enemigo = _enemigo;
}

FString AEstadoPasivo::GetEstado()
{
	return "pasivo";
}

void AEstadoPasivo::atacar()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("El dragon esta en estado pasivo por desgaste, no puede atacar")));
	GetWorld()->GetTimerManager().SetTimer(energia, this, &AEstadoPasivo::RecuperarEnergia, 0.5f, true);

}

void AEstadoPasivo::moverse()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("El dragon esta en estado pasivo por desgaste, no puede moverse")));
	GetWorld()->GetTimerManager().SetTimer(energia, this, &AEstadoPasivo::RecuperarEnergia, 0.5f, true);
}

void AEstadoPasivo::RecuperarEnergia()
{
	if (enemigo->GetEnergia() <= 100) {
		enemigo->RecuperarEnergia();
	}
	else {
		GetWorld()->GetTimerManager().ClearTimer(energia);
		enemigo->EstablecerEstado(enemigo->GetEstadoAgresivo());
	}
}





// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoAgresivo.h"
#include  "Enemigo.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Sets default values
AEstadoAgresivo::AEstadoAgresivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void AEstadoAgresivo::BeginPlay()
{
	Super::BeginPlay();
	
	Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	vigilar = true;
	incremento = 6.0f;
	tiempo = 0.0f;
}

// Called every frame
void AEstadoAgresivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tiempo += DeltaTime;
	if (tiempo >= 1) {
		PerderEnergia();
		tiempo = 0;
	}


}

void AEstadoAgresivo::SetEnemigo(AEnemigo* _enemigo)
{
	enemigo = _enemigo;
	PosicionInicial = enemigo->GetActorLocation();
	LimiteInicial = PosicionInicial + FVector(0, 2000, 0);
	LimiteFinal = PosicionInicial + FVector(0, -2000, 0);
}

FString AEstadoAgresivo::GetEstado()
{
	return "Agresivo";
}

void AEstadoAgresivo::atacar()
{
	/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan,
		FString::Printf(TEXT("El enemigo esta en ESTADO AGresivo")));*/

	if (Jugador) {
		FVector Direccion = (Jugador->GetActorLocation() - enemigo->GetActorLocation()).GetSafeNormal();
		FVector Posicion = enemigo->GetActorLocation() + (Direccion * 5.0f);
		enemigo->SetActorLocation(Posicion);
		FRotator Rotacion = Direccion.Rotation();
		Rotacion.Pitch = 0.0f;
		Rotacion.Roll = 0.0f;
		Rotacion.Yaw > 0 ? Rotacion.Yaw = 0 : Rotacion.Yaw = 180;
		enemigo->SetActorRotation(Rotacion);
		GetWorld()->GetTimerManager().SetTimer(ataque, this, &AEstadoAgresivo::atacar, 0.009f, true);
	}
	if (Jugador) {
		FVector JugadorPosicion = Jugador->GetActorLocation();
		FVector PosicionEnemigo = enemigo->GetActorLocation();
		float Distancia = FVector::Dist(PosicionEnemigo, JugadorPosicion);
		if (Distancia > 1500.f) moverse();
	}
}

void AEstadoAgresivo::moverse()
{
	posicionActual = enemigo->GetActorLocation();
	mirar = enemigo->GetActorRotation();
	if (vigilar)
	{
		if (posicionActual.Y <= LimiteInicial.Y) {
			posicionActual.Y += incremento;
			mirar.Yaw = 0;
		}
		else vigilar = false;
	}
	else
	{
		if (posicionActual.Y >= LimiteFinal.Y) {
			posicionActual.Y -= incremento;
			mirar.Yaw = 180;
		}
		else vigilar = true;
	}
	enemigo->SetActorLocation(posicionActual);
	enemigo->SetActorRotation(mirar);
	GetWorld()->GetTimerManager().SetTimer(ataque, this, &AEstadoAgresivo::moverse, 0.001f, true);
	if (Jugador) {
		FVector JugadorPosicion = Jugador->GetActorLocation();
		FVector PosicionEnemigo = enemigo->GetActorLocation();
		float Distancia = FVector::Dist(PosicionEnemigo, JugadorPosicion);
		if (Distancia < 1500.f) atacar();
	}
}

void AEstadoAgresivo::PerderEnergia()
{
	if (enemigo->GetEnergia() >= 10) {
		enemigo->PerderEnergia();
	}
	else {
		GetWorld()->GetTimerManager().ClearTimer(ataque);
		enemigo->EstablecerEstado(enemigo->GetEstadoPasivo());
	}
}

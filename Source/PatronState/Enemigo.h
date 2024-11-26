// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstadoEnemigo.h"
#include "Enemigo.generated.h"

UCLASS()
class PATRONSTATE_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// patron Satate 

private:

	UPROPERTY()
	UStaticMeshComponent* EnemigoMesh;

	IEstadoEnemigo* EstadoPasivo;
	IEstadoEnemigo* EstadoAgresivo;
	IEstadoEnemigo* EstadoDefensivo;
	IEstadoEnemigo* EstadoPatrullando;
	IEstadoEnemigo* EstadoPersiguiendo;

	IEstadoEnemigo* Estado;

	int energia = 0;

	FTimerHandle TimerHandle;
	TArray<IEstadoEnemigo*> Estados; 
	int EstadoIndex;
public:
	void InicializarEnemigo(int _energia);
	void EstablecerEstado(IEstadoEnemigo* _estado);
	void CambiarEstadoSiguiente();
	void Ataque();
	void Moverse();
	FORCEINLINE int GetEnergia() { return energia; }
	FORCEINLINE FString GetEstadoActual() { return "El estado actual del Dragon es " + Estado->GetEstado(); }
	FORCEINLINE IEstadoEnemigo* GetEstadoPasivo() { return EstadoPasivo; }
	FORCEINLINE IEstadoEnemigo* GetEstadoAgresivo() { return EstadoAgresivo; }
	FORCEINLINE IEstadoEnemigo* GetEstadoDefensivo() { return EstadoDefensivo; }
	FORCEINLINE IEstadoEnemigo* GetEstadoPatrullando() { return EstadoPatrullando; }
	FORCEINLINE IEstadoEnemigo* GetEstadoPersiguiendo() { return EstadoPersiguiendo; }
	FORCEINLINE void RecuperarEnergia() { energia += 7; };
	FORCEINLINE void PerderEnergia() { energia -= 2; };

};

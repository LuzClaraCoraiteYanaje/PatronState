// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstadoEnemigo.h"
#include "EstadoPersiguiendo.generated.h"

UCLASS()
class PATRONSTATE_API AEstadoPersiguiendo : public AActor , public IEstadoEnemigo
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoPersiguiendo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	class AEnemigo* enemigo;
public:
	void SetEnemigo(class AEnemigo* _enemigo) override;
	FString GetEstado() override;
	void atacar() override;
	void moverse() override;
	void RecuperarEnergia() override {};
	void PerderEnergia() override {};
};
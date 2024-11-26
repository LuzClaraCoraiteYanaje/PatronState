// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "EstadoAgresivo.h"
#include "EstadoDefensivo.h"
#include "EstadoPasivo.h"
#include "EstadoPatrullando.h"
#include "EstadoPersiguiendo.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemigoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemigoMesh")); 
	RootComponent = EnemigoMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); 
	if (MeshAsset.Succeeded()) { EnemigoMesh->SetStaticMesh(MeshAsset.Object); }
	EnemigoMesh->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	EstadoIndex = 0;
	
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	EstadoPasivo = GetWorld()->SpawnActor<AEstadoPasivo>(AEstadoPasivo::StaticClass());
	EstadoPasivo->SetEnemigo(this);
	EstadoAgresivo = GetWorld()->SpawnActor<AEstadoAgresivo>(AEstadoAgresivo::StaticClass());
	EstadoAgresivo->SetEnemigo(this);
	EstadoDefensivo = GetWorld()->SpawnActor<AEstadoDefensivo>(AEstadoDefensivo::StaticClass());
	EstadoDefensivo->SetEnemigo(this);
	EstadoPatrullando = GetWorld()->SpawnActor<AEstadoPatrullando>(AEstadoPatrullando::StaticClass());
	EstadoPatrullando->SetEnemigo(this);
	EstadoPersiguiendo = GetWorld()->SpawnActor<AEstadoPersiguiendo>(AEstadoPersiguiendo::StaticClass());
	EstadoPersiguiendo->SetEnemigo(this);

	Estados.Add(EstadoPasivo);
	Estados.Add(EstadoAgresivo);
	Estados.Add(EstadoDefensivo);
	Estados.Add(EstadoPatrullando);
	Estados.Add(EstadoPersiguiendo);

	EstablecerEstado(EstadoPasivo);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemigo::CambiarEstadoSiguiente, 5.0f, true);
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemigo::InicializarEnemigo(int _energia)
{
	energia = _energia;
	energia >= 35 ? Estado = EstadoAgresivo : Estado = EstadoPasivo;
}

void AEnemigo::EstablecerEstado(IEstadoEnemigo* _estado)
{
	Estado = _estado;
	Ataque();
	Moverse();
}

void AEnemigo::CambiarEstadoSiguiente()
{
	EstadoIndex = (EstadoIndex + 1) % Estados.Num();
	EstablecerEstado(Estados[EstadoIndex]);
}

void AEnemigo::Ataque()
{
	if (Estado) Estado->atacar();
}

void AEnemigo::Moverse()
{
	if (Estado) Estado->moverse();
}



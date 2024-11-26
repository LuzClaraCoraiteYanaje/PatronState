// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PatronStateGameMode.generated.h"

UCLASS(minimalapi)
class APatronStateGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APatronStateGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float segundos = 0;

	class AEnemigo* dragon;
};




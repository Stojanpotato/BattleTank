// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(EditAnywhere,Category=Setup)
	float AcceptanceRadius = 3000;

	UFUNCTION()
		void OnPossedTankDeath();

	virtual void SetPawn(APawn* InPawn) override;
private:
	
};

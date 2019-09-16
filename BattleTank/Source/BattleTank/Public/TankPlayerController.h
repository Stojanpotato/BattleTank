// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	UFUNCTION(BlueprintCallable,Category=Setup)
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation)const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation)const;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3f;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.0f;
};

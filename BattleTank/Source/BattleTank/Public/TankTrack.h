// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used for moving.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category=Input)
	void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
		float TrackMaxDrivingForce = 40000000;//40k*(100)(i multiply by 100 so that it starts moving) ton tank times (1g)accelertion.
private:
	UTankTrack();

	void DriveTrack(float CurrentThrottle);
	virtual void BeginPlay() override;
	
	TArray < class ASprungWheel* > GetWheels() const;
};

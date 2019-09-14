// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack|| !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendMoveLeft(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity,bool bForceMaxSpeed)
{
	auto TankName = GetOwner() ->GetName();
	auto MoveVelocityToString = MoveVelocity.ToString();
	UE_LOG(LogTemp,Warning,TEXT("%s vectoring to %s"),*TankName,*MoveVelocityToString)
}

void  UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack=LeftTrackToSet;
	RightTrack =RightTrackToSet;

}
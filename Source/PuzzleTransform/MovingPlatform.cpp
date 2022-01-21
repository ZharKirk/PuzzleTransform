// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
	PlatformLocationX = 10.0f;
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		float PlatformLocationY = 0.0f;
		float PlatformLocationZ = 0.0f;
		Location += FVector(PlatformLocationX * DeltaTime, PlatformLocationY, PlatformLocationZ);
		SetActorLocation(Location);
	}
}
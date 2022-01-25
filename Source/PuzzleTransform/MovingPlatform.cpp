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

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		float PlatformLocationY = 0.0f;
		float PlatformLocationZ = 0.0f;

		FVector Location = GetActorLocation();

		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();

		if (JourneyTravelled >= JourneyLength)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += PlatformLocationX * DeltaTime * Direction;
		SetActorLocation(Location);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//emMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	//ItemMeshComp->SetSimulatePhysics(true);
	//ItemMeshComp->SetupAttachment(RootComponent);
	//RootComponent = ItemMeshComp;


}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


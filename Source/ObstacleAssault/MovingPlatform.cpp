// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString Name = GetName();

	// UE_LOG(LogTemp, Display, TEXT("Begin Play: %s"), *Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move platform forwards
		// Get current location and name
	FVector CurrentLocation = GetActorLocation();
	FString PlatformName = GetName();
		// Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set the location
	SetActorLocation(CurrentLocation);
	// Send Platform back if gone too far
		// Check how far we've moved
	float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);
		// Reverse direction of motion if gone too far
	if (DistanceMoved > MoveDistance)  
	{
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("%s overshot by %f"), *PlatformName, OverShoot)

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}


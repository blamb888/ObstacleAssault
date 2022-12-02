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

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FString PlatformName = GetName();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
	float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);
	if (DistanceMoved > MoveDistance)  
	{
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("%s overshot by %f"), *PlatformName, OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FString PlatformName = GetName();

	UE_LOG(LogTemp, Display, TEXT("%s rotating!"), *GetName());
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Door.h"

// Sets default values
ACPP_Door::ACPP_Door()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACPP_Door::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ShouldOpenOrClose) {
		FRotator CurrentRotation = GetActorRotation();
		FRotator NewRotation;
		NewRotation.Roll = CurrentRotation.Roll;
		NewRotation.Pitch = CurrentRotation.Pitch;
		NewRotation.Yaw = CurrentRotation.Yaw + YawIncreament;
		SetActorRotation(NewRotation);
		if ( (YawIncreament > 0 && NewRotation.Yaw >= 90) || (YawIncreament < 0 && NewRotation.Yaw <=0 )) {
			
			ShouldOpenOrClose = false;
		}
	}
}

void ACPP_Door::OpenDoor() {
	if (GetActorRotation().Yaw < 90){
		YawIncreament = 2.0f;
		ShouldOpenOrClose = true;
	}
}

void ACPP_Door::CloseDoor() {
	if (GetActorRotation().Yaw >0) {
		YawIncreament = -2.0f;
		ShouldOpenOrClose = true;
	}
}
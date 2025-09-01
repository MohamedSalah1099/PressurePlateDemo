// Fill out your copyright notice in the Description page of Project Settings.


#include "CppPressurePlate.h"
#include "Components/SphereComponent.h"
#include "PressurePlateDemoCharacter.h"


// Sets default values
ACppPressurePlate::ACppPressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	PlateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlateMesh"));
	PlateMesh->SetupAttachment(RootComponent);

	    // Replace the incomplete line with the correct function call for creating a USphereComponent
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(PlateMesh);
	SphereCollision->SetSphereRadius(100.0f);

			
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ACppPressurePlate::OnPressurePlatePressed);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &ACppPressurePlate::OnPressurePlateReleased);
}

// Called when the game starts or when spawned
void ACppPressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppPressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void  ACppPressurePlate::OnPressurePlatePressed_Implementation(UPrimitiveComponent* OverLappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult) {

	if (OtherActor->IsA(APressurePlateDemoCharacter::StaticClass()) && DoorRef) {
	
		DoorRef->OpenDoor();
		PlateMesh->SetMaterial(0, PressedPlateMeshMaterial);
	}


}

void ACppPressurePlate::OnPressurePlateReleased_Implementation(UPrimitiveComponent* OverLappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {


	if (OtherActor->IsA(APressurePlateDemoCharacter::StaticClass()) && DoorRef) {

		DoorRef->CloseDoor();
		PlateMesh->SetMaterial(0, DefaultPlateMeshMaterial);
	}


}
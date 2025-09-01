// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Door.generated.h"

UCLASS()
class PRESSUREPLATEDEMO_API ACPP_Door : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Door();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* DoorMesh;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool ShouldOpenOrClose;
	float YawIncreament;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category= "Actions")
	void OpenDoor();

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void CloseDoor();
};

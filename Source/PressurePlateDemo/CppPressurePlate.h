

#pragma once

#include "CoreMinimal.h"
#include "CPP_Door.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CppPressurePlate.generated.h"


UCLASS()
class PRESSUREPLATEDEMO_API ACppPressurePlate : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACppPressurePlate();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlateMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereCollision;

	UPROPERTY(EditAnywhere, BluePrintReadWrite , Category = "Materials")
	UMaterialInterface* DefaultPlateMeshMaterial;


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Materials")
	UMaterialInterface* PressedPlateMeshMaterial;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent)
	void OnPressurePlatePressed(UPrimitiveComponent* OverLappedComp, AActor* OtherActor,
							UPrimitiveComponent* OtherComp , int32 OtherBodyIndex,
							bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintNativeEvent)
	void OnPressurePlateReleased(UPrimitiveComponent* OverLappedComp, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Config")
	ACPP_Door* DoorRef;
};

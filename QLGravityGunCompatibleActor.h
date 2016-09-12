//----------------------------------------
// Quarter Life
//
// MIT license
//
//  (\-/)
// (='.'=)
// (")-(")o
//----------------------------------------

// terminology: gravity gun compatible actor refers to the object
// that can be attracted and repulsed by the gravity gun

#pragma once

#include "QLUtility.h"
#include "GameFramework/Actor.h"
#include "QLGravityGunCompatibleActor.generated.h"

// constant
const float defaultLinearDamping = 1.0f;
const float defaultAngularDamping = 0.5f;
const float defaultBoxComponentDim = 80.0f;

UCLASS()
class QL_API AQLGravityGunCompatibleActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AQLGravityGunCompatibleActor();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity gun compatible actor")
    UBoxComponent* BoxComponent;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity gun compatible actor")
     UStaticMeshComponent* StaticMeshComponent;
};

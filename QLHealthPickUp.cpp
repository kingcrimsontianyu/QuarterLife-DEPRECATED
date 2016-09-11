// Fill out your copyright notice in the Description page of Project Settings.

#include "QL.h"
#include "QLHealthPickUp.h"

//------------------------------------------------------------
// Sets default values
//------------------------------------------------------------
AQLHealthPickUp::AQLHealthPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = BoxComponent;
    BoxComponent->InitBoxExtent(FVector(200.0f, 200.0f, 200.0f));
    BoxComponent->SetSimulatePhysics(false);
    BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

    // built-in dynamic delegate
    //BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AQLHealthPickUp::OnOverlapBeginForComp);
    this->OnActorBeginOverlap.AddDynamic(this, &AQLHealthPickUp::OnOverlapBeginForActor);
}

//------------------------------------------------------------
// Called when the game starts or when spawned
//------------------------------------------------------------
void AQLHealthPickUp::BeginPlay()
{
	Super::BeginPlay();
}

//------------------------------------------------------------
// Called every frame
//------------------------------------------------------------
void AQLHealthPickUp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

//------------------------------------------------------------
//------------------------------------------------------------
void AQLHealthPickUp::OnOverlapBeginForComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

//------------------------------------------------------------
//------------------------------------------------------------
void AQLHealthPickUp::OnOverlapBeginForActor(AActor* OverlappedActor, AActor* OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString(TEXT("overlap actor")));
    this->Destroy();
}
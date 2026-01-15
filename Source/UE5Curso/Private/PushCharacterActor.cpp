// Fill out your copyright notice in the Description page of Project Settings.


#include "PushCharacterActor.h"
#include "components/BoxComponent.h"
#include "GameFramework/Character.h"

// Sets default values
APushCharacterActor::APushCharacterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

}

// Called when the game starts or when spawned
void APushCharacterActor::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddUniqueDynamic(this,&APushCharacterActor::BeginOverlap);
	BoxComponent->OnComponentEndOverlap.AddUniqueDynamic(this,&APushCharacterActor::EndOverlap);
}

void APushCharacterActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Green,TEXT("Overlap Overlap"));

	ACharacter* character = Cast<ACharacter>(OtherActor);

	if(!IsValid(character)) return;

	character->LaunchCharacter(-OtherActor->GetActorForwardVector()*ForzeImpulse,true,false);
}

void APushCharacterActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Blue,TEXT("Exit Exit"));
}

// Called every frame
/*void APushCharacterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/


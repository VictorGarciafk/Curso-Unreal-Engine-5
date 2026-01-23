
#include "Actors/PushCharacterActor.h"
#include "components/BoxComponent.h"
#include "Components/HealthComponent.h"
#include "GameFramework/Character.h"

// Sets default values
APushCharacterActor::APushCharacterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RootComponent = BoxComponent;
	
	//hacemoos que nuestro boxcomponent ignore todo lo que colisione con el a excepcion de los Pawn que lo pondra en overlap
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

//funcion para cuando el boxComponent detecte algun actor entrar
void APushCharacterActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//imprime unn texto en la consola
	GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Green,TEXT("Overlap Overlap"));

	//iniciamos una variable del jugador usando el cast en OtherActor
	ACharacter* character = Cast<ACharacter>(OtherActor);
	if(!IsValid(character)) return;

	//si se detecta a un actor haciend overlap sera empujadoo a la direccion contraria
	character->LaunchCharacter(-OtherActor->GetActorForwardVector()*ForzeImpulse,true,false);
	UHealthComponent* PlayerHealthComponent = character->FindComponentByClass<UHealthComponent>();
	int restHealt = -50;
	PlayerHealthComponent->updateCurrentHealth(restHealt);
}

//funcion para cuando el boxComponent detecte algun actor salir
void APushCharacterActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Blue,TEXT("Exit Exit"));
}
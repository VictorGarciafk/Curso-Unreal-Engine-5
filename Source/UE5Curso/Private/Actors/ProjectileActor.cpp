
#include "Actors/ProjectileActor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if(!PCollisionComp)
	{
		//utilizamos una esfera como forma de colision del objeto
		PCollisionComp = CreateDefaultSubobject<USphereComponent>("PCollisionComp");

		//asignamos un radio a la colision de la esfera
		PCollisionComp->InitSphereRadius(15.0f);

		//asignamos el preset de colision creado en unreal engine
		PCollisionComp->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));

		//evita que se pueda caminar sobre encima del projectile
		PCollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable,0.0f));
		PCollisionComp->CanCharacterStepUpOn = ECB_No;
		
		RootComponent = PCollisionComp;
	}

	if (!PMeshComp)
	{
		PMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("PMeshComp");
		PMeshComp->SetCollisionProfileName("NoCollision");
		PMeshComp->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		PMeshComp->SetupAttachment(RootComponent);
		
	}

	if (!PMovementComp)
	{
		PMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("PMovementComp");
		
		//le asignamos las fisicas al componente de PCollisionComp
		PMovementComp->UpdatedComponent = PCollisionComp;
		PMovementComp->InitialSpeed = 3000.0f;
		PMovementComp->MaxSpeed = 3000.0f;
		PMovementComp->ProjectileGravityScale = 1.0f;
	}
	
	// borramos el proyectil despues de 3 segundos
	InitialLifeSpan = 3.0f;
}


// Called when the game starts or when spawned 
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	PCollisionComp->OnComponentHit.AddDynamic(this,&AProjectileActor::OnHit);
}

void AProjectileActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine ->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,FString::Printf(TEXT("OtherActor: %s"),*OtherActor->GetName()));
	Destroy();
}




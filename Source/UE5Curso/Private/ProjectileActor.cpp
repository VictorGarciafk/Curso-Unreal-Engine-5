


#include "ProjectileActor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if(!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}

	if(!ProjectileCollisionComponent)
	{
		//utilizamos una esfera como forma de colision del objeto
		ProjectileCollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");

		//asignamos un nombre a la esfera de colision 
		ProjectileCollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));

		//asignamos un radio a la colision de la esfera
		ProjectileCollisionComponent->InitSphereRadius(15.0f);

		//llama al evento OnProjectHit cuando el objeto colisiona
		ProjectileCollisionComponent->OnComponentHit.AddUniqueDynamic(this, &AProjectileActor::OnProjectHit);
		
		RootComponent = ProjectileCollisionComponent;
		
	}

	if (!ProjectileMovementComponent)
	{
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
		//ProjectileMovementComponent->SetUpdatedComponent(ProjectileCollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		//ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.6f;
		ProjectileMovementComponent->ProjectileGravityScale = 1.0f;
		
	}

    if (!ProjectileMeshComponent)
    {
    	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMeshComponent");

    	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Sphere.Sphere'"));
	    if (Mesh.Succeeded())
	    {
	    	ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
	    }

    	static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/SphereMaterial.SphereMaterial'"));
    	if (Material.Succeeded())
    	{
    		ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
    	}
    	ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);

    	ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
    	SetRootComponent(ProjectileMeshComponent);
    	ProjectileMeshComponent->SetCollisionProfileName("BlockAll");
    }
	
	// borramos el proyectil despues de 3 segundos
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned 
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
}

/*void AProjectileActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ProjectileCollisionComponent->OnComponentHit.RemoveAll(this);
}*/

void AProjectileActor::OnProjectHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
	
	Destroy();
}




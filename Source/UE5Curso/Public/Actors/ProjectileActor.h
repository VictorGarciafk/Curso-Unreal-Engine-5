#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileActor.generated.h"

UCLASS()
class UE5CURSO_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();

protected:
	
	UPROPERTY(EditDefaultsOnly, Category = Components)
	USphereComponent* PCollisionComp;
	
	UPROPERTY(EditDefaultsOnly, Category = Components)
	UStaticMeshComponent* PMeshComp;

	UPROPERTY(EditDefaultsOnly, Category = Components)
	UProjectileMovementComponent* PMovementComp;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);
};

#include "Components/GunComponent.h"

UGunComponent::UGunComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UGunComponent::Fire(USceneComponent* PosFireComponent)
{
	FHitResult Hit;
	FVector StartLocation = PosFireComponent->GetComponentLocation();
	FVector EndLocation = StartLocation + (PosFireComponent->GetForwardVector() * MaxDistance);
	FCollisionQueryParams CollisionParams;

	//Dibuja una linea azul de la direccion del proyectil
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, false, 2.0f);

	if (GetWorld()->LineTraceSingleByChannel(Hit,StartLocation,EndLocation,ECC_Visibility,CollisionParams)){
		if (Hit.bBlockingHit){
			//Imprime al actor que golpea el rayo y las coordenadas del impacto
			GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Red,FString::Printf(TEXT("Hitting Actor: %s, "
			 "Impact Point %s, Impact Normal: %s"),
				*Hit.GetActor()->GetName(),
				*Hit.ImpactPoint.ToString(),
				*Hit.Normal.ToString()));
		}
	}
}
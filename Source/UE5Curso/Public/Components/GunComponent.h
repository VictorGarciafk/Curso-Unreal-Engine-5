#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GunComponent.generated.h"

UCLASS()
class UE5CURSO_API UGunComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UGunComponent();

	void Fire(USceneComponent* PosFireComponent);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float MaxDistance = 1000.0f;
};

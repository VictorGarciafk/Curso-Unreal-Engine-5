#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateHealth, int32, CurrentHealth);

class UPlayerWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5CURSO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	FOnUpdateHealth OnUpdateHealth;
	
	// Sets default values for this component's properties
	UHealthComponent();

	int32 getCurrentHealth() const { return CurrentHealth; }
	bool isDead() const { return CurrentHealth <= 0; }
	
	void updateCurrentHealth(int32 AmountHealth);

	void death();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = Settings)
	int32 MaxHealth = 100;
	int32 CurrentHealth = 0;

	virtual void BeginPlay() override;
};

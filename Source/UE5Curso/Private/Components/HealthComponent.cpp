#include "Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::updateCurrentHealth(int32 AmountHealth)
{
	CurrentHealth += AmountHealth;

	/*CurrentHealth = (CurrentHealth > MaxHealth) ? MaxHealth : CurrentHealth;
	CurrentHealth = (CurrentHealth < 0) ? 0 : CurrentHealth;*/
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);

	if (CurrentHealth <= 0){
		death();
	}
	OnUpdateHealth.Broadcast(CurrentHealth);
}

void UHealthComponent::death()
{
	GEngine->AddOnScreenDebugMessage(-1,10.0f, FColor::Red, TEXT("Player is dead"));
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	updateCurrentHealth(MaxHealth);
}
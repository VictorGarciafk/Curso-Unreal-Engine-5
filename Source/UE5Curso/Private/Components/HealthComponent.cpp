//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-Aviso-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Esta clase solo es para comprender el uso de los componentes, no sera utilizado para el producto final
#include "Components/HealthComponent.h"
#include "UI/PlayerWidget.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UHealthComponent::updateCurrentHealth(int32 AmountHealth)
{
	CurrentHealth += AmountHealth;

	/*CurrentHealth = (CurrentHealth > MaxHealth) ? MaxHealth : CurrentHealth;
	CurrentHealth = (CurrentHealth < 0) ? 0 : CurrentHealth;*/
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);

	if (CurrentHealth <= 0)
	{
		death();
	}
	if (!IsValid(PlayerWidget)) return;
	PlayerWidget->UpdateHealthText(CurrentHealth);
}

void UHealthComponent::death()
{
	GEngine->AddOnScreenDebugMessage(-1,10.0f, FColor::Red, TEXT("Player is dead"));
}

void UHealthComponent::setPlayerWidget(UPlayerWidget* NewPlayerWidget)
{
	PlayerWidget = NewPlayerWidget;
	updateCurrentHealth(MaxHealth);
}

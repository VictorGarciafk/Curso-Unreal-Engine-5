//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-Aviso-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Esta clase solo es para comprender el uso de los componentes, no sera utilizado para el producto final
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


class UPlayerWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5CURSO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	int32 getCurrentHealth() const { return CurrentHealth; }
	bool isDead() const { return CurrentHealth <= 0; }
	
	void updateCurrentHealth(int32 AmountHealth);

	void death();

	void setPlayerWidget(UPlayerWidget* NewPlayerWidget);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = Settings)
	int32 MaxHealth = 100;
	int32 CurrentHealth = 0;

	UPROPERTY()
	UPlayerWidget* PlayerWidget;
};

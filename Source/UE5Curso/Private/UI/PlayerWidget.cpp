// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/PlayerWidget.h"
#include "Components/HealthComponent.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UPlayerWidget::HandleUpdateHealth()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HandleUpdateHealth"));
}

void UPlayerWidget::NativeOnInitialized()
{
	//Esto funciona como si fuera el beginPlay del widget
	Super::NativeOnInitialized();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if (!IsValid(PlayerPawn)) return;

	UHealthComponent* HealthComp = PlayerPawn->FindComponentByClass<UHealthComponent>();
	if (!IsValid(HealthComp)) return;

	//añadimos al Delegate de forma unica la funcion de UpdateHealthText
	HealthComp->OnUpdateHealth.AddUniqueDynamic(this, &UPlayerWidget::UpdateHealthText);
}

void UPlayerWidget::UpdateHealthText(int32 CurrentHealth)
{
	FString StCurrentHealth = FString::FromInt(CurrentHealth);
	FText TxtCurrentHealth = FText::FromString(StCurrentHealth);

	//Same
	//PlayerHealthText->SetText(FText::FromString(FString::FromInt(CurrentHealth)));
	PlayerHealthText->SetText(TxtCurrentHealth);
}

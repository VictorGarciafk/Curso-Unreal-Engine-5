// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameHUD.h"
#include "UI/PlayerWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/HealthComponent.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(PlayerWidgetClass)) return;

	UPlayerWidget* PlayerWidget = CreateWidget<UPlayerWidget>(GetWorld(), PlayerWidgetClass);
	PlayerWidget->AddToViewport();

	//PlayerWidget->UpdateHealthText(100);
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (!IsValid(Pawn)) return ;

	UHealthComponent* HealthComponent = Pawn->FindComponentByClass<UHealthComponent>();
	
	if (!IsValid(HealthComponent)) return ;

	HealthComponent->setPlayerWidget(PlayerWidget);
}

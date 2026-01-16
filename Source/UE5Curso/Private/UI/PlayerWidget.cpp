// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerWidget.h"
#include "Components/TextBlock.h"

void UPlayerWidget::UpdateHealthText(int32 CurrentHealth)
{
	FString StCurrentHealth = FString::FromInt(CurrentHealth);
	FText TxtCurrentHealth = FText::FromString(StCurrentHealth);

	//Same
	//PlayerHealthText->SetText(FText::FromString(FString::FromInt(CurrentHealth)));
	PlayerHealthText->SetText(TxtCurrentHealth);
}

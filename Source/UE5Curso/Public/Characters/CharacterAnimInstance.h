#pragma once

#include "CoreMinimal.h"
#include "Player01.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class UCharacterMovementComponent;

UCLASS()
class UE5CURSO_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	protected:
		UPROPERTY()
		UCharacterMovementComponent* CharacterMovementComponent;

		UPROPERTY()
		APlayer01* Player01;

		UPROPERTY(BlueprintReadOnly)
		bool bShouldBeMove = false;

		UPROPERTY(BlueprintReadOnly)
		bool bIsFalling = false;

		UPROPERTY(BlueprintReadOnly)
		float Velocity;
	
		UPROPERTY(BlueprintReadOnly)
		float ZVelocity;

		UPROPERTY(BlueprintReadOnly)
		float XRotator;

		virtual void NativeBeginPlay() override;
		virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};

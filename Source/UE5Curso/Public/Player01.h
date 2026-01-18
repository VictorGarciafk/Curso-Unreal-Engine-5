#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player01.generated.h"

struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AProjectileActor;
class UHealthComponent;

UCLASS()
class UE5CURSO_API APlayer01 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayer01();

protected:

	UPROPERTY(EditDefaultsOnly, Category = Components)
	USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = Components)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category = Components)
	USceneComponent* FireSceneComponent;

	UPROPERTY(EditDefaultsOnly, Category = Components)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* FireAction;

	UPROPERTY(EditDefaultsOnly, Category = ProjectileConfig)
	TSubclassOf<AProjectileActor> ProjectileActorClass;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);

	UFUNCTION()
	void Fire();
public:	

	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};

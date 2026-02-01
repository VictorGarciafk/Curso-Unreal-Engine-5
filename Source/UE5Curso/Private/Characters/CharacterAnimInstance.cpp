
#include "Characters/CharacterAnimInstance.h"

#include "Camera/CameraComponent.h"
#include "Characters/Player01.h"
#include "GameFramework/CharacterMovementComponent.h"


void UCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	
	if (!IsValid(TryGetPawnOwner())) return;
	CharacterMovementComponent = TryGetPawnOwner()->GetComponentByClass<UCharacterMovementComponent>();

	Player01 = Cast<APlayer01>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (!IsValid(CharacterMovementComponent) || !IsValid(Player01)) return;
	const FVector CharacterVelocity = CharacterMovementComponent->Velocity;
	Velocity = CharacterVelocity.Size2D();
	bShouldBeMove = Velocity > 0;

	ZVelocity = CharacterVelocity.Z;
	bIsFalling = CharacterMovementComponent->IsFalling();

	XRotator = -Player01->GetThirdCameraComponent()->GetComponentRotation().Pitch;	
}
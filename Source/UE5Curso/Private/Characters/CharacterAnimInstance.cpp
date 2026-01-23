
#include "Characters/CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	if (!IsValid(TryGetPawnOwner())) return;
	CharacterMovementComponent = TryGetPawnOwner()->GetComponentByClass<UCharacterMovementComponent>();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (!IsValid(CharacterMovementComponent)) return;
	const FVector CharacterVelocity = CharacterMovementComponent->Velocity;
	Velocity = CharacterVelocity.Size2D();
	bShouldBeMove = Velocity > 0;

	ZVelocity = CharacterVelocity.Z;
	bIsFalling = CharacterMovementComponent->IsFalling();
}
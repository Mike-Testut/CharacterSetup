// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimInstance.h"

#include "Characters/ThirdPersonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UThirdPersonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	ThirdPersonCharacter = Cast<AThirdPersonCharacter>(TryGetPawnOwner());
	if(ThirdPersonCharacter)
	{
		ThirdPersonMoveComponent = ThirdPersonCharacter->GetCharacterMovement();
	}
}

void UThirdPersonAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(ThirdPersonMoveComponent)
	{
		
		GroundSpeed = UKismetMathLibrary::VSizeXY(ThirdPersonMoveComponent->Velocity);
	}
}

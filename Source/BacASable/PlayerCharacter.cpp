// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerCharacter::MoveRight);

}

void APlayerCharacter::MoveForward(float value)
{
	if (FMath::Abs(value) >= 0.01f) {
		FVector dir = GetActorForwardVector();

		AddMovementInput(dir, value);
	}
}

void APlayerCharacter::MoveRight(float value)
{
	if (FMath::Abs(value) >= 0.01f) {
		FVector dir = GetActorRightVector();

		AddMovementInput(dir, value);
	}
}

void APlayerCharacter::AnalyzeDifference()
{
	if (fallDifference > 350) {
		setHealth(getHealth() - 10);
	}
	else if (fallDifference > 250) {
		setHealth(getHealth() - 5);
	}
	else if (fallDifference > 100) {
		setHealth(getHealth() - 1);
	}
}

//void APlayerCharacter::Falling()
//{
//	bool calculateStartHeigh = true;
//	float startHeight;
//	float endHeight;
//	float heightDifference;
//	if (GetCharacterMovement()->IsFalling()){
//		calculateStartHeigh = false;
//		if (calculateStartHeigh == false) {
//			startHeight = APlayerCharacter::GetActorLocation().Z;
//			//UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), startHeight);
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("The float value is: %f"), startHeight));
//			calculateStartHeigh = true;
//		}
//	}
//	if (&APlayerCharacter::OnLanded) {
//		endHeight = APlayerCharacter::GetActorLocation().Z;
//		heightDifference = startHeight - endHeight;
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("The float value is: %f"), endHeight));
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("The difference is: %f"), heightDifference));
//
//		calculateStartHeigh = false;
//
//
//	}
//}


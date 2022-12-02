// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class BACASABLE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float health = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int maxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Falling")
		float startHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Falling")
		float endHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Falling")
		float fallDifference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float speed = 600;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void MoveForward(float value);
	UFUNCTION(BlueprintCallable, Category = "Movement")
		void MoveRight(float value);

	UFUNCTION(BlueprintCallable, Category = "Falling")
		float getStartHeight() const { return this->GetActorLocation().Z; }

	UFUNCTION(BlueprintCallable, Category = "Falling")
		float getEndHeight() const { return this->GetActorLocation().Z; }

	UFUNCTION(BlueprintCallable, Category = "Falling")
		void setStartHeight(float var) { startHeight = var; }

	UFUNCTION(BlueprintCallable, Category = "Falling")
		void setEndHeight(float var) { endHeight = var; }

	UFUNCTION(BlueprintCallable, Category = "Falling")
		float getFallDifference() const { return startHeight - endHeight; }

	UFUNCTION(BlueprintCallable, Category = "Falling")
		void setFallDifference(float var) { fallDifference = var; }

	UFUNCTION(BlueprintCallable, Category = "Falling")
		void AnalyzeDifference();
	//get 
	UFUNCTION(BlueprintCallable, Category = "Health")
		float getHealth() const { return health; }

	//set 
	UFUNCTION(BlueprintCallable, Category = "Health")
		void setHealth(int var) { health = var; }

	//get 
	UFUNCTION(BlueprintCallable, Category = "Health")
		int getMaxHealth() const { return maxHealth; }

};

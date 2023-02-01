// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainController.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class COMPULSORY_API AMainController : public APawn
{
	GENERATED_BODY()

public:
	AMainController();

protected:

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		TArray<UStaticMeshComponent*> Spheres;


	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;


	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;


	UPROPERTY(EditAnywhere)
		UMaterial* Red;
	UPROPERTY(EditAnywhere)
		UMaterial* Blue;
	UPROPERTY(EditAnywhere)
		UMaterial* White;

	bool isRed;

	TArray<UMaterial*> Color;



	void One();
	void Two();
	void Three();
	void Four();
	void Five();
	void Six();
	void Seven();
	void Eight();
	void Nine();

	void MakeTurn(int indexNumber);

	void isMatching(int index);
};
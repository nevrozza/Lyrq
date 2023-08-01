// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AC_Stats.h"

#include "C_Player.generated.h"

UCLASS(config = Game)	
class LYRQ_API AC_Player : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category =  Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;


public:
	// Sets default values for this character's properties
	AC_Player();
	

protected:
	// Привязка контроллера игрока к DefaultMappingContext 
	// Данные из PlayerState --> StatsComponent
	virtual void BeginPlay() override;
	
	// Нет смысла трогать
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Move(const FInputActionValue& Value);


public:
	UPROPERTY(Category = Stats, VisibleAnywhere, BlueprintReadOnly)
	UAC_Stats* StatsComponent;

	// Неуязвимость от всех типов урона
	UPROPERTY(Category = Combat, VisibleAnywhere, BlueprintReadOnly)
	bool bIsInvincible = true;

	// Персонаж находится в состоянии блока
	UPROPERTY(Category = Combat, VisibleAnywhere, BlueprintReadOnly)
	bool bIsBlocking = true;

	

};

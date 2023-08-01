// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class LYRQ_API UW_ActionBar : public UUserWidget
{
	GENERATED_BODY()

//HEART

public:
	
	// Update HP Bar
	UFUNCTION()
	void SetHealth(float Percent);

	// Update Mana Bar
	UFUNCTION()
	void SetMana(float Percent);
	
	// Скорость изменения отображения хп и маны
	UPROPERTY(EditAnyWhere)
	float BarSpeed = 1;


// Smooth bar transition variables (ChatGPT <3)
protected:
	// Используется для анимации
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
	bool bIsHealthBarAnimating = false;
	float TargetHealth = 1;
	float HealthTransitionStartTime = 0;
	float HealthTransitionDuration = 0;
	bool bIsManaBarAnimating = false;
	float TargetMana = 1;
	float ManaTransitionDuration = 0;
	float ManaTransitionStartTime = 0;
	float PrevHealth = 1;
	float PrevMana = 1;

private:
	// Привязка виджетов по имени в blueprint
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UProgressBar* HealthBar;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UProgressBar* ManaBar;
	
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "W_ActionBar.h"
#include "Components/ProgressBar.h"


void UW_ActionBar::SetHealth(float Percent)
{
	HealthTransitionDuration = (PrevHealth-Percent) * BarSpeed;
	if (bIsHealthBarAnimating)
	{
		TargetHealth = Percent;
	}
	else
	{
		HealthTransitionStartTime = GetWorld()->GetTimeSeconds();
		bIsHealthBarAnimating = true;
		TargetHealth = Percent;
	}
}

void UW_ActionBar::SetMana(float Percent)
{
	ManaTransitionDuration = (PrevHealth - Percent) * BarSpeed;
	if (bIsManaBarAnimating)
	{
		TargetMana = Percent;
	}
	else
	{
		ManaTransitionStartTime = GetWorld()->GetTimeSeconds();
		bIsManaBarAnimating = true;
		TargetMana = Percent;
	}
}

void UW_ActionBar::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);
	// ChatGPT code with some improvements
	// Smoothly update health bar 
	if (bIsHealthBarAnimating)
	{
		float CurrentTime = GetWorld()->GetTimeSeconds();
		float TimeSinceStart = CurrentTime - HealthTransitionStartTime;

		if (TimeSinceStart >= HealthTransitionDuration)
		{
			bIsHealthBarAnimating = false;
			PrevHealth = TargetHealth;
			HealthTransitionDuration = 0;
		}
		else
		{
			float Alpha = TimeSinceStart / HealthTransitionDuration;
			float NewHealth = FMath::Lerp(PrevHealth, TargetHealth, Alpha);

			HealthBar->SetPercent(NewHealth);
		}
	}

	// Smoothly update mana bar
	if (bIsManaBarAnimating)
	{
		float CurrentTime = GetWorld()->GetTimeSeconds();
		float TimeSinceStart = CurrentTime - ManaTransitionStartTime;

		if (TimeSinceStart >= ManaTransitionDuration)
		{
			bIsManaBarAnimating = false;
			PrevMana = TargetMana;
			ManaTransitionDuration = 0;
		}
		else
		{
			float Alpha = TimeSinceStart / ManaTransitionDuration;
			float NewMana = FMath::Lerp(PrevMana, TargetMana, Alpha);
			ManaBar->SetPercent(NewMana);
		}
	}
}

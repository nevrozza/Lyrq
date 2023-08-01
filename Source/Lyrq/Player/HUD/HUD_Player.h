// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "W_ActionBar.h"
#include "HUD_Player.generated.h"

/**
 * 
 */
UCLASS()
class LYRQ_API AHUD_Player : public AHUD
{
	GENERATED_BODY()
		
private:
	AHUD_Player();
	virtual void BeginPlay() override;
public:
	TSubclassOf<class UUserWidget> ActionBarWidget;
	UW_ActionBar* ActionBar;	
};

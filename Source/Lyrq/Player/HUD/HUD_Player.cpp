// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Player.h"
#include "Blueprint/UserWidget.h"



AHUD_Player::AHUD_Player()
{
	ConstructorHelpers::FClassFinder<UW_ActionBar> WActionBar(TEXT("/Game/Player/Widgets/BW_ActionBar"));
	ActionBarWidget = WActionBar.Class;
}

void AHUD_Player::BeginPlay()
{
	if (ActionBarWidget != nullptr) {
		ActionBar = CreateWidget<UW_ActionBar>(GetWorld(), ActionBarWidget);
		ActionBar->AddToViewport();
	}
}

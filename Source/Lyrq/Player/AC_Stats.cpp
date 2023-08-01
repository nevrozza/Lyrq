// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Stats.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UAC_Stats::UAC_Stats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}

void UAC_Stats::RegisterPlayer()
{
	// Получение PlayerController владельца
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this->GetOwner(), 0);
	// Получение HUD (возможно только на клиенте)
	AHUD_Player* HUD = Cast<AHUD_Player>(PlayerController->GetHUD());
	// Находим FName функции
	FName SetHealthFun = GET_FUNCTION_NAME_CHECKED(UW_ActionBar, SetHealth);
	// Биндим ActionBar функцию к делегату
	OnHPPercentChangedDelegate.BindUFunction(HUD->ActionBar, SetHealthFun);
	FName SetManaFun = GET_FUNCTION_NAME_CHECKED(UW_ActionBar, SetMana);
	OnManaPercentChangedDelegate.BindUFunction(HUD->ActionBar, SetManaFun);
	
	// Получение PlayerState
	APS_Main* PS = Cast<APS_Main>(PlayerController->PlayerState);
	
	Stats = PS->Stats;
}

void UAC_Stats::RegisterMob()
{
	
}

void UAC_Stats::HPEvent()
{
	// Обновить хп в UI
	// IfBound используется, чтобы не вылетало, если нет забинженной функции
	OnHPPercentChangedDelegate.ExecuteIfBound(Stats.CurrentHP / (float)Stats.MaxHP);
}

void UAC_Stats::SetName(const FString& Value)
{
	Stats.Name = Value;
}


void UAC_Stats::IncreaseHP(int32 Value)
{
	Stats.CurrentHP += Value;
	if (Stats.CurrentHP >= Stats.MaxHP) Stats.CurrentHP = Stats.MaxHP;
	HPEvent();
}
void UAC_Stats::DecreaseHP(int32 Value)
{
	Stats.CurrentHP -= Value;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(Stats.CurrentHP));
	if (Stats.CurrentHP <= 0)
	{
		//DeathCode
	}
	HPEvent();
}



void UAC_Stats::IncreaseMaxHP(int32 Value) 
{
	Stats.MaxHP += Value;
	HPEvent();
}
void UAC_Stats::SetMaxHP(int32 Value) { 
	Stats.MaxHP = Value; 
	HPEvent(); 
}

void UAC_Stats::IncreaseMana(int32 Value) { Stats.CurrentMana += Value; }
void UAC_Stats::DecreaseMana(int32 Value) { Stats.CurrentMana -= Value; }

void UAC_Stats::IncreaseIQ(int32 Value) { Stats.IQ += Value; }
void UAC_Stats::SetIQ(int32 Value) { Stats.IQ = Value; }

void UAC_Stats::IncreaseXP(int32 Value)
{
	Stats.XP += Value;
	if (Stats.XP >= 500) Stats.XP = 0; Stats.CountOfPoints++;
}

void UAC_Stats::DecreasePoints(int32 Value) { Stats.CountOfPoints -= Value; }

void UAC_Stats::IncreaseStrength(int32 Value) { Stats.Strength += Value; }
void UAC_Stats::SetStrength(int32 Value) { Stats.Strength = Value; }

void UAC_Stats::IncreaseSpeed(int32 Value) { Stats.Speed += Value; }
void UAC_Stats::SetSpeed(int32 Value) { Stats.Speed = Value; }

void UAC_Stats::IncreaseAgility(int32 Value) { Stats.Agility += Value; }
void UAC_Stats::SetAgility(int32 Value) { Stats.Agility = Value; }


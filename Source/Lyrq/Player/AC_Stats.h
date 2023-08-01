// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PS_Main.h"
#include "HUD/HUD_Player.h"

#include "AC_Stats.generated.h"


DECLARE_DELEGATE_OneParam(FOnHPPercentChangedSignature, float);
DECLARE_DELEGATE_OneParam(FOnManaPercentChangedSignature, float);


// Компонент, отвечающий за характеристики Actor (hp, mana, etc.)
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LYRQ_API UAC_Stats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Stats();

public:	
    FStatsStruct Stats;
   
    // Нужно почитать, но, вроде, делегаты сами анбиндятся с уничтожением объекта

    // Делегаты HPEvent и ManaEvent
    FOnHPPercentChangedSignature OnHPPercentChangedDelegate;
    FOnManaPercentChangedSignature OnManaPercentChangedDelegate;
    
    // *Регистрация* игрока (получение характеристик из PlayerState)
    void RegisterPlayer();
    // Заготовка для *регистрации* характеристик моба, должна получать MaxHP, Strength, Speed, 
    void RegisterMob();

    // Вызывать, когда хотим обновить показатели хп в HUD (IncreaseHP, DecreaseHP, IncreaseMaxHP, SetMaxHP)
    void HPEvent();

    // Аналогичный стоит сделать для маны =)

    UFUNCTION(BlueprintCallable, Category = "Stats")
        void SetName(const FString& Value);

    UFUNCTION(BlueprintCallable, Category = "HP")
        void IncreaseHP(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "HP")
        void DecreaseHP(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Stats")
        void IncreaseMaxHP(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void SetMaxHP(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Mana")
        void IncreaseMana(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Mana")
        void DecreaseMana(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void IncreaseIQ(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void SetIQ(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Stats")
        void IncreaseXP(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Stats")
        void DecreasePoints(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Stats")
        void IncreaseStrength(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void SetStrength(int32 Value);

    UFUNCTION(BlueprintCallable, Category = "Stats")
        void IncreaseSpeed(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void SetSpeed(int32 Value);

    // Вырезать??
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void IncreaseAgility(int32 Value);
    UFUNCTION(BlueprintCallable, Category = "Stats")
        void SetAgility(int32 Value);
		
};

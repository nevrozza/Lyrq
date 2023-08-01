// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "PS_Main.generated.h"

/**
 * 
 */


// Структура статы (для всех)
USTRUCT()
struct FStatsStruct
{
    GENERATED_BODY()
        
    UPROPERTY()
        FString Name = "None";

    UPROPERTY()
        int32 CurrentHP = 100;

    UPROPERTY()
        int32 MaxHP = 100;

    UPROPERTY()
        int32 CurrentMana = 100;

    UPROPERTY()
        int32 IQ = 100;

    // Используется только в InGame развитии
    UPROPERTY(NotReplicated)
        int32 XP = 0;

    // Используется только в InGame развитии
    UPROPERTY(NotReplicated)
        int32 CountOfPoints = 0;

    UPROPERTY()
        int32 Strength = 1;

    UPROPERTY()
        int32 Speed = 1;

    UPROPERTY()
        int32 Agility = 1;

};


UCLASS(config = Game)
class LYRQ_API APS_Main : public APlayerState
{
    GENERATED_BODY()
public:
    UPROPERTY() //UPROPERTY(Replicated) https://forums.unrealengine.com/t/errors-with-c-variable-replication/364744
    FStatsStruct Stats;    
};

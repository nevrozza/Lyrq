// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SG_Player.generated.h"

/**
 * 
 */
UCLASS()
class LYRQ_API USG_Player : public USaveGame
{
	GENERATED_BODY()

	// Функция для получения файлов.sav из папки сохранений (Stackoverflow <3)
	UFUNCTION(BlueprintCallable)
	static TArray<FString> GetAvailableSaveGameFiles();
};

	


		
// Fill out your copyright notice in the Description page of Project Settings.


#include "SG_Player.h"

TArray<FString> USG_Player::GetAvailableSaveGameFiles()
{
	// По идее эти переменные должны быть в header, но игра вылетала при фулл запуске (компилятор не ругался)
	FString SaveGameDirName = TEXT("SaveGames");
	FString SaveGameDirPath = FPaths::ProjectSavedDir() + SaveGameDirName;
	FString SaveGameFileExt = TEXT("sav");
	FString SaveGameFileExtIncDot = TEXT(".") + SaveGameFileExt;
	//
	TArray<FString> FoundFiles;
	
	const FString Empty = TEXT("");

	
	IFileManager::Get().FindFiles(FoundFiles, *SaveGameDirPath, *SaveGameFileExt);
	
	
	for (int i = 0; i < FoundFiles.Num(); i++)
	{
		
		FoundFiles[i] = FoundFiles[i].Replace(*SaveGameFileExtIncDot, *Empty);
	}

	FoundFiles.RemoveSingleSwap("main");
	
	return FoundFiles;
}


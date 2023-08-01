// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Lyrq : ModuleRules
{
	public Lyrq(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Latest;
        PublicDependencyModuleNames.AddRange(new string[] 
        { 
            "Core", // Default
            "CoreUObject", // Default
            "Engine", // Default
            "InputCore", // Default
            "EnhancedInput", // EnhancedInput plugin
            "UMG" // For UI
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
    
}

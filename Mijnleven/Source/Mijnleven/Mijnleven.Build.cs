// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Mijnleven : ModuleRules
{
	public Mijnleven(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Mijnleven",
			"Mijnleven/Variant_Strategy",
			"Mijnleven/Variant_Strategy/UI",
			"Mijnleven/Variant_TwinStick",
			"Mijnleven/Variant_TwinStick/AI",
			"Mijnleven/Variant_TwinStick/Gameplay",
			"Mijnleven/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

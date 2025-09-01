// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PressurePlateDemo : ModuleRules
{
	public PressurePlateDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PressurePlateDemo",
			"PressurePlateDemo/Variant_Platforming",
			"PressurePlateDemo/Variant_Combat",
			"PressurePlateDemo/Variant_Combat/AI",
			"PressurePlateDemo/Variant_SideScrolling",
			"PressurePlateDemo/Variant_SideScrolling/Gameplay",
			"PressurePlateDemo/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

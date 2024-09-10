// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExploreBLE_Plugin : ModuleRules
{
	public ExploreBLE_Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

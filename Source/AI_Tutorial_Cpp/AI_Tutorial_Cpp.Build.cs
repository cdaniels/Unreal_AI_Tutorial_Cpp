// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI_Tutorial_Cpp : ModuleRules
{
	public AI_Tutorial_Cpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"AIModule",
			"GameplayTasks",
			"NavigationSystem"
		});
	}
}

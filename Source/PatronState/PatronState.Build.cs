// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PatronState : ModuleRules
{
	public PatronState(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}

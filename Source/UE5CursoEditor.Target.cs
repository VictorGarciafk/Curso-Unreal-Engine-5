// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5CursoEditorTarget : TargetRules
{
	public UE5CursoEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V6;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("UE5Curso");
	}
}

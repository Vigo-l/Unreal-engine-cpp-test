using System;
using System.Collections.Generic;
using UnrealBuildTool;

public class MijnlevenEditorTarget : TargetRules
{
    public MijnlevenEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;

        ExtraModuleNames.AddRange(new string[] { "Mijnleven" });
    }
}
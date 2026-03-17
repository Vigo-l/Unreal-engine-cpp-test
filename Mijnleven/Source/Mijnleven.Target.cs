using System;
using System.Collections.Generic;
using UnrealBuildTool;

public class MijnlevenTarget : TargetRules
{
    public MijnlevenTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V6;

        ExtraModuleNames.AddRange(new string[] { "Mijnleven" });
    }
}
using UnrealBuildTool;
using System.Collections.Generic;

public class StillringTarget : TargetRules
{
    public StillringTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("Stillring");
    }
}

using UnrealBuildTool;
using System.Collections.Generic;

public class StillringEditorTarget : TargetRules
{
    public StillringEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.AddRange(new[] { "Stillring", "StillringDev" });
    }
}

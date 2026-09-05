#include "SystemIDE/StillringSystemIDE.h"

FStillringSystemIDERegistry& FStillringSystemIDERegistry::Get()
{
    static FStillringSystemIDERegistry Registry;
    return Registry;
}

bool FStillringSystemIDERegistry::RegisterWorkbench(const TSharedRef<IStillringSystemWorkbench>& Workbench)
{
    const FName Id = Workbench->GetWorkbenchId();
    if (Id.IsNone() || Workbenches.Contains(Id))
    {
        return false;
    }

    Workbenches.Add(Id, Workbench);
    return true;
}

void FStillringSystemIDERegistry::UnregisterWorkbench(const FName WorkbenchId)
{
    Workbenches.Remove(WorkbenchId);
}

TArray<TSharedRef<IStillringSystemWorkbench>> FStillringSystemIDERegistry::GetWorkbenches() const
{
    TArray<TSharedRef<IStillringSystemWorkbench>> Result;
    Workbenches.GenerateValueArray(Result);
    return Result;
}

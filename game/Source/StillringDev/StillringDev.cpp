#include "Modules/ModuleManager.h"
#include "SystemIDE/StillringSystemIDE.h"
#include "SystemIDE/StillringHarnessWorkbench.h"

class FStillringDevModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        HarnessWorkbench = MakeShared<FStillringHarnessWorkbench>();
        FStillringSystemIDERegistry::Get().RegisterWorkbench(HarnessWorkbench.ToSharedRef());
    }

    virtual void ShutdownModule() override
    {
        FStillringSystemIDERegistry::Get().UnregisterWorkbench(TEXT("Gate1Harness"));
        HarnessWorkbench.Reset();
    }

private:
    TSharedPtr<FStillringHarnessWorkbench> HarnessWorkbench;
};

IMPLEMENT_MODULE(FStillringDevModule, StillringDev);

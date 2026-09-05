#include "Modules/ModuleManager.h"

class FStillringDevModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FStillringDevModule, StillringDev);

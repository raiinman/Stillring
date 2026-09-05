#pragma once

#include "SystemIDE/StillringSystemIDE.h"

class FStillringHarnessWorkbench final : public IStillringSystemWorkbench
{
public:
    virtual FName GetWorkbenchId() const override
    {
        static const FName Id(TEXT("Gate1Harness"));
        return Id;
    }

    virtual FText GetDisplayName() const override
    {
        return NSLOCTEXT("StillringSystemIDE", "Gate1HarnessWorkbench", "Gate 1 Harness");
    }
};

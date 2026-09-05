#pragma once

#include "CoreMinimal.h"

/** Development-only provenance states required by docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md. */
enum class EStillringValueProvenance : uint8
{
    Canonical,
    SessionOverride,
    Staged,
    Promoted
};

/** Minimal registration contract for purpose-built System IDE workbenches. */
class IStillringSystemWorkbench
{
public:
    virtual ~IStillringSystemWorkbench() = default;

    virtual FName GetWorkbenchId() const = 0;
    virtual FText GetDisplayName() const = 0;
};

/** Shared development-only registry. UI presentation is intentionally deferred. */
class STILLRINGDEV_API FStillringSystemIDERegistry
{
public:
    static FStillringSystemIDERegistry& Get();

    bool RegisterWorkbench(const TSharedRef<IStillringSystemWorkbench>& Workbench);
    void UnregisterWorkbench(FName WorkbenchId);
    TArray<TSharedRef<IStillringSystemWorkbench>> GetWorkbenches() const;

private:
    TMap<FName, TSharedRef<IStillringSystemWorkbench>> Workbenches;
};

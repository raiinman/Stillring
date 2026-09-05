#include "Misc/AutomationTest.h"
#include "SystemIDE/StillringSystemIDE.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace StillringSystemIDESmoke
{
class FSmokeWorkbench final : public IStillringSystemWorkbench
{
public:
    explicit FSmokeWorkbench(const FName InId)
        : Id(InId)
    {
    }

    virtual FName GetWorkbenchId() const override { return Id; }
    virtual FText GetDisplayName() const override { return FText::FromName(Id); }

private:
    FName Id;
};
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FStillringSystemIDERegistrySmokeTest,
    "Stillring.Gate1.SystemIDE.Registry",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FStillringSystemIDERegistrySmokeTest::RunTest(const FString& Parameters)
{
    using namespace StillringSystemIDESmoke;

    static const FName SmokeId(TEXT("AutomationSmokeWorkbench"));
    FStillringSystemIDERegistry& Registry = FStillringSystemIDERegistry::Get();
    Registry.UnregisterWorkbench(SmokeId);

    const TSharedRef<FSmokeWorkbench> First = MakeShared<FSmokeWorkbench>(SmokeId);
    TestTrue(TEXT("first registration succeeds"), Registry.RegisterWorkbench(First));

    const TSharedRef<FSmokeWorkbench> Duplicate = MakeShared<FSmokeWorkbench>(SmokeId);
    TestFalse(TEXT("duplicate registration is rejected"), Registry.RegisterWorkbench(Duplicate));

    const bool bFound = Registry.GetWorkbenches().ContainsByPredicate(
        [](const TSharedRef<IStillringSystemWorkbench>& Workbench)
        {
            return Workbench->GetWorkbenchId() == SmokeId;
        });
    TestTrue(TEXT("registered workbench is discoverable"), bFound);

    Registry.UnregisterWorkbench(SmokeId);
    const bool bStillFound = Registry.GetWorkbenches().ContainsByPredicate(
        [](const TSharedRef<IStillringSystemWorkbench>& Workbench)
        {
            return Workbench->GetWorkbenchId() == SmokeId;
        });
    TestFalse(TEXT("unregistered workbench is removed"), bStillFound);

    return true;
}

#endif

# 188 — Stillring Technical Production Bible

**Status:** ACTIVE / STUDIO-HANDOFF TECHNICAL PRODUCTION AUTHORITY / DOCUMENTATION-ONLY PRE-PRODUCTION  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap authority:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance authority:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Primary technical parents:** `CLAUDE.md`, `docs/03_PRODUCTION_WORKFLOW.md`, `docs/04_TECHNICAL_DIRECTION.md`, `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md`, `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`, `docs/139_SYSTEM_OWNERSHIP_MAP.md`, `docs/140_CROSS_SYSTEM_CONTRACT_MATRIX.md`, `docs/141_SYSTEM_IDE_COVERAGE_MATRIX.md`, `docs/142_RUNTIME_EVIDENCE_LEDGER_BASELINE.md`, `docs/144_UNANSWERED_QUESTION_REGISTER.md`, `docs/145_IMPLEMENTATION_READINESS_GAP_REGISTER.md`  
**Current stacked content parent:** `docs/185_REGION_WORLD_CONTENT_PRODUCTION_MANIFEST.md`, `docs/186_DUNGEON_ENCOUNTER_AND_NETWORK_PRODUCTION_MANIFEST.md`, `docs/187_WORLD_CONTENT_WRITTEN_HANDOFF_ACCEPTANCE_AUDIT.md`  
**Closes toward:** `SH-TECH-001` through `SH-TECH-010`  
**Boundary:** this document consolidates technical-production conventions for an external studio. It does **not** authorize UE5.8 implementation, select the final Hush runtime representation, establish measured performance budgets, claim a working build, or close Issues #4, #5, or #58.

---

# 1. Purpose

Stillring already has substantial architecture authority spread across gameplay, persistence, content, and production documents.

What an external studio still needs is one operating contract that answers:

- where code and assets belong;
- what may own gameplay truth;
- how authored data is represented;
- how stable IDs survive asset moves and save migrations;
- how Unreal binaries are versioned and reviewed;
- when hard references are acceptable;
- when plugins/frameworks may be adopted;
- how developer tooling is stripped from retail;
- how user-facing text remains localization-ready;
- how fixtures, logs, captures, and evidence are named;
- which technical decisions engineering may make without owner approval;
- which architecture questions are deliberately left to runtime evidence.

The governing rule is:

> **Repository authority defines meaning; Unreal implements and presents that meaning.**

A second rule follows:

> **A convenient engine object is not automatically a valid source of truth.**

---

# 2. Current runtime truth

As of this document:

- `game/` remains intentionally skeletal;
- no `Stillring.uproject` exists in accepted authority;
- no gameplay C++ module exists;
- no playable UE5.8 map exists;
- no System IDE exists in runtime;
- no Hush representation has been selected by comparative runtime evidence;
- no target-PC frame budget has been selected;
- no performance claims are accepted;
- no source-control workflow has yet been proven against real Unreal binary churn.

Therefore every rule below is either:

1. existing locked technical authority consolidated for production;
2. a studio-operational convention safe to choose before runtime;
3. an explicit future evidence gate.

It is not implementation proof.

---

# 3. Authority precedence

When technical documents disagree, resolve conflicts in this order:

1. current owner-approved product/gameplay/story authority;
2. current system ownership and cross-system contracts (`docs/139`, `docs/140`);
3. save/Hush/completion/Setup-Payoff/Skiff/finale scoped authority;
4. `CLAUDE.md` and `docs/04_TECHNICAL_DIRECTION.md`;
5. this Technical Production Bible;
6. approved implementation architecture recorded after runtime evidence;
7. local engine/editor defaults.

Unreal defaults are never higher authority than Stillring.

A marketplace/plugin framework is never higher authority than Stillring.

A binary asset is never higher authority merely because it is harder to diff.

---

# 4. Engine and version policy

## 4.1 Production engine

Stillring targets **Unreal Engine 5.8**.

Do not silently move to:

- preview builds;
- development branches;
- later major/minor engine versions;
- source-engine forks;
- plugin-pinned engine forks.

An engine migration requires:

- identified blocker or measurable production benefit;
- dedicated migration branch;
- project build/open proof;
- content/reference validation;
- save/schema compatibility review;
- plugin compatibility review;
- representative map/asset validation;
- explicit project approval.

## 4.2 Engine features are opt-in

The following remain **non-default dependencies**:

- Gameplay Ability System;
- World Partition;
- Runtime Data Layers;
- Nanite;
- Lumen;
- MetaHuman;
- PCG;
- Mass framework;
- any third-party save/quest/dialogue/combat framework.

They may be adopted only when they solve a demonstrated Stillring problem better than a smaller transparent implementation.

---

# 5. C++-first gameplay authority / thin Blueprint policy

## 5.1 C++ owns authoritative gameplay/state

Prefer C++ or reviewable structured data for:

- locomotion rules/state;
- camera and targeting policy;
- combat action/state;
- encounter scheduling and durable encounter outcomes;
- inventory/tool progression;
- quest/objective state;
- world-state authority;
- semantic Waking/Hush authority;
- save schema/version/migration;
- persistent semantic identity;
- completion reconciliation;
- Setup/Payoff evaluation and receipts;
- Line Skiff route semantics;
- dialogue eligibility policy;
- System IDE registration/semantic services;
- deterministic validation interfaces.

## 5.2 Blueprints may own presentation and assembly

Blueprints are appropriate for:

- presentation wiring;
- Animation Blueprint presentation;
- VFX/audio hooks;
- scene assembly;
- designer references;
- Sequencer integration;
- disposable prototypes;
- local presentation state that does not become durable gameplay truth.

## 5.3 Blueprint rejection conditions

Reject or refactor a Blueprint if it becomes the only owner of:

- a quest branch;
- persistent world history;
- save identity;
- completion entitlement;
- a core combat rule;
- Hush semantic state;
- a major dialogue eligibility rule;
- a route-availability rule;
- a System IDE shadow state.

Level Blueprints may stage local presentation but may not become regional game-state databases.

---

# 6. Source ownership and transaction discipline

`docs/139` and `docs/140` are binding.

The production shorthand is:

> **One canonical fact, one authoritative writer.**

Consumers may:

- read;
- query;
- request;
- derive;
- present;
- react.

Consumers may not quietly persist a second copy of another owner's truth.

## 6.1 Cross-system commit rule

A multi-system operation must settle semantically before save/completion/downstream systems treat it as history.

Examples:

```text
pickup
  -> Inventory settles ownership
  -> World settles consumed state
  -> Completion observes settled source outcome
  -> snapshot allowed
```

```text
boss resolution
  -> Encounter State settles unique outcome
  -> World/Quest consequences settle through their owners
  -> reward/Completion observe
  -> snapshot allowed
```

```text
Setup/Payoff
  -> source-owned event settles
  -> Setup/Payoff commit/resolution receipt settles
  -> source-owned consequence remains source-owned
  -> Completion observes receipt
```

No system may use save serialization timing as a substitute for a semantic transaction boundary.

---

# 7. Project organization

The target root remains:

```text
game/
  Stillring.uproject
  Config/
  Source/
    Stillring/
      Public/
        Core/
        Player/
        Combat/
        Interaction/
        Narrative/
        World/
        Tools/
        Debug/
      Private/
        Core/
        Player/
        Combat/
        Interaction/
        Narrative/
        World/
        Tools/
        Debug/
        Tests/
  Content/
    Stillring/
      Maps/
      Blueprints/
      Characters/
      Animation/
      Environments/
      UI/
      Audio/
      VFX/
      Materials/
      Cinematics/
      Developer/
  SourceData/
    Narrative/
    Quests/
    Items/
    Enemies/
    WorldState/
    TestPresets/
  Scripts/
```

This is a **domain map**, not permission to pre-create empty folders.

Create a directory when a real file needs it.

---

# 8. C++ folder and module conventions

## 8.1 Domain-first source layout

Source code should follow ownership domains rather than asset type or feature marketing names.

Examples:

- `Player/Locomotion`;
- `Player/Camera`;
- `Combat`;
- `Interaction`;
- `World/Hush`;
- `Narrative/Quest`;
- `Narrative/Dialogue`;
- `Tools/Cantor`;
- `World/Routes`;
- `Debug/SystemIDE`.

Do not create a giant `Managers/` directory.

Do not create a giant inheritance hierarchy merely to share editor exposure.

## 8.2 Public versus Private

Place headers in `Public/` only when another module/domain genuinely needs the public API.

Implementation-only types remain private.

Avoid making every internal class public because Blueprint access is convenient.

## 8.3 Module decomposition is studio choice within bounds

The exact number of Unreal modules is not locked on paper.

A studio may split runtime/editor/developer modules when useful, provided:

- owner domains remain clear;
- dependency direction remains acyclic enough to reason about;
- development-only tooling can be excluded from Shipping;
- no module split duplicates gameplay truth;
- build/package complexity remains justified.

---

# 9. Naming conventions

Naming exists for searchability, reviewability, collision reduction, and automation.

It is not identity authority.

## 9.1 C++ type naming

Use normal Unreal conventions:

- `A` — Actor;
- `U` — UObject/Component;
- `F` — struct/value type;
- `E` — enum;
- `I` — interface;
- `T` — template/helper where idiomatic.

Project types should use clear `Stillring` or domain-specific names where ambiguity would otherwise exist.

Avoid abbreviations that only one author understands.

## 9.2 Asset prefix convention

Use the following production prefixes unless a later tool-specific pipeline documents a better bounded exception:

| Asset class | Prefix |
|---|---|
| Blueprint | `BP_` |
| Blueprint Interface | `BPI_` |
| Widget Blueprint | `WBP_` |
| Data Asset / Primary Data Asset | `DA_` |
| Data Table | `DT_` |
| Input Action | `IA_` |
| Input Mapping Context | `IMC_` |
| Static Mesh | `SM_` |
| Skeletal Mesh | `SK_` |
| Skeleton | `SKEL_` |
| Material | `M_` |
| Material Instance | `MI_` |
| Texture | `T_` |
| Animation Blueprint | `ABP_` |
| Animation Sequence | `AS_` |
| Animation Montage | `AM_` |
| Blend Space | `BS_` |
| Control Rig | `CR_` |
| Niagara System | `NS_` |
| Sound effect asset/family | `SFX_` |
| Music asset/cue family | `MUS_` |
| Level Sequence | `SEQ_` |
| World/Level | `L_` |

Format:

```text
<Prefix><RegionOrDomain>_<Purpose>[_Variant][_State]
```

Examples:

```text
SM_Rootmere_FerryPier_A
MI_Saltreach_WetIron_Hush
DA_Completion_Fault_Rootmere_07
IA_Player_Interact
IMC_Player_Gameplay
WBP_SystemIDE_Shell
SEQ_Cairnspire_GrandRing_Entry
```

Examples are naming-form demonstrations, not new canonical content IDs.

## 9.3 Forbidden asset-name practices

Do not ship assets named:

- `NewBlueprint`;
- `Final` / `Final2` / `UseThis`;
- `Temp` for production content;
- `Copy` variants with no semantic reason;
- another commercial game's terminology;
- a content ID embedded only in a display label with no real semantic field.

Temporary prototype content should be visibly placed under `Developer/` or another clearly non-production scope.

---

# 10. Package/folder conventions

Unreal Content Browser root:

```text
/Game/Stillring/
```

Do not place project content directly under `/Game/` beside unrelated plugin/template assets.

Recommended organization:

```text
/Game/Stillring/Characters/
/Game/Stillring/Animation/
/Game/Stillring/Environments/
/Game/Stillring/Maps/
/Game/Stillring/Materials/
/Game/Stillring/VFX/
/Game/Stillring/Audio/
/Game/Stillring/UI/
/Game/Stillring/Cinematics/
/Game/Stillring/Blueprints/
/Game/Stillring/Developer/
```

Within a discipline, prefer region/domain folders when production volume justifies them.

Examples:

```text
/Game/Stillring/Environments/Rootmere/
/Game/Stillring/Audio/Regions/Saltreach/
/Game/Stillring/Characters/Neris/
/Game/Stillring/UI/SystemIDE/
```

Do not duplicate the same asset into region folders merely to avoid a reference.

Shared authored families should live in a deliberate shared location.

---

# 11. Stable semantic ID policy

Stable semantic identity is one of Stillring's hardest technical boundaries.

## 11.1 Semantic IDs are independent of assets

Never use as canonical persistence identity:

- Actor pointer;
- UObject path;
- package path;
- map path;
- Data Layer name;
- spline Actor name;
- runtime GUID created on spawn;
- Blueprint instance name;
- display/localized text;
- array index;
- spawn order.

## 11.2 ID format

Canonical content/system IDs should use lower-case dotted semantic namespaces where current authority already follows that pattern.

Examples from existing authority include forms such as:

```text
setup.brindle.crooked_fire_bell
upgrade.cantor.field_memory
```

New families should follow the same readability principle:

```text
<domain>.<region-or-subdomain>.<stable-name>
```

The exact typed wrapper used in C++ remains an implementation decision.

Allowed Unreal-friendly representations include:

- `FName` inside a typed wrapper;
- Gameplay Tag when hierarchical query behavior is genuinely useful;
- another small typed semantic-ID value with explicit serialization.

Do not scatter raw `FString` comparisons throughout gameplay code.

## 11.3 Renames

Renaming an asset does **not** require changing its semantic ID.

Renaming a semantic ID requires:

- explicit alias/migration mapping;
- save/data compatibility review;
- reference validation;
- idempotent migration tests later.

Display-name changes do not change semantic identity.

---

# 12. Gameplay Tags boundary

Gameplay Tags are useful for hierarchical categorization and queries.

They may represent things such as:

- capabilities;
- states;
- categories;
- authored compatibility labels;
- event classes.

They must not automatically become the persistence ID system for every object.

Use a Gameplay Tag as canonical identity only when the semantic contract explicitly says that tag itself is the stable identity.

Do not convert every boolean into a tag merely to claim the project is data-driven.

---

# 13. Data-authoring conventions

Stillring uses the **smallest transparent representation appropriate to the data**.

## 13.1 Primary Data Assets

Prefer a `UPrimaryDataAsset`-style representation when:

- an authored definition has a stable top-level semantic identity;
- it benefits from Asset Manager discovery/loading;
- it contains typed references to other assets/data;
- it is independently reviewable as one content definition;
- lifecycle/load-bundle behavior matters.

Candidate domains include:

- Setup/Payoff chain definitions;
- encounter archetypes/configurations;
- items/tools/upgrades;
- completion item definitions;
- route definitions;
- named fixture definitions.

The exact class fields remain system implementation work unless already locked.

## 13.2 Data Tables

Prefer a Data Table for:

- dense homogeneous rows;
- data that genuinely shares one row schema;
- bulk balancing/reference datasets;
- deterministic import/export where useful.

Do not use one giant project-wide Data Table for unrelated domains.

Do not encode branching gameplay policy in opaque text columns.

## 13.3 Repository SourceData

Prefer text/CSV/JSON or another deterministic reviewable source representation when:

- IDs/conditions change frequently;
- merge review matters;
- external tools/localization need access;
- the Unreal asset can be generated/imported/validated from source;
- binary-only editing would hide critical production truth.

`SourceData/` does not automatically outrank canonical design documents; it is a production representation of approved authority.

## 13.4 Config

Use config for:

- project/environment settings;
- non-secret defaults;
- tunable values appropriate to configuration scope;
- platform overrides after platform scope exists.

Do not put story progression or per-save world facts in `.ini` files.

---

# 14. Data validation contract

Every scalable authored-data family must eventually expose validation for the mistakes that would be expensive in production.

Project-wide minimum validators should cover, where applicable:

- duplicate semantic IDs;
- missing semantic references;
- missing source owner;
- invalid cross-domain ownership;
- stale completion literals `48/28/30`, old 30-Fault K02, old 13-Fault Drift eligibility;
- missing localization keys/context;
- broken asset references;
- disallowed hard-reference expansion;
- missing migration aliases/tombstones;
- completion registry count mismatch;
- setup/payoff dependency cycles;
- route identity bound only to spline/path;
- Hush paired identity missing or contradictory;
- developer-only asset referenced by Shipping content;
- System IDE fixture/preset referencing retired state.

Validation output must name the semantic item and owning system, not merely an opaque object path.

---

# 15. Asset reference policy

Unreal supports both hard and soft references. Stillring uses them deliberately.

## 15.1 Hard references are acceptable when

- both objects belong to one tightly loaded ownership unit;
- the referenced asset is required whenever the owner loads;
- load/memory coupling is intentional;
- the dependency does not create broad circular loading.

Examples may include:

- an Actor Component's required local presentation component;
- a character's always-loaded core skeletal presentation;
- a small tightly bounded local asset family.

## 15.2 Prefer soft references when

- content belongs to another region/package;
- content is optional;
- a heavy asset should load on demand;
- the reference would otherwise pull an unrelated content tree into memory;
- tooling must inspect definitions without loading all presentation assets.

Use `TSoftObjectPtr`/equivalent Unreal-supported soft references where appropriate.

## 15.3 Asset Manager boundary

Use the Asset Manager when the project benefits from explicit primary-asset discovery/load ownership.

Do not introduce Asset Manager complexity merely to wrap every texture and sound.

Primary assets should correspond to meaningful authored units, not arbitrary file-count inflation.

## 15.4 Persistence boundary

Soft object paths are still **asset references**, not canonical save identity.

A persistent save record must store semantic identity and let the owning system resolve the current representation.

---

# 16. Circular dependency rule

Reject content/code architecture where:

- UI hard-references gameplay owners that then hard-reference UI;
- region assets hard-reference unrelated regions through incidental content;
- Data Assets form cycles that make load order implicit;
- Quest owns World which owns Quest as duplicated persistent truth;
- System IDE code becomes required by runtime gameplay code;
- plugin implementation details leak into canonical domain APIs.

When two domains exchange information, use the directional contract in `docs/140`.

---

# 17. Plugin / framework adoption policy

A plugin being installed, free, popular, or bundled with Unreal is not sufficient reason to adopt it.

## 17.1 Required adoption review

Before a nontrivial plugin/framework becomes a production dependency, record:

1. problem it solves;
2. current Stillring authority affected;
3. smaller native alternative considered;
4. runtime footprint;
5. Editor-only versus Shipping footprint;
6. source availability/debuggability;
7. supported UE5.8 version;
8. licensing/commercial redistribution terms;
9. save/content format lock-in;
10. platform implications;
11. network/telemetry/external-service behavior;
12. upgrade/migration risk;
13. removal/escape strategy;
14. System IDE/testing implications;
15. responsible owner/domain adapter.

## 17.2 Adapter rule

Third-party systems should be isolated behind Stillring-owned interfaces where practical.

Do not let a plugin's object identifiers become canonical save IDs.

Do not let a plugin's quest/dialogue/combat model silently redefine project semantics.

## 17.3 Version pinning

Production plugins must use an explicit reviewed version.

No automatic major/minor update policy is permitted for gameplay-critical dependencies.

A plugin update that changes serialized content, APIs, gameplay semantics, or Shipping footprint is a reviewed production change.

---

# 18. Source control policy

Stillring uses Git for reviewable source and Git LFS for Unreal/source binaries.

The current repository already defines:

### Normal Git

- C++;
- headers;
- `.uproject` / `.uplugin` descriptors;
- config;
- scripts;
- docs;
- text/CSV/JSON structured source data.

### Git LFS

Current `.gitattributes` includes:

- `.uasset`;
- `.umap`;
- `.ubulk`;
- `.uexp`;
- `.blend`;
- `.fbx`;
- `.glb`;
- `.gltf`;
- `.wav`;
- `.flac`;
- `.psd`;
- `.kra`;
- `.exr`;
- `.tif` / `.tiff`.

### Ignored generated/local directories

Current `.gitignore` excludes, among others:

- `Binaries/`;
- `DerivedDataCache/`;
- `Intermediate/`;
- `Saved/`;
- local IDE files;
- packaged/export output;
- crash/temp profiling data.

Derived Data Cache is never canonical source.

---

# 19. Unreal binary collaboration / exclusive-edit policy

LFS solves binary storage, not mergeability.

Some Unreal/DCC assets remain effectively exclusive-edit production surfaces.

## 19.1 High-collision binary classes

Treat these as exclusive-edit by default when multiple people could touch the same asset:

- `.umap` / major Level asset;
- Level Sequence;
- master Skeleton/Control Rig assets;
- complex Animation Blueprint;
- shared master material graphs;
- source DCC scene files;
- high-value hero PSD/Krita/source textures;
- any binary registry asset that cannot be safely merged.

## 19.2 Lock mechanism

Preferred mechanism:

1. use Git LFS locking if the repository/server workflow is verified during Gate 1 bootstrap;
2. if locking is not available/reliable, establish explicit issue/PR ownership before edit;
3. do not rely on "we probably won't collide."

The locking technology remains implementation workflow; the **exclusive-edit requirement** for high-collision assets is the production rule.

## 19.3 World Partition / OFPA caveat

If World Partition later wins the Gate 4 architecture comparison, One File Per Actor may reduce Level-file collision.

That does not pre-authorize World Partition.

Source-control convenience is one comparison input, not the owner of Hush architecture.

---

# 20. Binary asset PR evidence

A PR modifying `.uasset`, `.umap`, DCC, animation, sequence, or other poorly diffable binary files must state:

- exact asset paths changed;
- why each asset changed;
- source/reimport path where applicable;
- semantic IDs affected;
- before/after screenshots or video when visual/spatial behavior matters;
- validation performed;
- save/progression implications if any;
- expected reference/load impact;
- whether any canonical/reviewable source data changed with it;
- whether a binary lock/exclusive-edit claim can be released.

Binary opacity requires **more evidence**, not less.

---

# 21. Branch / PR conventions

One bounded production outcome per branch/PR.

Preferred branch forms:

```text
feat/<issue>-<short-name>
fix/<issue>-<short-name>
docs/<issue>-<short-name>
```

The Studio Handoff Closure may continue using its current stacked `studio-handoff/*` branch sequence while that program remains active.

A PR should identify:

- authority read;
- intended outcome;
- non-goals;
- source/data/binary assets changed;
- validation/evidence;
- runtime claims not proven;
- follow-up dependencies;
- owner-review need, if any.

Do not merge documentation stacks independently when their base authority is incompatible.

---

# 22. Build configuration policy

Epic's UE5.8 build configurations distinguish debugging, development, test, and shipping behavior.

Stillring uses that distinction deliberately.

## 22.1 Development Editor

Primary everyday authoring/debug environment.

May include:

- System IDE;
- developer console commands;
- verbose diagnostics;
- fixture authoring;
- validation tools;
- capture/promote surfaces;
- Editor-only tooling.

## 22.2 Development Game

Packaged/runtime development build used for behavior outside the Editor.

May include approved development diagnostics and System IDE where the milestone requires it.

Must still label development-only state clearly.

## 22.3 Test

Use where a near-Shipping optimized build with selected diagnostics/profiling is useful.

Do not treat Test as retail.

## 22.4 Shipping

Retail boundary.

Shipping must exclude or hard-disable:

- System IDE modules/UI;
- unrestricted developer console/state mutation;
- test fixtures that expose privileged mutation surfaces;
- editor-only modules/plugins;
- remote debug listeners;
- local agent control protocols;
- Claude/model APIs;
- API keys/secrets;
- debug save corruption commands;
- developer-only content that retail assets depend on accidentally.

Shipping inclusion is proven later by packaged-build inspection/testing; it is not considered proven by this document.

---

# 23. Development-tool module dependency direction

Player-facing runtime modules must not require a System IDE/developer module in order to function.

Correct dependency direction:

```text
runtime gameplay service
        ^
        |
System IDE / test tooling consumes and requests through runtime API
```

Forbidden:

```text
runtime gameplay service
        |
        v
System IDE helper required for normal gameplay
```

Developer tooling may register adapters for gameplay owners.

Gameplay owners must remain fully functional when those adapters are absent.

---

# 24. Enhanced Input policy

Stillring uses Unreal **Enhanced Input**.

Rules:

- gameplay uses named Input Actions;
- contexts are explicit;
- physical keys/buttons are mappings, not gameplay semantics;
- controller is the primary design target;
- keyboard/mouse remains first-class;
- remapping/accessibility belongs to Profile/Settings authority;
- gameplay services receive action intent rather than polling hardcoded keys;
- UI input/focus behavior remains separate from gameplay action ownership.

Do not encode `SpaceBar means Jump` as a gameplay rule.

---

# 25. Localization-ready text pipeline

Unreal user-facing localized text uses `FText` semantics.

## 25.1 Type boundary

Use:

- `FText` for player-facing localizable text;
- `FName`/typed semantic IDs for identity;
- `FString` for logs, paths, non-localized processing, and external interfaces where appropriate.

Do not use display text as identity.

Avoid converting `FText` to `FString` and back when localization history still matters.

## 25.2 Stable localization identity

Every production string must have deterministic localization identity through:

- namespace/key;
- String Table key;
- or another Unreal localization-supported stable source identity.

Do not depend on auto-generated unstable keys from repeated table imports.

## 25.3 String Tables

String Tables are appropriate for:

- reusable UI labels;
- system/common terminology;
- repeated controlled phrases;
- content families where centralized review helps.

Keep tables granular enough that one team does not create one giant conflict domain.

## 25.4 Narrative text

Dialogue/records/subtitles should preserve:

- semantic line/entry ID;
- speaker;
- scene/state context;
- branch conditions;
- spoiler status;
- variables/placeholders;
- performance/pronunciation notes where applicable;
- localization comments/context.

No production dialogue should be hardcoded inside gameplay branching logic.

## 25.5 Formatting

Use culture-aware `FText` formatting for numbers and variables where player-facing.

Avoid sentence fragments concatenated in code when grammar can vary by language.

---

# 26. Logging standard

Logging exists to explain system decisions and reproduce defects.

## 26.1 Log categories

Use project/domain categories such as:

```text
LogStillringCore
LogStillringLocomotion
LogStillringCamera
LogStillringCombat
LogStillringWorld
LogStillringHush
LogStillringQuest
LogStillringSave
LogStillringCompletion
LogStillringSetupPayoff
LogStillringSkiff
LogStillringSystemIDE
```

Exact category decomposition may evolve with modules.

Do not dump all project diagnostics into `LogTemp`.

## 26.2 Required high-value context

Important warnings/errors should include, where relevant:

- semantic ID;
- owner/system;
- map/region/checkpoint;
- build/commit;
- source predicate/state reason;
- expected versus actual state;
- migration/schema version;
- fixture/preset ID;
- safe error classification.

Avoid logging personal secrets or platform credentials.

---

# 27. Capture / evidence / provenance standard

Every meaningful runtime evidence package must be traceable to a specific build and semantic fixture.

## 27.1 Evidence ID

Use a human-readable form equivalent to:

```text
EVID-<YYYYMMDD>-<DOMAIN>-<FIXTURE>-<SHORTSHA>
```

Example:

```text
EVID-20260906-LOCOMOTION-flat_stop-1a2b3c4
```

This is an evidence label, not a gameplay semantic ID.

## 27.2 Minimum metadata

Capture where applicable:

- evidence schema version;
- repository commit SHA;
- UE version;
- build configuration;
- platform/OS;
- actual hardware used;
- map/region/checkpoint;
- player transform if spatially relevant;
- fixture/preset ID;
- system/workbench;
- canonical values versus session overrides;
- source semantic facts involved;
- validation result;
- screenshot/video/log/stat artifact paths;
- tester/automation route;
- known limitation;
- associated issue/PR.

## 27.3 Canonical versus override provenance

System IDE and captures must distinguish:

1. repository-backed canonical value;
2. session override;
3. dirty/staged change;
4. promoted change.

A screenshot of a tuned value with no provenance is not enough to make that value production authority.

---

# 28. Test and fixture naming

## 28.1 Semantic fixture IDs

Named developer presets/fixtures use stable semantic IDs such as:

```text
fixture.brindle.pre_crisis.clean
fixture.rootmere.cathedral.pre_boss
fixture.hush.paired_save.baseline
fixture.completion.missing_item.audit
fixture.null_meridian.story_minimum
```

Existing approved preset names remain valid where already defined.

## 28.2 Automation names

C++/Automation tests should use discoverable hierarchical names:

```text
Stillring.<Domain>.<Feature>.<Case>
```

Examples:

```text
Stillring.Save.Migration.RenameAliasIdempotent
Stillring.Completion.Rounding.IncompleteCapsAt99_9
Stillring.SetupPayoff.S01.CommitIdempotent
Stillring.Skiff.RouteGraph.RejectsSplinePathIdentity
```

Examples are test-name demonstrations, not proof those tests exist.

## 28.3 Fixture rule

A fixture must declare:

- purpose;
- source semantic facts it establishes;
- facts intentionally absent;
- expected checkpoint/layer;
- expected result;
- canonical authority version;
- whether it is valid for save/load.

No `debug_save_7` production infrastructure.

---

# 29. Save schema / migration boundaries

Save authority remains in the Save Coordinator/schema documents.

Technical production rules:

- schema version exists from the first real save format;
- persistent domains serialize semantic records, not Actor graphs;
- source owners restore before derived consumers reconcile;
- completion percentage is never authoritative cached truth;
- Hush save occurs only at save-stable semantic boundaries;
- migration is explicit and idempotent;
- semantic rename/split/merge/retirement has an authored rule;
- unknown/orphaned records are not silently discarded;
- display strings and object paths are not migration keys.

Project custom-version usage should be selected during implementation consistent with UE5.8 serialization practices.

---

# 30. Hush production-representation gate

`SH-TECH-009` remains runtime-gated on purpose.

Do **not** lock the production representation in this document.

Gate 4 must compare at least:

## Candidate A

**World Partition + Runtime Data Layers**

Potential strengths to evaluate:

- paired presentation organization;
- OFPA/source-control behavior;
- streaming support;
- authoring scale.

Risks to evaluate:

- accidental semantic coupling to Data Layer state;
- complexity for compact spaces;
- paired-identity authoring cost;
- streaming/collision transition behavior.

## Candidate B

**Explicit non-World-Partition level/Actor layering**

Potential strengths:

- explicit compact authored spaces;
- lower framework overhead where streaming is unnecessary;
- direct control over paired representation.

Risks:

- source-control overlap;
- manual organization burden;
- streaming/scalability cost later.

## Selection evidence

Compare with the same representative paired area on:

- semantic identity clarity;
- authoring clarity;
- source-control collision;
- collision/transition reliability;
- save/reload reconstruction;
- performance/memory;
- streaming behavior;
- IDE inspection/reset;
- environment-production burden;
- Line Skiff implications where relevant.

The winner must still obey:

> Data-layer/level/Actor representation never owns Waking/Hush semantic truth.

---

# 31. Performance-budget gate

`SH-TECH-010` remains runtime-gated.

Concrete budgets require:

1. target-PC baseline (`SH-PROD-001` / `UQ-F001` owner decision);
2. selected platform scope where platform-specific;
3. representative vertical-slice content;
4. real profiling.

Do not invent:

- triangle budgets;
- material slot budgets;
- draw-call caps;
- texture-memory caps;
- VFX particle caps;
- animation CPU caps;
- streaming budgets;
- Hush stall budgets;
- frame-time targets

as authoritative numbers before evidence exists.

## 31.1 Metrics that must eventually be tracked

The production pipeline must later record at least:

- frame time;
- game thread;
- render thread;
- GPU;
- memory growth/peaks;
- streaming stalls;
- Hush transition cost;
- animation cost;
- VFX cost;
- dynamic-light/shadow cost;
- shader/material complexity;
- package/build size trend;
- Skiff-speed streaming stability.

Actual hardware used must always accompany a performance result.

---

# 32. Platform-conditional code/data boundary

Stillring remains PC-first until the owner selects launch-platform scope.

Therefore:

- do not bake console certification assumptions into core gameplay yet;
- do not make PC-only APIs the canonical gameplay abstraction;
- isolate platform services behind project-owned interfaces when they appear;
- controller and keyboard/mouse remain supported at the input abstraction;
- save paths/storage specifics remain platform implementation detail under Save authority;
- platform-specific config belongs in platform-scoped config/data, not scattered `#if` behavior policy;
- platform selection does not reopen game semantics.

---

# 33. System IDE production architecture

The System IDE contract is mandatory.

Each major system that requires repeated tuning, authoring, state inspection, reproduction, or validation must register a purpose-built workbench into one shared developer shell.

Minimum common capabilities:

- Inspect;
- Author/Tune where safe;
- Exercise;
- Validate;
- Capture/Promote.

## 33.1 Shared shell implementation choice

UMG, Slate, or hybrid remains studio choice during Issue #58 implementation.

Acceptance is semantic:

- controller/keyboard usable;
- second workbench registers without new architecture;
- reads authoritative state;
- mutations go through owner APIs;
- provenance visible;
- Shipping exclusion proven.

## 33.2 No external service dependency

The IDE may support local Claude-assisted development through deterministic local interfaces.

Retail Stillring must have no AI/model/API dependency.

No public network listener is required or allowed by default.

---

# 34. Development content isolation

Development-only content belongs under clear development scope such as:

```text
/Game/Stillring/Developer/
```

Production validation must detect if Shipping-required assets reference Developer-only assets.

Developer content may include:

- graybox test maps;
- fixture assets;
- target arrangements;
- test presets;
- System IDE visual support;
- placeholder test-only VFX/audio;
- developer instrumentation assets.

A fixture may represent canonical state without pretending its geometry/art is shipping content.

---

# 35. Import/source asset policy

For imported production assets:

- keep original source file where the pipeline requires future re-export;
- record intended Unreal target asset;
- preserve unit/scale/orientation settings in discipline documentation;
- avoid destructive one-off editor edits that cannot be reconstructed when source reimports;
- use deterministic naming;
- retain license/provenance for third-party production tools/source materials;
- never import ripped/extracted commercial-game assets.

Source art ownership/reuse rules remain subordinate to the Art/Animation/Audio bibles.

---

# 36. Redirector / rename hygiene

Asset moves/renames are normal during production but must not accumulate invisible technical debt.

When moving/renaming production assets:

- perform moves through Unreal-aware tooling;
- fix redirectors/references during controlled cleanup;
- validate important maps/content afterward;
- do not manually move `.uasset` files on disk as a routine workflow;
- do not change semantic IDs simply to match new package names.

Large rename waves should be isolated from unrelated feature work.

---

# 37. Generated content and caches

Generated outputs are not repository authority unless an explicit pipeline says otherwise.

Do not commit:

- Derived Data Cache;
- local `Binaries/`;
- `Intermediate/`;
- `Saved/`;
- local shader debug/cache output;
- crash dumps;
- ad hoc packaged builds;
- personal profiling folders.

Build artifacts used as accepted evidence should be stored in the project evidence/artifact mechanism defined later, not mixed into source directories.

---

# 38. Reproducible build / validation entry points

Gate 1 must establish command-line reproducibility.

A production engineer/agent should eventually be able to invoke documented commands/scripts for at least:

- project generation where needed;
- development build;
- project/editor load smoke;
- fast Automation tests;
- content/data validation;
- packaged Development/Test/Shipping builds at later gates;
- targeted fixture tests;
- fresh-checkout verification.

Exact command scripts belong to implementation once `Stillring.uproject` exists.

Do not make manual Editor clicking the only path to validate a PR.

---

# 39. Validation failure policy

Automated validation failures must be actionable.

A failure should report:

- validator name;
- semantic item;
- source owner;
- asset/source path for navigation;
- expected condition;
- actual condition;
- remediation class;
- whether it blocks cook/build/merge/production.

Do not normalize hundreds of ignored warnings until real failures disappear in noise.

Warnings may exist, but accepted warning classes must be intentional and documented.

---

# 40. Secrets / networking / telemetry boundary

Do not commit or ship:

- API keys;
- access tokens;
- private credentials;
- external model keys;
- private signing keys;
- unrestricted debug endpoints.

Stillring is an authored single-player game.

No gameplay feature requires a backend, model API, or live telemetry service by default.

If future publishing/platform work introduces online services, they require explicit product/technical authority and privacy/security review.

---

# 41. Clean-room / dependency provenance

Technical production must remain inside the IP firewall.

Forbidden inputs include:

- commercial-game decompiled code;
- leaked SDK/source;
- ripped maps/assets;
- extracted animations/audio;
- ROM-derived geometry/data;
- copied proprietary shaders;
- unauthorized proprietary plugins.

Open-source or commercial middleware may be used only under valid licensing and the adoption review in this document.

---

# 42. Technical change control

A technical proposal should be classified before implementation.

## LOCKED — implement, do not redefine

- Unreal Engine 5.8 baseline;
- C++-first gameplay/state authority;
- thin Blueprint presentation boundary;
- one authoritative writer per canonical fact;
- semantic persistence identity independent of Actor/package paths;
- Save Coordinator orchestrates but does not own all gameplay truth;
- System IDE architecture requirement;
- developer tooling absent/hard-disabled in Shipping;
- Enhanced Input / named actions;
- repository authority over binary convenience;
- no external AI/API dependency in retail;
- current completion constants;
- Hush semantic authority independent of representation.

## STUDIO CHOICE WITHIN BOUNDS

- exact C++ class names;
- component/service lifetime pattern;
- module decomposition;
- UMG vs Slate vs hybrid System IDE shell;
- exact typed semantic-ID wrapper;
- Data Asset versus Data Table choice for a bounded content family when semantics are preserved;
- hard/soft reference implementation inside this policy;
- command-line script language;
- local editor utility design;
- exact Git LFS lock tooling if exclusive-edit behavior is preserved;
- exact log category granularity;
- exact capture file format.

## PROTOTYPE / RUNTIME EVIDENCE

- Hush production representation;
- exact movement/camera/combat tuning;
- exact world/module scale metrics;
- Skiff handling/streaming details;
- runtime loading/chunking strategy;
- performance budgets;
- exact save I/O mechanics;
- editor/runtime tool technology where acceptance depends on actual use.

## OWNER DECISION REQUIRED

- target-PC performance baseline;
- launch-platform scope;
- material change to locked product/gameplay/story/art scope;
- engine migration that materially changes production/product risk;
- new online/service dependency affecting product behavior/privacy/cost;
- major external framework adoption that would redefine locked game semantics rather than merely implement them.

---

# 43. Technical handoff acceptance rules

A technical-production package is acceptable when an external studio can answer:

1. Which engine/version do we use?
2. Where does authoritative gameplay live?
3. What is Blueprint allowed to own?
4. How is canonical state ownership divided?
5. What is a valid persistent ID?
6. How are data definitions represented?
7. How are assets named and organized?
8. Which binary types use LFS?
9. Which assets require exclusive editing?
10. What evidence accompanies binary PRs?
11. How do hard/soft references differ in project policy?
12. How do we adopt a plugin/framework?
13. How does retail exclude development tooling?
14. How does player-facing text remain localization-ready?
15. How are fixtures, logs, and evidence named?
16. What is currently runtime-proven?
17. Which Hush architecture question remains open?
18. Why are final performance budgets not written yet?
19. What may engineering decide without owner approval?
20. What changes must be escalated?

If those answers still depend on chat history, the technical handoff is not closed.

---

# 44. Research basis

This document reconciles existing Stillring authority with current UE5.8/Git production behavior.

Fresh references reviewed on 2026-09-06 include:

- Epic Games — **Build Configurations Reference for Unreal Engine 5.8**;
- Epic Games — **Asset Management in Unreal Engine 5.8**;
- Epic Games — **UPrimaryDataAsset** API reference;
- Epic Games — **Object Pointers in Unreal Engine 5.8**;
- Epic Games — **Referencing Assets in Unreal Engine 5.8**;
- Epic Games — **Gameplay Tags in Unreal Engine 5.8**;
- Epic Games — **Text Localization in Unreal Engine 5.8**;
- Epic Games — **String Tables in Unreal Engine 5.8**;
- Epic Games — **World Partition / One File Per Actor in Unreal Engine 5.8**;
- GitHub Docs — **Managing large files / Git Large File Storage**.

These references inform engine/tool behavior only.

Stillring's gameplay semantics, ownership contracts, content rules, Hush rules, completion rules, System IDE requirements, and decision rights remain original project authority.

---

# 45. Explicit non-claims

This document does **not** prove:

- a UE5.8 build works;
- any module structure compiles;
- LFS file locking is currently configured/verified;
- System IDE stripping works in Shipping;
- Asset Manager is the final representation for every candidate content family;
- Hush uses World Partition/Data Layers;
- Hush uses explicit layering;
- save migration works;
- localization gather/cook works;
- any automation test exists;
- any packaged build exists;
- any performance target is met.

Those claims require implementation evidence.

---

# 46. Next bounded technical work after this Bible

The next technical handoff step should not be UE implementation.

The immediate follow-on is:

> **Technical Production Written-Handoff Acceptance Audit**

It should reconcile `SH-TECH-001` through `SH-TECH-010`, mark written authority separately from runtime proof, and leave Hush representation/performance budgets visibly runtime-gated.

After the technical discipline is closed on paper, the Studio Handoff Closure sequence proceeds to:

> **Production Dependency / Discipline Matrix**

unless a higher-authority owner decision changes the documentation sequence.

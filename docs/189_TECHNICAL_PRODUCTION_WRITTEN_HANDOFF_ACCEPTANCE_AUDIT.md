# 189 — Technical Production Written-Handoff Acceptance Audit

**Status:** CURRENT / STUDIO-HANDOFF TECHNICAL WRITTEN-AUTHORITY AUDIT  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap register:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance checklist:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Primary authority:** `docs/188_TECHNICAL_PRODUCTION_BIBLE.md`  
**Runtime boundary:** documentation only; no UE5.8 implementation/testing/runtime proof authorized

---

# 1. Purpose

This audit answers one bounded question:

> **Does the repository now give an external studio enough technical-production authority to operate without inventing naming, data, binary/source-control, plugin, build-stripping, localization, reference, and provenance policy?**

It does **not** answer whether those policies are implemented or proven in UE5.8.

`docs/152` remains the global gap register. For the current scoped status of `SH-TECH-001` through `SH-TECH-010`, use this audit together with `docs/188`.

---

# 2. Status vocabulary

This audit uses the governing `docs/153` terms:

- **PASS** — written repository authority is sufficient for studio execution at this stage;
- **PARTIAL** — additional written authority is still required;
- **TBD OWNER** — a real owner/product choice remains unresolved;
- **RUNTIME-GATED** — paper authority is intentionally complete enough, but a production choice or acceptance value requires implementation/runtime evidence;
- **MISSING** — the required production authority does not exist.

A written `PASS` does not claim implementation proof.

---

# 3. Executive result

| Result | Count |
|---|---:|
| PASS — written authority | **8** |
| PARTIAL | **0** |
| RUNTIME-GATED | **2** |
| MISSING | **0** |

The two runtime-gated rows are deliberate:

1. `SH-TECH-009` — final Hush production representation;
2. `SH-TECH-010` — concrete performance budgets.

Neither should be faked on paper.

---

# 4. Gap-by-gap reconciliation

## SH-TECH-001 — naming / folder / package conventions

**Original gap:** naming/folder/package conventions.

**Current status:** **PASS — WRITTEN AUTHORITY**

Current authority:

- `docs/188` §§7–10;
- C++ Unreal naming conventions;
- Stillring asset prefix table;
- `/Game/Stillring/` content-root rule;
- domain-first source organization;
- shared-versus-regional package guidance;
- temporary/developer-content isolation;
- redirector/rename hygiene.

Closed production ambiguity:

- studio no longer needs to invent where major asset/code classes belong;
- prefixes are explicit enough for search/review/tooling;
- asset/package name is explicitly separated from semantic identity.

Still runtime/production-dependent:

- exact module count;
- exact final subfolder decomposition as real assets appear.

Those are bounded studio choices, not handoff gaps.

---

## SH-TECH-002 — content / data authoring convention

**Original gap:** DataAssets/tables/semantic registries/validation boundaries by system.

**Current status:** **PASS — WRITTEN AUTHORITY**

Current authority:

- `docs/188` §§11–14;
- `docs/04` data-driven-content boundary;
- `docs/139` system ownership;
- `docs/140` directional contracts;
- system-specific authoring authority for Setup/Payoff, Completion, routes, Save, etc.

The repository now distinguishes:

- stable semantic identity;
- Primary Data Asset candidate usage;
- Data Table candidate usage;
- repository `SourceData/` usage;
- config usage;
- Gameplay Tag categorization versus identity;
- project-wide validation expectations.

No single representation is mandated for every system.

That is intentional: the studio may choose the smallest transparent representation that preserves the locked semantic contract.

Implementation-specific class fields remain correctly open under `UQ-SP-001`, `UQ-CMP-001`, `UQ-G3-002`, `UQ-SKIFF-002`, and related rows.

---

## SH-TECH-003 — plugin / framework adoption process

**Original gap:** explicit review criteria and block against assuming availability equals authority.

**Current status:** **PASS — WRITTEN AUTHORITY**

Current authority:

- `docs/188` §17;
- `docs/04` and `CLAUDE.md` non-cargo-cult Unreal policy.

Required review now covers:

- actual project problem;
- native/smaller alternative;
- engine/version support;
- license/redistribution;
- source/debuggability;
- Shipping/runtime footprint;
- save/content lock-in;
- platform/network/service implications;
- upgrade risk;
- removal/escape plan;
- System IDE/testing implications;
- project-owned adapter boundary.

Stillring explicitly does not adopt GAS, World Partition, Runtime Data Layers, Nanite, Lumen, MetaHuman, PCG, Mass, or third-party quest/save/dialogue/combat frameworks by default.

---

## SH-TECH-004 — source-control / LFS binary workflow

**Original gap:** Unreal binary list/review conventions and ownership/locking strategy.

**Current status:** **PASS — WRITTEN AUTHORITY / RUNTIME WORKFLOW PROOF STILL REQUIRED**

Current authority:

- repository `.gitattributes` already tracks Unreal/source binaries through Git LFS;
- repository `.gitignore` already excludes generated Unreal/cache/build directories;
- `docs/188` §§18–21 defines binary collaboration, exclusive-edit classes, locking fallback, binary PR evidence, and branch/PR conventions.

The production rule is now explicit:

> LFS stores binaries; it does not make them mergeable.

High-collision binaries use exclusive-edit discipline.

Preferred locking is Git LFS locking **if verified** at Gate 1. If that workflow is not available/reliable, issue/PR ownership provides the fallback.

`UQ-G1-004` remains valid because the actual fresh-checkout/LFS/locking workflow still needs runtime/bootstrap proof.

That evidence requirement does not make the written workflow missing.

---

## SH-TECH-005 — build configuration / dev-tool stripping

**Original gap:** Editor/Development/Test/Shipping behavior.

**Current status:** **PASS — WRITTEN AUTHORITY / SHIPPING PROOF LATER**

Current authority:

- `docs/188` §§22–23;
- `docs/16` security/release boundary;
- `docs/21` retail boundary;
- `CLAUDE.md` retail boundary.

The repository now defines:

- Development Editor role;
- Development Game role;
- Test role;
- Shipping retail boundary;
- one-way dependency from developer tools toward runtime services;
- no gameplay dependency on System IDE modules;
- no public debug listener/model/API/secrets in retail;
- developer-only content dependency rejection.

`UQ-IDE-005` remains a future packaged-build proof:

> Shipping exclusion is locked in design but not proven until a Shipping build exists.

---

## SH-TECH-006 — logging / capture / provenance

**Original gap:** common fixture/capture names, evidence packages, System IDE promotion records.

**Current status:** **PASS — WRITTEN AUTHORITY**

Current authority:

- `docs/188` §§26–28;
- `docs/16` observation capture and machine-QA contract;
- `docs/21` Capture/Promote contract;
- `docs/141` shared shell provenance/capture rules;
- `docs/142` evidence-state taxonomy.

The repository now defines:

- project/domain log-category convention;
- high-value semantic log context;
- evidence ID form;
- minimum capture metadata;
- canonical/session-override/dirty/promoted provenance distinctions;
- semantic fixture ID form;
- Automation test naming hierarchy;
- fixture declaration requirements.

Exact capture file serialization remains studio choice within bounds.

---

## SH-TECH-007 — localization-ready text pipeline

**Original gap:** stable IDs/context/variables; no production dialogue hidden in gameplay logic.

**Current status:** **PASS — WRITTEN AUTHORITY**

Current authority:

- `docs/188` §25;
- Narrative Production Package localization/context authority;
- UI/UX subtitle/caption/text authority;
- Audio/VO performance/localization authority.

The technical pipeline now requires:

- `FText` for player-facing localizable text;
- semantic IDs separate from display text;
- deterministic localization identity;
- String Tables where central reuse helps;
- stable dialogue/record line IDs and context;
- variable/placeholder/context metadata;
- no production dialogue hardcoded in gameplay branch logic;
- no unsafe sentence-fragment concatenation as the normal pipeline.

Language list remains a product/localization-scope decision, not a reason to postpone localization-ready authoring.

---

## SH-TECH-008 — asset-reference / persistence rule consolidation

**Original gap:** no display/path/runtime IDs where semantic identity is required.

**Current status:** **PASS — WRITTEN AUTHORITY**

Current authority:

- `docs/188` §§11, 15–16, 29;
- `docs/139` ownership map;
- `docs/140` cross-system contracts;
- Save/World-State authority.

The project now explicitly differentiates:

- hard references;
- soft references;
- Asset Manager/Primary Asset usage;
- canonical semantic identity;
- persistent save identity;
- asset/package/Actor paths.

Key locked rule:

> A soft object path is still an asset reference, not a valid canonical save identity.

Circular/cross-region hard-reference expansion and developer-module reverse dependencies are also explicitly rejected.

---

## SH-TECH-009 — Hush production representation

**Original gap:** select a production representation after comparing credible runtime approaches.

**Current status:** **RUNTIME-GATED — CORRECTLY NOT SELECTED**

Current authority:

- `docs/188` §30;
- `docs/04` Hush architecture candidates;
- `docs/145` Gate 4 comparison;
- `docs/144` `UQ-G4-001` through `UQ-G4-005`;
- Hush semantic authority docs 70–80.

The required comparison is now production-operational:

- Candidate A: World Partition + Runtime Data Layers;
- Candidate B: explicit non-World-Partition level/Actor layering;
- compare semantic identity clarity, authoring, source-control collision, collision/transition reliability, save/reload, performance/memory, streaming, IDE usability, content burden, and Skiff implications.

The representation cannot be selected honestly without a UE5.8 paired-area prototype.

That is not missing documentation.

It is a deliberately preserved architecture evidence gate.

---

## SH-TECH-010 — concrete performance budgets

**Original gap:** measured technical budgets require target platform/hardware and representative runtime evidence.

**Current status:** **RUNTIME-GATED — OWNER PRODUCT INPUT PREREQUISITE**

Current authority:

- `docs/188` §31;
- `docs/145` performance evidence rules;
- `docs/142` performance proof vocabulary;
- `SH-PROD-001` target-PC decision;
- `UQ-F001` target-PC/platform owner queue.

The repository now explicitly states what must eventually be measured:

- frame time;
- game/render threads;
- GPU;
- memory;
- streaming stalls;
- Hush transition cost;
- animation/VFX/lighting/shader cost;
- build/package-size trend;
- Skiff-speed streaming.

What remains intentionally absent are fake universal numbers.

Concrete budgets require:

1. target-PC owner decision;
2. selected platform context where needed;
3. representative content;
4. profiling evidence.

Therefore this row must not be marked `PASS` as a concrete-budget claim and must not be marked `MISSING` as if guessing numbers would improve the handoff.

---

# 5. `docs/153` Technical Production checklist audit

| Technical acceptance row | Current status | Evidence |
|---|---|---|
| Technical Production Bible exists | **PASS** | `docs/188` |
| UE5.8 authority explicit | **PASS** | `docs/04`, `CLAUDE.md`, `docs/188` |
| C++-first / thin Blueprint boundary | **PASS** | `CLAUDE.md`, `docs/04`, `docs/188` |
| state ownership map linked | **PASS** | `docs/139`, `docs/188` |
| stable semantic-ID policy linked | **PASS** | Save/Completion authorities, `docs/139`, `docs/188` |
| save/version/migration policy linked | **PASS** | Save docs, `docs/104`, `docs/188` |
| System IDE contract linked/required | **PASS** | `docs/21`, `docs/141`, `docs/188` |
| naming conventions exist | **PASS** | `docs/188` §§8–10 |
| folder/package conventions exist | **PASS** | `docs/188` §§7–10 |
| source-control/LFS workflow exists | **PASS — written** | `.gitattributes`, `.gitignore`, `docs/188` §§18–21 |
| asset-reference rules exist | **PASS** | `docs/188` §§15–16 |
| data-authoring conventions exist | **PASS** | `docs/188` §§11–14 |
| plugin/framework adoption process exists | **PASS** | `docs/188` §17 |
| build config/dev-tool stripping rules exist | **PASS — written** | `docs/188` §§22–23 |
| localization-ready text policy exists | **PASS** | `docs/188` §25 |
| logging/capture/provenance standard exists | **PASS** | `docs/188` §§26–28 |
| implementation decision rights explicit | **PASS** | `docs/188` §42 |
| unresolved production architecture choices clearly gated | **PASS** | `docs/188` §§30–31 |

The Technical Production section of `docs/153` is now fully answerable from repository authority.

That does not mean all runtime-gated technical decisions are resolved.

---

# 6. Current technical decision rights

## LOCKED

External engineering may not redefine:

- UE5.8 baseline without approved migration;
- C++-first gameplay/state authority;
- thin Blueprint boundary;
- source ownership / one-writer rule;
- stable semantic identity independent of Actor/package paths;
- Save Coordinator ownership boundary;
- System IDE obligation;
- Enhanced Input named-action principle;
- developer-tool retail exclusion;
- no external AI/API dependency in retail;
- Hush semantic authority independent of Unreal representation;
- existing completion constants and migration rules.

## STUDIO CHOICE WITHIN BOUNDS

Engineering may choose without returning ordinary implementation details to the owner:

- exact class names;
- object lifetime/container mechanisms;
- module boundaries;
- UMG/Slate/hybrid developer shell;
- typed ID wrapper;
- bounded Data Asset/Data Table/SourceData choice;
- log/capture serialization details;
- exact script language for build tooling;
- plugin adapter implementation;
- locking tool implementation if exclusive-edit rules remain satisfied.

## RUNTIME / PROTOTYPE DECISION

Engineering must bring evidence before locking:

- Hush production representation;
- performance budgets;
- final module/world scale numbers;
- Skiff runtime/streaming implementation;
- save I/O mechanics;
- high-impact handling/timing/tuning.

## OWNER DECISION

Return to the owner for:

- target-PC baseline;
- launch-platform scope;
- material game/product/canon change;
- production-significant engine migration;
- new online/service dependency;
- framework adoption that would redefine gameplay/product semantics rather than merely implement current authority.

---

# 7. Runtime proof explicitly still absent

This audit does not claim:

- fresh checkout builds UE5.8;
- LFS binary locking works on the active repo;
- a Development/Test/Shipping packaging pipeline exists;
- System IDE code is stripped from Shipping;
- semantic validators run;
- Asset Manager registry exists;
- localization gather/cook works;
- save migration works;
- Hush architecture has been selected;
- performance targets exist or are met;
- any named fixture/test currently executes.

Those claims remain tracked by Issues #4/#5/#58, `docs/142`, `docs/144`, and `docs/145`.

---

# 8. Hard rejection conditions for technical production

Reject a future technical implementation if:

- critical gameplay/state truth migrates into opaque Blueprint-only graphs;
- a persistent save record uses Actor/package/spline path as canonical identity;
- a plugin's IDs become project persistence authority without explicit project semantic mapping;
- Hush semantic truth becomes Data Layer load state;
- World Partition is adopted solely because it is convenient for OFPA/source control;
- one project-wide giant Data Table becomes an unreviewable rules engine;
- UI or Animation Blueprint owns durable gameplay state;
- System IDE bypasses owner APIs with a hidden debug state model;
- Shipping requires the System IDE/developer module;
- Shipping contains external model/API dependencies or secrets;
- production dialogue is embedded as hardcoded branch text in gameplay logic;
- binary assets change with no enumerated evidence;
- semantic IDs are renamed to match asset/package reorganizations with no migration;
- performance budgets are copied from generic Unreal guidance instead of measured against target hardware/content;
- the first Hush prototype is promoted to production without the required comparison.

---

# 9. Research reconciliation

The Technical Bible's external-engine assumptions were checked against current Unreal Engine 5.8 and GitHub documentation on:

- UE build configurations;
- Primary Assets / `UPrimaryDataAsset` / Asset Manager;
- hard versus soft object references;
- Gameplay Tags;
- `FText` localization and String Tables;
- World Partition / One File Per Actor;
- Git Large File Storage.

These references do not override Stillring authority.

They confirm that the production conventions use supported engine/source-control concepts rather than imaginary capabilities.

---

# 10. Technical workstream conclusion

The Technical Production workstream now has sufficient **written production authority** for an external studio to begin technical planning without inventing ordinary conventions.

Scoped result:

> **8 PASS / 0 PARTIAL / 2 RUNTIME-GATED / 0 MISSING**

The remaining technical unknowns are exactly where they should be:

- **Hush representation:** compare prototypes later;
- **performance budgets:** choose target hardware and measure representative runtime later.

No additional broad technical-policy document is required before moving to the next Studio Handoff Closure discipline.

---

# 11. Next Studio Handoff Closure step

Per `docs/151` / `docs/152`, the next bounded production-documentation package should be:

> **Production Dependency / Discipline Matrix**

That matrix must use the completed Art, Animation, UI/UX, Audio/VO, Narrative, World/Content, Product/Decision-Rights, and Technical packages to identify:

- upstream blockers;
- safe parallel work;
- artifact handoffs;
- owner/runtime gates;
- region-pod sequencing dependencies;
- outsourcing-safe packages;
- work that must not begin before another discipline proves a prerequisite.

It must not invent dates, headcount, dollar budgets, or runtime evidence.

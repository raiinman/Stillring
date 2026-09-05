# 77 — Gate 4 Hush / World-Layer System IDE Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #8 — Hush / World-Layer System IDE inspect/force/reset/validate/capture contract

## Decision

Gate 4's Hush prototype is incomplete without one integrated **Hush / World-Layer System IDE** registered in Stillring's shared development shell. The workbench must expose semantic truth and engine representation side-by-side, exercise every reviewed seam state safely, validate divergence automatically, and capture deterministic evidence without creating a second rules engine.

Core philosophy:

> **Show the truth, show the expression, and make disagreement impossible to miss.**

`docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` remains parent authority. This decision defines the Hush-specific workbench required to satisfy it.

## Workbench scope

The Hush / World-Layer IDE owns development surfaces for:
- semantic Waking/Hush state;
- seam request/preparation/commit/presentation state;
- paired semantic entity identity;
- loaded/presented/physical expression ownership;
- cross-layer puzzle facts/causality;
- combat/NPC/interactable continuity through a seam;
- Hush-specific save-stability/reload evidence;
- Hush visual/audio/accessibility presentation state;
- representation-candidate diagnostics needed by Decision #9.

It does **not** replace:
- Locomotion IDE;
- Camera / Targeting IDE;
- Combat / Encounter IDE;
- Tool / Puzzle IDE;
- Quest / World-State IDE;
- Save / Persistence IDE.

Instead it cross-links their relevant state while leaving authoritative mutations with the owning gameplay service.

## One semantic source, many debug views

The workbench reads authoritative services and presentation adapters; it does not maintain its own shadow `IsHush` Boolean, duplicate pair table, duplicate puzzle facts, or alternate collision state.

Any forced development action must call the same reviewed semantic services used by normal gameplay where practical.

If a raw engine-level override is needed to create a failure fixture, it must be visibly labeled **FAULT INJECTION / NON-CANONICAL** and must never be promotable as gameplay authority.

## INSPECT — global state

The top-level Hush panel must expose at minimum:
- `ActiveSemanticLayer`;
- current seam transition phase;
- transition ID/source/destination;
- transition request source;
- eligibility result and rejection reason;
- preparation/readiness gates;
- semantic commit frame/time;
- save-stable yes/no + blocker;
- active authored Hush presentation profile;
- Reduced Hush Effects state;
- current representation strategy identifier for the prototype;
- semantic↔representation convergence status.

A developer should be able to answer in seconds:
> “What reality does gameplay think is active, what is Unreal currently presenting/loading, and are those two facts consistent?”

## INSPECT — selected semantic entity

Selecting/looking at a meaningful entity should expose:
- stable semantic entity ID;
- identity/pairing class;
- Waking expression ref/state;
- Hush expression ref/state;
- loaded/presented/physical-authority state for each expression;
- collision/query/overlap/physics authority;
- shared persistent facts;
- layer-local facts;
- derived expression facts;
- causal relations;
- continuity class for combat/NPC/interactable roles;
- alive/health/interaction state where relevant;
- last seam handoff transition ID;
- save persistence class;
- validation warnings.

Actor names/paths may be displayed for debugging, but semantic ID must be visually primary.

## INSPECT — transition timeline

Provide a compact transition timeline showing:
`Request → Eligibility → Preparing → Commit → Physical Handoff → Derived-State Convergence → Presentation Complete → Save-Stable`.

For each stage expose:
- timestamp/frame;
- success/failure;
- reason;
- authoritative layer before/after;
- player transform/velocity;
- target semantic/physical ref;
- key representation states;
- validation failures.

The timeline must make double commit, stale callback, or late physical handoff obvious.

## INSPECT — paired-state comparison

A comparison view should display Waking and Hush expressions in parallel without changing canonical semantic state.

Supported views may include:
- metadata table;
- loaded/presented/physical state matrix;
- collision overlay;
- paired transform/anchor comparison;
- persistent fact vs derived-state comparison;
- side-by-side semantic property diff;
- world-space debug shapes for pair anchors/safe seam volumes.

A visual free-camera or ghost overlay is acceptable as a **development view** only. It may not grant gameplay collision/interaction with the inactive expression.

## AUTHOR / TUNE

Hush IDE live tuning is limited to reviewed non-semantic prototype values such as:
- seam presentation timing/intensity;
- bounded safe-resolution tolerances where classified as tuning rather than policy;
- transition readiness timeout for prototype measurement;
- Hush presentation/audio mix values;
- residue/VFX density;
- Reduced Effects multipliers;
- test-only representation preloading thresholds;
- debug visualization settings.

Read-only or controlled-stage only:
- stable semantic IDs;
- pairing class;
- fact persistence class;
- causal direction;
- continuity class;
- save schema semantics;
- collision-authority policy;
- core seam commit semantics.

Those are reviewed authored contracts, not casual runtime sliders.

## Provenance

Every tunable/editable field must show at least:
- canonical/repository-backed value;
- effective runtime value;
- session override if present;
- staged value if present;
- dirty state;
- source asset/config/data path or semantic authority;
- whether restart/reload is required;
- whether promotion is supported.

No developer should confuse a temporary Hush tweak with canonical content.

## EXERCISE — seam controls

Provide explicit development actions for:
- request normal Waking→Hush;
- request normal Hush→Waking;
- reset to a named stable Waking fixture;
- reset to a named stable Hush fixture;
- pause immediately before semantic commit;
- pause immediately after commit;
- inject destination-not-ready failure;
- inject destination-occupancy failure;
- repeat/hold seam input fixture;
- test transition from locomotion/combat/traversal/tool states;
- run transition at reduced effects and selected scalability profiles.

Normal exercise actions call the authoritative transition service. Fault injection is clearly separated.

## EXERCISE — pair/geometry controls

Provide development-only actions to:
- select a semantic pair by ID/search;
- teleport to named paired fixture without changing puzzle/world truth beyond the fixture contract;
- visualize Waking collision;
- visualize Hush collision;
- show inactive collision/query ownership violations;
- force both expressions loaded while retaining one semantic physical owner;
- unload/reload an inactive expression;
- inject duplicate/absent pair expression for validation;
- test authored safe seam offset volumes.

Teleport is a developer navigation convenience, not a player seam rule.

## EXERCISE — puzzle/continuity controls

Cross-links/actions should support:
- reset a named Hush puzzle fixture through Tool/Puzzle authority;
- view/change supported fixture facts through semantic world-state services;
- test shared vs layer-local causal state;
- spawn/reset representative paired enemy through Encounter authority;
- set test enemy health through Combat/Encounter IDE authority;
- test target-lock continuity;
- exercise shared one-shot interactable;
- test layer-exclusive NPC/enemy dormancy/reactivation.

The Hush workbench orchestrates test setup but does not duplicate those systems' mutation logic.

## EXERCISE — save/reload controls

Cross-link Save/Persistence actions for:
- capture stable Waking snapshot;
- capture stable Hush snapshot;
- request save during each seam phase;
- teardown/reload current fixture;
- simulate expression unloaded at reload;
- run paired semantic-ID reconstruction check;
- compare pre-save vs post-load semantic facts;
- invoke malformed/migration fixtures owned by Save/Persistence authority.

## RESET semantics

Reset is always scoped and named.

A Hush fixture reset must declare exactly what it resets:
- semantic active layer;
- named pair/entity fact set;
- named puzzle/encounter fixture facts;
- player test transform/loadout if part of fixture;
- presentation/accessibility test overrides;
- representation load state.

It must not silently:
- reset unrelated quests/NPC relationships;
- clear global inventory;
- alter completion ledger;
- mutate story/catastrophe state outside fixture scope;
- rewrite canonical files;
- hide validation errors by rebuilding the whole game indiscriminately.

## VALIDATE — semantic identity

Catch at minimum:
- duplicate semantic IDs;
- missing required pair expression;
- paired expressions claiming different shared facts;
- Actor/package/runtime GUID used as persistent identity;
- stale pair reference after reload/reset;
- related-distinct entities incorrectly sharing persistence.

## VALIDATE — transition

Catch at minimum:
- multiple semantic commits for one transition ID;
- semantic layer changed by VFX/animation/Data Layer callback;
- gameplay mutation before accepted commit;
- queued reverse transition from held input;
- player state/velocity reset solely by seam;
- seam-created combat immunity/cancel;
- save captured before save-stable boundary;
- presentation completing while representation still contradicts semantic state.

## VALIDATE — physical authority

Catch at minimum:
- inactive blocking collision;
- inactive overlap/hit generation;
- both exclusive pair expressions physically authoritative;
- camera/tool/projectile query hitting inactive expression;
- inactive gameplay-affecting physics simulation;
- invalid destination occupancy at commit;
- safe correction outside authored bound;
- active visible geometry materially contradicting collision affordance.

## VALIDATE — puzzle / continuity

Catch at minimum:
- layer shift directly setting puzzle solved;
- cross-layer effect with no authored semantic causal relation;
- shared fact duplicated per expression;
- Cantor/Anchor receiving hidden Hush-only exception;
- seam clearing aggro/resetting enemy health;
- target auto-switching to a different semantic enemy;
- dead paired entity resurrecting;
- shared one-shot interactable becoming available twice;
- inactive AI issuing physical actions.

## VALIDATE — presentation/accessibility

Catch at minimum:
- Hush layer identity unreadable with post-process/reduced effects;
- critical cue color-only;
- critical cue audio-only where consequence requires another channel;
- transition hiding footing/attack tells;
- forbidden camera motion/FOV change;
- Hush ambience masking critical cues;
- semantic cue removed by scalability;
- semantic/presentation state mismatch after transition;
- configured fixture failing photosensitivity review.

## Validation severity

Use clear severity semantics:
- **ERROR** — violates locked gameplay/persistence/physical authority; cannot be accepted as a valid fixture/result.
- **WARNING** — likely readability/performance/authoring risk requiring review.
- **INFO** — useful diagnostic observation.

Do not bury locked-contract violations in generic log spam.

## CAPTURE

One-click Hush capture should produce a reviewable structured artifact containing at minimum:
- build/commit/map;
- fixture/preset ID;
- player transform/state;
- active semantic layer;
- transition timeline if relevant;
- selected semantic entity/pair state;
- persistent/shared/layer-local facts relevant to case;
- loaded/presented/physical ownership matrix;
- target/combat/NPC/interactable continuity state if relevant;
- save-stable/snapshot state if relevant;
- presentation/accessibility/scalability settings;
- validation results;
- performance timings relevant to seam/representation;
- developer note field;
- optional screenshots/video as supplementary evidence.

Semantic structured evidence is primary; screenshots alone are not an acceptable debugging record.

## COMPARE

The workbench must support named before/after or candidate comparison for Decision #9 prototype evidence.

Candidate comparison should normalize fixtures and display:
- transition preparation/commit/presentation timings;
- memory/residency footprint;
- hitch/frame-time evidence;
- number/type of authored pair records;
- source-control/binary asset footprint evidence;
- load/unload behavior;
- save/reload convergence;
- validation failures;
- developer workflow friction/steps.

The IDE records evidence; it does not automatically choose architecture.

## PROMOTE boundary

Only supported tunable values/config/data may be staged/promoted through the development workflow.

Promotion requires:
- explicit dirty/staged state;
- human-readable semantic diff/patch where practical;
- canonical source destination;
- validation pass appropriate to the changed value;
- no hidden mutation of story/world/save facts.

Stable IDs, policy classes, and schema contracts require repository review rather than one-click runtime promotion if the format cannot guarantee a safe diff.

## Shipping exclusion

The Hush / World-Layer IDE is development infrastructure.

Shipping requirements:
- workbench UI unavailable/hard-disabled;
- fault-injection actions absent/hard-disabled;
- no public network listener;
- no remote model/API dependency;
- no unrestricted world/save mutation surface;
- no development-only pair overlays/collision visualizers packaged as required player content;
- retail Hush gameplay must function without the IDE module.

Epic's Gameplay Debugger is designed for runtime diagnostic categories and is normally excluded behind development/test compile boundaries; Stillring may reuse such mechanisms where appropriate, but the System IDE contract is broader than a debug overlay.

## Automation integration

Named Hush validation fixtures should be runnable both from the in-game workbench and through Unreal Automation/Functional Test entry points where practical.

Machine-verifiable cases include:
- single semantic commit;
- physical ownership exclusivity;
- save deferral/stable reload;
- pair ID uniqueness;
- inactive collision/query rejection;
- target continuity/no-roulette;
- no combat reset;
- deterministic fixture reset;
- reduced-effects gameplay invariance.

Epic's Automation framework supports command-line test execution and structured report export; Gate 4 should use that capability rather than making all verification manual.

Human play remains authoritative for:
- transition feel;
- Hush readability;
- atmosphere;
- camera comfort;
- puzzle understanding;
- audio balance;
- whether paired-state correspondence feels coherent rather than technical.

## Research basis

Primary current technical sources verified:
- Epic Games, **Gameplay Debugger**, UE5.8 — extensible realtime game-specific diagnostics; development-oriented categories.
- Epic Games, **Automation Test Framework / Run Automation Tests**, UE5.8 — unit/feature/functional/content-stress testing, command-line runs, structured reports.
- Epic Games, **Rewind Debugger**, UE5.8 — recorded runtime inspection as a useful evidence/debugging pattern; Hush IDE is not required to adopt its animation-specific implementation.
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.
- Gate 4 Decisions #1–#7 (`docs/70`–`docs/76`).

## Locked statement

> **The Hush IDE must make semantic truth, Unreal expression, and every disagreement between them visible, reproducible, and testable from inside the running game.**

## Next decision

**Gate 4 Decision #9 — compare UE5.8 representation candidates and define the prototype evidence matrix/provisional implementation recommendation.**

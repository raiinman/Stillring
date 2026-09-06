# 139 — System Ownership Map

**Status:** CANONICAL CROSS-SYSTEM OWNERSHIP AUTHORITY  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 2  
**Baseline main:** `4c65b2429dbb601e9c5ba0124cc0d27dc4a31a35`

## Purpose

This document answers:

> **Which system is allowed to decide each major category of Stillring state, which systems may consume it, and who is forbidden from creating a second truth?**

It consolidates existing owner-approved authority. It does not invent concrete C++ class names where the design only defines a service/domain.

Core rules:

> **One canonical fact has one authoritative writer.**

> **Consumers may observe, request, derive, present, and react. They may not create a second canonical copy.**

> **Save coordinates snapshots. It does not become the gameplay owner.**

> **System IDEs operate through the same authoritative services used by ordinary play.**

---

# 1. Ownership vocabulary

## Authoritative owner

The gameplay/system domain allowed to decide and commit the canonical fact.

The exact future C++ class name may still be an implementation choice unless separately locked.

## Consumer

A system allowed to read authoritative state and derive behavior/presentation/consequences.

## Requester

A system allowed to request a mutation through the owner but not write the owner's private truth directly.

## Persistence participant

A domain whose durable state is snapshotted/restored through Save Coordinator under Save/World-State authority.

## Derived view

A system-generated result that can be recomputed from more fundamental authority and therefore does not become a second owner.

## Presentation

Visual/audio/UI/animation/streaming representation of semantic truth.

Presentation is never automatically canonical state.

---

# 2. Core runtime ownership table

| State / responsibility | Authoritative owner | Allowed consumers / requesters | Persistence boundary | Forbidden duplicate authority |
|---|---|---|---|---|
| Player locomotion state, movement transactions, grounded/airborne/traversal ownership | Player Locomotion / movement gameplay service | Camera, Combat, Tool interactions, Hush transition coordinator, Skiff boarding/disembark logic, animation/presentation | Ordinary frame state transient; reviewed checkpoint/location context only through Checkpoint/Travel + Save | Animation Blueprint, Camera, Hush seam, Skiff route data, input mapping |
| Raw player input interpretation / action requests | Input layer + owning gameplay service for each action | Locomotion, Camera, Combat, Tool, Interaction | Profile/remap settings separate from playthrough | UI widgets or animation state directly becoming gameplay truth |
| Camera mode/frame/collision response | Camera service | Locomotion, Targeting, Combat presentation, Skiff traversal | Generally transient/profile tuning; not playthrough world truth | Combat AI, animation, level script |
| Target-lock semantic target and target-relative combat frame | Camera/Targeting service under Gate 1/2 contract | Combat, locomotion steering, Hush paired-expression continuity, UI | Ordinary target pointer/state transient; semantic entity identity belongs to entity/world systems | Enemy AI, Hush seam presentation, animation |
| Player combat action/state, guard/evade windows, commitment/recovery | Combat service | Camera/Targeting, locomotion restrictions, animation, encounter, tools where approved | Ordinary combat frame transient; death/retry restores reviewed safe state rather than half-action | Animation montage state, enemy AI, Hush seam |
| Health / durable combat progression where designed | Player Progression / health resource owner; exact service implementation TBD | Combat, UI, Save | Durable capacity/progression persists; momentary state follows checkpoint/retry policy | Combat animation or HUD |
| Enemy individual combat state / action | Enemy combat/AI authority | Encounter scheduler, Targeting, animation, Hush expression mapping where supported | Ordinary transient; unique durable outcomes handled by Encounter State | Encounter scheduler directly owning every AI state; animation |
| Encounter composition, pressure scheduling, authored encounter state | Encounter / Encounter State service | Enemy AI, Combat, Camera readability validation, Quest/World consequence consumers | Unique encounter/boss resolution persists when authored; ordinary pressure queue transient | Quest, Completion, level script duplicating encounter resolution |
| Unique boss / elite resolved state | Encounter State | World State, Quest/Story, Completion Ledger, rewards | Durable semantic outcome | Completion percentage, cutscene completion, boss Actor existence |
| Cantor diagnostic procedure state | Cantor / Tool gameplay service | Puzzle mechanisms, Hush/world queries, combat only through approved diagnostics, UI | Learned Patterns persist via Inventory/Tool Progression; active scan/trace transient | UI scan result, arbitrary Blueprint callback |
| Anchor / Glasslung / Temper / Vane / Mirror tool operation | Owning Tool gameplay service + target source system for affected world fact | Locomotion, Combat, Puzzle/Mechanism, Hush, Quest/World as observers | Tool ownership/upgrades persist via Inventory/Tool Progression; transient operation does not | Puzzle level Blueprint storing its own tool truth |
| Tool ownership / upgrade ownership / learned Patterns | Inventory & Tool Progression service | Tool services, Quest, Completion, IDE, UI | Durable | Tool Actor presence, UI loadout alone |
| Puzzle/mechanism semantic state | Mechanism's declared source owner, usually World State or dedicated authored mechanism service | Tool services, Quest/Story, Completion, Hush presentation | Durable only when authored as persistent world fact | Mechanism animation pose, level Blueprint local bool, Completion Ledger |
| Quest / objective progression | Quest / Story State service | World State as requester/consumer where story causes world changes; Dialogue/NPC; Completion | Durable semantic quest/stage/resolution state | World State private quest copy, dialogue graph, cutscene timeline |
| One-shot story event consumption | Quest / Story State service unless explicitly a World Fact | Dialogue, cinematics, World State, Completion | Durable if replay must be prevented | Cutscene completion callback as sole owner |
| Persistent environment/world facts | World State service | Quest, Setup/Payoff, Hush, NPC, Route Network, Completion, presentation | Durable by stable semantic ID | Loaded Actor state, Data Layer, quest-local copy |
| Global pivots such as Grand Ring / Stillness | World State, requested/caused by Story authority | Quest, Hush, Setup/Payoff, routes, NPCs, presentation | Durable canonical pivot fact | Cutscene sequence, map name, Setup/Payoff blanket commit |
| Waking/Hush active semantic layer and layer transition authority | Hush / World-Layer service | Locomotion, Camera, Combat, World State, Tool/Puzzle, Route Network, presentation/streaming | Committed active semantic layer at save-stable boundary; transition presentation transient | Runtime Data Layer state, sublevel visibility, Actor existence |
| Waking/Hush paired semantic identity | World-Layer + persistent semantic identity contract | World State, Save, Targeting, Tool/Puzzle, presentation registry | Durable semantic identity where needed | Per-layer duplicated identity, actor path |
| Data Layer / streaming representation | Unreal presentation/streaming subsystem following semantic world authority | Rendering, collision/representation, Hush IDE | Runtime representation; not canonical quest/world state | Treating load state as story/world truth |
| NPC durable recurrence / alive/absent/relocated/role facts | World State until/unless a dedicated NPC Recurrence service is later promoted | Quest, Dialogue, Setup/Payoff, Completion, presentation | Durable when authored | Current AI/nav task, dialogue widget, spawn presence |
| NPC current AI/navigation behavior | NPC/AI runtime service | Dialogue trigger, presentation, encounter where relevant | Transient by default | World State storing behavior tree task |
| Dialogue eligibility / presentation | Dialogue service reads source facts; does not own source facts | Quest, NPC, World State, relationship facts | One-shot dialogue consequences persist only through their declared owner | Dialogue branch bool duplicating quest/world history |
| Checkpoint / safe resume identity | Checkpoint/Travel service | Save Coordinator, Locomotion spawn/recovery, Hush | Durable semantic checkpoint/area ID + reviewed placement context | Raw coordinates alone, map path alone |
| Save schema/header/migration/integrity | Save Schema / Save Coordinator | All persistent domain owners | Durable file/slot metadata | Gameplay domains writing raw save file sections without contract |
| Snapshot orchestration / disk I/O | Save Coordinator | All persistent domain owners | Owns orchestration, not semantic gameplay meaning | Save Coordinator becoming Quest/World/Inventory god object |
| Player settings/remaps/accessibility preferences | Profile / Settings channel | Input, Camera, UI, accessibility presentation | Persist separately from playthrough | Playthrough world-state, Completion |
| Completion-bearing semantic facts | Completion Ledger service | UI, assist/accounting, 100% reconciliation | Durable semantic completion record/reconciliation | Raw percentage, quest/world fact duplicates |
| Completion percentage/category summaries | Completion Ledger derived view | UI | Recomputed/derived; cache disposable | Persisted independent percentage as canonical truth |
| Setup/Payoff authored definition | Setup/Payoff definition authority (`UPrimaryDataAsset` design direction) | Setup/Payoff runtime evaluator, authoring IDE | Repository-backed authored data, not playthrough state | Level Blueprint, duplicate registry/manual mirror |
| Setup/Payoff source facts | Their source systems: Quest, World, NPC, Hush, Progression, Tool, Traversal, Encounter, Record, Repair Contract, etc. | Setup/Payoff evaluator | Persist according to source owner | Setup/Payoff copy of source truth |
| Setup/Payoff chain-specific commit/resolution history | Setup/Payoff runtime/history service | Completion, Quest/UI/presentation, IDE | Minimal durable Commit/Resolution receipts + schema reconciliation | Persisting every lifecycle boolean; source systems writing chain receipts |
| Setup/Payoff transient lifecycle labels (Dormant/Primed/Payoff Available/Unavailable) | Derived by Setup/Payoff evaluator from source facts + receipts | IDE/UI where spoiler rules allow | Derived, not blindly persisted | Save fields treated as higher authority than source facts |
| Line Skiff legal macro route traversal derivation | Line Skiff Route Network | Skiff movement/control, Quest/World presentation, Hush, Drift Knot systems | Durable route definitions in authored data; durable route/world facts remain with source owners | Spline Actor path, vehicle Actor, Hush Data Layer |
| Semantic route graph / route-expression definitions | Line Skiff Route Network authoring authority | Route traversal, IDE, content | Repository-backed semantic data | Level spline names as identity |
| Durable route availability/history facts | Story / World State unless a route-specific fact is explicitly owned elsewhere | Route Network derives legal traversal; Quest, Completion, IDE | Durable source fact | Route Network duplicating story/world history |
| Active Waking/Hush layer while aboard Skiff | Hush / World-Layer service | Route Network evaluates paired continuation; Skiff traversal | Save-stable semantic layer | Route Network silently switching world layer |
| Skiff moment-to-moment handling inside legal corridor | Skiff traversal/control service; player owns input intent | Camera, Route Network constraints, animation | Transient; stable resume point rather than frame-perfect vehicle state | Route graph driving player input, Camera owning vehicle physics |
| Drift Knot completion | Drift Knot authored source/resolution service + Completion Ledger consequence | Route Network, Route Listener, Completion | Durable semantic hunt resolution | Moving Actor existence, current route location |
| Route Listener post-12/12 service state | Progression/Skiff network service according to completion authority | Skiff dock network, assist UI | Durable unlock | Completion UI directly locating required Knots before unlock |
| Null Meridian S1–S6 source facts | Existing owners: Tool/Mechanism, Hush, Combat/Encounter, World State, Route/service machinery | Null Meridian sequence evaluator/Quest | Persist by source owner | Final-dungeon level script duplicating all facts |
| Null Meridian sequence settlement | Quest/Story or dedicated final-dungeon sequence service — exact runtime class **not yet fixed**; must expose stable semantic settlement and observe source facts | Save, IDE, story progression | Durable at approved semantic boundaries | Cutscene complete, room trigger, actor destruction alone |
| S6 local service branch states | Their actual mechanism/world source owners | S6 evaluator, Common Measure, presentation | Durable only as authored world/mechanism facts | S6 sequence object owning pressure/lift/vent truth |
| S6 Common Measure operation | Cantor/Common Measure procedure service coordinates one operation | Local source systems, S6 sequence | Temporary operation state; S6 settlement only after authoritative completion | Common Measure becoming permanent master authority |
| S6 master relay disconnected fact | World/Mechanism source owner for relay | Quest/Story, S6 settlement, presentation, Save | Durable semantic fact after commit | Relay animation state or S6 cutscene |

---

# 3. Ownership by major domain

## Player Locomotion

Owns:
- movement state/transactions;
- legal locomotion progression through grounded/airborne/traversal states;
- runtime velocity/movement response within Gate 1 authority.

Does not own:
- camera framing;
- combat attack state;
- Hush semantic layer;
- world affordance persistence;
- Skiff macro route legality.

Required consumers:
- Camera;
- Combat;
- traversal interaction;
- Hush transition coordinator;
- Skiff boarding/disembark.

Exact UE class decomposition remains an implementation choice under Issue #5.

---

# 4. Camera / Targeting

Owns:
- camera state/mode;
- camera collision response;
- target candidate evaluation/selection under locked rules;
- target-relative frame.

Does not own:
- enemy combat state;
- player combat state;
- world/Hush state;
- persistent entity identity.

During Hush transitions, it may carry lock to the destination expression only because the same semantic target identity remains valid under World-Layer/Combat authority.

It does not invent that identity.

---

# 5. Combat and Encounter

## Combat service

Owns player combat action semantics and combat timing windows.

Animation represents them.

Hush transitions do not reset them.

## Enemy runtime combat/AI

Owns individual enemy action behavior within encounter constraints.

## Encounter service

Owns composition/pressure scheduling and unique authored encounter resolution.

World consequences must be exported/committed through World State rather than hiding behind enemy Actor existence.

Completion observes settled encounter outcomes and records its own completion consequence.

---

# 6. Tools and mechanisms

Tool services own the tool operation.

The target's source system owns the resulting durable world truth.

Example pattern:

```text
Player uses Anchor
    -> Anchor service validates/executes physical tool relationship
    -> mechanism/world owner commits resulting durable mechanism fact if applicable
    -> Quest/SetupPayoff/Completion observe settled fact
    -> presentation follows
```

Forbidden:

```text
Anchor Blueprint
    -> directly writes Quest bool
    -> Completion reads bool
    -> World representation guesses from Quest
```

---

# 7. Hush / World-Layer

Hush/World-Layer owns:
- current semantic layer;
- legal seam transition coordination;
- paired world-expression relationship.

World State owns durable world facts unless a specific other owner is declared.

Unreal Data Layers/streaming realize the selected semantic expression.

They do not own it.

Locomotion, Camera, Combat, Tool, Route Network, and presentation must all consume the transition contract without resetting/re-owning their state.

---

# 8. Save / World-State

Save Coordinator:
- orchestrates coherent snapshots;
- serializes/deserializes;
- coordinates schema/migration/integrity/recovery.

It does not own gameplay meaning.

Persistent gameplay owners hand semantic records to Save and receive restored records back through owner APIs.

Restoration order must preserve source-before-derived semantics, especially for:
- World/Hush;
- Setup/Payoff;
- Completion;
- route derivation;
- UI/presentation.

Issue #4 remains open because this ownership model still requires real paired-layer save/reload proof.

---

# 9. Completion

Completion Ledger owns **completion-bearing semantic facts**.

Other systems own the gameplay truth that causes completion.

Examples:

```text
Quest owns contract resolution
    -> Completion Ledger satisfies contract completion ID

Encounter owns elite resolution
    -> Completion Ledger satisfies elite completion ID

Setup/Payoff owns chain resolution receipt
    -> Completion Ledger satisfies setup/payoff completion ID
```

Percentage and category totals are derived.

Completion must never write the source gameplay fact backward just to make the totals agree.

---

# 10. Setup/Payoff

Locked ownership split:

```text
SOURCE SYSTEMS
    own world/story/NPC/tool/route/record/encounter facts
        |
        v
SETUP/PAYOFF EVALUATOR
    derives lifecycle + writes only chain-specific commit/resolution history
        |
        v
SOURCE-OWNED CONSEQUENCES
    World / NPC / Quest / Record / Route / etc.
        |
        v
COMPLETION LEDGER
    derives completion consequence
```

Setup/Payoff does not own downstream world manifestations merely because the chain caused them.

Its authored definition is read-only game data; runtime history is separate.

---

# 11. Line Skiff

Locked split:

```text
Story / World State
    owns durable infrastructure/history facts

Hush / World-Layer
    owns active semantic layer

Line Skiff Route Network
    owns semantic route definitions + derives currently legal macro traversal

Skiff traversal/control
    owns moment-to-moment supported-corridor vehicle handling

Player
    owns acceleration/coast/brake/lateral/junction intent

Camera
    owns camera behavior
```

A route becoming unavailable because Stillness changed infrastructure is a World/Hush fact consumed by Route Network.

The Route Network must not write `Stillness=true` merely because a route disappeared.

---

# 12. Null Meridian

Null Meridian is deliberately **not** one giant custom authority service.

The final dungeon composes existing owners.

Examples:
- S1 uses existing Anchor/Vane/mechanism state;
- S2 uses Glasslung/Temper/source-owned machine state;
- S3/S4 use Hush/Palinode/Mirror/world-expression state;
- S4/S5 use normal Combat/Encounter authority;
- S6 uses local mechanism owners + Common Measure + a source-owned relay fact.

A thin semantic sequence/progression layer may own only:
- which Null Meridian sequence settlements are complete;
- dependency progression between sequences;
- approved local retry/checkpoint state that is not already another owner's fact.

The exact runtime class/service name is not yet locked and belongs in implementation planning, not in this map.

---

# 13. System IDE ownership boundary

The System IDE shell owns:
- developer UI shell;
- workbench registration/navigation;
- provenance display;
- session-override/staged-change presentation;
- common capture/validation surfaces.

It does **not** own gameplay facts.

Each workbench calls the real domain owner.

Examples:
- Locomotion IDE requests locomotion changes through Locomotion service;
- Save IDE constructs fixtures through declared owner APIs;
- Setup/Payoff IDE cannot flip a copied `PayoffAvailable` boolean;
- Hush IDE requests legal semantic transition rather than directly toggling Data Layers;
- Line Skiff IDE changes route fixtures/source facts through their owners, not spline visibility;
- Null Meridian IDE settles prerequisites through reviewed fixture APIs, not room-trigger hacks.

Issue #58 remains open until this shared architecture exists in UE5.8.

---

# 14. Owner-registration validation requirements

Future runtime architecture must make ownership auditable.

At minimum validation must detect:
- two services claiming canonical write ownership for one semantic fact family;
- persisted field with no owner;
- consumer writing another owner's state directly;
- same fact saved in multiple sections with conflicting values;
- Setup/Payoff definition/history duplicating source world facts;
- Completion duplicating source gameplay facts;
- Data Layer state used as semantic Hush authority;
- level Blueprint used as the only source of a persisted quest/world fact;
- route Actor/spline path used as persistent route identity;
- Null Meridian room script owning mechanism/combat/Hush truth;
- System IDE shadow state diverging from gameplay services.

The Save/World-State IDE ownership graph should eventually provide a project-wide foundation for this validation.

---

# 15. Implementation-choice boundary

This map intentionally does **not** lock concrete C++ class names for every domain.

Still unresolved at implementation-design level may include:
- whether a domain is one `UGameInstanceSubsystem`, `UWorldSubsystem`, component, service object, or another reviewed Unreal architecture;
- service lifetime where not already implied by persistence needs;
- internal event bus/delegate/message routing implementation;
- exact data container types;
- dependency injection/registration mechanism;
- save serialization mechanics beyond existing schema authority;
- exact Null Meridian sequence coordinator class.

Those choices must preserve the owner boundaries above.

They are not permission to merge owner domains because one class is easier to write.

---

# 16. Runtime proof boundary

This is an ownership/documentation artifact.

It does not prove:
- owner services exist in UE5.8;
- no duplicate state exists in code;
- restore order is correct;
- IDE mutations use real services;
- Hush/route/combat transitions behave correctly;
- Null Meridian composition works;
- performance/threading/lifetime choices are sound.

Those obligations belong in the Runtime Evidence Ledger and future implementation verification.

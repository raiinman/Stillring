# 04 — Technical Direction

## Engine

**Unreal Engine 5.8** is the production baseline for Project Stillring.

The engine decision was changed before Gate 1 implementation because Stillring's actual production problem is a long-form authored 3D action-adventure: third-person combat, animation, cinematics, state-heavy regions, tooling, and substantial environment production.

Do not move to preview/dev engine builds or a later major engine version during production merely because it exists. An engine migration requires a specific blocker/benefit, a migration branch, build proof, save/content compatibility review, and explicit approval.

## Primary implementation model

Claude is the primary implementation agent for the project.

Gameplay and authoritative runtime systems are **C++ first**.

Blueprints are intentionally thin and are appropriate for:
- presentation wiring;
- animation graph/presentation glue;
- scene-specific assembly;
- designer-exposed tuning that does not own canonical rules;
- VFX/audio hooks;
- cinematic/Sequencer integration;
- quick disposable prototypes that are rewritten when proven.

Blueprints must not become the sole owner of:
- quest/world state;
- save semantics;
- combat rules;
- inventory progression;
- persistent IDs;
- completion logic;
- dialogue eligibility policy;
- Hush/Waking authority;
- developer QA semantics.

Reason: `.uasset` Blueprint graphs are binary and substantially harder to diff, audit, recover, and reason about than C++ and repository text. Stillring should use Unreal's editor where it is strongest without surrendering architectural reviewability.

## Unreal systems are tools, not mandates

Do not adopt a large Unreal subsystem because it is fashionable or appears in a template.

In particular:
- **Gameplay Ability System:** not a default dependency. Use it only if prototype evidence shows it simplifies Stillring rather than adding framework weight.
- **World Partition:** not automatically required. Stillring is an authored interconnected adventure, not a giant procedural continent.
- **Data Layers:** useful candidate for Waking/Hush and catastrophe presentation when a map uses World Partition; not permission to put quest truth in world-layer state.
- **Nanite:** opt-in after art/performance testing; the visual target does not require high-poly assets.
- **Lumen:** opt-in after visual/performance testing; the project must not acquire generic modern-Unreal lighting by accident.
- **MetaHuman:** not part of the default character pipeline.
- **PCG:** not a substitute for authored level design.

Every heavyweight dependency must solve a demonstrated production problem.

## Project organization

Organize source by gameplay domain and keep source/authored truth distinct from generated/editor assets.

Target structure after Gate 1 bootstrap:

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

`SourceData/` is for reviewable source representations when a content domain benefits from text/CSV/JSON or another deterministic format. Unreal Data Assets/Data Tables may be generated/imported/runtime-facing representations; they do not automatically outrank repository canon.

Do not mirror this folder tree mechanically before a real file needs to exist.

## Source-of-truth boundary

Repository canon remains authoritative over Unreal editor assets.

When authored narrative/progression content is represented in both repository text and an Unreal asset:
- the canonical contract defines intent and required behavior;
- reviewable structured source data should own IDs/conditions where practical;
- generated/imported Unreal representations must be reproducible or explicitly reconciled;
- a binary `.uasset` must never silently become a secret alternate story bible.

If editor content contradicts canon, fix the contradiction rather than declaring the editor asset authoritative by convenience.

## Persistent identity

Any persistent/interactable world object that matters to save data needs a stable authored semantic ID.

Never key important save state only by:
- Actor pointer;
- UObject path;
- package path;
- spawn order;
- transient GUID generated at runtime;
- Blueprint instance name.

Examples:
- `rootmere.cathedral.gate_03`
- `saltreach.foundry.chest_pressure_room`
- `cairnspire.npc.tessa.midgame`

Represent IDs with a deliberate Unreal-friendly type (`FName`, Gameplay Tag, or a small typed ID wrapper) selected during Issue #4. Do not scatter raw string comparisons across gameplay code.

## Save model

Save semantic state, not serialized copies of entire Worlds/Actors.

Categories:
- player state;
- inventory/tools;
- quest flags/objective state;
- world facts;
- defeated bosses;
- opened permanent shortcuts;
- collected unique items;
- regional catastrophe state;
- current Waking/Hush state only where reload-safe;
- completion-bearing IDs.

Use an explicit schema version from the beginning.

Released schema changes require migrations or an explicit compatibility decision. Development builds may invalidate test saves only when the change is documented and fixtures are updated.

## Waking / Hush architecture

The Hush must not become two unrelated copies of every region.

Authoritative principles:
- shared semantic entity IDs;
- one authoritative quest/world-state service;
- layer/state presentation is downstream of semantic state;
- explicit authored seam transitions;
- save/reload must reproduce the intended layer and persistent facts;
- level designers must be able to understand which state owns an Actor.

Gate 4 should prototype at least two technically credible representations before locking the production pattern.

Candidate A — **World Partition + Runtime Data Layers**
- use Data Layers for state-dependent geometry/presentation;
- World Partition streaming may remain disabled in compact maps if streaming itself is unnecessary;
- gameplay state drives layer activation, not vice versa.

Candidate B — **explicit non-World-Partition level/Actor layering**
- shared persistent semantic Actors/services;
- authored presentation groups, Level Instances/sublevels/components, or another explicit pattern;
- no World Partition cost if the region does not benefit from it.

Choose using authoring clarity, transition behavior, save reliability, source-control cost, and performance—not engine marketing.

## Player / combat architecture

Keep responsibilities separable:
- input mapping;
- locomotion;
- camera;
- target selection;
- attack state;
- guard/evade;
- hit detection;
- damage receiver;
- health/posture/resources if retained;
- enemy decision logic;
- animation presentation;
- audio/VFX feedback.

Prefer Actor Components, focused UObject services, interfaces, data assets, and ordinary C++ state machines over a monolithic `AStillringCharacter` that owns the entire game.

Animation Blueprints reflect gameplay state; they must not become a second gameplay state machine that contradicts C++ authority.

## Input

Use **Enhanced Input** and named actions/mapping contexts.

Controller is the primary design target.
Keyboard/mouse remains first-class.

No gameplay rule may depend on a hard-coded physical key.

## Camera

Camera behavior is a first-class gameplay system, not generic SpringArm defaults left untouched.

Gate 1 must explicitly test:
- exploration orbit/recenter;
- collision/occlusion;
- narrow rooms/low ceilings;
- vertical spaces;
- lock acquisition/release;
- target switching;
- multi-enemy framing;
- boss distance/scale;
- sensitivity/inversion/accessibility.

Use Unreal camera components/framework pieces where useful, but the feel specification in Issue #2 remains authoritative.

## Animation and cinematics

Expected production stack:
- Animation Blueprints for presentation;
- montages/state machines only where they remain subordinate to gameplay authority;
- Control Rig where in-engine rigging/adjustment provides real production value;
- Sequencer for cinematics and authored scene timing;
- C++/semantic narrative state controls whether a cinematic is valid to enter.

Cinematics may not silently set broad quest/world state through arbitrary Blueprint side effects. State transitions should call explicit narrative/world-state services.

## Data-driven content

Use the smallest transparent representation appropriate to each content class.

Candidates include:
- C++ structs;
- Primary Data Assets/Data Assets;
- Data Tables;
- Gameplay Tags;
- config files;
- repository CSV/JSON imported or validated into Unreal assets.

Prefer reviewable source for high-churn systemic data and canonical IDs.

Do not move behavior that belongs in code into giant designer tables merely to call it data driven.

## Rendering target

Stillring's art direction outranks Unreal's defaults.

The target remains a late-1990s 3D adventure remembered through modern eyes:
- low-poly authored forms;
- compact textures;
- strong silhouettes;
- deliberate fog;
- restrained material complexity;
- controlled lighting;
- readable animation;
- modern output stability and accessibility underneath the style.

During the vertical slice, explicitly compare rendering configurations rather than inheriting the Third Person template look.

Evaluate individually:
- internal resolution/upscaling strategy;
- anti-aliasing method;
- Lumen versus simpler lighting;
- Virtual Shadow Maps versus alternatives;
- Nanite off/on only where useful;
- post-processing and fog treatment;
- texture filtering/pixel treatment.

A screenshot must look like **Stillring**, not an Unreal marketplace demo with low-poly assets dropped into it.

## Performance

Set budgets during the vertical slice, including:
- frame-time target on target PC;
- CPU game-thread and render-thread budgets;
- GPU budget;
- draw calls/primitive counts as practical monitoring metrics;
- animation cost;
- particle/VFX limits;
- dynamic light/shadow cost;
- shader/material complexity;
- memory growth during region transitions;
- Hush transition stall budget;
- package/build size trend.

Do not wait for beta to discover that layered worlds, cinematic assets, or default high-end Unreal features exceed the target.

## Git / Git LFS

Track C++, config, scripts, docs, and structured source data in normal Git.

Unreal binary assets must be treated deliberately. Use Git LFS for project binary content such as:
- `.uasset`;
- `.umap`;
- source `.fbx`/large `.glb`;
- `.blend`;
- high-resolution source textures;
- `.wav`/`.flac`;
- `.psd`/`.kra`;
- large cinematic source files.

Ignore generated/local Unreal directories including:
- `Binaries/`;
- `DerivedDataCache/`;
- `Intermediate/`;
- `Saved/`;
- local IDE/build artifacts.

Do not commit Derived Data Cache.

## Automated validation

Use Unreal's Automation/Functional Testing infrastructure where it helps, plus repository scripts and later Gauntlet where multi-session/build orchestration earns its cost.

At minimum, establish checks for:
- C++ project builds for the supported development target;
- editor project loads without fatal asset/reference errors;
- fast automation/smoke tests;
- required semantic IDs are unique;
- dialogue IDs referenced by quests exist;
- save schema fixtures load/migrate;
- completion-bearing IDs reconcile;
- important maps/assets can be loaded during content-stress validation;
- no forbidden generated directories or oversized non-LFS binary assets are committed.

Gate 1 should establish a reproducible command-line build/automation entry point so Claude can verify its work without relying solely on clicking around the editor.

## Developer tooling

Implement `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` alongside gameplay rather than after content multiplication.

Useful Unreal-native building blocks may include:
- development-only console commands;
- a project `UCheatManager` or equivalent debug command layer;
- Development-only UMG debug UI;
- Functional Tests;
- Automation Specs/tests;
- local structured state dumps;
- command-line/Automation/Gauntlet harnesses.

Debug commands must call the same authoritative services as normal gameplay whenever possible.

## Release boundary

Retail Stillring must not depend on:
- Claude or any other model runtime;
- external AI APIs;
- development automation endpoints;
- remote debug listeners;
- editor-only plugins/content;
- test-only state mutation commands.

Claude builds the game. Claude is not part of the shipped game.

## Technical definition of success

This engine migration succeeds if Unreal makes production easier without surrendering reviewability.

A healthy Stillring codebase should let Claude and a human reviewer answer:
- where a gameplay rule lives;
- where a world fact is owned;
- which repository contract authorizes a behavior;
- how to reproduce a state;
- how to test it from command line or developer tooling;
- which binary assets are presentation versus authority.

If those answers become harder as the game grows, the architecture is drifting and must be corrected.
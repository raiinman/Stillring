# 21 — In-Game System IDE Contract

**Status:** production architecture authority  
**Date:** 2026-09-04  
**Scope:** development-only in-game authoring, inspection, tuning, validation, and state-control workbenches for major Stillring systems.

## Core requirement

Project Stillring must be developable **from inside the running game** wherever practical.

A developer should not have to leave play, reopen several external tools, reconstruct state, edit one value, reload the whole route, and navigate back to the test site for every meaningful iteration.

Therefore every major gameplay/content system must ship alongside a dedicated **System IDE**: an in-game development workbench that exposes the system's meaningful state and authoring surface while the game is running.

This is not a giant cheat menu and not a generic debug overlay. It is production infrastructure.

> **Build the system and its in-game IDE together.**

The shared developer shell may host many workbenches, but each system owns a purpose-built IDE module rather than being reduced to an unstructured list of console variables.

---

## 1. What "System IDE" means

A Stillring System IDE is a development-only in-game workspace that lets a developer, tester, or Claude-assisted local workflow do most of the following without leaving the current playable session:

1. **Inspect** — see what the system currently believes.
2. **Author / tune** — change supported development values or authored data safely.
3. **Exercise** — force representative states, inputs, events, spawns, transitions, and resets.
4. **Validate** — run system-specific checks and show why something is invalid or unavailable.
5. **Compare** — inspect before/after or alternate configurations where useful.
6. **Capture** — record current state, evidence, notes, and reproduction context.
7. **Promote** — persist deliberate changes into reviewable repository-backed authority or export an explicit patch/artifact for review.

A read-only inspector is not enough. A console that can mutate opaque flags is not enough. The workbench must support the actual iteration loop for that system.

---

## 2. Shared in-game developer shell

System IDEs should live inside one coherent development shell so the project does not become a pile of unrelated debug windows.

The shell should eventually provide:

- open/close from controller and keyboard;
- searchable list of registered System IDEs;
- current build/commit identifier;
- current map/region/checkpoint and player transform;
- active test preset and save slot;
- common undo/revert boundary where technically safe;
- common dirty-state indicator for unsaved development changes;
- common capture/observation action;
- common validation-results surface;
- common reset/reload/checkpoint controls;
- common provenance display showing whether a value came from code, config, data, authored content, a temporary session override, or a staged change;
- clear DEVELOPMENT / TEST labeling so nobody mistakes runtime overrides for canonical content.

The shell may be UMG, Slate, a hybrid editor/runtime utility, or another Unreal-appropriate architecture. Exact presentation is an implementation decision. The semantic contract is not.

---

## 3. Required System IDE capabilities

Every substantial System IDE must define its own version of these five surfaces.

### A. INSPECT

Expose player-meaningful and author-meaningful state, not raw object dumps only.

Examples:
- current locomotion state and requested speed band;
- current target-lock frame and lock candidate reasons;
- active combat state and recovery/commitment windows;
- current quest/objective and unmet prerequisites;
- NPC recurrence/state facts;
- interaction eligibility and failed-condition reasons;
- inventory/tool ownership and progression gates;
- Hush/Waking presentation + semantic world state;
- save/persistence facts and authored IDs.

The developer should be able to answer **"why is the game doing this?"** from the IDE.

### B. AUTHOR / TUNE

Expose values and authored records that are genuinely useful to iterate while playing.

Examples:
- movement acceleration/braking/tolerance values;
- camera distances/response values;
- combat damage/recovery/timing values;
- interaction range/alignment tolerances;
- encounter composition/test parameters;
- quest condition test data;
- dialogue eligibility/test variants;
- tool/puzzle tuning values;
- environmental/Hush transition presentation values.

Not every value should be mutable. Canonical story facts, stable IDs, schema contracts, security-sensitive settings, or values whose live mutation would invalidate the session may be read-only or require a controlled staging flow.

### C. EXERCISE

Each IDE must make its own system easy to provoke and reset.

Examples:
- locomotion: teleport to representative test geometry, force/release movement states, replay boundary cases;
- camera: spawn/select camera targets and framing cases;
- combat: spawn archetypes, reset encounter, set health/loadout, force phase;
- quests: load named state preset, advance/revert supported transition, explain blocker;
- dialogue: select speaker/context, preview eligible lines, test state variants;
- tools/puzzles: grant tool, reset mechanism, force supported puzzle states;
- Hush/world: transition approved layer/state combinations and reload paired geometry;
- save: create/load fixture snapshots and migration cases.

A System IDE that cannot rapidly get the developer back to the behavior being tuned is incomplete.

### D. VALIDATE

The IDE should provide system-specific assertions or diagnostics, not just values.

Examples:
- traversal affordance geometry is inside/outside authored eligibility;
- target-lock candidate rejected because of range/occlusion/state;
- interaction blocked because prerequisite X is false;
- quest transition would violate required state invariant;
- NPC recurrence references a missing authored ID;
- dialogue branch has impossible prerequisites;
- save fixture references removed content;
- tool target has contradictory supported-state tags;
- current temporary tuning would violate an approved semantic boundary.

Validation should explain the failure in human terms where practical.

### E. CAPTURE / PROMOTE

Live experimentation must not create invisible production truth.

A System IDE must distinguish at least:

- **canonical/repository-backed value**;
- **session override**;
- **dirty staged development change**;
- **saved/promoted change**.

When a value is changed live, the IDE must make it obvious whether the change dies with the session or is staged for promotion.

Where technically practical, supported edits should save directly into reviewable text/config/data authority in Editor/Development workflows. Where direct persistence would be unsafe or opaque, the IDE must export a structured patch/change record that can be reviewed and deliberately applied.

No important design decision may exist only because "that value was tweaked in a running build once."

---

## 4. System IDEs required by production

The exact list can grow, but these are first-class planned workbenches rather than optional debug luxuries:

### Player / Locomotion IDE
- live movement state;
- processed input vector / dead-zone result;
- requested and actual speed;
- acceleration/braking/rotation state;
- Sprint request/active state;
- mantle/ledge/ladder/swim/slope eligibility visualization;
- traversal rejection reasons;
- fall severity/landing classification;
- teleport buttons to canonical locomotion test cases;
- live tuning for Gate 1-approved numeric values;
- one-click canonical five-minute locomotion course reset.

### Camera / Targeting IDE
- camera mode/state;
- camera collision probes;
- target candidates and rejection reasons;
- current lock target and target-relative frame;
- framing/offset/lag values;
- representative target arrangements;
- camera test presets and reset.

### Combat IDE
- player/enemy combat state;
- health/resources;
- active attack/recovery/guard/evade states;
- hit/hurt data and damage breakdown;
- spawn/reset encounter and boss states;
- force phase / representative loadout;
- combat tuning values that are approved for live iteration;
- instrumentation for timing/spacing/readability tests.

### Interaction / Traversal-Object IDE
- nearby interactables and eligibility reasons;
- authored interaction IDs/types;
- local alignment envelope visualization;
- reset/retrigger mechanisms;
- inspect traversal affordance metadata/geometry;
- validate visually equivalent affordance consistency.

### Inventory / Tool / Progression IDE
- grant/remove tools and test inventory;
- inspect upgrade/progression facts;
- preview tool capabilities and supported targets;
- reset tool-specific puzzles/test scenes;
- validate ownership/unlock dependencies.

### Quest / Objective / World-State IDE
- current objective and prerequisite graph;
- named state presets;
- supported advance/revert transitions;
- unmet-prerequisite explanations;
- regional/world epoch facts;
- completion flags and downstream effects;
- softlock/invariant checks.

### Dialogue / NPC IDE
- current NPC authored ID/state;
- recurrence/state history where supported;
- eligible dialogue branches and rejection reasons;
- preview dialogue for named world-state presets;
- inspect relationship/story facts used by eligibility;
- jump between representative NPC states without replaying hours.

### Hush / World-Layer IDE
- semantic world-layer state;
- presentation-layer/Data Layer/Actor pairing state when applicable;
- paired persistent IDs;
- approved transition triggers;
- seam/puzzle state reset;
- collision/geometry comparison views;
- save/reload verification entry points.

### Puzzle / Mechanism IDE
- mechanism state graph;
- supported inputs/outputs;
- reset to named states;
- force individual signal/input conditions;
- inspect dependency and completion reasons;
- validate impossible/softlocked configurations.

### Save / Persistence IDE
- active save slot/schema;
- inspect semantic persisted facts;
- create/load named fixtures;
- compare before/after state;
- run migration fixture cases;
- validate persistent authored IDs;
- expose save corruption/invariant diagnostics without manual file archaeology.

Additional system IDEs should be added when a new system becomes expensive to author, tune, reproduce, or understand from ordinary play alone.

---

## 5. Development rule: IDE debt counts as feature debt

A gameplay/content system is **not production-complete** merely because the player-facing behavior works.

If the system will require repeated tuning, authoring, reproduction, or state inspection during later production, its System IDE is part of the feature's definition of done.

The project must avoid this failure pattern:

1. rapidly build many systems;
2. defer their developer interfaces;
3. later discover every change requires editor archaeology and long replay routes;
4. production slows to a crawl;
5. debugging depends on whoever remembers hidden state.

Therefore:

- prototype IDE surface grows with the prototype system;
- vertical-slice systems get useful authoring/testing workbenches;
- production systems get durable workbenches before mass content depends on them;
- missing IDE capability is tracked as real production debt, not optional polish.

---

## 6. Live-edit safety and source-of-truth boundary

"Develop while in game" does **not** mean runtime state silently becomes canonical truth.

Rules:

- gameplay/state authority remains C++ first unless an approved reviewable data representation owns the value;
- live edits must identify their source and persistence status;
- runtime overrides are temporary unless deliberately promoted;
- canonical story/progression rules remain repository authority;
- binary Unreal assets may be edited only through a controlled editor-aware path with explicit evidence;
- a System IDE must not create a second hidden rules engine;
- mutations should call the same authoritative gameplay services used by normal play whenever practical;
- schema-breaking or unsafe changes may require restart/reload and should say so rather than pretending hot reload is safe;
- every promoted change must be reviewable in source control or accompanied by explicit binary-asset evidence.

---

## 7. Human + Claude development workflow

System IDEs are deliberately useful to both the owner and Claude-assisted development.

A typical iteration loop should become:

```text
PLAY
  ↓
notice problem / opportunity
  ↓
open relevant System IDE
  ↓
inspect why current behavior happened
  ↓
adjust supported value / load test state / reset case
  ↓
play immediately
  ↓
compare result
  ↓
promote chosen change + capture evidence
  ↓
continue playing
```

The owner should be able to tune and evaluate player-facing behavior without needing to understand an Unreal object hierarchy. Claude should be able to read semantic state and invoke bounded development actions instead of guessing from screenshots or editor internals.

The in-game IDE is therefore part of the bridge between **PLAY** and the rest of the production pipeline.

---

## 8. Retail / security boundary

System IDEs are development infrastructure only.

Shipping requirements:

- System IDE UI/modules are excluded or hard-disabled;
- no public network control listener;
- no external model/API dependency;
- no embedded Claude/autonomous runtime agent;
- no API keys/secrets;
- no unrestricted save/quest mutation surface exposed to players;
- development-only content must not accidentally become a Shipping dependency.

The shipped game remains a complete authored single-player game.

---

## 9. Gate expectations

### Gate 1 — establish the pattern
The locomotion and camera prototypes should establish the shared System IDE shell pattern rather than building throwaway debug widgets.

At minimum, Gate 1 should prove:
- the shell can open during play;
- Locomotion IDE can inspect state and tune approved numeric movement values live;
- locomotion test cases/course can be reset/reached rapidly;
- session overrides are visibly distinguished from persisted values;
- Camera IDE can later register into the same shell rather than inventing another debug architecture.

### Gates 2–4 — every new core system joins the shell
Combat, tool/puzzle, and Hush prototypes add their own System IDE modules while those systems are still small.

### Gate 5 — vertical-slice usefulness
A developer should be able to work on most slice gameplay/state systems from inside the running slice without repeatedly navigating back through Unreal editor panels and long play routes.

### Gate 6 — production durability
The shared shell, registration model, persistence/promotion path, state presets, validation surfaces, and system workbench conventions must be stable enough that region production can depend on them.

---

## 10. Definition of done

The System IDE architecture succeeds when:

- the owner can remain inside the playable game for long iteration sessions;
- each major system explains its current state and why it made important decisions;
- representative states can be reached/reset in seconds rather than replayed for minutes or hours;
- approved tunable values can be changed and evaluated immediately;
- temporary overrides cannot be confused with canonical values;
- deliberate changes can be promoted into reviewable repository-backed authority;
- new systems have a clear workbench pattern to follow;
- Claude can use semantic development surfaces rather than editor/screenshot guesswork;
- Shipping builds contain no unsafe developer IDE/control dependency.

**The goal is not merely to debug Stillring while playing. The goal is to keep developing Stillring while playing.**

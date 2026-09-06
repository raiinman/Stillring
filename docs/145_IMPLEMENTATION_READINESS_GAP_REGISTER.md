# 145 — Implementation-Readiness Gap Register

**Status:** DOCUMENTATION CLOSURE PHASE 3 — CURRENT  
**Updated:** 2026-09-05  
**Baseline main:** `22b4074e3d08358b302fd7a518773803f303990f`

## Purpose

This register answers:

> **What is designed, what is absent in UE5.8, what must be proven next, and in what order should implementation proceed?**

It is not a second roadmap. `ROADMAP.md` remains project gate authority.

It exists to stop a design-complete package from being mistaken for an implemented one.

---

# 1. Current executable baseline

The `game/` directory currently contains only `game/README.md`.

At this boundary there is no repository UE5.8 project file, gameplay C++ module, playable map, runtime System IDE, or executable save/Hush prototype.

Therefore the project is currently:

- **highly specified**;
- **minimally implemented**;
- **not production-ready**.

No document may upgrade a runtime claim without actual runtime evidence.

---

# 2. Readiness matrix

| Area | Locked design | Runtime implementation | Deterministic proof | Human-play proof | Primary next dependency |
|---|---|---|---|---|---|
| Gate 1 locomotion | yes | absent | absent | absent | Issue #5 + #58 pattern |
| Gate 1 camera/targeting | yes | absent | absent | absent | Gate 1 harness after locomotion shell |
| Shared System IDE | yes | absent | absent | N/A for architecture; usability later | Issue #58 |
| Combat | yes | absent | absent | absent | Gate 1 foundation first |
| Encounter/AI pressure | yes | absent | absent | absent | Combat runtime first |
| Gate 3 Cantor/tools/puzzles | yes | absent | absent | absent | Combat/Gate 1 foundation + IDE pattern |
| Hush/world layer | yes | production architecture unproven | absent | absent | comparative Gate 4 prototype |
| Save/World-State | yes | absent | absent | absent | Hush paired-state runtime + Issue #4 |
| Completion | yes | absent | absent | absent | semantic registries + save/world-state |
| Setup/Payoff | yes | absent | absent | absent | world-state/save + content pipeline |
| Line Skiff | yes | absent | absent | absent | locomotion/camera/world-route foundation |
| Null Meridian | yes | absent | absent | absent | all prerequisite systems + content blockout |

---

# 3. Recommended implementation order

This order minimizes duplicated architecture and lets the in-game development tooling grow with the systems.

## Step 1 — Issue #5: minimal UE5.8 Gate 1 bootstrap

Create only what the issue requires:

- `Stillring.uproject`;
- minimal C++ module/targets;
- Enhanced Input;
- graybox movement/camera test map;
- reset/reload;
- coordinates/basic performance readout;
- reproducible build/open/smoke workflow;
- Git LFS-safe binary-asset policy.

Do **not** pull later systems forward merely because Unreal makes them available.

### Exit proof

Fresh checkout can build/open/run the harness and fast validation path without manual repair.

---

## Step 2 — Issue #58 Gate 1 slice: shared System IDE shell + Locomotion IDE

Build the shell alongside Gate 1 rather than after it.

Minimum useful proof:

- open/close during play;
- shared registration model;
- Locomotion IDE reads real locomotion state;
- approved tuning values can be temporarily changed;
- canonical vs session override is obvious;
- canonical test cases can be reached/reset quickly;
- capture/provenance works;
- Camera IDE can later register without a second shell.

The IDE is not optional polish.

---

## Step 3 — Gate 1 camera/targeting runtime

Implement the locked third-person camera/targeting package against the same harness and developer shell.

### Required evidence

- exploration camera;
- collision/compression;
- recenter behavior;
- target lock/switch;
- narrow/low geometry fixtures;
- large-target framing fixtures;
- mouse/controller parity;
- accessibility settings relevant to Gate 1;
- Camera IDE registration;
- human movement/camera acceptance.

---

## Step 4 — Gate 2 combat + encounter

Implement the player combat state model first, then enemy/encounter pressure against it.

### Required evidence

- attack/guard/Perfect Guard/evade legality;
- input-buffer semantics;
- hit/interrupt/death cleanup;
- target-lock integration;
- encounter attack-bandwidth ownership;
- melee/ranged/shield archetype fixtures;
- deterministic capture;
- Combat/Encounter IDE;
- repeated human-play fairness/readability.

---

## Step 5 — Gate 3 tools/puzzles

Implement Cantor + first multi-use field-tool prototype using the established state/IDE/fixture patterns.

### Required evidence

- one coherent tool grammar across traversal/combat-pressure/puzzle use;
- mechanism reset and named fixtures;
- failure explanation;
- authoring/debug workbench;
- no puzzle solution leakage from privileged metadata;
- human comprehension.

---

## Step 6 — Gate 4 Hush architecture comparison

Do not automatically promote the earlier World Partition + Runtime Data Layers prototype direction into production architecture.

Compare at least:

1. World Partition + Runtime Data Layers;
2. a credible explicit level/Actor layering approach.

Evaluate:

- authoring clarity;
- paired semantic identity;
- source-control cost;
- collision/transition reliability;
- save/load reconstruction;
- performance/streaming;
- IDE inspection/reset;
- content-production burden.

Select production architecture only after evidence.

---

## Step 7 — Issue #4 runtime verification

Once paired Waking/Hush state exists in a real prototype:

- mutate meaningful semantic state;
- save at valid barrier;
- exit process;
- reopen;
- load;
- verify semantic state and correct representation;
- verify stable IDs rather than Actor paths;
- verify derived consumers reconcile after source owners.

Only then close Issue #4.

---

## Step 8 — first vertical slice: Brindle + S01 Crooked Fire Bell

This is the recommended first cross-system authored slice because S01 is already the canonical Setup/Payoff vertical-slice chain.

The slice should exercise:

- locomotion/camera;
- interaction;
- basic combat if required by route context;
- Cantor/tool interaction where authored;
- quest/world facts;
- Setup/Payoff priming/commit/payoff;
- save/reload;
- completion consequence where applicable;
- shared System IDE surfaces;
- ordinary player legibility without debug UI.

This slice should prove the architecture is useful for real authored game content, not only isolated test maps.

---

## Step 9 — completion/runtime registry and production content tooling

Before mass content production:

- implement semantic completion registry;
- derived exact weighting;
- migration support;
- canonical missing-item audit;
- authoring validation;
- content-count checks;
- late-assist tier support;
- completion IDE.

This is where stale legacy counts become dangerous if not blocked.

---

## Step 10 — Line Skiff prototype

Build the Line Skiff only after ordinary locomotion/camera and world-state foundations are stable.

Required prototype sequence:

- semantic route graph;
- supported-corridor vehicle handling;
- junction intent;
- camera at speed;
- save/resume;
- Hush paired-route behavior;
- representative mastery trial;
- one Drift Knot route;
- Skiff IDE.

Do not build a generic mount framework first.

---

## Step 11 — Null Meridian blockout and synthesis

Null Meridian is a synthesis test, not an early architecture sandbox.

Blockout S1–S6 only after prerequisite systems have real runtime behavior.

Required evidence includes:

- sequence dependency;
- puzzle/combat alternation;
- Hush behavior;
- Maelor;
- S6 physical disconnection;
- save/retry;
- accessibility;
- System IDE fixtures;
- human pacing/emotional acceptance.

---

# 4. Architecture blockers versus non-blockers

## True blockers before affected work

- no UE5.8 project exists: blocks all runtime work;
- no shared System IDE implementation exists: blocks production-complete status and should begin with Gate 1;
- Gate 4 production representation is not selected by evidence: blocks broad Hush content production;
- target-PC baseline is not selected: blocks objective Gate 5 performance acceptance, not Gate 1 bootstrap;
- Issue #4 paired-layer runtime proof is absent: blocks closing #4, not documenting the schema.

## Not blockers

The following should be tuned in play, not used as excuses to delay implementation:

- exact movement speed;
- exact camera distance/lag;
- exact combat frame timings;
- exact Hush transition duration;
- exact Skiff acceleration;
- exact Null Meridian room dimensions.

Locked semantics already bound these choices.

---

# 5. Evidence package required per system

A major system should not advance to `PRODUCTION-READY` without the evidence relevant to it:

1. **LOCKED DESIGN** — current authority identified.
2. **IMPLEMENTED** — code/assets exist.
3. **DETERMINISTICALLY VERIFIED** — fixtures exercise authoritative services.
4. **PERSISTENCE/RECOVERY VERIFIED** — where durable state exists.
5. **SYSTEM IDE PRESENT** — Inspect/Tune/Exercise/Validate/Capture-Promote as appropriate.
6. **ACCESSIBILITY VERIFIED** — relevant alternate inputs/comfort/redundant cues.
7. **PERFORMANCE EVIDENCE** — on the currently declared evidence machine; later on target baseline.
8. **HUMAN-PLAY VERIFIED** — where feel/readability/pacing claims are made.
9. **FRESH-CHECKOUT/REPRODUCTION** — where build/content workflow must be portable.

---

# 6. Recommended evidence vertical slices

| Slice | What it proves |
|---|---|
| Gate 1 graybox | executable foundation, locomotion/camera, shared IDE pattern, input/build workflow |
| Paired Waking/Hush save fixture | Issue #4, semantic identity, transition barriers, restore ordering |
| Brindle S01 slice | real authored cross-system state, Setup/Payoff, save, consequences, ordinary legibility |
| Representative Gate 3 mechanism | tool/puzzle authoring + reset/validation workflow |
| Representative Line Skiff route + Trial 05 | route graph, handling, high-speed camera, mastery, save/resume |
| Null Meridian S1–S6 blockout | full-system synthesis and finale pacing |

---

# 7. Broad implementation authorization boundary

This register is a recommendation, not authorization.

Until Documentation Closure Phase 4 is complete and the owner explicitly approves the implementation boundary:

> **Broad UE5.8 implementation remains unauthorized.**

If authorization is granted, the first implementation target should be **Issue #5 with the Gate 1 portion of Issue #58 built alongside it**, not a random later system.
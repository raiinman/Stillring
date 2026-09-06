# 150 — Implementation Owner Review Package

**Status:** AWAITING OWNER AUTHORIZATION  
**Updated:** 2026-09-05  
**Baseline main:** `af44e4cb79cadd593e35a4816267ec80527859d8`

## What is now locked

Stillring has current documented authority for:

- story/world/content direction;
- Gate 1 locomotion and camera/targeting;
- Gate 2 player combat and encounter behavior;
- Gate 3 Cantor/tool/puzzle rules;
- Gate 4 Hush/world-layer semantics;
- Save/World-State design and migration/recovery policy;
- the 16-category completion model and current counts/thresholds;
- all 12 Setup/Payoff chains and their authoring/runtime contract;
- Line Skiff traversal transformation/mastery rules;
- Null Meridian S1–S6 synthesis/finale structure;
- shared in-game System IDE requirements;
- state ownership, cross-system contracts, precedence, terminology, traceability, stale-literal blocklists, and runtime proof boundaries.

No additional mechanics-design round is currently required before the first UE5.8 prototype.

---

## What is **not** proven

The repository is still minimally implemented.

Not yet proven in UE5.8:

- project bootstrap/build/open workflow;
- locomotion feel;
- camera feel/readability;
- target-lock behavior;
- combat fairness/fun;
- encounter AI behavior;
- tool/puzzle usability;
- Hush production architecture/performance/comfort;
- save/load runtime behavior;
- completion runtime registry/math;
- Setup/Payoff runtime reconciliation/legibility;
- Line Skiff handling/streaming/camera;
- Null Meridian blockout/pacing;
- shared System IDE runtime shell/workbenches.

These are implementation/test obligations, not reasons to invent more paper design.

---

## Open issues that correctly remain open

### #5 — Bootstrap Gate 1 Unreal Engine 5.8 C++ prototype harness

This is the first recommended implementation target.

### #58 — Build shared in-game System IDE framework

Its Gate 1 shell + Locomotion IDE portion should be implemented alongside #5, not later as debug debt.

### #4 — Define persistent world-state and save schema

Design is substantially complete, but closure requires actual paired Waking/Hush save -> exit -> reopen -> load verification.

---

## Recommended initial implementation scope

If authorized, start narrowly:

1. create the minimal UE5.8 C++ project required by Issue #5;
2. establish Enhanced Input and the Gate 1 graybox course;
3. implement locked locomotion semantics;
4. build the shared developer shell pattern and Locomotion IDE at the same time;
5. add reset/reload/runtime state/performance readout;
6. establish reproducible build/editor/smoke-test commands and Git LFS-safe binary workflow;
7. then implement the locked Gate 1 camera/targeting package and Camera IDE in the same shell;
8. tune feel in the actual game rather than freezing fake final numbers in docs.

Do **not** begin with combat, Hush, world production, Line Skiff, Null Meridian, or production art.

Do **not** import heavyweight Unreal frameworks just because they exist.

Do **not** let stock Third Person template behavior silently define Stillring.

---

## Hard implementation rules

Authorization does not permit changing locked design for convenience.

Implementation must preserve:

- C++-first gameplay/state authority;
- thin presentation-oriented Blueprints unless explicitly justified;
- one authoritative writer per durable fact;
- stable semantic IDs for persisted/content-addressed state;
- no Actor/map/node/runtime IDs as canonical persistence identity;
- no ordinary traversal stamina/fuel grind;
- no free/universal climbing;
- no unapproved first-person/precision-aim camera grammar;
- no System IDE shadow state;
- no stale completion constants;
- no Data Layer state as Hush/world truth;
- no procedural two-timeline duplication for Setup/Payoff;
- no free-roam/summon-anywhere Line Skiff mount behavior;
- no optional-completion `true ending` gate;
- no claim of runtime/human proof without evidence.

---

## Implementation workflow

For each system:

**authority -> implementation -> System IDE -> deterministic fixtures -> save/recovery where relevant -> accessibility/performance evidence -> human play -> accepted tuning**

A feature that works only for the player but cannot be inspected/reset/validated efficiently is not production-complete.

---

## First human review checkpoint

After the Gate 1 harness can be run reliably, the owner should review movement/camera **in play** before later gates are allowed to treat those values as stable.

That review should focus on feel rather than architecture minutiae:

- does ordinary movement disappear beneath intention?;
- does sprint feel fast without becoming slippery or costly?;
- does jump/mantle help without turning every wall into traversal?;
- does the camera stay useful without being babysat?;
- does target lock remain precise without autopilot?;
- are narrow spaces/low ceilings/large targets readable?;
- do the IDE controls make iteration fast enough to keep tuning inside the game?

---

## Later owner decision — not a Gate 1 blocker

Before objective Gate 5 performance acceptance and platform-specific release/certification work, select:

- target-PC hardware/performance baseline;
- intended launch platform scope.

Gate 1 may begin on the available development machine as long as evidence records the actual hardware/context and does not pretend it is the shipping baseline.

---

# Owner authorization decision

## Recommended decision

**AUTHORIZE** broad UE5.8 implementation, with the initial scope constrained to:

> **Issue #5 + the Gate 1 portion of Issue #58, followed by the already-locked Gate 1 camera/targeting runtime and Camera IDE.**

All later systems remain gated by the roadmap, evidence, and human-review boundaries already documented.

### What “authorize” means

It means:

- implementation may now begin;
- engineering may make Class-B implementation choices inside locked design without asking the owner about every class name/technical detail;
- Class-C tuning questions are resolved through prototype + human play;
- genuine new Class-F design/product decisions still come back to the owner;
- the owner retains final human acceptance at the gate boundaries.

### What “authorize” does not mean

It does not mean:

- auto-approve gameplay changes;
- skip owner play review;
- treat runtime evidence as optional;
- build the entire game at once;
- close Issues #4/#5/#58 before evidence exists;
- let an implementation agent invent missing canon.

---

# Required owner response

Choose one:

- **APPROVED — BEGIN UE5.8 IMPLEMENTATION**
- **HOLD — KEEP DOCUMENTATION-ONLY**
- **APPROVED WITH CHANGE —** state the scope change

Recommendation: **APPROVED — BEGIN UE5.8 IMPLEMENTATION.**
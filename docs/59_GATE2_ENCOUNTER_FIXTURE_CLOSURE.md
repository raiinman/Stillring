# 59 — Gate 2 Encounter Fixture / Reset / Cumulative Closure

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #10 for GitHub Issue #104. Defines deterministic development fixtures, reset semantics, death/checkpoint cleanup boundaries, Combat/Encounter IDE controls, machine-verifiable invariants, and cumulative acceptance for the Gate 2 enemy/encounter specification.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Fixture principle:
> **A combat bug should be reproducible in seconds, not rediscovered by replaying the game.**

This decision adds no new enemy combat verb. It proves Decisions #1–#9 repeatedly and closes the enemy/encounter policy system for Gate 2.

---

## Decision #10 — spawn / reset / debug fixture contract — LOCKED

### 1. Every development encounter fixture has a stable semantic ID
A fixture is a named development setup with repository-backed identity, for example conceptually:
- `Encounter.Single.Melee.Basic`
- `Encounter.Pair.MeleeRanged`
- `Encounter.Trio.MeleeRangedShield`
- `Encounter.Stress.Five.Mixed`
- `Encounter.Edge.OffscreenPressure`
- `Encounter.Edge.DisengageReturn`

Exact names are implementation choices. Stable semantic identity is required.

Fixture IDs are not player-facing encounter names and do not become canonical story IDs automatically.

### 2. Fixture data declares setup, not hidden combat rules
Each fixture records enough information to reproduce a scenario:
- map/test area or scenario location;
- player start transform/facing;
- player health/loadout/combat state preset where appropriate;
- enemy roster with stable fixture-local IDs;
- enemy archetype/class/data reference;
- spawn transform/initial facing;
- authored encounter territory/home/fallback references;
- initial encounter lifecycle state;
- optional target-lock selection;
- optional visibility/occlusion arrangement;
- intended authority/test tags;
- reset policy;
- expected machine invariants;
- whether human feel/readability review is required.

The fixture may select approved data. It may not invent a new attack permission, resistance, shield rule, camera behavior, or AI policy.

### 3. Deterministic spawn registration order
For a given fixture/version:
- roster members receive stable fixture-local identity;
- spawn/registration ordering is deterministic;
- encounter coordinator registration completes before any enemy may request an attack commit;
- occupancy/role data initializes before active combat;
- no actor is allowed to attack during a partially-created fixture.

Determinism is required for debugging even where AI movement later contains authored randomness.

### 4. Spawn placement must be validated before combat begins
A fixture spawn is invalid if it begins:
- inside blocking geometry;
- overlapping another actor beyond accepted setup tolerance;
- outside required navigation/support surface without explicit airborne/special authority;
- already inside unavoidable active-hit range with no authored test reason;
- behind hard cover with a pre-granted impossible firing lane;
- in a position that violates the fixture's declared visibility/composition premise.

A failed setup reports failure; it does not silently move actors to arbitrary fallback locations and pretend the same case ran.

### 5. Reset is one authoritative transaction
A fixture reset must clear and restore the scenario through one coordinated reset service rather than many unrelated debug buttons racing each other.

Baseline reset clears:
- current MajorCommit / PressureCommit reservations;
- queued/denied permission state;
- approach/pressure occupancy reservations;
- attack Telegraph/Active/Recovery transient state;
- active enemy hit volumes/traces;
- enemy reaction/retrigger state;
- shield transient states such as `ShieldDisplaced` / attack Exposure;
- offscreen threat indicators/audio/haptic transient warnings;
- engagement/disengage/return transient state;
- AI transient target/perception/request state where fixture authority owns it;
- fixture-spawned projectiles and other transient attack actors;
- temporary debug-forced state;
- stale target lock to removed/replaced actors.

Then reset restores declared fixture baseline in a deterministic order.

### 6. Reset distinguishes fixture-owned actors from unrelated world state
A fixture reset may destroy/recreate or restore only actors/state it owns or explicitly declares.

It must not casually:
- reset unrelated NPCs/quests;
- mutate Hush/world layer state;
- clear story flags;
- reload arbitrary region state;
- delete ambient actors outside the fixture contract.

Later world-state fixtures may compose higher-level presets through their own authority.

### 7. Reset may respawn fixture enemies because fixture reset is explicit authority
Decision #9 forbids dead enemies reviving merely because aggro dropped. Decision #10 distinguishes a deliberate development/reset event.

When an explicit fixture reset occurs:
- dead fixture enemies may be recreated/restored to declared baseline;
- health/resources restore to fixture values;
- home transforms/states restore;
- this is visible in the IDE/capture as `FixtureReset`, not ordinary disengagement.

Production checkpoint respawn policy remains a higher-level save/checkpoint contract unless already explicitly owned by the test fixture.

### 8. Already-launched projectiles are cleared only by explicit reset ownership
World-causal projectiles remain real during ordinary combat/disengage. A deliberate fixture reset may remove fixture-owned projectiles because the entire scenario is being restored.

The distinction must be inspectable:
- `ProjectileResolvedWorld` versus
- `RemovedByFixtureReset`.

### 9. Player reset is explicit and bounded
Fixture controls may restore Neris to declared development baseline:
- transform;
- health;
- target lock;
- combat state;
- representative loadout;
- approved combat resource state if any;
- camera reset/recenter where the scenario declares it.

This calls authoritative player services. It does not directly mutate opaque animation flags and hope gameplay follows.

### 10. Player death cleanup integrates through the same encounter reset boundary
For development fixtures, Neris Death must:
- stop new enemy commits;
- complete/clean active threat state under player death authority;
- preserve structured death evidence before reset;
- allow a one-action fixture retry that restores player + fixture encounter baseline;
- never require manually deleting stale enemy/projectile state.

Production checkpoint/save respawn semantics remain separate future authority; the fixture proves the cleanup interface they will call.

### 11. Required canonical Gate 2 encounter fixtures
At minimum the Encounter IDE must provide named cases for:

#### Solo archetype
- single melee;
- single ranged;
- single shield.

#### Pair
- two melee duplicates;
- melee + ranged;
- melee + shield;
- ranged + shield.

#### Trio
- melee + ranged + shield representative composition.

#### Stress / edge
- five-enemy mixed pressure;
- simultaneous ready requests;
- visible Major + ranged Pressure overlap;
- offscreen ranged pressure eligibility;
- hard-occluded ranged source;
- cramped-room composition;
- target-switch while secondary threat commits;
- Heavy interrupt of current Major holder;
- repeated Light anti-stunlock case;
- disengage / return / re-entry;
- player death during active commit.

### 12. Fixture randomization is opt-in and seed-visible
Baseline acceptance fixtures use deterministic initial conditions.

If later fuzz/stress tests randomize:
- seed is explicit and captured;
- roster/rules remain within approved semantic authority;
- a failing seed can be rerun exactly;
- randomization never replaces named representative cases.

### 13. Machine validation versus human-play authority
Machine checks should prove semantic invariants such as:
- no more than approved MajorCommit concurrency;
- PressureCommit eligibility rules;
- no attack through blocked geometry;
- no committed tell without permission;
- no fake urgent tell from denied enemies;
- no stale hit state after interruption/reset;
- no target-lock-as-AI-permission coupling;
- no universal hidden poise meter;
- no Light reaction infinite timer reset;
- no occupancy double reservation;
- no attack during Returning;
- no stale warning/projectile/reservation after explicit fixture reset;
- deterministic fixture setup and teardown.

Machine checks do **not** close:
- ten-minute combat satisfaction;
- telegraph comfort/readability;
- whether Heavy disruption feels earned;
- whether composition feels active instead of choreographed;
- whether offscreen warning is distracting;
- whether movement space feels fair.

Those require human play.

### 14. Structured capture is first-class evidence
Every fixture run can produce a structured capture including:
- fixture ID/version/seed;
- source build/commit;
- map/scenario;
- player baseline;
- enemy roster and stable fixture IDs;
- encounter lifecycle;
- occupancy/reservations;
- attack permission timeline;
- telegraph/active/recovery phases;
- offscreen/occlusion state and warning channels;
- player inputs/Guard/Perfect Guard/Evade/attacks;
- hit/reaction/resistance outcomes;
- projectiles;
- disengage/reset transitions;
- validation failures;
- timestamps/frame sequence.

Video/screenshots may supplement but are not the only evidence.

### 15. Reproduction records are portable within compatible builds
A capture/repro record should retain enough semantic data to load the named fixture and reapply supported setup values.

It must explicitly report incompatibility if:
- fixture ID/version no longer exists;
- referenced archetype/data changed incompatibly;
- map/test geometry is missing;
- schema changed.

Do not silently approximate an old repro and call it identical.

### 16. Development mutations carry provenance
Encounter IDE values/actions distinguish:
- canonical repository-backed fixture data;
- session override;
- staged development change;
- promoted/saved change.

Developer actions such as `Set Health`, `Force Major Holder`, `Force Visibility Classification`, or `Teleport Enemy` are clearly marked forced/debug state.

Forced state does not become evidence that normal gameplay eligibility works unless the test specifically exercises forced-state handling.

### 17. Debug controls use gameplay services where practical
IDE actions should call the same authoritative services used in normal play for:
- encounter reset;
- enemy damage/death;
- player health/state restore;
- target lock;
- spawn registration;
- commit requests/releases;
- shield/reaction state setup where supported.

Direct low-level mutation is reserved for explicit diagnostic force controls and must be labeled accordingly.

### 18. Gameplay Debugger may supplement the Encounter IDE
Unreal's Gameplay Debugger can display AIController, Behavior Tree, EQS, Perception, and NavMesh runtime evidence and supports project-specific categories.

Stillring may extend/use it for low-level corroboration, but the Encounter System IDE remains the semantic authoring/exercise/validation surface under `docs/21`.

Raw Blackboard values are not a replacement for human-readable reasons such as `Denied_HardOccluded` or `Disengage_NoCredibleReachableFight`.

### 19. Automation framework may drive fixture invariants
Current Unreal 5.8 testing infrastructure supports:
- C++ Automation tests;
- CQTest fixtures with setup/teardown;
- latent/spec-style tests;
- command-line execution and structured exported reports;
- optional later Gauntlet orchestration for packaged sessions.

Recommended Gate 2 use:
- fast C++/CQTest checks for pure state/invariant logic;
- map/functional/latent automation for representative encounter fixture flows;
- command-line smoke group for CI/local verification;
- Gauntlet only when packaged-session orchestration is justified later, consistent with ROADMAP.

The automation framework executes approved fixture contracts; it does not define encounter behavior.

### 20. Retail boundary
Fixture/Encounter IDE mutation surfaces are Development/Test only.

Shipping must not require:
- Gameplay Debugger;
- CQTest/Automation modules as gameplay dependencies;
- external model/API calls;
- remote developer control listeners;
- fixture reset UI;
- test-only spawn controls.

The retail encounter runtime contains authored gameplay services, not the developer harness.

---

## Cumulative Gate 2 enemy / encounter authority

With Decisions #1–#10 locked, the system now has an implementation-facing policy chain:

1. **Attack bandwidth** — group owns commit permission; one ordinary MajorCommit baseline; approved Pressure lane only.
2. **Melee pressure** — honest spatial pressure, real whiffs, no magnetism/input reading, active yield/recovery.
3. **Ranged pressure** — visible non-homing projectile, real fire corridor, frozen bounded launch lead, conditional Pressure eligibility.
4. **Shield/armor** — directional stateful defense with flank/Heavy/Exposure/Perfect Guard tempo answers; no hidden durability/posture.
5. **Telegraph/readability** — committed warnings are truthful gameplay promises with world/body evidence first.
6. **Offscreen/occluded threats** — invisible attacks obey stricter readability and geometry; supplemental threat indicator is bounded, not radar; camera never rescues threats.
7. **Enemy reaction/interrupt** — explicit ImpactForce versus state ReactionResistance, no universal poise meter, Heavy disruption role, anti-stunlock protection.
8. **Composition/coordination** — complementary roles, world-aware occupancy, arena obligation, quality-before-concurrency difficulty scaling.
9. **Disengage/reset/re-entry** — semantic engagement viability and readable return, no magic leash/heal line, causal re-entry.
10. **Fixture/proof contract** — deterministic named scenarios, transactional reset, structured evidence, System IDE and Automation coverage.

---

## Combat / Encounter System IDE cumulative minimum

The workbench must now support:

### Inspect
- encounter fixture/roster/lifecycle;
- role/occupancy;
- target lock separately;
- AI readiness and attack-permission requests;
- Major/Pressure holders;
- telegraph/action phases;
- visibility/occlusion/fire corridor;
- offscreen warning state;
- health/damage/reaction/ImpactForce/Resistance;
- shield states;
- projectiles;
- disengage/return/reset evidence;
- validation/reason codes;
- build/fixture provenance.

### Tune
Only approved prototype values with provenance, including:
- handoff/readability timings;
- positioning/occupancy weights;
- telegraph/presentation timing;
- visibility/warning thresholds;
- reaction durations/protection;
- disengage hysteresis;
- fixture setup values.

### Exercise
All named Decision #10 fixtures plus per-decision cases in docs/50–58.

### Validate
All semantic invariants listed across docs/50–59, with human-readable failure reasons.

### Capture / Promote
Structured deterministic encounter timeline and reviewable promotion path. Session overrides may never masquerade as canonical enemy policy.

---

## Representative cumulative acceptance run

A Gate 2 enemy/encounter prototype should be able to execute repeatedly:
1. load/reset the melee+ranged+shield trio fixture;
2. fight normally for several minutes;
3. switch lock among all enemies without changing AI permission semantics;
4. observe one ordinary MajorCommit plus only approved readable ranged Pressure overlap;
5. Guard/Evade/Perfect Guard/Light/Heavy and verify reactions/shield answers;
6. turn away from a committed threat and verify bounded offscreen communication;
7. use hard cover and verify honest projectile/LOS behavior;
8. interrupt current Major holder and verify deterministic handoff;
9. leave the encounter and verify semantic Disengaging/Returning behavior;
10. re-enter before full reset and verify causal retained state;
11. trigger explicit fixture reset and verify complete deterministic baseline restoration;
12. repeat at representative 30/60/120+ FPS and with audio/vibration/shake accessibility variations.

Human acceptance target remains ROADMAP's Gate 2 condition:
> **Ten minutes of repeated combat remains readable and satisfying without story or final art.**

The documentation locks the testable design contract; fresh playable human evaluation remains required after implementation.

---

## Research basis

### Current primary engine references
- Epic Games, Unreal Engine 5.8, **Gameplay Debugger** — runtime AIController/Behavior Tree/EQS/Perception/NavMesh inspection and project-extensible categories.  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/using-the-gameplay-debugger-in-unreal-engine
- Epic Games, Unreal Engine 5.8, **CQTest** — C++ test fixtures/common commands with before/after setup/teardown support.  
  https://dev.epicgames.com/documentation/unreal-engine/cqtest-test-framework-for-unreal-engine
- Epic Games, Unreal Engine 5.8, **Run Automation Tests** — Editor/Frontend/command-line execution and structured report export.  
  https://dev.epicgames.com/documentation/unreal-engine/run-automation-tests-in-unreal-engine
- Epic Games, Unreal Engine 5.8, **Spawning Actors** — `UWorld::SpawnActor` is the runtime actor construction primitive; Stillring wraps spawning in deterministic fixture registration/validation rather than treating SpawnActor as fixture semantics.  
  https://dev.epicgames.com/documentation/unreal-engine/spawning-actors-in-unreal-engine

### IP boundary
This fixture/testing contract copies no encounter composition, enemy AI, timings, map layout, or developer UI from another game.

---

## Why this package is approved
Decision #10 turns the nine preceding design decisions into something production can actually iterate:
- every important case has a stable reproduction entry point;
- reset is transactional and cannot leave ghost state;
- debug controls remain visibly separate from canonical gameplay authority;
- machine tests prove invariants while human play still owns feel;
- structured captures replace memory/video archaeology;
- the System IDE is part of the feature instead of deferred debt;
- the harness can later support checkpoint/save systems without defining them prematurely.

---

## Issue #104 closure criteria
Issue #104 is ready to close as **design/specification complete** when this document is merged because all ten scoped decisions are individually locked and cumulative acceptance/IDE evidence is defined.

This does **not** claim the Gate 2 Unreal prototype has been implemented or human-play accepted. Implementation and playable verification remain future production work under the existing CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY pipeline.

---

## Next system boundary
After Issue #104 closes, re-read `ROADMAP.md` and open project issues before selecting the next unresolved **design system**. Do not infer the next system from this encounter document and do not jump into implementation merely because Gate 2 design is now specified.
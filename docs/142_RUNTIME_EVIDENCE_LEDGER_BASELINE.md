# 142 — Runtime Evidence Ledger Baseline

**Status:** CANONICAL EVIDENCE-STATUS BASELINE  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 2  
**Baseline main:** `4c65b2429dbb601e9c5ba0124cc0d27dc4a31a35`

## Purpose

Stillring's documentation is intentionally far ahead of its implementation.

That is useful only if the repository never confuses:
- design authority;
- implementation existence;
- deterministic runtime verification;
- human-play acceptance.

This ledger records the evidence boundary before UE5.8 implementation begins.

Core rule:

> **No evidence row becomes green because a design document is detailed.**

---

# 1. Current executable-project baseline

At this baseline, repository `game/` contains only:

`game/README.md`

The README explicitly says the directory is intentionally skeletal until Gate 1 bootstrap and that Gate 1 must create:
- `Stillring.uproject`;
- minimal C++ module/target files;
- Enhanced Input baseline;
- graybox movement/camera test map;
- minimal debug/performance readout;
- reproducible build/editor-load/Automation entry points.

Therefore the repository currently has **no accepted UE5.8 executable project proof**.

This is not a failure.

It is the intentional pre-bootstrap boundary tracked by Issue #5.

---

# 2. Evidence-state vocabulary

## DESIGN

Owner-approved behavior/data/architecture contract exists.

## CODE/ASSET EXISTS

Relevant UE5.8 code/assets are present in repository.

## BUILD/LOAD PROOF

Fresh/reproducible UE5.8 project build/editor-open evidence exists.

## DETERMINISTIC FIXTURE PROOF

Repeatable semantic fixture/test exercises the real authoritative service and passes expected assertions.

## SAVE/RELOAD PROOF

Relevant durable state survives the exact required save/exit/reload or checkpoint/retry contract.

## ACCESSIBILITY PROOF

Required accessibility settings/cue redundancy operate in runtime without invalidating progression/completion.

## PERFORMANCE PROOF

Representative target hardware/content scale has measured evidence within approved budget/experience goals.

## HUMAN-PLAY PROOF

Human play accepts the scoped feel/readability/pacing/fun/emotional claim.

## PRODUCTION PROOF

All evidence required for the scoped production-ready claim has passed.

---

# 3. Project-wide baseline

| Evidence category | Current status | Accepted evidence at baseline | Blocking/open boundary |
|---|---|---|---|
| UE5.8 project exists | **NO** | `game/` skeletal README only | Issue #5 |
| Reproducible C++ build | **NO** | none | Issue #5 |
| Editor opens project | **NO** | none | Issue #5 |
| Enhanced Input runtime | **NO** | none | Issue #5 |
| Graybox Gate 1 map | **NO** | none | Issue #5 |
| Shared System IDE shell | **NO** | design doc 21 only | Issue #58 |
| Automation/smoke entry point | **NO** | design/roadmap only | Issue #5 / future gates |
| Save/persistence runtime | **NO** | design docs 81–88 only | Issue #4 |
| Paired Hush save/exit/reload | **NO** | design contract only | Issue #4 |
| Shipping build developer-shell exclusion | **NO** | design contract only | Issue #58 / build pipeline |
| Human playable vertical slice | **NO** | design only | future Gate 5 |

---

# 4. System evidence matrix

Legend:
- **D** = design authority exists;
- **C** = code/assets exist;
- **F** = deterministic fixtures passed;
- **S** = save/reload proof where applicable;
- **A** = accessibility runtime proof;
- **P** = performance proof;
- **H** = human-play proof.

`YES` under D does not imply any other column.

| System | D | C | F | S | A | P | H | Notes |
|---|---:|---:|---:|---:|---:|---:|---:|---|
| Shared UE5.8 bootstrap | YES | NO | NO | N/A | N/A | NO | NO | Issue #5; no `.uproject` yet |
| Locomotion | YES | NO | NO | N/A | NO | NO | NO | Gate 1 first player-feel proof |
| Camera / Targeting | YES | NO | NO | N/A | NO | NO | NO | Gate 1; high/low geometry and target readability require play |
| System IDE shell | YES | NO | NO | N/A | N/A | NO | NO | Issue #58 |
| Combat | YES | NO | NO | retry proof NO | NO | NO | NO | Gate 2 |
| Enemy / Encounter | YES | NO | NO | encounter-retry NO | NO | NO | NO | Gate 2 |
| Interaction / traversal objects | YES | NO | NO | world-persistent cases NO | NO | NO | NO | spans Gate 1/3/world production |
| Cantor / major tools | YES | NO | NO | progression/puzzle durable cases NO | NO | NO | NO | Gate 3 |
| Puzzle / mechanism framework | YES | NO | NO | durable mechanism cases NO | NO | NO | NO | Gate 3 |
| Hush / World-Layer | YES | NO | NO | **NO** | NO | NO | NO | Gate 4; Issue #4 paired-layer proof remains open |
| Save / World-State | YES | NO | NO | **NO** | N/A | NO | N/A | Issue #4 |
| Quest / Objective / World progression | YES | NO | NO | NO | N/A | NO | NO | vertical-slice proof needed |
| Dialogue / NPC recurrence | YES | NO | NO | NO | NO | NO | NO | story/content runtime absent |
| Inventory / Tool Progression | YES | NO | NO | NO | N/A | NO | NO | required before Gate 3/vertical slice |
| Completion / 100% | YES | NO | NO | NO | NO | NO | NO | reconciliation only on paper |
| Setup / Payoff | YES | NO | NO | NO | NO | NO | NO | Issue #9 closed design-only; S01 vertical-slice runtime unproven |
| Line Skiff / Route Network | YES | NO | NO | NO | NO | NO | NO | Issue #10 closed design-only |
| Drift Knots / Route Listener | YES | NO | NO | NO | NO | NO | NO | depends on Skiff + completion runtime |
| Null Meridian S1–S6 | YES | NO | NO | NO | NO | NO | NO | Issue #11 closed design-only |
| Maelor boss | YES | NO | NO | retry/save NO | NO | NO | NO | exact encounter timing/content runtime absent |
| Listener / final decommission | YES | NO | NO | save boundary NO | NO | NO | NO | emotional/playable proof absent |
| Full story route | YES | NO | NO | NO | NO | NO | NO | no playable campaign yet |
| 100% campaign | YES | NO | NO | NO | NO | NO | NO | no playable campaign yet |

---

# 5. Gate 1 evidence obligations — Issue #5

Issue #5 remains the first executable proof boundary.

Required evidence before Gate 1 bootstrap can be considered complete must include at minimum:

## Repository / build
- actual `game/Stillring.uproject`;
- C++ module/target structure;
- UE5.8 association/toolchain documented;
- reproducible project-file/build process;
- fresh checkout succeeds;
- Git LFS handling for Unreal binary assets is proven.

## Runtime
- project opens in UE5.8;
- Enhanced Input active;
- graybox Gate 1 course loads;
- locomotion/camera systems are real project services/components, not design-only stubs;
- player can reset/reach representative cases quickly;
- basic performance/debug readout works.

## Automation
- at least a minimal smoke/Automation path;
- semantic state readout/assertion where available;
- failure is machine-detectable.

## Human
- owner can play the Gate 1 course;
- baseline control/camera behavior can be evaluated;
- no claim of final feel before tuning/acceptance.

---

# 6. Locomotion evidence obligations

Deterministic/runtime:
- grounded start/stop/turn;
- sprint availability with no stamina/resource consumption;
- jump;
- low obstacle mantle/scramble;
- stairs/slope handling;
- ledge grab/release;
- same-handhold shimmy limits;
- no corner-wrap/gap-transfer leakage;
- fall/landing classification;
- death/retry where relevant;
- remap/accessibility control behavior.

Human:
- low-speed precision;
- responsiveness;
- jump usefulness without making authored height gates meaningless;
- traversal readability;
- animation/physics confidence;
- no movement system feels like friction added for its own sake.

---

# 7. Camera / Targeting evidence obligations

Deterministic/runtime:
- free camera/recenter;
- collision near wall/ceiling/low geometry;
- target acquisition/rejection;
- target switching;
- target loss/reacquire;
- multiple enemy arrangements;
- locomotion/combat target-relative frame continuity;
- Hush target continuity later;
- high-speed Skiff camera later.

Accessibility:
- shake/reduced motion options;
- camera sensitivity/inversion/remap persistence;
- critical targeting information not single-channel.

Human:
- motion comfort;
- spatial awareness;
- target readability;
- camera does not fight player intent;
- camera preserves authored puzzle/world observation.

---

# 8. Combat / Encounter evidence obligations

Runtime fixtures:
- attack state timings;
- guard/perfect guard;
- evade;
- hit/hurt/interrupt;
- death/retry cleanup;
- one/two/three/five enemy fixtures where authority calls for them;
- melee/ranged/offscreen pressure;
- occlusion rules;
- attack bandwidth scheduler;
- narrow doorway/space cases;
- already-launched projectile persistence;
- target/camera coordination.

Human:
- fairness/readability;
- combat feels deliberate but responsive;
- multi-enemy pressure does not become camera tax;
- no one mandatory sensory channel;
- boss/miniboss readability.

---

# 9. Gate 3 Tool / Puzzle evidence obligations

Runtime:
- Cantor diagnostic base loop;
- source-target compatibility;
- Anchor physical contract;
- traversal/combat/puzzle Anchor uses;
- mechanism state reset;
- durable vs transient tool state;
- inventory/tool progression;
- save/reload around durable mechanisms;
- IDE explanations of eligibility/rejection.

Human:
- tool relationship is understandable from world/presentation;
- puzzles do not require reading debug logic;
- tools feel like coherent verbs rather than colored keys;
- optional upgrades change possibility/handling rather than percentages only.

---

# 10. Gate 4 Hush evidence obligations

Runtime:
- semantic Waking/Hush state exists independently of Data Layer load state;
- legal seam transition;
- illegal seam rejection;
- paired persistent ID mapping;
- collision/geometry handoff;
- locomotion continuity;
- camera continuity;
- combat/target continuity;
- tool/puzzle continuity;
- representation unload/reload;
- saved semantic facts remain queryable while Actor unloaded.

Save:
- save only at stable semantic boundary;
- exit process;
- reopen/reload;
- correct semantic layer restored;
- shared fact appears once and drives both representations;
- no half-transition state serialized.

This proof is required before Issue #4 can close.

Performance:
- real paired-area memory/streaming measurements;
- authoring/source-control workflow evidence;
- World Partition/Data Layer architecture validated under actual content scale.

Human:
- transition is readable and comfortable;
- Waking/Hush relationship does not feel like arbitrary teleportation;
- puzzles communicate state without mandatory pitch/color alone.

---

# 11. Save / World-State evidence obligations

Runtime/fixtures:
- stable semantic IDs independent of Actor load;
- schema v1 record construction;
- owner registration graph;
- coherent snapshot boundary;
- migration alias/split/merge/tombstone fixtures;
- malformed/corrupt/incompatible recovery;
- checkpoint fallback;
- source-before-derived restore;
- Setup/Payoff reconciliation;
- Completion recompute;
- unique encounter transaction;
- pickup transaction;
- developer named preset through owner APIs;
- duplicate-owner rejection.

Disk/process:
- asynchronous/write behavior as chosen by implementation;
- interrupted-write recovery;
- slot/cadence/retry contract.

Issue #4 remains OPEN until its exact runtime verification criterion is met.

---

# 12. Completion evidence obligations

Machine:
- all 16 categories registered;
- exact canonical item counts;
- exact rational/integer-equivalent internal arithmetic;
- one-decimal display;
- incomplete rounding cap at 99.9;
- only all requirements + story complete yields 100.0;
- aliases/migrations/splits/merges/tombstones;
- legacy literal rejection;
- K01/K02/Drift thresholds use reconciled values;
- global-item/internal-stage distinctions;
- idempotent settlement;
- Canonical Missing-Item Audit.

Human:
- accounting is understandable without spoiling hidden content;
- assist tiers help without turning into mandatory radar;
- 100% route remains an exploration/completion experience rather than checklist fatigue.

---

# 13. Setup/Payoff evidence obligations

Runtime definitions:
- one semantic-ID chain definition source;
- no per-chain Blueprint authority;
- declarative typed predicates;
- named deterministic source-owned provider escape hatch;
- commit/resolution receipts separate from source facts.

Fixtures:
- before setup;
- setup performed;
- ignored/non-intervention;
- committed variants;
- payoff available;
- each valid outcome;
- temporary unavailable;
- NPC absent;
- unexpected order;
- save/reload at every boundary;
- superseded/equivalent resolution;
- duplicate attempt;
- contradiction injection;
- dependency-cycle detection.

Vertical slice:
- S01 Crooked Fire Bell is naturally noticed later;
- materiality/legibility/causality/history tests pass in play;
- no hidden morality meter;
- valid branch cannot unknowingly destroy completion.

Human:
- consequence feels remembered rather than announced;
- player can understand known unresolved state without spoilers;
- portfolio does not feel like twelve copies of the same dilemma.

---

# 14. Line Skiff evidence obligations

Runtime:
- semantic route graph;
- route segment identity independent of spline Actor;
- acceleration/coast/brake/lateral/junction input;
- supported corridor enforcement;
- Roadhand Pulse route infrastructure behavior;
- Switchshoe alternate junction behavior;
- no summon-anywhere/cross-country leak;
- parking/recovery;
- save/reload stable resume;
- source-world fact changes re-derive legal route;
- legal/illegal Hush aboard transition;
- Trial 05;
- Drift Knot integration;
- Route Listener post-12/12 behavior.

Performance:
- high-speed streaming/HLOD;
- route visibility/collision;
- camera at speed;
- representative regional travel.

Human:
- Skiff is fun before it becomes a mastery/chase tool;
- route network feels like world infrastructure, not racetrack menu;
- micro-control feels meaningful without fake free-roam promise;
- camera remains comfortable/manual.

---

# 15. Null Meridian evidence obligations

Machine/debug-loadout:
- Story Minimum;
- Representative Partial;
- Full Completion;
- Upgrade-Stripped Audit;
- no optional Pattern/upgrade gates mandatory path;
- direct S1–S6 load fixtures;
- prior dependency settlement;
- local reset;
- death/retry;
- save/reload at semantic boundaries;
- Hush legal/illegal cases;
- combat pressure variants;
- S6 Local Accord absent/present;
- source-owner validation;
- scene-order validation.

Sequence-specific:
- S1 independent walkway motion is readable;
- S2 unlike machine end states are readable;
- S3 contradictory door history works without truth-detector framing;
- S4 Hush traversal + combat continuity works;
- S5 preserved/current battle distinction works without Cantor exposing AI/future attacks;
- S6 local services continue after relay disconnect and Common Measure remains temporary coordination.

Human:
- each major problem can be understood in one ordinary sentence;
- dungeon is remembered as one place/idea, not six exam rooms;
- first half breathes before combat escalation;
- Quiet Court midpoint lands;
- Maelor workspace quiet beat lands;
- S6 silence/local-restart beat reads as intentional, not bug;
- pacing into Maelor is strong.

---

# 16. Maelor evidence obligations

Runtime:
- core combat remains authoritative;
- silenced tells retain redundant non-audio readability;
- delayed echoes behave deterministically/fairly;
- preserved objects/arena states follow source ownership;
- false histories use existing diagnostic language;
- no optional item gates fight;
- no new boss-only mandatory input/verb;
- death/retry restores reviewed safe baseline.

Human:
- emotionally hard but mechanically readable;
- technical competence is legible;
- boss escalates language learned in dungeon;
- does not become six inventory locks;
- argument remains shorter than world evidence.

---

# 17. Listener / final decommission evidence obligations

Runtime:
- playable preserved desirable states;
- actual selected save-state/content memories where feasible and safe;
- pleasant state inability to progress is mechanically legible;
- Listener remains nonstandard confrontation, not health-bar boss;
- final player action decommissions central heart through established relationships;
- controlled release settles Hush/world state consistently;
- canonical ending is valid without 100%;
- optional completion changes specificity/preparedness/credits, not ending validity.

Human:
- temptation feels genuinely desirable first;
- wrongness emerges through inability to progress rather than horror filter;
- final destructive act feels correct **and costly**;
- release has wonder/sorrow, not victory-lap boss tone.

---

# 18. System IDE evidence obligations

Issue #58 runtime proof must eventually show:
- shell works during play;
- registered workbench architecture;
- authoritative state read;
- real-service mutation;
- session override provenance;
- reset/preset workflow;
- human-readable validation;
- capture/promotion path;
- second system can register without new shell architecture;
- Shipping exclusion.

Every later system must show its workbench uses the same authority as gameplay.

A screenshot of a debug menu is not sufficient evidence.

---

# 19. Evidence artifact format

Future accepted proof should identify:
- exact Git commit;
- UE version;
- build configuration;
- map/fixture/preset ID;
- test/automation command where applicable;
- relevant semantic IDs;
- result;
- logs/assertions;
- save files/migration fixture IDs where relevant;
- performance capture context where relevant;
- accessibility preset where relevant;
- human reviewer/acceptance note for subjective claims.

Evidence should be reproducible whenever the claim is objective.

---

# 20. What does not count as runtime proof

Do not promote these into runtime evidence:
- design document;
- pseudocode;
- schema sketch;
- screenshots of a static mockup;
- a PR being merged;
- a compile-free code draft;
- a Blueprint graph viewed in editor but not run;
- assistant/agent assertion;
- `should work` reasoning;
- engine documentation saying a feature exists;
- one successful run with no recorded commit/fixture context;
- a shadow debug state that does not exercise gameplay authority.

---

# 21. Baseline conclusion

Stillring is currently:

> **highly specified, minimally implemented.**

That is the intended state before Gate 1.

The Documentation Closure Program should preserve that honesty while making implementation much safer.

Broad UE5.8 implementation remains unauthorized until the closure program reaches final owner review.

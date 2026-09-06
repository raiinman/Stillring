# 141 — System IDE Coverage Matrix

**Status:** CANONICAL DEVELOPMENT-WORKBENCH COVERAGE AUTHORITY  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 2  
**Tracks:** GitHub Issue #58 — shared in-game System IDE framework

## Purpose

Stillring's System IDE rule is not optional polish:

> **Build the system and its in-game IDE together.**

This matrix consolidates the workbench obligations already spread across system authorities and makes missing IDE capability visible as feature debt.

It does **not** claim any workbench is currently implemented.

At this baseline, Issue #58 remains open.

---

# 1. Shared shell contract

Authority:

`docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`

The shared developer shell must eventually provide:
- controller/keyboard open/close;
- registered-workbench search/navigation;
- build/commit identity;
- map/region/checkpoint/player context;
- active fixture/save slot;
- common dirty/session-override provenance;
- reset/reload/checkpoint actions;
- validation-results surface;
- capture/evidence action;
- safe promotion path for deliberate changes;
- unmistakable DEVELOPMENT/TEST labeling;
- shipping exclusion/hard-disable.

The shell is infrastructure.

It does not own gameplay state.

---

# 2. Required workbench status matrix

Legend:
- **D** = design obligation documented;
- **R** = runtime implementation proven;
- **V** = deterministic validation proven;
- **H** = human usability/iteration acceptance proven.

At this baseline, `R/V/H` are **NO** unless explicit runtime evidence is later entered into the Runtime Evidence Ledger.

| Workbench | Primary authority | Inspect | Author/Tune | Exercise | Validate | Capture/Promote | D | R | V | H |
|---|---|---|---|---|---|---|---|---|---|---|
| Shared System IDE shell | doc 21 / Issue #58 | build/session/provenance/common context | shell/config where safe | reset/reload/preset coordination | common results/provenance safety | shared capture/promotion | YES | NO | NO | NO |
| Player / Locomotion | docs 20, 21 | input, state, requested/actual speed, sprint, traversal eligibility, fall/landing | approved numeric movement tuning | canonical movement course, boundary cases, teleports/reset | affordance eligibility/rejection/invariants | tune capture + fixture evidence | YES | NO | NO | NO |
| Camera / Targeting | docs 22–36, 21 | mode, collision probes, candidates/rejections, target/frame, offsets/lag | approved camera/framing values | target arrangements, walls/ceilings, lock transitions, presets | candidate/occlusion/frame invariants | config/preset evidence | YES | NO | NO | NO |
| Combat | docs 37–49, 21 | combat states, health/resources, attack/guard/evade windows, hit/damage data | approved timing/damage/handling values | spawn targets, reset, health/loadout, force representative phase | combat-state invariants, timing/continuity | evidence/tuning capture | YES | NO | NO | NO |
| Encounter / Enemy | docs 50–59, 21 | pressure scheduler, candidates, active attackers, role/composition, rejection reasons | approved composition/spacing/timing test values | spawn/reset archetypes, fixture rooms, occlusion cases | bandwidth/offscreen/readability/composition assertions | fixture + telemetry capture | YES | NO | NO | NO |
| Interaction / Traversal Object | docs 20, 21, world-production authority | nearby interactables, semantic IDs, eligibility/alignment envelopes | approved tolerances/authoring metadata | reset/retrigger mechanism/affordance cases | visually-equivalent affordance consistency, softlock checks | authored change/evidence | YES | NO | NO | NO |
| Inventory / Tool / Progression | docs 13, 69, 21 | tool ownership, upgrades, patterns, compatibility/unlock gates | approved tool/pattern tuning/data | grant/remove, reset tool scenes, target fixtures | ownership/unlock/dependency validation | data/preset promotion | YES | NO | NO | NO |
| Puzzle / Mechanism | docs 69, 21 + mechanism-specific content | state graph, inputs/outputs, source owner, completion reason | approved mechanism state/tuning | reset named states, force source inputs | impossible/softlocked configs, owner conflicts | authored mechanism evidence | YES | NO | NO | NO |
| Quest / Objective / World-State | docs 82, 88, 21 | objective/prereq graph, world facts, source owners, downstream consumers | authored data only through controlled path | named semantic presets, supported transitions, regional pivots | missing IDs, invariant/softlock/duplicate-owner checks | state-fixture capture/promotion | YES | NO | NO | NO |
| Dialogue / NPC | doc 21 + story/NPC authority | NPC ID/state, recurrence facts, eligible dialogue + rejection reasons | controlled authored dialogue/eligibility data where supported | speaker/context + named world-state presets | impossible branch/missing fact/source-owner checks | dialogue evidence/change record | YES | NO | NO | NO |
| Hush / World-Layer | docs 70–80, especially 77/79 | semantic layer, paired IDs, transition state, representation/Data Layer pairing | presentation transition tuning where safe | legal/illegal seams, paired geometry, save/reload entry points | semantic-vs-representation mismatch, continuity, missing pair IDs | seam/transition evidence | YES | NO | NO | NO |
| Save / Persistence | docs 81–88, especially 87 | slot/schema, persisted semantic facts, owner graph, live vs snapshot | fixture/schema dev data only through controlled path | create/load fixtures, migration/corruption cases, snapshot boundaries | duplicate owner, missing ID, integrity/migration/derived-state assertions | fixture/evidence export | YES | NO | NO | NO |
| Completion / 100% | docs 89–111, especially 104/109 | 16 categories, source entries, reconciled counts, assist state, missing items | authored completion catalog only through controlled path | completion fixtures, legacy IDs, threshold cases | count/weight/alias/tombstone/global-item reconciliation | audit evidence/catalog change | YES | NO | NO | NO |
| Setup / Payoff | docs 112–119 | chain ID/lifecycle, predicates + owners, commit boundary, variants, receipts, manifestations, dependencies | chain definition authoring/validation | before setup, ignored, commit variants, payoff, NPC unavailable, unexpected order, save/reload, superseded recovery | materiality, ownership, non-intervention, reachability, cycle, migration, path-authority checks | definition/fixture promotion | YES | NO | NO | NO |
| Line Skiff / Route Network | docs 120–126 | route/segment ID, current legal expression, route source facts, layer pairing, handling/junction state | route definitions + approved handling/camera values through controlled path | direct route fixtures, junctions, parking/recovery, Hush paired routes, Trial 05, Drift Knot cases | semantic route identity, source-owner, unsupported shift, stranded-player, optional-upgrade leakage | route/handling evidence | YES | NO | NO | NO |
| Null Meridian | docs 127–134 | sequence ID/dependency, source facts/owners, current solution path, settlement/retry state, loadout assumptions | authored sequence definitions/fixtures; no shadow world state | load S1–S6 directly, Story Minimum/full/stripped, Hush/combat variants, local failures, save/reload | one-sentence problem, optional dependency, source ownership, cycle/softlock, semantic settlement, scene-order checks | final-dungeon evidence package | YES | NO | NO | NO |

---

# 3. Locomotion IDE minimum contract

Must answer:
- What input did Locomotion receive?
- What state does Locomotion believe it is in?
- Why did Sprint/jump/mantle/hang/ladder/slope/fall transition succeed or fail?
- What speed/acceleration/braking values are active and where did they come from?
- Is a value canonical, config-backed, session override, or dirty staged change?

Must exercise:
- flat start/stop/turn;
- slopes/stairs;
- jump/landing;
- low obstacle mantle;
- ledge grab/release/shimmy bounds;
- narrow geometry/collision cases;
- canonical short locomotion course.

Must not:
- mutate raw movement private fields without normal service path;
- create a second debug locomotion state machine.

---

# 4. Camera / Targeting IDE minimum contract

Must answer:
- Which camera mode is active?
- What collision probe/constraint changed framing?
- Which target candidates exist and why were they accepted/rejected?
- What semantic target is locked?
- What target-relative frame is Locomotion/Combat consuming?

Must exercise:
- one/multiple targets;
- occlusion;
- close wall/ceiling;
- high/low target geometry;
- target loss/reacquire/switch;
- representative locomotion/combat states;
- eventually Skiff-at-speed presets.

---

# 5. Combat / Encounter IDE boundary

Combat and Encounter may share one visible workbench group but must preserve ownership distinction.

Combat panel:
- action state;
- guard/evade timing;
- damage/hit/interrupt;
- target relationship;
- death/retry.

Encounter panel:
- active pressure commitments;
- attackers waiting/requesting pressure;
- offscreen/occlusion eligibility;
- composition roles;
- fixture topology;
- encounter resolution.

A single `force attack` cheat that bypasses the scheduler is not sufficient as the test architecture.

---

# 6. Tool / Puzzle IDE boundary

Tool IDE owns testing of tool operation/compatibility.

Puzzle/Mechanism IDE owns testing of target mechanism state graph/source facts.

They should integrate without merging authority.

Example developer flow:

```text
grant Anchor
 -> select mechanism fixture
 -> inspect Anchor compatibility
 -> execute real Anchor action
 -> inspect mechanism owner state
 -> reset through mechanism owner
```

The IDE must explain whether a failure is:
- tool incompatibility;
- source mechanism condition;
- progression ownership;
- world/Hush state;
- collision/geometry;
- tuning.

---

# 7. Hush / World-Layer IDE minimum contract

Must distinguish:
- semantic layer;
- transition phase;
- Waking/Hush paired semantic identity;
- Unreal Data Layer/streaming representation;
- collision/geometry readiness;
- save-stable vs mid-transition state.

Must prove in future runtime evidence:
- toggling the IDE uses the legal Hush service path;
- loaded Data Layer does not silently change semantic truth;
- locomotion/combat continuity remains authoritative;
- paired persistent fact appears once, not duplicated per representation.

---

# 8. Save / Persistence IDE minimum contract

Must provide one project-wide ownership graph.

For every persisted record show:
- semantic ID;
- category;
- owner;
- live value;
- snapshot value;
- canonical/derived/transient classification;
- dirty state;
- last mutation provenance.

Must exercise:
- stable snapshot;
- intentionally rejected unstable snapshot;
- paired Hush save/reload;
- migration aliases/splits/merges/tombstones;
- corruption/integrity recovery;
- checkpoint fallback;
- source-before-derived restore/reconciliation.

Issue #4 cannot close until the required paired-layer runtime proof exists.

---

# 9. Completion IDE minimum contract

Must expose:
- all 16 top-level categories;
- exact current canonical item counts;
- source owner for each entry;
- resolved/unresolved semantic IDs;
- migration/alias state;
- global item vs internal stage distinction;
- one-decimal display vs exact rational authority;
- legacy literal audit;
- completion-assist disclosure level.

Required future audit preset:

**Canonical Missing-Item Audit**

It must identify missing required entries without using stale counts or raw actor locations as identity.

---

# 10. Setup/Payoff IDE minimum contract

Two views are required conceptually:

## Runtime Inspector

Shows:
- ChainId;
- lifecycle;
- source predicates/owners;
- commit receipt;
- current payoff eligibility;
- resolution receipt;
- current manifestation/owners;
- migration/reconciliation state;
- exact reason unavailable.

## Authoring Inspector

Shows:
- full declarative definition;
- predicate tree;
- boundary/variant resolver;
- non-intervention;
- payoff outcomes;
- manifestations;
- dependencies;
- recovery;
- fixtures;
- validation.

Required actions include:
- Validate Chain;
- Exercise All Variants;
- Save/Reload Every Boundary;
- Unexpected-Order Matrix;
- Portfolio Similarity Audit;
- Trace Dependency Graph;
- Find Orphan Semantic References;
- Explain Current State.

---

# 11. Line Skiff / Route Network IDE minimum contract

Must distinguish:
- route definition;
- current route legality;
- source world/story facts;
- active Hush layer;
- paired continuation declaration;
- vehicle handling state;
- player intent;
- camera state;
- parking/recovery state.

Must exercise:
- route starts/stops;
- junction choice;
- braking/coasting/lateral placement;
- Switchshoe absent/present;
- Roadhand Pulse;
- invalid off-network attempt;
- legal/illegal Hush shift;
- save/reload at route boundaries;
- Trial 05;
- Drift Knot route cases;
- stranded-player recovery.

The IDE may not equate spline visibility with route truth.

---

# 12. Null Meridian IDE minimum contract

The workbench must preserve the approved dungeon's simplicity while giving developers deep semantic visibility.

For each sequence show:
- one-sentence player-facing problem;
- semantic sequence ID;
- prerequisite settlements;
- required Story Minimum capabilities;
- optional recognized capabilities;
- source facts + owners;
- current solution path;
- reversible local state;
- semantic commit/settlement;
- failure/recovery reason;
- save/reconciliation state.

Fixtures:
- Story Minimum;
- Representative Partial;
- Full Completion;
- Upgrade-Stripped Audit;
- Local Accord absent/present for S6;
- S4 combat pressure on/off + legal/illegal seam cases;
- S5 preserved/current formation cases;
- death/retry and save/reload at semantic boundaries.

Validation must fail if:
- optional content gates mandatory completion;
- room trigger/Actor path becomes sequence truth;
- finale-only hidden system grammar appears;
- sequence cannot be explained in one ordinary sentence;
- source ownership is stolen by final-dungeon script.

---

# 13. Capture / Promote project rule

Every workbench that supports tuning/authoring must make four states visually distinct:

1. repository-backed canonical value/data;
2. temporary session override;
3. dirty/staged development change;
4. deliberately promoted/saved change.

A promoted change must be reviewable:
- text/config/data diff where practical;
- explicit structured patch/artifact where direct source update is unsafe;
- binary asset evidence if an Unreal binary must change.

No accepted tuning value may exist only in developer memory.

---

# 14. Shared semantic fixture API requirement

System IDEs and automation should converge on common semantic fixture/control APIs.

Examples:
- load named world preset;
- grant semantic tool/upgrade;
- set source-owned authored fact through owner API;
- load checkpoint;
- spawn reviewed encounter fixture;
- request legal Hush transition;
- reset mechanism;
- run save/reload fixture;
- settle prior Null Meridian dependencies for direct test.

This is not one universal `SetAnyFlag()` API.

Every operation still routes to the appropriate owner.

---

# 15. Issue #58 implementation acceptance bridge

Issue #58 remains open.

Phase 2 closure defines what must eventually be proven by the implementation issue.

At minimum the first runtime shell proof should demonstrate:
- shell opens during play;
- Locomotion workbench registers;
- a second workbench (Camera is the planned Gate 1 follow-on) can register without separate architecture;
- authoritative state is read from gameplay service;
- approved live tuning is clearly a session override until promoted;
- reset/test preset uses semantic fixture API;
- validation result is human-readable;
- Shipping build does not expose the shell.

Later gates add workbenches rather than creating unrelated debug systems.

---

# 16. Coverage gaps at this baseline

## Runtime gaps

All workbenches above remain runtime-unproven.

## Architecture choices still open

The following are implementation choices, not missing design authority:
- UMG vs Slate vs hybrid shell;
- registration mechanism;
- exact owner-service class names;
- structured promotion transport;
- headless automation integration details;
- which panels share a single visual workbench versus separate registered modules.

## Closure rule

Do not mark a system `production-ready` while the workbench needed to author/tune/reproduce it is absent.

IDE debt is feature debt.

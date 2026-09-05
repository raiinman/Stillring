# 79 — Gate 4 Hush-Layer Cumulative Specification / Fixture Closure

**Status:** CUMULATIVE / FINAL OWNER-DELEGATED DESIGN AUTHORITY  
**Updated:** 2026-09-05  
**Issue:** #126 — Define Gate 4 Hush-layer prototype design system  
**Decision:** #10 — deterministic paired-layer fixtures, transition/save/capture matrix, cumulative Gate 4 design closure and implementation-evidence boundary

## Governing Hush principle

> **One place. One history of facts. Two authored expressions—and exactly one semantic reality active at a time.**

The Hush is an echo-layer coupled to ordinary Orra. It contains discarded possibilities, emotional residue, incomplete states, and impressions of things no longer present. It is not an afterlife, not inherently evil, not a quest-script teleport, and not a full-screen visual filter.

Gate 4 design is now sufficiently specified to implement and test the first paired-layer prototype without letting Unreal representation choose gameplay rules by accident.

---

## 1. Authority chain

1. `docs/70_GATE4_HUSH_SEMANTIC_LAYER_IDENTITY_ADDENDUM.md` — Decision #1: semantic state + paired identity
2. `docs/71_GATE4_HUSH_SEAM_TRANSITION_ADDENDUM.md` — Decision #2: transition eligibility/commit/control
3. `docs/72_GATE4_HUSH_GEOMETRY_COLLISION_AUTHORITY_ADDENDUM.md` — Decision #3: physical authority
4. `docs/73_GATE4_HUSH_CROSS_LAYER_PUZZLE_STATE_ADDENDUM.md` — Decision #4: cross-layer puzzle facts/causality
5. `docs/74_GATE4_HUSH_COMBAT_NPC_INTERACTABLE_CONTINUITY_ADDENDUM.md` — Decision #5: combat/NPC/interactable continuity
6. `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md` — Decision #6: Hush-specific save/reload semantics
7. `docs/76_GATE4_HUSH_PRESENTATION_AUDIO_ACCESSIBILITY_ADDENDUM.md` — Decision #7: presentation/accessibility
8. `docs/77_GATE4_HUSH_WORLD_LAYER_IDE_ADDENDUM.md` — Decision #8: in-game development workbench
9. `docs/78_GATE4_HUSH_REPRESENTATION_COMPARISON_ADDENDUM.md` — Decision #9: representation comparison / first prototype direction
10. **This document** — Decision #10: fixture matrix, cumulative closure, implementation-evidence boundary

Parent/cross-system authority remains:
- `docs/01_GAME_VISION.md`;
- `docs/02_STORY_BIBLE.md`;
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
- Gate 1 movement/camera authority;
- Gate 2 combat/encounter authority;
- Gate 3 Cantor/Anchor puzzle authority;
- Issue #4 persistent-world/save authority.

If a summary here omits detail, the numbered decision addendum remains provenance authority.

---

## 2. Cumulative semantic model

### One semantic place
Waking and Hush are expressions of one authored Orra. One authoritative world-layer service owns the current semantic layer:
- `Waking`
- `Hush`

Engine state is downstream representation.

### Stable semantic identity
Meaningful paired/shared entities use authored stable semantic IDs independent of:
- Actor path;
- package path;
- runtime GUID;
- Data Layer name;
- sublevel visibility;
- spawned instance identity.

Identity classes distinguish shared invariant, paired expression, layer-exclusive, and related-distinct entities.

### One history of facts
Shared persistent facts live once under semantic identity. Layer-local facts are explicitly scoped. Derived expression state is recomputed.

No Waking/Hush duplicate quest/world/combat truth is allowed merely because two Actors exist.

---

## 3. Cumulative seam-transition model

A normal player seam request follows:

```text
Request
  ↓
Eligibility
  ↓
Preparing (optional / bounded; source remains semantic truth)
  ↓
COMMIT exactly once
  ├─ ActiveSemanticLayer changes
  ├─ physical authority hands off
  ├─ continuity hooks resolve
  └─ destination derived state becomes authoritative
  ↓
Presenting (visual/audio only; not a third reality)
  ↓
Save-Stable
```

Rules:
- failures before commit are side-effect free;
- no rollback cancel after commit; reverse shift is a new request;
- repeated/held input never queues oscillation;
- player locomotion/camera remain owned by Gate 1/2 rules;
- seam grants no generic invulnerability, attack cancel, momentum reset, target roulette, or world-state reset;
- save snapshots never record a half-transition.

---

## 4. Cumulative physical-authority model

Loaded, presented, and physically authoritative are different states.

Default:
- active semantic expression owns ordinary collision/gameplay queries;
- inactive expression may be loaded/presented but does not block player/camera/tools/projectiles, generate ordinary overlaps, or run gameplay-affecting physics;
- shared-invariant collision may remain active only when intentionally identical across both states.

At seam commit:
- source exclusive physical authority ends;
- destination exclusive physical authority begins;
- destination player occupancy is validated;
- there is no deliberate dual-blocking frame.

Occupancy resolution order:
1. same transform;
2. smallest deterministic correction inside a narrowly authored seam-safe envelope;
3. reject before commit.

No arbitrary nearby teleport search is allowed.

---

## 5. Cumulative puzzle model

Hush puzzles remain Gate 3-style observable machines.

Semantic puzzle state classes:
- shared persistent;
- layer-local;
- cross-layer causal;
- derived expression.

Cross-layer effects occur because an authored semantic fact changed—not because the player toggled layers or a hidden destination Actor received a Blueprint event.

Anchor:
- acts only on currently active legal physical load points;
- may cause cross-layer consequences only by changing a real semantic mechanical fact.

Cantor:
- diagnoses authored relationships;
- never reveals privileged solution metadata or becomes Hush radar.

Puzzle completion is derived from explicit invariants and accepts alternate valid orders that reach the same lawful state.

---

## 6. Cumulative combat/NPC/interactable continuity

A seam changes expression, not history.

The seam does not reset:
- player combat action/phase;
- evade immunity;
- guard/perfect-guard timing;
- health/resources;
- enemy health/death;
- aggro/encounter state;
- one-shot interaction facts;
- NPC relationship/story facts.

Target lock:
- transfers only to the destination expression of the **same semantic target** if valid;
- otherwise breaks explicitly;
- never silently selects another enemy.

Layer-exclusive entities may become semantically dormant/unavailable while inactive; returning does not create a fresh spawn baseline by accident.

Actor/AI lifecycle is representation behavior, not continuity authority.

---

## 7. Cumulative save/reload model

A persistent Hush save is one coherent semantic snapshot.

Save:
- records settled active semantic layer;
- records persistent semantic facts once by stable ID;
- scopes legitimate layer-local facts explicitly;
- defers while seam/world fact state is not save-stable;
- snapshots coherently before asynchronous disk I/O.

Reload:
1. validate/migrate schema through Issue #4 policy;
2. restore semantic facts;
3. restore active semantic layer;
4. prepare representation;
5. derive paired expressions;
6. establish active physical authority;
7. validate player occupancy;
8. reconstruct NPC/combat/interactable presentation/runtime state;
9. validate convergence;
10. release player control.

Reload never replays the seam gameplay transition and never treats Data Layer/Actor visibility as saved truth.

---

## 8. Cumulative presentation/accessibility model

The Hush is a world-space alternate expression first; post-process is support.

Presentation hierarchy:
1. world-space geometry/presence/material/lighting/residue;
2. local semantic cues;
3. ambience/audio mix;
4. restrained post-process;
5. optional transition flourish.

Required:
- Hush remains identifiable with post-process disabled/reduced;
- critical distinctions are not color-only;
- critical gameplay cues receive appropriate multimodal support;
- no required strobing/full-screen flashing;
- no Hush-specific forced camera sway/FOV oscillation;
- Reduced Hush Effects preserves all gameplay semantics/readability;
- atmosphere may not bury combat/tool/dialogue/puzzle evidence.

---

## 9. Cumulative System IDE model

The Hush / World-Layer IDE registers in the shared development shell and must make semantic truth, Unreal expression, and disagreement visible together.

Required surfaces:
- **Inspect** semantic layer, transitions, pairs, physical authority, facts, continuity, save-stability, presentation;
- **Author/Tune** only reviewed tunable values with provenance;
- **Exercise** normal shifts, failures, pair/geometry/puzzle/combat/save fixtures;
- **Validate** semantic/physical/persistence/continuity/accessibility invariants;
- **Compare** representation/performance/authoring candidates;
- **Capture** structured reproducible evidence;
- **Promote** only reviewable supported changes.

Fault injection is development-only and cannot become gameplay authority.

Shipping excludes/hard-disables the workbench and exposes no remote model/API/debug mutation surface.

---

## 10. Prototype representation direction

First implementation direction:

> **World Partition + Runtime Data Layers, with spatial streaming disabled for the tiny Gate 4 fixture initially.**

Conceptual representation:
- shared expression set;
- Waking Runtime Data Layer expression set;
- Hush Runtime Data Layer expression set;
- semantic Hush service above a replaceable representation adapter.

Runtime Data Layers express reality; they do not define semantic truth or save keys.

Fallback comparator:
- non-World-Partition persistent map + explicit Waking/Hush streamed sublevels/Actor groups.

Candidate A is **not production-proven** until real UE5.8 evidence satisfies Decision #9's acceptance gates.

---

# 11. Deterministic Gate 4 fixture suite

Every fixture receives a stable test ID, reset baseline, expected semantic/physical state, machine assertions, and human-play review notes.

## H4-F01 — Baseline paired room
Purpose: prove same-place identity with Shared/Waking/Hush expression sets.

Setup:
- recognizable shared floor/landmark;
- one Waking-exclusive prop/wall;
- one Hush-exclusive prop/wall;
- one paired semantic interactable;
- no combat.

Must prove:
- stable semantic IDs;
- only active expression owns ordinary collision;
- correspondence remains readable;
- repeated shifts do not drift state.

## H4-F02 — Geometry conflict / occupancy
Purpose: prove deterministic seam rejection/correction.

Cases:
- same player transform valid;
- small authored safe correction required;
- destination fully blocked → reject;
- airborne destination blocker.

Must prove:
- no broad teleport search;
- no dual collision;
- exact rejection/correction reason visible in IDE.

## H4-F03 — Camera/tool query boundary
Purpose: prove inactive geometry is non-authoritative.

Cases:
- camera between mismatched walls;
- Cantor diagnostic trace near inactive expression;
- Anchor targeting across inactive geometry;
- generic interaction query.

Must prove:
- inactive presentation does not block camera/tool/interaction;
- active geometry remains honest.

## H4-F04 — Cross-layer observable machine
Purpose: prove Gate 3-compatible puzzle causality.

Suggested mechanism:
- one shared semantic support/load fact;
- Waking exposes a legal Anchor manipulation;
- Hush expresses the consequence with different geometry/route/mechanism state;
- Cantor can explain a relationship without exposing the solution.

Must prove:
- no `Shift == Solved` condition;
- shared fact stored once;
- causal relationship visible in IDE;
- alternate valid order accepted where legal;
- reset converges both expressions.

## H4-F05 — Paired combatant continuity
Purpose: prove anti-reset combat semantics.

Cases:
- enemy at partial health;
- enemy mid-action paired-compatible;
- target lock on paired target;
- player Light/Heavy/Guard/Evade across seam;
- incoming/outgoing hit at commit boundary.

Must prove:
- no HP/action/aggro reset;
- no evade immunity restart;
- same semantic target transfers cleanly;
- no duplicate hit;
- no fresh encounter on immediate shift-back.

## H4-F06 — Layer-exclusive combatant / projectile
Purpose: prove dormancy and layer scope.

Cases:
- source-only enemy;
- source-layer projectile/hazard;
- shift away and immediately return.

Must prove:
- target breaks without replacement;
- inactive enemy/projectile cannot affect player;
- health/aggro/one-shot state is not freshened on return.

## H4-F07 — NPC / one-shot interactable continuity
Purpose: prove stable identity beyond combat.

Cases:
- shared/paired one-shot pickup;
- NPC relationship/world fact;
- noncommitted prompt;
- committed dialogue/interaction that rejects seam.

Must prove:
- no duplicate reward;
- no dialogue rewind;
- prompt rebinds rather than auto-fires;
- ownership rejection reason is explicit.

## H4-F08 — Save Waking / reload
Purpose: baseline semantic persistence.

Must prove:
- save-stable snapshot;
- active Waking layer restored semantically;
- paired facts reconstructed;
- physical authority established before control;
- no seam transition replay.

## H4-F09 — Save Hush / reload
Same as F08 with Hush active, including destination expression initially unloaded before reconstruction.

## H4-F10 — Save during seam
Cases:
- request during Preparing;
- request immediately after commit but before save-stable convergence;
- request after stable.

Must prove:
- save defers correctly;
- no mixed-layer snapshot;
- resulting reload is one settled reality.

## H4-F11 — Persistent cross-layer mutation
Purpose: combine puzzle + save.

Flow:
1. change shared mechanism fact in Waking;
2. enter Hush and observe derived consequence;
3. save;
4. teardown/reload;
5. inspect both expressions.

Must prove one fact restores both expressions without replaying actions.

## H4-F12 — Representation refactor persistence
Purpose: prove semantic IDs outlive Unreal organization.

Fixture changes representation asset/path/Data Layer assignment in a controlled test while semantic IDs remain stable.

Must prove save/state still resolves after appropriate content/schema handling and no Actor/path key was canonical.

## H4-F13 — Transition presentation / accessibility
Cases:
- full/default effects;
- Reduced Hush Effects;
- post-process disabled;
- haptics off;
- color-vision simulation;
- HDR/SDR where available;
- photosensitivity capture.

Must prove:
- layer remains understandable;
- active physical geometry remains legible;
- combat/tool cues remain readable;
- gameplay results are identical across effects settings.

## H4-F14 — Stress / repeated transition
Purpose: expose drift, leaks, callbacks, oscillation.

Run a long deterministic shift cycle across the paired room with periodic puzzle/interaction resets.

Must prove:
- exactly one commit per accepted request;
- no semantic/physical drift;
- no duplicate entities/facts;
- no accumulating transition callbacks;
- memory returns to expected envelope or persistent allocations are explained.

## H4-F15 — Git/authoring workflow comparator
Purpose: gather Decision #9 non-runtime evidence.

Perform controlled branches/edits for:
- Waking-only Actor;
- Hush-only Actor;
- shared Actor;
- paired entity relation.

Capture files changed, binary/OFPA churn, merge/rebase friction, Editor steps, and whether semantic intent is reviewable.

## H4-F16 — Candidate-B fallback microfixture
Purpose: keep architecture comparison honest.

Only required to be implemented if Decision #9 hard-failure criteria are triggered or Candidate A evidence is ambiguous.

Use the same semantic service and as much of the same fixture as practical with explicit non-WP level/Actor layering. Compare normalized measurements rather than inventing a different gameplay setup.

---

# 12. Gate 4 test/capture matrix

Legend:
- **M** = machine-verifiable / Automation/Functional Test candidate
- **H** = human play/review required
- **P** = profiler/trace evidence required
- **SC** = source-control workflow evidence

| Concern | Core fixture(s) | Evidence |
|---|---|---|
| semantic ID/pair correctness | F01, F12 | M |
| one semantic commit | F01, F14 | M |
| eligibility/rejection | F02, F07, F10 | M + H |
| physical ownership exclusivity | F01–F03 | M |
| camera/tool correctness | F03 | M + H |
| cross-layer puzzle causality | F04, F11 | M + H |
| player combat continuity | F05 | M + H |
| enemy/aggro continuity | F05, F06 | M + H |
| target continuity/no roulette | F05, F06 | M + H |
| NPC/interactable one-shot state | F07 | M + H |
| Waking save/reload | F08 | M |
| Hush save/reload | F09 | M |
| save deferral | F10 | M |
| semantic fact persistence | F11, F12 | M |
| presentation readability | F13 | H |
| accessibility gameplay invariance | F13 | M + H |
| photosensitivity | F13 | H/tool evidence |
| transition/frame performance | F01, F05, F14 | P + H |
| memory/residency | F01, F14 | P |
| repeated-cycle leak/drift | F14 | M + P |
| authoring/source-control cost | F15 | SC + H |
| representation comparison | F15, optional F16 | M + P + SC + H |

Automation/Functional Tests should emit structured reports where practical. Unreal Insights/Memory Insights provide performance and residency evidence; in-game IDE captures provide semantic context around the trace.

---

# 13. Hard acceptance invariants

The Gate 4 implementation cannot pass if any of these remain reproducible:

1. active semantic layer can disagree silently with gameplay physical authority;
2. semantic commit occurs more than once for one accepted transition;
3. inactive exclusive geometry blocks/overlaps/damages/targets the player;
4. seam gives combat cancel/immunity/health/aggro reset not authorized elsewhere;
5. target lock silently jumps to a different semantic enemy;
6. shared persistent fact exists as contradictory Waking/Hush copies;
7. shift itself satisfies hidden puzzle completion;
8. save contains half-transition/mixed-reality truth;
9. reload requires Actor/Data Layer/package path as canonical persistent identity;
10. Hush becomes unintelligible with Reduced Effects/post-process disabled;
11. critical Hush gameplay cue is color-only;
12. Hush IDE cannot explain a transition rejection or semantic↔representation mismatch;
13. Candidate A requires bending a locked semantic/gameplay rule to accommodate World Partition/Data Layers;
14. transition or residency performance is unacceptable on target-class hardware without a credible mitigation;
15. Git/LFS authoring workflow is so opaque/conflict-prone that paired content cannot be maintained reliably.

A representation feature loses before a gameplay rule does.

---

# 14. Human acceptance pass

Even if all machine tests pass, Gate 4 still needs human play to answer:
- does shifting feel immediate rather than like opening a mode?
- does Neris remain trustworthy while moving/fighting through a seam?
- can the player recognize the same place in both expressions?
- does the Hush communicate absence/residue/incompleteness rather than generic spooky-filter language?
- can the player reason about one cross-layer puzzle without hidden objective logic?
- is physical active geometry immediately legible after commit?
- does target/enemy continuity feel coherent rather than glitchy?
- is Reduced Hush Effects still readable and atmospheric enough?
- does repeated shifting feel systemic rather than fragile?
- does the implementation remain explainable from the Hush IDE?

Human feel/readability remains authoritative for acceptance.

---

# 15. Performance evidence boundary

No numeric frame/memory budget is invented in design documentation without target-hardware context.

Real implementation must capture at minimum:
- exact UE5.8 engine/build;
- source commit;
- map/fixture ID;
- hardware/build configuration;
- worst and representative frame timings around seam;
- game/render/GPU tracks where available;
- asset-loading timing;
- memory/residency source-only / both-prepared / destination-only;
- repeated-cycle leak trend;
- VFX/post-process differential;
- profiler overhead noted separately.

Use Unreal Insights/Memory Insights/Stat evidence rather than screenshots of FPS alone.

---

# 16. Source-control/authoring evidence boundary

Gate 4's representation choice must be tolerable under Stillring's actual Git/Git-LFS workflow.

Before Candidate A is production-proven, capture:
- one-Actor Waking edit;
- one-Actor Hush edit;
- shared Actor edit;
- paired identity change;
- controlled two-branch non-overlap edit;
- controlled two-branch overlap edit;
- exact files changed;
- merge/rebase result;
- whether binary changes can be attributed to meaningful content;
- recovery path for accidental wrong-layer placement;
- any OFPA encoded-file friction outside the Editor.

Epic documentation describes OFPA's collaboration benefit, but Stillring must validate it with Git rather than assuming Perforce-oriented workflows map perfectly.

---

# 17. Issue #126 acceptance reconciliation

| Issue #126 criterion | Design status | Authority |
|---|---|---|
| One authoritative semantic Waking/Hush state service | **PASS** | D1/D2 |
| Paired persistent IDs/ownership explicit | **PASS** | D1/D3/D6 |
| Deterministic seam request/commit/failure | **PASS** | D2 |
| Geometry/collision/state differences explainable | **PASS** | D3/D4 |
| Puzzle can depend on meaningful layer differences without hidden objective metadata | **PASS (design)** | D4 + F04 |
| Save/load reproduces layer + persistent facts via stable IDs | **PASS (design); implementation proof pending** | D6 + F08–F12 |
| Seam does not silently mutate combat/tools/quest/camera | **PASS** | D2/D4/D5 |
| Hush IDE Inspect/Author-Tune/Exercise/Validate/Capture | **PASS** | D8 |
| Runtime Data Layers vs explicit layering compared | **PASS** | D9 |
| No representation claimed production-proven without real UE5.8 evidence | **PASS** | D9 + this closure |
| No retail runtime AI/model/API dependency | **PASS** | parent System IDE/technical authority |

**Conclusion:** Issue #126's **design** scope is complete. Gate 4's actual playable prototype remains unverified/unimplemented until the fixture/evidence requirements above are executed in Unreal Engine 5.8.

---

# 18. Implementation authorization boundary

The following is now authorized for Gate 4 prototype implementation:
- authoritative semantic world-layer service;
- stable semantic pair identity/data;
- deterministic transition service;
- replaceable Hush representation adapter;
- first candidate: WP + Runtime Data Layers with spatial streaming disabled in the tiny fixture;
- paired physical/collision ownership handoff;
- representative shared/Waking/Hush fixture content;
- cross-layer observable-machine fixture;
- combat/NPC/interactable continuity fixture support;
- Hush-specific semantic save/reload integration compatible with Issue #4;
- Hush presentation/accessibility prototype;
- Hush / World-Layer IDE;
- Automation/Functional/Insights evidence capture required by this document.

Not yet authorized as proven production architecture:
- production-wide World Partition grid/HLOD strategy;
- all six regions converted/partitioned;
- Candidate A declared final without evidence;
- final art/audio/VFX values;
- mass content production depending on unverified seam performance;
- save implementation that preempts unresolved whole-project Issue #4 schema decisions;
- any retail runtime model/API dependency.

---

# 19. Definition of Gate 4 prototype success

The actual prototype succeeds when:
- Waking↔Hush transition is fast and player-owned;
- semantic ownership remains unambiguous;
- paired geometry/collision behaves deterministically;
- one cross-layer puzzle works through observable causal state;
- combat/NPC/interactable continuity cannot be exploited through shifting;
- Waking and Hush save/reload reproduce semantic state;
- Reduced Effects remains fully playable/readable;
- Hush IDE can force, inspect, validate, reset, compare, and capture the system;
- real performance/memory/source-control evidence supports the selected representation;
- human play confirms the Hush feels like the same place entering a different state rather than a technical level swap.

Design alone does not satisfy these prototype-execution criteria.

---

## Research basis

Decision #10 focused research/reconciliation used:
- Epic Games, **Automation Test Framework / Run Automation Tests**, UE5.8 — deterministic feature/functional tests, command-line execution, structured reporting.
- Epic Games, **Unreal Insights**, UE5.8 — frame/thread/GPU/asset-loading telemetry and trace capture.
- Epic Games, **Memory Insights**, UE5.8 — allocation/residency investigation.
- Epic Games, **Introduction to Performance Profiling**, UE5.8 — profiler/tool selection and measurement discipline.
- Decisions #1–#9 and the parent Gate 1–3/System IDE authority.

---

## Locked closure statement

> **Gate 4 Hush design is closed. Implementation may begin against Decisions #1–#10, but the representation is not production-proven until the named real-UE5.8 fixtures, save tests, profiler evidence, Git workflow checks, and human play all pass.**

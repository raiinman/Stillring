# 144 — Unanswered Question Register

**Status:** CANONICAL OPEN-QUESTION / UNKNOWN REGISTER  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 3  
**Baseline main:** `22b4074e3d08358b302fd7a518773803f303990f`

## Purpose

Stillring's design is intentionally detailed, but not every future implementation/tuning/content decision should be locked on paper before the engine exists.

This register prevents two opposite failures:

1. **hidden guessing** — an implementation agent silently chooses a behavior/architecture because the docs did not mention it;
2. **fake owner work** — every numeric tuning variable or Unreal class-placement choice is pushed to the owner as if it were a game-design decision.

Core rule:

> **An unanswered question is not a defect if its owner, blocking point, evidence path, and allowed decision class are explicit.**

---

# 1. Classification

From `docs/135_DOCUMENTATION_CLOSURE_PROGRAM_CHARTER.md`:

- **A — architecture blocker**: must be resolved before the affected implementation begins.
- **B — implementation choice within locked design**: engineering may choose/recommend; must preserve authority and be documented.
- **C — tuning / feel**: prototype + human play decides within locked design bounds.
- **D — content production detail**: authored later inside locked systemic/narrative constraints.
- **E — runtime evidence requirement**: design answer already exists; implementation/testing remains.
- **F — owner decision required**: cannot be inferred from current authority.

A row may carry two classifications where the question has both a technical/evidence and owner-lock boundary.

---

# 2. Current owner-decision queue

These are the only currently identified items that genuinely require owner authority rather than implementation experimentation.

| ID | Class | Question | Already locked | Blocking point | Required resolution |
|---|---|---|---|---|---|
| UQ-F001 | **F** | What PC hardware/performance baseline is the project's **target PC** for vertical-slice and later production acceptance, and which launch platforms are actually in product scope? | UE5.8; Gate 5 requires stable frame pacing on a `target PC`; accessibility/platform compatibility principles exist | **Before Gate 5 performance exit criteria can be objectively accepted**; broader platform list before platform-specific certification/release work | Owner selects target-PC baseline and product platform scope after implementation cost/performance research; record resolution in project authority |
| UQ-F002 | **F** | After Documentation Closure final review, is broad UE5.8 implementation authorized, and under what initial scope? | Gate order, authority maps, evidence rules, open issues #4/#5/#58 | End of Closure Phase 4 | Explicit owner authorization; until then broad implementation remains unauthorized |

### UQ-F001 is not a Gate 1 blocker

Issue #5 can bootstrap a desktop UE5.8 prototype on the available development machine without pretending that machine is the shipping performance target.

Gate 1 evidence should record its actual hardware/context.

The `target PC` must be defined before Gate 5 can claim its frame-pacing exit criterion.

### No current owner decision is required for exact Gate 1 tuning

Movement speed, acceleration curves, camera lag, jump values, animation response, and similar feel values belong to **C — tuning / human play** within the locked locomotion/camera rules.

Do not manufacture dozens of owner questions from numeric tuning.

---

# 3. Gate 1 / UE bootstrap questions

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-G1-001 | **A/B/E** | What exact UE5.8 project/module/target structure will implement the Gate 1 harness? | C++ first; thin Blueprints; minimal bootstrap only; no stock-template design defaults | Resolve during Issue #5 implementation; prove fresh build/editor load |
| UQ-G1-002 | **B** | Which Unreal lifetime/container types host Locomotion, Camera/Targeting, fixture services, and shared IDE registration? | Ownership boundaries in docs 139/140; class names intentionally not locked | Decide before coding each owner; document architecture; no owner-domain merging |
| UQ-G1-003 | **B** | What service registration/dependency/event mechanism will connect gameplay owners? | Directional ownership contracts locked | Decide during bootstrap architecture; validate no circular/duplicate authority |
| UQ-G1-004 | **B/E** | What Git LFS / binary Unreal asset PR evidence workflow will be used? | `.uasset`/`.umap` must not hide critical rules; fresh-checkout build required | Issue #5 before bootstrap closure |
| UQ-G1-005 | **C/H** | Exact walk/run/sprint speeds, acceleration/braking, steering, jump arc, air control, mantle thresholds, ledge tolerances | Functional roles and hard movement rules locked | Gate 1 human-play iteration |
| UQ-G1-006 | **C/H** | Exact camera distance/FOV/lag/collision recovery/lock offsets and target-switch tuning | Camera semantics/policies locked | Gate 1 human-play iteration |
| UQ-G1-007 | **E** | Can ordinary movement stop demanding conscious correction within the roadmap's fresh-playtest target while preserving authored gates? | Exit criterion locked | Human Gate 1 play evidence |

---

# 4. Shared System IDE questions — Issue #58

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-IDE-001 | **B** | UMG, Slate, or hybrid for the shared developer shell? | One shared shell; gamepad/keyboard usable; dev-only; real services; visible provenance | Decide while implementing #58; second workbench must register without new shell architecture |
| UQ-IDE-002 | **B** | How do workbenches register/discover themselves and expose common metadata/actions? | Shared registration required; no unrelated debug-window pile | #58 runtime architecture |
| UQ-IDE-003 | **B** | How are session overrides represented and promoted safely into repository-backed data/config/assets? | canonical vs override vs dirty vs promoted must be distinct | Resolve before author/tune surfaces are relied on for production |
| UQ-IDE-004 | **B/E** | How do headless/Automation tests reuse the same semantic fixture APIs as the in-game shell? | Same gameplay owners; no shadow state | Prove progressively beginning Gate 1/2 |
| UQ-IDE-005 | **E** | Is the entire shell absent/hard-disabled in Shipping? | Shipping exclusion locked | Packaged-build verification |

No owner design decision is currently needed for shell UI technology; implementation should recommend the simplest approach that satisfies the locked contract.

---

# 5. Combat / encounter questions

Older individual addenda contain temporary `deferred` language for decisions that were later resolved. Those are **not** open questions when later authority exists.

Example:
- Guard doc 40 deferred Perfect Guard;
- doc 43 later locks Perfect Guard;
- doc 48 incorporates the combat state model.

Do not reopen resolved combat decisions by keyword search.

Current real unknowns:

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-CMB-001 | **C/H** | Exact light/heavy timings, chain windows, Perfect Guard timing, evade values, damage/health/resource tuning | relative philosophy/state rules locked | Gate 2 repeated-combat human play |
| UQ-CMB-002 | **C/H** | Exact multi-enemy pressure numbers/composition timing at difficulty levels | bandwidth/readability/offscreen rules locked | Gate 2 fixture + human play |
| UQ-CMB-003 | **B/E** | Exact AI architecture/nav/behavior implementation that satisfies encounter ownership and pressure scheduling | encounter vs individual-AI ownership locked | Gate 2 runtime fixtures |
| UQ-CMB-004 | **E** | Does target/camera/encounter composition remain readable in narrow/occluded/offscreen cases? | rules locked | deterministic fixtures + human play |
| UQ-CMB-005 | **C/H** | Boss/miniboss final timings, vulnerability durations, phase pacing | boss language/ownership locked where authored | respective boss playtests |

---

# 6. Gate 3 tool / puzzle questions

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-G3-001 | **B** | Exact C++ object/data architecture for Cantor and individual tool operations | Gate 3 semantics/ownership locked | Gate 3 implementation |
| UQ-G3-002 | **B** | Exact authored mechanism state-data representation and authoring pipeline | mechanism source ownership + stable semantic identity locked | Before scalable puzzle/content implementation |
| UQ-G3-003 | **C/H** | Tool timings/ranges/feedback intensity/tolerance values | verb identity and failure/readability rules locked | Gate 3 prototype + human play |
| UQ-G3-004 | **E** | Can one tool genuinely produce traversal + combat-pressure + puzzle value without feeling like three unrelated scripts? | Gate 3 exit contract | Gate 3 playable proof |
| UQ-G3-005 | **D/C** | Exact puzzle geometry/room composition for later authored uses | system rules locked | content production + playtest |

---

# 7. Gate 4 Hush production-architecture questions

The current prototype direction does **not** count as production architecture proof.

Roadmap Gate 4 explicitly requires comparing at least two credible Unreal representations before production lock.

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-G4-001 | **A/E** | Which production representation wins after comparing World Partition + Runtime Data Layers against a credible explicit level/Actor layering approach? | semantic Waking/Hush authority independent of representation; Data Layers cannot own world truth | **Before Gate 4 production architecture is locked**; compare authoring clarity, source-control cost, performance, save reliability |
| UQ-G4-002 | **B/E** | If WP/RDL wins, what exact partition/data-layer granularity and streaming strategy supports paired spaces? | semantic ownership locked | Gate 4 prototype evidence |
| UQ-G4-003 | **B/E** | If explicit layering wins, what exact level/Actor organization preserves paired IDs and authoring safety? | semantic ownership locked | Gate 4 prototype evidence |
| UQ-G4-004 | **C/H** | Exact visual/audio transition timing and comfort | continuity + accessibility boundaries locked | Gate 4 human play |
| UQ-G4-005 | **E** | Can paired state save/exit/reload reproduce exactly enough to close Issue #4? | Save/Hush contract locked | Issue #4 verification |

### Production architecture selection

The evidence should be brought back for explicit review before declaring the production representation locked. Do not let the first prototype automatically become permanent architecture.

---

# 8. Save / World-State questions — Issue #4

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-SAV-001 | **B** | Exact Unreal host/lifetime for Save Coordinator and persistent owner registry | semantic ownership/schema locked | Before Save implementation |
| UQ-SAV-002 | **B** | Exact serialization format/container mechanics inside the locked schema/version/migration policy | record semantics locked | Save implementation |
| UQ-SAV-003 | **B/E** | Exact write/rotation/LKG implementation by platform/file APIs | integrity/recovery behavior locked | Issue #4 runtime fixtures; later target-platform validation |
| UQ-SAV-004 | **E** | Paired Hush save -> process exit -> reopen -> load reproduces intended semantic state | required by Issue #4 | Must pass before #4 closes |
| UQ-SAV-005 | **E** | Migration aliases/splits/merges/tombstones and corruption recovery behave idempotently in real files | policy locked | Gate 6/future save automation |
| UQ-SAV-006 | **E** | Source-before-derived restore ordering works with Setup/Payoff, Completion, route derivation, and presentation | directional contract locked | integration fixture suite |

---

# 9. Completion questions

The canonical counts/weights are **not open questions**.

Docs 104/109 lock them.

Open questions are implementation/play questions:

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-CMP-001 | **B** | Exact registry/data representation for completion items and migration metadata | semantic IDs/counts/weights/reconciliation locked | Before Completion implementation |
| UQ-CMP-002 | **E** | Exact arithmetic/display rules reconcile correctly at every edge and migration case | rules locked | deterministic Completion fixtures |
| UQ-CMP-003 | **C/H** | Are assist tiers useful without spoiling discovery or becoming checklist/radar fatigue? | disclosure/assist boundaries locked | human completion playtests |
| UQ-CMP-004 | **D/C** | Exact authored hint placement/wording for late missing-item assistance | tier behavior locked | content production |

---

# 10. Setup/Payoff questions

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-SP-001 | **B** | Exact UE5.8 `UPrimaryDataAsset` class fields, predicate serialization types, Asset Manager registration, source-provider registry | authoring/data contract locked | Before Setup/Payoff implementation |
| UQ-SP-002 | **B/E** | Exact receipt persistence/reconciliation implementation | minimal commit/resolution history locked | Runtime + Save integration |
| UQ-SP-003 | **E/H** | Does S01 Crooked Fire Bell payoff feel naturally remembered rather than announced? | canonical prototype/materiality contract locked | Gate 5/8 vertical-slice play |
| UQ-SP-004 | **E** | All 12 variants/non-intervention/supersession paths remain completion-safe under save/reload/unexpected order | design locked | fixture matrix |
| UQ-SP-005 | **C/H** | Portfolio similarity feels varied enough in real play | portfolio audit rule locked | content playtest |

---

# 11. Line Skiff questions

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-SKIFF-001 | **B** | Exact UE movement implementation for supported-corridor Skiff handling | network vehicle identity; player vs route ownership locked | Before Skiff runtime implementation |
| UQ-SKIFF-002 | **B** | Exact route-definition/data representation and how authored geometry binds to semantic segments | semantic route graph identity locked | Before route authoring at scale |
| UQ-SKIFF-003 | **C/H** | Acceleration/coast/brake/lateral/junction/momentum values and sense of speed | control grammar locked | first Skiff playable prototype |
| UQ-SKIFF-004 | **C/H** | High-speed camera tuning | manual camera authority/reduced-motion rules locked | Skiff prototype |
| UQ-SKIFF-005 | **A/E** | Can streaming/HLOD/collision keep supported routes reliable at Skiff speed across representative regions? | route grammar locked | Before broad route network production |
| UQ-SKIFF-006 | **E** | Save/reload/parking/recovery and Hush paired-route continuation converge correctly | rules locked | integration fixtures |
| UQ-SKIFF-007 | **E/H** | Trial 05 and Drift Knot routes test mastery without turning the network into racetracks | content/system rules locked | playable trial/hunt proof |
| UQ-SKIFF-008 | **E** | Route Listener unlock only after 12/12 Knots and never locates still-required Knots | completion rule locked | completion/Skiff fixtures |

---

# 12. Null Meridian / finale questions

The six-sequence structure is locked. Exact blockout/timing is intentionally not.

| ID | Class | Question / unknown | Locked boundary | Blocking point / evidence |
|---|---|---|---|---|
| UQ-NM-001 | **B/D** | Exact blockout/geometry and spatial relationships for S1–S6 | sequence idea, dependency, one-sentence problems locked | Gate 10 content implementation |
| UQ-NM-002 | **B/D** | Exact physical mechanism used by Neris to disconnect S6 master relay | player must physically remove central control after local branches are safe; no menu/abstract frequency solution | S6 blockout/implementation |
| UQ-NM-003 | **C/H** | Sequence duration, number of combat beats, recovery spacing, first-half breathing time | emotional/mechanical waveform locked | Null Meridian playtest |
| UQ-NM-004 | **C/H** | Maelor exact attack timings, phase lengths, arena pressure, damage | core-combat language and thematic progression locked | boss playtest |
| UQ-NM-005 | **D/E/H** | Which actual save-state memories are feasible/safe/meaningful for Listener realization | use player-loved actual state where feasible; no `true ending` gate | implementation + narrative playtest |
| UQ-NM-006 | **E** | Story Minimum / Partial / Full / Upgrade-Stripped fixture matrix proves no optional gate | hard rule locked | deterministic final-dungeon fixtures |
| UQ-NM-007 | **E/H** | S6 silence and independent restart reads as intentional, not as a bug | moment locked | runtime + human play |
| UQ-NM-008 | **C/H** | Final decommission feels correct and costly rather than a victory-button | ending relationship locked | Listener/finale playtest |

---

# 13. Content-production questions

These do not require owner decisions unless authoring discovers a conflict with locked canon.

| ID | Class | Question / unknown | Blocking point |
|---|---|---|---|
| UQ-CNT-001 | **D** | Exact geometry/layout/prop density/encounter placement for region pods | Relevant production wave |
| UQ-CNT-002 | **D/C** | Exact dialogue wording beyond locked anchor lines | Writing pass + voice/readability review |
| UQ-CNT-003 | **D/C** | Exact optional hint placement and environmental discovery language | Completion/content pass |
| UQ-CNT-004 | **D/C** | Exact credits compositions/shot sequence for supported save states | Gate 10/12 content pass |
| UQ-CNT-005 | **D/E** | Which authored content can safely be data-driven/text-reviewed vs must remain `.uasset`/`.umap` binary | Gate 6/content pipeline proof |

---

# 14. Conditional future decisions — not current blockers

## Precision aim / first-person / gyro

Camera Decision #18 is already **resolved**:

> **No verb, no camera mode.**

Gate 1 intentionally has no generic precision aim, first-person toggle, or gyro aim.

Only if a future **new approved player verb** genuinely requires precision pointing does a new camera decision become necessary.

Until then this is not an open TODO.

## Major design changes caused by prototype evidence

If runtime proof shows a locked design is materially unworkable or harmful:
- capture evidence;
- identify exact authority;
- propose the smallest revision;
- obtain owner approval where canon changes.

Do not pre-authorize unknown future revisions in this register.

---

# 15. Questions explicitly NOT open

Do not ask again unless new evidence justifies reopening:
- ordinary sprint stamina cost — **none**;
- universal/free climbing — **no**;
- generic Gate 1 first-person/precision aim/gyro — **no**;
- whether Line Skiff is a free-roam mount — **no**;
- whether Roadhand Pulse is a speed boost — **no**;
- whether Switchshoe is raw top-speed upgrade — **no**;
- whether Setup/Payoff copies source facts — **no**;
- completion category counts/weights — **locked by doc 104**;
- Drift Knot threshold — **10 reconciled Faults + story/Skiff prerequisites**;
- whether Local Accord is mandatory for Null Meridian — **no**;
- whether Quiet Court immediately precedes Maelor — **no; it is the midpoint turn**;
- whether Null Meridian is six regional barrier rooms — **no**;
- whether 100% is required for a valid ending — **no**;
- whether System IDE can use a shadow state model — **no**.

---

# 16. Review cadence

This register must be reviewed:
- at Documentation Closure Phase 4;
- before each implementation gate begins;
- when a prototype exposes a new architecture/design conflict;
- before Alpha, where foundational unknowns must be closed or explicitly waived by owner authority.

Do not let an old `deferred` sentence automatically create a new register item. Check later authority first.

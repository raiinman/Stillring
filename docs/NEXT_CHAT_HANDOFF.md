# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Operational status:** Core design through Save/World-State, Completion, Issue #9 Setup/Payoff, and Issue #10 Traversal Transformation is documentation/design complete once the current Issue #10 closure package merges. UE5.8 runtime implementation, System IDE implementation, deterministic fixture execution, performance evidence, and human play acceptance remain UNVERIFIED unless later authority explicitly proves them.

## Read first

1. `docs/125_TRAVERSAL_TRANSFORMATION_ISSUE_10_CLOSURE_AUDIT.md`
2. `docs/126_TRAVERSAL_TRANSFORMATION_DECISION_REGISTER_ADDENDUM.md`
3. `docs/124_TRAVERSAL_TRANSFORMATION_DECISION_5_NETWORK_INTEGRATION.md`
4. `docs/123_TRAVERSAL_TRANSFORMATION_DECISION_4_ACQUISITION_MASTERY.md`
5. `docs/122_TRAVERSAL_TRANSFORMATION_DECISION_3_WORLD_LAYER_ROUTE_STATE.md`
6. `docs/121_TRAVERSAL_TRANSFORMATION_DECISION_2_ROUTE_NETWORK_GRAMMAR.md`
7. `docs/120_TRAVERSAL_TRANSFORMATION_DECISION_1_LINE_SKIFF_SELECTION.md`
8. `docs/100_COMPLETION_DRIFT_KNOT_AUTHORITY_ADDENDUM.md`
9. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`
10. `docs/98_COMPLETION_SKILL_TRIAL_AUTHORITY_ADDENDUM.md`
11. `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`
12. `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
13. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`
14. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
15. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
16. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
17. `docs/119_SETUP_PAYOFF_DECISION_REGISTER_ADDENDUM.md`
18. `docs/118_SETUP_PAYOFF_ISSUE_9_CLOSURE_AUDIT.md`
19. `docs/18_PROJECT_DECISION_REGISTER.md`
20. GitHub Issue #11 — Define Null Meridian synthesis trial matrix

Always re-check exact current `main` before repository writes.

## Required method

For unresolved design work:

fresh research -> reconcile existing authority, IP, accessibility, failure/recovery, save semantics, System IDE, deterministic fixtures, content-production cost, and human-play implications -> owner review/approval -> document -> exact diff/review -> expected-head merge -> next decision.

The owner's previous auto-approval delegation applied to locomotion/traversal work and was used for Issue #10. **Do not carry that delegation into Issue #11.** Null Meridian synthesis decisions require explicit owner review unless the owner grants a new delegation.

Do not silently reopen a locked decision merely because an older authored document contains shorthand. Use the authority/supersession chain.

---

# Completion status

Completion Decision #16 remains locked in `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`.

Canonical completion remains 16 equal 6.25% top-level buckets.

Relevant here:

- Cross-state Setup/Payoff = 12 canonical items;
- Skill Trials = 9;
- Tool Mastery Upgrades = 14;
- Drift Knots = 12.

Drift Knot family eligibility is:

**10 reconciled Resonance Faults + existing story/Line Skiff prerequisites.**

Older fixed 13-Fault wording is superseded.

---

# Issue #9 Setup/Payoff — CLOSED / design complete

Issue #9 closed after PR #167 / main merge `30d3e0efca12ae71a2a3ccc9189a755166e4bde3`.

Authority:

- `docs/112` — semantic state authority;
- `docs/113` — commit boundaries;
- `docs/114` — payoff materiality;
- `docs/115` — 12-chain portfolio;
- `docs/116` — authoring/data authority;
- `docs/117` — S01/S06/S11 prototypes;
- `docs/118` — closure audit;
- `docs/119` — compact decision register.

Runtime Setup/Payoff/DataAsset/Save/IDE/vertical-slice/human proof remains future work.

---

# Issue #10 Traversal Transformation — locked decisions

## Decision #1 — Line Skiff selection — `docs/120`

Selected **Line Skiff** as Stillring's midgame traversal transformation.

Core identity:

> **The Line Skiff is a network vehicle, not a mount. It makes authored roads newly expressive; it does not replace the world between them.**

Rejected as primary transformation:

- wind-rig — overlaps Vane/High Aerie, broad 3D world/camera scope, puzzle-bypass risk;
- maintenance strider — horse-analogue behavior, large terrain/IK/collision/dismount scope.

Line Skiff:

- seeded at Graymile before Grand Ring;
- tied to Tessa's route/courier history;
- acquired on changed-world return;
- uses `pattern.roadhand_pulse`;
- cannot be summoned anywhere;
- cannot free-roam cross-country;
- is not ordinary mounted combat;
- has no normal fuel/stamina/ticket travel tax;
- preserves authored on-foot exploration.

## Decision #2 — route/network grammar — `docs/121`

Locked principle:

> **The semantic network owns legal macro travel; the player owns acceleration, coasting, braking, bounded lateral placement, junction intent, Roadhand Pulse, momentum, and camera.**

Stable identities:

- `skiff.route.<region>.<slug>`
- `skiff.node.<region>.<slug>`

Spline/Actor/map paths are presentation, never persistence identity.

Control/network rules:

- accelerate / coast / brake;
- low-speed reverse only;
- meaningful bounded lateral corridor control;
- route-edge scrub/resistance rather than invisible billiard bounce;
- readable standard junctions use player branch intent;
- no quest-marker branch selection;
- no safe default -> controlled stop;
- Roadhand Pulse wakes/identifies compatible infrastructure, never generic boost;
- intentional boarding/parking/dismount at compatible semantic nodes;
- no baseline high-speed dismount exploit;
- minor collision sheds momentum, not instant fail;
- major invalid route -> controlled safe stop;
- manual camera orbit remains authoritative.

Switchshoe:

- `upgrade.lineskiff.switchshoe`;
- before upgrade, marked legacy transfer may require stop/re-couple;
- after upgrade, supported adjacent strips may transfer at speed;
- does not increase global top speed or permit off-network hopping.

## Decision #3 — Stillness/Hush/world route state — `docs/122`

Authority separation:

- Story/World State owns durable route history/damage/repair;
- Hush/World-Layer owns active `Waking` / `Hush` semantic layer;
- Line Skiff network derives current traversal from those truths;
- Runtime Data Layers/streaming are representation only.

While riding, seam shift is legal only if the current route has an explicit deterministic paired continuation and destination occupancy is safe before semantic commit.

No route contract -> reject before commit.

Route expression classes:

- Shared Invariant;
- Paired Expression;
- Layer Exclusive;
- Related Distinct.

Roadhand may wake valid dormant infrastructure but cannot override destroyed/story-blocked/tool-gated/layer-invalid roads.

Non-deferrable world events that could invalidate an occupied route require an Occupied-Segment Continuity Contract.

Changed-world route changes may not silently brick Drift Knots or required access.

## Decision #4 — acquisition/mastery — `docs/123`

Teaching arc:

1. see Tessa use it;
2. safely wake/couple/move/park;
3. unpressured fun stretch;
4. learn lateral control, braking, junction, parking;
5. learn Roadhand-in-motion with safe fallback;
6. ordinary-world practice;
7. Trial 05 Relay Run;
8. Switchshoe expansion;
9. advanced Drift Knot/tool synthesis.

Mastery = route fluency, not top speed.

Trial 05:

`trial.circuit.line_skiff_relay_run`

Tests:

- acceleration/coasting/braking;
- momentum;
- junction/route choice;
- Roadhand Pulse;
- recovery.

Three physical relay flags use generous authored mechanical timing.

Completion does NOT require rank/par/leaderboard/perfect/no-collision/personal best.

Accessible timing/steering/speed accommodations earn identical Trial completion and reward.

Qualifying clear settles Switchshoe exactly once.

## Decision #5 — network/optional integration — `docs/124`

Network is shared world infrastructure, not 12 Hunt racetracks.

Purpose families:

- Trunk Corridors;
- Hub Approaches;
- Regional Spurs;
- Legacy/Maintenance Lanes;
- Hazard/Hunt Segments;
- Mastery Course.

By natural late-game state, network should meaningfully approach every major region where story/world facts permit, usually preserving a last meaningful on-foot stretch.

The 12 Drift Knots retain stable existing identities and progressively combine:

- base Skiff/Cantor;
- Anchor;
- Glasslung;
- Temper;
- Switchshoe;
- Vane/Crosswind;
- Palinode;
- authored observation window;
- Mirror;
- Hush/Mirror;
- Fine Fork;
- seam/Switchshoe/Fine Fork synthesis.

No route-discovery completion category.

No required infinite courier grind.

Other tools interact while riding only through explicit Route Tool Interaction Contracts: Observe/Diagnose, In-Motion Compatible, Slow-Zone Compatible, or Park/Service Required.

Route Listener remains bounded completion assistance after 12/12 Knots.

---

# Issue #10 closure — `docs/125`

All original acceptance criteria are design-satisfied:

- 3 concepts evaluated;
- 1 selected;
- route/network requirements documented;
- Hush/Stillness interaction documented;
- optional Hunt hook defined;
- mastery activity defined;
- foreshadowing preserved;
- faster/more expressive known-world travel specified;
- limitations preserve authored on-foot spaces.

Issue #10 can close **design/documentation complete** after the closure package merges.

Runtime proof remains explicitly open, including:

- UE5.8 Skiff implementation;
- semantic route graph;
- high-speed camera tuning;
- World Partition streaming/HLOD performance at target speed;
- Hush paired-route transitions;
- save/reload;
- Roadhand/Switchshoe runtime;
- Trial 05;
- 12 Drift Knots;
- Route Listener;
- accessibility;
- Line Skiff / Route Network System IDE;
- human confirmation that the Skiff is fun, readable, transformative, and does not trivialize the world.

`docs/126` is the compact traversal decision-register addendum.

---

# NEXT unresolved design issue

**Issue #11 — Define Null Meridian synthesis trial matrix.**

Issue goal:

Design the final dungeon as a cumulative exam of Stillring's existing verbs rather than a new-mechanic dump or renamed version of another game's finale.

Required verb families:

- Anchor Line;
- Glasslung Reed;
- Temper Gauntlet;
- Vane Cloak;
- Mirror Nail;
- Cantor patterns;
- Hush seam mode;
- core lock-on combat.

Issue rules:

- 5–7 compact synthesis trials;
- no one-room-per-region / one-barrier-per-element formula;
- every trial combines previously mastered mechanics;
- at least one traversal + combat trial;
- at least one perception/state-commitment trial;
- final Maelor/Listener sequence resolves thematic problem through mechanics as well as cutscenes;
- no new mandatory core verb in finale;
- every trial lists prerequisites and failure/recovery;
- debug loadouts must permit trial testing before full narrative content exists.

## Issue #11 process boundary

Do not auto-approve Issue #11 from the old traversal delegation.

Before proposing the first Null Meridian decision:

1. read Issue #11;
2. read final story / Null Meridian objective / scene / puzzle / combat authority;
3. inventory every required verb's final locked capabilities and upgrades;
4. research cumulative-final-dungeon / synthesis-challenge design without copying specific rooms/puzzles;
5. propose the first trial-matrix architecture for explicit owner review.

---

# Repository truth / stale-document rule

Newer authority controls conflicts:

- `docs/104` controls completion counts/thresholds over older literals;
- `docs/112`–`docs/119` control Setup/Payoff;
- `docs/120`–`docs/126` control Line Skiff / Issue #10 traversal transformation;
- old 13-Fault Drift Knot unlock is superseded by 10 reconciled Faults;
- Issue #10's wind-rig/strider candidate text is historical framing, not current selection authority.

Do not mechanically rewrite long authored docs merely to erase every old literal unless a scoped cleanup proves it is safe. Prefer explicit precedence/supersession when the older text remains valuable context.

---

# Governing constraints

- Unreal Engine 5.8 target
- C++ first; thin Blueprints
- every major stateful/tuned system gets an in-game System IDE/workbench
- no retail AI/API dependency
- clean-room IP discipline
- authored world over procedural duplication
- puzzles/story remain central
- no hidden morality meter
- no ordinary traversal stamina tax
- save/world facts use stable semantic IDs
- human play is final authority for movement feel, readability, pacing, puzzle clarity, emotional impact, and whether traversal transformation actually improves the game

**Build the system and its in-game IDE together.**

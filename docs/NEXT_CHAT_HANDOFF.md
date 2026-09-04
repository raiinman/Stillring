# Stillring — Next Chat Handoff

**Status:** current continuation boundary  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Decision boundary

Base before the current shimmy decision PR:

`f05314a60d8de918c82e8c157ccfe1a81ebc2630`

Current decision PR:
- PR #37 — `Design: lock same-handhold ledge shimmy`

## Read first in the next chat

1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
3. `docs/18_PROJECT_DECISION_REGISTER.md`
4. GitHub Issue #1 — `Lock player locomotion specification`
5. GitHub Issue #2 — `Lock exploration and combat camera specification`
6. `ROADMAP.md`
7. `CLAUDE.md`

## Production / technical baseline

- Engine: **Unreal Engine 5.8**.
- Primary implementation agent: **Claude**.
- Gameplay/state authority: **C++ first**.
- Blueprints: thin presentation/assembly/prototyping.
- Enhanced Input is the Gate 1 input baseline.
- No runtime AI/model/API dependency ships in the retail game.
- Permanent pipeline: **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**.
- Human play is authoritative for feel, fun, clarity, pacing, atmosphere, and whether movement disappears beneath play.
- High-impact player-feel choices are settled **one meaningful owner decision at a time** and migrated into repository authority before implementation depends on them.

## Governing movement principle

> **Simple intention, capable character, honest world.**

Ocarina of Time is a root reference, not a 2026 control ceiling. Stillring uses the Zelda design lineage to solve control problems rather than copy exact mechanics or protected expression.

## Gate 1 locomotion decisions already LOCKED

### Base movement

- Modern free exploration camera; recenter is convenience only.
- Camera-relative analog exploration movement.
- Useful careful movement below ordinary run.
- Stairs, tiny steps, minor floor lips, and ordinary uneven ground resolve automatically.
- Neris has an always-available, modest, deliberate jump.
- Major cliffs / meaningful height gates remain authored traversal problems.
- Affordance honesty is mandatory.

### Sprint

- Sustained sprint is available from the beginning.
- Ordinary sprint has **no stamina or resource cost**.
- Ordinary sprint may be sustained indefinitely.
- Sprint is separate from the eventual combat evade.
- Sprint supports **Hold** and **Toggle**; Hold is default.
- Full sprint remains highly steerable through ordinary curves/corners.
- Hard reversals briefly shed momentum; 180-degree reversal uses a quick planted turn and re-acceleration rather than an instant full-speed snap or giant turning circle.
- Sprint → jump preserves existing horizontal sprint momentum.
- Sprint-jumping adds no bonus speed.
- Landing continues/returns to sprint when sprint is still requested and no higher-priority state overrides it.
- Acquiring target lock ends exploration sprint but does not hard-zero velocity.
- Sprint → target lock uses a short natural deceleration/pivot into precise target-relative combat locomotion.
- Full exploration sprint is unavailable while target-locked.

### Mantle / scramble

- Low-obstacle mantle/scramble is automatic from clear movement or jump intent.
- There is no separate mantle button.
- Auto-mantle requires valid geometry, reachable landing/top, appropriate approach, clearance, standing space, and no conflicting higher-priority state.
- Passing near, brushing, or moving parallel to mantle geometry must not trigger it.
- Baseline mantle scope is body-relative, not a permanently locked arbitrary Unreal-unit threshold:
  - knee → waist: fluent ordinary traversal;
  - waist → lower chest: baseline-mantleable, but requires deliberate direct approach/jump intent;
  - shoulder-height and above: **not** baseline auto-mantle territory.
- Exact centimeters/angles/detection volumes/timing remain Gate 1 tuning tied to Neris's actual prototype scale and may not silently expand baseline mantle upward.

### Ledge catch / hang / pull-up / shimmy

- Above the ordinary mantle band, Neris may automatically catch a **valid reachable ledge** when jump/fall trajectory and directional intent clearly communicate the attempt.
- There is no dedicated ledge-grab button.
- Catch requires plausible physical reach, clear facing/directional intent, a valid handhold/hang position, and no conflicting higher-priority state.
- Incidental proximity, sideways/parallel passes, wall-brushing, implausible rescue distance, or arbitrary cliff falls must not trigger a catch.
- A successful catch always settles into a real **hang state first**.
- Catching does **not** immediately force pull-up.
- Neutral movement input keeps Neris hanging.
- Continued movement toward/up onto the ledge requests pull-up with **no separate climb button**.
- Pull-up only completes when the top/landing is valid, standable, and clear enough to finish safely.
- Invalid/blocked/unsafe tops leave Neris hanging rather than clipping or forcing placement.
- Left/right input while hanging allows **simple lateral shimmy along the same continuous valid handhold**.
- Releasing lateral input leaves Neris hanging at the current valid position.
- Shimmy may correct an imperfect catch or move Neris toward a valid pull-up position.
- Baseline shimmy does **not** wrap corners, cross gaps, transfer to another wall/ledge, jump laterally between ledges, or climb vertically between handholds.
- A corner, gap, new wall/ledge, or higher/lower handhold is a separate traversal problem.
- Exact shimmy speed, acceleration, animation cadence, hand spacing, and ledge-follow tolerances remain Gate 1 tuning.
- Ledge catch/pull-up/shimmy does not silently authorize a broader climbing system.

## Current locked movement grammar

```text
tiny step / stair / minor floor lip    → automatic terrain handling
careful movement                        → analog low-speed movement
ordinary travel                         → run
faster ground travel                    → unlimited sustained sprint
sprint input                             → Hold default / Toggle optional
normal sprint steering                  → highly responsive
hard sprint reversal                    → brief momentum loss + planted turn
sprint → jump                            → preserve horizontal sprint momentum
jump speed                               → no bonus speed added
land while sprint still requested       → continue/return to sprint
sprint → acquire target lock             → end sprint state, keep brief physical momentum
lock transition                          → short deceleration/pivot
locked movement                          → precise target-relative combat locomotion
small gap / intentional vertical move   → deliberate jump
knee → waist obstacle                   → fluent automatic step/vault/mantle
waist → lower-chest obstacle            → deliberate direct approach/jump + automatic mantle
shoulder-height and above               → NO baseline auto-mantle; meaningful ledge/traversal problem
valid reachable ledge + clear intent    → automatic catch → hang
hang + neutral movement                 → remain hanging
hang + continued toward/up intent       → pull up if top is valid/clear
hang + left/right on same handhold      → simple lateral shimmy
shimmy reaches corner/gap/new wall      → stop; NO automatic continuation
shimmy toward higher/lower handhold     → NO vertical transfer/climb
invalid or blocked top                  → remain hanging; NO forced pull-up
sideways/incidental/implausible ledge   → NO catch
passing near/alongside mantle geometry  → NO mantle
combat defense/reposition               → eventual evade, NOT sprint
major cliff / meaningful height gate    → route, tool, or later traversal capability
```

## IMMEDIATE NEXT OWNER DECISION

**Deliberate drop behavior while hanging.**

The shimmy package is now owner-approved and locked. The next question is intentionally narrower:

> When Neris is hanging, what explicit player input means “let go,” and how do we prevent ordinary analog movement from accidentally causing a fall?

Do **not** let Unreal defaults, Zelda, Assassin's Creed, Souls games, or another traversal system answer this automatically.

## Remaining Issue #1 owner-review sequence

Continue one meaningful decision at a time:

1. deliberate drop behavior;
2. broader climbing scope;
3. ladders;
4. swimming;
5. crouch/stealth posture if any;
6. slope scrambling/sliding;
7. fall damage/recovery;
8. jump arc / air control;
9. interaction while moving;
10. traversal-tool overrides.

Issue #1 also still needs enough prototype-tuning authority for controller dead zones, movement thresholds, acceleration/deceleration philosophy, and target-lock movement details before it can be considered implementation-complete. Do not let Claude infer permanent design policy from Unreal defaults.

## Camera / implementation order

After locomotion authority is sufficiently settled:

1. finish Issue #1 locomotion specification;
2. finish Issue #2 exploration/combat camera specification;
3. proceed to Issue #5 Unreal Engine 5.8 Gate 1 C++ prototype harness;
4. implement movement;
5. implement camera;
6. implement target lock.

Issue #5 should not invent movement/camera decisions that Issues #1/#2 have not resolved.

## Gate 1 human target

> **Within roughly five minutes, ordinary movement should stop being something the player consciously fights.**

A green automated test can prove state and regressions. It cannot declare movement fun, trustworthy, readable, or comfortable. Human play remains authoritative.

## Recent locomotion decision PR chain

- #25 deliberate jump + low-obstacle mantle
- #26 sustained sprint
- #27 unlimited ordinary sprint
- #28 Hold/Toggle sprint input
- #29 sprint steering + reversal weight
- #30 sprint-jump momentum
- #31 sprint-to-combat transition
- #32 automatic mantle trigger
- #33 body-relative mantle height scope
- #34 automatic reachable ledge catch
- #35 ledge hang pull-up continuation
- #37 same-continuous-handhold ledge shimmy

## Important continuation rule

If a fresh chat is opened, do not reconstruct Stillring from remembered chat text alone. Read this handoff, Issue #1, `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`, and `docs/18_PROJECT_DECISION_REGISTER.md`, then continue from the **deliberate drop decision** unless the owner deliberately changes priorities.

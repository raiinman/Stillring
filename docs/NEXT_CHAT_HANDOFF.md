# Stillring — Next Chat Handoff

**Status:** current continuation boundary  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Current main

`7ebf9526f02d83d8a98b254dc64a89250dcba8a0`

Current decision-authority branch:
- `design/deliberate-ledge-drop`

Latest merged decision PR:
- PR #37 — `Design: lock same-handhold ledge shimmy`

Reference research:
- PR #38 / `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` — **research input only; not design authority**. It studies AC1 through the Ezio/Kenway/Unity/RPG/Mirage/Shadows eras and 2026 Black Flag Resynced for player-intent, flow, safety, route-design, animation, and climbing lessons. It does not decide unresolved Stillring mechanics.

## Read first in the next chat

1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
3. `docs/18_PROJECT_DECISION_REGISTER.md`
4. GitHub Issue #1 — `Lock player locomotion specification`
5. GitHub Issue #2 — `Lock exploration and combat camera specification`
6. `ROADMAP.md`
7. `CLAUDE.md`

Use `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` only as secondary reference when an unresolved movement choice benefits from that research; never treat it as a shortcut around owner review.

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

Ocarina of Time is a root reference, not a 2026 control ceiling. Stillring uses the Zelda design lineage to solve control problems rather than copy exact mechanics or protected expression. Assassin's Creed movement history may be consulted as secondary research on traversal intention/flow, but does not become authority by reference.

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

### Ledge catch / hang / pull-up / shimmy / drop

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
- While hanging, release requires a **distinct deliberate Drop/Release action press**.
- Ordinary analog direction alone — including down, away, diagonal-down, partial input, drift, or dead-zone noise — never releases the ledge.
- A deliberate Drop/Release press acts promptly with **no hold-to-confirm delay**.
- The exact physical button/key binding is not locked and remains remappable control-layout/accessibility policy.
- Exact shimmy/drop timing, animation, and tolerance values remain Gate 1 tuning.
- Ledge catch/pull-up/shimmy/drop does not silently authorize a broader climbing system.

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
hang + analog down/away                 → remain hanging; NEVER implicit drop
hang + explicit Drop/Release press      → promptly let go
invalid or blocked top                  → remain hanging; NO forced pull-up
sideways/incidental/implausible ledge   → NO catch
passing near/alongside mantle geometry  → NO mantle
combat defense/reposition               → eventual evade, NOT sprint
major cliff / meaningful height gate    → route, tool, or later traversal capability
```

## IMMEDIATE NEXT OWNER DECISION

**Broader climbing scope.**

Ledge catch, pull-up, same-handhold shimmy, and deliberate Drop/Release behavior are owner-approved and locked. The next question is intentionally broader but still only one decision:

> Beyond the existing catch → hang → same-handhold shimmy → pull-up/drop grammar, does Neris have any baseline free-climbing capability at all, or should broader climbing exist only on specially authored traversal structures/tools/capabilities?

Do **not** let Unreal defaults, Zelda, Assassin's Creed, Souls games, or another traversal system answer this automatically.

## Remaining Issue #1 owner-review sequence

Continue one meaningful decision at a time:

1. broader climbing scope;
2. ladders;
3. swimming;
4. crouch/stealth posture if any;
5. slope scrambling/sliding;
6. fall damage/recovery;
7. jump arc / air control;
8. interaction while moving;
9. traversal-tool overrides.

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
- current branch `design/deliberate-ledge-drop` — deliberate explicit ledge release authority

## Important continuation rule

If a fresh chat is opened, do not reconstruct Stillring from remembered chat text alone. Read this handoff, Issue #1, `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`, and `docs/18_PROJECT_DECISION_REGISTER.md`, then continue from the **broader climbing scope decision** unless the owner deliberately changes priorities. Consult `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` only as secondary research when relevant.
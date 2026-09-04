# Stillring — Next Chat Handoff

**Status:** current continuation boundary  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Current locomotion authority

Detailed implementation-facing locomotion contract:

- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`

Design-lineage / reasoning authority:

- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`

Decision index:

- `docs/18_PROJECT_DECISION_REGISTER.md`

Tracking / acceptance:

- GitHub Issue #1 — `Lock player locomotion specification`

## Decision boundary

Merged main before this decision branch:

`ce3ab95512146e5a88ebf3e1947f479dc63a11aa`

Latest merged locomotion PR:

- PR #41 — `Design: lock player-driven ladder movement`

Current decision branch:

- `design/auto-ladder-mount`

Current decision:

- authored ladders automatically mount from clear deliberate movement intent when entry geometry/alignment are valid;
- no separate ladder-interact button;
- incidental proximity, parallel movement, sideways brushing, neutral standing, camera orientation, drift, and implausible offsets do not mount;
- short alignment transition is allowed but magnetic long-distance snapping is not.

Next decision after this branch merges:

- **ladder top/bottom dismount behavior**.

## Owner delegation for this locomotion pass

The owner authorized the assistant to continue the remaining **locomotion-only** decisions without stopping for individual approval. The same discipline still applies: reason through one meaningful decision at a time, write it into repository authority, inspect the diff, merge, then continue.

This delegation does **not** extend to camera, combat, story, world design, or unrelated systems.

The locomotion package remains pending a **final owner review together** before Issue #1 is considered final/closed.

## Read first in a fresh chat

1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
3. GitHub Issue #1
4. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
5. `docs/18_PROJECT_DECISION_REGISTER.md`
6. GitHub Issue #2 — camera specification
7. `ROADMAP.md`
8. `CLAUDE.md`

Use `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` only as secondary research. It is not design authority.

## Production / technical baseline

- Engine: **Unreal Engine 5.8**.
- Primary implementation agent: **Claude**.
- Gameplay/state authority: **C++ first**.
- Blueprints: thin presentation/assembly/prototyping.
- Enhanced Input is the Gate 1 input baseline.
- No runtime AI/model/API dependency ships in retail.
- Permanent pipeline: **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**.
- Human play is authoritative for feel, fun, clarity, pacing, atmosphere, and whether movement disappears beneath play.

## Governing movement principle

> **Simple intention, capable character, honest world.**

Ocarina of Time is a root reference, not a 2026 control ceiling. Stillring learns design principles without copying protected expression. Universal/free climbing has been deliberately rejected so authored route and puzzle meaning survives.

## Already locked at this boundary

- analog exploration movement and ordinary terrain handling;
- deliberate jump;
- unlimited sustained sprint with Hold default / Toggle optional;
- sprint steering/reversal and sprint-jump momentum;
- sprint-to-target-lock transition;
- automatic low-obstacle mantle with body-relative scope;
- automatic intent-based reachable-ledge catch;
- hang before pull-up;
- toward/up pull-up continuation;
- same-handhold shimmy only;
- explicit ledge Drop/Release; analog direction never drops;
- no baseline universal/free climbing;
- broader climbing only through explicit authored structures/tools/later capabilities;
- authored ladder movement is player-driven: up/down moves, neutral holds, camera remains player-owned;
- ladder mounting is automatic only from clear deliberate valid approach intent, never from incidental proximity.

See `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` for exact safeguards and grammar.

## Remaining locomotion sequence

Continue without pausing for approval, but preserve one-decision-at-a-time reasoning:

1. ladder top/bottom dismount behavior;
2. ladder Drop/Release behavior;
3. swimming;
4. crouch/stealth posture if any;
5. slope scrambling/sliding;
6. fall damage/recovery;
7. jump arc / air control;
8. interaction while moving;
9. traversal-tool overrides;
10. controller axes / dead-zone behavior;
11. analog low-speed / run / sprint threshold philosophy;
12. acceleration / deceleration / turning philosophy;
13. target-lock locomotion detail;
14. locomotion accessibility implications;
15. final five-minute human-play acceptance test;
16. repository-authority reconciliation and final owner review.

## Camera / implementation order

After final owner review of locomotion:

1. close/finalize Issue #1;
2. finish Issue #2 exploration/combat camera specification;
3. proceed to Issue #5 Unreal Engine 5.8 Gate 1 C++ prototype harness;
4. implement movement;
5. implement camera;
6. implement target lock.

Issue #5 must not invent unresolved Issue #1/#2 policy.

## Recent locomotion PR chain

- #25 deliberate jump + low-obstacle mantle
- #26 sustained sprint
- #27 unlimited ordinary sprint
- #28 Hold/Toggle sprint
- #29 sprint steering/reversal
- #30 sprint-jump momentum
- #31 sprint-to-combat transition
- #32 automatic mantle trigger
- #33 body-relative mantle scope
- #34 reachable ledge catch
- #35 hang/pull-up continuation
- #37 same-handhold shimmy
- #39 explicit ledge release
- #40 no baseline free climbing
- #41 player-driven ladder movement

## Continuation rule

If a fresh chat opens, read the files above and continue from **ladder top/bottom dismount behavior** once the current ladder-mount PR is confirmed merged. Do not reconstruct locomotion from chat memory alone.

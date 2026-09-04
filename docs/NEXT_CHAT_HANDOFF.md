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

`89200b7288d04e063e025fb4b55085e54c8bee77`

Latest merged locomotion PR:
- PR #42 — `Design: lock automatic deliberate-intent ladder mounting`

Current decision branch:
- `design/ladder-dismount`

Current decision:
- continued up input at a valid ladder top automatically dismounts onto the clear standable top;
- continued down input at a valid ladder bottom automatically steps off onto clear ground;
- neutral input at either ladder end keeps Neris attached;
- blocked/unsafe exits keep Neris attached instead of clipping, teleporting, or forcing placement;
- local alignment is allowed only as needed for the authored ladder exit.

Next decision after this branch merges:
- **ladder-specific Drop/Release behavior**.

## Owner delegation for this locomotion pass

The owner authorized the assistant to continue the remaining **locomotion-only** decisions without stopping for individual approval. Keep the established discipline: one meaningful decision at a time, repository authority first, diff inspection before merge.

This delegation does **not** extend to camera, combat, story, world design, or unrelated systems.

The locomotion package remains pending a **final owner review together** before Issue #1 is considered final/closed.

## Read first in a fresh chat

1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
3. GitHub Issue #1
4. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
5. `docs/18_PROJECT_DECISION_REGISTER.md`
6. GitHub Issue #2
7. `ROADMAP.md`
8. `CLAUDE.md`

Use `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` only as secondary research; it is not design authority.

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

## Already locked at this boundary

- analog exploration movement and ordinary terrain handling;
- deliberate jump;
- unlimited sustained sprint with Hold default / Toggle optional;
- sprint steering/reversal, sprint-jump momentum, and sprint-to-lock transition;
- automatic low-obstacle mantle with body-relative scope;
- automatic intent-based reachable-ledge catch;
- hang before pull-up, toward/up pull-up continuation;
- same-handhold shimmy only;
- explicit ledge Drop/Release; analog direction never drops;
- no baseline universal/free climbing;
- broader climbing only through explicit authored structures/tools/later capabilities;
- authored ladder movement is player-driven;
- ladder mounting is automatic only from clear deliberate valid approach intent;
- ladder top/bottom dismount follows continued climb direction only when the exit is valid and clear; neutral stays attached.

See `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` for exact safeguards and grammar.

## Remaining locomotion sequence

1. ladder Drop/Release behavior;
2. swimming;
3. crouch/stealth posture if any;
4. slope scrambling/sliding;
5. fall damage/recovery;
6. jump arc / air control;
7. interaction while moving;
8. traversal-tool overrides;
9. controller axes / dead-zone behavior;
10. analog low-speed / run / sprint threshold philosophy;
11. acceleration / deceleration / turning philosophy;
12. target-lock locomotion detail;
13. locomotion accessibility implications;
14. final five-minute human-play acceptance test;
15. repository-authority reconciliation and final owner review.

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
- #42 automatic deliberate-intent ladder mounting

## Continuation rule

If a fresh chat opens, read the files above and continue from **ladder-specific Drop/Release behavior** once the current ladder-dismount PR is confirmed merged. Do not reconstruct locomotion from chat memory alone.

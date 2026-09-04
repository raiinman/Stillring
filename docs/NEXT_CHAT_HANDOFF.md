# Stillring — Next Chat Handoff

**Status:** current continuation boundary  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Current locomotion authority
- Detailed contract: `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
- Design reasoning: `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
- Decision index: `docs/18_PROJECT_DECISION_REGISTER.md`
- Tracking/final review: GitHub Issue #1

## Current boundary
Merged main before this decision branch:
`4222428489ec9c26e07faf2e70f769143a22ff5b`

Latest merged locomotion PR:
- PR #46 — `Design: reject baseline crouch posture`

Current branch:
- `design/slope-scramble-slide`

Current decision:
- ordinary walkable slopes remain ordinary ground locomotion;
- short plausible borderline uphill slopes may use automatic, slower, no-stamina scrambling from clear direct intent;
- terrain outside that authored scramble band cannot be mountain-goated with sprint/jump/diagonal tricks;
- steep or low-traction downhill terrain may automatically slide;
- slides retain camera ownership and limited lateral line correction, but not full uphill cancellation;
- no baseline slide/surf button;
- exact angle/traction values remain Gate 1 tuning.

Next decision after merge:
- **fall damage / landing recovery**.

## Owner delegation
The owner authorized completion of the remaining **locomotion-only** decisions without individual approval pauses. Continue one meaningful choice at a time, document it, inspect the diff, merge it, then proceed. This does not extend to camera, combat, story, world design, or unrelated systems. Final locomotion authority remains pending a final owner review together.

## Read first in a fresh chat
1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
3. GitHub Issue #1
4. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
5. `docs/18_PROJECT_DECISION_REGISTER.md`
6. GitHub Issue #2
7. `ROADMAP.md`
8. `CLAUDE.md`

## Technical baseline
Unreal 5.8; Claude primary implementation agent; C++-first gameplay/state; thin Blueprints; Enhanced Input; no retail runtime AI dependency; CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY; human play owns feel/fun judgment.

## Governing movement principle
> **Simple intention, capable character, honest world.**

## Locked summary
The exact contract is in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`. Locked so far: ground/jump/sprint, mantle, ledge grammar, no universal free climbing, complete ladder grammar, surface swimming/no baseline dive, no baseline crouch, and the slope scramble/slide bands above.

## Remaining locomotion sequence
1. fall damage/recovery;
2. jump arc / air control;
3. interaction while moving;
4. traversal-tool overrides;
5. controller axes / dead-zone behavior;
6. analog low-speed / run / sprint threshold philosophy;
7. acceleration / deceleration / turning philosophy;
8. target-lock locomotion detail;
9. locomotion accessibility implications;
10. final five-minute human-play acceptance test;
11. repository-authority reconciliation;
12. final owner review together.

## Camera / implementation order
After final owner review: finalize Issue #1 → finish Issue #2 → Issue #5 Unreal harness → movement → camera → target lock. Issue #5 must not invent unresolved policy.

## Recent locomotion PRs
#25, #26, #27, #28, #29, #30, #31, #32, #33, #34, #35, #37, #39, #40, #41, #42, #43, #44, #45, #46.

## Continuation rule
Once the current slope PR is merged, continue from **fall damage / landing recovery**. Do not reconstruct locomotion from chat memory alone.

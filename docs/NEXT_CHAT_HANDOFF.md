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
`1e3a081104ee35c0e6a9c6c1b9127c64dcce263a`

Latest merged locomotion PR:
- PR #45 — `Design: lock surface-swimming baseline`

Current branch:
- `design/no-baseline-crouch`

Current decision:
- no always-available baseline crouch/stealth posture;
- careful/quiet-feeling positioning uses analog low-speed movement;
- no generic capsule shrink from a crouch input;
- crawlspaces, squeeze-throughs, concealment postures, or authored stealth states require a later explicit design need and do not create a universal crouch system.

Next decision after merge:
- **slope scrambling / sliding**.

## Owner delegation
The owner authorized completion of the remaining **locomotion-only** decisions without individual approval pauses. Continue one meaningful choice at a time, document it, inspect the diff, merge it, then proceed. This delegation does not extend to camera, combat, story, world design, or unrelated systems. Final locomotion authority remains pending a final owner review together.

## Read first in a fresh chat
1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
3. GitHub Issue #1
4. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
5. `docs/18_PROJECT_DECISION_REGISTER.md`
6. GitHub Issue #2
7. `ROADMAP.md`
8. `CLAUDE.md`

`docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` remains secondary research only.

## Technical baseline
- Unreal Engine 5.8
- Claude primary implementation agent
- C++-first gameplay/state authority
- thin Blueprints
- Enhanced Input
- no retail runtime AI dependency
- CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY
- human play owns feel/fun judgment

## Governing movement principle
> **Simple intention, capable character, honest world.**

## Locked locomotion at this boundary
The detailed mechanics live in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`. In summary:
- analog ground travel, deliberate jump, unlimited sprint;
- responsive sprint steering/reversal, sprint-jump momentum, sprint-to-lock transition;
- automatic low-obstacle mantle with body-relative scope;
- intent-based ledge catch → hang → same-handhold shimmy → valid pull-up / explicit release;
- no universal free climbing;
- complete authored-ladder grammar;
- competent surface swimming with no stamina/breath tax and no baseline underwater dive;
- no baseline crouch/stealth posture.

## Remaining locomotion sequence
1. slope scrambling/sliding;
2. fall damage/recovery;
3. jump arc / air control;
4. interaction while moving;
5. traversal-tool overrides;
6. controller axes / dead-zone behavior;
7. analog low-speed / run / sprint threshold philosophy;
8. acceleration / deceleration / turning philosophy;
9. target-lock locomotion detail;
10. locomotion accessibility implications;
11. final five-minute human-play acceptance test;
12. repository-authority reconciliation;
13. final owner review together.

## Camera / implementation order
After final owner review of locomotion:
1. close/finalize Issue #1;
2. finish Issue #2 camera specification;
3. proceed to Issue #5 Unreal Gate 1 C++ harness;
4. implement movement;
5. implement camera;
6. implement target lock.

Issue #5 must not invent unresolved Issue #1/#2 policy.

## Recent locomotion PRs
#25, #26, #27, #28, #29, #30, #31, #32, #33, #34, #35, #37, #39, #40, #41, #42, #43, #44, #45.

## Continuation rule
Once the current crouch PR is confirmed merged, continue from **slope scrambling / sliding**. Do not reconstruct locomotion from chat memory alone.

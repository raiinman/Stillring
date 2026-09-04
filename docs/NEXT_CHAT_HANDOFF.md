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
Merged main before this branch:
`cd874c96295007396110a0eaa70783b3ce60173e`

Latest merged locomotion PR:
- PR #47 — `Design: lock slope scramble and slide grammar`

Current branch:
- `design/fall-damage-recovery`

Current decision:
- routine traversal-scale falls deal no damage;
- the upper safe band may use a firm but brief non-damaging landing response;
- above the safe envelope, damage scales with impact severity and moderate falls use proportionate brief recovery rather than long helpless stun;
- genuinely extreme falls may be lethal;
- no landing-timing/jump/Sprint/input trick cancels impact;
- deep valid water may reduce ordinary-to-moderate impact severity but is not universal immunity;
- ledge/ladder release and slide-off falls feed the same severity rules.

Next decision after merge:
- **jump arc / air control**.

## Owner delegation
The owner authorized completion of the remaining **locomotion-only** decisions without individual approval pauses. Each meaningful choice is documented, diff-reviewed, and merged before proceeding. Final locomotion authority still requires final owner review together.

## Read first in a fresh chat
1. `docs/NEXT_CHAT_HANDOFF.md`
2. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
3. GitHub Issue #1
4. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
5. `docs/18_PROJECT_DECISION_REGISTER.md`
6. GitHub Issue #2
7. `ROADMAP.md`
8. `CLAUDE.md`

## Governing movement principle
> **Simple intention, capable character, honest world.**

## Remaining locomotion sequence
1. jump arc / air control;
2. interaction while moving;
3. traversal-tool overrides;
4. controller axes / dead-zone behavior;
5. analog low-speed / run / sprint thresholds;
6. acceleration / deceleration / turning philosophy;
7. target-lock locomotion detail;
8. locomotion accessibility implications;
9. final five-minute human-play acceptance test;
10. repository-authority reconciliation;
11. final owner review together.

## Implementation order after final locomotion review
Finalize Issue #1 → finish Issue #2 → Issue #5 Unreal harness → movement → camera → target lock. Issue #5 must not invent unresolved policy.

## Continuation rule
Once this fall-behavior PR is merged, continue from **jump arc / air control**. Do not reconstruct locomotion from chat memory alone.

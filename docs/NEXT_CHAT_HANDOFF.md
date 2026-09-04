# Stillring — Next Chat Handoff

**Status:** current continuation boundary  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Authority
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` — detailed locomotion contract
- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` — reasoning
- `docs/18_PROJECT_DECISION_REGISTER.md` — decision index
- Issue #1 — tracking/final review

## Current boundary
Merged main before branch: `eece251600f7520e2b589d7bede0631ac5037c27`

Latest merged locomotion PR:
- #48 `Design: lock fall damage and landing recovery`

Current branch:
- `design/jump-arc-air-control`

Current decision:
- predictable modest mostly fixed jump arc;
- jump hold does not meaningfully change height;
- no double jump/air jump/hover;
- takeoff inherits existing horizontal velocity; sprint-jump preservation remains binding;
- useful but limited air steering, no instant full-speed midair reversal or hidden acceleration;
- short coyote window immediately after ordinary ground-edge departure;
- short jump-input buffer before becoming legally able to jump;
- coyote/buffer cannot bypass explicit traversal/recovery states or authored height gates.

Next after merge:
- **interaction while moving**.

## Owner delegation
The owner authorized remaining **locomotion-only** decisions without individual approval pauses. Continue one decision at a time, document, inspect diff, merge, then proceed. Final locomotion authority remains pending final owner review together.

## Read first in a fresh chat
1. this handoff
2. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
3. Issue #1
4. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
5. `docs/18_PROJECT_DECISION_REGISTER.md`
6. Issue #2
7. `ROADMAP.md`
8. `CLAUDE.md`

> **Simple intention, capable character, honest world.**

## Remaining locomotion sequence
1. interaction while moving;
2. traversal-tool overrides;
3. controller axes / dead-zone behavior;
4. analog low-speed / run / sprint thresholds;
5. acceleration / deceleration / turning philosophy;
6. target-lock locomotion detail;
7. accessibility implications;
8. final five-minute human-play acceptance test;
9. repository-authority reconciliation;
10. final owner review together.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, continue from **interaction while moving**. Do not reconstruct locomotion from chat memory alone.

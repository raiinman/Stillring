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
Merged main before branch: `8e0bf05f2587a6956448756620c1d4dac5e6f0ab`

Latest merged locomotion PR:
- #49 `Design: lock jump arc and air-control philosophy`

Current branch:
- `design/interaction-while-moving`

Current decision:
- valid explicit interactions may be requested while Neris is moving; no perfect standstill prerequisite;
- movement-compatible interactions may complete without forcing a stop;
- planted/alignment interactions use a short natural deceleration and only small plausible local alignment;
- invalid/nonlocal alignment does not commit or magnetically pull Neris;
- moving out before commit cancels cleanly;
- committed interactions may temporarily own movement, then current valid movement input resumes promptly on release;
- airborne/traversal states are not yanked into ordinary ground interactions unless explicitly authored.

Next after merge:
- **traversal-tool overrides**.

## Owner delegation
Remaining **locomotion-only** decisions continue without individual approval pauses. One meaningful decision at a time; repository authority + diff review + merge. Final owner review together remains mandatory.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. traversal-tool overrides;
2. controller axes / dead-zone behavior;
3. analog low-speed / run / sprint thresholds;
4. acceleration / deceleration / turning philosophy;
5. target-lock locomotion detail;
6. accessibility implications;
7. five-minute human-play acceptance test;
8. repository-authority reconciliation;
9. final owner review.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, continue from **traversal-tool overrides**. Read the authority files rather than reconstructing from chat memory.

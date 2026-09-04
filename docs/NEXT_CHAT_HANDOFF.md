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
Merged main before branch: `41b4c0f1569527d3488c14850eb474b11390a6f2`

Latest merged locomotion PR:
- #51 `Design: lock traversal-tool locomotion override contract`

Current branch:
- `design/controller-dead-zone`

Current decision:
- movement stick uses radial/magnitude-based dead-zone processing rather than separate X/Y dead zones;
- stick direction is preserved once active and magnitude is smoothly rescaled beyond the dead-zone boundary;
- drift/jitter inside the dead zone produces zero movement and zero directional traversal intent;
- configurable outer saturation may let worn controllers reach full requested magnitude without changing direction or maximum speed;
- movement dead-zone settings are player-configurable within safe bounds and resettable;
- keyboard diagonals are normalized so they do not create a speed bonus;
- look-stick/camera response remains Issue #2 authority.

Next after merge:
- **analog low-speed / run / sprint threshold philosophy**.

## Owner delegation
Remaining **locomotion-only** decisions continue without individual approval pauses. One decision at a time; repository authority + diff review + merge. Final owner review together remains mandatory.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. analog low-speed / run / sprint thresholds;
2. acceleration / deceleration / turning philosophy;
3. target-lock locomotion detail;
4. accessibility implications;
5. five-minute human-play acceptance test;
6. repository-authority reconciliation;
7. final owner review.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, continue from **analog low-speed / run / sprint threshold philosophy**. Read repository authority rather than chat memory.

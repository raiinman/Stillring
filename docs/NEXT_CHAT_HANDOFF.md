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
Merged main before branch: `d9081fb4ab056d944a5d5be557792b1f3243f4b5`

Latest merged locomotion PR:
- #54 `Design: lock acceleration, deceleration, and turning philosophy`

Current branch:
- `design/target-lock-locomotion`

Current decision:
- target-lock movement is target-relative on the horizontal plane: forward/back control radial distance and left/right strafe/orbit;
- player owns combat spacing; neutral input does not auto-orbit, auto-maintain distance, or auto-position Neris;
- analog low-speed precision remains available and full exploration Sprint is unavailable;
- all locked movement directions remain useful, with only modest tuning differences allowed;
- Neris faces the target promptly without tank controls or animation-delayed movement;
- lock entry preserves brief physical velocity through the existing deceleration/pivot and clears toggled Sprint request;
- Jump remains the normal baseline jump, not a hidden side-hop/backflip/evade;
- combat-disrupting automatic exploration entries such as mantle initiation and ladder mounting are suppressed while ordinary target-lock ground locomotion is active;
- entering an incompatible traversal state ends target-lock locomotion;
- releasing/losing lock preserves physical velocity and immediately returns held input to camera-relative exploration semantics;
- camera framing/target-selection presentation remains Issue #2 authority.

Next after merge:
- **locomotion accessibility implications**.

## Owner delegation
Remaining **locomotion-only** decisions continue without individual approval pauses. One decision at a time; repository authority + diff review + merge. Final owner review together remains mandatory.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. accessibility implications;
2. five-minute human-play acceptance test;
3. repository-authority reconciliation;
4. final owner review.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, continue from **locomotion accessibility implications**. Read repository authority rather than chat memory.

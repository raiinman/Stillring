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
Merged main before branch: `9b96c3d085f995d9d9890ac3d4375af59e420643`

Latest merged locomotion PR:
- #53 `Design: lock analog speed and Sprint threshold philosophy`

Current branch:
- `design/accel-decel-turning`

Current decision:
- valid movement intent is acknowledged immediately rather than waiting on locomotion animation anticipation;
- careful movement has near-immediate precision response;
- ordinary run accelerates/decelerates briskly, stops in a short distance, and turns tightly without tank-style arcs;
- Sprint keeps highly steerable normal curves but carries more visible momentum, especially on stopping and hard reversal;
- hard Sprint reversal retains the already-locked momentum shed + planted redirect + re-acceleration behavior;
- exploration facing follows requested movement promptly, with only speed-appropriate visible lag;
- digital movement uses the same physical speed-band response;
- animation follows gameplay locomotion authority and may not introduce hidden control delay or state-transition impulses;
- exact acceleration/braking/friction/rotation values remain Gate 1 tuning.

Next after merge:
- **target-lock locomotion detail**.

## Owner delegation
Remaining **locomotion-only** decisions continue without individual approval pauses. One decision at a time; repository authority + diff review + merge. Final owner review together remains mandatory.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. target-lock locomotion detail;
2. accessibility implications;
3. five-minute human-play acceptance test;
4. repository-authority reconciliation;
5. final owner review.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, continue from **target-lock locomotion detail**. Read repository authority rather than chat memory.

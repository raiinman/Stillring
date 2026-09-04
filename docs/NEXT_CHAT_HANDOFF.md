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
Merged main before branch: `05a3e1ca35104da80a7c44717984681134f96d53`

Latest merged locomotion PR:
- #52 `Design: lock controller movement dead-zone semantics`

Current branch:
- `design/analog-speed-thresholds`

Current decision:
- post-dead-zone analog magnitude continuously expresses movement strength from useful careful movement through ordinary run;
- there is no required baseline Walk button/toggle;
- without Sprint requested, high/full analog input reaches the ordinary run ceiling;
- Sprint is an explicit request that unlocks the upper speed band rather than forcing tiny stick input to full Sprint;
- Sprint uses separate engage/disengage thresholds with hysteresis to prevent state chatter;
- Hold requests Sprint only while held; Toggle may remain armed through brief ordinary neutral movement but is cleared by explicit incompatible locomotion states to avoid surprise re-sprint;
- digital movement maps to ordinary run, or full Sprint when Sprint is requested and legally available;
- exact curves and threshold magnitudes remain Gate 1 tuning.

Next after merge:
- **acceleration / deceleration / turning philosophy**.

## Owner delegation
Remaining **locomotion-only** decisions continue without individual approval pauses. One decision at a time; repository authority + diff review + merge. Final owner review together remains mandatory.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. acceleration / deceleration / turning philosophy;
2. target-lock locomotion detail;
3. accessibility implications;
4. five-minute human-play acceptance test;
5. repository-authority reconciliation;
6. final owner review.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, continue from **acceleration / deceleration / turning philosophy**. Read repository authority rather than chat memory.

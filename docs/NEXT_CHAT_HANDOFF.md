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
Merged main before branch: `b4f448928e51c9cf448bf9bee9c04e23c0f14277`

Latest merged locomotion PR:
- #55 `Design: lock target-lock locomotion semantics`

Current branch:
- `design/locomotion-accessibility`

Current decision:
- locomotion actions are remappable and preserve semantic meaning across bindings;
- Sprint retains Hold/Toggle alternatives and baseline locomotion avoids mashing, grab-button holds, locomotion QTEs, or repeated swim inputs;
- movement dead-zone and outer-saturation settings remain configurable/resettable without changing world rules;
- keyboard/digital players receive an optional remappable Digital Precision modifier to access the tuned careful movement band without analog hardware;
- coyote time and jump buffering remain baseline forgiveness rather than hidden assists;
- accessibility input settings may change ergonomics/tolerance, not mantle/ledge/slope/jump/water/fall eligibility;
- camera and combat accessibility remain their own authority.

Next after merge:
- **final five-minute human-play acceptance test**.

## Owner delegation
Remaining **locomotion-only** decisions continue without individual approval pauses. One decision at a time; repository authority + diff review + merge. Final owner review together remains mandatory.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. five-minute human-play acceptance test;
2. repository-authority reconciliation;
3. final owner review.

## Implementation order after final review
Issue #1 final → Issue #2 camera → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, define the **final five-minute human-play acceptance test**. Read repository authority rather than chat memory.

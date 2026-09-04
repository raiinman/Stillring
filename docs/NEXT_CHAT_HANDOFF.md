# Stillring — Next Chat Handoff

**Status:** locomotion authority ready for reconciliation before final owner review  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Authority
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` — detailed locomotion contract and canonical human feel test
- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` — reasoning / design lineage
- `docs/18_PROJECT_DECISION_REGISTER.md` — decision index
- Issue #1 — tracking / final owner review

## Current boundary
Merged main before branch: `1e18479cbe2e7dd6afbd7af30d9ac5499f236b10`

Latest merged locomotion PR:
- #56 `Design: lock locomotion accessibility implications`

Current branch:
- `design/locomotion-five-minute-test`

Current decision:
- Gate 1 has one canonical compact graybox locomotion course and a five-minute-per-input-profile human feel script;
- the script deliberately tests ground speed bands, Sprint reversal, jump/coyote/buffer, mantle boundaries, ledge catch/hang/shimmy/pull-up/release, ladder intent, water, slopes, falls, interaction overlap, target-lock movement, rapid state transitions, and forbidden free-climbing behavior;
- controller and keyboard/digital each receive their own five-minute pass rather than splitting one pass;
- semantic failures are distinguished from ordinary tuning notes;
- any material unintended movement/traversal, hidden input delay, magnetic snapping, drift-driven traversal, exploit-created height/speed, target-lock autopilot, world-language lie, or accessibility-caused traversal-rule change is a hard fail;
- final human questions explicitly ask whether Neris obeyed intent, ever moved without intent, held control too long, lied about traversability, or made the tester fight the controls;
- owner feel may reject locomotion even when machine-verifiable tests pass;
- the test becomes a regression gate after material movement, collision, traversal, animation/root-motion, Enhanced Input, target-lock, or route-geometry changes.

Next after merge:
- **repository-authority reconciliation**.

## Owner delegation
The delegated locomotion decision pass is effectively complete after this test PR. Reconciliation may proceed without another approval pause, but no new locomotion semantics should be invented during reconciliation. Final owner review together remains mandatory before Issue #1 closes.

> **Simple intention, capable character, honest world.**

## Remaining sequence
1. reconcile locomotion authority across vision/reasoning/decision/spec/handoff/Issue #1 and any materially stale roadmap/Claude references;
2. present the complete package to the owner for final locomotion review together.

## Reconciliation rule
`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` owns exact player-facing locomotion behavior. Older/high-level files should summarize and point to it rather than duplicate the full mechanics. Reconciliation removes stale unresolved language and contradictions; it does not reopen settled locomotion decisions.

## Implementation order after final owner review
Finalize/close Issue #1 → finish Issue #2 camera specification → Issue #5 Unreal harness → movement → camera → target lock.

## Continuation rule
After this PR merges, create a dedicated reconciliation branch from merged `main`, read the current authority files, reconcile them without inventing new semantics, inspect the full diff, and merge. Then STOP automated locomotion work and present the package for final owner review. Do not close Issue #1 before that review.

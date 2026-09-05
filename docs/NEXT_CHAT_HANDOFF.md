# Stillring — Next Chat Handoff

**Status:** Gate 1 locomotion FINAL OWNER APPROVED; next design work is Issue #2 camera  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Final locomotion authority

Exact player-facing locomotion behavior:
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`

Supporting authority:
- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` — reasoning / design lineage;
- `docs/18_PROJECT_DECISION_REGISTER.md` — durable decision index;
- `docs/01_GAME_VISION.md` — vision-level movement summary;
- Issue #1 — completed locomotion design/owner-review record.

`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` owns exact semantics. Higher-level files summarize and point to it rather than duplicate a second locomotion specification.

> **Simple intention, capable character, honest world.**

## Final owner review — COMPLETE

The owner-delegated locomotion design pass and repository reconciliation were completed first. A final red-team review then exposed three small implementation ambiguities. The owner instructed that each be walked through in the established style and then auto-approved.

Final edge-case closures:
1. **ordinary unsupported edges:** no invisible edge guard; continued deliberate movement may carry Neris off an ordinary unsupported edge into normal airborne/fall rules;
2. **deliberate release:** releasing a ledge or ladder cannot immediately auto-recatch/remount the same released attachment from unchanged overlap; genuine separation and a new valid approach are required, while a different genuinely reachable ledge may still be caught under normal rules;
3. **target-lock jump reference:** limited air correction stays target-relative during a target-lock jump; if lock disappears before landing, the last stable target-relative frame remains in force until landing or another explicit movement-authority state takes over.

These are now locked in `docs/20` and covered by the canonical locomotion regression course.

## Complete final locomotion package

The package includes:
- camera-relative ground movement and useful careful analog control;
- deliberate ordinary edge commitment with no invisible cliff guard;
- unlimited sustained Sprint, Hold default / Toggle optional;
- sprint steering, reversal weight, jump momentum, and Sprint→target-lock continuity;
- deliberate jump, limited air correction, coyote time, and input buffering;
- automatic intent-based mantle with body-relative height scope;
- automatic reachable ledge catch → real hang → pull-up / same-handhold shimmy / explicit Drop/Release;
- same-attachment re-catch suppression after deliberate ledge/ladder release;
- no baseline universal/free climbing;
- authored ladder mount, player-driven movement, end exits, and explicit release;
- surface swimming with no baseline underwater free-dive;
- no baseline crouch/stealth posture;
- slope scramble/slide boundaries;
- fall severity and recovery philosophy;
- interaction while moving;
- traversal-tool override contract;
- radial movement dead-zone semantics and worn-controller tolerance;
- analog careful→run continuum with explicit Sprint upper band and hysteresis;
- responsive acceleration/deceleration/turning with animation subordinate to control;
- target-relative target-lock locomotion with no spacing autopilot;
- stable target-relative airborne movement frame through target-lock jumps;
- locomotion accessibility/remapping and Digital Precision for keyboard;
- canonical five-minute-per-input-profile human feel/regression test.

## System IDE architecture — first-class production rule

`docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` and Issue #58 are binding.

> **Build the system and its in-game IDE together.**

Gate 1 implementation must establish the shared in-game developer-shell pattern with a **Locomotion IDE** so movement can be inspected, tuned, reset, validated, and iterated while the game is running. Camera and every later major system must register its own workbench into the same architecture rather than inventing unrelated debug menus.

At minimum the Gate 1 Locomotion IDE must expose live locomotion/input state, speed/acceleration/rotation state, Sprint state, traversal eligibility/rejection reasons, fall classification, approved live-tunable numeric values, canonical locomotion-test teleports/reset, and clear session-override versus promoted-value provenance.

## Current boundary

- Issue #1 locomotion: ready to close after final closure PR merges;
- Issue #58 System IDE framework: open implementation dependency;
- **Issue #2 camera specification is next**;
- camera design must not reinterpret settled locomotion semantics;
- camera-specific look response, collision, recenter, target selection/framing, lock-loss presentation, look-stick accessibility, and motion-reduction behavior remain to be settled under Issue #2.

## Implementation order

1. close Issue #1 after the final owner-approval closure PR merges;
2. complete Issue #2 camera specification with owner review;
3. ensure Issue #5 Gate 1 Unreal harness includes the shared System IDE shell + Locomotion IDE registration pattern;
4. bootstrap the Unreal 5.8 C++ prototype;
5. implement locomotion under `docs/20` and its Locomotion IDE under `docs/21`;
6. implement camera/targeting presentation under the final Issue #2 authority and register Camera/Targeting IDE in the same shell;
7. run deterministic verification plus the canonical human feel tests.

## Continuation rule

Do **not** reopen locomotion semantics merely because implementation tuning begins. Exact numeric values explicitly left to Gate 1 tuning may be tuned through human play and the Locomotion IDE, but any proposed change to the locked movement grammar must return to design authority deliberately.

Proceed next to **Issue #2 — camera specification**, one meaningful camera/player-feel decision at a time unless the owner grants a similarly bounded delegation.

# Stillring — Next Chat Handoff

**Status:** locomotion authority reconciled; final owner review is the only remaining Issue #1 decision gate  
**Updated:** 2026-09-04  
**Repository:** `raiinman/Stillring`

## Locomotion authority

Exact player-facing locomotion behavior:
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`

Supporting authority:
- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` — reasoning / design lineage;
- `docs/18_PROJECT_DECISION_REGISTER.md` — durable decision index;
- `docs/01_GAME_VISION.md` — vision-level movement summary;
- Issue #1 — final owner review / closure gate.

`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` owns exact semantics. Higher-level files should summarize and point to it rather than duplicate a second locomotion specification.

> **Simple intention, capable character, honest world.**

## Reconciliation completed on this branch

No new locomotion semantics were invented during reconciliation.

The cleanup:
- removed stale Game Vision language that treated already-settled locomotion capabilities as unresolved;
- reduced Game Vision movement duplication so exact mechanics live in `docs/20`;
- removed stale lineage sections that still listed ladders/swimming/crouch/slopes/fall/air-control/interactions/tool overrides as pending;
- kept the Zelda-lineage document focused on the design problems/reasoning it exists to preserve;
- replaced the old broad `D-045 PENDING OWNER REVIEW` bundle with historical/superseded status and indexed the completed locomotion package;
- corrected the old ladder decision text that still claimed mount/dismount/release were pending;
- made the remaining pending locomotion item the truthful one: **final owner package review**;
- added `docs/20` to Claude's required authority path for movement/traversal implementation;
- updated README status so the project no longer says Issue #1 is still choosing capabilities one by one.

`ROADMAP.md` was reviewed and intentionally left unchanged where its gate-level rule remains correct: locomotion and camera authority must be complete before Gate 1 implementation outruns design.

## Complete locomotion package now awaiting owner review

The package includes:
- camera-relative ground movement and useful careful analog control;
- unlimited sustained Sprint, Hold default / Toggle optional;
- sprint steering, reversal weight, jump momentum, and Sprint→target-lock continuity;
- deliberate jump, limited air correction, coyote time, and input buffering;
- automatic intent-based mantle with body-relative height scope;
- automatic reachable ledge catch → real hang → pull-up / same-handhold shimmy / explicit Drop/Release;
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
- locomotion accessibility/remapping and Digital Precision for keyboard;
- canonical five-minute-per-input-profile human feel/regression test.

## Human acceptance gate

The owner must review the package before Issue #1 closes.

The canonical feel test in `docs/20` remains authoritative after implementation. A green machine test does not overrule an owner verdict that locomotion feels late, magnetic, slippery, unpredictable, tiring, or otherwise wrong.

Do **not** close Issue #1 or begin treating locomotion semantics as finally owner-accepted until that review happens.

## System IDE architecture — now first-class

Separate from locomotion semantics, the project now has `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` and Issue #58.

Gate 1 implementation must establish the shared in-game developer-shell pattern with a **Locomotion IDE** so movement can be inspected, tuned, reset, validated, and iterated while the game is running. Camera and every later major system must register its own workbench into the same architecture rather than inventing unrelated debug menus.

## After owner locomotion acceptance

1. record final owner acceptance in Issue #1 / decision authority and close Issue #1;
2. finish Issue #2 camera specification;
3. update Gate 1 implementation scope so Issue #5 includes the shared System IDE shell + Locomotion IDE pattern;
4. bootstrap the Unreal 5.8 Gate 1 C++ prototype;
5. implement movement under `docs/20` rather than Unreal defaults;
6. implement camera/target lock under the final Issue #2 authority;
7. run automated verification **and** the canonical human feel tests.

## Continuation rule

After the reconciliation PR is merged, **stop making new locomotion design decisions automatically** and present the reconciled package to the owner for final review. The standing delegated approval applied to the locomotion design pass; the promised final owner review remains mandatory.

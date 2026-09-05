# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera design COMPLETE / LOCKED. Gate 2 player combat design COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat design COMPLETE / LOCKED through Decisions #1–#10; Issue #104 closes with `docs/59` after merge. No Unreal implementation or human-play acceptance is implied by design closure.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. Enemy / encounter authority `docs/50`–`docs/59`
5. `ROADMAP.md`
6. Open project issues before selecting the next design system.

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Gate 2 enemy / encounter decisions — LOCKED
1. Attack bandwidth — `docs/50`.
2. Melee pressure — `docs/51`.
3. Ranged pressure — `docs/52`.
4. Shield/armor — `docs/53`.
5. Telegraph/readability — `docs/54`.
6. Offscreen/occluded threats — `docs/55`.
7. Enemy reaction/interrupt — `docs/56`.
8. Archetype coordination/composition — `docs/57`.
9. Disengage/reset/re-entry — `docs/58`.
10. **Deterministic fixture / reset / cumulative closure** — `docs/59`: stable semantic fixture IDs; deterministic roster registration and placement validation; transactional reset of reservations/attacks/reactions/warnings/projectiles/player baseline; explicit fixture reset may respawn fixture-owned dead enemies without changing ordinary disengage semantics; named solo/pair/trio/stress fixtures; deterministic seed-visible fuzzing only as supplement; machine invariants remain separate from human feel acceptance; structured capture/repro records; all debug mutations carry provenance; Gameplay Debugger/Automation/CQTest are optional execution/inspection tools, never policy authority; development surfaces excluded from Shipping.

## Gate 2 enemy / encounter closure boundary
`docs/50`–`docs/59` now define an implementation-facing enemy/encounter policy chain and required Combat/Encounter System IDE evidence.

The design system is complete. The following remain **not yet completed by design closure**:
- Unreal implementation;
- exact numeric balancing/timing;
- animation/art/audio production;
- packaged-build verification;
- ten-minute human repeated-combat acceptance from ROADMAP;
- production checkpoint/save respawn semantics beyond the fixture interface.

Do not reopen locked semantics merely because implementation has not begun.

## Next work
Re-read `ROADMAP.md` and current open issues. Select the next unresolved **design system** by actual project dependency/order, then apply the same one-decision-at-a-time research/approval/documentation loop.

Do not automatically jump into implementation merely because Gate 2 design authority is complete. Do not assume the next system from old chat memory.

## Governing constraints
C++ first for gameplay/state authority; thin Blueprint presentation. System IDE remains first-class production infrastructure. No retail runtime AI/model/API dependency. Human play is final authority for feel. Clean-room IP rules apply.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
System IDE: **Build the system and its in-game IDE together.**

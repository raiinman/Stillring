# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera COMPLETE / LOCKED. Gate 2 player combat COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat is active in Issue #104. Encounter Decisions #1–#9 are LOCKED. Next fresh decision: **#10 encounter spawn/reset/debug fixture + cumulative closure**.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. Encounter authority `docs/50`–`docs/58`
5. `ROADMAP.md`
6. GitHub Issue #104

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Locked encounter decisions
1. Attack bandwidth — `docs/50`.
2. Melee pressure — `docs/51`.
3. Ranged pressure — `docs/52`.
4. Shield/armor — `docs/53`.
5. Telegraph/readability — `docs/54`.
6. Offscreen/occluded threats — `docs/55`.
7. Enemy reaction/interrupt — `docs/56`.
8. Archetype coordination/composition — `docs/57`.
9. **Disengage/reset/re-entry** — `docs/58`: no magic leash radius; semantic Dormant/Engaged/Disengaging/Returning/Reset-Ready lifecycle; sustained loss of credible reachable fight drives disengage; temporary LOS/path loss does not; no new commits during Disengaging/Returning; projectiles remain real; no instant health refill; dead enemies do not revive from aggro loss; re-entry before completed reset preserves causal state; authored territory prevents cross-map pursuit; visible teleport-home is rejected; IDE exposes every viability/reset reason.

## Next fresh decision — #10 spawn/reset/debug fixture + cumulative closure
Core question:
> **What deterministic fixture and reset contract proves the whole Gate 2 encounter system repeatedly, including death/checkpoint cleanup, without turning debug controls into hidden gameplay authority?**

Research independently. Resolve:
- stable encounter fixture IDs and authored roster/setup data;
- deterministic spawn registration/order and valid placement;
- reset semantics for living/dead enemies, projectiles, reservations, reactions, warnings, health and player state;
- player-death/checkpoint integration boundary;
- developer spawn/reset/health controls and provenance;
- named 1/2/3/5-enemy representative fixtures;
- machine-validatable invariants versus human-play authority;
- capture/replay evidence format;
- cumulative Issue #104 acceptance and Gate 2 enemy/encounter closure.

## Remaining Issue #104 sequence
10. spawn/reset/debug fixture + cumulative closure.

## Governing constraints
Camera will not rescue crowd design. Player combat authority is settled. Enemy gameplay properties cannot come from animation alone. C++ first. No retail runtime AI/model/API dependency. Human play remains final authority. Clean-room IP rules apply.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
System IDE: **Build the system and its in-game IDE together.**

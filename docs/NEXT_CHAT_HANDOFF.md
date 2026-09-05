# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera COMPLETE / LOCKED. Gate 2 player combat COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat is active in Issue #104. Encounter Decisions #1–#3 are LOCKED; Decision #4 is finalizing in the current branch. Next fresh decision after merge: **#5 enemy telegraph / readability contract**.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. `docs/50_GATE2_ENCOUNTER_ATTACK_BANDWIDTH_ADDENDUM.md`
5. `docs/51_GATE2_MELEE_ENEMY_PRESSURE_MODEL_ADDENDUM.md`
6. `docs/52_GATE2_RANGED_ENEMY_PRESSURE_MODEL_ADDENDUM.md`
7. `docs/53_GATE2_SHIELD_ARMOR_ENEMY_ADDENDUM.md`
8. `ROADMAP.md`
9. GitHub Issue #104

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Locked encounter baseline
### #1 Attack bandwidth
> **Keep the whole group alive. Keep the actual danger readable.**
One ordinary `MajorCommit`; separately-approved one-lane `PressureCommit`; non-holders stay active; target lock is independent; no offscreen fairness exemption; IDE explains every grant/deny/release.

### #2 Melee pressure / spacing
> **Close with purpose. Commit honestly. Leave the player room to answer.**
Broad pressure bands; shared approach occupancy; honest attack-start conditions; genuine whiffs; no magnetism/input reading; real Recovery/Yield; cramped spaces reduce pressure rather than allowing swarms.

### #3 Ranged pressure / line of fire
> **Make distance matter without letting distance cheat.**
Visible non-homing projectile baseline; honest fire corridor/friendly obstruction; bounded observable-motion lead frozen at launch; Standard Ranged Shot conditionally earns the single `PressureCommit` lane only when readable/guardable/non-hard-stagger; no offscreen unreadable PressureCommit; no point-blank spam/infinite kiting.

### #4 Shield / armor verb-pressure — FINALIZING / LOCKED ON MERGE
> **Change the question, not the health bar.**
- directional explicit `Shielded` front-sector defense, not 360°/collision-only;
- ordinary Light into stable shield clearly deflects and does not drain hidden durability/posture;
- multiple valid answers: real flank/reposition; qualifying Heavy creates bounded `ShieldDisplaced`; enemy's own MajorCommit creates honest `Exposure`; Perfect Guard preserves tempo during that exposure;
- no precision weak-point/aim-mode requirement;
- no universal enemy posture resource or broad armor damage sponge layer;
- shield enemy's offensive action uses normal `MajorCommit`; defense itself consumes no attack lane and gets no PressureCommit attack;
- finite state-dependent reorientation, no instant 180° flank denial;
- shield collision cannot become an oversized body wall;
- IDE exposes shield sector/state, incoming contact/result, displacement, exposure, facing and commit state.

## Next fresh decision — #5 enemy telegraph / readability contract
Research independently after #4 merges.

Core question:
> **What must the player be able to perceive before an enemy action becomes dangerous, and how do melee/ranged/shield attacks share one trustworthy warning grammar without becoming icon soup?**

Must resolve:
- semantic telegraph phases and relationship to attack reservation/Startup/Active;
- what visual/body/weapon/projectile evidence is mandatory;
- audio as supplement, never sole critical channel;
- whether any optional UI indicators are allowed and what they may communicate;
- color-independent/accessibility rules;
- Guardable / special-danger communication without copying another game's colored-ring language;
- fake tells/canceled tells policy;
- telegraph scaling under difficulty/accessibility without changing combat legality;
- animation-notify boundary: animation may present/timestamp but gameplay data owns danger windows;
- Combat/Encounter IDE diagnostics and adversarial overlap tests.

## Remaining Issue #104 sequence
5. telegraph/readability;
6. offscreen/occluded threat rules + optional communication;
7. enemy reaction/stun/poise/guard-break if retained;
8. archetype coordination + encounter composition;
9. disengage/reset/leash/re-entry;
10. spawn/reset/debug fixture + cumulative closure.

## Governing constraints
Camera will not rescue crowd design. No critical threat information may depend only on audio. Player combat authority is settled. Enemy properties cannot come from animation alone. BT/StateTree/EQS/Nav/projectile/GAS-like primitives are implementation options, not policy. C++ first. No retail runtime AI/model/API dependency. Human play remains final authority. Clean-room IP rules apply.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
System IDE: **Build the system and its in-game IDE together.**

## Mechanical documentation debt — not design debt
Camera `docs/28`/`docs/36` and combat `docs/49` remain temporary safe companion/register extensions awaiting normal-git consolidation. Do not reopen locked semantics because of bookkeeping.

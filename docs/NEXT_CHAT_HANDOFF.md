# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera COMPLETE / LOCKED. Gate 2 player combat COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat is active in Issue #104. Encounter Decisions #1–#4 are LOCKED; Decision #5 is finalizing in the current branch. Next fresh decision after merge: **#6 offscreen / occluded threat rules + optional communication**.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. Encounter authority `docs/50`–`docs/54`
5. `ROADMAP.md`
6. GitHub Issue #104

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Locked encounter decisions
1. **Attack bandwidth** — `docs/50`: one ordinary `MajorCommit`, one separately-approved `PressureCommit` lane, active non-holder pressure, lock independent, honest fairness.
2. **Melee pressure** — `docs/51`: broad pressure bands/occupancy, honest start conditions, real whiffs, no magnetism/input reading, Recovery/Yield.
3. **Ranged pressure** — `docs/52`: visible non-homing projectile, honest fire corridor, bounded lead frozen at launch, conditional readable Standard Shot `PressureCommit`, no offscreen cheat/kiting.
4. **Shield/armor** — `docs/53`: directional stateful shield, no hidden durability/posture, flank + Heavy `ShieldDisplaced` + attack `Exposure` + Perfect Guard tempo as valid answers, normal MajorCommit offense.
5. **Telegraph/readability** — `docs/54`, FINALIZING / LOCKED ON MERGE: Ready → committed Telegraph → Active → Recovery semantic grammar; body/world-space evidence first; no mandatory colored attack-ring language; no critical audio/color/vibration-only information; committed tells do not casually lie; danger direction matches presentation; gameplay owns Active, animation notifies synchronize/present; Major+Pressure overlap must remain separable; IDE validates threat timelines and animation/gameplay mismatch.

## Next fresh decision — #6 offscreen / occluded threat rules
Core question:
> **When may an enemy the player cannot meaningfully see begin or continue an attack, and what warning is enough without making the camera or UI omniscient?**

Research independently after #5 merges. Resolve:
- distinction between attack beginning offscreen versus an already-committed attack moving offscreen;
- hard occlusion versus merely outside frame;
- melee and projectile rules separately;
- whether/when directional threat indicators are justified;
- indicator information boundary (direction/timing/type) without target omniscience;
- audio + visual alternatives/accessibility;
- camera #6/#13 authority and no forced camera steering;
- PressureCommit eligibility implications;
- no attacks through meaningful opaque geometry;
- Combat/Encounter IDE and adversarial tests.

## Remaining Issue #104 sequence
6. offscreen/occluded threat rules;
7. enemy reaction/stun/poise/guard-break if retained;
8. archetype coordination + encounter composition;
9. disengage/reset/leash/re-entry;
10. spawn/reset/debug fixture + cumulative closure.

## Governing constraints
Camera will not rescue crowd design. Player combat authority is settled. Enemy gameplay properties cannot come from animation alone. Engine AI/animation/navigation primitives are implementation options, not policy. C++ first. No retail runtime AI/model/API dependency. Human play remains final authority. Clean-room IP rules apply.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
System IDE: **Build the system and its in-game IDE together.**

## Mechanical documentation debt — not design debt
Camera `docs/28`/`docs/36` and combat `docs/49` remain temporary safe companion/register extensions awaiting normal-git consolidation. Do not reopen locked semantics because of bookkeeping.

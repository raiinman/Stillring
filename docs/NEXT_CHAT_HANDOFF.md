# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion COMPLETE / LOCKED. Gate 1 camera Decisions #1–#18 COMPLETE / LOCKED. Gate 2 player combat Decisions #1–#11 COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat is active in Issue #104. Encounter Decisions #1–#2 are LOCKED; Decision #3 is finalizing in the current branch. Next fresh decision after merge: **#4 shield / armor enemy verb-pressure model**.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. `docs/50_GATE2_ENCOUNTER_ATTACK_BANDWIDTH_ADDENDUM.md`
5. `docs/51_GATE2_MELEE_ENEMY_PRESSURE_MODEL_ADDENDUM.md`
6. `docs/52_GATE2_RANGED_ENEMY_PRESSURE_MODEL_ADDENDUM.md`
7. `ROADMAP.md`
8. GitHub Issue #104

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile existing authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Locked enemy / encounter decisions

### #1 Attack bandwidth — LOCKED
`docs/50_GATE2_ENCOUNTER_ATTACK_BANDWIDTH_ADDENDUM.md`

> **Keep the whole group alive. Keep the actual danger readable.**

- shared coordinator owns attack permission;
- ordinary baseline: one `MajorCommit` at a time;
- separately-approved lower-bandwidth attacks may use one `PressureCommit` lane;
- non-holders stay active through honest positioning, not fake attack tells or waiting circles;
- commit granted before real telegraph/startup;
- target lock is independent of enemy attack permission;
- offscreen/occluded enemies receive no fairness exemption;
- no difficulty-based silent concurrency increase;
- IDE explains grant/deny/release/handoff.

### #2 Melee pressure / spacing — LOCKED
`docs/51_GATE2_MELEE_ENEMY_PRESSURE_MODEL_ADDENDUM.md`

> **Close with purpose. Commit honestly. Leave the player room to answer.**

- semantic Acquire/Approach/Pressure/RequestCommit/CommittedAttack/Recovery-Yield/React states;
- pressure uses broad bands, not one orbit radius;
- shared approach occupancy prevents capsule swarms;
- crowd avoidance smooths movement but cannot decide combat roles;
- attack starts only from honest range/facing/path/lane conditions;
- committed attacks can genuinely whiff; no late magnetism/input reading;
- Guard/Evade/Perfect Guard retain player authority;
- target lock is not an enemy movement leash;
- cramped geometry reduces feasible pressure rather than allowing clipping;
- real Recovery/Yield supports group flow.

### #3 Ranged pressure / line of fire — FINALIZING / LOCKED ON MERGE
`docs/52_GATE2_RANGED_ENEMY_PRESSURE_MODEL_ADDENDUM.md`

> **Make distance matter without letting distance cheat.**

Package locks:
- baseline ranged threat is a visible traveling **non-homing projectile**, not hitscan;
- broad ranged pressure band with explicit reposition triggers;
- honest line-of-fire / volume-aware firing corridor;
- friendly bodies do not become transparent firing props;
- real firing telegraph starts only after encounter permission;
- one Standard Ranged Shot earns conditional `PressureCommit` compatibility only when visible/readable, single-projectile, ordinarily Guardable, non-hard-stagger baseline, and timing does not intentionally collapse onto an unavoidable Major Commit instant;
- only one PressureCommit at a time;
- fully offscreen/hard-occluded/no-warning ranged attacks are not PressureCommit eligible by default;
- aim may use bounded observable current motion but freezes at launch; no future-input reading or homing;
- ordinary Guard can block frontal eligible projectile; Perfect Guard does **not** auto-reflect; Evade keeps existing rules;
- closing TooClose creates a tactical advantage; ranged does not point-blank spam or kite forever;
- target lock is irrelevant to firing permission;
- IDE exposes line-of-fire, aim sample, permission, projectile trajectory/outcome, reposition reason.

## Next fresh decision — #4 shield / armor enemy verb-pressure
Research independently after #3 merges.

Core question:
> **How does a defensive enemy force the player to change tactics without becoming a frontal invulnerability wall, giant health bar, hidden stamina test, or precision-aim weak-point gimmick?**

Must resolve:
- representative shield/armor archetype's tactical job;
- what ordinary Light/Heavy do against its defense;
- whether flank/reposition, Heavy commitment, Perfect Guard advantage, tools, or another approved verb opens it;
- whether defense is directional, stateful, breakable, bypassable, or temporarily displaced;
- no universal hidden posture/stamina bar unless separately justified;
- attack-bandwidth behavior while defending/attacking;
- collision/spacing so the enemy does not simply body-wall Neris;
- target-lock independence;
- enemy defensive telegraph/state readability;
- Combat/Encounter IDE and adversarial tests.

## Remaining Issue #104 sequence
4. shield/armor verb-pressure;
5. enemy telegraph/readability contract;
6. offscreen/occluded threat rules + optional communication;
7. enemy reaction/stun/poise/guard-break model if retained;
8. archetype coordination + encounter composition;
9. disengage/reset/leash/re-entry;
10. spawn/reset/debug fixture + cumulative closure.

## Governing constraints
- camera does not rescue crowd design with group framing;
- no critical threat information only in audio;
- player combat state authority is settled;
- enemy gameplay properties cannot come from animation alone;
- Behavior Trees/StateTree/EQS/Nav/projectile components are implementation tools, not policy;
- C++ first for authoritative gameplay/state;
- no retail runtime AI/model/API dependency;
- human play remains final authority for feel/readability;
- clean-room IP rules apply.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
System IDE: **Build the system and its in-game IDE together.**

## Mechanical documentation debt — not design debt
Camera `docs/28`/`docs/36` and combat `docs/49` are temporary safe companion/register extensions awaiting normal-git consolidation. Do not reopen locked semantics because of bookkeeping.

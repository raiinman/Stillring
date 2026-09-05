# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera COMPLETE / LOCKED. Gate 2 player combat COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat is active in Issue #104. Encounter Decisions #1–#6 are LOCKED. Next fresh decision: **#7 enemy reaction / stun / poise / guard-break model if retained**.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. Encounter authority `docs/50`–`docs/55`
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
5. **Telegraph/readability** — `docs/54`: Ready → committed Telegraph → Active → Recovery semantic grammar; body/world-space evidence first; no mandatory colored attack-ring language; no critical audio/color/vibration-only information; committed tells do not casually lie; danger direction matches presentation; gameplay owns Active, animation notifies synchronize/present; Major+Pressure overlap must remain separable; IDE validates threat timelines and animation/gameplay mismatch.
6. **Offscreen / occluded threats** — `docs/55`: fresh ordinary high-salience melee/shield commits require meaningful visibility; already-honest committed attacks continue if the player looks away; hard occlusion is stricter than merely offscreen; real projectiles persist after launch; ranged PressureCommit is offscreen-presentation-gated; optional directional threat indicator may expose coarse direction/urgency but not radar-like hidden enemy identity/position; UI/audio/haptics/accessibility remain supplemental; camera never steers for secondary threats.

## Next fresh decision — #7 enemy reaction / stun / poise / guard-break model if retained
Core question:
> **When Neris hits an enemy, what actually earns interruption, stagger, displacement, guard break, or continued commitment—and which of those systems do we really need?**

Research independently. Resolve:
- whether Stillring needs a universal hidden poise/stun meter at all;
- ordinary hit reactions versus true gameplay interrupts;
- light/heavy/Perfect Guard interaction with enemy commitment;
- archetype-specific resistance without unexplained immunity;
- shield-specific state integration from Decision #4;
- boss/large-enemy boundary without blanket super armor;
- repeated-hit stun lock prevention;
- reaction readability and recovery ownership;
- encounter commit cleanup when an attacker is interrupted;
- Combat/Encounter IDE and red-team fixtures.

## Remaining Issue #104 sequence
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

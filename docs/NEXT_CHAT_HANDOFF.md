# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion COMPLETE / LOCKED. Gate 1 camera Decisions #1–#18 COMPLETE / LOCKED. Gate 2 player combat Decisions #1–#11 COMPLETE / LOCKED; Issue #3 CLOSED. Gate 2 enemy / encounter combat is active under GitHub Issue #104. Encounter Decision #1 is LOCKED; Decision #2 is being finalized in the current branch. Next fresh decision after merge: **#3 ranged enemy pressure / line-of-fire / reposition model**.

## Read first
1. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
2. Camera authority `docs/22`–`docs/36`
3. Player combat authority `docs/37`–`docs/49`
4. `docs/50_GATE2_ENCOUNTER_ATTACK_BANDWIDTH_ADDENDUM.md`
5. `docs/51_GATE2_MELEE_ENEMY_PRESSURE_MODEL_ADDENDUM.md`
6. `ROADMAP.md`
7. GitHub Issue #104 — enemy / encounter combat system

Always re-check exact current `main` before repository writes.

## Required method
For each decision: fresh focused research → reconcile locked authority/IP/accessibility/controls/failure cases/System IDE/tests → one coherent package → scheduled-run delegated approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake.** Never batch unresolved decisions into one research packet.

## Locked player-combat baseline
- meaningful Startup/Active/Recovery commitment; gameplay owns legality, animation presents;
- three-entry one-press-per-strike Light chain;
- fixed committed Heavy;
- directional ordinary Guard with viable Hold/Toggle accessibility and no stamina drain;
- position-first Evade with short central combat-immunity window;
- explicit damage/reaction/interrupt hierarchy and retrigger protection;
- precision Perfect Guard layered above viable ordinary Guard;
- one bounded pending combat intent, no FIFO;
- bounded attack-facing assistance, no magnetism/vacuum;
- no universal player combat stamina/posture permission meter;
- Death atomically ends combat; retry restores a clean combat-local baseline from external world/checkpoint authority.

Cumulative state/transition authority: `docs/48_GATE2_COMBAT_STATE_MODEL.md`.

## Enemy / encounter Decision #1 — LOCKED
`docs/50_GATE2_ENCOUNTER_ATTACK_BANDWIDTH_ADDENDUM.md`

Principle:
> **Keep the whole group alive. Keep the actual danger readable.**

Locked:
- shared authoritative encounter coordinator owns attack permissions;
- ordinary baseline allows one `MajorCommit` at a time;
- later attacks may separately earn `PressureCommit` compatibility; none receive it by default;
- non-holders remain active through positioning/pressure rather than passive waiting circles;
- reservation is granted before genuine attack telegraph/startup;
- target lock and commit permission are independent;
- scheduler considers honest opportunity/readability/fairness and prevents starvation;
- no same-frame dog-pile on reservation handoff;
- difficulty does not silently increase Major Commit concurrency;
- offscreen/occluded enemies receive no cheaper fairness standard;
- Combat/Encounter IDE must expose every grant/deny/release and reason.

## Enemy / encounter Decision #2 — FINALIZING / LOCKED ON MERGE
`docs/51_GATE2_MELEE_ENEMY_PRESSURE_MODEL_ADDENDUM.md`

Principle:
> **Close with purpose. Commit honestly. Leave the player room to answer.**

Package establishes:
- local semantic states Acquire/Approach/Pressure/RequestCommit/CommittedAttack/Recovery-Yield/React/Dead;
- pressure uses bands/envelopes rather than one magic orbit radius;
- no automatic synchronized orbit around Neris;
- shared approach occupancy prevents capsule pileups and preserves usable gaps;
- Unreal crowd avoidance may smooth movement but cannot decide combat occupancy;
- `MajorCommit` request requires honest current range/facing/path/visibility/lane conditions;
- committed melee attacks can genuinely whiff; no late magnetic tracking/reach inflation/input reading;
- Guard remains viable; no invented unblockable/stamina break just because Guard is held;
- Evade can create a miss; Perfect Guard does not freeze the whole encounter;
- committed attacker has real Recovery/Yield and should not monopolize group turns;
- target lock is not an enemy movement leash;
- cramped geometry naturally reduces feasible pressure instead of authorizing clipping/swarming;
- baseline Gate 2 melee enemy has at least one ordinary guardable MajorCommit strike for exercising player combat.

## Next fresh decision — #3 ranged enemy pressure / line-of-fire / reposition
Research independently after Decision #2 merges.

Must decide at minimum:
- representative ranged enemy gameplay job;
- preferred distance/positioning and reposition triggers;
- line-of-fire and friendly-fire/ally-body obstruction policy;
- projectile versus hitscan/instant threat direction for the Gate 2 baseline;
- telegraph and travel readability;
- offscreen/occluded firing eligibility;
- whether any ranged attack genuinely earns `PressureCommit` status under Decision #1;
- how ranged pressure interacts with Guard/Evade/Perfect Guard without requiring generic precision aim;
- target-lock independence;
- no sniper-perfect input reading/leading beyond observable motion;
- Combat/Encounter IDE inspect/tune/exercise/validate/capture requirements;
- mixed melee+ranged red-team scenarios.

Do not assume ranged attacks bypass the shared commit coordinator.

## Remaining Issue #104 sequence
3. ranged pressure / line-of-fire / reposition;
4. shield/armor verb-pressure model;
5. enemy telegraph/readability contract;
6. offscreen/occluded threat rules + optional communication;
7. enemy reaction/stun/poise/guard-break model if retained;
8. archetype coordination + encounter composition;
9. disengage/reset/leash/re-entry;
10. spawn/reset/debug fixture + cumulative closure.

Each receives its own full pass.

## Governing constraints
- camera will not zoom/orbit/group-frame to rescue crowd design;
- no critical threat information may depend only on audio;
- player Guard/Evade/Perfect Guard rules are already authoritative;
- enemy attack properties must be gameplay data, not inferred from animation;
- Behavior Trees/StateTree/EQS/Nav are implementation tools, not owner policy;
- C++ first for authoritative gameplay/state; thin Blueprint/animation presentation;
- no retail runtime AI/model/API dependency;
- human play remains authoritative for combat feel/readability;
- clean-room IP rules apply to comparative research.

Movement:
> **Simple intention, capable character, honest world.**

Camera:
> **The player should look at Orra, not babysit the camera.**

System IDE:
> **Build the system and its in-game IDE together.**

## Mechanical documentation debt — not design debt
Camera `docs/28`/`docs/36` and combat `docs/49` are temporary companion/register extensions awaiting safe normal-git consolidation into the large cumulative docs. Do not reopen locked design because of that bookkeeping.

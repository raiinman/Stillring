# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED. Gate 1 camera Decisions #1–#18 COMPLETE / LOCKED. Gate 2 **player combat state model Decisions #1–#11 COMPLETE / LOCKED**. GitHub Issue #3 is ready to close after this reconciliation PR merges. The next unresolved Gate 2 design work is the **enemy / encounter combat system**, beginning with a fresh decision-by-decision pass rather than inventing enemy behavior during implementation.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. Camera authority `docs/22`–`docs/36`
4. Combat authority `docs/37`–`docs/47`
5. `docs/48_GATE2_COMBAT_STATE_MODEL.md`
6. `docs/49_GATE2_COMBAT_DECISION_REGISTER_EXTENSION.md`
7. `docs/18_PROJECT_DECISION_REGISTER.md`
8. `ROADMAP.md`
9. GitHub Issue #3 — close after verifying this reconciliation
10. Gate 2 roadmap requirements for melee/ranged/shield enemies and multi-enemy aggression/readability

Always re-check exact current `main` before repository writes.

## Methodical approval workflow — REQUIRED
The owner has explicitly delegated approval during scheduled deep-work runs **only after each individual decision receives its own complete pass**.

For every meaningful decision/system:
1. fresh focused research for the current decision;
2. current primary sources + relevant shipped-game design lineage at the abstract problem-solving level;
3. reconcile against locked Stillring authority, IP guardrails, accessibility, controls, failure cases, System IDE requirements, tests, and implementation boundaries;
4. produce one coherent decision package;
5. only when that individual package is genuinely complete, scheduled-run delegation permits locking/approving it;
6. document, inspect exact diff, merge with expected head verification;
7. only then begin the next decision.

**Work for as long as productively possible in each scheduled wake/session.** Continue through as many complete individual decisions/systems as possible, but never batch unresolved decisions or skip the research/approval/documentation loop.

## Player combat state system — COMPLETE
Combat Decisions #1–#11 are individually locked:
1. attack commitment / cancel philosophy;
2. three-entry Light chain semantics;
3. fixed committed Heavy semantics;
4. ordinary directional Guard;
5. position-first Evade with bounded central immunity;
6. damage/reaction and interrupt hierarchy;
7. Perfect Guard timing layer;
8. bounded one-slot input buffering;
9. bounded attack-facing assistance;
10. no universal core player stamina/posture meter;
11. Death / retry combat-state boundary.

`docs/48_GATE2_COMBAT_STATE_MODEL.md` reconciles these into the implementation-facing state diagram and legal/conditional/illegal transition matrix and verifies every Issue #3 acceptance criterion.

Player-combat principles now include:
- gameplay state owns legality; animation presents/timestamps it;
- meaningful attack commitment exists, but decorative clip length cannot imprison input;
- Light/Heavy/Guard/Evade are separate verbs with explicit transition authority;
- ordinary Guard remains viable without a stamina drain;
- Evade uses position plus a short justified forgiveness interval rather than broad roll-through-everything immunity;
- Perfect Guard rewards fresh timing without replacing viable ordinary Guard;
- hit damage and reaction are separate resolved results;
- one bounded pending combat intent is allowed; no stale combo command queue;
- facing help is bounded rotation, never attack vacuum/magnetism;
- core combat has no generic player stamina/posture permission meter;
- Death ends combat state immediately; retry restores a fresh combat-local baseline from external checkpoint/world authority.

### Combat documentation mechanics debt — not design debt
`docs/49_GATE2_COMBAT_DECISION_REGISTER_EXTENSION.md` temporarily carries the combat register rows because the connector should not replace the large root `docs/18` merely for mechanical consolidation.

When a normal git workspace is available:
- fold C-001 through C-012 into `docs/18`;
- verify against `docs/37`–`docs/48`;
- retire `docs/49`;
- do not reopen player combat policy merely because the register is being consolidated.

## Immediate next design system — Gate 2 enemy / encounter combat
Do **not** treat Issue #3 closure as full Gate 2 specification closure. `ROADMAP.md` still requires:
- one melee enemy;
- one ranged enemy;
- one shield/armor enemy;
- encounter aggression/readability compatible with the camera's practical visual bandwidth;
- test enemy spawn/reset behavior;
- enough enemy/combat integration for ten minutes of repeated combat to remain readable and satisfying.

Camera authority explicitly refuses to solve crowd unreadability by zooming out, orbiting toward offscreen enemies, or group-framing every threat. Therefore enemy/encounter design owns attack bandwidth, telegraph honesty, pressure staging, and offscreen fairness.

### Next decision — research fresh
Begin with the narrow foundational enemy/encounter question:
> **When several enemies can threaten Neris, who is allowed to commit a high-salience attack at the same time?**

Research this independently before approval. Do not copy Ocarina's exact attack-turn behavior, modern action-game director logic, or Unreal AI defaults. Determine Stillring's own attack-bandwidth / aggression-coordination rule, including:
- active attacker versus pressure/positioning roles;
- offscreen/occluded enemy constraints;
- melee/ranged interaction;
- target-lock independence;
- telegraph requirements;
- escalation without passive waiting circles;
- accessibility/readability;
- Combat/Encounter IDE inspect/exercise/validate/capture requirements;
- adversarial tests for 2/3/5 enemies, ranged cross-pressure, cramped rooms, target switching, and camera occlusion.

Only after that decision is individually researched/locked should the next enemy behavior decision begin.

## Inherited constraints for enemies / encounters
- target lock is tactical, not mandatory;
- player spacing remains player-owned;
- no camera group-framing rescue for crowds;
- offscreen threats require honest combat/UI/audio communication;
- no critical information may depend on audio alone;
- player Guard/Evade/Perfect Guard timing is already authority and enemy attacks must interact with it explicitly;
- enemy attacks must declare reaction force/guardability/other reviewed combat properties rather than deriving them from animation alone;
- enemy animation/Behavior Tree/StateTree may present/coordinate authored policy but may not silently become design authority;
- enemy stun/poise/guard-break remains unresolved and must be separately researched if needed;
- every substantial enemy/encounter state and rejection reason must be inspectable in the Combat/Encounter IDE.

## Camera documentation mechanics debt
Camera policy is complete. `docs/28` and `docs/36` remain temporary mechanical companions until a normal git workspace folds them into `docs/22` / `docs/18`. Do not reopen camera semantics for that cleanup.

## Governing rules
- Unreal Engine 5.8.
- Claude primary implementation agent.
- C++ first for authoritative gameplay/state; thin Blueprint/animation presentation.
- No retail runtime AI/model/API dependency.
- Pipeline: CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY.
- Human play remains authoritative for feel/readability.
- Research before every major design recommendation.
- Engine/template defaults are implementation options, never owner policy.
- `docs/05_IP_GUARDRAILS.md` clean-room rules apply to comparative game research.

Movement principle:
> **Simple intention, capable character, honest world.**

Camera principle:
> **The player should look at Orra, not babysit the camera.**

System IDE rule:
> **Build the system and its in-game IDE together.**

## Recent methodical combat PRs
- #92 — Combat #1 commitment/cancel
- #93 — Combat #2 Light chain
- #94 — Combat #3 Heavy
- #95 — Combat #4 Guard
- #96 — Combat #5 Evade
- #97 — Combat #6 hit/interrupt hierarchy
- #98 — Combat #7 Perfect Guard
- #99 — Combat #8 input buffer
- #100 — Combat #9 attack-facing
- #101 — Combat #10 resource model
- #102 — Combat #11 Death/retry — merge `054436fe57653bbdc377b98ceea773e94e10d8e2`

Next: merge combat-state reconciliation/closure, close Issue #3, then research the enemy/encounter attack-bandwidth decision individually.
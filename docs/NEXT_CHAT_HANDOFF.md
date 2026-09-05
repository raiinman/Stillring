# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED. Camera Decisions #1–#11 OWNER APPROVED. Decisions #1–#9 are reconciled into cumulative `docs/22`; Decisions #10–#11 remain canonical in `docs/26` and `docs/27` pending ordered cumulative reconciliation. Decisions #12–#18 have a durable NON-CANONICAL research packet awaiting owner review. Gate 1 UE/System IDE source scaffolding is open in PR #79 pending real UE 5.8 verification. Gate 2 combat-state research is also prepared non-canonically.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
4. `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`
5. `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md`
6. `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md`
7. `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`
8. `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`
9. `docs/research/CAMERA_DECISIONS_12_18_RESEARCH_PACKET.md`
10. `docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md`
11. `docs/research/GATE2_COMBAT_FRAME_RESEARCH_PACKET.md`
12. `ROADMAP.md`
13. `docs/18_PROJECT_DECISION_REGISTER.md`
14. GitHub Issues #2, #5, #58, and #3
15. Open PR #79 before doing more Gate 1 implementation work.

Always check the exact current `main` SHA before writing.

## Immediate owner-review queue
### Camera #12 — target-switch transition behavior — NEXT
Research is already prepared in `docs/research/CAMERA_DECISIONS_12_18_RESEARCH_PACKET.md`.

Recommended philosophy candidate:
> **Switch by intent, not by roulette.**

The same packet prepares #13 multiple-enemy framing limits, #14 large-boss framing, #15 jump/fall/mantle camera, #16 shake/accessibility, #17 sensitivity/inversion/mouse parity, and #18 aim/first-person/gyro deferral.

None of #12–#18 is canonical yet.

## Required reconciliation debt
Before Camera Decision #12 is repository-final, fold approved Decisions #10 then #11 into `docs/22_GATE1_CAMERA_SPECIFICATION.md` and mark both locked there while preserving `docs/26` and `docs/27` as provenance.

A one-shot GitHub Actions reconciliation helper was attempted during the deep-work run. GitHub recognized the workflow but failed before creating a job; the helper was removed from `main`. No camera authority was changed or lost. Do not repeat that CI approach blindly.

## Gate 1 implementation status
Remaining camera owner review does **not** block authorized infrastructure or locomotion implementation.

`docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md` defines the safe boundary.

### PR #79 — open / DO NOT MERGE WITHOUT UE 5.8 VERIFICATION
`Gate 1: bootstrap UE5.8 C++ and System IDE registry scaffold`

PR #79 contains source only:
- `game/Stillring.uproject` targeting UE 5.8;
- Enhanced Input plugin declaration;
- minimal Runtime and Editor targets;
- authoritative `Stillring` runtime module;
- development-only `StillringDev` module;
- shared System IDE workbench registry;
- provenance states: canonical / session override / staged / promoted;
- one registered Gate 1 sample workbench;
- source-level `Stillring.Gate1.SystemIDE.Registry` Automation smoke test;
- `game/BUILDING.md` with explicit verification entry points/status.

No `.uasset` or `.umap` binaries are included.

Current authoring environment does not contain Unreal Engine 5.8, so PR #79 has **NOT** been compiled, editor-loaded, Automation-run, or Shipping-exclusion-tested. Fix any real-engine API/build mismatch before merging.

Highest-leverage implementation sequence after PR #79 verification:
1. merge verified UE 5.8 C++ harness/System IDE registry;
2. add shared shell UI/navigation + scenario/provenance/result surfaces;
3. implement ground locomotion + analog processing + Sprint as the first complete gameplay/workbench vertical slice;
4. expand approved locomotion/traversal and Camera #1–#11 slices with their IDE surfaces alongside them.

## Gate 2 research prepared — NON-CANONICAL
`docs/research/GATE2_COMBAT_FRAME_RESEARCH_PACKET.md` prepares Issue #3 without approving combat feel/state policy.

Core architecture recommendation:
> **Combat legality lives in authoritative gameplay state. Animation presents and timestamps that state.**

Candidate feel philosophy:
> **Commit to the decision, not to dead time.**

Prepared future owner sequence:
1. attack commitment/cancel philosophy;
2. light-chain semantics;
3. heavy/committed attack semantics;
4. guard model;
5. evade model / i-frame decision;
6. hit reaction / interrupt hierarchy;
7. input buffering;
8. attack-facing/rotation assistance;
9. combat resource/stamina/posture decision;
10. death/retry combat-state boundary.

Do not implement these as final combat policy until owner review.

## Governing rules
- Unreal Engine 5.8.
- Claude primary implementation agent.
- C++ first for gameplay/state authority; thin Blueprints.
- No retail runtime AI/model/API dependency.
- Pipeline: CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY.
- Human play is authoritative for feel.
- Research before major design recommendations.
- Do not let engine/template defaults resolve owner policy.

Movement principle:
> **Simple intention, capable character, honest world.**

Camera goal:
> **The player should look at Orra, not babysit the camera.**

System IDE rule:
> **Build the system and its in-game IDE together.**

## Camera authority summary
1. Default exploration framing — LOCKED.
2. Player-owned orbit — LOCKED.
3. Conditional soft yaw follow — LOCKED.
4. Manual recenter — LOCKED.
5. Collision compression/recovery — LOCKED.
6. Occlusion priority/grace — LOCKED.
7. Close Quarters Camera — LOCKED.
8. Ceiling-Constrained Camera — LOCKED.
9. Vertical Context Assist — LOCKED.
10. Lock-on acquisition transition — LOCKED; provenance `docs/26`, cumulative reconciliation pending.
11. Dual-subject Relationship Frame — LOCKED; provenance `docs/27`, cumulative reconciliation pending.
12–18. PENDING OWNER REVIEW; research packet ready.

## Open project issues relevant to next work
- #2 — complete camera specification.
- #5 — bootstrap Gate 1 UE 5.8 C++ prototype harness.
- #58 — build shared in-game System IDE framework.
- #3 — combat frame/state model; research packet ready, owner policy still pending.
- #4/#8/#9/#10/#11 are later production/design tracks and should not displace Gate 1 implementation priority without explicit reason.

## Recent PRs
- #74 vertical-space camera behavior
- #75 reconcile vertical-space authority
- #76 lock-on acquisition transition
- #77 established target Relationship Frame
- #78 remaining-camera research + Gate 1 readiness
- #79 UE5.8/System IDE source scaffold — OPEN / UNVERIFIED

## Deep-work additions
- `docs/research/CAMERA_DECISIONS_12_18_RESEARCH_PACKET.md`
- `docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md`
- `docs/research/GATE2_COMBAT_FRAME_RESEARCH_PACKET.md`

Continue productively past camera research by verifying/advancing PR #79 on a UE 5.8 host and then implementing approved Gate 1 slices with their System IDEs. Do not implement unresolved owner camera/combat policy.

# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED. Camera Decisions #1–#11 OWNER APPROVED. Decisions #1–#9 are reconciled into cumulative `docs/22`; Decisions #10–#11 remain canonical in `docs/26` and `docs/27` pending ordered cumulative reconciliation. Decisions #12–#18 now have a durable NON-CANONICAL research packet awaiting owner review.

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
11. `ROADMAP.md`
12. `docs/18_PROJECT_DECISION_REGISTER.md`
13. GitHub Issues #2, #5, and #58

Always check the exact current `main` SHA before writing.

## Immediate owner-review queue
### Camera #12 — target-switch transition behavior — NEXT
Research is already prepared in `docs/research/CAMERA_DECISIONS_12_18_RESEARCH_PACKET.md`.

Recommended philosophy candidate:
> **Switch by intent, not by roulette.**

The packet also prepares #13 multiple-enemy framing limits, #14 large-boss framing, #15 jump/fall/mantle camera, #16 shake/accessibility, #17 sensitivity/inversion/mouse parity, and #18 aim/first-person/gyro deferral.

None of #12–#18 is canonical yet.

## Required reconciliation debt
Before Camera Decision #12 is repository-final, fold approved Decisions #10 then #11 into `docs/22_GATE1_CAMERA_SPECIFICATION.md` and mark both locked there while preserving `docs/26` and `docs/27` as provenance.

A one-shot GitHub Actions reconciliation helper was attempted during the overnight deep-work run. GitHub recognized the workflow but failed before creating a job; the helper was removed from `main`. No camera authority was changed or lost. Do not repeat that CI approach blindly.

## Authorized non-camera work can proceed
Remaining camera owner review does **not** block infrastructure.

`docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md` defines work that is safe now:
- minimal Unreal Engine 5.8 C++ project bootstrap for Issue #5;
- Enhanced Input baseline;
- Git/Git LFS Unreal rules;
- reproducible build/editor/Automation entry points;
- graybox Gate 1 scenario/test-map scaffolding;
- shared development-only System IDE shell for Issue #58;
- provenance model: canonical vs session override vs staged vs promoted;
- scenario registry/reset/teleport/validation/capture infrastructure;
- Locomotion IDE skeleton and implementation against final `docs/20` authority;
- Camera/Targeting IDE skeleton and approved Camera #1–#11 semantics, without inventing #12–#18 policy.

Highest-leverage implementation sequence:
1. UE 5.8 C++ harness + build/validation path;
2. shared System IDE shell + registry/provenance models;
3. ground locomotion + analog processing + Sprint as the first complete gameplay/workbench vertical slice;
4. expand locomotion/traversal and approved camera slices with their IDE surfaces alongside them.

Actual Unreal build/binary-asset verification requires an environment with UE 5.8 available; never claim those checks passed without that environment.

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
- #3 — combat frame/state model; may be researched, but combat feel/state policy requires deliberate owner review before implementation.
- #4/#8/#9/#10/#11 are later production/design tracks and should not displace Gate 1 implementation priority without explicit reason.

## Recent PRs
- #74 vertical-space camera behavior
- #75 reconcile vertical-space authority
- #76 lock-on acquisition transition
- #77 established target Relationship Frame

## Overnight/deep-work additions
- `docs/research/CAMERA_DECISIONS_12_18_RESEARCH_PACKET.md`
- `docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md`

Continue productively past camera research by advancing Issues #5/#58 within the readiness boundaries above. Do not implement unresolved owner camera/combat policy.

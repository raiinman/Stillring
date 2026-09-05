# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED. Camera Decisions #1–#11 OWNER APPROVED. Decisions #1–#9 are reconciled into cumulative `docs/22`; Decisions #10–#11 remain canonical in `docs/26` and `docs/27` pending ordered cumulative reconciliation. Camera #12 is the next owner decision.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
4. `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`
5. `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md`
6. `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md`
7. `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`
8. `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`
9. GitHub Issue #2
10. `docs/18_PROJECT_DECISION_REGISTER.md`
11. `ROADMAP.md`

Always check exact current `main` SHA before repository writes.

# CRITICAL WORKFLOW — OWNER RESTORED

Stillring proceeds **one meaningful design decision at a time**.

The required loop is:

> **deep research for the current decision → present recommendation/options to owner → explicit owner approval → document canonical decision → inspect exact diff → merge → only then research the next decision**

The owner's instruction to "work as long as possible" means continue doing as much useful work as possible **inside this loop**. It does **not** authorize batching unresolved decisions, assuming approval, jumping ahead into later systems, or beginning implementation before the applicable design package has been individually reviewed.

Previous locomotion auto-approval delegation applied to locomotion only. It does not grant automatic approval for camera, combat, or later system policy.

## Overnight deep-work correction
During the 2026-09-05 overnight run, the assistant over-interpreted permission to continue working and:
- created one batch research file covering Camera #12–#18;
- created a Gate 1 implementation-readiness plan;
- prepared Gate 2 combat research ahead of sequence;
- drafted a UE5.8/System IDE implementation scaffold in PR #79.

Those actions **do not change the owner-review workflow**.

### PR #79
PR #79 is CLOSED / NOT MERGED as premature implementation. Its branch may remain as exploratory scratch work, but it is not approved architecture, implementation authority, or a basis for further code work.

### Batch research files
The following files are **background notes only**:
- `docs/research/CAMERA_DECISIONS_12_18_RESEARCH_PACKET.md`
- `docs/research/GATE2_COMBAT_FRAME_RESEARCH_PACKET.md`
- `docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md`

They must **not** be treated as completed individual research passes, approval packets, canonical policy, or permission to implement. When each decision/system is actually reached, perform a fresh focused research pass on that decision, verify sources/current engine context, present the result to the owner, and wait for approval before advancing.

# Current exact next work

## Camera Decision #12 — target-switch transition behavior
This is the single current owner decision.

Before presenting #12:
1. perform a fresh focused deep study of target switching specifically;
2. research current UE 5.8 capabilities and primary sources;
3. study relevant shipped-game solutions at the design-problem level without copying exact expression;
4. reconcile against locked Camera #10 acquisition and #11 Relationship Frame;
5. cover controller and mouse input implications, switch-vs-manual-nudge conflict, candidate semantics, transition behavior, repeated inputs, no-candidate behavior, occlusion, vertical candidates, accessibility, failure cases, System IDE diagnostics, and representative tests;
6. present one coherent recommendation package to the owner;
7. do not mark #12 locked until explicit owner approval.

### Required cumulative reconciliation
Before repository-finalizing approved Camera #12, fold Camera #10 then Camera #11 into `docs/22_GATE1_CAMERA_SPECIFICATION.md` in order and mark both locked there while preserving `docs/26` and `docs/27` as provenance.

A prior GitHub Actions helper attempt failed before creating a job and was removed. Do not repeat that helper approach blindly.

# Camera authority summary
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
12. Target-switch transition behavior — **NEXT / PENDING OWNER REVIEW**.
13–18. PENDING OWNER REVIEW and must be handled individually after #12.

# After camera
Do not jump straight from camera into implementation merely because background planning exists.

When Issue #2 is fully resolved and reconciled, review the repository/roadmap with the owner and begin the next system using the same process:

> **research one meaningful decision → owner approval → canonical documentation → next decision**

For systems such as combat, puzzle/tool behavior, Hush architecture, save/world state, and other major production systems, research and lock their policy decisions individually before implementation depends on them.

The System IDE remains first-class authority:
> **Build the system and its in-game IDE together.**

That requirement affects every later implementation plan, but it does not authorize implementation before system policy is approved.

# Governing rules
- Unreal Engine 5.8.
- Claude primary implementation agent.
- C++ first for gameplay/state authority; thin Blueprints.
- No retail runtime AI/model/API dependency.
- Pipeline: CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY.
- Human play is authoritative for feel.
- Research **before** every major design recommendation.
- Do not let Unreal defaults, Claude, another game, or batch research decide unresolved Stillring policy.

Movement principle:
> **Simple intention, capable character, honest world.**

Camera goal:
> **The player should look at Orra, not babysit the camera.**

System IDE rule:
> **Build the system and its in-game IDE together.**

## Recent relevant PRs
- #76 — lock-on acquisition transition
- #77 — established target Relationship Frame
- #78 — batch background research/readiness notes; NON-CANONICAL
- #79 — premature UE/System IDE scaffold; CLOSED / NOT MERGED
- #80 — background Gate 2 combat research; NON-CANONICAL

Resume with **Camera Decision #12 only**.
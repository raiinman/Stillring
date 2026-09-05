# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED; Camera Decisions #1–#7 OWNER APPROVED.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
4. `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`
5. GitHub Issue #2 — `Lock exploration and combat camera specification`

Then check the exact current `main` SHA before creating a branch.

## Immediate next work
Decision #7 is canonical in `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`. Before repository-finalizing Decision #8, fold Decision #7 into the cumulative `docs/22_GATE1_CAMERA_SPECIFICATION.md` and mark item #7 locked there.

Then perform a fresh research pass and present **Camera Decision #8 — low-ceiling behavior** for owner review.

Do not infer #8 from cramped-room policy and do not let Claude/Unreal choose a default.

## Governing rules
- Unreal Engine 5.8.
- Claude primary implementation agent.
- C++ first for gameplay/state authority; thin Blueprints.
- No retail runtime AI/model/API dependency.
- Pipeline: CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY.
- Human play is authoritative for feel.
- Resolve one meaningful high-impact feel decision at a time unless the owner explicitly delegates otherwise.
- Research **before** major design recommendations.

Movement principle:
> **Simple intention, capable character, honest world.**

Camera goal:
> **The player should look at Orra, not babysit the camera.**

## System IDE rule
`docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` is first-class authority.

> **Build the system and its in-game IDE together.**

IDE debt counts as feature debt. Camera / Targeting must register in the shared dev-only shell and expose live state/rejection/tuning evidence for approved camera behavior.

## Camera decisions locked so far

### #1 Default exploration framing
Medium-wide, slightly elevated, full-body exploration view; Neris somewhat below center; enough footing plus forward-route/landmark visibility; stable through walk/run/Sprint; exact values remain tuning.

### #2 Orbit
360° player-owned yaw; generous bounded pitch; level horizon; camera input does not rotate Neris; manual input has priority; exact pitch limits/asymmetry remain tuning.

### #3 Automatic yaw follow
Conditional soft follow only. No hard snap. Manual input cancels assistance. Standing still does not auto-recenter. Careful movement receives little/none; open travel may receive more. Eventual Off/Never option required.

### #4 Manual recenter
Dedicated remappable action. Fast eased recovery of yaw + pitch. While moving, align behind stable travel direction; while stationary, behind Neris facing. Manual input cancels it. It never changes movement, target, or gameplay state.

### #5 Collision compression / recovery
Walls may shorten camera distance but do not steer it. Physical collision resolves promptly with a non-zero probe volume. Manual orbit stays authoritative while compressed. Outward recovery is smoother/slower with clearance stability + hysteresis. Camera-only blockers are allowed for pathological art collision.

### #6 Occlusion priority
Priority: Neris/readable movement first; established target second where physically honest; meaningful world geometry remains opaque/honest. Brief target LOS loss uses an occluded grace state. Sustained hard occlusion breaks lock instead of forcing camera around architecture. Explicit decorative clutter may be fade eligible.

### #7 Cramped-room behavior
Exact authority: `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`.

Stillring stays third-person. Severe compression changes composition, not control grammar. Close Quarters Camera may use small pivot/height/composition adjustments while preserving player yaw/pitch authority. No automatic first-person, fixed-camera, shoulder-aim, corridor snap, top-down, or aggressive FOV fallback. Neris may self-fade/dither only at pathological near-camera proximity to prevent interior-mesh clipping. Leaving the space uses Decision #5 recovery. Ordinary rooms that force long severe compression fail camera review unless deliberately authored.

Philosophy:
> **When the room gets smaller, the camera gets closer—not stranger.**

## Remaining Issue #2 sequence
1–7: LOCKED.  
8. **low-ceiling behavior — NEXT**  
9. vertical-space behavior  
10. lock-on acquisition transition  
11. lock-on framing distance/offset  
12. target-switch transition  
13. multiple-enemy framing limits  
14. large boss framing  
15. jump/fall/mantle camera  
16. camera shake/accessibility  
17. sensitivity/inversion/mouse parity  
18. aim/first-person/gyro if later proposed

Anything unresolved remains **PENDING OWNER REVIEW**.

## Recent camera PRs
- #63 default exploration framing
- #64 player-owned orbit
- #65 conditional yaw follow
- #66 manual recenter
- #67 collision compression/recovery
- #68 occlusion readability hierarchy

Main immediately before the Decision #7/handoff branch:
`26166302eb968feeb1f10c1f431188d88cbe236f`

Always re-check `main` next chat.

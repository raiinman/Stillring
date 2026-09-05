# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED; Camera Decisions #1–#10 OWNER APPROVED. Decisions #1–#9 are reconciled into cumulative camera authority; Decision #10 is canonical in its provenance addendum pending next reconciliation.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
4. `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`
5. `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md`
6. `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md`
7. `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`
8. GitHub Issue #2 — `Lock exploration and combat camera specification`

Then check the exact current `main` SHA before creating a branch.

## Immediate next work
Camera Decision #10 is canonical in `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`. Before repository-finalizing Decision #11, fold Decision #10 into the cumulative `docs/22_GATE1_CAMERA_SPECIFICATION.md` and mark item #10 locked there.

Then perform a fresh research pass and present **Camera Decision #11 — lock-on framing distance/offset philosophy** for owner review.

Do not infer #11 from the acquisition transition, Zelda lineage, stock Unreal behavior, or later multi-enemy/boss rules. Decision #11 owns the established ordinary lock-on composition: Neris/target screen placement, camera distance response to player-target separation, how strongly the target is centered, vertical-separation handling, whether combat uses modest dynamic framing, and how much camera influence the player retains while locked. Target-switch transitions remain #12, multiple-enemy framing #13, and large-boss framing #14.

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
Cumulative authority is reconciled into `docs/22`; provenance remains `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`.

Stillring stays third-person. Severe compression changes composition, not control grammar. Close Quarters Camera may use small pivot/height/composition adjustments while preserving player yaw/pitch authority. No automatic first-person, fixed-camera, shoulder-aim, corridor snap, top-down, or aggressive FOV fallback. Neris may self-fade/dither only at pathological near-camera proximity. Ordinary rooms that force long severe compression fail camera review unless deliberately authored.

Philosophy:
> **When the room gets smaller, the camera gets closer—not stranger.**

### #8 Low-ceiling behavior
Cumulative authority is reconciled into `docs/22`; provenance remains `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md`.

Low ceilings constrain vertically before avoidable distance compression. Ceiling-Constrained Camera lowers the rig/pivot smoothly, preserves yaw and as much pitch as geometry permits, never queues blocked pitch, never auto-aims down tunnels, and uses hysteresis against overhead pumping. Remaining obstruction follows #5; severe compression follows #7.

Philosophy:
> **When the ceiling comes down, the camera comes down with it—not into Neris.**

### #9 Vertical-space behavior
Cumulative authority is reconciled into `docs/22`; provenance remains `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md`.

Grounded exploration uses **Vertical Context Assist**. Sustained ascent/descent first shifts Neris modestly in screen-space to reveal more route in the direction of elevation change. A very weak, bounded, delayed soft-pitch assist may occur only when screen-space framing is insufficient, and manual camera input always cancels/suppresses it. Drop framing requires actual approach intent; nearby/parallel/behind drops do not pull the camera down. Tall rooms do not automatically aim the camera. Automatic vertical pitch must offer an eventual Off/Never option. The camera may not use quest, puzzle-solution, secret-route, treasure, hidden-enemy, or other privileged metadata to decide where to aim. Grounded #9 does not decide jump/fall/mantle (#15) or lock-on/combat framing (#10–#14).

Philosophy:
> **Make room for the height. Never aim on the player's behalf.**

### #10 Lock-on acquisition transition
Exact authority until reconciliation: `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`.

Lock requests use one immediate candidate evaluation. Initial acquisition requires honest visibility and strongly prioritizes current camera/screen intent over mere closeness or Neris facing. A valid winner commits target identity and target-relative locomotion immediately; Sprint exits through the already-approved short natural deceleration/pivot. The camera then performs one fast eased transition directly from its exact current pose toward the later-defined lock-on composition—no hidden recenter, hard snap, time slowdown, input freeze, dramatic FOV punch, or micro-cutscene. Failed requests have no camera/movement/Sprint side effects. Once committed, the system never silently retargets; temporary occlusion follows #6 and hard invalidation/cancel aborts cleanly from the current pose. Physical camera authority remains #5/#7/#8. Final established combat framing is #11 and intentional switching is #12.

Philosophy:
> **Lock the target instantly. Move the camera deliberately.**

## Remaining Issue #2 sequence
1–10: LOCKED.  
11. **lock-on framing distance/offset philosophy — NEXT / PENDING OWNER REVIEW**  
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
- #69 cramped-room camera behavior
- #70 reconcile cramped-room authority into cumulative spec
- #71 low-ceiling camera behavior
- #73 reconcile low-ceiling authority into cumulative spec
- #74 vertical-space camera behavior
- #75 reconcile vertical-space authority into cumulative spec

Main immediately before the Decision #10 branch:
`8a4dcd8b64e7d89a921c1179ef0f144b6d77936d`

Always re-check `main` next chat.

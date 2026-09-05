# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED; Camera Decisions #1–#11 OWNER APPROVED. Decisions #1–#9 are reconciled into cumulative camera authority; Decisions #10–#11 are canonical in their provenance addenda pending ordered reconciliation.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
4. `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`
5. `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md`
6. `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md`
7. `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`
8. `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`
9. GitHub Issue #2 — `Lock exploration and combat camera specification`

Then check the exact current `main` SHA before creating a branch.

## Immediate next work
Before repository-finalizing Camera Decision #12, reconcile approved Decisions #10 and #11 into `docs/22_GATE1_CAMERA_SPECIFICATION.md` **in order**, marking both locked while preserving `docs/26` and `docs/27` as provenance.

Then perform a fresh research pass and present **Camera Decision #12 — target-switch transition behavior** for owner review.

Do not infer #12 from generic action-game controls. #12 owns switch gesture/directionality, eligible switch candidates, transition speed, confirmation, camera movement, cooldown/debounce, no-candidate behavior, and conflicts with #11 bounded manual composition nudge. Multiple-enemy framing remains #13 and large-boss framing #14.

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

Grounded exploration uses **Vertical Context Assist**. Sustained ascent/descent first shifts Neris modestly in screen-space; only weak bounded delayed pitch assistance may follow. Manual input wins. Drop framing requires approach intent. Tall rooms do not auto-aim. Privileged puzzle/quest/secret metadata may not direct the camera.

Philosophy:
> **Make room for the height. Never aim on the player's behalf.**

### #10 Lock-on acquisition transition
Exact authority until reconciliation: `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`.

One immediate candidate evaluation; honest initial LOS; current camera/screen intent prioritized over mere closeness/facing; immediate target and target-relative locomotion commitment; Sprint exits via approved deceleration/pivot; one fast eased camera transition directly from current pose; no hidden recenter, hard snap, slowdown, freeze, FOV punch, or micro-cutscene; failed requests have no side effects; no silent retarget; #5/#6/#7/#8 remain authoritative.

Philosophy:
> **Lock the target instantly. Move the camera deliberately.**

### #11 Lock-on framing distance / offset philosophy
Exact authority until reconciliation: `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`.

Established ordinary lock-on uses a **dual-subject Relationship Frame**: show Neris, the locked target, and readable combat space between them. Target is soft-framed rather than hard-centered. Screen-space dead/soft/hard zones suppress jitter. Ordinary combat uses a canonical medium distance with modest capped separation-driven dolly, dead band + hysteresis, and essentially stable FOV. Camera adaptation is visual only and never maintains gameplay spacing. Player retains bounded manual composition nudge; exact control conflict with switching waits for #12/#17. #5/#6/#7/#8 remain physical/occlusion authority. Multiple enemies remain #13; bosses #14.

Philosophy:
> **Frame the relationship, not the reticle.**

Practical test:
> **Show Neris. Show the threat. Show the space between them.**

## Remaining Issue #2 sequence
1–11: LOCKED.  
12. **target-switch transition behavior — NEXT / PENDING OWNER REVIEW**  
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
- #76 lock-on acquisition transition

Main immediately before the Decision #11 branch:
`5e7444620b676586d52833cdc6ec10ef81a40346`

Always re-check `main` next chat.

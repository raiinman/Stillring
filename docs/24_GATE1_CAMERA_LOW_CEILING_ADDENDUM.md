# 24 — Gate 1 Camera Low-Ceiling Addendum

**Status:** FINAL OWNER APPROVED / RECONCILED INTO `docs/22`  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #8 provenance record for Issue #2. The cumulative implementation-facing authority now lives in `docs/22_GATE1_CAMERA_SPECIFICATION.md`; this file preserves the decision-specific owner-approved record.

## Authority

Camera Decision #8 is locked. Claude may not replace this behavior with stock Unreal Spring Arm behavior, an automatic downward-looking tunnel camera, a blanket Close Quarters trigger, an aggressive FOV fallback, or any other unstated low-ceiling policy.

Stillring's governing camera goal remains:

> **The player should look at Orra, not babysit the camera.**

The governing locomotion principle also remains intact:

> **Simple intention, capable character, honest world.**

---

## Camera Decision #8 — low-ceiling behavior — LOCKED

### Core rule
Low ceilings constrain the camera **vertically before they compress it longitudinally**.

When overhead clearance makes the canonical Decision #1 camera height impossible, Stillring enters a smooth **Ceiling-Constrained Camera** state that lowers the third-person rig/pivot within a tuning-defined range while preserving ordinary camera distance, player-owned yaw, and as much player-selected pitch as the world physically allows.

A low ceiling is not automatically a cramped room. Decision #8 handles overhead restriction; Decision #7 Close Quarters remains the severe-distance-compression response when legal camera distance also collapses.

### Resolution priority
For an overhead constraint, the camera resolves in this order:

1. preserve the player's requested viewing direction where physically legal;
2. lower the camera rig/pivot within the approved low-ceiling vertical adjustment envelope;
3. if obstruction still remains, use Decision #5 collision distance compression only as much as required;
4. if legal distance crosses Decision #7's severe-compression threshold, Close Quarters Camera becomes the relevant severe-compression presentation.

This priority prevents a simple low roof from needlessly driving the camera into Neris.

Exact height offsets, clearance thresholds, transition speeds, and distance-compression values remain Gate 1 tuning.

### Ceiling-Constrained Camera state
- the state activates only when meaningful overhead geometry prevents the normal camera rig from occupying its desired vertical position;
- the camera lowers smoothly rather than snapping between preset heights;
- sloped, stepped, cave-like, stair-understructure, and otherwise uneven ceilings should produce a continuous legal-height solution where practical;
- the state remains recognizably Stillring's ordinary third-person exploration camera;
- horizontal yaw ownership does not change;
- the state does not rotate Neris, alter movement authority, reinterpret camera-relative locomotion, or create a new gameplay mode;
- low ceiling alone does not automatically enter Decision #7 Close Quarters Camera.

### Player-owned pitch under physical constraint
The player retains the largest physically legal pitch range available under the current ceiling.

- lowering the rig/pivot is the first tool used to preserve useful pitch authority;
- if a requested pitch would still place the camera/probe through solid overhead geometry, pitch stops cleanly at the current physically legal boundary;
- the system does not counter-steer the camera away from the player's request merely to find a prettier view;
- reversing camera input responds immediately;
- no hidden or queued pitch is accumulated behind the physical limit;
- when clearance later becomes available, the camera does not snap toward a previously blocked stored angle;
- if the player is still actively holding camera input toward the newly available range, ordinary live input may continue moving the camera normally.

Exact pitch-bound calculation and solver implementation remain engineering/tuning choices so long as the player-facing semantics above hold.

### No automatic tunnel aim
Low-ceiling handling does **not** automatically pitch the camera downward, toward the floor, toward Neris, or toward a presumed corridor direction.

A low roof does not tell the system what the player wants to inspect. The player may still want to look toward:
- a doorway or route ahead;
- a wall mechanism;
- overhead architecture;
- an enemy or movement cue;
- a branch in the path;
- nearby footing.

The rig may translate vertically to remain legal, but ordinary viewing direction remains player-owned.

### Transient beams, lintels, and repeated overhead geometry
Collision safety remains immediate, but **composition-state churn is not**.

- a brief doorway lintel, beam, rafter, arch edge, or similar transient overhead obstruction must not cause the full camera composition to pump up/down repeatedly;
- Ceiling-Constrained composition should require meaningful/persistent overhead restriction rather than every one-frame overhead hit becoming a new camera state;
- repeated overhead features must use tuning-defined hysteresis/stability so the camera does not visibly accordion through rafters;
- if an overhead obstruction disappears and immediately returns, the camera remains biased toward stable continuity rather than chasing every small clearance change.

Exact persistence and hysteresis thresholds remain tuning.

### Recovery
When usable headroom returns:
- collision safety remains authoritative at all times;
- the camera waits for tuning-defined stable overhead clearance before fully committing to upward recovery;
- camera height/pivot eases toward the canonical Decision #1 composition rather than snapping upward;
- any remaining Decision #5 distance compression recovers under Decision #5's own clearance/hysteresis rules;
- if Close Quarters Camera was also active, Decision #7 recovery remains authoritative for that state;
- recovery does not restore or replay blocked pitch input.

### Distance / FOV / character-fade boundaries
- low ceiling alone does not authorize a dramatic FOV change;
- Stillring does not widen the lens merely to make a tunnel appear larger;
- low ceiling alone does not authorize Neris self-fade;
- Decision #7's Neris self-fade remains tied to pathological camera-to-character proximity / near-body intersection risk;
- if the lowered rig preserves healthy third-person distance, Neris remains normally visible;
- meaningful ceiling geometry remains visually and physically honest rather than being made transparent solely because it constrains the camera.

### Interaction with recenter
A manual Decision #4 recenter request under a low ceiling targets the nearest legal version of the canonical exploration composition.

- recenter does not force the camera through the ceiling;
- recenter does not bypass Ceiling-Constrained pitch/height limits;
- manual camera input still cancels the recenter transition immediately;
- when the ceiling later clears, the system does not replay an unreachable recenter target as a delayed snap.

### Level-design consequence
The camera system is not required to normalize indefinitely camera-hostile ceilings.

A deliberately low tunnel, cave, undercroft, or architectural passage is valid when the constrained presentation is intentional and playtested. An ordinary exploration/combat space that forces sustained ugly pitch restriction, pathological camera height, repeated overhead pumping, or severe distance compression should fail camera review unless that presentation is deliberately authored.

The Gate 1 camera test space must include at minimum:
- one long flat low tunnel;
- a single doorway lintel;
- repeated rafters/beams;
- a sloped cave roof;
- a descending/ascending ceiling;
- stairs beneath a ceiling/soffit;
- low ceiling plus rear/side wall compression;
- full yaw orbit attempts under low cover;
- repeated upward/downward pitch extremes under low cover;
- high-speed entry and exit from low-ceiling space.

### System IDE requirement
The Camera / Targeting IDE must expose enough live evidence to diagnose low-ceiling behavior, including at minimum:
- Ceiling-Constrained Camera active/inactive;
- detected overhead clearance;
- current ceiling actor/surface where available;
- canonical desired camera height/pivot;
- current legal/resolved camera height/pivot;
- vertical adjustment amount;
- player requested pitch versus resolved/legal pitch;
- pitch physically constrained yes/no and reason;
- remaining collision-limited camera distance;
- Ceiling-Constrained versus Close Quarters state ownership;
- overhead stability/hysteresis/recovery state and timer;
- current low-ceiling rejection/constraint reason.

The IDE should support one-click teleport/reset to the representative low-ceiling test cases listed above.

### Research basis / boundary
This decision is informed by:
- Unreal Engine 5.8 `USpringArmComponent`, which treats ordinary camera collision as distance retraction rather than a full game-specific composition policy;
- Cinemachine Third Person Follow, which exposes vertical arm length, camera distance, camera radius, and separate damping into/from collision as distinct rig concepts;
- Cinemachine Collider behavior separating obstruction response, return damping, and minimum occlusion time, reinforcing the value of stability/hysteresis around transient geometry;
- third-person level-design practice that treats camera clearance as part of environment design rather than expecting a generic solver to rescue every hostile space.

Primary/official references:
- https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/USpringArmComponent
- https://docs.unity.cn/Packages/com.unity.cinemachine%406.6/manual/CinemachineThirdPersonFollow.html
- https://docs.unity.cn/Packages/com.unity.cinemachine%402.10/manual/CinemachineCollider.html

Research supports separating vertical rig adjustment from distance compression and using stable recovery. It does not justify copying another engine's exact offsets, probe sizes, damping values, thresholds, or camera architecture.

### Player-facing acceptance
Low-ceiling behavior passes when:
1. entering a low passage does not unnecessarily shove the camera into Neris;
2. the camera lowers smoothly before using avoidable distance compression;
3. yaw remains player-owned;
4. the player keeps as much pitch range as the real geometry physically permits;
5. blocked pitch stops cleanly with no hidden-input snap after clearance returns;
6. the camera does not automatically aim down a tunnel or toward the floor;
7. rafters/lintels do not cause obvious camera-height accordion pumping;
8. leaving the low ceiling restores normal height smoothly after stable clearance;
9. low ceiling alone does not trigger dramatic FOV changes or Neris fading;
10. severe simultaneous distance compression correctly hands presentation responsibility to Decision #7 rather than inventing another mode;
11. persistently camera-hostile ordinary spaces are treated as level-design failures unless deliberately authored.

Philosophy:
> **When the ceiling comes down, the camera comes down with it—not into Neris.**

---

## Reconciliation note

Decision #8 has been folded into `docs/22_GATE1_CAMERA_SPECIFICATION.md`. `docs/22` is the cumulative implementation-facing camera authority; this addendum remains the owner-approved decision-specific provenance record. The two files must stay semantically consistent.

## Next owner decision

**Camera Decision #9 — vertical-space behavior.**

Research it first. Do not infer vertical shafts, tall rooms, steep drops, upper/lower route inspection, or targets far above/below from the low-ceiling contract; vertical-space readability may require its own composition and pitch-assistance rules.

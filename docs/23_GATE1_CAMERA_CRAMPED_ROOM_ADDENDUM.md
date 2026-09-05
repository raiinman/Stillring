# 23 — Gate 1 Camera Cramped-Room Addendum

**Status:** FINAL OWNER APPROVED / RECONCILED INTO `docs/22`  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #7 for Issue #2. This file preserves the decision-specific record; cumulative implementation authority now also lives in `docs/22_GATE1_CAMERA_SPECIFICATION.md`.

## Authority

Camera Decision #7 is locked. Claude may not replace this behavior with stock Unreal camera behavior, an automatic first-person switch, a fixed-camera fallback, a shoulder-aim camera, or any other unstated cramped-space policy.

Stillring's governing camera goal remains:

> **The player should look at Orra, not babysit the camera.**

The governing locomotion principle also remains intact:

> **Simple intention, capable character, honest world.**

---

## Camera Decision #7 — cramped-room behavior — LOCKED

### Core rule
Stillring remains **third-person in cramped spaces**. Severe camera compression may change composition, but it does not silently change the player's control grammar.

When physical collision makes the canonical Decision #1 distance impossible, the camera stays on the same player-owned yaw/pitch model and transitions into a dedicated close-quarters presentation rather than automatically becoming first-person, fixed-camera, shoulder-aim, or top-down.

### Close-quarters camera state
- Decision #5 collision compression remains the first response;
- when legal camera distance crosses a tuning-defined severe-compression threshold, the camera enters a **Close Quarters Camera** state;
- the state remains recognizably Stillring's ordinary third-person camera;
- the camera may make a small tuning-defined pivot/height/composition adjustment to preserve useful immediate-ground and forward-route visibility when full-body framing is physically impossible;
- exact severe-compression threshold, pivot shift, height shift, and close composition remain Gate 1 tuning;
- cramped-space composition does not introduce a dramatic FOV change merely to make the room appear larger.

### Player camera authority
- player-selected yaw and pitch remain authoritative;
- manual orbit continues wherever world geometry physically permits it;
- cramped-space handling does not automatically swing the camera around Neris searching for a prettier angle;
- no automatic shoulder swap, corridor-facing snap, fixed-camera cut, or forced 90-degree turn is part of ordinary cramped-space handling;
- cramped-space behavior does not rotate Neris, change locomotion authority, or reinterpret camera-relative movement.

### Neris near-camera self-occlusion
Neris should remain visible whenever useful, but the player should never be forced to stare through the inside of her head, torso, hair, clothing, or equipment.

- progressive **Neris self-fade/dither** is permitted only as a last-resort near-camera readability measure;
- the fade is driven by extreme camera-to-character proximity / near-body intersection risk, not merely by being indoors;
- normal close-quarters framing should preserve as much useful Neris silhouette/body readability as practical;
- at pathological proximity, camera-near parts may fade sufficiently to prevent interior-mesh clipping from dominating the view;
- this rule applies to Neris's own presentation and does not make meaningful room geometry transparent;
- exact fade start/end distances, curve, affected render pieces, and material treatment remain Gate 1/production tuning.

### Explicitly rejected automatic fallbacks
Ordinary cramped-space handling does **not**:
- switch automatically to first person;
- attach the camera to Neris's head;
- hide the entire character as the default indoor presentation;
- change character-facing rules to camera-facing controls;
- widen FOV aggressively as a substitute for physical room;
- convert to a fixed cinematic camera;
- introduce an over-the-shoulder aiming grammar.

If Stillring later gains an explicit first-person, aim, or gyro mode, that remains Camera Decision #18 authority and is not implied by this close-quarters state.

### Recovery
When space opens again:
- the camera exits close-quarters presentation through Decision #5's stable-clearance, hysteresis, and eased outward recovery;
- Neris self-fade reverses smoothly as valid viewing distance returns;
- the camera does not pop instantly between close-quarters and ordinary full-body framing.

### Level-design consequence
The camera system is not required to rescue indefinitely cramped ordinary gameplay spaces.

If a normal traversable/combat room keeps the camera in severe compression for a substantial portion of play, the room should fail camera review unless that claustrophobic presentation is deliberately authored and playtested.

Doors, narrow passages, alcoves, corners, small interiors, and transitions into/out of them must be represented in the Gate 1 camera test space.

### System IDE requirement
The Camera / Targeting IDE must expose enough live evidence to diagnose cramped-space behavior, including at minimum:
- Close Quarters Camera active/inactive;
- desired, legal, and actual camera distance;
- severe-compression threshold/state reason;
- active close-quarters composition/pivot offset;
- Neris self-fade amount and trigger reason;
- available orbit/collision constraint state;
- recovery state back toward canonical exploration framing.

### Research basis / boundary
This decision is informed by:
- engine camera systems that treat collision pull-in and severe occlusion/composition solving as separate concerns;
- third-person camera practice that preserves control continuity instead of silently converting a collision response into a different gameplay camera mode;
- common near-camera character fading techniques used to prevent the camera from rendering through the inside of the player mesh.

Research supports preserving third-person grammar, allowing a deliberate close-quarters composition, and using character self-fade only as a final proximity safety valve. It does not justify copying another game's exact threshold, fade distance, pivot shift, FOV, or material implementation.

### Player-facing acceptance
Cramped-room handling passes when:
1. entering a small space does not surprise the player with a new control scheme;
2. the camera remains third-person and player-owned even when physically compressed;
3. immediate footing/route readability is favored when full-body framing becomes impossible;
4. manual orbit remains useful wherever geometry allows it;
5. extreme proximity never leaves the player looking through the inside of Neris's mesh;
6. Neris fading is limited to genuine near-body need rather than becoming a blanket indoor effect;
7. exiting the cramped space restores normal framing smoothly;
8. persistent severe compression in an ordinary room is treated as a level-design failure rather than accepted as normal camera behavior.

---

## Reconciliation note

Decision #7 has now been folded into `docs/22_GATE1_CAMERA_SPECIFICATION.md`, and item #7 is marked **LOCKED** in the cumulative Issue #2 sequence. This addendum remains a decision-specific provenance record and must agree with `docs/22`; if wording ever diverges, reconcile the files rather than allowing parallel camera authority.

## Next owner decision

**Camera Decision #8 — low-ceiling behavior.**

Research it first. Do not infer low-ceiling policy from cramped-room behavior; ceiling constraints may require their own pitch/pivot/composition rules.

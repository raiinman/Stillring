# 36 — Gate 1 Camera Decision Register Extension

**Status:** LIVING AUTHORITY INDEX EXTENSION / TEMPORARY COMPANION TO `docs/18_PROJECT_DECISION_REGISTER.md`  
**Updated:** 2026-09-05  
**Purpose:** index the completed Gate 1 camera decision sequence without rewriting the very large root decision register through a whole-file connector replacement.

## Authority boundary
This file is an index, not a supersession layer. Detailed camera authority remains in the linked source documents. If this extension and a detailed camera authority file disagree, fix the index.

When a normal git workspace can safely patch `docs/18_PROJECT_DECISION_REGISTER.md`, fold these rows into the root register and retire this extension. Until then, read `docs/18` + this file together as the durable decision index.

---

## Gate 1 camera decisions — COMPLETE

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-CAM-01 | LOCKED | Exploration uses medium-wide, slightly elevated, full-body framing that protects footing and world/route readability. | `docs/22_GATE1_CAMERA_SPECIFICATION.md` |
| D-CAM-02 | LOCKED | Player owns 360° yaw and bounded useful pitch; manual camera input does not rotate Neris and wins over ordinary assistance. | `docs/22_GATE1_CAMERA_SPECIFICATION.md` |
| D-CAM-03 | LOCKED | Automatic yaw behavior is conditional soft follow only, suppressible by manual input and eventually disableable. | `docs/22_GATE1_CAMERA_SPECIFICATION.md` |
| D-CAM-04 | LOCKED | Manual recenter is a dedicated remappable fast eased recovery action that never changes gameplay intent. | `docs/22_GATE1_CAMERA_SPECIFICATION.md` |
| D-CAM-05 | LOCKED | Camera collision compresses inward along the chosen view and recovers with stable clearance/hysteresis; walls do not steer the camera. | `docs/22_GATE1_CAMERA_SPECIFICATION.md` |
| D-CAM-06 | LOCKED | Neris/readable movement > established target where physically honest > opaque world geometry; brief target occlusion receives grace, sustained hard occlusion breaks lock. | `docs/22_GATE1_CAMERA_SPECIFICATION.md` |
| D-CAM-07 | LOCKED | Cramped spaces remain third-person; severe compression changes composition, not control grammar. | `docs/22_GATE1_CAMERA_SPECIFICATION.md`, `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md` |
| D-CAM-08 | LOCKED | Low ceilings constrain camera height/pitch before avoidable distance compression and never queue blocked pitch or auto-aim down tunnels. | `docs/22_GATE1_CAMERA_SPECIFICATION.md`, `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md` |
| D-CAM-09 | LOCKED | Grounded vertical travel uses Vertical Context Assist: composition first, only weak bounded pitch assistance second, never privileged puzzle/quest metadata. | `docs/22_GATE1_CAMERA_SPECIFICATION.md`, `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md` |
| D-CAM-10 | LOCKED | Target acquisition commits target/gameplay relationship immediately and moves the camera deliberately from the exact current pose with one fast eased transition. | `docs/28_GATE1_CAMERA_10_11_RECONCILIATION_COMPANION.md`, `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md` |
| D-CAM-11 | LOCKED | Established lock uses a dual-subject Relationship Frame: Neris + current target + readable combat space, soft zones, modest bounded dolly, essentially stable FOV. | `docs/28_GATE1_CAMERA_10_11_RECONCILIATION_COMPANION.md`, `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md` |
| D-CAM-12 | LOCKED | Target switching is an explicit semantic directional request: one request/one switch, screen-space intent, honest visibility, no wraparound roulette, immediate target commit, short eased relationship-frame transition. | `docs/29_GATE1_CAMERA_TARGET_SWITCH_ADDENDUM.md` |
| D-CAM-13 | LOCKED | Ordinary lock frames one chosen combat relationship. Secondary enemies may appear naturally but never steer yaw/pitch/distance/FOV; encounter/threat communication owns crowd fairness. | `docs/30_GATE1_CAMERA_MULTI_ENEMY_FRAMING_ADDENDUM.md` |
| D-CAM-14 | LOCKED | Genuinely large bosses use authored Boss Framing Profiles that frame action-relevant regions, protect Neris/footing, use bounded distance, prefer stable FOV, and never use hidden solution/attack metadata. | `docs/31_GATE1_CAMERA_LARGE_BOSS_FRAMING_ADDENDUM.md` |
| D-CAM-15 | LOCKED | Airborne/traversal camera follows authoritative gameplay state rather than animation: calm ordinary jump, bounded meaningful-fall context, continuous mantle/ledge/hang behavior, severity-aware settling. | `docs/32_GATE1_CAMERA_AIRBORNE_TRAVERSAL_ADDENDUM.md` |
| D-CAM-16 | LOCKED | Gameplay shake is optional post-composition feedback with restrained default, 0–100% scale reaching true zero, no baseline ambient sway, no gameplay FOV shake, bounded rotation/stacking, independent haptics. | `docs/33_GATE1_CAMERA_SHAKE_ACCESSIBILITY_ADDENDUM.md` |
| D-CAM-17 | LOCKED | Controller and mouse share camera semantics but use native processing: radial/rate-based stick look; direct unsmoothed/unaccelerated mouse delta; independent sensitivity/inversion; remapping; explicit switch/nudge separation. | `docs/34_GATE1_CAMERA_INPUT_PARITY_ADDENDUM.md` |
| D-CAM-18 | LOCKED — DEFER | Gate 1 adds no generic precision-aim, first-person, or gyro camera mode because no current player verb requires one. Any future verb must earn a separate camera contract; gyro, if later approved, is optional/configurable. | `docs/35_GATE1_CAMERA_AIM_MODE_BOUNDARY_ADDENDUM.md` |

---

## Completion record
Camera Decisions #1–#18 are individually resolved. Issue #2 may be considered complete after repository closure bookkeeping.

### Temporary reconciliation debt
`docs/28_GATE1_CAMERA_10_11_RECONCILIATION_COMPANION.md` exists only because the current GitHub connector could not safely insert #10/#11 into the very large `docs/22` without replacing the entire file.

When a normal git workspace is available:
1. mechanically insert already-approved #10 then #11 into `docs/22`;
2. verify no semantic changes against `docs/26`, `docs/27`, and `docs/28`;
3. retire `docs/28`;
4. fold this extension into `docs/18` and retire `docs/36`.

That is documentation mechanics only. Camera policy is complete and does not require another owner decision.

---

## Cross-system obligations created by camera authority
Later systems must preserve these camera-derived constraints:
- Combat/encounter design must respect practical visual bandwidth; secondary/offscreen enemies cannot rely on camera omniscience.
- Target switching remains explicit and one-target-at-a-time.
- Camera-only boss framing anchors are not gameplay targets by default.
- Combat/tool systems may not add aim/first-person/gyro grammar without an explicit verb-specific contract.
- Camera gameplay shake can be reduced to true zero without losing critical information.
- Input design must preserve remapping, device-native processing, and semantic switch/nudge separation.
- Every camera/targeting implementation surface must be inspectable/testable through the shared System IDE contract.

# 22 — Gate 1 Camera Specification

**Status:** camera authority in owner review  
**Updated:** 2026-09-05  
**Scope:** exploration/combat camera behavior only. Locomotion semantics remain final-owner-approved in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` and must not be silently reinterpreted here.

## Authority and review protocol
This file is the implementation-facing accumulation of settled Gate 1 camera behavior. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` explains the design lineage; Issue #2 tracks the owner-review sequence.

Camera choices are resolved **one meaningful player-feel decision at a time**. Anything not explicitly locked below remains **PENDING OWNER REVIEW**. Claude may not substitute Unreal defaults, stock third-person templates, Zelda camera values, or common-industry assumptions for unresolved camera policy.

Each recommendation receives a research pass before owner presentation. Research may establish useful design patterns, but Stillring does not copy another game's exact camera values, timings, offsets, or presentation.

The camera goal is the same trust principle that governs locomotion:

> **The player should look at Orra, not babysit the camera.**

---

## 1. Default exploration distance / height philosophy — LOCKED

### Composition target
Stillring uses a **medium-wide, slightly elevated, full-body exploration framing**.

- Neris remains fully visible during ordinary exploration;
- Neris sits somewhat below screen center rather than dominating the frame;
- the world receives more screen real estate than the character;
- nearby ground/footing remains readable for ledges, stairs, mantles, doors, mechanisms, and precision movement;
- enough forward/horizon space remains visible for roads, landmarks, enemies, route reading, and environmental composition;
- this is not an over-the-shoulder shooter camera;
- this is not a distant tactical/isometric camera;
- framing serves exploration first rather than constantly seeking cinematic closeups of Neris.

### Stability
- ordinary walk → run → Sprint transitions do **not** cause dramatic automatic camera push/pull;
- baseline exploration distance should feel stable and predictable unless another explicit camera state owns composition;
- ordinary locomotion does not gain or lose movement authority because camera framing changes;
- camera collision, cramped-room compression, low ceilings, vertical spaces, target lock, bosses, and other explicit camera states may alter composition only under their own later locked rules.

### Tuning boundary
Exact numeric values remain Gate 1 tuning, including:
- camera boom/distance;
- vertical height/pivot offset;
- default pitch;
- field of view;
- Neris's exact screen-space percentage/vertical placement;
- small interpolation values required to make the locked composition feel natural.

Tuning may refine the approved medium-wide/slightly-elevated philosophy; it may not silently convert the camera into shoulder-close, tactical-distant, or continuously speed-zooming behavior.

### Player-facing acceptance
A successful baseline composition should let a fresh player simultaneously answer:
1. Where is Neris standing and what is immediately around her feet?
2. Where am I going next?
3. What important world geometry/landmark is ahead?

If ordinary exploration makes the player repeatedly rotate or zoom merely to regain basic route/footing awareness, the framing is failing even if the camera is technically functional.

---

## 2. Horizontal / vertical orbit behavior — LOCKED

### Player-owned horizontal orbit
- ordinary exploration supports continuous **360-degree horizontal orbit** around Neris;
- right-stick / mouse camera input directly changes camera yaw without rotating Neris by itself;
- Neris may continue moving in one direction while the player looks in another;
- ordinary camera orbit has no hidden front-facing cone and does not prevent the player from looking behind Neris;
- camera-relative locomotion uses the current valid horizontal camera heading according to the final locomotion authority in `docs/20`.

### Bounded vertical orbit
- ordinary exploration supports a generous but **bounded vertical pitch range**;
- the player must be able to look downward enough to read footing, ledges, drops, lower mechanisms, and spaces below;
- the player must be able to look upward enough to read towers, cliffs, hanging structures, elevated routes, architecture, and vertical threats;
- pitch limits prevent camera inversion, passing underneath Neris, crossing over the top into an upside-down view, or entering otherwise unusable near-vertical orientations;
- **no fixed upward-versus-downward asymmetry is design authority yet**: exact upper/lower pitch limits, including whether useful tuning is asymmetric, remain Gate 1 prototype tuning against Stillring's representative spaces.

### Horizon / roll
- ordinary exploration orbit maintains a level world horizon;
- player camera input controls yaw and pitch, not free camera roll;
- ordinary orbit does not introduce decorative Dutch-angle lean or camera banking.

### Manual-input authority
- while the player is deliberately moving the camera, that manual camera intent has priority over ordinary camera assistance;
- camera assistance must not visibly fight, counter-steer, or immediately undo active right-stick/mouse input;
- releasing camera input does **not by itself** command a snap or recenter;
- moving Neris does not by itself cancel the manually chosen camera angle except where a later explicit approved assistance/state rule says otherwise.

### Framing continuity
- ordinary orbit preserves the Decision #1 medium-wide/slightly-elevated exploration framing rather than secretly changing zoom based on yaw/pitch input;
- collision, cramped rooms, low ceilings, vertical-space handling, target lock, bosses, or other explicit camera states may alter the usable orbit/composition only under their own later locked rules.

### Research basis / boundary
This decision is informed by:
- Nintendo's discussion of adding free camera control to the Zelda lineage and its value for letting the player inspect important world elements while continuing to move;
- established third-person camera design practice describing free yaw/pitch orbit around a tracked character with vertical-angle limits.

Research supports player-owned orbit plus bounded pitch. It does **not** justify copying another game's exact angular range, acceleration, sensitivity, or pitch asymmetry; those remain Stillring tuning decisions.

### Player-facing acceptance
The baseline orbit passes when:
1. the player can look freely around Neris without the character being rotated against locomotion intent;
2. looking behind while moving forward remains natural;
3. vertical inspection is useful without permitting inverted/useless camera states;
4. manual camera input feels authoritative rather than contested by assistance;
5. ordinary orbit does not destabilize the already-approved baseline distance/framing.

---

## 3. Automatic yaw recentering while moving — LOCKED

### Core rule
Stillring uses **conditional soft yaw follow**, not constant recentering and never an automatic hard snap.

The camera may quietly help follow sustained travel when the current view has become poor at showing the player's direction of movement, but it may not decide what the player wants to look at.

### Manual authority
- while the player is actively moving the camera with right stick or mouse, automatic yaw follow is fully suppressed;
- any new manual camera input immediately cancels an active automatic follow correction;
- releasing manual camera input does not itself command a recenter;
- the manually chosen view is preserved for a grace period before any follow assistance may begin;
- exact grace-period timing remains Gate 1 tuning.

### When soft follow may occur
Automatic yaw follow may begin only when all relevant conditions support it, including:
- Neris is in sustained ordinary movement rather than standing still;
- the player is not actively manipulating the camera;
- the travel direction has meaningfully diverged from the current view for long enough that route visibility is degraded;
- no higher-priority explicit camera state owns composition.

Small course corrections should produce little or no camera response. Stronger and more sustained travel-direction changes may justify stronger assistance.

### When soft follow does not occur
- standing still does not trigger automatic yaw recentering;
- looking sideways or backward while intentionally moving forward is not automatically treated as an error;
- careful movement near ledges, mechanisms, interactions, or precision traversal should use extremely weak or no automatic yaw follow;
- automatic yaw follow does not alter camera pitch, exploration distance, Neris's movement direction, or locomotion authority;
- camera assistance never teleports, snaps, or instantaneously places the view directly behind Neris.

### Movement-context scaling
- open sustained travel and Sprint may tolerate somewhat stronger follow assistance than careful movement;
- lower-speed precision movement should preserve the chosen view more aggressively;
- exact activation angle, delay, yaw speed, damping, and movement-speed scaling remain Gate 1 prototype tuning.

### Accessibility / preference boundary
The final camera settings must provide a way to reduce or completely disable ordinary automatic yaw follow. An **Off/Never** behavior is a legitimate player preference, not a debug-only exception.

Exact settings presentation and sensitivity/accessibility grouping remain part of later Decision #17 authority.

### Research basis / boundary
This decision is informed by:
- the Zelda lineage's history of explicit/manual camera centering and later free-camera ownership;
- modern third-person games that separate camera follow strength, auto-adjust delay, and recenter assistance rather than treating one omnipresent autocamera as mandatory;
- camera-design practice that preserves a manually chosen view before smoothly transitioning back toward ordinary follow behavior.

Research supports a conditional assistance layer with player override. It does not justify copying another game's exact delay, angle threshold, follow speed, or damping.

### Player-facing acceptance
The behavior passes when:
1. manual camera input always wins immediately;
2. intentional sideways/backward viewing while moving remains possible;
3. sustained travel can receive quiet help without the player feeling the camera being stolen;
4. careful ledge/interaction movement does not trigger unwanted view rotation;
5. no ordinary automatic yaw correction ever snaps;
6. an eventual Off/Never setting can remove ordinary yaw-follow assistance without breaking camera-relative locomotion.

---

## Remaining Issue #2 owner-review sequence

1. ~~default exploration distance/height philosophy~~ — **LOCKED**
2. ~~horizontal/vertical orbit behavior~~ — **LOCKED**
3. ~~automatic yaw recentering while moving~~ — **LOCKED**
4. manual recenter action behavior — **PENDING OWNER REVIEW**
5. camera collision compression/recovery — **PENDING OWNER REVIEW**
6. occlusion priority when player/target cannot both remain visible — **PENDING OWNER REVIEW**
7. cramped-room behavior — **PENDING OWNER REVIEW**
8. low-ceiling behavior — **PENDING OWNER REVIEW**
9. vertical-space behavior — **PENDING OWNER REVIEW**
10. lock-on acquisition transition — **PENDING OWNER REVIEW**
11. lock-on framing distance/offset philosophy — **PENDING OWNER REVIEW**
12. target-switch transition behavior — **PENDING OWNER REVIEW**
13. multiple-enemy framing limits — **PENDING OWNER REVIEW**
14. large-boss framing — **PENDING OWNER REVIEW**
15. camera behavior during jump/fall/mantle — **PENDING OWNER REVIEW**
16. camera shake default/accessibility range — **PENDING OWNER REVIEW**
17. sensitivity curves/inversion/mouse parity — **PENDING OWNER REVIEW**
18. aim/first-person/gyro behavior if later proposed — **PENDING OWNER REVIEW**

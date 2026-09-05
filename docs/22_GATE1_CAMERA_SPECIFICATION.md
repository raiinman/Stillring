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

## 4. Manual recenter action behavior — LOCKED

### Core purpose
Manual recenter is an explicit **camera recovery command**: when the player asks for it, Stillring rapidly restores a sane canonical exploration composition without changing gameplay intent.

Automatic yaw follow remains quiet assistance; manual recenter is the deliberate player command that says to restore the normal view now.

### Input and target composition
- manual recenter is a dedicated **remappable action**;
- one press requests the canonical Decision #1 exploration framing;
- recenter restores both **yaw and pitch**, not yaw alone;
- while Neris is moving, the recenter target is aligned behind her **stable direction of travel**;
- while Neris is stationary, the recenter target is aligned behind **Neris's facing direction**;
- the action does not create a special zoom/FOV state and returns toward the normal medium-wide, slightly elevated exploration composition.

### Transition behavior
- recenter uses a **fast eased transition** rather than an instantaneous visual snap;
- it must also avoid a slow cinematic pan that delays practical camera recovery;
- exact transition duration, interpolation curve, and minor composition settling remain Gate 1 tuning;
- repeated recenter presses do not stack camera animations; they retarget/restart the current recovery request from the current valid camera state.

### Manual camera override
- any deliberate right-stick/mouse camera input during the recenter transition immediately cancels the automatic transition and returns full camera authority to the player;
- the recenter command may not counter-steer against active camera input.

### Gameplay-authority boundary
Manual recenter:
- does **not** rotate Neris;
- does **not** alter movement input or velocity;
- does **not** choose or acquire an enemy;
- does **not** point toward a quest objective or landmark;
- does **not** trigger target lock;
- is **not** a 180-degree quick-turn command;
- does not override a higher-priority explicit camera state whose later-approved rules own composition.

Camera collision may prevent the mathematically ideal recenter position. How the camera compresses, recovers, and handles obstruction is Decision #5 authority rather than being silently invented here.

### Research basis / boundary
This decision is informed by:
- Ocarina of Time / Majora's Mask using an explicit center-behind camera command to recover a useful third-person view;
- modern games preserving a distinct bindable recenter action rather than relying entirely on passive auto-follow;
- modern camera practice favoring quick eased recovery over visually jarring hard snaps where the player's intent does not require an instantaneous cut.

Research supports a decisive explicit recovery action, but does not justify copying Zelda's exact snap timing, button mapping, or camera numbers.

### Player-facing acceptance
Manual recenter passes when:
1. one press reliably restores a useful exploration composition;
2. moving recenter follows stable travel direction while stationary recenter follows facing;
3. the recovery feels quick without feeling like a visual cut/slap;
4. moving the camera manually cancels the transition immediately;
5. recenter never changes Neris's movement, facing, target selection, or gameplay state;
6. obstruction does not cause the action to violate later camera-collision authority.

---

## 5. Camera collision compression / recovery — LOCKED

### Core rule
Physical camera collision resolves by **compressing the camera inward along the player's currently chosen viewing direction**. Walls may shorten the camera arm; they do not steer the camera.

Collision safety and view ownership are separate concerns: the solver may reduce legal camera distance, but ordinary collision does not automatically orbit, yaw, or pitch the camera around an obstacle.

### Compression behavior
- physical collision is resolved promptly enough that the camera never passes through or visibly enters blocking world geometry;
- the camera has a non-zero collision/probe volume rather than behaving like an infinitely small point;
- the solver finds the nearest legal camera distance along the current valid viewing direction;
- inward collision response takes priority over distance smoothing when required for safety;
- exact probe radius, inward response speed, clearance offsets, and trace/frustum implementation remain Gate 1 engineering/tuning choices so long as the semantic result matches this contract.

### Manual orbit while compressed
- right-stick/mouse orbit remains authoritative while collision-compressed;
- when the player changes yaw or pitch, the collision solver recomputes the nearest legal distance along that newly requested view;
- collision may shorten distance but does not counter-steer camera input;
- ordinary collision solving does not silently select a sideways orbit around an obstacle.

Whether deliberate occlusion handling may ever choose a lateral viewpoint is separate Decision #6 authority.

### Recovery behavior
When the obstructing geometry clears:
- the camera does not instantly fire back to full Decision #1 distance;
- clearance should remain credibly stable for a short tuning-defined window before outward recovery fully commits;
- the camera then eases outward toward its canonical exploration distance;
- outward recovery is deliberately smoother/slower than emergency inward compression;
- if an obstruction reappears during recovery, inward safety immediately takes priority again;
- hysteresis must prevent tiny collision-distance changes from causing visible rapid IN/OUT breathing around rails, posts, corners, foliage collision, or decorative geometry.

Exact recovery delay, outward speed, damping, and hysteresis thresholds remain Gate 1 tuning.

### Geometry-authoring boundary
A generic solver is not required to make arbitrarily noisy art collision behave well.

- camera-specific simplified blocker geometry may be authored where decorative/compound collision would otherwise cause vibration, snagging, or repeated compression churn;
- those blockers exist only to represent the intended camera boundary cleanly; they do not become secret gameplay collision or world-state authority;
- level review must include camera traversal through representative doors, railings, corners, stairs, clutter, and narrow transitions rather than assuming a default Unreal Spring Arm is sufficient.

### Cramped-space boundary
Decision #5 does **not** decide the final presentation when legal camera distance becomes extremely short. Character fading, special close framing, near-first-person behavior, or other severe-compression responses remain Decision #7 authority.

### System IDE requirement
The Camera / Targeting IDE must expose enough live evidence to tune and diagnose collision behavior, including at minimum:
- desired camera distance;
- actual camera distance;
- collision-limited distance;
- collision active/inactive state;
- current blocking surface/actor where available;
- probe/clearance parameters;
- recovery state and clearance timer.

### Research basis / boundary
This decision is informed by:
- Unreal's standard Spring Arm collision model, which retracts camera distance when obstructed and extends when clear;
- Cinemachine-style separation of obstruction-entry damping, return damping, minimum obstruction time, and smoothing to reduce camera jumpiness;
- shipped-game camera postmortems warning that automatic collision can pop or snag on complex geometry and may need authored camera constraints/blockers.

Research supports fast collision safety plus controlled recovery. It does not justify copying another engine's exact probe size, damping values, or collision algorithm.

### Player-facing acceptance
Camera collision passes when:
1. the camera never visibly enters solid geometry;
2. walls shorten distance without stealing yaw/pitch ownership;
3. manual orbit remains useful while compressed;
4. leaving a wall does not produce a distracting snap-out;
5. repeated thin obstacles do not make the camera visibly breathe or vibrate;
6. pathological art collision can be repaired with clean camera-only blockers without changing gameplay geometry semantics;
7. severe cramped-space presentation remains explicitly unresolved until Decision #7.

---

## Remaining Issue #2 owner-review sequence

1. ~~default exploration distance/height philosophy~~ — **LOCKED**
2. ~~horizontal/vertical orbit behavior~~ — **LOCKED**
3. ~~automatic yaw recentering while moving~~ — **LOCKED**
4. ~~manual recenter action behavior~~ — **LOCKED**
5. ~~camera collision compression/recovery~~ — **LOCKED**
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

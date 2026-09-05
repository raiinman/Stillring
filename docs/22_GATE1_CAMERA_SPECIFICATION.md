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
Decision #5 does **not** decide the final presentation when legal camera distance becomes extremely short. Character fading, special close framing, near-first-person behavior, or other severe-compression responses are Decision #7 authority.

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
7. severe cramped-space presentation follows Decision #7 authority rather than being invented by the collision solver.

---

## 6. Occlusion priority when player and target cannot both remain visible — LOCKED

### Core readability hierarchy
Stillring uses a strict readability hierarchy:
1. **Neris and her immediate movement/footing remain the highest visual priority.**
2. A currently locked target is the next priority when the world physically permits both to remain readable.
3. Meaningful opaque world geometry remains honest; target readability does not grant supernatural visibility through solid cover.

When ideal composition is impossible, the camera sacrifices perfect target centering before sacrificing Neris's basic readability or violating world geometry.

### Target-lock readability
- target lock should normally keep the Neris ↔ target relationship legible rather than requiring the target to remain dead-center;
- the camera may use available framing room within later-approved lock-on composition rules, but ordinary target occlusion does not authorize a violent automated orbit around architecture;
- Decision #5 camera collision continues to solve where the camera may physically exist, independently from whether the target has line of sight;
- target occlusion never rotates or repositions Neris to preserve framing.

### Honest hard occluders
Meaningful opaque structures remain visually authoritative, including walls, closed doors, substantial pillars, cliff faces, and comparable cover.

- these objects do not automatically fade merely because they block a target;
- Stillring does not display a target's exact body, pose, animation, or movement through hard world cover;
- the camera does not swing around a hard occluder solely to manufacture impossible line of sight;
- a target indicator may communicate that an already-established lock is temporarily **occluded**, but it may not become an x-ray representation of the target's exact hidden state.

### Fade-eligible foreground clutter
Small/decorative foreground objects may be explicitly authored as **camera-fade eligible** when their visual role is not meaningful cover and they repeatedly block critical readability.

Examples may include selected foliage, cloth, thin decorative pieces, or other authored foreground clutter.

- fade eligibility is explicit data/authoring, not a blanket material rule;
- hard structural world geometry is not implicitly fade eligible;
- exact fade amount, transition timing, material treatment, and eligible content classes remain Gate 1/production tuning and art implementation subject to this semantic boundary.

### Temporary target occlusion grace
Brief hard occlusion does not immediately destroy an existing lock.

- an established lock enters a short **occluded grace state** when line of sight is temporarily lost;
- a brief post, corner, doorway edge, animation crossover, or similar momentary interruption should not cause rapid lock/unlock flicker;
- exact grace duration and reacquisition tolerances remain Gate 1 tuning;
- while grace is active, the camera preserves ordinary readable composition without chasing the hidden target around geometry.

### Sustained hard occlusion
If hard occlusion persists beyond the valid grace/lock conditions:
- target lock breaks cleanly;
- the camera does not contort itself around architecture to keep the target artificially visible;
- target-relative locomotion exits according to the already-locked locomotion transition authority rather than being silently maintained against an invalid hidden target;
- subsequent target acquisition must satisfy later-approved target-lock acquisition rules.

### Encounter-design consequence
Camera logic is not allowed to compensate for unreadable combat staging with wall vision. Enemy aggression, attack timing, and arena composition must respect what the player can reasonably see and interpret under this camera contract.

### System IDE requirement
The Camera / Targeting IDE must expose enough live evidence to diagnose occlusion behavior, including at minimum:
- Neris visibility/readability state where measurable;
- current target line-of-sight state;
- occlusion duration;
- current occluder identity/classification;
- camera-fade eligibility/result;
- lock state including visible / occluded-grace / broken;
- reason an occluded lock was retained or broken.

### Research basis / boundary
This decision is informed by:
- Zelda's target-lock lineage, where lock-on exists to preserve a readable player ↔ opponent relationship;
- modern target-lock/accessibility systems that distinguish visible targets and allow temporary loss of perfect composition without requiring supernatural visibility;
- camera design guidance warning against excessive camera movement merely to maintain line of sight;
- modern camera systems that treat camera pull-in, obstacle rotation, and transparency/fading as distinct tools rather than one mandatory response.

Research supports prioritizing player readability, preserving target relationship where physically honest, and separating temporary occlusion from sustained invalid lock. It does not justify copying another game's exact grace time, fade implementation, lock-break distance, or target-indicator presentation.

### Player-facing acceptance
Occlusion handling passes when:
1. Neris and her immediate movement remain readable before perfect target centering is preserved;
2. brief occlusion does not cause distracting lock flicker;
3. meaningful walls/cover do not become x-ray windows;
4. decorative fade-eligible clutter can stop obscuring critical readability without globally dissolving the world;
5. sustained impossible line of sight breaks lock rather than forcing a violent camera orbit;
6. target occlusion never repositions Neris or invents gameplay authority;
7. combat staging remains responsible for attacks the player is expected to read.

---

## 7. Cramped-room behavior — LOCKED

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

Philosophy:
> **When the room gets smaller, the camera gets closer—not stranger.**

---

## 8. Low-ceiling behavior — LOCKED

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

A low roof does not tell the system what the player wants to inspect. The rig may translate vertically to remain legal, but ordinary viewing direction remains player-owned.

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

## 9. Vertical-space behavior — LOCKED

### Core rule
Stillring uses **Vertical Context Assist** for grounded exploration: sustained meaningful elevation change may alter screen-space composition and may apply a very weak, bounded pitch assist only when vertical route readability would otherwise degrade.

The camera makes room for the vertical space without choosing what the player should look at.

Vertical Context Assist is not a special cinematic camera mode and is not triggered merely because a room is tall.

### Screen-space composition first
The first response to meaningful vertical travel is a small screen-space framing bias rather than automatic camera rotation.

- sustained ascent may place Neris somewhat lower in frame to reveal more route/geometry above and ahead;
- sustained descent may place Neris somewhat higher in frame to reveal more route/geometry below and ahead;
- exact screen-space offset, dead-zone/soft-zone size, transition rate, and persistence remain Gate 1 tuning;
- shallow slopes, ordinary stairs, and small terrain undulations should remain inside a generous vertical dead zone and should not cause continuous visible camera bobbing;
- composition bias does not rotate Neris or alter locomotion authority.

### Sustained vertical-travel classification
Vertical Context Assist may classify grounded exploration into tuning-defined states such as flat/ordinary terrain, sustained ascent, sustained descent, drop approach, and recovery toward canonical framing.

Classification must use recent/sustained player movement and nearby immediately relevant traversable/supporting geometry rather than one-frame height noise. Hysteresis/stability prevents repeated state changes on stair treads, rubble, small ramps, or sawtooth terrain.

### Drop approach
Approaching a meaningful drop may justify modest additional below-footing context, but proximity alone is insufficient.

- the player must actually be moving toward the drop/edge;
- moving parallel to a cliff does not cause a downward bias merely because the cliff is nearby;
- a pit or cliff behind Neris does not pull the camera downward;
- standing near an edge without approach intent does not trigger an automatic look-down;
- exact edge-distance, approach-vector, persistence, and severity thresholds remain tuning.

The purpose is immediate footing/drop readability, not dramatic presentation of danger.

### Tall rooms, shafts, and atriums
A tall space does not itself grant the camera permission to tour the environment.

- standing in a shaft, atrium, tower interior, or tall chamber leaves ordinary camera ownership with the player;
- the camera does not automatically look up because important geometry exists above;
- it does not automatically look down because depth exists below;
- manual pitch remains the primary inspection tool when vertical travel intent is not established;
- Vertical Context Assist matters when the player's actual grounded route meaningfully gains or loses elevation.

### Weak conditional soft-pitch assist
Stillring permits a **very weak, bounded automatic pitch assist** only after screen-space composition alone is insufficient to preserve useful route readability during sustained vertical travel.

The assist may begin only when all relevant conditions are true:
- Neris is in sustained grounded movement with meaningful elevation change;
- route-relevant geometry in the current travel corridor is drifting outside the approved vertical readability envelope;
- the player is not actively manipulating the camera;
- a tuning-defined grace period after the last manual camera input has expired;
- no higher-priority camera state owns presentation.

The assist is slow, small, capped, never snaps, immediately yields to manual input, does not change yaw, does not alter Neris movement/facing, and does not change FOV merely because the route is steep. Exact thresholds/timing remain tuning.

### Manual camera authority
Manual camera input always wins.

- while the player manipulates the camera, automatic vertical pitch assist is fully suppressed;
- new deliberate input immediately cancels any active pitch correction;
- releasing manual input preserves the chosen pitch for a grace period rather than immediately steering toward route direction;
- the player may deliberately look downhill while moving uphill, uphill while descending, or inspect a side wall while on stairs;
- the camera must accept that choice rather than treating it as an error;
- non-rotational screen-space composition bias may remain active where useful.

### Accessibility / preference boundary
Final camera settings must permit reducing or fully disabling ordinary automatic vertical pitch assistance, including an **Off/Never** behavior. Disabling pitch assist does not disable manual pitch, vertical screen-space composition bias, collision safety, or separately approved behavior. Exact settings presentation belongs to Decision #17.

### The camera must not know the puzzle solution
Vertical Context Assist may use only player-facing physical context required to understand current movement, such as sustained Neris movement direction, recent elevation trend, nearby immediately relevant traversable/supporting geometry, current footing/drop relationship, and physically visible route geometry in the local travel corridor.

It may **not** use privileged solution/gameplay metadata to decide where to aim or bias the camera, including quest objectives, hidden interaction targets, puzzle-solution metadata, designer-authored solution look points, undiscovered routes/secret entrances, treasure locations, hidden enemies, or the preferred/correct branch through a multi-route puzzle.

If several possible vertical routes exist, the camera does not reveal the intended answer. The player explores and interprets the space.

### Recenter interaction
Decision #4 manual recenter remains an explicit player recovery command. During valid vertical context, recenter may use the nearest contextually useful exploration framing already allowed by #9 instead of blindly restoring flat-ground pitch that hides the route. It may not bypass Decisions #5/#7/#8, manual input still cancels it, and it never uses puzzle/quest metadata to choose a vertical direction.

### Interaction with low ceilings / cramped spaces
Decision #9 requests readability; Decisions #5, #7, and #8 determine where the camera may physically exist. A steep descent under a low roof can request more below-route context while #8 limits legal height/pitch; rear-wall obstruction invokes #5; severe compression invokes #7. #9 never authorizes clipping, teleportation, or a new emergency camera mode.

### Jump / fall / mantle boundary
Decision #9 owns **grounded exploration verticality only**. Once Neris enters jump, fall, mantle, or another airborne/transition presentation, Decision #15 owns the material camera behavior. #9 therefore does not decide airborne vertical follow, landing framing, mantle offsets, airborne pitch assistance, or vertical launch/fall lag.

### Lock-on / combat boundary
Decision #9 does not use enemy position to drive ordinary vertical pitch assistance. A target above/below does not become #9 authority merely because it is vertically separated. Lock-on acquisition/transition and combat framing remain Decisions #10–#14; physical legality from #5/#7/#8 still applies later.

### Explicitly rejected behavior
Ordinary vertical-space handling does **not** automatically yaw toward stairs/shafts/cliffs, constantly pitch with every slope change, look toward the highest/lowest point in a room, widen FOV because a shaft is tall, zoom out merely to show full architecture height, add decorative roll, use objective/puzzle/secret/treasure/hidden-route data to direct view, or become cinematic merely because the environment is dramatic.

### System IDE requirement
The Camera / Targeting IDE must expose at minimum:
- Vertical Context Assist active/inactive;
- current vertical-travel classification and reason;
- measured recent elevation trend / travel-vector evidence;
- persistence/hysteresis state and timers;
- canonical Neris screen-space Y versus resolved screen-space Y;
- active vertical composition bias;
- dead / soft / hard vertical framing zones drawn on screen;
- player-requested pitch;
- automatic pitch-assist contribution;
- final resolved pitch;
- manual-input suppression / grace state;
- pitch-assist activation/rejection reason;
- drop-approach state and supporting approach evidence;
- current higher-priority constraint/state limiting requested composition;
- whether automatic vertical pitch assistance is enabled/reduced/off.

The IDE must make clear **why** a vertical adjustment occurred rather than requiring tuning by superstition.

### Representative test cases
The Gate 1 camera workbench/test space must include at minimum:
- long gentle and steep uphill routes;
- long gentle and steep downhill routes;
- switchback stairs;
- repeated shallow steps / sawtooth terrain;
- tall shaft entered but not climbed;
- tall atrium crossed horizontally;
- cliff approached head-on;
- cliff traversed parallel to the edge;
- drop behind Neris while moving away;
- standing still at a cliff;
- steep descent beneath a low ceiling;
- ascent with rear-wall compression;
- multi-route vertical puzzle chamber;
- moving uphill while deliberately looking downhill;
- moving downhill while deliberately looking uphill;
- manually inspecting a side wall while vertical travel continues.

### Research basis / boundary
This decision is informed by Nintendo's discussion of verticality as an exploration/readability problem, modern camera systems that separate screen-space framing/dead zones from physical camera rotation, third-person camera practice using free-move/dead zones and delayed following to avoid excessive camera reaction, and Stillring's locked rule that deliberate manual camera input outranks assistance.

Research supports screen-space composition first, bounded conditional pitch assistance second, and player ownership throughout. It does not justify copying another game's exact screen offset, dead-zone dimensions, pitch timing, acceleration, or environmental metadata model.

### Player-facing acceptance
Vertical-space behavior passes when:
1. steep routes gain useful context without constant right-stick babysitting;
2. ordinary stairs/shallow slopes do not visibly bob the camera;
3. approaching a meaningful drop improves footing/drop readability without every nearby cliff becoming an automatic look-down;
4. parallel/away movement near a drop does not trigger inappropriate downward framing;
5. tall rooms do not steal the camera merely because architecture exists above/below;
6. manual camera input always overrides pitch assistance immediately;
7. deliberate looking opposite the route remains stable and respected;
8. pitch assistance is weak, capped, delayed, and independently disableable;
9. vertical assistance never reveals puzzle solutions, hidden routes, objectives, treasure, or unseen enemies;
10. recenter respects current valid vertical context without inventing authority;
11. low ceilings/collision/cramped spaces obey Decisions #5/#7/#8;
12. jump/fall/mantle and lock-on presentation remain reserved for later decisions.

Philosophy:
> **Make room for the height. Never aim on the player's behalf.**

---

## Remaining Issue #2 owner-review sequence

1. ~~default exploration distance/height philosophy~~ — **LOCKED**
2. ~~horizontal/vertical orbit behavior~~ — **LOCKED**
3. ~~automatic yaw recentering while moving~~ — **LOCKED**
4. ~~manual recenter action behavior~~ — **LOCKED**
5. ~~camera collision compression/recovery~~ — **LOCKED**
6. ~~occlusion priority when player/target cannot both remain visible~~ — **LOCKED**
7. ~~cramped-room behavior~~ — **LOCKED**
8. ~~low-ceiling behavior~~ — **LOCKED**
9. ~~vertical-space behavior~~ — **LOCKED**
10. lock-on acquisition transition — **PENDING OWNER REVIEW**
11. lock-on framing distance/offset philosophy — **PENDING OWNER REVIEW**
12. target-switch transition behavior — **PENDING OWNER REVIEW**
13. multiple-enemy framing limits — **PENDING OWNER REVIEW**
14. large-boss framing — **PENDING OWNER REVIEW**
15. camera behavior during jump/fall/mantle — **PENDING OWNER REVIEW**
16. camera shake default/accessibility range — **PENDING OWNER REVIEW**
17. sensitivity curves/inversion/mouse parity — **PENDING OWNER REVIEW**
18. aim/first-person/gyro behavior if later proposed — **PENDING OWNER REVIEW**

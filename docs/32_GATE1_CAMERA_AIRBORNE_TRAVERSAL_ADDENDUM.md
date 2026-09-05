# 32 — Gate 1 Camera Airborne / Traversal Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #15 for Issue #2. This file extends cumulative camera authority through Decisions #1–#15.

## Authority
Camera Decision #15 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Decision #15 owns camera behavior during ordinary jump, fall, mantle/scramble, ledge catch/hang/pull-up/release, and the transition back to grounded camera authority. It does not change locomotion semantics in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`.

Camera goal:
> **The player should look at Orra, not babysit the camera.**

Movement principle:
> **Simple intention, capable character, honest world.**

---

## Camera Decision #15 — jump / fall / mantle behavior — LOCKED

### Core philosophy
Airborne/traversal camera preserves **continuity, landing readability, and player ownership**.

> **Follow the state, not the animation.**

Ordinary vertical movement does not earn cinematic camera behavior merely because Neris left the ground. The camera changes only as much as the actual gameplay state and readable route require.

### Gameplay state owns camera classification
Camera classification is driven by authoritative locomotion/traversal state and physical movement evidence, not by animation pose alone.

At minimum the camera can distinguish:
- grounded ordinary movement;
- ordinary jump / short airborne arc;
- meaningful fall;
- mantle/scramble traversal;
- ledge catch transition;
- established hang;
- pull-up;
- deliberate ledge/ladder release into fall;
- landing/recovery;
- target-locked versions of applicable states.

Animation, root motion, Motion Warping, sockets, and montage phases may provide presentation timing/diagnostics, but they may not silently redefine the gameplay state or camera contract.

### Ordinary jump — preserve the current camera grammar
A normal jump does **not** create a special spectacle camera.

- exploration jump remains on the current exploration camera grammar;
- locked jump remains on the current valid lock-on Relationship Frame unless lock itself becomes invalid under existing rules;
- no jump-specific zoom-out;
- no jump-specific FOV kick;
- no automatic yaw recenter;
- no automatic dramatic pitch-up at takeoff;
- no apex camera bob;
- no landing slam built into ordinary jump framing;
- manual yaw/pitch input remains authoritative subject to physical camera constraints.

The camera should feel like the same camera following a character who jumped, not like a new camera state announcing the jump.

### Vertical follow dead zone for small airborne motion
Short ordinary jump arcs should not make the whole world bounce vertically.

- Neris may move within a tuning-defined vertical screen-space dead/soft region before the camera translates vertically;
- small takeoff/apex/landing movement inside the region causes little or no vertical camera translation;
- meaningful displacement beyond the comfortable region produces smooth follow;
- exact dead-zone size, damping, and follow rate remain Gate 1 tuning;
- manual pitch input remains separate from automatic vertical position following.

This follows the same anti-jitter principle as Decisions #9/#11 without reusing grounded Vertical Context Assist as airborne policy.

### Meaningful fall — increase landing/trajectory context, not drama
A sustained fall may need more vertical route context than an ordinary jump.

When fall evidence becomes meaningfully different from a short jump:
- the vertical framing envelope may expand so Neris can travel farther within frame before the camera fully follows;
- the camera may bias Neris somewhat higher in frame to reveal more physically visible space below and along the current trajectory;
- camera vertical translation may follow the sustained fall smoothly after tuning-defined persistence/severity evidence;
- the purpose is to preserve landing/trajectory readability, not to make the fall cinematic;
- the camera does **not** automatically pitch downward simply because `MOVE_Falling` is active;
- a downward composition/pitch contribution requires actual visible/supporting physical evidence that it improves immediate fall/landing readability;
- exact persistence, severity bands, screen-space offsets, and follow damping remain tuning.

A brief walk-off/coyote moment does not instantly become a dramatic fall camera.

### No hidden landing prediction
The camera may use physically observable/local movement evidence such as:
- Neris velocity and trajectory;
- current movement/fall state;
- current visible nearby collision/support geometry;
- directly traceable ground/landing surfaces in the local trajectory corridor;
- actual ledge/traversal state.

It may not use:
- hidden scripted landing destination;
- quest/puzzle solution metadata;
- invisible preferred landing marker;
- future AI/gameplay event information;
- designer-authored secret-route hints;
- an animation warp target as proof of where the player will land unless gameplay traversal authority has already committed that destination.

The camera can read the honest world; it cannot know the answer before the player does.

### Manual camera input remains authoritative
During jump/fall:
- deliberate yaw/pitch input immediately takes priority over ordinary automatic pitch assistance;
- the player may look sideways, behind, upward, or toward nearby geometry while falling;
- automatic vertical *position* following may continue as required to keep Neris readable, but it must not counter-steer the player's chosen viewing direction;
- releasing manual input does not trigger a snap toward a presumed landing;
- any later weak automatic pitch contribution requires a grace period and current physical justification.

### Mantle / scramble — preserve camera continuity through character displacement
Mantle is an authoritative traversal state from `docs/20`, not a camera cut.

During mantle/scramble:
- the camera follows the authoritative Neris traversal/capsule/root transform smoothly;
- it does not attach directly to an animated hand, head, pelvis, root bone, or Motion Warping target;
- it does not snap to the top surface merely because the animation is warping there;
- player yaw/pitch authority is preserved as far as the traversal state and physical geometry allow;
- camera collision/ceiling/cramped-space authorities continue to apply throughout the displacement;
- a small tuning-defined pivot/vertical composition adjustment is allowed if necessary to preserve Neris + obstacle/top-surface readability during the committed mantle;
- no automatic FOV change is part of mantle;
- exit blends naturally into the valid grounded camera from the camera's exact current pose.

The camera tracks gameplay movement; animation presents that movement.

### Ledge catch — absorb the discontinuity without a cut
A valid ledge catch always enters a real hang state under locomotion authority.

On catch:
- the camera does not cut or snap;
- vertical follow absorbs the abrupt change from falling trajectory to arrested hang through a short bounded eased settle;
- Neris + the ledge/nearby wall + immediate below/side context remain readable;
- the camera does not automatically orbit to a side-on platformer angle;
- player camera input remains available where physical geometry allows it;
- collision and low-ceiling constraints remain authoritative.

Exact settle timing/offset remains tuning.

### Established hang — readable, player-owned third person
While hanging:
- the camera stays third-person and player-owned;
- Neris and the current handhold/ledge relationship remain readable;
- enough nearby below/side context should remain available for shimmy/drop decisions;
- no automatic side view, top-down view, or forced look-at-handhold camera;
- neutral hang does not cause camera drift or slow auto-recenter;
- left/right shimmy does not make the camera chase every hand movement or animation bone;
- ordinary manual orbit remains bounded only by real geometry/approved physical constraints.

A tuning-defined hang composition bias is allowed, but it may not change the control grammar.

### Pull-up — continuity with mantle principles
Pull-up from hang is treated as committed traversal displacement.

- preserve camera continuity from the current hang pose;
- follow authoritative character displacement rather than animation bones;
- no cut/snap to the top;
- no hidden preview of the top surface beyond physically readable local geometry;
- smoothly return to grounded framing once the traversal state ends;
- physical camera constraints remain authoritative during the entire transition.

### Deliberate release / drop
When the player deliberately releases a ledge/ladder:
- camera remains continuous from the exact current pose;
- release itself does not trigger a dramatic pitch-down, zoom, or FOV event;
- once the resulting fall becomes meaningful, the ordinary meaningful-fall rules above may engage;
- camera behavior grants no fall immunity, extra air control, recatch authority, or other locomotion benefit;
- a different valid ledge catch later transitions through the normal catch camera rule.

### Landing — severity may alter settling, not camera authority
Landing consequences already have locomotion severity bands. Camera presentation may reflect those bands modestly but must not invent gameplay consequences.

#### Routine safe landing
- return to the valid grounded camera continuously;
- no landing camera slam;
- no FOV pulse;
- no forced pitch;
- no unnecessary vertical overshoot/bounce.

#### Firm but non-damaging landing
- a small, short, critically damped vertical settle may communicate weight if playtesting supports it;
- camera remains readable and controllable;
- exact magnitude/duration remain tuning and must be compatible with Decision #16 motion reduction.

#### Damaging / severe landing
- camera may use a somewhat stronger but still bounded settle consistent with the already-authoritative gameplay recovery;
- the camera does not add extra control lock, damage, recovery time, or fake stagger;
- critical landing state must be communicated by gameplay/animation/audio/UI as well, not camera motion alone;
- extreme/lethal landing may use later death-state presentation authority but Decision #15 does not define death camera grammar.

### No spring overshoot as default feel
Automatic airborne follow should be damped for stability rather than deliberately springy.

- no visible camera oscillation around jump apex;
- no rebound past canonical height after landing;
- no repeated vertical bouncing on stairs/rapid hops;
- tuning may use damping/lag mechanisms, but the player-facing result should settle without decorative overshoot.

### Locked-target airborne behavior
If Neris is target-locked while jumping/falling:
- #11/#14 Relationship Frame authority remains active for the valid current target;
- Neris's airborne movement semantics remain `docs/20` authority;
- camera may adapt vertical composition to keep Neris + target readable, but does not reinterpret movement input;
- if lock becomes invalid midair, target lock exits under existing lock validity rules;
- movement basis after lock loss follows locomotion's already-approved stable-frame behavior and is not retroactively changed by camera orientation;
- the camera transitions from its exact current pose toward valid unlocked airborne/exploration behavior without snap or hidden recenter.

Decision #15 does not create automatic airborne retargeting.

### Physical camera authority
Throughout jump/fall/mantle/hang:
- Decision #5 owns collision compression/recovery;
- Decision #6 owns target/world occlusion honesty;
- Decision #7 owns severe Close Quarters presentation;
- Decision #8 owns low-ceiling legality;
- no airborne state allows camera clipping or world transparency hacks;
- a low ceiling over a jump/mantle may constrain pitch/height exactly as the physical authorities require.

### State-transition hysteresis
Short-lived transitions must not cause state thrash.

The camera should distinguish by tuning-defined persistence/evidence between:
- ordinary jump versus meaningful fall;
- one-frame `MOVE_Falling` during floor transitions versus a real airborne event;
- catch transition versus established hang;
- mantle/pull-up versus grounded recovery.

Exact timing remains tuning, but classifications must be inspectable and deterministic enough for the System IDE to explain.

---

## Accessibility boundary
Airborne camera motion is a significant comfort surface.

Requirements:
- ordinary jump minimizes unnecessary automatic vertical camera motion;
- no automatic landing slam;
- no forced spectacle pitch/zoom;
- any optional landing-settle contribution must later respect Decision #16 camera-motion/shake reduction settings;
- critical fall/landing information may not rely solely on camera movement;
- manual camera input remains available through ordinary airborne/traversal states wherever physically possible.

Decision #16 owns shake/motion intensity controls. Decision #17 owns sensitivity/inversion/device mapping.

---

## Camera / Targeting System IDE requirements

The workbench must expose enough evidence to answer **why is the camera treating this as a jump, fall, mantle, hang, or landing?**

At minimum show:
- authoritative locomotion/traversal state;
- Unreal movement mode/custom substate where applicable;
- time in current state;
- Neris world velocity and vertical velocity;
- recent airborne duration and vertical displacement;
- ordinary-jump vs meaningful-fall classification/reason;
- canonical/resolved Neris screen-space Y;
- airborne vertical dead/soft/hard zones;
- current automatic vertical position-follow contribution;
- any automatic pitch contribution and activation/rejection reason;
- manual camera input and suppression/grace state;
- local landing/ground evidence used by camera, clearly separated from hidden metadata;
- mantle/hang/pull-up state and authoritative traversal target where gameplay has committed one;
- animation/root-motion/Motion-Warping state as **presentation diagnostic**, not camera authority;
- requested camera pose;
- physically resolved pose;
- active #5/#6/#7/#8 constraint ownership;
- landing severity from locomotion authority;
- landing settle contribution;
- lock target/Relationship Frame state during airborne movement;
- lock-loss reason/transition if applicable.

### Validation checks
At minimum detect:
- camera state driven solely by an animation montage/bone instead of authoritative traversal state;
- ordinary hop causing excessive vertical camera translation;
- automatic pitch-down with no physically justified fall/landing evidence;
- hidden warp/landing marker used before gameplay commitment;
- mantle camera attached to a moving skeleton bone;
- jump/fall camera adding FOV pulses;
- camera overshoot/oscillation after landing;
- blocked physical camera constraint ignored during traversal;
- lock loss retroactively changing airborne movement basis;
- state thrash from one-frame falling transitions.

---

## Representative test matrix

### Ordinary jump
- standing jump;
- walk→jump;
- run→jump;
- Sprint→jump;
- tiny coyote-edge jump;
- buffered jump on landing;
- repeated hops;
- jump while manually orbiting camera;
- jump under low ceiling;
- jump with rear-wall camera compression.

Expected: same camera grammar, minimal vertical bounce, no zoom/FOV/pitch spectacle.

### Falls
- brief ordinary walk-off;
- short safe drop;
- upper-safe firm landing;
- moderate damaging fall;
- severe fall;
- long fall alongside wall;
- fall through tall shaft;
- fall while manually looking upward/sideways/backward;
- fall with physically visible landing area below;
- fall with no visible landing surface;
- fall near a different catchable ledge.

### Mantle / ledge
- low mantle toward camera;
- low mantle away from camera;
- mantle side-on;
- mantle under overhang;
- mantle with wall compression;
- ledge catch from short fall;
- ledge catch from longer fall;
- established hang + manual orbit;
- shimmy while camera remains stable;
- pull-up;
- deliberate release → fall;
- release → different valid ledge catch;
- blocked pull-up stays hanging.

### Lock integration
- locked jump with ordinary target level with Neris;
- locked jump with target above/below;
- locked fall;
- target temporarily occluded midair;
- target invalidates midair;
- lock breaks during fall near wall;
- boss-profile target during airborne movement.

### Robustness
- 30/60/120+ FPS;
- camera collision during every airborne/traversal state;
- repeated state transitions without vertical camera chatter;
- animation root-motion/warping variations with identical gameplay state proving camera semantics do not change.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
- `UCharacterMovementComponent` and `EMovementMode` represent authoritative character movement modes such as walking, falling, swimming, and custom movement. Falling is a gameplay movement state, not merely an animation state.
- Unreal locomotion separates movement/capsule authority from animation presentation; Pose Warping and Motion Warping are tools for fitting animation to movement/targets.
- Motion Warping can align a mantle montage to a named warp target; that makes it useful presentation/animation infrastructure, not automatic camera authority.
- Gameplay Cameras supports explicit damping nodes, demonstrating that position smoothing can be designed separately from gameplay state.

References:
- https://dev.epicgames.com/documentation/en-us/unreal-engine/movement-components-in-unreal-engine
- https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/EMovementMode
- https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UCharacterMovementComponent
- https://dev.epicgames.com/documentation/unreal-engine/motion-warping-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/locomotion-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/gameplay-camera-system-quick-start

These establish useful implementation primitives and state separation. They do not dictate Stillring's airborne camera feel.

### Stillring authority
`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` already locks:
- modest always-available jump;
- useful but limited air control;
- coyote/buffer windows;
- mantle/scramble as validated traversal state;
- real ledge catch/hang/pull-up/release grammar;
- fall severity/landing recovery bands;
- release/catch rules and state continuity.

Decision #15 deliberately presents those systems without changing them.

### IP boundary
Under `docs/05_IP_GUARDRAILS.md`, this decision uses general third-person readability problems only. It copies no exact Zelda or other game's airborne camera offsets, damping, pitch, landing motion, ledge camera, timings, or control mapping.

---

## Why this package is approved
This package follows the project's established separation of concerns:
- locomotion state tells the camera what Neris is actually doing;
- camera chooses readable presentation without altering locomotion;
- animation presents traversal and may be warped to authored targets, but does not become a second camera rules engine;
- #5/#6/#7/#8 retain physical/world honesty;
- #9's “camera must not know the puzzle solution” principle extends naturally to hidden landing prediction;
- #11/#14 remain lock-on target framing authority when a valid target exists;
- System IDE instrumentation makes state transitions auditable.

The result is a camera that stays calm through ordinary jumping and becomes more informative only when the physical situation genuinely demands it.

---

## Player-facing acceptance
Decision #15 passes when:
1. ordinary jumping feels like the same camera continuing through the jump;
2. small jump arcs do not visibly bob the whole world;
3. meaningful falls gain useful trajectory/landing context without automatic spectacle or constant look-down;
4. manual camera input remains authoritative while airborne;
5. hidden landing/puzzle metadata never steers the camera;
6. mantle/pull-up camera follows authoritative traversal displacement rather than animation bones/warp targets;
7. ledge catch settles smoothly into a readable hang without a cut or side-view takeover;
8. established hang remains third-person and player-owned;
9. deliberate release continues naturally into fall rules;
10. routine landings do not slam/bounce/pulse the camera;
11. stronger landing settle, if used, reflects existing locomotion severity and does not invent gameplay consequences;
12. camera follow settles without decorative spring overshoot;
13. lock-on airborne behavior preserves the current valid Relationship Frame and exits cleanly if lock becomes invalid;
14. physical collision/occlusion/cramped/ceiling authorities remain intact;
15. the System IDE can explain state classification, camera contribution, physical constraints, and transitions.

---

## Next decision
**Camera Decision #16 — camera shake default and accessibility range.**

Research it independently. Do not infer shake categories, intensity, stacking, rotational versus positional motion, comfort controls, rumble relationship, or reduction/off behavior from landing-settle language in Decision #15.
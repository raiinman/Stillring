# 33 — Gate 1 Camera Shake / Motion Accessibility Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #16 for Issue #2. This file extends cumulative camera authority through Decisions #1–#16.

## Authority
Camera Decision #16 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Decision #16 owns gameplay camera shake semantics, motion stacking, authored shake categories, motion-accessibility scaling, and the relationship between shake and other camera systems. It does not own look sensitivity/inversion/device mapping (#17), cinematics, or controller vibration policy beyond requiring separation.

Camera goal:
> **The player should look at Orra, not babysit the camera.**

---

## Camera Decision #16 — camera shake default / accessibility range — LOCKED

### Core philosophy
Camera shake is **optional feedback layered on top of a solved readable camera**, never part of the camera's gameplay logic.

> **Impact may move the image. It may not move the rules.**

Stillring uses restrained gameplay camera shake by default and always allows the player to reduce it continuously to **zero**.

### Camera shake is post-composition feedback
Camera shake is applied only after the authoritative camera has resolved:
- camera mode;
- framing target(s);
- player manual input;
- target relationship framing;
- collision/occlusion legality;
- cramped/ceiling constraints;
- airborne/traversal composition;
- boss profile composition.

Shake must not feed back into those systems.

Therefore shake may not:
- change target acquisition/switch scoring;
- alter Neris movement or facing;
- change lock validity;
- change collision traces or desired camera distance;
- move canonical framing anchors;
- alter gameplay hit timing/damage/invulnerability;
- become input to aim/interaction logic;
- permanently alter the solved camera pose after the shake ends.

The authoritative camera remains stable beneath the additive presentation layer.

### Player-facing gameplay-shake control
Stillring exposes a player setting:

**Gameplay Camera Shake Intensity: 0–100%**

Semantic requirements:
- 100% = authored full gameplay-shake scale;
- intermediate values scale authored gameplay shake continuously;
- 0% = no authored gameplay camera shake contribution;
- the setting is available without requiring a difficulty change;
- reset-to-default is available;
- exact default percentage is a prototype/accessibility tuning choice, but the default must be **restrained rather than maximal spectacle**;
- setting shake to 0% does not change gameplay rules, hit results, timing, animation, VFX, audio, enemy behavior, or controller rumble settings.

This is not copied from another game's exact slider presentation; the semantic requirement is continuous player control that reaches true zero.

### No baseline ambient handheld sway
Stillring does **not** add constant decorative handheld/idle camera sway as a baseline exploration effect.

Reasons:
- the camera already has meaningful movement from player control, locomotion, physical constraints, framing, and traversal;
- constant sway adds motion without information;
- it weakens the project's goal that the player stop noticing the camera;
- it creates unnecessary motion-sensitivity burden.

If a future explicit world state requires environmental motion (ship deck, earthquake, dream state, etc.), that motion must be authored under a relevant system/event contract and respect the same motion-accessibility scaling where appropriate.

### Semantic shake categories
Every gameplay shake must have a semantic category rather than being an anonymous effect.

Gate 1 categories:
1. **Player Landing / Locomotion Impact** — firm/severe landings or comparable player-body impact feedback;
2. **Player Hit** — Neris receiving a hit;
3. **Player Attack Impact** — deliberate impact feedback from Neris's offensive action;
4. **World / Environmental Event** — explosion, collapse, heavy mechanism, earthquake-like event;
5. **Boss / Heavy Event** — large authored boss/world impacts where stronger presentation may be justified.

Additional categories may be added later only when they have a clear semantic purpose.

Each shake instance must report its category to the Camera / Targeting IDE.

### Restrained default authoring
Gameplay readability outranks spectacle.

Authoring rules:
- ordinary repeated actions use low-intensity/short-duration motion;
- high-frequency shake is especially conservative during active combat;
- large one-off events may use stronger motion but remain bounded;
- long looping shake requires deliberate review and attenuation where physical origin matters;
- repeated weak hits may not build into stronger motion simply because effects stack accidentally;
- no event receives a strong shake merely because “impact should feel big.” Animation, audio, VFX, haptics, timing, and hit reaction should carry most impact information.

### Rotation is more constrained than translation
Rotational camera shake can directly disturb orientation and targeting, so Stillring treats it as the highest-risk shake channel.

- rotational shake is allowed only in small bounded amounts;
- yaw/pitch rotation must never become large enough to resemble player camera input or target-camera steering;
- roll is extremely limited and normally zero for ordinary combat feedback;
- strong rotational oscillation is not a substitute for impact animation;
- player camera orientation after the shake resolves returns to the same underlying solved orientation it would have had without shake.

### No gameplay FOV shake
Gameplay camera shake does **not** animate FOV as a default feedback channel.

- no impact lens pumping;
- no repeated FOV oscillation during combat;
- no zoom-in/out shake on hits or landings;
- boss/world impacts do not earn automatic FOV pulses.

A future deliberately authored cinematic camera effect is outside Decision #16 and does not become ordinary gameplay camera authority.

This preserves spacing perception and reduces motion discomfort.

### Position shake remains small and physically legible
Positional shake is preferred over rotation where camera motion is useful.

- positional amplitude is bounded relative to the active camera distance/space;
- shake must not visibly clip the camera through solid geometry;
- shake is a view-layer displacement, not permission to move the authoritative camera through world blockers;
- if implementation-level post-shake clipping risk exists, the final presentation must clamp/resolve safely rather than sacrifice physical camera legality.

Exact implementation order is engineering work; physical honesty is semantic authority.

### World-source shake uses distance attenuation
Environmental/world-origin shake should normally attenuate with physically meaningful distance.

- nearby heavy event may produce stronger shake;
- distant event produces weaker or no shake;
- attenuation bounds are authored and inspectable;
- event category/intensity still passes through the player's gameplay-shake scale;
- being inside a source radius does not override 0% player shake.

Unreal's Camera Shake Source/PlayWorldCameraShake attenuation primitives are implementation options, not tuning authority.

### Stacking budget / saturation
Multiple shake events may overlap, but their result is **budgeted**, not unlimited additive chaos.

Requirements:
- active shake instances can coexist where semantically useful;
- the final combined translation/rotation magnitude is capped by a tuning-defined gameplay-shake budget;
- low-priority repetitive shakes should saturate or merge rather than linearly grow forever;
- one major boss/environment event may temporarily dominate weaker shake layers without deleting their gameplay events;
- repeated identical effects may use single-instance/restart/merge behavior where appropriate;
- exact priority weights and cap values remain tuning, but the final camera must remain readable under worst-case stacking.

One hit + explosion + landing should not equal three times the camera violence.

### Shake does not fight camera constraints
Shake cannot become a hidden competitor to Decisions #5/#6/#7/#8/#11/#14/#15.

- collision-compressed camera remains collision-compressed;
- low-ceiling camera remains legally constrained;
- Relationship Frame remains authoritative beneath shake;
- boss framing remains authoritative beneath shake;
- airborne/landing composition remains authoritative beneath shake;
- shake ending cannot cause camera recenter, distance recovery, target change, or a second settling animation.

### Landing settle interaction
Decision #15 permits a small bounded landing **settle** based on fall severity. Decision #16 classifies optional non-essential impact motion as part of motion accessibility.

- gameplay-shake intensity scales any decorative/high-frequency landing shake;
- a small low-frequency camera-position settle used to visually reconcile the camera with authoritative character displacement may remain part of #15 follow behavior;
- any extra impact kick/oscillation must reduce toward zero with the gameplay-shake setting;
- at 0% gameplay shake, landing remains fully readable through character animation, audio, VFX, UI, and gameplay recovery without an impact shake.

### Critical information cannot depend on shake
Camera shake is redundant feedback only.

No player-critical fact may be conveyed solely by shake, including:
- whether Neris was hit;
- whether an attack connected;
- whether a boss phase changed;
- whether a platform/world event occurred;
- whether a landing caused damage;
- attack direction;
- stun/interrupt state;
- environmental danger.

If shake is disabled, the game remains fully interpretable.

### Controller rumble is independent
Camera shake and controller vibration/haptics are separate presentation channels.

- changing gameplay camera shake does not silently alter controller vibration;
- disabling vibration does not disable camera shake;
- both should ultimately have their own player-facing settings/policy;
- critical information may not rely solely on either channel.

Final vibration semantics can be specified by the relevant input/accessibility production work; Decision #16 only forbids hidden coupling.

### Cinematic boundary
Decision #16 governs **gameplay camera** motion.

Cinematics may later define their own motion/smoothing policy, but:
- gameplay shake settings should not be assumed to govern Sequencer/cinematic motion unless explicitly designed;
- cinematic accessibility must be deliberately addressed before release;
- cinematic camera motion may not be used as a loophole to add mandatory gameplay-relevant shake during interactive control.

---

## Accessibility requirements

### True zero
0% gameplay shake means true zero for authored gameplay shake instances.

No category is exempt because it is “important.” Important events need redundant non-camera communication.

### Motion-reduction compatibility
Stillring should support a future broader **Motion Reduction** settings grouping/preset that can adjust multiple comfort surfaces together, such as:
- gameplay camera shake;
- optional camera-settle strength;
- automatic recenter/follow assists where applicable;
- motion blur/post effects where production includes them;
- future cinematics smoothing settings.

Decision #16 does not finalize that entire settings menu. It establishes that camera shake must participate cleanly and can reach zero.

### Persistent reference point compatibility
A future optional persistent center/reference dot is compatible with this camera architecture and may help players with motion sensitivity. It is not required by Decision #16 and would be a UI/accessibility presentation decision.

---

## Camera / Targeting System IDE requirements

The workbench must expose the entire live shake stack and resulting motion budget.

At minimum show:
- gameplay-shake player setting percentage;
- each active shake instance;
- semantic category;
- source actor/event and stable identifier where available;
- shake asset/pattern;
- authored base scale;
- source attenuation factor;
- player accessibility multiplier;
- category/priority multiplier;
- final instance scale;
- duration / blend-in / blend-out;
- play space;
- positional amplitudes/frequencies;
- rotational amplitudes/frequencies;
- any FOV contribution, with validation error for ordinary gameplay shake;
- single-instance/restart/merge state;
- final stack translation magnitude;
- final stack rotation magnitude;
- stack budget/cap and saturation state;
- authoritative pre-shake camera pose;
- final presented post-shake pose;
- active camera mode/constraint ownership;
- whether optional landing impact motion is shake-scaled or core camera settle.

### Exercise tools
The IDE should support one-click preview/test of each semantic shake category at:
- authored full scale;
- current player scale;
- 50%;
- 0%;
- representative near/mid/far source attenuation where relevant;
- representative stack combinations.

### Validation checks
At minimum detect:
- gameplay shake containing FOV oscillation;
- rotational amplitude above reviewed safety bounds;
- shake instance bypassing player accessibility scale;
- event marked critical but communicated only by shake;
- stack exceeding final motion budget;
- looping world shake with no valid stop/attenuation design;
- category missing/unknown;
- shake modifying canonical camera state rather than presentation only;
- 0% setting still producing authored gameplay shake;
- camera shake and controller rumble accidentally coupled;
- post-shake camera failing to return to the correct underlying solved pose.

---

## Representative test matrix

### Individual categories
- routine firm landing;
- damaging landing;
- light player hit;
- heavy player hit;
- light attack impact;
- heavy attack impact;
- nearby environmental collapse;
- distant environmental collapse;
- boss heavy event;
- sustained environmental rumble.

### Player settings
Test every representative event at:
- 100%;
- default tuned value;
- 50%;
- low non-zero value;
- 0%.

Expected: gameplay semantics never change and 0% produces no authored gameplay shake.

### Stacking
- player hit + attack impact;
- landing + boss event;
- environment rumble + repeated hits;
- three rapid identical hits;
- multiple boss impacts;
- source shake plus local hit shake;
- long rumble while smaller events occur.

Expected: final motion remains inside the budget; repetition does not become uncontrolled additive violence.

### Camera-state integration
- free exploration;
- target lock;
- target switch transition;
- boss profile;
- rear-wall collision compression;
- Close Quarters Camera;
- low ceiling;
- jump/fall;
- ledge hang;
- mantle;
- manual camera input during shake.

Expected: shake never changes authoritative camera/gameplay state.

### Comfort / robustness
- 30/60/120+ FPS;
- repeated high-frequency events for 30+ seconds;
- long low-frequency world event;
- quick alternating rotation-sensitive impacts;
- 0% shake through entire combat encounter;
- vibration on/off independently of camera shake;
- camera collision at maximum allowed stack displacement.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
Unreal's camera-shake system supports:
- separate root shake patterns;
- positional, rotational, and FOV channels;
- amplitude/frequency control;
- timing/blend in/out;
- instance-level scale;
- camera/world/user-defined play spaces;
- single-instance behavior;
- composite/layered shakes;
- source-based distance attenuation;
- stopping individual/all shakes.

References:
- https://dev.epicgames.com/documentation/unreal-engine/camera-shakes-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/UCameraShakeBase
- https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UCameraShakeSourceComponent
- https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/APlayerCameraManager/PlayWorldCameraShake

These primitives make semantic categories, accessibility scaling, source attenuation, and stacking control feasible. Their defaults are not Stillring policy.

### Shipped-game accessibility problem study
Official accessibility documentation provides strong evidence that camera shake should be independently adjustable for motion comfort:
- **God of War Ragnarök** exposes a 0–10 camera-shake intensity slider, separates short/high-frequency gameplay shake from ambient camera sway, and includes both in a Motion Reduction preset.
- **The Last of Us Part II** identifies simulated 3D motion as a source of motion sickness and exposes camera-shake intensity alongside motion blur, camera distance, FOV, and a persistent center dot.

References:
- https://www.playstation.com/en-us/games/god-of-war-ragnarok/accessibility/
- https://www.playstation.com/en-id/games/the-last-of-us-part-ii/accessibility/

Stillring takes only the abstract accessibility lesson: gameplay camera motion must be reducible and independently controllable. It does not copy those games' exact scales, menu layouts, presets, camera patterns, values, or presentation.

### IP boundary
Under `docs/05_IP_GUARDRAILS.md`, Stillring defines its own shake categories, authoring limits, stack budget, channel rules, IDE surfaces, and testing. No other game's shake assets, patterns, exact amplitudes, timing, or UI are authority.

---

## Why this package is approved
Decision #16 is consistent with the camera system already locked:
- the camera is built around stable player ownership and readable framing;
- #15 specifically rejects mandatory landing spectacle;
- #13 assigns threat readability to honest communication rather than camera contortion;
- #5/#7/#8 require physically stable camera behavior;
- #11/#14 depend on trustworthy spatial framing;
- the System IDE contract requires live state/provenance/validation;
- modern accessibility practice strongly supports a true reduction/zero path for camera shake.

The clean rule is therefore: shake can add feel, but never authority.

---

## Player-facing acceptance
Decision #16 passes when:
1. ordinary gameplay shake feels restrained rather than constantly noticeable;
2. the player can continuously reduce gameplay shake to true zero;
3. setting shake to zero never changes gameplay outcomes or removes critical information;
4. Stillring has no mandatory baseline ambient handheld sway;
5. gameplay shake never drives FOV;
6. rotational shake is much more constrained than positional micro-shake;
7. world-source shake attenuates with distance where appropriate;
8. overlapping shake remains inside a tested final motion budget;
9. repeated effects do not multiply into uncontrolled camera violence;
10. shake never changes target selection, movement, camera framing authority, or physical camera constraints;
11. optional landing impact motion respects the shake/motion-reduction setting;
12. vibration remains independently controllable;
13. the IDE exposes every active shake, effective scaling, stack budget, and underlying canonical camera pose;
14. worst-case stacked combat remains readable with shake at default/full values and completely playable at 0%.

---

## Next decision
**Camera Decision #17 — sensitivity curves / inversion / mouse parity.**

Research it independently. Do not infer look-stick dead zones, response curve, acceleration, horizontal/vertical sensitivity, mouse scaling, inversion, frame-rate behavior, target-switch binding, or remapping from movement input authority or Decision #12's semantic actions.
# 34 — Gate 1 Camera Input / Sensitivity / Parity Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #17 for Issue #2. This file extends cumulative camera authority through Decisions #1–#17.

## Authority
Camera Decision #17 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Decision #17 owns player camera-input processing semantics across controller and mouse/keyboard, look sensitivity, dead-zone/response behavior, inversion, frame-rate treatment, remapping requirements, and parity constraints for camera/targeting actions. It does not reserve final physical buttons/keys that depend on the complete future game-wide action map.

Camera goal:
> **The player should look at Orra, not babysit the camera.**

---

## Camera Decision #17 — sensitivity / inversion / mouse parity — LOCKED

### Core philosophy
Controller and mouse share **camera meaning**, not the same transfer function.

> **Same intention. Native device feel.**

The camera receives semantic look/switch/recenter actions. Device-specific processing converts hardware input into those semantics without forcing a mouse to behave like a stick or a stick to behave like a mouse.

---

## 1. Semantic camera actions

The camera/input layer must preserve distinct semantic actions at minimum:
- `LookCamera2D` — continuous player camera manipulation;
- `RecenterCamera` — Decision #4 explicit recenter request;
- `TargetLockOrCancel` — current targeting lock/cancel semantic;
- `SwitchTarget2D` — Decision #12 discrete directional switch request;
- any later explicitly approved aim/precision action, if one exists after Decision #18/later tool design.

Physical bindings may vary by device/platform and may be remapped. Gameplay code must not infer these semantics from a specific hardware key name.

### No premature permanent button reservation
Decision #17 does **not** permanently reserve D-pad, shoulder buttons, stick click, mouse wheel, or another physical control for target switching because the full combat/tool/inventory action vocabulary is not yet approved.

That is not unresolved camera policy. The policy is:
- `SwitchTarget2D` must remain a distinct semantic action;
- its eventual default physical binding must not unpredictably co-trigger `LookCamera2D`/Decision #11 composition nudge;
- controller and keyboard/mouse must both have practical default access;
- all gameplay camera/targeting actions must be remappable;
- when the global control map is finalized, it must obey these constraints rather than silently collapsing switch and nudge into one ambiguous axis.

---

## 2. Controller look processing

### Right-stick input is a rate request
Controller look-stick magnitude represents a requested **angular camera velocity**, not an immediate per-sample angular displacement.

Processing conceptually follows:

```text
raw stick vector
→ radial dead-zone / outer saturation
→ preserve direction
→ static monotonic response curve
→ horizontal/vertical sensitivity
→ inversion
→ requested angular velocity
→ integrate by frame delta time
→ camera semantic request
```

Exact implementation classes/modifier order may differ so long as the player-facing behavior matches.

### Radial inner dead zone
Controller camera look uses a **radial/magnitude-based inner dead zone**.

- centered drift inside the threshold produces zero look request;
- direction is preserved outside the dead zone;
- separate axial dead zones are not the baseline because they distort diagonals;
- output magnitude is smoothly remapped from the dead-zone edge toward full input;
- no discontinuous camera-speed jump at activation;
- exact default threshold remains tuning against representative controllers.

### Outer saturation
A small configurable outer saturation margin is permitted so worn/limited-travel sticks can reach full requested look speed.

- it must not change direction;
- it must not exceed the canonical maximum requested speed;
- exact default remains device testing/tuning.

### Player-adjustable right-stick dead zone
The look-stick inner dead zone must be player-adjustable within safe supported bounds.

The settings UI should communicate the tradeoff plainly:
- lower = earlier response / more drift sensitivity;
- higher = more drift resistance / less fine low-end travel.

Reset-to-default is required.

### Static, monotonic response curve
Controller look uses a static magnitude response curve that is:
- monotonic;
- continuous;
- predictable;
- precision-friendly near center;
- capable of reaching full speed near the outer stick range;
- independent of how long the player has held the stick.

Exact curve/exponent remains playtest tuning.

### No hidden time-based look acceleration by default
Stillring does **not** use time-held acceleration as the default controller look behavior.

Holding the same processed stick magnitude should request the same angular velocity over time.

Reasons:
- repeatable muscle memory;
- easier accessibility/tuning;
- easier System IDE diagnosis;
- fewer surprises during camera nudge/lock-on;
- avoids a slow stick request suddenly becoming a fast camera sweep merely because it was held.

A future optional response preset could be explicitly reviewed if human testing establishes need, but time acceleration is not baseline authority.

### Controller horizontal and vertical sensitivity
Controller camera settings expose independent:
- **Horizontal Look Sensitivity**;
- **Vertical Look Sensitivity**.

Requirements:
- both may be raised and lowered substantially around default;
- exact UI scale/default numeric representation remains product tuning;
- effective angular-speed range must include at least ±50% around default and should offer broader practical adjustment;
- settings affect manual look request, not automatic camera-assist timing/strength unless explicitly stated elsewhere.

### Controller inversion
Expose independent:
- **Invert Camera X** — On/Off;
- **Invert Camera Y** — On/Off.

Inversion happens as a clear player preference and must apply consistently to manual camera look in every normal state where that axis is available.

It must not invert:
- Neris movement;
- automatic camera assistance;
- target-switch semantic direction unless the global remapping/settings design explicitly chooses that separate behavior.

Target switching expresses requested screen direction, not “camera look inversion.”

---

## 3. Mouse look processing

### Mouse delta is displacement, not stick rate
Mouse input represents hardware movement delta and is mapped directly to camera angular displacement after sensitivity/inversion processing.

Conceptually:

```text
raw mouse delta
→ mouse horizontal/vertical sensitivity
→ inversion
→ angular displacement request
→ camera semantic request
```

### No stick dead zone
Mouse has no analog-stick dead zone.

- tiny genuine mouse movement remains tiny camera movement;
- no “must move X pixels before camera wakes up” behavior;
- no radial stick processing applied to mouse delta.

### No controller response curve
Mouse does not pass through the controller magnitude response curve.

A mouse should not become sluggish near zero because the stick was designed for thumb precision.

### No default mouse acceleration
Stillring adds no game-level velocity-dependent or time-dependent mouse acceleration by default.

- equal device delta at equal sensitivity produces equal angular displacement;
- fast physical mouse motion does not gain a hidden multiplier merely because it is fast;
- OS/platform raw-input behavior remains an implementation/platform consideration, but the game must not intentionally add opaque acceleration.

### No default mouse smoothing
Stillring does not add multi-frame mouse smoothing by default.

- mouse movement should feel immediate;
- smoothing that creates latency/trailing motion is rejected as baseline;
- any platform-level unavoidable processing must be documented/verified rather than mistaken for intentional camera feel.

### Do not multiply mouse delta by frame delta time
Mouse delta must **not** receive the same delta-time angular-rate integration used for a held controller stick.

The mouse sample already represents movement over the input interval. Multiplying it again by frame delta would make sensitivity vary incorrectly with frame rate/input sampling.

Implementation must validate this explicitly at 30/60/120+ FPS and representative mouse polling rates.

### Mouse sensitivity
Expose independent:
- **Mouse Horizontal Sensitivity**;
- **Mouse Vertical Sensitivity**.

Requirements:
- meaningful broad adjustment around default;
- reset-to-default;
- no artificial coupling to controller sensitivity;
- UI values may use a human-friendly scale rather than exposing engine coefficients.

A later advanced “lock X/Y together” convenience is compatible but must not remove independent control.

### Mouse inversion
Expose independent mouse:
- **Invert Mouse X**;
- **Invert Mouse Y**.

These may default to the corresponding global camera inversion preference if the settings UX chooses, but controller and mouse values must remain representable independently in configuration so mixed-device players are not trapped by one shared preference.

---

## 4. Keyboard camera/accessibility parity

Mouse is not the only PC camera input path.

The game must support remappable **digital camera look directions** or an equivalent digital-accessible method so essential gameplay is not structurally impossible without analog mouse movement.

Digital camera look:
- requests a tuning-defined angular rate;
- supports left/right/up/down;
- normalizes diagonals where combined;
- uses the same semantic camera authority/constraints;
- respects camera inversion if the selected mapping/settings design applies it;
- is remappable.

Exact default keys are global-control-map authority, not Decision #17.

This also provides a development/accessibility fallback and aligns with broader input-accessibility practice.

---

## 5. Frame-rate independence

### Controller
Processed stick input requests angular velocity. Final angular displacement is integrated using elapsed frame time so the same sustained stick request turns the camera at approximately the same degrees-per-second across supported frame rates.

### Mouse
Mouse delta maps to angular displacement without extra delta-time multiplication.

### Automatic camera systems
Decision #17 does not change their tuning, but all time-based damping/transition behavior must likewise use time-consistent calculations so sensitivity/input testing is not confounded by frame rate.

### Acceptance range
Gate 1 must compare at minimum 30, 60, 120, and a high-refresh uncapped/representative PC mode where feasible.

No supported frame rate may materially change:
- controller degrees-per-second at a fixed processed stick magnitude;
- mouse angular movement for a given physical/input delta;
- target-switch one-request/one-switch semantics;
- recenter action semantics.

---

## 6. Target-switch physical mapping constraints

Decision #12 already locks switching and camera nudge as separate semantic actions. Decision #17 locks how eventual device mappings must respect that separation.

### Controller
The final global control map must provide a practical `SwitchTarget2D` binding that:
- carries directional intent;
- does not rely on ordinary stick drift;
- does not unpredictably co-trigger camera nudge/look;
- can be remapped;
- can be performed without an undocumented magnitude/time classifier;
- does not require a physically demanding chord as the only available binding if an accessible remap can avoid it.

A context-sensitive binding is allowed if the lock-on mapping context is explicit and prompts/settings correctly show it.

### Keyboard/mouse
The final global control map must provide practical directional target switching without interpreting arbitrary mouse motion as a switch.

Possible later mappings may include:
- remappable digital switch-left/right/up/down actions;
- mouse buttons/wheel where direction semantics can be represented deliberately;
- other explicit inputs.

Decision #17 does not canonize a particular key/wheel direction before the full action map exists.

### No hidden flick classifier as required default
A scheme that uses one physical look axis for both nudge and switch may exist only if:
- the user explicitly selects/maps that scheme;
- classification thresholds are visible/testable;
- one sample cannot trigger both semantics;
- drift/noise is rejected;
- accessibility alternatives exist.

It is not the mandatory Stillring baseline.

---

## 7. Recenter and camera assists

Recenter (#4) remains a discrete semantic action and is remappable.

Sensitivity settings do not secretly modify:
- recenter duration/easing;
- soft yaw-follow strength;
- vertical-context-assist strength;
- target Relationship Frame damping;
- boss framing;
- camera shake intensity.

Those systems have their own authority/settings.

This prevents “I lowered camera sensitivity and now auto-camera takes longer” style hidden coupling.

---

## 8. Full gameplay remapping requirement

Stillring's production control system must support in-game remapping of gameplay camera/targeting actions rather than relying only on platform-level remapping.

At minimum camera-related remapping includes:
- manual camera look inputs where hardware representation permits;
- recenter;
- target lock/cancel;
- target switch directions/action;
- later approved aim/precision actions if any.

Requirements:
- remapped prompts/tutorials/controller diagrams update to show current bindings;
- conflicts are detected/explained;
- reset-to-default available;
- alternate supported input devices retain practical access;
- settings remain usable with controller and keyboard/mouse.

Broader game-wide remapping belongs production input authority, but camera cannot be an exception.

---

## 9. Device switching and mixed input

The camera must tolerate players alternating between controller and mouse/keyboard.

- active-device detection may update prompts/UI but must not reset camera orientation;
- switching device does not interpolate sensitivity values between device profiles;
- each device uses its own processing path/settings immediately;
- a mouse movement after controller use must not inherit stick smoothing/dead-zone state;
- controller input after mouse use must enter through its normal radial dead-zone/response path;
- stale input from the previous device must not create a target switch or camera movement.

Prompt-source hysteresis may be used to avoid UI glyph flicker from noisy devices; it must not alter gameplay input semantics.

---

## 10. Settings persistence and provenance

Player settings must persist separately from canonical design tuning.

The camera system must distinguish:
- canonical default/tuning values;
- player preference values;
- temporary development/System IDE overrides;
- effective runtime processed values.

Changing a player preference must not “promote” a new canonical game default.

The System IDE contract's provenance rules apply.

---

## Camera / Targeting System IDE requirements

The workbench must expose the entire raw→processed look pipeline.

At minimum show:
- active input device;
- active Input Mapping Context(s) and priority;
- physical input source/key/axis;
- raw `LookCamera2D` input value;
- controller radial magnitude/direction;
- inner dead-zone threshold/state;
- outer saturation threshold/state;
- post-dead-zone vector;
- response-curve input/output;
- controller horizontal/vertical sensitivity;
- mouse horizontal/vertical sensitivity;
- X/Y inversion state per device;
- smoothing/acceleration state, with baseline expected Off for mouse and time acceleration Off for controller;
- frame delta;
- controller requested angular velocity;
- controller final angular displacement this frame;
- raw mouse delta;
- mouse final angular displacement this sample/frame;
- final semantic look request;
- camera state that consumes/rejects/limits the request;
- manual-input suppression of auto assists;
- recenter action state;
- `SwitchTarget2D` semantic request separately from look/nudge;
- mapping conflict/co-trigger diagnostics;
- currently persisted player preferences versus canonical defaults/session overrides.

### Visualizers
The IDE should support:
- live 2D stick vector plot with radial dead/outer zones;
- response-curve graph with current input point;
- angular velocity readout in degrees/second for controller;
- mouse delta→angular-displacement readout;
- frame-rate comparison capture;
- device-switch timeline;
- mapping-context/action trigger view.

### Validation checks
At minimum detect:
- axial/square controller dead zone accidentally replacing radial baseline;
- discontinuity at dead-zone boundary;
- controller time-held acceleration active in baseline path;
- mouse receiving controller response curve;
- mouse receiving stick dead zone;
- mouse receiving extra delta-time scaling;
- mouse smoothing/acceleration unexpectedly enabled;
- missing independent X/Y inversion;
- sensitivity range failing supported accessibility range;
- target switch/look actions co-triggering from one input event;
- unmappable camera gameplay action;
- remapped prompts not matching actual action;
- device switch inheriting stale processing state;
- player settings overwriting canonical tuning provenance.

---

## Representative test matrix

### Controller hardware
- healthy modern controller centered;
- mild right-stick drift;
- near-dead-zone slow circles;
- diagonal input around dead-zone edge;
- partial stick 25/50/75%;
- full stick;
- worn controller unable to reach perfect hardware maximum;
- rapid direction reversal;
- small deliberate precision movements;
- sustained stick for 10+ seconds proving no time acceleration.

### Controller settings
- minimum/low/default/high/maximum horizontal sensitivity;
- same for vertical;
- low/high dead zone;
- outer saturation variation;
- invert X only;
- invert Y only;
- invert X+Y;
- reset defaults.

### Mouse
- low/high DPI representative devices;
- slow 1-pixel/small delta movement;
- fast swipe;
- repeated equal delta samples;
- 30/60/120+ FPS;
- representative low/high polling rates where test environment permits;
- horizontal/vertical sensitivity extremes;
- inversion combinations;
- controller→mouse→controller switching.

Expected: no game-added acceleration/smoothing, no stick dead zone/curve, no extra delta-time scaling.

### Keyboard/digital
- digital look left/right/up/down;
- diagonal digital look;
- remapped digital camera controls;
- play representative camera-required scenario without analog mouse input.

### Camera states
Test manual look/input processing in:
- exploration;
- soft yaw follow;
- manual recenter cancellation;
- collision compression;
- Close Quarters;
- low ceiling;
- Vertical Context Assist;
- ordinary lock nudge;
- target-switch context;
- boss profile;
- jump/fall;
- mantle/hang;
- shake active/off.

### Target switching
- controller mapping prototype with separate switch semantic;
- keyboard/mouse explicit directional switching;
- no arbitrary mouse movement triggers switch;
- stick drift triggers neither look outside dead zone nor switch;
- any experimental shared-axis scheme proves mutual exclusivity before consideration.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
Enhanced Input provides the implementation primitives required for deliberate device-specific processing:
- semantic Input Actions;
- dynamic/prioritized Input Mapping Contexts;
- runtime remapping support;
- radial dead zones;
- scalar modifiers;
- inversion/negation;
- exponential/user response curves;
- smoothing modifiers;
- an explicit `ScaleByDeltaTime` modifier;
- custom modifiers with access to delta time/player settings;
- triggers/chorded/blocker behavior;
- platform-specific mapping redirection.

References:
- https://dev.epicgames.com/documentation/unreal-engine/enhanced-input-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/EnhancedInput
- https://dev.epicgames.com/documentation/unreal-engine/input-overview-in-unreal-engine
- https://dev.epicgames.com/documentation/en-us/unreal-engine/BlueprintAPI/Input/SetControllerDeadZones

The presence of smoothing, response curves, and delta-time scaling as separate tools is important: Stillring deliberately applies different subsets to stick versus mouse instead of using one generic axis pipeline.

### Accessibility guidance
Current Microsoft accessibility metadata/guidelines explicitly support:
- individual adjustable sensitivity for analog controls and mouse movement;
- at least meaningful increase/decrease around default;
- in-game remapping rather than platform remapping alone;
- independent X/Y inversion for sticks;
- updated prompts/controller maps after remapping;
- digital alternatives and broader input accessibility.

References:
- https://learn.microsoft.com/en-us/gaming/game-publishing/concepts/metadata-accessibility
- https://learn.microsoft.com/en-us/xbox/accessibility/accessibility-feature-tags
- https://learn.microsoft.com/en-us/xbox/accessibility/xbox-accessibility-guidelines/107

These are accessibility design evidence, not a requirement to copy Xbox menu presentation or exact values.

### Stillring authority
Decision #12 requires `SwitchTarget2D` and manual composition nudge to remain separate semantic actions. Decision #17 turns that into a device-mapping constraint without guessing the final button layout before combat/tools/inventory are specified.

### IP boundary
Under `docs/05_IP_GUARDRAILS.md`, Stillring copies no exact sensitivity values, response curves, button layouts, target-switch bindings, acceleration formulas, or UI from another game.

---

## Why this package is approved
The package is intentionally conservative where premature certainty would cause later control-map debt:
- it fully locks how controller and mouse should **feel/process**;
- it locks remapping/accessibility/device parity;
- it locks the semantic separation needed by camera/targeting;
- it does **not** steal physical buttons from future combat/tool systems before those actions are researched.

This preserves methodical system design while preventing Unreal/template defaults from silently defining camera input.

---

## Player-facing acceptance
Decision #17 passes when:
1. controller look is smooth, predictable, radial-dead-zone processed, precision-friendly, and frame-rate independent;
2. holding a controller stick at one magnitude does not accelerate over time by default;
3. mouse feels immediate and does not inherit controller dead zones/curves/smoothing;
4. equal mouse delta maps consistently without extra frame-delta multiplication;
5. horizontal/vertical sensitivity are independently adjustable for controller and mouse;
6. X/Y inversion is independently available;
7. right-stick dead zone is player-adjustable within safe bounds;
8. camera sensitivity does not secretly alter automatic assist strength/timing;
9. controller and mouse settings remain separate when devices are switched mid-session;
10. essential camera/targeting actions are remappable and prompts reflect remaps;
11. target switching remains a distinct semantic action and arbitrary mouse/look input never silently becomes a switch;
12. the final global control map cannot resolve switch-vs-nudge by an undocumented ambiguous threshold;
13. camera input behavior remains consistent across 30/60/120+ FPS;
14. the System IDE can explain raw input, every processing stage, effective player settings, mapping contexts, semantic action, and final camera request.

---

## Next decision
**Camera Decision #18 — aim / first-person / gyro behavior if later proposed.**

Research it independently. Decision #18 must first establish whether Gate 1 has any demonstrated gameplay verb that actually requires a new camera grammar. Do not add an aim/first-person/gyro mode merely because Unreal/platform hardware can support one.
# 35 — Gate 1 Camera Aim / First-Person / Gyro Boundary Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL — EXPLICIT DEFER  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #18 for Issue #2. This file closes the final Gate 1 camera policy decision without inventing a camera mode that current gameplay does not require.

## Authority
Camera Decision #18 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass against the current roadmap and Unreal Engine 5.8 capabilities.

Decision #18 asks whether Gate 1 should add a generic precision-aim camera, first-person toggle, or gyro/motion-aim grammar merely because those technologies are available.

The answer is **no**.

Camera goal:
> **The player should look at Orra, not babysit the camera.**

---

## Camera Decision #18 — aim / first-person / gyro boundary — LOCKED

### Core philosophy
A new camera grammar must be justified by a real player verb.

> **No verb, no camera mode.**

Gate 1 has no approved player action that requires a precision shoulder-aim camera, first-person camera, or gyro aiming. Those modes are therefore deliberately **not part of Gate 1**.

This is a resolved scope decision, not an unresolved TODO.

---

## 1. Gate 1 remains third-person

Gate 1 camera authority remains the third-person grammar defined by Decisions #1–#17.

Gate 1 does **not** add:
- a generic first-person toggle;
- automatic first-person when entering cramped spaces;
- a shoulder-aim mode;
- an over-the-shoulder precision reticle mode;
- a generic free-aim mode;
- a camera mode whose only purpose is inspecting scenery more closely;
- motion-sensor/gyro aiming as a required control path;
- a “just in case” aim camera for later tools.

Decision #7 already forbids automatic first-person as a cramped-room fallback. Decision #18 makes the broader product boundary explicit.

---

## 2. Current roadmap does not justify precision aim

The approved roadmap establishes:
- Gate 1: third-person locomotion, exploration camera, camera collision, target lock, traversal, interaction;
- Gate 2: player light/heavy melee, guard, evade, hit reactions, melee/ranged/shield **enemies**, lock-on switching;
- Gate 3: first prototype of the Cantor Key and one multi-use field tool.

There is currently no approved Gate 1 player verb whose success requires:
- pixel/reticle precision;
- weapon sight alignment;
- first-person inspection;
- motion-sensor fine aiming;
- a dedicated shoulder offset.

A ranged enemy in Gate 2 is not evidence that Neris needs a ranged aim camera.

The existence of a future field tool is also not enough: its traversal/combat/puzzle uses have not yet been individually designed.

---

## 3. Engine capability is not design authority

Unreal Engine 5.8 can support:
- first-person templates and first-person camera viewpoints;
- first-person-specific rendering/FOV/scaling for arms/weapons;
- multiple camera rigs;
- Aim-At camera actions targeting actors/bones/sockets;
- camera blending and custom gameplay camera systems;
- Enhanced Input mappings for additional aim controls.

Stillring deliberately does not enable a new player camera grammar merely because implementation is possible.

Every additional mode would expand:
- control mapping;
- camera collision;
- animation requirements;
- character rendering;
- FOV tuning;
- reticle/UI;
- target lock interaction;
- accessibility settings;
- device parity;
- System IDE state;
- QA/test matrix;
- encounter/tool authoring assumptions.

That integration cost must be earned by gameplay value.

---

## 4. Future precision-aim verb must open its own decision

If a future tool, weapon, puzzle interaction, or traversal capability genuinely requires precision pointing, its design pass must first state the exact player problem.

Before any aim camera becomes production authority, the tool/action specification must answer at minimum:
- what the player is aiming at;
- why ordinary third-person camera + target lock is insufficient;
- whether aiming is hold/toggle/other semantic action;
- whether Neris may move while aiming and at what locomotion authority;
- whether target lock can coexist with aim;
- whether aim uses free direction, soft assist, snap assist, or no assist;
- whether shoulder position changes;
- whether shoulder swapping exists;
- whether FOV changes and why;
- whether a reticle exists and what it means;
- whether aim direction is camera direction, character facing, projectile direction, or another authored relation;
- how camera collision behaves near walls;
- how cramped/low-ceiling states behave;
- how jump/fall/mantle/hang states accept/reject aim;
- controller/mouse sensitivity relationship;
- remapping/accessibility requirements;
- target-switch interaction;
- cancellation/failure behavior;
- System IDE diagnostics/tests.

Only after that verb-specific research may an aim mode be approved.

---

## 5. First-person requires stronger justification than “precision”

A future precision tool does not automatically imply first person.

First-person changes more than camera distance:
- Neris visibility and body awareness;
- world-scale perception;
- close-geometry presentation;
- character mesh/rendering requirements;
- animation/viewmodel treatment;
- shadow/reflection consistency;
- interaction composition;
- motion comfort;
- FOV/settings needs;
- collision and clipping handling;
- transition language between third/first person.

Therefore a future first-person mode requires its **own explicit design justification**, even if an aim mode has already been approved.

### No automatic first-person fallback
First-person may never silently activate because:
- a room is small;
- the camera is compressed;
- a boss is large;
- a puzzle object is close;
- Neris is near a wall;
- a target becomes occluded.

Existing third-person physical camera authority remains responsible for those cases.

---

## 6. Gyro / motion aiming is optional-if-earned, never mandatory

Gate 1 has no gyro requirement.

If a future precision verb justifies motion aiming, gyro should be evaluated as an **optional additional input path**, not as the only viable way to perform the action.

A future gyro decision must consider:
- platform/device availability;
- sensitivity;
- independent inversion where meaningful;
- recenter/calibration;
- motion dead/noise threshold;
- reduction of unintended small motion;
- whether gyro adds to stick/mouse aim or replaces it;
- pause/menu behavior;
- accessibility for players unable to use motion controls;
- remapping/on-off setting;
- device switching;
- test hardware coverage.

No gameplay content may become inaccessible merely because a player's controller/platform lacks motion sensing.

### No hidden gyro camera drift
If gyro is ever added:
- sensor noise may not cause unexplained camera drift;
- motion input must have an explicit active state;
- the System IDE must expose raw/processed sensor input;
- disabling gyro must fully remove its camera contribution.

---

## 7. Mouse/controller parity remains Decision #17

Decision #18 adds no new aim pipeline today.

If a future aim mode is approved:
- mouse must retain native delta behavior;
- controller aim must use reviewed stick processing;
- aim sensitivity may require distinct player preferences from ordinary camera look, but that must be decided explicitly;
- gyro, if used, becomes a third separately processed input source;
- none of those devices may silently share inappropriate dead zones/curves/acceleration.

Decision #17 remains the baseline camera input architecture.

---

## 8. Target lock remains the current combat targeting grammar

Until a future verb says otherwise:
- target lock is the current explicit target relationship mechanism;
- Decision #12 owns switching;
- Decision #11/#14 own target relationship framing;
- Decision #13 prevents secondary enemies from steering ordinary framing;
- no hidden free-aim reticle runs simultaneously “just in case.”

Combat design may later determine whether particular attacks require a target or permit unlocked direction. That is combat authority, not permission to invent a precision camera now.

---

## 9. Tool/puzzle camera honesty

A future puzzle/tool aim mode must preserve Stillring's existing anti-spoiler camera principle.

The camera/aim system may not:
- snap to the correct puzzle solution because metadata identifies it;
- auto-aim at hidden interactables the player has not perceived;
- reveal secret weak points through privileged target scoring;
- use quest relevance to steer a precision reticle;
- turn camera assist into solution assistance without explicit accessibility/design authority.

The camera may help execute an intention the player already formed; it may not form the answer for them.

---

## 10. System IDE boundary

Because Gate 1 has no aim/first-person/gyro mode, the Camera / Targeting IDE should show the boundary explicitly rather than carrying fake dormant systems.

At minimum expose:
- `PrecisionAimMode = NotPresent_Gate1`;
- `FirstPersonGameplayMode = NotPresent_Gate1`;
- `GyroAim = NotPresent_Gate1`;
- current active third-person camera mode;
- current target-lock state;
- references to Decision #18 boundary.

### Validation checks
At minimum detect:
- a generic aim Input Action/routine becoming active without approved verb authority;
- first-person camera activation in normal gameplay;
- automatic first-person fallback from Close Quarters or collision compression;
- gyro/motion sensor contribution affecting camera without explicit future approval;
- hidden reticle/aim-assist scoring influencing target/camera state;
- future tool code directly changing FOV/shoulder/camera mode without an approved camera contract.

This turns “defer” into an enforceable production boundary rather than a note people forget.

---

## Representative Gate 1 verification

Verify:
- full Gate 1 movement/camera course without any first-person transition;
- severe Close Quarters compression remains third-person;
- low-ceiling traversal remains third-person;
- boss profile remains third-person;
- target lock/switch requires no precision aim mode;
- mouse/controller camera behavior works without an aim context;
- no gyro/motion input changes camera behavior;
- no hidden aim reticle appears;
- no dormant first-person rendering path is required for Gate 1 package success;
- Camera IDE reports the three deferred modes as intentionally absent.

---

## Research basis / design lineage

### Repository authority
`ROADMAP.md` establishes the actual gate sequence:
- Gate 1 does not contain a player precision/ranged aim verb;
- Gate 2 introduces melee player combat and a ranged **enemy**;
- Gate 3 is the first multi-use field-tool prototype.

Decision #18 therefore follows actual gameplay need rather than anticipating an unresearched tool.

### Unreal Engine 5.8 primary references
Unreal clearly has the technical capability for these modes:
- First Person Template provides first-person character/camera examples;
- native First Person Rendering provides separate first-person primitive FOV/scaling and clipping-oriented rendering support;
- Gameplay Cameras exposes `UAimAtCameraAction` / `UAimAtActorCameraAction` and multiple rig architectures;
- camera managers/components can blend/manage distinct viewpoints.

References:
- https://dev.epicgames.com/documentation/unreal-engine/first-person-template-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/first-person-rendering
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayCameras
- https://dev.epicgames.com/documentation/unreal-engine/cameras-in-unreal-engine

This evidence supports the boundary: implementation capability is abundant, so absence is a deliberate product decision rather than an engine limitation.

### Motion-input accessibility problem study
Modern titles/platform guidance demonstrate that motion aiming can be an adjustable optional input surface with sensitivity/noise controls. Stillring retains only the abstract lesson that if gyro is ever added it should be optional, configurable, and not a content gate. No exact control scheme or values are copied.

### IP boundary
Under `docs/05_IP_GUARDRAILS.md`, Stillring does not add first-person/aim/gyro merely to imitate Zelda or another action adventure, and it will not copy another game's exact camera transition, shoulder offset, reticle, gyro tuning, aim assist, or input map if a future verb earns the feature.

---

## Why this package is approved
Decision #18 is a scope-discipline decision grounded in current canon:
- there is no demonstrated Gate 1 verb requiring a new camera grammar;
- existing third-person camera authority already solves movement, targeting, scale, physical constraints, and accessibility;
- adding dormant modes now multiplies integration/QA/control-map cost;
- the correct time to design precision camera behavior is when the actual tool/action can define what precision means.

The strongest camera system is not the one with the most modes. It is the one where every mode has a job.

---

## Player-facing acceptance
Decision #18 passes when:
1. Gate 1 contains no generic first-person toggle;
2. Gate 1 contains no generic shoulder/precision-aim mode;
3. Gate 1 contains no mandatory or hidden gyro camera contribution;
4. cramped/low-ceiling/boss states never force first person;
5. target lock/switch remains the active targeting grammar without hidden free-aim state;
6. no dormant camera mode reserves controls/FOV/reticle assumptions for an unresearched future tool;
7. future tool/weapon/puzzle code cannot introduce an aim camera without a verb-specific design contract;
8. any future gyro path must be optional/configurable and not required for content access;
9. the Camera IDE can prove the deferred modes are intentionally absent;
10. the camera system is considered complete for Gate 1 without these modes.

---

## Gate 1 Camera Decision Sequence — CLOSED

Camera Decisions #1–#18 are now individually resolved.

Decision #18 outcome:
> **DEFER generic aim / first-person / gyro until a concrete later gameplay verb earns a separate camera contract.**

Next project work should reconcile/close Issue #2, update the project handoff/decision register, then select the next system from the actual roadmap and begin its first meaningful decision with a fresh research pass.
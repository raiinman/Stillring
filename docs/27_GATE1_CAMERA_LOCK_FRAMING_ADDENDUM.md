# 27 — Gate 1 Camera Lock-Framing Addendum

**Status:** FINAL OWNER APPROVED  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #11 for Issue #2. This addendum extends the cumulative authority in `docs/22_GATE1_CAMERA_SPECIFICATION.md` until the next reconciliation pass folds it into that file.

## Authority
Camera Decision #11 is locked. Claude may not replace this behavior with target-dead-center framing, permanent over-the-shoulder composition, unlimited combat zoom-out, separation-driven FOV pumping, auto-spacing, or any other unstated lock-on framing policy.

Stillring's governing camera goal remains:

> **The player should look at Orra, not babysit the camera.**

The governing movement principle remains:

> **Simple intention, capable character, honest world.**

---

## Camera Decision #11 — lock-on framing distance / offset philosophy — LOCKED

### Core rule
Established ordinary lock-on uses a **dual-subject Relationship Frame**.

The camera frames three things together:
1. Neris;
2. the locked target;
3. the meaningful combat space between them.

The camera does not treat the enemy reticle as the sole composition subject.

Philosophy:
> **Frame the relationship, not the reticle.**

Practical test:
> **Show Neris. Show the threat. Show the space between them.**

### Pair framing rather than hard centering
- Neris and the locked target are treated as a relationship pair for ordinary combat framing;
- the target is not rigidly pinned to screen center;
- both subjects receive tuning-defined screen-space ideal/dead/soft/hard regions;
- small motion inside approved dead zones does not move the camera;
- meaningful motion into soft zones produces damped correction;
- approaching hard readability boundaries permits stronger correction;
- exact screen-space anchors, weights, zone dimensions, damping, and hysteresis remain Gate 1 tuning.

The purpose is stable readability without forcing the camera to chase every small target motion.

### Neris remains readable
- Neris remains clearly readable in the lower portion of the frame during ordinary lock-on;
- target framing may not reduce Neris to an unusable silhouette or hide her immediate footing/movement relationship;
- the target normally occupies a stable upper/central relationship region rather than being hard-centered behind Neris;
- vertical separation may carry much of the composition work where useful;
- exact Neris/target screen placement remains tuning.

### No permanent shooter shoulder
Stillring does not establish a permanent left- or right-shoulder combat camera for ordinary lock-on.

- horizontal pair composition is symmetric and continuity-biased;
- modest lateral separation is allowed when it improves silhouettes/readability;
- the camera does not repeatedly flip sides because Neris crosses a mathematical angle;
- no automatic shoulder swap is part of ordinary lock-on framing;
- later explicit aim/first-person behavior remains Decision #18 authority.

### Canonical combat distance
Ordinary lock-on has a tuning-defined **canonical medium combat distance** broadly related to Stillring's exploration framing rather than becoming a dramatically tighter or tactical-distant camera by default.

The exact value remains Gate 1 tuning.

### Separation-driven dolly — bounded and restrained
The camera may adapt its physical distance modestly when the world-space Neris↔target separation changes enough to threaten pair readability.

- small separation changes stay inside a distance dead band and cause no camera movement;
- sustained meaningful separation beyond the comfort band may ease the camera outward;
- closing distance may ease the camera back toward canonical combat distance;
- dolly is capped by tuning-defined minimum/maximum combat framing distances;
- inward/outward changes use hysteresis/damping so dodges, backsteps, attack recoil, or small spacing oscillations do not create visible breathing;
- collision safety can further limit the resolved distance under Decisions #5/#7/#8.

### Camera adaptation is visual only
Separation-driven framing never maintains combat spacing for the player.

It does **not**:
- push Neris toward the target;
- pull Neris away from the target;
- move the target;
- auto-orbit Neris around the target;
- preserve a preferred melee range;
- change locomotion speed;
- change dodge distance;
- alter attack reach;
- alter enemy AI spacing.

Player-owned target-relative locomotion remains authoritative.

### No unlimited tactical escape
The camera may not continue backing away indefinitely merely to preserve both subjects.

- maximum ordinary combat framing distance is bounded;
- exceeding the usable relationship envelope is not solved by transforming into a distant tactical camera;
- actual lock validity/range belongs to targeting authority rather than the camera inventing indefinite lock support;
- minimum distance is likewise bounded before Decisions #5/#7 handle physical compression.

### Stable ordinary combat FOV
Ordinary established lock-on uses an essentially stable FOV.

- player↔target separation does not continuously widen/narrow FOV;
- attacks, dodges, backsteps, or ordinary target motion do not trigger lens pulses;
- a small fixed exploration→combat FOV difference may remain Gate 1 tuning only if playtesting shows it materially improves readability;
- once established, ordinary separation framing should use bounded physical dolly and composition before dynamic lens change;
- large-boss presentation remains Decision #14 authority.

### Ordinary vertical target separation
Decision #11 owns normal lock-on framing when an ordinary target is moderately above or below Neris.

- pair framing may smoothly recompose/pitch enough to keep both readable;
- the target may occupy more of the upper/lower safe region rather than being forced to screen center;
- Neris readability and immediate movement context remain protected;
- the camera does not pitch directly at the floor/sky merely to perfectly center the target;
- large/exotic vertical relationships belong to Decision #14 where boss scale materially changes framing.

Decision #9's grounded exploration assist does not drive established combat framing.

### Target animation is not automatically camera-worthy
The relationship frame responds to meaningful world-space relationship change, not every skeletal or cosmetic motion.

- idle breathing, weapon swings, recoil, crouch/pose animation, head motion, or small hops inside the framing dead zone do not cause camera chase;
- substantial target displacement through world space may move the pair frame;
- the chosen target anchor/bounds should represent meaningful combat position rather than a noisy animated bone where possible;
- exact target framing point/bounds remain implementation/tuning.

### Bounded manual composition influence
While locked, the player retains **bounded manual composition nudge** rather than either full exploration free-orbit or a completely dead camera stick/mouse.

- sustained camera input may bias the relationship frame horizontally and/or vertically within tuning-defined limits;
- the nudge may expose a little more adjacent combat space, ground, or vertical context;
- the locked Neris↔target pair must remain inside a hard readability envelope;
- the player may not rotate 180 degrees away from the established locked relationship while remaining in the same ordinary lock camera state;
- releasing the nudge preserves it briefly, then eases toward canonical relationship framing rather than snapping;
- exact input gesture, sensitivity, mouse/controller mapping, and coexistence with target switching remain Decisions #12/#17 authority.

### Physical and occlusion authority
The Relationship Frame expresses an ideal composition; it does not override physical camera legality.

- Decision #5 owns collision compression/recovery;
- Decision #6 owns honest target occlusion and grace/break behavior;
- Decision #7 owns severe Close Quarters presentation;
- Decision #8 owns low-ceiling legality;
- the pair solver does not automatically swing around walls/pillars simply to restore ideal framing;
- if the requested pair frame cannot be satisfied physically, the camera resolves to the nearest valid readable state under those authorities.

### Decision boundaries
Decision #11 owns **one established ordinary locked target**.

It does not define:
- target-switch transition behavior — Decision #12;
- multiple-enemy framing limits — Decision #13;
- large-boss framing — Decision #14;
- jump/fall/mantle camera behavior — Decision #15;
- camera shake/accessibility — Decision #16;
- final sensitivity/inversion/mouse parity — Decision #17;
- aim/first-person/gyro behavior — Decision #18.

### System IDE requirement
The Camera / Targeting IDE must expose at minimum:
- active relationship-frame mode;
- Neris framing anchor/bounds;
- target framing anchor/bounds;
- actual Neris screen position;
- actual target screen position;
- weighted/derived relationship point;
- ideal/dead/soft/hard framing zones drawn on screen;
- world-space Neris↔target separation;
- projected screen-space pair separation;
- canonical combat camera distance;
- requested separation-driven distance;
- resolved legal distance;
- distance dead-band/hysteresis state;
- min/max ordinary combat dolly limits;
- requested/resolved yaw and pitch;
- current FOV and any fixed combat-vs-exploration difference;
- manual composition-nudge input and resolved offset;
- nudge hold/recovery state;
- active #5/#6/#7/#8 constraint ownership;
- plain-language reason when ideal relationship framing cannot be satisfied.

The IDE must make combat-camera movement auditable rather than visually mysterious.

### Representative test cases
The Camera / Targeting workbench must include at minimum:
- ordinary humanoid at close/medium/far separation;
- Neris circling the target;
- target circling Neris;
- rapid forward/back spacing changes;
- tiny spacing oscillations specifically for camera-breathing detection;
- target idle/breath/recoil/weapon animation without world-space movement;
- short ordinary enemy;
- tall ordinary enemy;
- moderate target-above relationship;
- moderate target-below relationship;
- stairs/slopes while locked;
- wall compression behind Neris;
- low ceiling while locked;
- cramped corner;
- temporary target occlusion;
- sustained hard occlusion;
- bounded manual nudge left/right/up/down;
- release/recovery from manual nudge;
- #10 acquisition arriving from unusual exploration camera angles;
- second nearby enemy present but not allowed to affect ordinary #11 pair framing;
- large proxy target specifically to prove #14 remains unresolved rather than silently handled here.

### Research basis / boundary
This decision is informed by modern camera systems that support multi-target/group framing, screen-space ideal/dead/soft zones, weighted relationship framing, bounded camera distance, and explicit debugging of target bounds. It is also constrained by Stillring's locked target-relative locomotion rule that player spacing remains player-owned.

Primary references:
- https://dev.epicgames.com/documentation/unreal-engine/unreal-engine-5-8-release-notes
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayCameras/UBaseFramingCameraNode
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayCameras/UAttachToActorGroupCameraNode
- https://docs.unity.cn/Packages/com.unity.cinemachine%406.6/manual/GroupingTargets.html
- https://docs.unity.cn/Packages/com.unity.cinemachine%406.6/manual/CinemachinePositionComposer.html

Research supports relationship framing, dead-zone stability, and bounded distance adaptation. It does not justify copying another game's exact offsets, actor weights, dead-zone size, dolly limits, damping, FOV, or manual-input behavior.

### Player-facing acceptance
Established ordinary lock-on framing passes when:
1. Neris and the target remain simultaneously readable as a relationship;
2. useful combat space between them remains visible;
3. the target is not twitchily hard-centered;
4. tiny target animation/spacing changes do not move the camera;
5. meaningful separation may produce modest smooth dolly without visible accordion behavior;
6. FOV remains stable during ordinary combat spacing changes;
7. camera adaptation never changes gameplay spacing or movement authority;
8. ordinary above/below targets remain readable without extreme pitch;
9. the player can make bounded composition nudges without breaking lock framing;
10. releasing a nudge does not snap the camera;
11. #5/#6/#7/#8 remain authoritative when ideal framing is impossible;
12. nearby secondary enemies do not silently alter #11 framing before #13 is approved;
13. large-boss behavior remains explicitly reserved for #14.

---

## Reconciliation note
`docs/22_GATE1_CAMERA_SPECIFICATION.md` currently contains Decisions #1–#9; Decision #10 is canonical in `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`. This file is canonical authority for Decision #11 until the next reconciliation pass folds Decisions #10 and #11 into cumulative `docs/22` in order and marks them locked there. Perform that reconciliation before treating Camera Decision #12 as repository-final.

## Next owner decision
**Camera Decision #12 — target-switch transition behavior.**

Research it first. Do not infer switch gesture, candidate directionality, transition speed, target confirmation, camera movement, cooldown/debounce, no-candidate behavior, or control conflicts with manual composition nudge from generic action-game conventions.
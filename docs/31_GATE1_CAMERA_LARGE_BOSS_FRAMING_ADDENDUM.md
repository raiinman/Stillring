# 31 — Gate 1 Camera Large-Boss Framing Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #14 for Issue #2. This file extends cumulative camera authority through Decisions #1–#14.

## Authority
Camera Decision #14 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Decision #14 answers how the camera should preserve readable combat when the selected target's physical scale materially exceeds the ordinary target assumptions in Decision #11.

Camera goal:
> **The player should look at Orra, not babysit the camera.**

Decision #11 remains ordinary one-target Relationship Frame authority. Decision #13 remains ordinary multi-enemy boundary. Decision #14 creates a scale-specific framing profile for genuinely large bosses; it does not turn every boss encounter into a cinematic camera mode.

---

## Camera Decision #14 — large-boss framing — LOCKED

### Core philosophy
Large bosses use an authored **Boss Framing Profile** that tells the camera what portion of the creature is meaningful for readable combat.

> **Frame the fightable giant, not the entire poster.**

A huge enemy is not treated as one noisy skeleton point, and the camera is not required to fit the boss's complete silhouette at all times.

### Boss Framing Profile
A boss whose scale materially exceeds ordinary #11 framing must provide reviewed camera-framing data separate from ordinary targetability/hit detection.

The profile may define:
- one or more authored meaningful framing anchors/regions;
- manual camera target bounds/shape representing the combat-readable portion of the boss;
- canonical boss camera-distance envelope;
- minimum/maximum boss framing distance;
- preferred Neris/boss screen-space relationship zones;
- permitted vertical composition/pitch envelope;
- optional phase/action-specific framing anchor changes where justified by visible boss anatomy/action;
- optional fixed boss FOV override only where human play proves physical composition alone is insufficient;
- profile-specific readability assertions and test scenarios.

Exact data representation, class names, and Unreal node choices remain implementation decisions.

### Do not use actor origin or arbitrary bone as policy
The engine may expose actor location, sockets, bones, skeletal bounds, or automatic target shapes. Those are inputs, not game-design authority.

For a large boss:
- actor origin may be underground, centered in an irrelevant volume, or far from the combat-readable anatomy;
- head bones may make the camera look too high and lose Neris/footing;
- root/pelvis bones may produce poor framing for tall or elongated creatures;
- animated bones can create camera jitter if used as raw framing authority;
- generic full-mesh bounds may include tails, wings, weapons, effects, or extremities that should not force constant zoom-out.

The profile therefore chooses stable authored combat framing evidence rather than inheriting whichever transform Unreal happens to expose most conveniently.

### Action-relevant portion, not full silhouette
The camera frames the **action-relevant portion** of a truly large boss.

Examples of valid intent:
- preserve Neris plus the boss's nearby body/action region during grounded melee;
- show enough upper-body/weapon context to read an imminent large attack when that anatomy is physically relevant and visible;
- preserve footing and near-field spacing while a tall boss extends far beyond the top of frame;
- allow an enormous tail/body section to leave frame when forcing it into view would destroy combat readability.

The following are not requirements:
- full head-to-foot visibility at every moment;
- full wing span;
- complete tail/body length;
- all appendages simultaneously visible;
- cinematic silhouette presentation during ordinary player-controlled combat.

A boss may be visually larger than the frame. That is acceptable when the player can still read the current fight.

### Neris and footing remain protected
Boss scale does not demote Neris's readability.

- Neris remains a required framing subject;
- immediate ground/footing and the meaningful Neris↔boss interaction space remain protected;
- the camera does not pitch so high that the player loses basic locomotion/defense context merely to show the boss's head;
- if full boss height and usable player footing cannot coexist, footing/combat relationship wins;
- Decision #6's readability hierarchy remains authoritative.

### Boss distance envelope
Large bosses may use a farther canonical camera-distance envelope than ordinary #11 targets.

Rules:
- boss camera distance is bounded, not unlimited;
- the profile defines a reviewed minimum/maximum envelope appropriate to the encounter scale;
- small boss motion inside the profile's dead/soft zones does not continuously dolly the camera;
- meaningful separation/occupancy pressure may ease distance within the allowed envelope;
- hysteresis/damping prevent giant-target breathing as animation bounds fluctuate;
- the camera may not retreat indefinitely to fit all geometry;
- if the arena cannot support a readable legal camera position inside the profile envelope, the encounter/arena fails camera review rather than demanding infinite zoom-out.

Exact numeric distances remain prototype tuning.

### Stable FOV preferred
Physical composition and bounded dolly are preferred over dynamic FOV pumping.

- ordinary boss combat should keep FOV stable enough that spacing remains perceptually trustworthy;
- target animation or separation does not continuously widen/narrow lens angle;
- a modest **fixed** boss-profile FOV difference may be approved as tuning if human play demonstrates that legal physical dolly cannot preserve combat readability without excessive distance;
- any fixed boss FOV difference must transition smoothly on entry/exit and remain constant during ordinary established boss combat;
- dramatic action-by-action FOV pulses are not part of Decision #14;
- exact FOV, if any, remains playtest tuning.

### Authored anchor/region changes
A boss profile may expose multiple authored framing anchors/regions, but camera ownership remains strict.

An anchor/region change is permitted only when:
- the boss's **visible** combat anatomy or action-relevant region materially changes;
- the change corresponds to an understandable physical/action state the player can perceive;
- the new anchor improves readable player↔boss relationship framing;
- the transition is continuity-biased and bounded.

Examples may include:
- a towering boss lowering into a grounded vulnerable stance;
- a long creature turning so a different combat body region becomes the nearby active threat;
- an airborne phase where the meaningful visible combat region changes height materially.

The camera may not use:
- hidden future attack selection;
- puzzle-solution metadata;
- secret vulnerability metadata not visually expressed;
- internal boss AI intent unknown to the player;
- treasure/quest objectives;
- invisible “look here” markers whose only purpose is revealing the answer.

This preserves the same honesty rule established by Camera Decision #9.

### Anchor transitions are not cinematic cuts
When the active boss framing region changes:
- camera response is smooth, bounded, and begins from the exact current physically resolved pose;
- no hard cut;
- no forced orbit flourish;
- no gameplay freeze/slowdown;
- no automatic cinematic recenter;
- no dramatic lens pulse simply because a phase changed.

A new profile region changes the desired Relationship Frame; normal physical camera constraints remain authoritative.

### Boss movement and animation filtering
Large boss animation can move large mesh bounds dramatically without meaningful world-space combat relocation.

Therefore:
- noisy animated extremities do not directly drive camera distance;
- temporary weapon swings/wings/tails leaving the authored region do not force the camera outward;
- framing responds to reviewed boss-region position/bounds and meaningful world-space relationship change;
- authored bounds must avoid accidental per-frame growth/shrink from animation that causes camera breathing;
- if a phase intentionally changes effective combat scale, the profile may change through an explicit reviewed state transition.

### Target identity versus target region
Decision #14 does **not** automatically create multiple lockable body parts.

- a boss remains one target identity unless later targeting/combat authority explicitly defines separate lockable parts;
- a camera framing region is not automatically a damage target, lock target, weak point, or gameplay interaction target;
- changing the active camera region does not silently change target identity;
- Decision #12 target switching continues to operate on legal target identities, not camera-only anchors.

This prevents camera authoring data from becoming a hidden gameplay rules engine.

### Multiple enemies remain separate
A large boss does not authorize group framing of ordinary secondary enemies.

- #13 remains authoritative;
- boss profile framing covers Neris + selected large target only;
- adds/minions may naturally appear in frame but do not influence camera distance/FOV/yaw/pitch by default;
- switching to an ordinary enemy uses #12 and returns to the appropriate ordinary #11 framing unless another explicit profile applies.

### Physical/occlusion authority
Boss framing expresses an ideal composition only.

Decisions #5/#6/#7/#8 remain authoritative:
- collision may compress the camera;
- hard world geometry remains honest;
- Close Quarters handles severe compression;
- Ceiling-Constrained Camera handles overhead legality;
- the boss profile may not clip through walls or dissolve meaningful cover to show the boss;
- the camera does not orbit around architecture merely to reveal the full boss silhouette.

### Arena-design obligation
Large-boss arenas must be authored with the valid camera envelope as a gameplay requirement.

Review must consider:
- rear-wall clearance;
- side-wall/corner pressure;
- ceiling/overhang clearance;
- slopes/elevation changes;
- boss approach to arena edge;
- Neris fighting between boss and wall;
- boss crossing near camera boundaries;
- phase changes at awkward arena positions;
- representative minion/add presence without granting them camera authority.

If ordinary intended combat repeatedly forces unusable severe compression or impossible framing, the arena/boss staging is wrong. The camera is not required to rescue it with tactical zoom-out or cinematic cuts.

---

## Accessibility boundary
Large bosses can amplify motion sickness if camera pitch/distance/FOV constantly reacts to giant animation.

Decision #14 therefore requires:
- bounded camera motion;
- dead/soft zones around authored boss regions;
- stable ordinary FOV;
- no automatic spectacle orbit;
- no requirement to track every extremity;
- no critical boss attack information communicated solely through camera motion or shake.

Later Camera Decision #16 owns camera shake/motion intensity controls. Decision #17 owns sensitivity/input settings.

---

## Camera / Targeting System IDE requirements

The workbench must expose the Boss Framing Profile as first-class inspectable authority.

At minimum show:
- active target identity;
- ordinary vs Boss Framing Profile mode;
- profile asset/record/stable ID;
- active authored framing anchor/region;
- reason that region is active;
- source actor/socket/bone/manual bounds where applicable;
- target shape/manual bounds visualization;
- canonical boss distance;
- requested boss distance;
- profile min/max distance envelope;
- actual/resolved legal camera distance;
- Neris screen-space position;
- active boss-region screen-space position/occupancy;
- ideal/dead/soft/hard zones for both subjects;
- requested/resolved yaw/pitch;
- current FOV and whether a fixed profile FOV override is active;
- profile transition state/progress;
- active boss phase/action tag only where it legitimately selects visible framing data;
- raw full-mesh bounds compared with authored camera bounds for diagnosis;
- active #5/#6/#7/#8 constraint ownership;
- reason ideal profile framing cannot be satisfied;
- unreadable-frame warnings/assertions.

### Validation checks
At minimum detect:
- boss profile missing for a target marked large-scale;
- actor origin/root bone being used accidentally when authored profile is required;
- manual bounds invalid/zero/extreme;
- profile distance envelope inverted or unbounded;
- frame requiring persistent camera placement outside arena legal space;
- FOV dynamically driven by animation/separation despite fixed-profile rule;
- camera region sourced from hidden puzzle/attack metadata;
- camera anchor accidentally treated as a gameplay target identity;
- animated full-mesh bounds causing camera-distance churn;
- profile transition producing a hard cut/snap;
- Neris/footing readability falling outside approved hard region.

---

## Representative test matrix

### Boss body forms
- tall humanoid boss;
- wide quadruped;
- long/serpentine body crossing frame;
- boss with large wings or weapon reach;
- boss whose actor origin is physically poor for framing;
- boss whose head bone moves heavily during animation;
- truly enormous target whose complete body cannot fit while preserving Neris.

### Relationship / position
- close/medium/far Neris↔boss separation;
- Neris directly beneath/tight to tall boss;
- boss significantly above Neris;
- boss below Neris on terrain;
- Neris circling boss;
- boss circling/crossing Neris;
- boss rapidly closes distance;
- boss backs to arena edge;
- Neris between boss and rear wall.

### Profile/phase transitions
- ordinary grounded region → lowered/vulnerable region;
- grounded → airborne meaningful region;
- profile anchor change while camera is already collision-compressed;
- anchor change under low ceiling/overhang;
- rapid animation with no profile change proving no camera breathing;
- phase change while boss is near wall/corner;
- invalid/missing profile data produces explicit diagnostic rather than fallback policy.

### FOV/distance
- boss occupancy pressure inside distance dead zone;
- movement across soft/hard occupancy bounds;
- max boss distance reached while full silhouette still cannot fit;
- fixed boss FOV override enabled/disabled prototype comparison;
- repeated attack animation proves FOV does not pulse;
- transition ordinary target → boss → ordinary target.

### Authority boundaries
- boss + minions present; minions do not affect profile framing;
- switch from boss to minion and back;
- hard wall occludes boss region;
- severe camera compression invokes #7;
- low ceiling invokes #8;
- temporary target occlusion follows #6;
- camera-only anchor never appears as targetable gameplay identity.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
Unreal Gameplay Cameras exposes camera-target information with exactly the kinds of primitives needed to implement an authored boss profile without making them design authority:
- `FCameraActorTargetInfo` can identify an actor, optional socket/bone, target shape, manual target size/bounds, and weighting;
- `UBaseFramingCameraNode` can frame one or more target actors using framing zones and target-distance logic;
- UE 5.8 camera updates added screen-space target framing plus projection/unprojection improvements for framing nodes;
- PlayerCameraManager supports blending/arbitration between camera influences rather than requiring hard camera cuts.

References:
- https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/GameplayCameras/FCameraActorTargetInfo
- https://dev.epicgames.com/documentation/unreal-engine/BlueprintAPI/Utilities/Struct/BreakCameraActorTargetInfo
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayCameras/UBaseFramingCameraNode
- https://dev.epicgames.com/documentation/unreal-engine/unreal-engine-5-8-release-notes
- https://dev.epicgames.com/documentation/unreal-engine/cameras-in-unreal-engine

These prove Unreal can represent authored target shapes/anchors and smooth camera composition. They do not determine Stillring's boss framing policy.

### Shipped-game problem study
Large-monster action games demonstrate the general problem: one selected creature may occupy far more screen space than an ordinary humanoid target, and camera readability must balance the player, attack-relevant anatomy, and arena awareness. Stillring uses this only as abstract problem evidence; no exact camera distance, lock point, body-part behavior, control mapping, timing, or UI expression is copied.

### IP boundary
Under `docs/05_IP_GUARDRAILS.md`, Stillring defines its own:
- authored boss camera-region data;
- framing philosophy;
- distance/FOV rules;
- anchor transition semantics;
- IDE diagnostics;
- arena review obligations.

No Zelda or other game's boss camera expression is production authority.

---

## Why this package is approved
Decision #14 extends rather than breaks prior camera rules:
- #11 already frames a relationship rather than a reticle;
- #6 already prioritizes Neris/footing and world honesty;
- #13 prevents secondary enemies from hijacking composition;
- #9 establishes the rule that camera assistance may not use hidden solution metadata;
- the System IDE contract requires authored state and rejection reasons to remain inspectable;
- Unreal 5.8 provides target bounds/anchors/framing primitives without forcing a specific design.

A Boss Framing Profile is therefore the smallest explicit tool that handles giant scale while preserving Stillring's camera ownership and honesty principles.

---

## Player-facing acceptance
Decision #14 passes when:
1. a giant boss remains readable without treating one arbitrary actor point/bone as the entire camera policy;
2. Neris and immediate footing remain usable even when the boss cannot fit completely onscreen;
3. the camera shows the action-relevant boss region rather than endlessly backing away to fit the silhouette;
4. boss camera distance is farther when justified but remains bounded;
5. ordinary boss combat FOV is stable and does not pulse with animation/separation;
6. any fixed boss FOV difference is a reviewed tuning value, not dynamic spectacle;
7. animated extremities/full-mesh bounds do not create camera breathing;
8. authored region changes correspond to visible physical/action changes and transition smoothly;
9. hidden future attack/puzzle/weak-point metadata never steers the camera;
10. camera framing anchors do not silently become gameplay target identities;
11. minions/secondaries still obey #13;
12. collision/occlusion/cramped/ceiling authority remains #5/#6/#7/#8;
13. boss arenas that cannot support the valid profile envelope fail camera/level review rather than forcing camera hacks;
14. the Camera IDE can explain the active profile, region, distance, FOV, physical constraint, and any unreadable state.

---

## Next decision
**Camera Decision #15 — camera behavior during jump / fall / mantle.**

Research it independently. Do not infer airborne follow, jump dead zones, falling/landing composition, mantle pivot behavior, ledge/hang camera, or lock-on airborne interaction from grounded Vertical Context Assist or boss framing.
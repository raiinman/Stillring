# 26 — Gate 1 Camera Lock-Acquisition Addendum

**Status:** FINAL OWNER APPROVED  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #10 for Issue #2. This addendum extends the cumulative authority in `docs/22_GATE1_CAMERA_SPECIFICATION.md` until the next reconciliation pass folds it into that file.

## Authority
Camera Decision #10 is locked. Claude may not replace this behavior with stock Unreal target selection, nearest-enemy lock, a hard camera snap, an intermediate recenter, a cinematic micro-cutscene, automatic retargeting, or any other unstated lock-on acquisition policy.

Stillring's governing camera goal remains:

> **The player should look at Orra, not babysit the camera.**

The governing movement principle remains:

> **Simple intention, capable character, honest world.**

---

## Camera Decision #10 — lock-on acquisition transition — LOCKED

### Core rule
Stillring uses **immediate target commitment with deliberate camera convergence**.

When the player requests lock-on from exploration, the game performs one immediate acquisition evaluation. If a valid target wins, target identity and target-relative locomotion become authoritative immediately while the camera performs one fast, eased transition from its exact current pose toward the later-defined valid lock-on composition.

Target selection, locomotion-state commitment, and camera convergence are coordinated, but they are not the same operation and do not wait on one another unnecessarily.

Philosophy:
> **Lock the target instantly. Move the camera deliberately.**

### Single acquisition snapshot
A lock request evaluates the current candidate set once.

- the request does not enter a fuzzy multi-frame searching state;
- the camera does not begin wandering before a winner exists;
- the system does not keep an unfulfilled request alive waiting for a future enemy to enter range;
- pressing lock again after a failure performs a fresh evaluation;
- once a winner is committed, the system does not silently reconsider the initial ranking because another candidate becomes marginally better a moment later.

Exact implementation may be task/pipeline based, but the player-facing result must behave as one immediate acquisition decision.

### Candidate resolution order
Candidate resolution follows this semantic order:

1. **eligibility** — target must be alive/valid/targetable and otherwise legal for initial acquisition;
2. **honest visibility** — initial acquisition requires valid line of sight according to the approved target-lock trace/visibility rules;
3. **camera/view intent** — candidates nearer the player's current camera-forward / screen-space intention are strongly preferred;
4. **distance** — distance may refine ranking after view intent rather than replacing it;
5. **deterministic tie-break** — near-equal candidates must resolve stably rather than flickering nondeterministically.

Exact acquisition cone/envelope, score weights, near-edge forgiveness, distance weighting, trace origin, target point, and tie-break implementation remain Gate 1 tuning/engineering.

### Camera intent beats character facing
The player's current view is the primary expression of target intent during exploration.

- Neris may face or move one direction while the player deliberately looks another;
- if the camera clearly frames an eligible enemy and Neris's body faces elsewhere, the camera-view candidate normally wins;
- closest-to-Neris alone is not a sufficient acquisition policy;
- character facing may contribute only as a subordinate/tie-breaking signal where useful;
- the system should not select an enemy directly behind the player merely because it is physically closer when the player's view clearly communicates a different intent.

This preserves the value of Stillring's already-approved player-owned exploration camera at the exact moment the player requests combat focus.

### No surprise behind-the-player lock
Initial acquisition has a bounded view-intent envelope.

- a candidate requiring an extreme camera reversal is not a normal initial lock target;
- an enemy directly behind the current view does not trigger a surprise 180-degree camera whip merely because no better candidate exists;
- a small tuning-defined screen-edge/near-edge forgiveness region is permitted;
- the acquisition envelope must not become an invisible full-sphere nearest-enemy search.

Exact angular limits remain tuning and must be tested against ordinary encounters.

### Initial visibility requirement
Initial lock requires **honest current visibility**.

- a target behind meaningful hard cover is not initially acquired through the wall;
- a visible off-center candidate may therefore beat a mathematically better-scoring hidden candidate;
- decorative fade eligibility from Decision #6 does not create supernatural initial target visibility;
- after a target has successfully committed, temporary later occlusion follows Decision #6's established-lock grace rules.

The semantic distinction is explicit: initial acquisition requires visible legitimacy; established lock may survive brief honest occlusion under Decision #6.

### Immediate lock commitment
Once a winning candidate is found, the lock commits immediately rather than waiting for camera convergence.

On commit:
- target identity becomes authoritative;
- the lock-confirmation presentation identifies the chosen target immediately;
- target-relative locomotion becomes authoritative according to `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`;
- active exploration Sprint ends immediately as a locomotion state;
- existing physical Sprint velocity resolves through the already-approved short natural deceleration/pivot into target-relative locomotion rather than hard-zeroing;
- Neris's target-relative facing/movement settles through locomotion authority, not because the camera forcibly rotates the character.

The UI may not claim a lock while movement remains secretly exploration-relative waiting for the camera animation to finish.

### Camera begins from the exact current pose
The acquisition transition starts from the actual valid exploration camera pose at commit time.

There is no hidden intermediate recenter.

Stillring does **not** perform:

`current exploration view → behind Neris → lock camera`

It performs:

`current valid view → valid lock-on composition`

Decision #11 owns the final lock-on framing distance/offset philosophy. Decision #10 owns only how the camera enters whatever later-approved #11 composition is valid.

### Fast eased camera convergence
The camera uses one **fast, bounded, eased transition** toward the target-lock composition.

- the transition is not an instantaneous hard snap;
- it is not a slow cinematic pan;
- larger legal corrections may take modestly longer than tiny corrections, but remain strongly bounded and responsive;
- the target is already locked while convergence occurs;
- exact duration, easing curve, angular speed/acceleration limits, and distance interpolation remain Gate 1 tuning;
- acquisition rules should prevent extreme corrections rather than relying on a long blend to hide an inappropriate target choice.

### No cinematic acquisition behavior
Ordinary lock-on acquisition does **not**:
- slow time;
- freeze Neris;
- pause movement or combat input;
- play a camera cut;
- orbit cinematically around Neris or the target;
- apply a dramatic FOV punch;
- perform a dramatic automatic zoom as confirmation;
- force Neris to complete a facing animation before control continues.

The lock request changes combat focus, not gameplay continuity.

### Camera-input authority boundary
Before a valid target commits, ordinary exploration camera authority remains unchanged.

After target commit, target-lock camera grammar begins immediately. Ordinary exploration free-look rules no longer define whether the acquisition blend continues.

The acquisition transition therefore continues unless:
- the player explicitly cancels lock;
- the target becomes invalid under the approved lock rules;
- a higher-priority gameplay/traversal state invalidates lock.

What right-stick/mouse camera input does **while an established lock is active** is intentionally not defined here. Final lock-on camera control influence and framing belong to Decision #11; target switching belongs to Decision #12.

### No-target failure
If no valid candidate exists, the lock request fails with **no gameplay or camera side effects**.

- lock does not activate;
- exploration locomotion remains exploration locomotion;
- active Sprint is not canceled by a failed request;
- camera yaw/pitch/distance do not change;
- the camera does not recenter;
- the system does not acquire a hidden/offscreen fallback target;
- no pending search state waits for an enemy to appear.

The player receives a brief unobtrusive no-target acknowledgement so the input does not feel broken. Exact audio/UI/haptic presentation remains tuning/accessibility work.

### No silent retarget after commit
Once candidate A wins and commits, A remains the target unless later explicit target-switch/break rules say otherwise.

- a candidate becoming slightly more favorable during camera convergence does not steal the lock;
- the initial target dying or invalidating does not silently cause candidate B to replace it;
- intentional switching belongs to Decision #12.

This prevents acquisition flicker and preserves clear player causality.

### Target invalidation during convergence
Once the target has committed, Decision #6 applies to visibility loss.

#### Temporary line-of-sight loss
A brief LOS interruption enters the already-approved occluded grace behavior. The camera does not panic, switch targets, or force itself around architecture.

#### Hard invalidation
If the target dies, despawns, becomes fundamentally untargetable, exits hard validity, or another approved rule invalidates lock during convergence:
- abort the lock cleanly;
- do not silently acquire the next-ranked target;
- transition from the camera's current pose toward valid exploration behavior without a snap;
- target-relative locomotion exits according to the existing movement/lock transition authority;
- a subsequent player lock request performs a fresh acquisition evaluation.

### Explicit cancel during convergence
If the player explicitly cancels lock during acquisition convergence:
- the target lock ends immediately;
- the transition retargets smoothly from the camera's current pose toward the valid exploration camera state;
- camera motion does not finish the obsolete lock transition first;
- target-relative locomotion exits according to the existing locomotion authority;
- cancellation never requires the camera to pass through the originally requested final lock pose.

Exact exit blending is tuning unless a later camera decision adds stronger policy.

### Physical camera authority during acquisition
Decision #10 never overrides established physical camera legality.

During acquisition/convergence:
- Decision #5 controls collision compression and recovery;
- Decision #7 controls severe close-quarters presentation;
- Decision #8 controls low-ceiling legality;
- Decision #6 controls world/target occlusion honesty.

The mathematically ideal target-lock pose may be physically unavailable. The camera must resolve to the nearest valid presentation under those authorities rather than clipping through geometry or dissolving meaningful cover.

### Higher-priority locomotion/traversal boundary
Target-lock locomotion already ends when Neris enters incompatible traversal states according to `docs/20`.

Decision #10 does not invent exceptions for hang, ladder, surface swim, committed slide, tool-owned traversal, or other states whose existing authority rejects target-lock locomotion. Camera retention or later special targeting policy for such systems requires explicit later authority rather than being inferred here.

### Immediate target confirmation
The chosen target must be identifiable **at commit time**, not only after the camera finishes moving.

The functional requirement is that the player can immediately tell which candidate won. Exact reticle/icon/art/audio/haptic styling remains UI/accessibility tuning and is not copied from Zelda or another game.

### System IDE requirement
The Camera / Targeting IDE must expose enough live evidence to diagnose target acquisition and transition behavior, including at minimum:
- lock request frame/time;
- acquisition envelope in screen/world space;
- all candidates considered;
- candidate lock point;
- onscreen / near-edge / outside-envelope classification;
- candidate distance;
- camera-forward / screen-space angular error;
- initial LOS result and trace evidence;
- targetability/eligibility result;
- individual candidate score components;
- deterministic ranking/tie-break result;
- exact candidate rejection reason;
- winning candidate;
- lock commit frame;
- current lock target;
- exploration→lock transition state/progress;
- starting camera pose;
- requested target-lock pose;
- current physically resolved pose;
- yaw/pitch/distance correction remaining;
- active collision / Ceiling-Constrained / Close Quarters constraints;
- locomotion mode before/after commit;
- Sprint exit state and remaining deceleration/pivot where relevant;
- occlusion grace state during convergence;
- abort/cancel reason;
- no-target result/acknowledgement.

The workbench must make target choice auditable rather than requiring developers to guess why a particular enemy won.

### Representative test cases
The Gate 1 Camera / Targeting workbench must include at minimum:
- one enemy centered in view;
- centered enemy farther away plus closer enemy near screen edge;
- closest enemy directly behind Neris/current view;
- enemy just inside acquisition edge;
- enemy just outside acquisition edge;
- centered candidate behind hard wall plus visible off-center candidate;
- two nearly identical candidates requiring deterministic tie-break;
- Sprint → lock;
- sideways movement → lock;
- reverse movement → lock;
- stationary Neris looking away from her facing;
- Neris facing one direction, camera looking another, enemy in each direction;
- target above Neris;
- target below Neris;
- low-ceiling acquisition;
- cramped-room acquisition;
- rear-wall camera compression during acquisition;
- target loses LOS during convergence;
- target dies during convergence;
- target becomes untargetable during convergence;
- explicit cancel during convergence;
- no valid targets;
- rapidly repeated lock requests.

For the facing-versus-view test, the camera-view enemy should win when the player's view clearly communicates that intention and both candidates are otherwise valid.

### Research basis / boundary
This decision is informed by:
- Nintendo's historical discussion of Z-targeting as the solution to readable player↔opponent relationships in 3D combat;
- Unreal Engine's Gameplay Targeting System, which separates candidate acquisition, filtering, sorting, and evaluation rather than requiring one nearest-target rule;
- Unreal Engine's Gameplay Cameras system, which supports explicit camera rigs/transitions/blending separate from gameplay target state;
- Stillring's already-locked target-relative locomotion and Sprint→target-lock transition authority.

Primary references:
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/1/2/
- https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-targeting-system-in-unreal-engine
- https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-camera-system-overview

Research supports immediate deterministic commitment plus a deliberate camera blend. It does not justify copying Zelda's exact targeting cone, camera snap, button mapping, lock marker, timings, or another game's target scoring values.

### Player-facing acceptance
Lock-on acquisition passes when:
1. pressing lock on a clearly framed visible enemy selects that enemy predictably;
2. view intent normally beats mere physical closeness;
3. an enemy behind the player does not cause a surprise 180-degree initial lock;
4. hidden hard-cover targets are not initially acquired;
5. target identity and target-relative locomotion commit immediately;
6. Sprint exits through the already-approved natural movement transition;
7. the camera moves once from its actual current pose with a fast eased transition and no intermediate recenter;
8. acquisition does not slow/freeze gameplay or add cinematic camera theatrics;
9. the selected target is identifiable immediately;
10. a failed request causes no camera, locomotion, or Sprint side effects;
11. the system never silently retargets because another candidate becomes better or the chosen target invalidates;
12. temporary post-commit occlusion follows Decision #6 rather than changing targets;
13. hard invalidation/cancel aborts cleanly from the current camera pose;
14. Decisions #5/#7/#8 remain physically authoritative during convergence;
15. final established combat framing remains explicitly reserved for Decision #11 and intentional target switching for Decision #12.

---

## Reconciliation note
`docs/22_GATE1_CAMERA_SPECIFICATION.md` currently contains Decisions #1–#9. This file is canonical authority for Decision #10 until the next reconciliation pass folds this section into `docs/22` and marks item #10 locked there. Do that reconciliation **before** treating Camera Decision #11 as repository-final.

## Next owner decision
**Camera Decision #11 — lock-on framing distance/offset philosophy.**

Research it first. Do not infer final player/target screen placement, camera distance behavior, target-centering strength, vertical separation framing, combat zoom, or player camera influence while locked from Decision #10's acquisition transition.
# 29 — Gate 1 Camera Target-Switch Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #12 for Issue #2. This file extends the cumulative camera authority in `docs/22_GATE1_CAMERA_SPECIFICATION.md` + `docs/28_GATE1_CAMERA_10_11_RECONCILIATION_COMPANION.md`.

## Authority
Camera Decision #12 is locked under the owner's explicit scheduled-run delegation to approve each individually researched decision once its package is complete.

Stillring may not replace this behavior with nearest-enemy cycling, automatic threat retargeting, hidden target roulette, screen-center hard snapping, a shared raw-axis guess that unpredictably converts camera movement into target switching, or another unstated policy.

Camera goal:
> **The player should look at Orra, not babysit the camera.**

Movement principle:
> **Simple intention, capable character, honest world.**

Decision #10 remains acquisition authority. Decision #11 remains established one-target Relationship Frame authority. Decision #12 owns **intentional switching from one established target to another**.

---

## Camera Decision #12 — target-switch transition behavior — LOCKED

### Core philosophy
Target switching is an **explicit directional request inside the current combat relationship**.

> **Switch by intent, not by roulette.**

One deliberate switch request produces at most one new target commitment. The player communicates a direction; the targeting system chooses the best valid candidate in that direction using current screen-space relationship evidence.

### Semantic input first
Target switching is a dedicated **semantic Input Action**, separate from manual composition nudge.

- the gameplay layer receives a discrete directional switch request rather than inferring intent from arbitrary camera movement;
- the switch request may carry a 2D direction vector so left/right and materially vertical target arrangements are representable;
- manual composition nudge remains its own semantic action from Decision #11;
- one physical control may later be mapped to both semantics only if the device-specific mapping makes them mutually exclusive and predictable;
- the final controller/mouse/keyboard binding, sensitivity, remapping presentation, and any device-specific classifier belong to Decision #17;
- Decision #12 therefore does **not** canonize “right-stick flick” as the only control grammar;
- a default mapping must never require players to discover an undocumented magnitude/timing threshold where ordinary camera nudge suddenly changes targets.

This preserves accessibility and prevents mouse micro-movement or strong manual nudge from accidentally becoming combat intent.

### One request, one snapshot, one switch
A switch request samples the current eligible switch-candidate set once.

- no multi-frame searching state waits for a candidate to appear;
- no held request continuously cycles targets;
- no one analog gesture may skip through several enemies;
- after a successful switch, a later deliberate request samples again from the newly committed target;
- repeated digital inputs may switch repeatedly only as repeated distinct actions, not because a cooldown timer is auto-repeating a held input.

The anti-multiskip mechanism is **re-arm/edge gating**, not an arbitrary long post-switch cooldown.

Exact trigger thresholds/debounce needed by a particular input device remain Decision #17 tuning.

### Candidate eligibility
A switch candidate must first satisfy targetability rules independent of directional ranking.

At minimum, a candidate must be:
- alive/valid;
- legally targetable in the current gameplay state;
- within the tuning-defined switch eligibility envelope/range;
- honestly visible for a new switch commitment, subject only to explicit near-edge visibility tolerance;
- not hidden behind meaningful hard cover;
- not the currently locked target.

An already-locked current target may be inside Decision #6 occlusion grace, but that does **not** authorize switching *to* a different target through hard cover.

Exact switch range, LOS trace points, near-edge forgiveness, targetable tags, and eligibility tolerances remain Gate 1 engineering/tuning under this semantic rule.

### Direction is screen-relative to the current target
Directional intent is resolved primarily in **screen space relative to the current locked target's meaningful framing anchor**.

For candidate `C` and current target `T`, the relevant directional evidence is the screen-space vector from `T` to `C`, not simply Neris-facing, world compass direction, or raw distance.

Consequences:
- a left request prefers candidates visually left of the current target;
- a right request prefers candidates visually right of the current target;
- a materially up/down request may select appropriately separated vertical candidates when the active device mapping exposes that semantic direction;
- a candidate on the wrong side may not win merely because it is physically closer;
- world distance refines a valid directional choice but does not override clear screen-space direction;
- the current camera/Relationship Frame is the player's visual combat reference, so switching respects what the player actually sees.

### Directional ranking
After eligibility filtering, candidates are ranked using this semantic priority:

1. **requested-side validity** — candidate must meaningfully agree with the requested direction;
2. **directional angular error** — smaller screen-space angular difference from the requested direction is preferred;
3. **screen-space adjacency to current target** — visually adjacent candidates are preferred over remote leaps where direction is otherwise similar;
4. **world distance / combat relevance envelope** — may refine ranking but not reverse obvious direction;
5. **deterministic tie-break** — near-equal candidates resolve consistently.

Exact scoring formula and weights remain tuning/engineering. The observable ordering above is authority.

### Offscreen / near-edge boundary
Switching is not a full-sphere enemy cycler.

- fully offscreen candidates are not ordinary switch winners;
- a small tuning-defined near-edge forgiveness region is permitted so a candidate just outside the visible safe frame can remain reachable without requiring pixel-perfect camera setup;
- the forgiveness region must not create surprise 90°/180° camera whips;
- a candidate far outside the current relationship frame requires the player to reorient or use another explicit targeting action rather than being secretly chosen.

This extends Decision #10's view-intent honesty into established switching.

### Successful switch commitment
When a candidate wins, **target identity commits immediately**.

On commit:
- the new target becomes authoritative immediately;
- target-relative locomotion basis updates immediately according to locomotion authority;
- target confirmation presentation identifies the new target immediately;
- the old target ceases to be lock authority;
- the camera begins one transition from its exact current physically resolved pose toward the new Decision #11 Relationship Frame.

The camera does not need to finish moving before gameplay acknowledges the switch.

### Camera transition
A successful switch uses one **short, bounded, eased Relationship Frame transition**.

It does not:
- recenter behind Neris first;
- cut;
- hard snap to the new target;
- freeze or slow gameplay;
- add a dramatic FOV punch;
- zoom out merely because another enemy exists;
- orbit theatrically around the player;
- pass through invalid geometry to make the new frame perfect.

Small adjacent switches should visually settle faster than larger legal frame corrections; exact timing/easing remains Gate 1 tuning.

Decision #11 owns the destination frame. Decisions #5/#6/#7/#8 remain physical/occlusion authority during the transition.

### No-candidate result
If no eligible candidate meaningfully exists in the requested direction:

- target does not change;
- target-relative locomotion basis does not change;
- camera does not lurch, recenter, or begin a fake switch transition;
- the system does not wrap around to a candidate on the opposite side;
- the request does not queue until an enemy appears;
- a later switch input performs a fresh evaluation.

A subtle optional rejection acknowledgement may be presented if testing shows the action otherwise feels broken. Exact UI/audio/haptic treatment remains accessibility/presentation tuning.

### No wraparound roulette
Directional switching does not wrap from the rightmost visible candidate to the leftmost candidate, or vice versa, merely because the player repeats the same direction.

If no candidate remains in that requested direction, the result is no switch.

This preserves spatial causality and eliminates list-cycler behavior disguised as directional targeting.

### Current-target occlusion grace
If the current target is temporarily inside Decision #6 occlusion grace:

- the player may intentionally switch away to an otherwise valid visible candidate;
- the occluded current target does not receive special directional priority;
- a different hard-hidden candidate is still ineligible for new switch commitment;
- if no valid visible switch candidate exists, the switch request has no effect and Decision #6 continues governing the current lock.

### New target invalidates during transition
After a successful switch, the new target is fully committed and ordinary established-lock validity rules apply.

- brief LOS loss follows Decision #6 grace;
- death/despawn/fundamental untargetability/hard invalidation breaks lock cleanly;
- invalidation does **not** silently cascade to another candidate;
- a later explicit switch/lock request performs a new evaluation.

### Combat-action boundary
Decision #12 does not silently decide attack cancellation, attack magnetism, combo retarget windows, guard behavior, or whether a committed attack may redirect toward a newly selected target.

The targeting service may accept and commit a new target only when current gameplay state says target switching is legal. Later Combat authority must define how attacks/actions consume or reject that target change.

The Camera / Targeting IDE must show when a switch request was rejected because another gameplay state owned switching legality.

### Multiple enemies versus camera framing
Decision #12 selects the next **single current target**. It does not make secondary enemies framing subjects.

- non-selected candidates are used only for target-choice evaluation;
- after commit, ordinary framing returns to the #11 Neris↔new-target relationship;
- Decision #13 owns whether/how secondary enemies may influence composition after the switch.

### Large-target boundary
Decision #12 may switch among legal target identities, but it does not define large-boss target-part grammar, multi-anchor bosses, or boss-specific framing.

Decision #14 owns large-boss framing and any later question of multiple switchable boss anchors/body parts.

---

## Accessibility and control requirements

Target switching must remain independently remappable at the semantic-action level.

Requirements:
- switching and manual composition nudge must be independently bindable where platform capability permits;
- mouse movement alone is not inherently a switch request;
- ordinary stick drift must not switch targets;
- a player should be able to use strong camera-nudge input without accidental switching if their chosen mapping separates the actions;
- eventual controller shared-input schemes must expose predictable thresholds/state and must never co-trigger nudge + switch on one event;
- final inversion/sensitivity/dead-zone/device mapping belongs to Decision #17.

No target-switch gameplay rule depends solely on haptics, color, or a tiny reticle animation.

---

## Camera / Targeting System IDE requirements

The workbench must expose enough evidence to answer **why did this switch happen—or not happen?**

At minimum show:
- raw semantic switch request vector and timestamp/frame;
- active input device/mapping context where available;
- switch-action triggered/re-armed state;
- current target identity and framing anchor;
- all potential candidates considered;
- candidate targetability/eligibility result;
- candidate LOS result and occluder where relevant;
- onscreen / near-edge / outside-envelope classification;
- each candidate's screen-space offset from the current target;
- requested-direction angular error;
- screen-space adjacency metric;
- world distance refinement value;
- deterministic tie-break result;
- candidate rejection reason;
- winning target or explicit no-candidate result;
- old-target → new-target commit frame;
- locomotion basis before/after commit;
- requested new Relationship Frame;
- current physically resolved camera pose;
- switch transition state/progress;
- active collision / occlusion / Close Quarters / Ceiling-Constrained ownership;
- new-target invalidation/break reason;
- gameplay-state rejection reason when switching is not currently legal;
- separate manual-nudge semantic input/state so accidental cross-trigger can be diagnosed.

The IDE should draw candidate screen-space vectors and requested-direction cones/regions directly over the live camera view.

---

## Representative test matrix

The Camera / Targeting workbench must include at minimum:

### Directional selection
- current target centered; valid targets left and right;
- closer target on wrong side versus farther target on requested side;
- two candidates on same side with different directional error;
- same directional error with different screen adjacency;
- near-equal candidates requiring deterministic tie-break;
- target above-left versus pure-left;
- target below-right versus pure-right;
- materially vertical candidate arrangement.

### Visibility / envelope
- requested-side candidate behind hard wall;
- visible candidate beside hidden better-angle candidate;
- candidate just inside screen edge;
- candidate just inside near-edge forgiveness;
- candidate clearly outside forgiveness;
- enemy behind camera;
- current target in occlusion grace while another visible candidate exists.

### Input robustness
- one switch request produces exactly one switch;
- held action does not machine-cycle;
- rapid deliberate repeated requests step one target per request;
- stick drift / tiny mouse movement never becomes switching by itself;
- manual composition nudge remains nudge;
- shared-input prototype, if later tested, proves nudge and switch cannot co-trigger;
- low/high frame rate does not change one-request-one-switch semantics.

### Transition / authority interaction
- switch during normal Relationship Frame;
- switch during rear-wall compression;
- switch under low ceiling;
- switch in Close Quarters Camera;
- switch while current target is temporarily occluded;
- new target loses LOS during transition;
- new target dies/invalidates during transition;
- no candidate in requested direction;
- repeated same-direction request at spatial edge proves no wraparound;
- attempt switch while a later gameplay state marks switching illegal.

### Multiple-enemy boundary
- 3/5 candidates visible while only winner becomes framing subject;
- dense same-side cluster;
- targets crossing screen order immediately before request;
- non-selected enemies do not alter #11 framing merely because they were candidates.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
- Enhanced Input supports semantic Input Actions, runtime mapping contexts, mapping priority, triggers, modifiers, radial dead zones, remapping, and custom processing. This supports separating `SwitchTarget` from `CompositionNudge` rather than making raw camera movement itself game policy.
  - https://dev.epicgames.com/documentation/unreal-engine/enhanced-input-in-unreal-engine
  - https://dev.epicgames.com/documentation/unreal-engine/input-overview-in-unreal-engine
- Gameplay Targeting System explicitly separates target selection, filtering, sorting, and immediate targeting requests. This supports one-request candidate generation → eligibility filtering → directional sorting without treating engine distance sort as game authority.
  - https://dev.epicgames.com/documentation/unreal-engine/gameplay-targeting-system-in-unreal-engine
  - https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/TargetingSystem/UTargetingTask

### Shipped-game problem study
Modern action games demonstrate two relevant design lessons without providing Stillring's implementation authority:
- directional target switching is a familiar combat concept;
- overloading free camera/mouse movement with target switching can create accidental switches and player frustration when sensitivity or candidate selection is ambiguous.

Monster Hunter Wilds publicly exposes camera adjustment and target switching as distinct control concepts, reinforcing the value of treating them as separate semantic actions even when final bindings share limited controller hardware.

Community reports around Souls-like lock systems repeatedly identify accidental mouse/stick target changes, hidden/offscreen candidate choices, excessive sensitivity, and unexpected camera whips as concrete failure modes. Those reports are treated as usability evidence only, not implementation sources.

### Zelda lineage
Z-targeting established the value of preserving a readable player↔opponent relationship in 3D. Stillring retains that abstract problem solution but deliberately defines its own target acquisition, switching, camera transition, controls, reticle/presentation, and timings under `docs/05_IP_GUARDRAILS.md`.

No exact control mapping, timing, reticle, target list order, or camera expression from Zelda or another shipped game is copied.

---

## Why this package is approved
This decision is consistent with all prior camera authority:
- #10 already says player view intent outranks simple closeness for initial acquisition;
- #11 makes the current Relationship Frame the visual combat reference;
- #5/#6/#7/#8 remain physical and occlusion authority;
- the locomotion spec already makes target identity authoritative for target-relative movement;
- the System IDE contract requires explainable candidate rejection/state evidence;
- IP guardrails require Stillring to invent its own switching rule rather than clone a famous implementation.

The design is deterministic, auditable, remappable, accessibility-compatible, physically honest, and does not require unresolved #13/#14/#17 policy to be guessed now.

---

## Player-facing acceptance
Decision #12 passes when:
1. a deliberate directional switch chooses an eligible target in the direction the player intended;
2. screen-space direction from the current target beats simple nearest-enemy selection;
3. one request changes at most one target;
4. holding an input does not roulette through enemies;
5. no valid candidate means no target or camera change, with no opposite-side wraparound;
6. hard-hidden/offscreen enemies do not cause surprise switches;
7. target identity and target-relative movement basis commit immediately on a successful switch;
8. the camera makes one short eased transition from its exact current pose into the new #11 Relationship Frame;
9. no recenter, hard snap, slowdown, FOV punch, or cinematic flourish occurs;
10. new-target invalidation never silently cascades to another enemy;
11. manual composition nudge and switch are separate semantic actions and cannot unpredictably co-trigger;
12. mouse movement or stick drift alone never becomes switching intent;
13. the IDE can explain candidate eligibility, directional ranking, winner/rejection, and transition state;
14. #13 multiple-enemy framing, #14 boss framing, and #17 device mapping remain cleanly unresolved rather than being smuggled into this decision.

---

## Next decision
**Camera Decision #13 — multiple-enemy framing limits.**

Research it independently. Do not infer group framing, secondary-threat camera bias, automatic zoom/FOV, offscreen-threat behavior, or encounter camera obligations from the fact that #12 can see multiple switch candidates.
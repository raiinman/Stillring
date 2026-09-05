# 71 — Gate 4 Hush Seam Transition Control Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #2 — seam-transition eligibility / commit / cancel / camera-control contract

## Decision

A Waking↔Hush shift is an explicit player/world request resolved by one authoritative transition service. The request either rejects cleanly before semantic commitment or commits once, atomically, to the destination semantic layer. Presentation may continue briefly after commitment, but there is no long ambiguous half-state in which gameplay truth is undecided.

Core philosophy:

> **Decide the reality once. Present the change quickly. Never leave the player between truths.**

The seam is not a cutscene, teleport menu, hold-to-charge mode switch, or generic dodge. It must preserve the feeling that Neris remains in one place while Orra's active expression changes.

## Request model

The player-facing seam action is a semantic `RequestLayerShift` action rather than a raw engine Data Layer toggle.

A request records:
- source semantic layer;
- requested destination layer;
- request source (`Player`, reviewed scripted/world event, or development fixture);
- player transform and locomotion state at request time;
- current combat/target/traversal/tool ownership;
- transition eligibility result;
- rejection reason or accepted transition ID.

Enhanced Input may provide the remappable action and context filtering, but the input system does not decide legality.

## Eligibility is explicit

For ordinary player-owned shifts, eligibility must be answered synchronously from reviewed gameplay state before semantic commit.

A player request is rejected when any of the following applies unless a later system explicitly grants an exception:
- player is dead or in a non-interruptible death/retry boundary;
- a cinematic/scripted ownership state explicitly forbids player layer control;
- current traversal state cannot guarantee a valid paired destination position;
- a committed interaction/mechanism state would become semantically contradictory if shifted mid-action;
- the destination layer cannot establish a safe player occupancy solution within the authored seam rules;
- a previous transition is already active;
- the destination equals the current semantic layer;
- the current authored area/volume explicitly does not support player-initiated seam shifting.

Combat itself does **not** automatically forbid shifting. Combat continuity belongs to Decision #5; blanket `InCombat == false` gating would turn the seam into a puzzle-only key and erase systemic value.

## No hidden eligibility by engine load state

A request must not be rejected merely because a destination Data Layer/sublevel is not currently `Activated` if the approved representation can prepare it within the transition budget.

Conversely, a destination being loaded does not make the shift semantically legal.

Engine readiness is an execution precondition reported separately from gameplay eligibility.

## Prepare, then commit

The transition service uses three semantic phases:

1. `Requested` — capture request and evaluate gameplay eligibility.
2. `Preparing` — optional short representation-preparation phase; current semantic layer remains authoritative.
3. `Committed` — active semantic layer changes exactly once to the destination; paired gameplay expression ownership changes atomically.

After commit, a short `Presenting` process state may continue visual/audio/camera blending. `Presenting` is not a third reality.

If preparation cannot satisfy its bounded readiness contract, the transition fails before commit and the current layer remains authoritative.

## Commit point

The commit point must be deterministic and externally inspectable.

At commit:
- `ActiveSemanticLayer` changes once;
- the authoritative paired-expression ownership set changes for gameplay/collision according to Decision #3;
- transition ID records its source and destination;
- combat/NPC/interactable continuity hooks receive one reviewed layer-change event;
- tools and puzzle systems read the new semantic state through normal authority paths;
- no second hidden input action is required to “finish” the shift.

The commit is not driven by a VFX notify, material timeline reaching 50%, camera blend completion, Animation Blueprint state, Data Layer callback, or streamed-level visibility callback. Those may gate preparation or report presentation progress, but the semantic service owns commit.

## Cancel behavior

### Before commit
A player may cancel only while the transition is still in `Preparing` and only if the presentation/control design exposes a meaningful cancel window. A cancellation returns cleanly to the source layer with no persistent gameplay mutation.

For the Gate 4 prototype, the preferred default is **no deliberate charge-up**, so most valid shifts should progress from request to commit too quickly to need a player cancel gesture.

### After commit
There is no rollback cancel. A new shift back is a new request subject to normal eligibility.

This prevents double-tap races, half-restored Actors, and “cancel after reality already changed” ambiguity.

## Repeated input / debounce

While one transition ID is active:
- repeated seam requests are consumed/rejected as `Rejected_TransitionAlreadyActive`;
- they are not queued;
- they do not reverse the in-flight transition;
- holding the seam input does not oscillate layers;
- after transition completion, a fresh intentional press may request the reverse shift.

Exact post-completion debounce is tuning and should be only long enough to avoid accidental repeat activation from the same physical press.

## Movement ownership

Ordinary seam transition does **not** stop Neris, zero velocity, force idle, snap facing, or freeze locomotion solely for presentation.

Movement remains under the current authoritative locomotion state unless destination occupancy requires a small reviewed correction.

At commit:
- horizontal intent remains player-owned;
- ordinary grounded velocity carries through unless destination geometry makes that physically invalid;
- Sprint does not automatically cancel merely because the layer changes;
- Jump/airborne state does not restart;
- combat evade/attack state does not restart or gain new invulnerability from the seam;
- target-relative movement basis follows Gate 1/2 authority and Decision #5 continuity.

The seam must never become a free animation cancel, momentum reset, or defensive invulnerability exploit.

## Airborne transitions

Player-initiated shifting while airborne is allowed only where the destination layer can provide a deterministic compatible continuation.

The default contract:
- preserve player world transform and velocity across commit;
- preserve the existing jump/fall semantic state;
- do not re-run jump impulse;
- do not create seam-specific air control;
- destination collision is validated before commit;
- if paired geometry would place the player inside blocking space, the request rejects unless Decision #3's authored safe-resolution rule can solve it without meaningful teleportation.

A level that requires shifting during a jump must author and test that seam explicitly.

## Traversal ownership

Ledge hang, mantle, ladder, authored Anchor pull, or another state that owns player transform may allow seam shifting only if that traversal feature declares a compatible destination expression and deterministic continuation.

Otherwise the request rejects with a semantic reason such as `Rejected_TraversalNoDestinationContract`.

No traversal state may silently detach Neris, complete itself, or teleport to an endpoint just because a seam was requested.

## Camera ownership

Gate 1 camera authority remains authoritative through the transition.

The seam may add a short presentation layer, but it may not:
- hard cut;
- recenter yaw;
- take away manual orbit;
- alter target lock by camera behavior;
- apply a dramatic FOV punch that changes spatial judgment;
- queue blocked pitch;
- force first-person/shoulder/top-down framing;
- steer toward a puzzle answer or Hush-exclusive object.

Preferred transition camera behavior:
- preserve current camera pose and player-owned orbit input;
- allow a very short bounded compositional damping adjustment only if destination geometry/collision requires it;
- run ordinary camera collision against the currently authoritative physical expression;
- after commit, resolve immediately against destination collision using Gate 1 compression/occlusion rules;
- visual seam effects layer around the camera solution rather than replacing it.

## Target lock

Decision #2 does not define whether an established target survives a seam; that is Decision #5.

However, the transition itself may not silently clear, acquire, or replace a target simply to simplify presentation.

If Decision #5 later determines that a target cannot persist, the target service owns that result and reports it explicitly.

## Interaction/tool ownership

A seam request cannot be used as an implicit “cancel everything” command.

Current interaction/tool state must return one of:
- `TransitionCompatible` — carries through;
- `TransitionCompletesBeforeCommit` — only for an explicitly defined atomic interaction whose gameplay fact is already committed;
- `TransitionRejects` — seam request rejected until the state releases ownership.

The Hush service does not invent bespoke exits from Cantor, Anchor, guard, attack, ladders, prompts, or mechanisms.

## Failure behavior

All failures before commit are side-effect free with respect to semantic world truth.

Representative reasons:
- `Rejected_AlreadyInRequestedLayer`
- `Rejected_TransitionAlreadyActive`
- `Rejected_AreaDoesNotPermitPlayerShift`
- `Rejected_PlayerDead`
- `Rejected_ScriptOwnsLayer`
- `Rejected_TraversalNoDestinationContract`
- `Rejected_InteractionOwnsTransform`
- `Rejected_NoSafeDestinationOccupancy`
- `Rejected_DestinationRepresentationNotReady`
- `Rejected_PairedStateValidationFailed`

A rejected request may produce a restrained multimodal denial cue, but no camera lurch, movement interruption, fake partial transition, or misleading Hush flash.

## Accessibility / control requirements

- seam action is fully remappable;
- one press is sufficient by default;
- no rapid-mash, repeated-tap, stick-gesture, or precision timing requirement for ordinary shifting;
- if hold is offered as an accidental-activation option, tap remains available and hold duration is configurable;
- denial/transition confirmation is not color-only or audio-only;
- transition flash/contrast/intensity must eventually support reduced-effects settings under Decision #7;
- control hints name the world action, not an engine implementation concept such as “Toggle Data Layer.”

## System IDE requirements created by Decision #2

### Inspect
Expose:
- active semantic layer;
- current transition phase;
- transition ID/source/destination;
- request source;
- eligibility result;
- rejection reason;
- prepare elapsed time and readiness gates;
- semantic commit frame/time;
- presentation completion state;
- player locomotion/traversal/combat/tool owner at request and commit;
- transform/velocity before and after commit;
- camera mode/lock before and after commit;
- representation readiness separately from semantic state.

### Exercise
Provide development-only actions to:
- request Waking→Hush;
- request Hush→Waking;
- force a preparation failure;
- simulate repeated input during transition;
- test airborne request;
- test requests during each traversal/combat/tool ownership state;
- pause immediately before semantic commit for inspection without changing retail timing.

### Validate
Catch:
- more than one semantic commit per transition ID;
- gameplay mutation before accepted commit;
- queued reverse transition from held/repeated input;
- movement velocity reset without an owning gameplay reason;
- camera recenter/FOV mode change caused solely by seam transition;
- seam-created invulnerability/cancel opportunity not owned by combat authority;
- destination occupancy becoming invalid at commit;
- semantic layer changing from a VFX/animation/Data Layer callback;
- transition completing while representation state still contradicts semantic ownership.

### Capture
A seam-transition capture records request → eligibility → preparation gates → commit → post-commit locomotion/camera/target/tool state → representation convergence → validation results.

## Representative test matrix

Test at minimum:
- idle grounded shift both directions;
- walk/run/Sprint shift;
- manual camera orbit during shift;
- target lock active;
- light/heavy attack phases;
- guard/evade;
- jump ascent/apex/fall;
- ledge hang/mantle/ladder;
- Anchor targeting/tension/pull states;
- mechanism interaction;
- destination blocker at player position;
- destination becomes unavailable during `Preparing`;
- repeated/held seam input;
- reduced transition effects;
- low frame rate and streaming stress;
- save trigger immediately before/after commit once Decision #6 is defined.

## Comparative design lineage

Relevant shipped designs demonstrate useful problems, not Stillring expression to copy:
- **Titanfall 2 — Effect and Cause:** rapid player-controlled state switching works because control remains immediate and spatial correspondence is legible; Respawn's implementation used aligned versions of the level and tuned transitions heavily for fluidity.
- **Dishonored 2 — A Crack in the Slab:** two states of one place can support meaningful systemic consequences when state differences remain coherent and player actions have persistent meaning.
- **Legacy of Kain: Soul Reaver:** overlapping material/spectral realities show the value of shared spatial identity with different functional laws.

Stillring must not copy their exact input mappings, time-travel fiction, transition visuals, layout pairings, or encounter solutions.

## Research basis

Primary current technical sources verified for this decision:
- Epic Games, **Enhanced Input in Unreal Engine 5.8** — semantic actions, triggers, runtime mapping contexts, prioritization/remapping.
- Epic Games, **World Partition — Data Layers in Unreal Engine 5.8** — runtime state changes, loaded vs activated distinction, light/dark-world example, debugging.
- Epic Games, **World Partition in Unreal Engine 5.8** — streaming sources and readiness implications.
- Epic Games, `UDataLayerManager::SetDataLayerInstanceRuntimeState` UE5.8 API.

Comparative problem-study sources:
- Game Developer, “The idea for Titanfall 2's most iconic level predates the series itself” (2016).
- Game Developer / PC Gamer coverage of Dishonored 2's `A Crack in the Slab` seamless two-period design.
- Ernest Adams, Game Developer, “Defining the Physical Dimension of a Game Setting” discussion of Soul Reaver's material/spectral realms.

Repository authority:
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
- Camera authority `docs/22`–`docs/36`
- Gate 2 combat authority `docs/37`–`docs/59`
- Gate 3 tool/puzzle authority `docs/60`–`docs/69`
- `docs/70_GATE4_HUSH_SEMANTIC_STATE_IDENTITY_ADDENDUM.md`
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
- Issue #126

## Locked statement

> **A seam shift either rejects before commitment or changes semantic reality exactly once; locomotion and camera remain player-owned, and presentation never becomes a third gameplay state.**

## Next decision

**Gate 4 Decision #3 — paired geometry / Actor presence and collision-authority rules.**

# 47 — Gate 2 Combat Death / Retry Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #11 for Issue #3. This file defines when Death becomes authoritative, what combat state must terminate immediately, and what combat may or may not own during retry.

## Authority
Combat Decision #11 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Death / retry principle:
> **Death ends combat immediately. Retry restores a valid world, not a half-dead combat frame.**

---

## Combat Decision #11 — death / retry boundary — LOCKED

### Death is an authoritative gameplay result
Death begins when authoritative gameplay resolution produces the `Death` outcome established by Combat #6.

Death may be caused by:
- a fatal enemy hit;
- a fatal environmental/world consequence routed into player health/death authority;
- another future explicitly-authored fatal gameplay event.

Death does **not** begin because:
- a death animation notify fires;
- a montage reaches a named section;
- the mesh ragdolls;
- the camera begins a death presentation;
- a UI Game Over panel opens.

Presentation follows the already-decided gameplay result.

### Death has highest player-combat priority
Once Death commits, no ordinary player combat state may remain authoritative.

The combat service must atomically terminate or invalidate:
- Light / Heavy action state;
- Startup / Active / Recovery ownership;
- ordinary Guard;
- Guard Reaction;
- Perfect Guard activation/advantage;
- Evade entry/travel/recovery;
- Evade combat-immunity window;
- hit-reaction / interrupt recovery state;
- Reaction Retrigger Protection;
- pending continuation/input buffer;
- attack-facing correction;
- temporary current-attack target/facing samples;
- any combat-local action timers that could later fire into a live transition.

No stale callback may resurrect a pre-death action.

### Pending input is discarded
Combat #8's one-slot pending intent is cleared on Death.

A Light/Heavy/Guard/Evade/Jump/Sprint/targeting input pressed before death may not execute after death presentation or after retry simply because it was buffered earlier.

Death does not inherit command queues.

### New combat input is rejected while dead
While Death is authoritative:
- attack requests are rejected;
- Guard requests are rejected;
- Evade requests are rejected;
- combat-facing assistance is inactive;
- movement/combat transition requests do not enter the combat state graph;
- Perfect Guard cannot arm;
- no immunity may be granted by stale Evade state.

The Combat IDE should report a semantic rejection such as `Rejected_Dead` rather than silently ignoring the request.

### Target lock gameplay identity clears immediately
The active target-lock **gameplay relationship** ends when Death becomes authoritative.

Requirements:
- current lock target becomes none;
- target-relative locomotion basis is no longer authoritative;
- target switching cannot occur;
- current attack does not retain a dead-player target relationship for later callbacks.

The camera may temporarily preserve a readable death presentation using its own presentation state, but that is not an active gameplay lock and may not feed target-relative combat logic.

### Death presentation is presentation, not a second state machine
Animation, camera, sound, UI, hitstop, ragdoll, fade, or other death presentation may communicate the event.

They may not:
- determine whether the player is actually dead;
- restore health;
- reopen combat transitions;
- hold a hidden immunity state;
- decide save/checkpoint persistence;
- silently defer combat cleanup until an animation finishes.

The authoritative combat state is already Death while presentation runs.

### Fatal-hit resolution is single-shot
Once Death is authoritative:
- additional ordinary damage/hit callbacks cannot generate repeated death transitions;
- repeated corpse contacts cannot re-trigger combat rewards, death sounds, save writes, or encounter outcomes unless a later explicit system owns such behavior;
- simultaneous hits must resolve deterministically into one death transition.

Combat may record contributing hit context for diagnostics, but Death enters once.

### Death cannot be voluntarily canceled
Player action requests cannot cancel Death.

No:
- Guard cancel;
- Evade cancel;
- target-lock cancel into movement;
- Jump escape;
- interaction escape;
- pause/menu exploit that re-enters a pre-death action.

A retry/load operation replaces the dead gameplay instance through the checkpoint/save boundary; it does not cancel Death back into Free.

### Retry is not a combat rewind system
Combat owns the guarantee that its transient state is clean. Combat does **not** decide what world progress survives death.

On retry, Combat requests or participates in restoration through the project checkpoint/save/world-state authority.

Combat #11 does not decide:
- which checkpoint is selected;
- which quest facts persist;
- whether collected items persist;
- enemy/world persistence rules;
- economy penalties;
- world-layer/Hush persistence;
- checkpoint activation rules;
- save-file writing policy.

Those belong to Save / World State / Encounter authority and require their own decisions.

### Retry must produce a fresh valid combat baseline
After checkpoint/world restoration completes and player control is returned, combat must begin from a known neutral state.

At minimum:
- player is not in Death;
- no prior Light/Heavy/Guard/Evade/reaction state survives;
- no prior pending combat input survives;
- no prior Evade immunity survives;
- no prior Reaction Retrigger Protection survives;
- no prior Perfect Guard timing/advantage survives;
- no old combat target is retained;
- no old attack-facing sample is retained;
- no stale action timer can fire;
- no dead-player collision/attack ownership remains;
- current health/resource values are whatever the checkpoint/save authority explicitly restores.

Combat must not invent a fixed retry health amount inside this decision.

### Encounter reset is owned by encounter/checkpoint authority
Combat may expose hooks such as `OnPlayerDeath` / `OnPlayerCombatReset` for encounter systems, but it cannot assume that every enemy despawns, fully heals, persists, or rewinds.

The checkpoint/encounter contract decides that later.

Combat's obligation is narrower: no player-local combat state may leak across retry.

### Retry availability is explicit
The player may only request retry/load when the higher-level death/checkpoint flow says retry is available.

Combat must not treat arbitrary attack/Guard/Evade inputs during death presentation as hidden retry commands.

Exact presentation duration, fade timing, menu layout, and whether a completed death presentation may be shortened are tuning/UI/accessibility questions so long as they do not reopen combat state.

### No death-triggered save mutation inside combat
The combat service must not directly save inventory, quest, checkpoint, or world state merely because Death occurred.

It may emit the semantic event and context needed by the owning systems.

This prevents combat code from becoming an accidental second persistence system.

---

## Gameplay / animation implementation boundary

Unreal Engine 5.8 provides explicit interruption/cleanup primitives for active abilities/tasks and animation montages. Stillring may use such primitives, or a smaller C++ combat-state service, but the semantic requirement is the same:

- gameplay enters Death first;
- active combat tasks/state are ended deterministically;
- presentation is stopped/replaced/blended as appropriate;
- no animation callback can later restore an invalid action;
- restart/retry builds a fresh state from authoritative checkpoint/world data.

Animation assets may timestamp presentation. They do not own death legality or retry persistence.

---

## Accessibility / UX boundary

Death must remain understandable without requiring a long unskippable presentation.

Requirements:
- essential death/retry information is not conveyed by audio alone;
- retry/load controls are remappable or use the project-standard menu/navigation accessibility path;
- no rapid repeated input is required to recover from death;
- reducing camera shake or vibration does not change Death timing/state;
- any future option to shorten death presentation may shorten presentation only, never gameplay consequence or checkpoint policy.

---

## Combat System IDE requirements

### Inspect
Expose:
- alive/dead authoritative state;
- exact death cause/event ID;
- fatal hit resolution context;
- previous combat state/phase;
- cleanup actions performed;
- pending input before/after cleanup;
- current lock target before/after cleanup;
- Evade immunity / Perfect Guard / reaction-protection cleanup;
- retry availability owner;
- checkpoint/world restore status as read-only external ownership;
- current post-retry baseline validation status.

### Exercise
Provide scenarios for:
- fatal hit during Light Startup/Active/Recovery;
- fatal hit during Heavy;
- fatal hit during Guard / Guard Reaction;
- fatal hit during Evade vulnerable entry/recovery;
- fatal hit simultaneous with Evade immunity boundary;
- fatal hit during hit reaction / retrigger protection;
- fatal multi-hit same frame;
- death with buffered input pending;
- death while target locked;
- retry then immediate combat input;
- repeated retry/reset fixture.

### Validate
Detect:
- active attack/Guard/Evade state surviving Death;
- immunity surviving Death;
- pending combat input surviving Death/retry;
- gameplay target lock surviving Death;
- stale montage/notify/task reopening combat state;
- duplicate Death transition from corpse hits;
- combat service writing checkpoint/save/world-state data directly;
- retry restoring an old combat target or facing sample;
- post-retry player entering gameplay before combat baseline is valid;
- retry health/resource value hardcoded in combat instead of supplied by owning restore authority.

### Capture
Record a deterministic death timeline including:
- fatal event;
- pre-death combat state;
- resolved Death transition;
- cleanup sequence/results;
- lock/pending-input cleanup;
- presentation start;
- retry request;
- checkpoint/world restore handoff;
- post-retry combat baseline.

---

## Representative tests

1. Die during every Light phase and verify no continuation executes.
2. Die during Heavy and verify no Heavy Active/recovery callback survives.
3. Die during Guard/Perfect Guard boundary and verify no defensive benefit survives.
4. Die immediately before/after Evade immunity starts/ends; Death remains highest priority.
5. Die with one buffered intent; retry must not execute it.
6. Die while locked; gameplay lock clears immediately while camera presentation may remain independently readable.
7. Receive simultaneous fatal hits; exactly one Death transition occurs.
8. Continue receiving hit overlaps after Death; no repeated death-side effects occur.
9. Retry repeatedly and verify identical neutral combat-local state each time.
10. Verify checkpoint/world facts are supplied externally and combat makes no persistence decision.
11. Verify 30/60/120+ FPS does not alter death cleanup ordering.
12. Verify presentation reduction/accessibility settings do not alter state or consequence.

---

## Research basis / design lineage

Primary engine references reviewed for this decision:
- Epic Games, Unreal Engine 5.8 — Using Gameplay Abilities: explicit `CancelAbility` / `EndAbility` cleanup semantics and the danger of leaving an action logically active after presentation ends: https://dev.epicgames.com/documentation/unreal-engine/using-gameplay-abilities-in-unreal-engine
- Epic Games, Unreal Engine 5.8 — `UAbilityTask_StartAbilityState`: state-specific end/interruption cleanup: https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayAbilities/UAbilityTask_StartAbilityState
- Epic Games, Unreal Engine 5.8 — `PlayMontageAndWait`: explicit completed/interrupted/cancelled paths: https://dev.epicgames.com/documentation/en-us/unreal-engine/BlueprintAPI/Ability/Tasks/PlayMontageAndWait
- Epic Games, Unreal Engine 5.8 — montage stop APIs demonstrate presentation can be terminated independently of gameplay truth: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UAnimInstance/Montage_Stop

Design-lineage conclusion: older and modern Zelda games treat player defeat as a clear boundary followed by restoration/continuation rather than allowing an attack animation or target relationship to remain partially live. Stillring preserves the deeper clarity principle but keeps exact checkpoint/save consequences for its own later world-state design.

No proprietary retry timing, save policy, animation, UI, checkpoint placement, or code is copied.

---

## Why this package is approved
Combat #11 closes the final player-combat terminal boundary without letting death presentation become gameplay authority and without smuggling persistence rules into combat.

The rule is simple:
> **Dead means combat is over. Retry means rebuild from valid authority.**

---

## Player-facing acceptance
Combat #11 passes when:
1. fatal gameplay resolution enters Death exactly once;
2. Death outranks all player combat states;
3. pending combat intent, immunity, Guard/Perfect Guard, reactions, attack state, facing assistance, and target lock are cleaned immediately;
4. death presentation cannot reopen or delay authoritative cleanup;
5. new combat input is rejected while dead;
6. retry does not act as a combat rewind and does not decide world/save persistence;
7. post-retry combat begins from a neutral validated local state;
8. checkpoint/save authority supplies restored health/resources/world facts;
9. Combat IDE can prove cleanup and detect leaked state;
10. repeated death/retry cycles are deterministic and leave no stale combat ownership.

---

## Next step
Combat Decisions #1–#11 now cover the meaningful player combat-state policy required by Issue #3.

Next perform a **separate combat-state reconciliation/closure pass**: build the cumulative state diagram, legal/illegal transition matrix, verify every Issue #3 acceptance criterion against Decisions #1–#11, update the handoff/register, and close Issue #3 only if no semantic gap remains.

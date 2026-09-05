# 41 — Gate 2 Combat Evade Model Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #5 for Issue #3. This file defines the representative Gate 2 combat Evade after ordinary Guard is locked.

## Authority
Combat Decision #5 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

This decision answers:
- what one Evade request does;
- how evade direction is chosen;
- whether displacement or invulnerability is primary;
- whether any invulnerability window exists and why;
- how collision, target lock, Guard, attack commitment, repeated evades, and accessibility interact;
- what the Combat System IDE must expose.

It does **not** yet define Perfect Guard/parry, hit-reaction/interrupt hierarchy, global input-buffer rules, final attack-facing correction, combat resources, or death/retry.

Combat principle:
> **Commit to the meaningful decision, not to decorative dead time.**

Evade principle:
> **Move out of danger first. Forgive honest overlap briefly. Never phase through the world.**

---

## Combat Decision #5 — evade / invulnerability philosophy — LOCKED

### Evade is a dedicated combat action
Evade is its own remappable semantic action.

- one distinct Evade press requests one Evade;
- Sprint is not Evade;
- Jump is not Evade;
- camera input is not Evade;
- holding Evade does not auto-repeat;
- double-tap is not required;
- no contextual input silently converts Sprint or Jump into Evade.

### Position is the primary defense
The representative Gate 2 Evade is designed first as **committed displacement**.

The intended defensive success order is:
1. the player reads the threat;
2. commits to an evade direction;
3. Neris moves out of the attack volume;
4. a short explicit invulnerability interval forgives unavoidable overlap during the core evasive motion.

The invulnerability window is not the main locomotion mechanic and must not make physical positioning irrelevant.

### A short central invulnerability window is retained — explicitly justified
Gate 2 retains a **brief, bounded invulnerability interval** during the central committed portion of the Evade.

Reason:
3D melee uses swept weapon volumes, moving attackers, animation/contact timing, network-independent simulation steps, and complex body overlap. A visually honest displacement can otherwise still register a hit because attack and character collision overlap for a small fraction of the motion. A short forgiveness window prevents the defensive action from feeling dishonest without turning Evade into a universal phase-through attack button.

Locked semantics:
- invulnerability begins after Evade acceptance, not before input is processed;
- it occupies only a central portion of the action;
- early entry and late Recovery remain vulnerable;
- exact start/end duration remain prototype tuning;
- the window is authoritative combat state, not an animation notify by itself;
- replacing or retiming animation cannot silently change invulnerability.

### Evade invulnerability protects against ordinary combat hit resolution, not world collision
During the active invulnerability interval:
- ordinary damage/hit-reaction events authored as evade-eligible do not apply their normal hit result;
- Neris still collides with walls, closed doors, pillars, ledges, blockers, and other authoritative world geometry;
- Evade never teleports through a blocking surface;
- collision does not become disabled merely because damage immunity is active;
- persistent environmental hazards or specially authored effects are not automatically bypassed by combat i-frames unless their own authority explicitly opts in.

This cleanly separates **damage immunity** from **physical collision**.

### Evade movement must be swept and collision-honest
Evade displacement is action-authored gameplay movement.

Requirements:
- movement uses swept/collision-aware resolution;
- a blocking wall shortens/stops the requested displacement rather than allowing penetration;
- pathological penetration is resolved using normal movement/collision authority;
- Evade does not warp around corners or slide large distances along obstacles to preserve intended travel;
- if a small natural slide along a surface is used, it must remain bounded and must not increase total evade distance beyond action authority;
- animation root motion may present the move only when matched to approved gameplay displacement.

Exact distance/speed curve remain prototype tuning.

### Direction is sampled at acceptance and then committed
At the moment Evade is accepted, one evade direction is resolved from current player intent.

Locked behavior:
- meaningful movement-stick / movement-key input supplies the requested direction;
- once accepted, the core Evade direction is committed for that action;
- ordinary analog steering does not freely curve the Evade mid-motion;
- collision resolution may alter achieved displacement, but the player cannot snake around attacks during one Evade;
- exact tiny facing/presentation adjustments do not alter the authoritative travel vector.

This keeps Evade readable for both player and enemy design.

### Locked movement frame follows existing locomotion authority
When target-locked:
- directional Evade uses the current stable target-relative combat movement frame;
- lateral input produces left/right evasive displacement around the relationship;
- forward/back input produces toward/away displacement without auto-maintaining range;
- target loss after acceptance does not reinterpret the already committed direction.

When unlocked:
- Evade direction uses the ordinary stable camera-relative locomotion frame at acceptance;
- camera movement after acceptance does not rotate the active Evade path.

### Neutral Evade is a short backward retreat
When Evade is requested with no meaningful movement direction:
- Neris performs the representative **neutral back-evade** relative to her authoritative facing at acceptance;
- under lock, that normally means retreating away from the current target because combat facing is target-oriented;
- unlocked neutral Evade retreats opposite Neris's body forward, not opposite camera yaw.

Neutral Evade is intentionally predictable and does not select a random safe direction.

### Evade has explicit phases and real commitment
The representative Evade uses semantic phases:
1. **Entry** — request accepted, direction committed, displacement begins;
2. **Invulnerable Travel** — central evasive interval with combat damage immunity;
3. **Recovery** — immunity ended; action resolves toward legal follow-up/free state.

Exact durations are tuning. Their semantics are locked.

The player may not freely cancel the active Evade into arbitrary actions.

### No evade-cancel leakage into committed attacks
Decision #1 remains authoritative.

Combat #5 does not automatically add Evade edges from every attack phase.

Until a source action explicitly grants a defensive transition:
- Light Startup/Active cannot be erased by Evade;
- Heavy Startup/Active cannot be erased by Evade;
- a pending light continuation does not override a committed action to dodge;
- later Recovery may expose an explicit `DefensiveCancelWindow`, but each source action must authorize it.

This preserves offensive commitment instead of making Evade a universal undo button.

### Guard → Evade is legal from stable Guard, not Guard Reaction
Ordinary Guard and Evade are complementary defenses.

Locked transition:
- while Guard is stably Active and not currently owned by Guard Reaction, an Evade request may exit Guard and begin Evade immediately when no higher-priority state prevents it;
- during Guard Reaction, Evade is rejected until the reaction's gameplay release boundary unless later hit/interrupt authority explicitly changes that rule;
- Hold/Toggle guard input state does not automatically re-enter Guard during Evade;
- after Evade completes, the player must satisfy normal Guard input/state rules to guard again.

This lets a player change defensive strategy without making a successful block reaction meaningless.

### Evade cannot be canceled back into Guard/Attack during its core travel
During Entry and Invulnerable Travel:
- Light/Heavy/Guard/Jump/Sprint do not cancel Evade by default;
- target switching can change lock identity under targeting authority but does not redirect the committed path;
- ordinary movement input may be remembered only as post-Evade locomotion intent, not as active steering.

Recovery release determines when later actions regain authority.

### No evade attack in the Gate 2 baseline
Combat #5 does not add:
- dodge attack;
- roll attack;
- evasive counter;
- automatic follow-up strike;
- slowdown/Flurry-Rush-style reward;
- perfect-dodge damage bonus.

Those are distinct offensive/reward mechanics and must earn separate decisions if later proposed.

### Repeated Evade is not a special chain
Once an Evade has completed enough Recovery for another Evade to be legal, the player may request a new Evade.

However:
- the current Evade does not queue the next one during Entry/Invulnerable Travel;
- holding Evade does not repeat;
- repeated presses do not create a buffered roll chain;
- there is no special `Evade_1 -> Evade_2 -> Evade_3` combo state;
- no automatic increasing distance or hidden immunity stacking exists.

Evade repetition is simply successive legal actions, subject to normal state timing.

### No universal stamina cost
The representative Evade has **no stamina/resource cost** in Combat #5.

Its cost is:
- action commitment;
- displacement that can worsen position;
- vulnerable Entry/Recovery edges;
- inability to attack/guard during core travel;
- collision/world constraints;
- timing requirement;
- opportunity cost.

A later combat-resource decision may only add a cost if testing shows those constraints are insufficient.

### Invulnerability does not stack or linger
The immunity state:
- starts/ends exactly with the authoritative tuned interval;
- cannot be extended by repeated Evade presses;
- does not persist into normal locomotion;
- does not remain active because the animation is still in a visually low pose;
- does not stack multiple immunity tokens;
- is forcibly cleared on action termination/reset/death.

### Target lock persists through ordinary Evade
Evade does not automatically cancel target lock.

- current target identity remains authoritative unless normal targeting invalidation/break rules fire;
- camera continues approved relationship framing and does not spin/roll with Neris's animation;
- target switching remains explicit and does not redirect an Evade already accepted;
- the Evade itself does not silently choose a target.

### Off-ledge behavior follows world/traversal authority
Evade does not gain special invisible ground rails.

If an Evade path reaches a real ledge:
- normal locomotion/traversal/fall eligibility decides the result;
- the action cannot float across missing ground;
- the game must not silently teleport Neris back to safety;
- prototype testing must include ledge cases to ensure collision/ground transitions are readable.

If human testing later proves ordinary combat evades too easily produce accidental lethal falls, solve that explicitly rather than hiding a universal ledge clamp inside Evade.

### Evade does not bypass authored unblockable semantics by default wording
Combat #4's `Unblockable` means “ordinary Guard cannot block.” It does **not** automatically mean “Evade i-frames cannot avoid.”

Each damaging effect must expose its interaction class separately where needed.

Gate 2 baseline expectation:
- ordinary melee/projectile damage is evade-i-frame eligible;
- persistent world hazards, grabs/constraints, and exceptional authored effects may ignore combat evade immunity only through explicit data and strong player-readable logic;
- “red attack” presentation alone is not implementation authority.

### No hitbox shrink trick as hidden substitute
Stillring may use normal movement collision during Evade.

Combat #5 does not authorize silently shrinking Neris's world collision capsule to squeeze through geometry or enemies. If a future animation requires temporary collision-shape changes, that requires explicit collision/traversal review.

---

## Accessibility / controls

Requirements:
- Evade is fully remappable;
- one press performs one Evade; double-tap is never required;
- no rapid repeated tapping is required for baseline defensive success;
- neutral input has a defined back-evade rather than requiring precise stick direction;
- gameplay success/failure is readable without relying only on haptics/camera shake;
- the invulnerability window is data-driven and inspectable so future accessibility assistance can adjust timing only through explicit approved settings;
- no accessibility mode may secretly disable world collision or turn Evade into teleportation.

A future **Evade Timing Assist** may be evaluated as an accessibility option that modestly expands the immunity interval, but Combat #5 does not silently lock a balance range before human play establishes the baseline.

---

## Combat System IDE requirements

### Inspect
Expose at minimum:
- Evade input request frame/time;
- accepted/rejected + semantic reason;
- requested direction input;
- resolved movement frame (target-relative/camera-relative/facing-neutral);
- committed world-space evade direction;
- requested displacement and achieved swept displacement;
- blocking collision/hit result;
- Evade phase: Entry / Invulnerable Travel / Recovery;
- invulnerability active/inactive and authoritative start/end;
- incoming hit event and whether it was ignored due to immunity;
- current target at acceptance/current target now;
- source state (Free/Guard/etc.);
- post-Evade transition availability;
- animation state separately;
- gameplay↔animation mismatch warnings.

### Tune
Prototype values:
- evade distance and speed curve;
- Entry/Invulnerable/Recovery durations;
- immunity start/end within action;
- neutral back-evade distance if distinct;
- bounded collision slide behavior if used;
- visual blend/playback values that do not alter gameplay timing.

No stamina value exists in this decision.

### Exercise
One-click/debug scenarios:
- directional evade left/right/forward/back under lock;
- unlocked camera-relative evades;
- neutral back-evade;
- evade into wall/corner/pillar;
- evade toward ledge;
- evade through an ordinary melee swing timing matrix;
- evade projectile timing;
- request Evade during Light/Heavy phases;
- Guard Active → Evade;
- Guard Reaction → Evade rejection;
- target switch during Evade;
- target loss during Evade;
- repeated high-frequency Evade presses;
- force reset/death during immunity and verify cleanup.

### Validate
Detect at minimum:
- teleport/non-swept movement through blocking geometry;
- collision disabled because invulnerability is active;
- animation notify being sole owner of immunity without action contract;
- immunity beginning before request acceptance;
- immunity lasting through full animation/recovery accidentally;
- held input auto-repeating Evade;
- double-tap required;
- multiple queued Evades;
- active Evade freely canceling into attacks/Guard during core travel;
- Guard Reaction improperly canceled by Evade;
- target switch redirecting committed Evade path;
- camera yaw rotating an already accepted unlocked Evade;
- stale immunity after interrupt/reset/death;
- world capsule shrinking without authority;
- frame-rate-dependent immunity/hit result.

### Capture
Record:
- input request/accept/reject;
- source state;
- direction sample/frame;
- phase transitions;
- immunity start/end;
- movement request/resolution/collision hits;
- incoming hit attempts and immunity result;
- target changes;
- Guard/attack transition requests;
- animation markers/state;
- reset/termination reason.

---

## Representative test matrix

### Direction
- locked left/right/forward/back;
- neutral locked;
- unlocked with camera at multiple yaw angles;
- neutral unlocked;
- change stick/camera immediately after acceptance.

Expected: one direction is resolved at acceptance and remains committed.

### Collision honesty
- wall directly in path;
- diagonal wall;
- narrow doorway;
- pillar/corner;
- enemy body collision as configured by combat collision authority;
- ledge/drop.

Expected: no phasing/teleport; achieved displacement is explainable.

### Immunity timing
- hit just before immunity starts;
- hit exactly near start;
- hit mid-window;
- hit near end;
- hit during Recovery;
- rapid multi-hit crossing the window boundary.

Expected: only authoritative interval ignores eligible combat hit resolution.

### Attack/Guard integration
- Evade from Free;
- Evade during Light Startup/Active/Recovery;
- Evade during Heavy Startup/Active/Recovery;
- Guard Active → Evade;
- Guard Reaction → Evade;
- Guard input held/toggled across Evade.

Expected: explicit transition graph; no universal cancel.

### Repetition
- hold Evade;
- mash Evade during current action;
- press new Evade at first legal post-Recovery frame;
- alternate left/right successive legal evades.

Expected: no hidden queue/chain/immunity stacking.

### Target integration
- switch target before acceptance;
- switch during Entry/Invulnerable/Recovery;
- target dies during Evade;
- hard occlusion breaks lock during Evade.

Expected: current path does not rewrite; normal targeting authority persists.

### Robustness
- 30/60/120+ FPS;
- controller/keyboard;
- altered animation playback speed;
- replacement longer/shorter evade animation;
- reset/death during every phase.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary sources
Epic's movement APIs provide swept, collision-aware movement and explicit impact results. `UMovementComponent` exposes `SafeMoveUpdatedComponent`, penetration resolution, and surface-slide utilities; `MoveComponent` can sweep to a destination and stop on blocking collision. These primitives demonstrate that Stillring can implement evade displacement without teleporting or disabling world collision.

Primary references:
- Epic Unreal Engine 5.8 `UMovementComponent` API;
- Epic Unreal Engine 5.8 `MoveComponent` API;
- Epic Unreal Engine 5.8 `SlideAlongSurface` / movement utilities.

These are feasibility references, not policy authority.

### Shipped-game / official problem study
PlayStation's official *God of War Ragnarök* combat guide treats dodging as both damage avoidance and repositioning, while explicitly warning that timing and resulting positioning matter. Its accessibility options also expose a separate `Evade Assist` that increases immunity, demonstrating that immunity amount can be treated as a deliberate tuning/accessibility dimension rather than an invisible engine rule.

Stillring adopts the abstract lesson that evade should combine **position + bounded timing forgiveness**, but uses its own one-press committed displacement, no double-tap chain, no roll taxonomy, and no inherited timing values.

### Accessibility basis
Current Microsoft Xbox accessibility metadata treats rapid multi-press/QTE-like requirements and required prolonged holds as accessibility concerns. Stillring therefore uses one remappable press per Evade and does not require double-tapping or rapid repetition.

No exact timing, distance, animation, input layout, immunity duration, or proprietary implementation from reference games is copied.

---

## Why this package is approved
Combat #5 gives Stillring a defensive movement verb that remains physically honest while recognizing the practical ambiguity of 3D melee overlap.

It rejects both extremes:
- **zero forgiveness regardless of visible dodge success**;
- **long genre-standard roll invulnerability that lets the player phase through attacks/world logic**.

The result is position-first defense with one short, inspectable immunity interval.

---

## Player-facing acceptance
Combat Decision #5 passes when:
1. one remappable press requests one Evade; no double-tap or hold-repeat is required;
2. Sprint and Jump remain separate actions;
3. evade direction is resolved from existing locomotion frames at acceptance and is then committed;
4. neutral Evade is a predictable backward retreat relative to Neris's facing;
5. movement is swept/collision-honest and cannot phase through walls/doors;
6. the main defense is displacement, supported by a short central combat-immunity interval;
7. Entry and Recovery are vulnerable; exact immunity timing is action data;
8. immunity affects eligible combat hits, not world collision;
9. Light/Heavy do not gain universal Evade cancellation;
10. stable Guard may transition to Evade, but Guard Reaction cannot be erased by it;
11. Evade cannot freely cancel into attack/Guard during core travel;
12. repeated Evade is successive legal actions, not a queued chain or immunity stack;
13. no stamina/resource cost is assumed;
14. target lock persists normally and target changes do not redirect a committed Evade;
15. no dodge attack/perfect-dodge reward/slowdown is silently bundled;
16. Combat IDE explains direction, collision, displacement, phase, immunity, incoming-hit result, transition legality, and cleanup;
17. exact timing values and any future Evade Timing Assist remain human-play tuning/separate accessibility authority.

---

## Next combat decision
**Combat Decision #6 — hit reaction / interrupt hierarchy.**

Research independently before approval. Define how incoming hits are classified, when damage does not interrupt, when an action is interrupted, what hard stagger means, how Guard/Evade results enter the hierarchy, how simultaneous death is resolved, whether Heavy ever earns continuation under light hits, and how the system avoids both 'every hit stunlocks' and hidden hyper-armor.
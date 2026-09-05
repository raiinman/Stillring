# 42 — Gate 2 Combat Hit Reaction / Interrupt Hierarchy Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #6 for Issue #3. This file defines how successful incoming hits resolve against Neris's current combat state after attack commitment, Guard, and Evade are locked.

## Authority
Combat Decision #6 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

This decision answers:
- how incoming hits declare reaction force;
- how damage and reaction are separated;
- when a hit causes no action interruption, a short reaction, an interruption, a hard stagger, Guard Reaction, or death;
- whether Heavy has hidden armor;
- how repeated hits avoid indefinite reaction-reset loops without granting damage immunity;
- how simultaneous/competing outcomes are prioritized;
- what the Combat System IDE must expose.

It does **not** yet define Perfect Guard/parry, final global input buffering, exact attack-facing assistance, universal combat resources, enemy AI/aggression, or death/retry flow.

Combat principle:
> **Commit to the meaningful decision, not to decorative dead time.**

Hit-reaction principle:
> **Every hit has a reasoned result. Nothing stunlocks forever; nothing shrugs off impact by accident.**

---

## Combat Decision #6 — hit reaction / interrupt hierarchy — LOCKED

### Damage result and reaction result are separate
A successful incoming combat hit produces at least two semantic outputs:
1. **damage/effect resolution**;
2. **reaction/interrupt resolution**.

They may correlate, but they are not the same variable.

Examples:
- a damage-over-time tick may deal damage with `DamageOnly` reaction;
- a normal melee hit may deal damage and interrupt an attack;
- a hard impact may deal modest damage but create `HardStagger`;
- a valid Guard result may prevent normal direct HP damage and enter `GuardReaction`;
- Evade immunity may reject the hit entirely before damage/reaction resolution.

Animation is selected from the authoritative result; it does not decide the result.

### Incoming attacks declare reaction force explicitly
Every damaging combat effect that can produce a hit reaction must declare an authored **ReactionForce**.

Gate 2 baseline classes:
- `None` — no hit reaction requested; damage/effect only;
- `Light` — readable small impact appropriate to ordinary direct hits on an uncommitted/free target;
- `Interrupt` — explicitly breaks interruptible current actions;
- `Hard` — forces `HardStagger` unless a higher-priority invulnerability/death rule supersedes it.

Exact enum/type names are implementation choices; semantic classes are locked.

ReactionForce may not be inferred only from:
- damage number;
- animation size;
- VFX color;
- enemy rank;
- weapon mesh size.

Those may inform authored data, but gameplay data must explain the result.

### Authoritative reaction outcomes
After hit validation, the defender state resolves one of these baseline outcomes:
- `NoHit` — hit did not resolve, e.g. active Evade immunity or invalid collision;
- `Blocked` / `GuardReaction` — Combat #4 handled a valid ordinary block;
- `DamageOnly` — effect applies, current action/state is not interrupted;
- `LightReact` — short visible gameplay reaction appropriate when no more committed action needs breaking;
- `Interrupt` — current interruptible action terminates and Neris enters a short hit-recovery reaction;
- `HardStagger` — stronger forced loss-of-action state with longer/clearer recovery;
- `Death` — terminal combat outcome for the current life, finalized by later death/retry authority.

Every resolved hit must expose one exact outcome and reason.

### Priority order
When multiple candidate outcomes compete on the same authoritative hit resolution, use this semantic priority:

```text
Invalid / Evade-NoHit
    ↓
Death
    ↓
Valid Guard result
    ↓
HardStagger
    ↓
Interrupt
    ↓
LightReact
    ↓
DamageOnly
```

Clarifications:
- Evade `NoHit` means the hit never reaches damage/reaction resolution.
- Death outranks reaction animation; Neris does not finish a normal hit-stun before dying.
- Valid Guard replaces the unguarded reaction path for that hit.
- `HardStagger` outranks ordinary `Interrupt`.
- this is outcome priority, not a claim that all attacks can request every class.

### Baseline direct melee/projectile hits should feel like hits
An ordinary direct weapon/projectile impact on an unguarded, non-invulnerable Neris should normally request at least `Light` reaction force.

`DamageOnly` is reserved primarily for effects where no physical interruption is intended, such as:
- authored damage-over-time ticks;
- persistent status damage;
- tiny environmental damage where a reaction would be more disruptive than informative;
- explicitly reviewed special effects.

Do not make ordinary sword/club/projectile contact `DamageOnly` merely to keep player attacks flowing.

### Normal direct hits interrupt committed player attacks unless explicit future stability authority says otherwise
Gate 2 baseline does **not** grant hidden super armor to Light or Heavy.

When Neris is in Light or Heavy Startup/Active and receives a valid unguarded hit with sufficient reaction force for interruption:
- the attack is terminated;
- transient attack state/hit volumes/movement ownership are cleaned up;
- Neris enters the resolved hit reaction/recovery state;
- pending Light continuation is cleared;
- Heavy receives no automatic “strong attack immunity.”

Heavy's greater player-requested commitment from Combat #3 does not protect it against incoming world reactions.

Any future attack-specific armor/stability must be explicit new authority and visible in the IDE.

### `LightReact` is not hidden action armor
`LightReact` is primarily for states where no committed action must be broken, such as free locomotion/guard-lost contexts, or for explicitly authored low-force effects.

If a current committed attack is interruptible and the incoming reaction force is enough to break it, outcome is `Interrupt`, not “play a tiny flinch while secretly continuing the attack.”

Presentation may blend a short react, but gameplay state decides whether the action survived.

### `Interrupt` cleanly terminates the current action
An `Interrupt` outcome must:
- cancel/revoke current offensive active state;
- clear pending chain continuation owned by that action;
- release/correct action movement/facing authority;
- cancel temporary hit traces/volumes;
- enter a short authoritative Hit Recovery;
- expose the source attack and reason;
- let presentation blend into an appropriate reaction animation.

The prior action may not resume at its old animation time after Hit Recovery.

### `HardStagger` is a separate stronger state
`HardStagger` represents a materially stronger forced reaction than ordinary hit interruption.

Baseline semantics:
- all ordinary player-requested Light/Heavy/Guard/Evade entries are rejected while HardStagger owns the state;
- movement is strongly limited/owned by the stagger action;
- target lock may remain or break according to normal targeting validity/camera rules, but does not cancel stagger;
- exact knockback/knockdown animation family is presentation/tuning;
- HardStagger duration is gameplay authority, not animation clip length;
- no button mashing shortens it;
- later accessibility may tune presentation but cannot silently eliminate gameplay severity without explicit authority.

Gate 2 does not require every HardStagger to knock Neris to the ground; the semantic class is stronger loss of control, with exact presentation authored per representative case.

### No hidden hyper armor on Heavy
Combat #3 explicitly withheld armor. Combat #6 confirms:
- Heavy can be interrupted by an ordinary authored interrupting hit;
- Heavy can be hard-staggered by `Hard` reaction force;
- Heavy does not reduce reaction force merely because it is Heavy;
- Heavy does not gain one-hit protection;
- Heavy does not gain damage reduction.

If human testing later shows one specific committed action needs stability, add an explicit `ReactionResistance`/armor contract for that action and re-review its risk/reward. Do not infer it from animation or weapon weight.

### Guard results remain their own branch
Combat #4 remains authoritative.

For a valid ordinary block:
- the attack's normal direct HP damage is prevented as already locked;
- unguarded Light/Interrupt/Hard outcomes do not apply directly;
- the block enters Guard Reaction;
- later hit/guard severity data may make stronger guardable hits create larger Guard Reactions;
- an `Unblockable` attack bypasses ordinary Guard and resolves through normal hit reaction hierarchy.

Combat #6 does not add guard-break meters.

### Evade immunity remains a true pre-resolution rejection
During Combat #5's active invulnerability interval, an evade-eligible ordinary combat hit becomes `NoHit` for damage/reaction purposes.

- no damage;
- no reaction;
- no hit-stun timer;
- no hidden “absorbed” interrupt;
- world collision remains active.

Outside that interval, hits resolve normally.

### Reaction states have explicit gameplay recovery
`LightReact`, `Interrupt`, and `HardStagger` each own explicit reaction/recovery timing.

- exact durations remain human-play tuning;
- animation may finish earlier/later visually but cannot alter legal release time silently;
- movement/action legality after the reaction is authoritative state data;
- replacing a hit animation cannot change stun duration without reviewed gameplay data.

### Anti-loop reaction protection prevents indefinite equal/lower stun resets
Stillring must not allow a cluster of weak/ordinary hits to keep Neris in an indefinitely refreshed reaction solely because each hit restarts the full timer.

After entering `LightReact`, `Interrupt`, or `HardStagger`, the reaction state owns a short **Reaction Retrigger Protection** rule.

Locked semantics:
- incoming hits still apply normal damage/effects unless another defense says otherwise;
- stronger reaction outcomes can still escalate immediately (`LightReact -> Interrupt/Hard`, `Interrupt -> Hard`);
- equal or lower reaction force during the protected portion does **not** restart the full current reaction timer from zero;
- the hit can still play bounded additive presentation/contact feedback without extending gameplay lock;
- after the protection portion ends, a later valid hit may create a new reaction according to normal rules;
- exact protection duration/portion is prototype tuning and may differ by reaction class.

This is **anti-stunlock timing protection, not damage immunity**.

### HardStagger escalation remains possible during protection
Reaction Retrigger Protection cannot be exploited as armor against a stronger threat.

Example:
- Neris is in ordinary `Interrupt` recovery;
- another minor hit lands during protected time: damage applies, recovery is not reset;
- a `Hard` hit lands: it escalates immediately to `HardStagger`.

Death always remains highest priority.

### Repeated multi-hit attacks must author their reaction intent
A multi-hit attack may legitimately strike several times.

Authoring must distinguish:
- multiple damage contacts intended to maintain one reaction;
- a sequence where a later hit intentionally escalates reaction;
- separate attacks spaced far enough to create new reactions.

Do not rely on accidental frame timing to determine whether each hit resets stun.

The IDE must show each contact and whether retrigger protection suppressed/escalated the reaction.

### Damage accumulation during reaction remains real
Reaction protection does not create a hidden grace-health mechanic.

If multiple hits land while Neris is reacting:
- damage/effects still apply normally unless Guard/Evade/other authority prevents them;
- death can occur during reaction;
- only equal/lower **reaction timer restart** is suppressed during the protected portion.

This means crowd pressure is still dangerous without making loss of control indefinite.

### Player input during reaction is not silently executed
During `Interrupt` or `HardStagger`:
- ordinary attack/Guard/Evade/Jump/Sprint requests are rejected unless later input-buffer authority explicitly permits a near-release request to wait;
- current Decision #6 does not create that buffer itself;
- the IDE records rejected requests rather than pretending input never happened.

During a very short `LightReact`, movement/action release follows that reaction's explicit legality.

### Target lock/camera do not own hit reaction
Hit reaction can move or rotate Neris only through explicit gameplay reaction data.

- camera never chooses reaction direction;
- target lock does not suppress a hit from behind;
- knockback/reaction direction should derive from incoming impact/source geometry when relevant;
- camera continues to obey locked collision/occlusion/relationship rules rather than attaching to a reaction animation.

### Simultaneous lethal and interrupting hit resolves Death
If a hit both reduces Neris to the death boundary and would otherwise Interrupt/HardStagger:
- `Death` wins;
- current attack/Guard/Evade/reaction state terminates/cleans up under death authority;
- no normal hit-recovery state is completed first.

Exact death/retry timing remains Combat's later death decision.

### Simultaneous hits need deterministic ordering
If multiple hit events resolve in the same simulation update:
- process them deterministically using stable event/order data;
- aggregate/apply damage and choose the highest resulting reaction priority consistent with authoritative hit ordering;
- never let container iteration order randomly decide whether Neris gets LightReact versus HardStagger;
- the Combat IDE capture must preserve the actual event order and chosen winner.

Exact implementation can use stable timestamps/event sequence IDs; the determinism requirement is locked.

---

## Combat state-model requirements created by Decision #6

Minimum incoming-hit record:
- source/attack ID;
- contact/event ID and stable sequence order;
- damage/effect data;
- `ReactionForce`;
- guardability / evade-immunity eligibility from earlier authority;
- impact direction/source position where relevant;
- resolved defender state before hit;
- resolved outcome;
- outcome reason;
- reaction state entered;
- reaction start/release/retrigger-protection timing;
- whether an existing action was interrupted;
- cleanup result for that action;
- resulting health/death boundary.

Minimum current reaction data:
- `ReactionClass` (`LightReact`, `Interrupt`, `HardStagger`);
- authoritative elapsed/remaining time;
- retrigger-protection active/inactive;
- current maximum accepted reaction severity;
- movement/action ownership;
- source hit ID;
- animation state separately.

---

## Accessibility / readability

Requirements:
- no button mashing is required to shorten hit reaction/stagger;
- reaction severity must be readable through character motion/audio/VFX without depending only on camera shake/haptics;
- hit feedback must remain understandable with camera shake set to Off from Camera #16;
- repeated weak hits cannot create indefinite control-lock through timer reset;
- stronger escalation remains readable and deterministic;
- later difficulty/accessibility tuning may adjust damage or selected reaction durations only through explicit settings authority, not animation playback hacks.

---

## Combat System IDE requirements

### Inspect
Expose at minimum:
- incoming hit/event ID and sequence;
- source attack/entity;
- damage/effect result;
- ReactionForce;
- pre-hit combat state/action/phase;
- Guard/Evade pre-resolution result;
- final reaction outcome;
- reason;
- interrupted action ID if any;
- cleanup completion;
- current ReactionClass/timer;
- retrigger protection state/timer;
- suppressed equal/lower reaction attempts;
- escalation event;
- health before/after;
- death-boundary result;
- reaction direction/impact vector if used;
- animation montage/state separately;
- gameplay↔animation mismatch warnings.

### Tune
Prototype values:
- LightReact/Interrupt/HardStagger durations;
- retrigger-protection portions/durations;
- representative reaction displacement caps;
- attack-specific ReactionForce data;
- visual blend/playback values that do not change gameplay release.

### Exercise
Scenarios/tools:
- apply each ReactionForce to Free Neris;
- apply to Light Startup/Active/Recovery;
- apply to Heavy Startup/Active/Recovery;
- valid Guard and Unblockable-through-Guard cases;
- hit during Evade immunity / Entry / Recovery;
- repeated Light hits at configurable spacing;
- Interrupt then Hard escalation;
- Hard then weaker follow-ups;
- simultaneous hit events;
- lethal hit during each current state;
- altered reaction animation duration/playback rate;
- reset during reaction.

### Validate
Detect at minimum:
- reaction outcome inferred only from animation asset;
- Heavy continuing through interrupting hits without explicit armor authority;
- ordinary direct hits configured `DamageOnly` without explicit justification;
- equal/lower hits endlessly resetting reaction during protected interval;
- retrigger protection suppressing damage or death;
- stronger Hard hit failing to escalate during protection;
- reaction animation length defining gameplay recovery;
- interrupted attack leaving active hitbox/movement lock/pending chain;
- Guard/Evade result and unguarded reaction both applying to one hit;
- non-deterministic same-frame outcome ordering;
- death waiting for ordinary hit recovery;
- stale reaction/retrigger state after reset/death;
- frame-rate-dependent reaction choice.

### Capture
Record:
- every hit event with sequence/timestamp;
- damage/effect;
- ReactionForce;
- pre-resolution defense/state;
- outcome/reason;
- action interruption/cleanup;
- reaction transitions;
- retrigger suppression/escalation;
- player inputs during reaction;
- health/death changes;
- animation state/markers;
- release/reset.

---

## Representative test matrix

### Baseline outcomes
- DamageOnly effect in Free;
- Light direct hit in Free;
- Interrupt hit during Light attack;
- Interrupt hit during Heavy;
- Hard hit during each action;
- lethal version of each.

Expected: one semantic outcome with explicit reason; no hidden armor.

### Defense integration
- guardable frontal hit while Guard Active;
- unblockable hit through Guard;
- hit during Evade immunity;
- hit just before/after immunity;
- hit during Guard Reaction.

Expected: exactly one hierarchy branch owns the result.

### Stunlock red team
- ten equal Light/Interrupt hits rapidly;
- equal hits across retrigger-protection edge;
- Light then Hard during protection;
- Interrupt then Hard;
- Hard then repeated Light;
- damage sufficient to kill during protected reaction.

Expected: damage remains real; equal/lower timer reset is bounded; stronger escalation/death still works.

### Action cleanup
- interrupt Light with pending continuation;
- interrupt Heavy while hit volume active;
- interrupt action-authored movement;
- reaction animation replaced/retimed.

Expected: no ghost offense, stale queue, or animation-owned recovery.

### Simultaneous resolution
- two hits same simulation step with different ReactionForce;
- lethal + nonlethal same step;
- Guardable front + unguardable flank near-simultaneous;
- deterministic replay of same capture.

Expected: stable reproducible result.

### Robustness
- 30/60/120+ FPS;
- long/short reaction animations;
- camera shake Full/Reduced/Off;
- controller/keyboard inputs during reactions;
- reset/death at each reaction phase.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary sources
Epic's Gameplay Ability documentation explicitly models abilities as stateful executions that can block/cancel other abilities, be interrupted by game events, take temporary movement control, and coordinate animation separately. Gameplay Tags provide explicit semantic labels/queries, while Animation State Machines and Notifies are animation/presentation tools. These capabilities support a centralized reaction-result system without making AnimBP state the combat rules engine.

Primary references:
- Epic Unreal Engine 5.8 Gameplay Ability System overview;
- Epic Unreal Engine 5.8 Gameplay Tags documentation;
- Epic Unreal Engine 5.8 Animation State Machines;
- Epic Unreal Engine 5.8 Animation Notifies.

Stillring does not require GAS; these sources demonstrate implementation feasibility and separation of concerns only.

### Shipped-game / official problem study
Modern action games commonly distinguish ordinary hit reactions from stronger stagger/stun states rather than treating all contacts identically. PlayStation's official *God of War Ragnarök* materials expose a distinct stun state powerful enough to enable a separate stun-grab action, illustrating the player-readable value of semantic reaction severity. Stillring uses its own explicit reaction hierarchy rather than copying meters, timings, finishers, or presentation.

The central design problem is broader: direct hits must feel consequential, committed attacks must not secretly gain armor, and groups must not permanently remove control through repeated timer resets. Stillring solves that with authored ReactionForce plus damage-preserving anti-loop reaction protection.

No exact reaction timing, meter, animation, control layout, combo, or proprietary implementation is copied.

---

## Why this package is approved
Combat #6 closes the contradiction between offensive commitment and incoming impact:
- attacks are committed against the player's own cancel requests;
- the world can still interrupt them through explicit hit authority;
- no hidden Heavy armor exists;
- stronger hits escalate clearly;
- repeated weak/ordinary hits remain dangerous but cannot indefinitely reset control-lock.

---

## Player-facing acceptance
Combat Decision #6 passes when:
1. damage/effect and reaction outcome are independently explainable;
2. incoming hits declare semantic ReactionForce;
3. resolved outcomes include NoHit, GuardReaction, DamageOnly, LightReact, Interrupt, HardStagger, and Death as applicable;
4. ordinary direct hits do not default to invisible DamageOnly behavior;
5. interrupting hits cleanly terminate Light/Heavy and their transient state;
6. Heavy has no hidden armor/invulnerability/reaction resistance;
7. HardStagger is stronger than ordinary Interrupt and rejects normal player actions until released;
8. Guard/Evade remain distinct pre-resolution branches;
9. equal/lower hits during short Reaction Retrigger Protection can still damage but cannot endlessly restart the current reaction timer;
10. stronger reaction force can escalate immediately during that protection;
11. death always supersedes normal hit reaction;
12. same-update multiple hits resolve deterministically;
13. reaction gameplay duration is independent of animation clip duration;
14. no button mashing shortens recovery;
15. Combat IDE can explain every hit, outcome, interruption, suppression/escalation, cleanup, and death result;
16. exact timings remain human-play tuning and any future explicit action armor requires separate authority.

---

## Next combat decision
**Combat Decision #7 — Perfect Guard / timed-defense layer.**

Research independently before approval. Decide whether Stillring actually needs a precision guard above ordinary Guard; if retained, define timing semantics, payoff, attack eligibility, projectile behavior, relation to Guard Reaction, accessibility/timing assistance, and ensure it rewards deliberate reading without becoming the only viable defense.
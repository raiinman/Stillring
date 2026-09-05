# 37 — Gate 2 Combat Commitment / Cancel Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #1 for Issue #3. This file begins the Gate 2 combat authority sequence and defines what attack commitment means before light-chain, heavy, guard, evade, interrupt, buffering, or resource policy is separately decided.

## Authority
Combat Decision #1 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

This decision answers:
> **When Neris commits to an attack, what remains player-changeable before that action ends?**

It does **not** yet decide exact light-chain rules, heavy attack identity, guard timing, evade/i-frames, hit-stun hierarchy, input-buffer duration, stamina/posture, or combat animation content.

Movement principle:
> **Simple intention, capable character, honest world.**

Combat principle:
> **Commit to the meaningful decision, not to decorative dead time.**

---

## Combat Decision #1 — attack commitment / cancel philosophy — LOCKED

### Core rule
An accepted attack has a real committed gameplay interval. Neris cannot freely erase the offensive decision the instant conditions become unfavorable.

However, once the meaningful gameplay commitment has ended, animation follow-through may **not** keep the player locked merely because the clip still has frames remaining.

Stillring therefore rejects both extremes:
- **anything-cancels-anything at any time**;
- **the animation must finish before gameplay listens again**.

### Authoritative attack phases
Every player attack action must expose authoritative semantic phases:

1. **Startup** — the attack has been accepted and Neris is committing toward its active threat;
2. **Active** — the attack's offensive effect/hit opportunity is live according to its action contract;
3. **Recovery** — the meaningful offensive commitment has passed and the action is resolving toward a state where future actions may become legal.

An attack may later define explicit sub-windows such as:
- `ChainWindow`;
- `DefensiveCancelWindow`;
- `MovementReleaseWindow`;
- other action-specific reviewed windows.

Those are **permissions inside the authoritative action**, not generic animation events that automatically grant a cancel.

Exact phase durations remain prototype tuning/action data. Their semantics are locked.

### Startup is real commitment
Once an attack request is accepted into Startup:
- ordinary movement input cannot simply cancel the attack back to free locomotion;
- another ordinary attack cannot replace it unless a later approved chain/cancel rule explicitly permits that transition;
- target switching, guard, evade, interaction, jump, or another action may only interrupt Startup if that future system's own reviewed transition rule explicitly allows it;
- merely releasing the attack button does not undo a committed fixed attack unless that particular future attack is explicitly designed as charge/hold/cancel behavior;
- animation blend convenience is not permission to cancel gameplay commitment.

This gives attack choice consequence without requiring a long lockout.

### Active is the strongest ordinary commitment
During the attack's Active phase:
- ordinary locomotion/new attack requests do not cancel the current attack by default;
- player spacing remains a result of the attack's reviewed movement/facing rules, not free movement suddenly taking over mid-hit;
- guard/evade cancellation is **not assumed** and must be explicitly decided later;
- target switching may update targeting state only if later combat-target rules say the current action can consume that change; camera target authority does not itself redirect an already committed attack;
- damage/death/forced reactions follow future interrupt-priority authority rather than a generic “Active can never be interrupted” rule.

The Active phase is not invulnerability, hyper armor, or guaranteed completion. Those are separate decisions.

### Recovery is not decorative imprisonment
Recovery remains meaningful gameplay time, but it must be divided between **actual recovery commitment** and mere animation follow-through.

Rules:
- the beginning of Recovery may still reject selected actions to preserve weight/consequence;
- later Recovery may open action-specific transition windows;
- once gameplay state says locomotion/another action is legal, animation must blend/transition accordingly rather than forcing the player to wait for clip end;
- a long visual follow-through cannot silently extend recovery legality;
- animation may continue in a compatible upper/lower-body or blended form after gameplay movement authority returns, where presentation supports it;
- exact cancel-open points remain action-specific tuning/research, not one universal frame percentage.

### No universal complete cancel
Stillring does not have a global rule that guard, evade, jump, attack, target switch, or movement can cancel every attack at any time.

Cancel permission is explicit by **source action phase → requested destination action**.

Conceptually:

```text
CanTransition(CurrentCombatAction, CurrentPhase, RequestedAction, Context)
    -> Allowed | Rejected(reason)
```

Not:

```text
if new_input:
    stop_current_animation()
```

Every rejection must have a semantic reason that can be shown in the Combat IDE.

### No universal uninterruptibility either
Attack commitment does not mean attacks are immune to the world.

Future hit/interrupt authority may define external transitions such as:
- damage without interruption;
- light reaction;
- interrupt;
- hard stagger;
- death.

Decision #1 only establishes that **player-requested cancels** are explicit permissions and animation playback does not decide them.

### Intent acknowledgement must remain immediate
Physical commitment is allowed; delayed input acknowledgement is not.

When a legal attack request is accepted:
- gameplay state changes/records the accepted action immediately in the same simulation decision path;
- animation/presentation begins without an arbitrary pre-action “input lag” state;
- the Combat IDE can show the request and acceptance frame/time;
- if an action cannot start, the request is rejected for a semantic reason rather than accepted and silently waiting in an undefined state.

A later input-buffer decision may allow near-window requests to wait briefly and execute when legal. Until that decision is locked, **rejection and immediate acceptance are the only authoritative outcomes**; no hidden long queues.

### Gameplay state owns legality; animation presents and timestamps
Combat action legality belongs to authoritative gameplay state/data, C++ first.

Animation systems may:
- present the current attack/action phase;
- supply reviewed synchronization/timing markers;
- use Montage sections/blends/root motion where approved;
- signal that a reviewed timing marker was crossed;
- select appropriate visual follow-through/recovery presentation.

Animation systems may **not** independently decide:
- whether guard/evade/new attack is legal;
- whether Neris is invulnerable;
- whether damage interrupts;
- whether a chain input is accepted;
- whether movement authority has returned;
- whether an action remains committed simply because a montage is still playing.

If a Montage Notify/Branching Point is used to synchronize a gameplay phase boundary, the authoritative combat action contract must define what that marker means. Deleting/moving a notify must not silently create a new design rule.

### Animation length is not recovery length
The implementation must distinguish:
- gameplay phase duration/transition permissions;
- visual animation duration/blending.

It is valid for:
- gameplay Recovery to end before the original attack clip's nominal endpoint, with animation blending naturally into locomotion/another legal action;
- visual presentation to finish a harmless upper-body follow-through while lower-body locomotion has returned, if the action contract permits;
- an animation to be shortened/speed-adjusted during prototype tuning if needed to preserve accepted gameplay timing.

It is **not** valid for a longer replacement animation asset to accidentally increase player lockout without combat-authority review.

### Movement during attack is action-authored
Decision #1 does not assume Neris is rooted in place during attacks, nor that free locomotion continues unchanged.

Each later attack family must define:
- allowed translation during Startup/Active/Recovery;
- facing/rotation correction;
- whether movement input biases/steers that translation;
- whether target-relative facing assistance exists;
- when ordinary locomotion regains authority.

No attack may inherit animation root motion as hidden movement policy merely because the asset contains it.

### Target changes do not rewrite committed attacks automatically
Camera Decision #12 allows explicit target switching. Combat Decision #1 establishes:
- a target switch may change the current authoritative lock target when switching is legal;
- an already committed attack does not automatically vacuum/rotate/warp toward the new target merely because lock identity changed;
- each attack family must later define how much facing correction remains available by phase;
- losing/changing target never retroactively changes which direction/motion the player already committed unless that action's reviewed rules allow it.

This preserves player-owned spacing and honest attack commitment.

### Forced state priority boundary
The combat state system must support higher-priority external state changes, but Decision #1 does not finalize their exact hierarchy.

At minimum:
- Death can terminate an attack when death authority says death occurs;
- traversal/scripted ownership may reject attack entry before commitment where that state owns Neris;
- future hard interrupts may terminate attacks under explicit hit-reaction rules;
- ordinary player inputs are never promoted into “forced” transitions simply to make controls feel snappy.

### Cancellation cleanup must be explicit
Whenever a later rule legitimately cancels/interrupts an attack, the action must cleanly revoke/resolve any transient state it owns, such as:
- active hit volumes/traces;
- attack-specific movement/facing authority;
- temporary collision/query state;
- attack tags/state flags;
- pending presentation callbacks;
- temporary target/action references.

No canceled attack may leave an invisible hitbox, stale movement lock, or dangling “busy” state behind.

---

## Combat state model requirement created by Decision #1

Gate 2 should use one authoritative transition-request path rather than scattered per-animation booleans.

Minimum conceptual state data for an active attack:
- `ActionId`;
- `ActionFamily` (light/heavy/etc. once later defined);
- `Phase` (`Startup`, `Active`, `Recovery`);
- time/normalized progress within authoritative phase;
- current legal player-requested transitions;
- current externally-forced transitions/reactions once later authority exists;
- movement/facing ownership token/state;
- current target snapshot/reference where relevant;
- active offensive effect/hit state;
- rejection reason for most recent request;
- presentation animation/montage state as separate diagnostic data.

Exact C++ types/classes are implementation choices.

### State and animation must be independently inspectable
The Combat IDE must be able to show, side by side:
- authoritative gameplay action/phase;
- currently playing animation/montage/section;
- timing marker/notify state;
- whether animation and gameplay are synchronized;
- why a requested transition is legal/illegal.

If gameplay says `RecoveryComplete` but animation is still blocking transition, that is a bug.

---

## Accessibility / input boundary

Decision #1 minimizes arbitrary input lock but does not erase commitment.

Requirements:
- remapping later applies to combat actions without changing phase legality;
- Hold/Toggle accessibility for future actions may change input ergonomics but not attack commitment unless explicitly designed;
- no rapid button mashing/QTE is required to escape normal attack recovery;
- critical acceptance/rejection cannot be communicated solely by camera shake/haptics;
- when a request is rejected because the attack is committed, animation/state feedback should make the reason understandable rather than feel like dropped input.

Input buffering is deliberately deferred to a later combat decision so accessibility and responsiveness can be tuned against real chain/guard/evade windows instead of guessed now.

---

## Combat System IDE requirements

The Combat workbench must exist from the first combat prototype and expose the commitment model directly.

### Inspect
At minimum show:
- current high-level combat state;
- active `ActionId` / action family;
- phase: Startup / Active / Recovery;
- phase start time, elapsed, expected/tuned boundary;
- legal requested transitions *right now*;
- rejected transition requests + semantic reason;
- whether an external forced transition is currently possible/queued;
- movement authority owner;
- facing/rotation authority owner;
- target identity at action start and current lock target;
- attack effect/hit-active state;
- current animation asset/montage/section;
- current animation playback time/rate;
- relevant notify/branch marker events;
- gameplay↔animation phase mismatch warning;
- input request timeline.

### Tune
Only reviewed prototype values:
- Startup/Active/Recovery timing boundaries;
- per-transition permission windows once later decisions add them;
- action movement/facing windows once later decisions add them.

Every live change must use canonical/session/staged/promoted provenance from `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

### Exercise
At minimum:
- start a representative attack from free locomotion;
- request movement/new attack/lock switch/placeholder defensive actions at selected phase timestamps;
- force phase advance for debug without changing canonical timing;
- interrupt/cancel through a debug-only explicit external event;
- reset combat state cleanly;
- replay captured input/action timeline.

### Validate
At minimum detect:
- animation clip length implicitly defining gameplay recovery;
- animation notify granting a transition not present in action contract;
- legal gameplay transition blocked by animation playback;
- attack canceled while hit volume remains active;
- state stuck busy after montage end/cancel;
- ordinary input canceling Startup/Active without explicit permission;
- action data with undefined phase/transition ownership;
- transition path with no semantic rejection reason;
- target switch automatically warping an already committed attack;
- movement authority accidentally reverting to free locomotion during a committed phase;
- animation replacement changing gameplay lockout without reviewed action-data change.

### Capture
Capture a deterministic combat timeline containing:
- input requests;
- accept/reject results;
- action/phase transitions;
- target changes;
- movement/facing ownership changes;
- offensive-effect active windows;
- external interrupt events;
- animation/montage markers;
- frame/time stamps.

This should allow a “why couldn't I dodge/attack/move?” bug to be diagnosed without video archaeology alone.

---

## Representative test matrix

### Basic commitment
- press representative attack once from free state;
- attempt ordinary movement cancel during early Startup;
- attempt another attack during Startup;
- attempt another attack during Active;
- attempt movement during Active;
- attempt actions throughout early→late Recovery;
- hold movement continuously before/during/after attack;
- release attack input after acceptance.

Expected: transitions follow explicit action permission rather than clip endpoint.

### Animation mismatch red-team
- attack animation artificially lengthened while gameplay phase data unchanged;
- animation shortened;
- playback rate changed;
- notify moved early/late;
- montage interrupted externally;
- visual follow-through still playing after gameplay movement returns.

Expected: mismatches are visible/validated; animation asset edits do not silently rewrite combat legality.

### Target/camera integration
- attack while unlocked;
- attack while locked;
- switch target during each phase where targeting service permits request;
- lose target during Startup/Active/Recovery;
- camera collision/Close Quarters while attack remains committed;
- shake 0%/100% during attack.

Expected: camera/target changes do not automatically rewrite committed attack motion/facing.

### State ownership
- attempt attack while hanging/ladder/mantle/swim states where later combat entry is currently unsupported;
- debug external interrupt during Startup/Active/Recovery;
- debug death during attack;
- cancel/interrupt repeatedly to check cleanup;
- restart attack immediately after legitimate recovery completion.

### Frame/input robustness
- 30/60/120+ FPS;
- short tap versus held attack input;
- repeated button mash during committed phase;
- controller and keyboard inputs;
- no hidden queued action persists indefinitely after rejection.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
Unreal provides multiple implementation mechanisms for explicit action cancellation/blocking without requiring animation assets to become state authority:
- Gameplay Abilities expose `CanActivateAbility`, `CommitAbility`, `CancelAbility`, `CanBeCanceled`, and block/cancel tags;
- Lyra demonstrates independent, replaceable, and blocking activation groups plus tag-mediated concurrency/cancellation;
- Animation Montages provide sections/runtime control, while Montage Notifies/Notify Windows can provide timing markers;
- Montage Branching Points provide more precise synchronous notify timing for gameplay-altering boundaries;
- `Disable Root Motion` notify states illustrate that animation movement presentation and user movement authority can be separated during montage playback.

References:
- https://dev.epicgames.com/documentation/unreal-engine/using-gameplay-abilities-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/abilities-in-lyra-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/animation-montage-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/animation-notifies-in-unreal-engine

These are implementation primitives, not a requirement that Stillring use GAS or Lyra's exact architecture. Stillring may use a smaller C++ combat state/transition service if that better preserves explicit authority and IDE readability.

### Shipped-game / developer problem study
Historical and modern action-game developers consistently identify **responsiveness versus commitment** as a deliberate authored tradeoff rather than something animation should decide accidentally.

- Former God of War combat designer Eric Williams described “partial cancel” versus “complete cancel” systems and pre-/post-hit windows. His examples show that stronger actions can deliberately have stricter cancel rules while basic attacks can be more permissive.
- PlatinumGames' NieR:Automata team described using a dedicated test/tool environment to fine-tune exactly when attack animations can cancel into other actions because input-to-action response must feel excellent.
- Bayonetta 2 director Yusuke Hashimoto described combat responsiveness as minimizing inconsistency between player intention and what happens on screen.
- God of War encounter design demonstrates the complementary requirement that enemy attacks visibly ask the player for distinct defensive answers; player commitment therefore has to remain readable/fair rather than arbitrary.

References:
- https://www.gamedeveloper.com/game-platforms/combat-canceled-i-god-of-war-i-action-game-design
- https://www.platinumgames.com/official-blog/article/8997
- https://www.gamedeveloper.com/design/-i-bayonetta-i-s-combat-design-philosophy-creating-a-direct-link-to-your-brain
- https://blog.playstation.com/2019/02/01/how-santa-monica-studio-created-god-of-wars-greatest-challenge/

Stillring takes the abstract lessons only: define cancel permissions deliberately, make intention acknowledgement immediate, retain meaningful commitment, and instrument/tune the transitions. It copies no exact cancel frames, combo rules, animations, control mappings, hit-stop values, attack motion, or presentation.

### Zelda lineage / Stillring synthesis
`docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` locks the broader principle that physical weight may exist but delayed intention acknowledgement should not, and animation may not introduce hidden input lock contrary to gameplay authority.

Combat extends that principle: an attack may intentionally own Neris for a reviewed committed interval; the player must never be locked merely because animation presentation forgot to give control back.

---

## Why this package is approved
Decision #1 establishes the minimum state contract needed before every later combat question:
- chains need a source phase/window to chain from;
- heavy attacks need a clear meaning for stronger commitment;
- guard/evade need explicit cancel edges;
- hit reactions need external interrupt priority;
- buffering needs legal-window targets;
- facing assistance needs phase ownership;
- stamina/posture should not be invented before commitment itself creates meaningful choices.

It therefore intentionally locks **the transition grammar** before locking any particular defensive/offensive move's permissions.

---

## Player-facing acceptance
Combat Decision #1 passes when:
1. accepted attack input is acknowledged immediately;
2. attacks have explicit Startup / Active / Recovery gameplay phases;
3. Startup/Active cannot be freely erased by ordinary movement/new attacks;
4. Recovery retains meaningful consequence but does not force the player to wait for decorative animation completion;
5. every player-requested cancel is an explicit source-phase→destination permission;
6. future hard interrupts/death can still terminate attacks under their own authority;
7. animation/montage state never independently decides action legality;
8. changing animation length does not silently change gameplay lockout;
9. movement/facing during attacks must be explicitly authored by later attack-family decisions rather than inherited from root motion;
10. changing/losing target does not automatically warp a committed attack;
11. cancel/interrupt cleanup leaves no stale hitbox/movement lock/busy state;
12. Combat IDE can explain every accept/reject/phase/cancel decision and detect gameplay↔animation divergence;
13. input buffering, light-chain rules, guard, evade, i-frames, and interrupt severity remain cleanly separate later decisions rather than being smuggled into this package.

---

## Next combat decision
**Combat Decision #2 — light attack chain semantics.**

Research independently before approval. Define what one press means, chain depth/philosophy, when the next light request is accepted, whether early presses buffer, what missing a window does, how movement/facing/target changes interact, and what distinguishes a light chain from an automatic combo movie. Do not infer these rules from Decision #1 or generic action-game conventions.
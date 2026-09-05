# 39 — Gate 2 Combat Heavy / Committed Attack Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #3 for Issue #3. This file defines the representative Gate 2 heavy/committed attack semantics after Decision #1 locked attack commitment/cancel grammar and Decision #2 locked the baseline light chain.

## Authority
Combat Decision #3 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

This decision answers:
- whether the representative Gate 2 Heavy attack is fixed or charge/hold based;
- what makes Heavy materially different from `Light_3`;
- how its commitment, movement, facing, target changes, and player-requested cancels behave;
- what payoff Heavy earns without prematurely inventing stamina, posture, armor, or guard-break rules;
- what the Combat System IDE must expose to make that commitment explainable.

It does **not** yet define guard, evade/i-frames, hit-reaction/interrupt hierarchy, final input buffering, attack-facing assistance for every action family, combat stamina/posture, or final weapon roster.

Combat principle:
> **Commit to the meaningful decision, not to decorative dead time.**

Heavy principle:
> **Power is earned by visible commitment, not by hidden tax.**

---

## Combat Decision #3 — heavy / committed attack semantics — LOCKED

### Representative Gate 2 Heavy is a fixed committed attack
The representative Gate 2 Heavy Attack is a **distinct press-to-commit action**, not a hold-to-charge action.

Rules:
- one distinct Heavy press requests one Heavy action when legal;
- acceptance enters Heavy Startup immediately under Decision #1;
- holding the Heavy input does not automatically charge, repeat, or alter the action;
- releasing the button after acceptance does not cancel the action;
- there is no hidden minimum-hold threshold;
- there are no charge levels in the baseline Gate 2 Heavy;
- future weapons/tools may earn charge/hold attacks only through their own explicit decision authority.

This choice is deliberate. Charge attacks introduce another timing state, release semantics, partial-charge behavior, accessibility questions, and balance surface. Gate 2 first needs one clean high-commitment action that proves the state model before that complexity is justified.

### Heavy is not `Light_3`
`Light_3` remains the conclusion of the baseline Light family. Heavy is a separate action family with its own request, action data, transition permissions, and commitment profile.

Heavy must differ from light through gameplay semantics, not merely a larger damage number pasted onto the same timing:
- more readable Startup commitment;
- a stronger offensive consequence budget on hit;
- narrower player-requested cancel permissions;
- less late facing correction;
- more deliberate movement ownership;
- a more meaningful miss/recovery consequence;
- stronger presentation appropriate to its gameplay weight.

Exact damage, hit reaction, guard pressure, armor interaction, and resource values remain separate later authority.

### Heavy has visibly greater commitment
Compared with a baseline light entry, Heavy should normally have:
- longer and more legible Startup;
- an unmistakable committed Active interval;
- meaningful Recovery before ordinary freedom fully returns;
- less ability to redirect after commitment;
- a miss that creates a real but fair opening.

Exact durations remain prototype tuning. The semantic ordering is locked: Heavy cannot end up being a light attack with an inflated damage scalar and identical freedom.

### Player-requested cancels are stricter than Light
By default for the representative Heavy:
- ordinary locomotion cannot cancel Startup or Active;
- Light Attack cannot cancel Heavy Startup or Active;
- another Heavy cannot replace the current Heavy during Startup or Active;
- Jump cannot cancel Heavy Startup or Active;
- target switching may change lock state if targeting authority allows it, but does not cancel or rewrite the current Heavy;
- future Guard/Evade may only cancel Heavy where their own later decisions explicitly create a source-phase→destination transition;
- late Recovery may later expose reviewed defensive/offensive transition windows, but none are assumed now.

Heavy is still interruptible by future world/hit/death authority. “Player cannot freely cancel this” does **not** mean super armor or invulnerability.

### Heavy earns payoff without assuming a stamina tax
Ordinary Sprint remains free and Decision #3 does not add universal combat stamina.

The representative Heavy earns its place through **commitment-for-payoff**, not a resource fee.

At prototype level, Heavy must deliver a materially stronger successful-hit result than one baseline light entry. That may be represented during early testing by a higher damage/effect scalar and stronger presentation, while later decisions determine whether Heavy also has special interaction with:
- guard integrity;
- posture;
- armor;
- interrupt severity;
- enemy stagger thresholds;
- destructible/combat objects.

None of those future mechanics are silently locked here.

If later testing shows Heavy only feels worthwhile when given an arbitrary stamina cost or hidden armor privilege, the action design should be re-examined rather than assuming the tax is mandatory.

### Heavy Startup communicates risk before Active
A Heavy attack must visibly telegraph its commitment to the player through Neris's own motion before its offensive effect becomes Active.

Requirements:
- the Startup silhouette should clearly differ from ordinary light cadence;
- acceptance feedback is immediate even though the hit arrives later;
- the player should be able to understand “I committed to a stronger action” without HUD timing bars;
- the startup cannot be padded with decorative delay that has no gameplay purpose;
- replacing the animation asset may not silently extend the authoritative Startup phase.

### Heavy Active is not automatic tracking authority
The current committed Heavy does not chase a changing target merely because lock-on identity changed.

During Heavy Active:
- no free target vacuum/teleport occurs;
- no hidden orbit around the target occurs;
- target switching does not rotate the strike after the action's approved facing-correction window has closed;
- exact bounded pre-Active facing assistance remains a later combat-facing decision;
- collision/world geometry remains honest.

A Heavy may miss. Missing is part of the commitment contract, not a camera/targeting failure that must be corrected by magnetism.

### Heavy movement is action-authored, not free locomotion and not animation accident
Decision #3 establishes the following movement boundary:
- ordinary free locomotion does not remain fully authoritative during Heavy Startup/Active;
- a Heavy may contain a small, authored commitment step/lunge if the final action data later requires it;
- such translation must be explicit gameplay authority, capped, inspectable, and collision-respecting;
- animation root motion may present that movement only if it matches approved gameplay movement authority;
- Heavy may not vacuum Neris across large distances to guarantee contact;
- once Recovery returns ordinary locomotion authority, animation must blend accordingly rather than keeping the player rooted until clip end.

Exact Heavy translation distance and movement-input influence remain tuning/future facing-movement authority.

### Facing correction closes earlier than ordinary light intent
Heavy should ask the player to choose direction/target with more care.

Semantic rule:
- some bounded facing correction may be allowed during early Startup under a later facing-assistance decision;
- that correction must diminish/close before or by the committed Active portion;
- after the correction window closes, target changes do not rewrite the swing direction;
- Heavy cannot spin sharply late in Startup/Active simply to preserve hit chance.

The exact angular limits/timing are deferred, but Heavy's relative philosophy is locked: **less late correction than baseline light**.

### Heavy can be started from Free; Light→Heavy chaining is not assumed
The baseline authoritative entry is:

```text
Free / eligible combat state -> Heavy -> Recovery -> Free / later legal transition
```

Decision #3 does **not** automatically create:
- `Light_1 -> Heavy`;
- `Light_2 -> Heavy`;
- `Light_3 -> Heavy`;
- Heavy -> Light chain links;
- Heavy -> Heavy loops.

Those transition edges must be researched/authorized separately if desired. Until then, Heavy begins only from states that explicitly list Heavy as legal.

This prevents the current decision from quietly turning the simple Light chain into a branching combo tree.

### Heavy miss recovery must be meaningful but not decorative imprisonment
A Heavy that whiffs should create more exposure than a baseline light miss, but Decision #1 still applies:
- recovery length is gameplay authority, not animation clip length;
- once legal movement/action authority returns, presentation must release cleanly;
- no arbitrary extra lockout is added because a dramatic follow-through animation is long;
- exact whiff-versus-hit recovery differences are not assumed here and require explicit action data if later desired.

### Hit confirmation does not retroactively change commitment by default
Heavy does not require a hit to be a valid completed action.

- hit or miss both resolve through the Heavy action contract;
- a successful hit does not automatically grant a free cancel;
- a miss does not create a special stumble unless explicitly authored later;
- target death during Startup/Active does not automatically retarget the Heavy to another enemy;
- damage/hitstop may affect presentation but cannot silently rewrite phase legality.

### No default armor / hyper-armor privilege
Heavy commitment is **not** permission to ignore incoming attacks.

Decision #3 does not grant:
- super armor;
- hyper armor;
- invulnerability;
- poise immunity;
- damage reduction;
- guaranteed completion.

Future hit-reaction/interrupt authority decides whether specific incoming attacks allow Heavy to continue, interrupt it, or hard-stagger Neris.

The Combat IDE must distinguish “player-requested cancel rejected because Heavy is committed” from “external hit did/did not interrupt Heavy.”

### No charge semantics hidden in animation or input system
Because baseline Heavy is fixed:
- input `Ongoing`/hold duration cannot scale damage;
- release timing cannot select a stronger Heavy variant;
- animation pose duration cannot become an undocumented charge meter;
- holding Heavy cannot indefinitely delay the attack;
- a designer cannot add a charge notify and thereby create new gameplay authority.

If a future charged attack is proposed, it requires an explicit separate contract for begin-charge, minimum charge, release, cancel, max charge, overcharge, movement, accessibility, and resource interactions.

---

## Combat state-model requirements created by Decision #3

Minimum Heavy action diagnostics/data:
- `ActionFamily = Heavy`;
- `ActionId`;
- Startup / Active / Recovery phase;
- authoritative phase boundaries;
- current player-requested transitions allowed/rejected;
- movement authority owner;
- facing correction availability state;
- action-authored translation request/resolution where applicable;
- target snapshot at Heavy acceptance;
- current lock target separately;
- offensive effect active state;
- hit/miss result for correlation;
- external interrupt result once later authority exists;
- current animation/montage state as presentation-only diagnostics.

Heavy legality must travel through the same authoritative transition path created by Decision #1.

---

## Accessibility / controls boundary

The fixed Heavy baseline intentionally avoids requiring a long hold or precisely timed release to access the core committed attack.

Requirements:
- Heavy is a remappable semantic action;
- one valid press is sufficient to request it;
- no rapid repeated tapping is required to increase Heavy power;
- no hold duration is required for baseline Heavy;
- rejection/acceptance must be understandable through animation/state/UI/audio combinations rather than shake/haptics alone;
- future simplified-combat or timing assists may not silently change Heavy legality without their own authority.

This aligns with modern accessibility guidance that discourages required rapid repeated presses and prolonged holds when avoidable.

---

## Combat System IDE requirements

### Inspect
At minimum expose:
- Heavy request frame/time;
- accepted/rejected + semantic reason;
- active Heavy `ActionId`;
- Startup/Active/Recovery and elapsed/remaining authoritative time;
- legal transition list by phase;
- movement authority owner;
- authored translation requested/resolved;
- facing correction allowed/closed state;
- target at acceptance/current target;
- hit/miss result;
- external interrupt event/result once defined;
- animation/montage/section/playback time separately;
- gameplay↔animation mismatch warnings;
- recovery-complete versus animation-still-playing warning.

### Tune
Prototype values only:
- Heavy Startup/Active/Recovery boundaries;
- Heavy prototype damage/effect scalar;
- authored commitment translation cap once movement authority is approved;
- facing correction window/limits once later authority is approved;
- visual blend/playback values that do not silently change gameplay phases.

### Exercise
One-click/debug scenarios:
- Heavy from Free;
- request Light/Heavy/Jump/movement at early/mid/late Heavy phases;
- switch target during Startup and Active;
- target dies during Startup/Active;
- Heavy whiff versus hit;
- Heavy near wall/obstacle;
- Heavy while current animation playback rate is changed;
- external debug interrupt during each phase;
- reset during Heavy and verify cleanup.

### Validate
Detect at minimum:
- Heavy implemented as Light with only a damage scalar and identical commitment;
- held Heavy changing power or timing despite fixed-action authority;
- release timing canceling/charging Heavy;
- ordinary movement canceling Startup/Active;
- Light/new Heavy replacing committed Heavy without explicit transition;
- target switch warping or sharply retargeting current committed Heavy after correction closes;
- root motion causing unapproved translation/magnetism;
- animation length silently defining Recovery;
- Heavy receiving armor/invulnerability without later authority;
- stale hit volume/movement lock after interrupt/reset;
- gameplay Heavy complete while montage still blocks legal movement/action;
- frame-rate-dependent phase or request behavior.

### Capture
Record:
- Heavy request/accept/reject;
- phase transitions;
- player input requests during Heavy;
- target changes;
- movement/facing ownership changes;
- authored translation;
- hit/miss;
- external interrupts;
- animation markers/state;
- recovery release;
- reset/cleanup reason.

---

## Representative test matrix

### Input semantics
- tap Heavy once;
- hold Heavy through Startup/Active/Recovery;
- release immediately after acceptance;
- repeat Heavy presses during commitment.

Expected: one fixed Heavy; hold/release does not charge, cancel, or repeat it.

### Commitment
- move during early/late Startup;
- request Light during Startup/Active;
- request Jump during Startup/Active;
- request another Heavy;
- request each action during early/late Recovery.

Expected: transitions follow explicit Heavy phase permissions; no generic cancel.

### Target/facing
- lock target A and Heavy;
- switch to B during early Startup;
- switch to B immediately before Active;
- switch during Active;
- target dies during Startup;
- target dodges/moves outside contact.

Expected: current Heavy remains its own committed action; no vacuum or late spin.

### World honesty
- Heavy at wall;
- target just outside reach;
- target crosses behind Neris;
- Heavy on slope/stairs;
- cramped/low-ceiling camera states active.

Expected: combat action does not override collision or camera authority to guarantee contact.

### Hit/miss
- clean hit;
- whiff;
- target dies before hit;
- enemy attack externally interrupts through debug placeholder;
- future hitstop prototype on/off.

Expected: hit/miss correlates with payoff/presentation but does not invent unauthorized cancels/armor.

### Robustness
- 30/60/120+ FPS;
- controller/keyboard;
- altered animation playback rate;
- replacement longer/shorter Heavy animation;
- reset/interruption at each phase.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary sources
Enhanced Input supports distinct press/hold/release trigger semantics, and Gameplay Ability tasks can explicitly wait for release. These prove that a charged action is technically feasible but also demonstrate that charge/release is an additional state contract rather than something the engine forces onto Heavy.

Primary references:
- Epic Unreal Engine 5.8 Enhanced Input documentation — semantic trigger states and Hold behavior;
- Epic `UInputTriggerHold` API — hold threshold/one-shot semantics;
- Epic `UAbilityTask_WaitInputRelease` API — explicit release waiting/timing;
- Epic Montage/ability task APIs — completion/interruption/cancel are separate runtime outcomes.

Engine capability is not Stillring policy. Gate 2 deliberately chooses the smaller fixed-Heavy contract first.

### Shipped-game / developer problem study
Relevant abstract lessons:
- Nintendo's official *Tears of the Kingdom* tips show a hold input can build a stronger charged attack; this demonstrates a readable risk/reward family but does not make charge mandatory for Stillring.
- Capcom's official *Monster Hunter 4 Ultimate* manual describes Great Sword charged slashes where waiting increases power but over-waiting can reduce the result, showing that charge itself creates timing/commitment gameplay.
- Former *God of War* combat designer Eric Williams describes stronger attacks being less cancelable specifically to create risk/reward, while more basic attacks stay permissive.

Stillring takes the underlying lesson—**stronger payoff should be attached to visibly stronger commitment**—but chooses its own baseline expression: a fixed Heavy first, with charge deferred until a future weapon/verb proves it is worth the extra state complexity.

No exact animation, timing, control layout, damage ratio, combo string, or proprietary implementation is copied.

### Accessibility basis
Microsoft's current Xbox accessibility guidance recommends avoiding required rapid repeated inputs and prolonged holds where possible or providing alternatives. A one-press fixed Heavy gives Gate 2 a fully usable core committed attack without making hand endurance or release precision part of the baseline verb.

---

## Why this package is approved
Combat #3 gives Gate 2 a clean contrast pair:
- Light = short finite chain, one next decision at a time;
- Heavy = separate stronger commitment with reduced freedom and greater payoff.

It proves the state model can express meaningful offensive risk/reward without prematurely introducing charge tiers, stamina, posture, guard break, hyper armor, or branching combo trees.

---

## Player-facing acceptance
Combat Decision #3 passes when:
1. one Heavy press requests one fixed committed Heavy;
2. hold/release duration does not charge, repeat, cancel, or scale the baseline Heavy;
3. Heavy is visibly and mechanically more committed than one light entry;
4. Heavy cannot be freely canceled by movement/Light/Jump/new Heavy during Startup/Active;
5. future Guard/Evade cancels are not assumed;
6. Heavy earns a materially stronger successful-hit payoff without requiring a stamina tax;
7. Heavy has less late facing correction than baseline light and never vacuums to preserve contact;
8. target changes do not rewrite the current committed Heavy after its facing authority closes;
9. Heavy movement is explicit action authority, not accidental root-motion policy;
10. Heavy does not automatically gain armor, invulnerability, guard break, posture damage, or interrupt immunity;
11. `Light_3` remains Light-family authority rather than secretly Heavy;
12. Light→Heavy/Heavy→Light chain transitions are not assumed;
13. animation length cannot silently extend Heavy recovery;
14. Combat IDE can explain every Heavy request, phase, movement/facing owner, transition rejection, target change, hit/miss, animation mismatch, and reset;
15. exact charge mechanics, guard/evade, hit-reaction hierarchy, facing limits, resources, and buffer timings remain separate decisions.

---

## Next combat decision
**Combat Decision #4 — guard model.**

Research independently before approval. Define hold/toggle semantics, coverage direction, ordinary block versus timed defense, what successful block changes, whether guard has integrity/cost, how guard interacts with attack Recovery, projectiles, target lock, accessibility, and what belongs to a later perfect-guard/parry decision rather than being silently bundled here.
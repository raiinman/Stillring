# 56 — Gate 2 Enemy Reaction / Interrupt Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #7 for GitHub Issue #104. Defines how enemy damage, hit acknowledgement, interruption, displacement, stagger, shield-state change, and resistance resolve when Neris lands attacks.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Enemy-reaction principle:
> **Make impact visible. Make interruption earned. Never hide the rule in a meter the player cannot reason about.**

This decision is compatible with:
- player Combat #6's separation of damage and reaction outcomes;
- Encounter #1 commit reservations and deterministic cleanup;
- Shield #4's explicit `Shielded` / `ShieldDisplaced` / `Exposure` states and explicit rejection of a universal enemy posture meter;
- Telegraph #5's requirement that a committed tell remains honest unless a visible legitimate interrupt ends it.

---

## Decision #7 — enemy reaction / stun / poise / guard-break — LOCKED

### 1. No universal enemy poise or stun meter
Gate 2 does **not** introduce one shared hidden or visible posture/stun resource that every enemy accumulates until it breaks.

Reasons:
- ordinary melee, ranged, shield, elite, and boss-scale enemies have different physical/tactical jobs;
- one meter would pressure every player attack into being partly 'stun damage';
- it would duplicate already-explicit shield state and attack-commit rules;
- it encourages balance through invisible thresholds rather than readable action/state;
- Stillring currently has no design need for a global execution/stun-grab loop.

A future specific archetype may own an explicit authored stability resource if its gameplay truly requires one, but that would be a separate visible/inspectable contract—not the default enemy substrate.

### 2. Enemy damage and reaction are separate outputs
A valid player hit resolves at least:
1. damage/effect result;
2. reaction result.

A hit can:
- deal damage and only acknowledge contact;
- deal damage and interrupt;
- deal damage and force stronger stagger/displacement;
- change a shield-specific state;
- kill without first completing a normal reaction.

Animation presents the resolved result; it does not choose it.

### 3. Player attacks declare explicit `ImpactForce`
Every player attack capable of affecting enemy action stability declares an authored semantic `ImpactForce`.

Gate 2 baseline classes:
- `None` — no gameplay reaction requested;
- `Light` — ordinary contact acknowledgement on eligible targets/states;
- `Disrupt` — may break ordinary committed actions when target/state resistance permits;
- `Hard` — may force a stronger stagger/displacement state when target/state resistance permits.

Exact enum names are implementation choices; semantics are locked.

`ImpactForce` must not be inferred solely from:
- damage number;
- animation size;
- weapon mesh size;
- VFX intensity;
- audio loudness.

### 4. Enemies expose explicit `ReactionResistance` by archetype/state
Every representative enemy state that can be struck declares the maximum reaction it normally resists.

Baseline conceptual levels:
- `Open` — Light can visibly react; Disrupt/Hard can interrupt/escalate;
- `Committed` — Light does not cancel the committed action; Disrupt/Hard may break it if that attack/archetype allows;
- `Stable` — ordinary Disrupt is resisted; Hard or explicit state-specific answer required;
- `UninterruptibleExplicit` — only for narrowly authored windows with a visible justification; damage may still apply unless separately protected.

These are not enemy-rank labels. Resistance is stateful gameplay data.

### 5. Ordinary Light hits acknowledge impact but do not stun-lock commitments
Against an ordinary non-shield enemy in neutral/reposition/recovery states, a valid Light attack should normally produce a short visible `LightReact` or equivalent contact acknowledgement.

Against an enemy already in a committed Telegraph/Active action:
- Light damage still resolves;
- bounded contact feedback is allowed;
- the committed attack does **not** automatically cancel solely because Light connected;
- no full reaction timer is repeatedly restarted by Light spam.

This preserves attack commitment while keeping hits from looking ghostly.

### 6. Heavy earns disruption without becoming universal crowd control
The representative player Heavy is the baseline `Disrupt` answer against ordinary enemy commitments.

When Heavy connects before the target's reviewed action is no longer interruptible:
- ordinary melee/ranged enemy Telegraph may be interrupted;
- the attack's commit reservation is cleaned up deterministically;
- active hit authority is disabled if interruption occurs before/during Active according to the attack contract;
- enemy enters a short explicit `InterruptRecovery` / stagger state;
- the player gets an earned opening.

Heavy does **not** automatically:
- interrupt every boss-scale action;
- bypass explicit shield sector rules;
- knock down every target;
- guarantee launch/ragdoll;
- create an execution state.

### 7. Shield enemy keeps its specific answer set
Shield #4 remains authoritative.

Heavy interacting with the defensive shield sector causes/earns the already-approved `ShieldDisplaced` result according to that contract rather than routing through a generic posture bar.

Perfect Guard does not automatically shatter shield or trigger generic stun. It earns the already-approved tempo advantage through the attacker's real recovery/exposure.

### 8. Perfect Guard is tempo authority, not universal enemy stun
A successful Perfect Guard may:
- preserve/extend the player's approved advantage window;
- create a visible recoil response where the enemy attack contract supports it;
- interrupt specific future attacks only if that attack explicitly declares a Perfect-Guard interrupt response.

Baseline Gate 2 does not convert every Perfect Guard into `HardStagger`.

This avoids reducing defense to a guaranteed stun-button and keeps enemy recovery/action data meaningful.

### 9. `Hard` impact is a distinct authored class, not damage scaling
A `Hard` impact may force stronger reaction such as:
- pronounced stagger;
- bounded knockback/displacement;
- temporary loss of attack readiness;
- specific archetype state transition.

Gate 2 does not require the normal player Heavy to be `Hard` against every target. `Hard` is reserved for explicitly authored moves/world effects/future tools where stronger control is part of their identity.

### 10. Bosses and large enemies do not get blanket invisible super armor
Boss/large-target resistance must be explained per action/state.

Allowed:
- a huge planted attack can declare `Stable` because its mass/action presentation clearly supports it;
- a boss recovery/opening state can become `Open` and visibly respond to Light/Disrupt hits;
- a specific weak-point/tool interaction can transition resistance explicitly.

Rejected:
- `IsBoss => ignore all reaction`;
- hidden immunity because animation is inconvenient to interrupt;
- damage threshold secretly deciding whether reaction exists;
- permanent super armor with no presentation/state explanation.

### 11. Interruption must visibly terminate the old threat
When an enemy committed attack is interrupted:
- its Telegraph/Active gameplay state terminates;
- future unearned hit events are disabled;
- encounter `MajorCommit` / `PressureCommit` reservation releases at the reviewed cleanup point;
- stale animation notifies cannot resurrect the attack;
- warning UI/audio tied to that attack resolves;
- the interruption itself must be visually readable so the player knows the promised threat ended.

### 12. Already-launched projectiles remain real
Interrupting/killing a ranged enemy after projectile launch does not erase the projectile.

Projectile/world authority from Decisions #3/#6 remains intact.

### 13. Reaction anti-loop protection prevents enemy stun-lock
Stillring applies an enemy-side reaction retrigger rule similar in purpose to player Combat #6:
- damage/effects continue normally;
- equal/lower reaction attempts during a short protected portion do not restart the full reaction lock from zero;
- stronger impact may escalate immediately when target/state allows;
- death always resolves;
- exact protected portion remains tuning.

This prevents Light/fast-hit chains from creating indefinite control loss without inventing damage immunity.

### 14. Multi-hit attacks must declare reaction intent
A multi-hit player action must say whether repeated contacts:
- merely add damage during one existing reaction;
- escalate on a later authored hit;
- count as separate reaction opportunities after sufficient spacing.

Frame timing alone may not accidentally define stun-lock behavior.

### 15. Enemy reaction never grants hidden invulnerability by default
During `LightReact`, `InterruptRecovery`, or stronger stagger:
- enemy remains damageable unless explicit separate authority says otherwise;
- collision remains honest;
- death may occur;
- reaction protection suppresses repeated control-lock extension, not damage.

### 16. Reaction direction/displacement is world-causal
Where reaction uses direction or displacement:
- source comes from real hit/impact geometry;
- displacement is bounded against collision/navigation constraints;
- no camera-relative knockback;
- no teleport to preserve animation composition;
- wall collisions cannot silently turn small hits into huge damage without separate authority.

### 17. Reaction does not secretly rewrite encounter bandwidth
An interrupted commit frees its reservation through explicit cleanup. The coordinator may then hand off the next threat under Decision #1's readability boundary.

It does not:
- globally pause all enemies because the player landed Heavy;
- grant the player a universal crowd-free punish window;
- automatically transfer commit permission to the lock target;
- let several waiting enemies commit simultaneously on interruption.

### 18. Difficulty changes resistance only through explicit authored profiles
Difficulty may tune selected timings/health/damage within later authority, but cannot silently:
- make ordinary enemies immune to Heavy disruption;
- remove visible hit acknowledgement;
- disable reaction anti-loop protection;
- turn boss actions into uninterruptible states without presentation/data authority.

---

## Representative Gate 2 baseline

### Ordinary melee enemy
- neutral/reposition/recovery: `Open`;
- committed attack: `Committed`;
- Light: visible acknowledgement but no commitment break;
- Heavy (`Disrupt`): can interrupt the ordinary committed attack inside its approved interruptible interval;
- stronger future `Hard`: may force stronger stagger if authored.

### Ordinary ranged enemy
- positioning/aim-ready/recovery: `Open`;
- committed firing Telegraph: `Committed`;
- Light: acknowledgement/damage but no automatic firing cancel;
- Heavy (`Disrupt`): may interrupt before/through the reviewed launch boundary;
- projectile launched before valid interrupt remains real.

### Shield enemy
- shield-facing defense: shield-specific state contract from #4;
- Heavy against shield sector: `ShieldDisplaced` path;
- flank/open exposure: normal enemy reaction resolution applies;
- Perfect Guard: tempo/opening, not automatic generic stun.

---

## Unreal Engine 5.8 implementation boundary

Current Epic animation tooling supports montage interruption, blend-out, animation notifies/notify states, and explicit interrupted completion paths. These are useful presentation/synchronization mechanisms.

Recommended authority split:
- **authoritative enemy combat state:** damage/reaction result, `ImpactForce`, `ReactionResistance`, reaction timer, interruption cleanup;
- **encounter coordinator:** reservation cleanup/handoff;
- **animation montage/state:** presents the resolved state and may blend out on interrupt;
- **notifies/curves:** synchronization evidence only;
- **physics/navigation:** bounds legal displacement/collision;
- **Combat/Encounter IDE:** shows gameplay result versus animation state.

Animation clip length or montage interruption callback may not be the sole source of reaction legality/duration.

---

## Accessibility / readability boundary

Requirements:
- hit acknowledgement must remain readable with camera shake and vibration off;
- no reaction class depends solely on color;
- stronger stagger/displacement must be visually distinguishable from ordinary contact acknowledgement;
- player does not need to know a hidden meter value because no universal meter exists;
- reaction duration does not require button-mashing interaction;
- reduced effects must not erase the evidence that an attack was successfully interrupted.

---

## Combat / Encounter IDE requirements

### Inspect
Expose:
- player attack ID;
- damage/effect result;
- `ImpactForce`;
- enemy archetype/current state;
- current `ReactionResistance`;
- pre-hit attack phase / commit reservation;
- resolved reaction result and exact reason;
- interrupted attack ID/phase if any;
- cleanup status for hit authority/commit warning/reservation;
- current reaction class/timer;
- retrigger-protection state;
- suppressed equal/lower reaction attempts;
- escalation event;
- shield-specific state transition where applicable;
- projectile launch state separately;
- enemy health before/after;
- animation montage/state separately;
- gameplay↔animation mismatch warning.

### Tune
With provenance:
- reaction durations;
- retrigger-protection portions;
- archetype/state resistance profile;
- bounded displacement values;
- attack `ImpactForce` values only where owning player-attack authority permits prototype tuning;
- presentation blend values.

No live tuning may create a universal hidden poise meter or silently change semantic impact classes without owning authority.

### Exercise
Fixtures:
- Light/Heavy against neutral melee;
- Light/Heavy during melee Telegraph/Active/Recovery;
- Light/Heavy against ranged before/after projectile launch;
- shield front/side/rear interactions;
- Heavy causing `ShieldDisplaced`;
- Perfect Guard then punish timing;
- repeated fast Light hits;
- Disrupt then stronger Hard escalation;
- enemy against wall/corner;
- attacker interrupted while holding MajorCommit;
- attacker killed during Telegraph/Active/reaction;
- 2/3/5-enemy encounter during player disruption;
- boss/large placeholder with state-specific resistance;
- 30/60/120+ FPS.

### Validate
Detect:
- reaction inferred only from animation;
- universal posture/stun resource accidentally added to baseline enemies;
- Light spam indefinitely resetting enemy reaction;
- Light silently canceling committed action without authority;
- Heavy failing/succeeding solely due to damage number;
- generic boss flag granting blanket reaction immunity;
- interrupted attack retaining hit volume/projectile spawn/warning/reservation;
- launched projectile erased by later shooter interruption;
- shield path bypassing #4 state rules;
- Perfect Guard automatically stunning every enemy without attack-specific authority;
- reaction protection suppressing damage/death;
- reaction animation length defining gameplay recovery;
- frame-rate-dependent reaction result.

### Capture
Record deterministic timelines containing:
- player attack/input/action phase;
- hit/contact ID;
- damage/effect;
- `ImpactForce`;
- target state/resistance;
- resolved reaction/reason;
- interrupted action cleanup;
- encounter reservation release/handoff;
- reaction retrigger suppression/escalation;
- projectile persistence;
- health/death;
- animation state;
- frame/time stamps.

A designer must be able to answer:
> **Why did that Heavy interrupt this enemy but not that action?**

---

## Representative red-team tests

1. Repeated Light attacks on neutral melee: visible impact; no indefinite full reaction-reset loop.
2. Light lands during committed melee Telegraph: damage/contact feedback, but ordinary commitment continues.
3. Heavy lands during interruptible committed melee Telegraph: attack terminates cleanly and reservation releases.
4. Heavy lands after ranged projectile already launched: shooter can react/interruption, projectile remains real.
5. Heavy hits shield front: routes through `ShieldDisplaced`, not generic posture damage.
6. Perfect Guard succeeds: player earns tempo; enemy is not universally hard-stunned by rule.
7. Strong placeholder enemy uses `Stable` state: IDE explains why Disrupt did not interrupt.
8. Same enemy enters authored Open recovery: Disrupt/Light responses update visibly according to state.
9. Boss flag alone with no reaction profile: validation failure.
10. Kill committed attacker: threat cleanup and reservation release deterministic.
11. Interrupt current Major holder while another enemy is ready: next handoff obeys Decision #1 instead of same-frame dog-pile.
12. Reaction target against wall: bounded physical response, no teleport/clip.
13. Camera shake/vibration disabled: reaction severity still readable.
14. 30/60/120+ FPS: identical hit/state inputs resolve same semantic result.

---

## Research basis / design lineage

### Current primary engine references
- Epic Games, Unreal Engine 5.8, **Animation Notifies** — animation events/notify states are synchronization mechanisms with trigger/filter/timing behavior; Stillring keeps gameplay reaction authority outside them.  
  https://dev.epicgames.com/documentation/unreal-engine/animation-notifies-in-unreal-engine
- Epic Games, Unreal Engine 5.8, **Montage Stop / interruption paths** — montages can explicitly stop/blend out and expose interrupted completion behavior; Stillring uses those to present/cleanly blend an already-authoritative gameplay interrupt.  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UAnimInstance/Montage_Stop

### Shipped-game problem study
- PlayStation's official **God of War Ragnarök combat guide** distinguishes damage tools from explicit stun-focused tools (for example bare-handed attacks are described as especially good at stun damage), showing one credible shipped solution where stun is a deliberate combat axis rather than an accidental synonym for damage. Stillring deliberately does **not** copy that universal stun loop because current Stillring authority does not need one.  
  https://www.playstation.com/en-us/games/god-of-war-ragnarok/god-of-war-combat-refresher-course/
- PlayStation's official accessibility documentation exposes enemy stun state in HUD/settings and offers Stun Grab controls, further demonstrating that a dedicated stun system creates broad UI/control/accessibility surface area. Stillring avoids paying that integration cost without a specific gameplay need.  
  https://www.playstation.com/en-us/games/god-of-war-ragnarok/accessibility/

### Existing Stillring authority
- Player Combat #6 already proves that reaction force and damage can remain separate and that retrigger protection prevents indefinite control-lock without damage immunity.
- Shield #4 explicitly rejected a universal enemy posture meter and already has a state-specific Heavy answer.
- Telegraph #5 requires interrupted committed threats to visibly resolve rather than lie.

### IP boundary
No stun meter layout, execution prompt, threshold, timing, UI art, attack value, animation, or enemy behavior is copied from another game. The comparison is used only to evaluate integration cost and player-facing problem structure.

---

## Why this package is approved
This model gives player attacks weight without turning enemies into combo mannequins:
- every hit visibly matters;
- Light cannot erase enemy commitment through spam;
- Heavy earns a concrete disruptive role;
- shield behavior remains distinct instead of being swallowed by a generic meter;
- large enemies can resist through readable state, not an unexplained boss flag;
- encounter reservations cleanly follow legitimate interruption;
- no universal posture resource creates unnecessary HUD/control/balance complexity;
- the IDE can explain every reaction decision.

---

## Player-facing acceptance
Decision #7 passes when:
1. normal hits visibly acknowledge contact;
2. ordinary Light spam cannot indefinitely stun-lock enemies;
3. Light does not casually erase committed enemy attacks;
4. Heavy can earn clean interruption against ordinary eligible commitments;
5. shield defense continues to use its approved explicit state contract;
6. Perfect Guard creates tempo rather than automatically stunning all enemies;
7. large/boss enemies explain resistance per state/action rather than blanket immunity;
8. interrupted committed threats visibly end and clean reservations/hit authority;
9. already-launched projectiles remain honest world objects;
10. the IDE can answer exactly why an enemy did or did not react/interupt.

---

## Next decision
**Enemy / Encounter Decision #8 — archetype coordination + encounter composition.**

Research independently before approval. Do not infer role counts, preferred mixtures, spacing topology, difficulty scaling, spawn waves, or encounter-script ownership from the attack-bandwidth scheduler alone.
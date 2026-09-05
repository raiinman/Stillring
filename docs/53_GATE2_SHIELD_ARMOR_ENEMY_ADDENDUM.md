# 53 — Gate 2 Shield / Armor Enemy Verb-Pressure Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #4 for GitHub Issue #104. Defines the representative Gate 2 defensive enemy's tactical job, directional shield state, player-answer set, attack-bandwidth behavior, and anti-health-sponge/anti-hidden-meter rules.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Defensive-enemy principle:
> **Change the question, not the health bar.**

---

## Decision #4 — shield / armor enemy verb-pressure model — LOCKED

### Gameplay job
The representative shield/armor enemy exists to make Neris **change how she creates an opening**.

It must not become challenging primarily because:
- it has dramatically inflated health;
- frontal hits secretly drain an invisible posture bar;
- every ordinary attack bounces forever until one mandatory gimmick is used;
- the player must precision-aim a tiny weak point;
- the shield is actually universal invulnerability disguised as equipment.

Its tactical job is to present a readable defensive state with several valid answers already supported by Stillring's combat grammar.

### Baseline defense is directional and stateful
The representative enemy has a gameplay-authoritative **Shielded** state with a defended front sector.

While Shielded and correctly facing an incoming ordinary attack:
- eligible Light attacks are defended/deflected rather than dealing normal direct body damage;
- the result is explicit gameplay resolution, not collision accidentally missing the hurtbox;
- the shield itself does not grant 360-degree protection;
- attacks that genuinely connect outside the defended sector resolve against the enemy normally under later enemy-reaction authority;
- shield facing follows authored enemy orientation rules and may not snap arbitrarily after an incoming strike has already committed.

Exact defended angle is prototype tuning.

### Defense is not always-on permanent geometry
The enemy may move with the shield raised in approved pressure states, but Shielded is an explicit state, not a permanent unconditional property of the actor.

Defense can be unavailable or weakened during authored states such as:
- its own committed attack;
- recovery after its own attack;
- Heavy-induced shield displacement;
- certain reactions/interruptions once Decision #7 defines enemy reaction semantics;
- death/disabled states.

Animation presents shield posture. Gameplay state decides whether the defended sector is active.

### Four baseline answers are intentionally valid
The Gate 2 shield enemy supports **multiple** player solutions rather than one required key.

#### 1. Reposition / flank
Because defense is directional, Neris can create an attack line outside the protected front sector through real movement/spacing.

Requirements:
- shield enemy may try to reorient while not committed, but not with infinite turn speed;
- it cannot magnetically face Neris through its own attack/reaction commitment;
- group occupancy/geometry must make at least some real flank movement possible in representative tests;
- target lock does not auto-orbit Neris behind the shield.

A successful flank is earned by world-space positioning, not a contextual backstab prompt.

#### 2. Heavy causes temporary Shield Displacement
A successful qualifying player Heavy against the defended shield creates a **ShieldDisplaced** result/state rather than simply dealing normal full body damage through the shield.

ShieldDisplaced:
- visibly knocks/forces the defense out of its stable protected posture;
- creates a bounded temporary opening where ordinary body attacks may connect according to actual facing/contact;
- is a consequence of Heavy's existing higher commitment, giving Heavy a tactical job beyond damage;
- does not permanently destroy the shield by default;
- does not rely on a hidden cumulative shield-health meter;
- cannot be re-triggered infinitely to keep the enemy locked without later reaction/retrigger limits.

Exact displacement duration and qualifying Heavy properties remain tuning/enemy-reaction integration.

Heavy into shield is therefore useful, but not a free full-damage bypass plus opening in the same instant unless later numeric tuning explicitly proves that fair.

#### 3. Punish the enemy's own commitment
When the shield enemy receives `MajorCommit` and performs its representative attack, it cannot simultaneously preserve perfect all-purpose defense through the entire offensive action.

The attack contract must create an honest **Exposure** interval through startup/active/recovery where the defended sector is reduced, displaced, or unavailable in a visually consistent way.

This means a patient player can create an opening by making the enemy commit rather than always attacking the shield.

Exact attack/exposure timing belongs to telegraph/attack tuning, but the semantic opening is locked.

#### 4. Perfect Guard preserves tempo against its attack
If Neris Perfect Guards the shield enemy's eligible attack, existing Combat #7 rules apply.

The success does not magically shatter the shield or auto-counter, but the player's Perfect Guard Advantage may be used during whatever exposure/recovery the enemy's committed attack already creates.

This rewards defensive mastery without inventing a unique shield-enemy parry minigame.

### Ordinary Light against stable shield has an honest consequence
Repeated Light attacks into the stable defended sector must not secretly progress an invisible break gauge.

The baseline outcome is:
- no normal body damage through the shield;
- a clear deflection/blocked result;
- enough attacker/enemy presentation response to teach that the current line is ineffective;
- no universal player stun or huge forced recoil merely for touching the shield;
- no hidden shield durability depletion.

Light may still be useful after flank, ShieldDisplaced, or Exposure.

### No universal enemy posture meter
Decision #4 does not introduce a generic enemy posture/stagger resource.

The shield archetype's defense is controlled by explicit semantic state and authored transitions, not a meter that every hit drains.

If later Decision #7 determines enemy poise/stun needs a resource or threshold model, that decision must justify it across enemy behavior. It may not be backfilled here as hidden shield HP.

### No precision weak-point requirement
The representative shield enemy does not require:
- aiming at feet;
- shooting a hand;
- hitting a tiny exposed pixel;
- generic shoulder-aim/first-person mode;
- lock-on sub-target cycling.

World-space flank, committed Heavy, and attack-created Exposure are sufficient Gate 2 answers.

A future tool may gain additional interactions, but the enemy must remain solvable before those future tools exist.

### Shield enemy pressure state
While it does not hold `MajorCommit`, the shield enemy may:
- approach/hold a useful pressure lane;
- face Neris within believable authored turning limits;
- protect a lane or complicate direct frontal access;
- yield/reposition according to encounter occupancy;
- remain defensively active without issuing fake attack telegraphs.

It may not become an immovable physics barricade.

### Collision is not the defense mechanic
Neris and the shield enemy use ordinary character/world collision appropriate to the project.

The shield's defensive gameplay result is resolved by attack direction/state/contact semantics, not by giving the shield a giant invisible collision wall that:
- physically shoves Neris backward;
- blocks Evade paths beyond the enemy's real body/equipment footprint;
- traps Neris against geometry with another enemy;
- makes attacks fail before gameplay can explain why.

A shield collision shape may support hit-location/contact evidence, but gameplay resolution remains semantic and IDE-readable.

### Attack bandwidth behavior
The shield enemy's ordinary offensive action competes for the same **`MajorCommit`** lane as other high-salience melee attacks.

Shielded pressure/defensive presence itself consumes **no attack commit lane**.

Decision #4 grants no special `PressureCommit` attack.

When it owns MajorCommit:
- real attack telegraph begins;
- its authored Exposure interval occurs;
- reservation persists until the action no longer demands primary defensive attention;
- interruption/death releases reservation cleanly.

This prevents a shield enemy from both being the safest defensive body and constantly adding free overlapping attacks.

### Shield enemy does not receive attack priority because Neris targets it
Target lock remains independent from encounter permission.

Locking the shield enemy does not:
- make it attack more often;
- make other enemies wait indefinitely;
- increase its turn speed;
- make flank movement automatic;
- transform the camera into a shield-solving tool.

### Reorientation is bounded and state-dependent
While in stable defensive pressure, the shield enemy may turn to keep its defended sector relevant.

But:
- rotation rate is finite/tunable;
- committed attack/reaction/ShieldDisplaced states impose their own stricter facing authority;
- it may not instant-180 in response to an already committed flank attack;
- it may use observable Neris motion only, not pending input;
- crowd/geometry constraints remain real.

The player must be able to create a positional mistake in the defense.

### ShieldDisplaced is not a stun-lock engine
The opening must be meaningful but bounded.

Rules:
- qualifying Heavy creates one reviewed displacement/opening event;
- repeated impacts during an existing displacement do not indefinitely refresh it unless later reaction authority explicitly permits retriggering;
- when the opening expires, the enemy may recover defense if its state/context permits;
- Death/stronger future reactions override normally;
- the enemy can still be hit/interrupted according to later Decision #7 while displaced.

### Defense and body armor are not additive sponge layers
The representative Gate 2 archetype uses **shielded defense** as its defining mechanic.

It does not also receive a broad always-on percentage damage reduction layer merely because the issue says “shield/armor enemy.”

Visual armor may support the fiction, but the baseline combat distinction is the directional stateful defense.

Any future true armor/resistance model requires separate justification.

### Mixed encounters preserve route choice
With melee/ranged/shield enemies together:
- the shield enemy may complicate the most direct frontal route;
- it may not permanently block all access to a ranged enemy through collision formation;
- shared approach occupancy must preserve believable gaps/alternate angles under representative geometry;
- Decision #1 attack bandwidth remains unchanged;
- Standard Ranged Shot may still use its separately-approved PressureCommit lane if readability conditions are satisfied.

### No tool dependency in Gate 2
Gate 3 tools may later create additional shield interactions, but this enemy's required answer set cannot depend on a tool not yet in the Gate 2 combat prototype.

---

## Unreal Engine 5.8 implementation boundary

Possible engine primitives include:
- C++ state/tag data for `Shielded`, `ShieldDisplaced`, `Exposure` and reaction results;
- collision/query evidence for incoming attack direction/contact;
- Gameplay Tags if useful for semantic classification;
- Behavior Tree/StateTree for executing approved local defensive/attack states;
- animation montage/state presentation for shield pose/displacement/attack.

Epic's Gameplay Ability/Tag systems can block actions through tags, but that does not require Stillring to adopt GAS. The relevant implementation lesson is that **blocking/permission can be explicit semantic state**, rather than being inferred from animation or collision alone. citeturn934492search0turn934492search1turn934492search2

Exact architecture remains an implementation choice so long as the authoritative result is inspectable and C++-first.

---

## Accessibility / readability boundary

Requirements:
- Shielded versus ShieldDisplaced/Exposure state must be visually readable without relying only on color;
- block/deflect feedback must not rely only on audio or controller vibration;
- Heavy's successful displacement result must have distinct readable presentation;
- accessibility timing assistance may adjust allowed prototype timing envelopes but cannot secretly turn Light into a shield break;
- high-contrast options may emphasize shield state without changing coverage geometry;
- no precision targeting requirement is introduced;
- camera shake can be zero without losing shield-state information.

---

## Combat / Encounter IDE requirements

### Inspect
Expose:
- enemy semantic local state;
- shield state: Raised / Displaced / Exposure / unavailable;
- current defended sector world direction/angle;
- incoming attack direction/contact point;
- resolution: Deflected / BodyHit / ShieldDisplaced / other later reaction;
- current facing authority/turn-rate limit;
- MajorCommit request/holder;
- attack Exposure interval and recovery;
- last Heavy qualification/rejection reason;
- displacement remaining and retrigger-protection state;
- target-lock identity shown separately;
- approach occupancy/collision pressure;
- last Guard/Perfect Guard/Evade interaction during its attack.

### Tune
With provenance:
- defended-sector angle;
- stable defensive turn rate;
- Heavy qualification thresholds/data references;
- ShieldDisplaced duration;
- attack Exposure timing;
- recovery/re-raise timing;
- spacing/occupancy values appropriate to this archetype.

No tune surface may create hidden shield HP, 360° defense, permanent armor damage reduction, extra attack concurrency, or precision weak-point requirements.

### Exercise
Fixtures:
- frontal Light into Shielded;
- side/rear Light;
- Heavy into Shielded;
- repeated Heavy during ShieldDisplaced;
- bait shield enemy attack and punish Exposure;
- Perfect Guard its attack and punish recovery;
- Neris circles while enemy reorients;
- rapid target switching;
- shield + melee;
- shield + ranged;
- shield in doorway/corner;
- interrupt/kill during attack/displacement;
- 30/60/120+ FPS facing/coverage checks.

### Validate
Detect:
- shield coverage active outside explicit Shielded state;
- effective 360° defense from turn snapping or coverage bug;
- ordinary Light draining hidden break state;
- Heavy failing to create reviewed displacement despite valid contact;
- displacement indefinitely refreshed without authority;
- enemy maintaining full defense throughout its committed Exposure action;
- shield collision becoming an oversized movement wall;
- target lock changing defense/attack priority;
- attack bypassing shared MajorCommit;
- body armor hidden multiplier duplicating shield defense;
- stale Shielded/Displaced state after death/despawn/reset.

### Capture
Record:
- shield-state timeline;
- enemy facing/coverage sector;
- incoming attack action/direction/contact;
- resolution + reason;
- Heavy displacement/expiry;
- enemy attack commit + Exposure interval;
- player positioning/lock state;
- group occupancy;
- frame/time stamps.

---

## Representative red-team tests

1. Spam Light directly into shield: clear deflections, no secret cumulative break.
2. Walk around enemy while unlocked: bounded reorientation; real flank can emerge.
3. Strafe around while locked: camera/lock does not auto-solve flank.
4. Heavy from defended front: produces one bounded ShieldDisplaced opening.
5. Heavy repeatedly during opening: no infinite refresh exploit by default.
6. Bait enemy MajorCommit: defense creates an honest Exposure interval and player can punish if positioned/timed well.
7. Perfect Guard the attack: normal Perfect Guard Advantage works; shield does not auto-shatter.
8. Corner/doorway: shield enemy threatens space but does not become an oversized collision wall.
9. Mixed melee+ranged: one MajorCommit + conditional ranged PressureCommit rules remain intact.
10. Switch target away from shield enemy: its defense/attack priority does not change from lock state alone.
11. Attack from behind during enemy recovery: shield cannot instant-180 to invalidate a committed flank.
12. Disable camera shake/audio: shield state and openings remain readable visually.

---

## Research basis / design lineage

Primary/current engine references:
- Epic Games, Unreal Engine 5.8 Gameplay Tags / blocking primitives demonstrate explicit semantic state/tag gating as an available implementation mechanism, without requiring Stillring to adopt GAS. https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayAbilities/UGameplayEffect/GetBlockedAbilityTags
- Epic Games, *Abilities in Lyra*: activation groups and tag relationships make concurrency/blocking explicit rather than animation-owned. https://dev.epicgames.com/documentation/unreal-engine/abilities-in-lyra-in-unreal-engine

Comparative problem study:
- Nintendo, *Iwata Asks: Skyward Sword — Fight with Your Eyes on Your Opponent*, discusses shield bash risk/reward and the shield gauge. The relevant lesson is that defense needs consequence and readable opportunity; Stillring deliberately does **not** copy the shield-gauge durability loop. https://www.nintendo.com/en-gb/Iwata-Asks/Iwata-Asks-The-Legend-of-Zelda-Skyward-Sword/Vol-3-The-Dense-Volcano-and-Enemy-Monsters/3-Fight-with-Your-Eyes-on-Your-Opponent/3-Fight-with-Your-Eyes-on-Your-Opponent-208359.html
- 2026 Lords of the Fallen 2 developer commentary describes Heavy attacks having tactical guard-breaking purpose beyond extra damage. Stillring independently uses the abstract design lesson that committed attacks benefit from distinct tactical jobs, without copying timings, animations, systems, or values. citeturn934492news42

No exact shield angles, timings, animations, health values, guard-break values, enemy layouts, or code are copied.

---

## Why this package is approved
This shield enemy changes the player's tactical question without adding a new universal resource system or demanding a future tool.

The answers are already native to Stillring:
- move for a flank;
- invest in Heavy to force a temporary opening;
- bait the enemy's own commitment;
- use Perfect Guard to preserve tempo during that commitment.

That makes the enemy a test of the combat system we designed rather than a gimmick bolted on top of it.

---

## Player-facing acceptance
Decision #4 passes when:
1. stable defense is directional and explicit rather than 360° or collision-only;
2. ordinary Light does not secretly drain shield durability;
3. flank/reposition is a real solution;
4. qualifying Heavy creates a bounded ShieldDisplaced opening without a hidden meter;
5. the enemy's own committed attack creates honest Exposure;
6. Perfect Guard helps exploit normal attack/recovery openings but does not auto-break/reflect;
7. shield enemy uses normal MajorCommit bandwidth and gains no free overlap lane;
8. target lock does not alter defense/attack permission;
9. shield collision does not become an oversized body-wall mechanic;
10. IDE can explain every defend/body-hit/displacement/exposure result.

---

## Next enemy / encounter decision
**Decision #5 — enemy telegraph / readability contract.**

Research independently before approval. Define a common semantic warning grammar across melee, ranged, and shield attacks without making combat dependent on UI icons, color, audio, or animation notifies as gameplay authority.

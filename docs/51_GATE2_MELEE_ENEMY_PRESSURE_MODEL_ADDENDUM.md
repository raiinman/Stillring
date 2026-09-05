# 51 — Gate 2 Melee Enemy Pressure / Spacing Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #2 for GitHub Issue #104. Defines the representative Gate 2 melee enemy's spatial pressure, approach, commit, recovery, and group-spacing behavior. It does not yet define ranged, shield/armor, full telegraph taxonomy, or enemy poise/stun.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Melee pressure principle:
> **Close with purpose. Commit honestly. Leave the player room to answer.**

---

## Decision #2 — melee pressure / spacing / commitment model — LOCKED

### The representative melee enemy has a job
The baseline Gate 2 melee enemy exists to test whether Neris can read and manage ordinary close-range pressure using the already-approved player combat verbs.

Its job is to:
- approach through real navigable space;
- occupy a credible threatening distance;
- make Neris care about facing and spacing;
- request `MajorCommit` permission when a real attack opportunity exists;
- execute an honest committed attack that can hit, be Guarded, Perfect Guarded, Evaded, interrupted, or simply miss;
- recover/yield enough space for the encounter to hand pressure to another enemy;
- remain active when denied attack permission without becoming a collision wall or fake-telegraph machine.

It is **not** a homing missile attached to the player.

### Core local state families
The representative melee enemy requires these semantic behavior families:

1. **Acquire / Orient** — establish valid awareness/path context without attacking through unknown/invalid space;
2. **Approach** — move toward a useful pressure region using world navigation;
3. **Pressure** — maintain threat while improving angle/spacing and waiting for a valid attack opportunity/commit permission;
4. **RequestCommit** — request shared encounter `MajorCommit` only when local attack starting conditions are credible;
5. **CommittedAttack** — perform the already-authorized attack; local steering/tracking becomes deliberately constrained;
6. **Recovery / Yield** — finish consequence and make room for continued group flow rather than instantly re-requesting from the same position;
7. **React / Interrupted** — resolve incoming player attack/reaction authority, releasing any held reservation where appropriate;
8. **Dead / Disabled** — no pressure/commit ownership remains.

Exact C++/StateTree/Behavior Tree names may differ; these semantics may not disappear into animation branches.

### Pressure is a region, not one magic radius
Melee AI should reason in authored **distance bands/envelopes**, not chase one exact ring around Neris.

Semantic bands:
- **TooFar** — enemy should approach if path/context permits;
- **PressureBand** — close enough to matter and maneuver, not necessarily attack-ready;
- **AttackOpportunityBand** — attack-specific range/facing/path conditions may permit a commit request;
- **TooClose / Crowded** — ordinary non-committing enemy should create separation/yield rather than keep pushing through Neris or another enemy.

Exact distances remain prototype tuning and attack/archetype data.

There is no requirement that the enemy maintain a mathematically perfect circle around the player.

### No automatic orbit around Neris
The melee enemy may move laterally or seek a different approach lane because its current route is crowded or tactically poor.

It may not:
- continuously orbit Neris simply because lock-on combat exists;
- mirror every player strafe at identical angular speed;
- maintain a fixed polar angle/distance as hidden formation autopilot;
- rotate around the player through walls or other enemies;
- use camera-space target location as its movement authority.

Lateral movement must come from real path/space goals, not an invisible turntable.

### Shared approach occupancy prevents swarming
Decision #1 required shared pressure/approach occupancy. For ordinary melee enemies, the encounter coordinator must provide **distinct usable approach occupancy** around Neris.

Requirements:
- two non-committing melee enemies should not fight for the same exact approach point;
- an occupied lane/sector may cause another enemy to choose a different valid approach, widen, hold, or reposition;
- occupancy follows world geometry and cannot assign a location inside a wall, drop, blocked nav area, or another enemy;
- occupancy is advisory spatial coordination, not a teleport or magnetic formation;
- the committed attacker receives enough lane priority that a denied enemy does not body-block its telegraph/attack path without authored intent;
- Neris remains able to move through plausible gaps; enemies may threaten escape routes but should not accidentally form an impenetrable physics fence.

Exact sector count/angles/radii are tuning, not locked policy.

### Crowd avoidance is necessary but not sufficient
Unreal's RVO or Detour Crowd can help agents avoid one another in motion. Those systems solve dynamic collision/pathing problems, not Stillring's combat-spacing semantics.

Therefore:
- avoidance may smooth motion between authored goals;
- avoidance may not choose who owns a pressure lane or attack reservation;
- a local avoidance result that pushes an enemy into the player's body/another reserved lane must be rejected/corrected by gameplay spacing rules;
- RVO and Detour Crowd are implementation alternatives, not simultaneous mandatory systems.

### Attack request starts from honest conditions
The melee enemy may request `MajorCommit` only when its intended attack's current starting conditions are credible.

At minimum the request snapshot must include:
- valid Neris target/gameplay relationship;
- attack-specific distance eligibility;
- attack-specific facing/angle eligibility;
- unobstructed required motion/reach path;
- valid nav/ground/world support for any authored attack displacement;
- no friendly body occupying a forbidden attack corridor;
- required visibility/readability eligibility from the encounter rules;
- local action not already committed/reacting/dead;
- shared commit permission availability or queued request state.

If those conditions are not met, the enemy keeps pressuring/repositioning. It does not enter attack startup and hope root motion fixes the problem.

### Commitment may miss
After `MajorCommit` is granted and attack Startup begins, Neris remains allowed to move according to player authority.

The melee attack must not guarantee contact by:
- warping the enemy onto Neris;
- continually matching Neris's position through Active;
- extending hit reach because the player moved away;
- teleporting around collision;
- rotating arbitrarily late to catch an Evade;
- reading future player input.

The attack may have a separately-authored bounded early facing/translation component, but its final rules belong to the melee attack/telegraph data and must preserve the principle that **good spacing can cause a real whiff**.

A whiff is a valid combat result, not AI failure.

### No input reading
Melee behavior may react to observable gameplay state and world evidence already committed in simulation, such as:
- current Neris transform/velocity;
- current Guard state;
- current attack action/state;
- current target lock identity;
- recent actual movement direction;
- line of sight / path condition.

It may not inspect a future input buffer/request that has not yet become observable gameplay action in order to counter it perfectly.

The enemy should read Neris the way a fair opponent could read Neris—not the controller queue.

### Guard does not freeze the melee enemy
If Neris holds Guard, the baseline melee enemy may continue to:
- reposition;
- seek a side angle through real movement;
- wait for a later archetype/attack rule that interacts differently with Guard;
- request its ordinary attack when legitimate.

Decision #2 does **not** grant the enemy a hidden unblockable, instant flank teleport, stamina-break, or attack-concurrency exception merely because Guard is held.

Ordinary Guard must remain viable under Combat #4.

### Evade does not cause magnetic chase correction
When Neris Evades:
- the enemy may observe the resulting movement after it occurs;
- a non-committed enemy may choose a new approach goal;
- an already committed attack follows its bounded authored correction and can miss;
- the enemy does not gain special speed/turning/reach to punish Evade simply because Neris entered immunity.

### Perfect Guard does not globally stun the group
A Perfect Guard affects the resolved attacker according to later enemy reaction rules. It does not trigger a hidden global freeze on all other enemies.

Decision #1's shared permission/handoff still governs the next threat.

### Recovery creates consequence and group flow
After a committed melee attack ends, the attacker enters a meaningful Recovery/Yield phase before simply requesting another Major Commit.

During this period it may:
- finish attack recovery presentation;
- regain stable footing;
- slightly widen/shift if overcrowded;
- yield the best approach lane to another enemy;
- transition into React if hit;
- return to Pressure when legal.

It may not use Recovery as a fake instant attack reset.

Exact recovery/yield timing remains attack tuning, but the state must exist and be inspectable.

### Same enemy cannot monopolize the group
Decision #1's starvation/fairness scheduler applies directly to melee enemies.

A melee enemy that just completed a Major Commit is normally less preferred than another valid ready enemy until group flow/fairness says otherwise.

This is not a guaranteed round-robin sequence. World position and actual opportunities still matter.

### Non-holder melee pressure must stay visually non-urgent
An enemy denied `MajorCommit` may look alert, ready, defensive, or in motion.

It must not repeatedly perform a wind-up, weapon flash, lunge tell, shout, or other signal that the player reasonably learns means **attack now** if it has no permission to follow through.

Readability depends on attack telegraphs being trustworthy.

### Lock target is not a movement leash
Whether Neris locks this melee enemy does not change its basic spatial authority.

The enemy:
- still chooses valid world-space approach/pressure goals;
- does not maintain a special preferred camera-facing position;
- does not receive exclusive proximity rights;
- does not stop repositioning simply because it is not locked;
- does not aggressively rush simply because it became locked.

### Cramped spaces degrade gracefully
In a cramped room or corridor:
- fewer valid approach occupancies may exist;
- denied enemies may hold farther back, stagger in depth, or reposition outside the choke;
- the encounter must not force every enemy into Neris's capsule;
- the current commit holder must not be visually buried by teammates;
- camera compression authority remains unchanged;
- encounter authoring must accept lower simultaneous spatial pressure when geometry genuinely cannot support more.

The AI may not 'fix' a bad room by ignoring collision or spawning attackers behind the player without authored rules.

### Verticality remains world-honest
A melee enemy on a different elevation may pressure/approach only through a real valid route or its future explicitly-authored traversal ability.

It does not reserve a close approach slot through floors, cliffs, or inaccessible geometry merely because 2D distance is small.

### Basic Gate 2 melee attack boundary
The representative melee enemy needs at least one ordinary guardable `MajorCommit` strike suitable for exercising:
- Neris ordinary Guard;
- Perfect Guard timing;
- Evade positioning/immunity;
- Light/Heavy interruption testing;
- whiff/recovery behavior;
- attack-bandwidth handoff.

Decision #2 does **not** lock the final animation, exact damage, exact timing, combo count, or enemy reaction-force tuning. Later telegraph/reaction decisions may refine the strike's authored properties without violating this spatial model.

---

## Unreal Engine 5.8 implementation boundary

Useful current primitives:
- Navigation Mesh / AI movement for valid path goals;
- RVO or Detour Crowd avoidance for dynamic agent collision avoidance;
- EQS for scoring candidate approach/pressure positions;
- Behavior Trees or StateTree for local state execution;
- native C++ encounter/enemy gameplay services for authoritative occupancy and attack-request legality.

Recommended separation:
- **Encounter coordinator:** shared `MajorCommit`, approach occupancy, conflict/fairness bookkeeping;
- **Melee gameplay service/state:** local semantic state, attack eligibility, committed/recovery ownership;
- **EQS/navigation:** candidate position/path solving only;
- **avoidance:** smooth local collision avoidance only;
- **BT/StateTree:** execute approved state transitions/requests;
- **animation:** present approach/commit/recovery/react;
- **IDE:** make all layers visible.

No NavMesh/EQS score or animation root-motion result is design authority by itself.

---

## Accessibility / readability boundary

Requirements:
- the melee enemy's meaningful attack start must be readable without requiring audio alone;
- high-contrast/visibility options may change presentation, not attack range/permission;
- difficulty may adjust timing/spacing values inside approved envelopes but not secretly add magnetic tracking or additional `MajorCommit` concurrency;
- melee attack indicators, if later approved, supplement rather than replace readable body/weapon motion;
- a player using Reduced/Off melee facing assistance still faces the same enemy spatial rules;
- Toggle Guard and input-timing assistance cannot cause the enemy to read accessibility settings and counter them differently.

---

## Combat / Encounter IDE requirements

### Inspect
Expose per melee enemy:
- semantic local state;
- current distance band;
- current approach occupancy/goal;
- path validity and path length;
- local crowd/avoidance result;
- nearby enemy separation/conflict state;
- attack readiness + starting-condition breakdown;
- requested/granted `MajorCommit`;
- denial reason;
- attack phase and authored correction remaining;
- current target lock status shown as separate player-owned context;
- Recovery/Yield status;
- last whiff/hit/Guard/PerfectGuard/Evade outcome;
- time since last commit / ready-denied duration.

### Tune
With canonical/session/staged/promoted provenance:
- distance-band thresholds;
- approach occupancy spacing parameters;
- navigation goal refresh tolerance;
- overcrowding/yield thresholds;
- bounded attack-start facing/range requirements;
- Recovery/Yield timing;
- local movement speed/acceleration values after locomotion/animation integration permits tuning.

Live tuning cannot enable teleport/magnetism or bypass shared attack permission.

### Exercise
Named fixtures:
- one melee enemy versus stationary Neris;
- one versus moving unlocked Neris;
- one versus locked strafing Neris;
- two/three/five melee enemies;
- narrow doorway;
- corner/back-wall pressure;
- pillar/occlusion path;
- elevation mismatch;
- Neris holds Guard;
- repeated Evade;
- rapid target switching;
- interrupt commit holder during Startup/Active/Recovery;
- kill current holder;
- deliberately force attack whiff;
- force crowd avoidance conflict.

### Validate
Detect:
- two enemies owning same exclusive approach occupancy;
- enemy movement goal inside blocking geometry/nav-invalid area;
- denied enemy frozen without an approved reason;
- committed attack starting outside its approved conditions;
- late Active tracking/magnetism beyond authored correction;
- attack reach/translation expanded to guarantee contact;
- enemy reading pending player input rather than gameplay state;
- non-holder issuing urgent fake attack telegraph;
- attack holder body-blocked/visually masked by a non-holder due bad occupancy;
- Recovery omitted or immediately bypassed into another request;
- locked enemy receiving hidden spacing/attack priority;
- RVO/Detour result overriding combat occupancy rules;
- stale occupancy or reservation after interrupt/death/despawn/reset.

### Capture
Record:
- local semantic-state transitions;
- pressure band / approach occupancy changes;
- requested nav/EQS goal + resolved path;
- avoidance correction;
- attack start-condition snapshots;
- commit grant/deny;
- target/player motion context;
- attack correction / whiff/hit outcome;
- player Guard/Evade/Perfect Guard;
- Recovery/Yield;
- frame/time stamps.

---

## Representative red-team tests

1. Neris walks backward continuously: melee closes at authored speed but does not warp or permanently stick to one exact radius.
2. Neris suddenly reverses during enemy Startup: bounded early correction only; attack may whiff.
3. Neris Evades laterally during Active: no magnetic follow beyond attack authority.
4. Neris holds Guard: enemy continues honest pressure but gains no invented unblockable/stamina-break/concurrency cheat.
5. Three melee enemies approach: separate occupancies, no capsule pileup, one Major Commit.
6. Five enemies in open space: active pressure without synchronized orbit/wait ring.
7. Five enemies in a doorway: geometry naturally reduces usable pressure; AI does not clip/swarm.
8. Lock/unlock/switch targets repeatedly: enemy spatial goals remain world-driven rather than camera-driven.
9. Current holder is interrupted: reservation and lane cleanup occurs and group flow continues.
10. Current holder whiffs: Recovery/Yield still occurs; it cannot instantly retry.
11. Player attacks a non-holder: enemy can react normally without needing attack permission.
12. 30/60/120+ FPS: distance-band/state transitions and equivalent occupancy decisions remain stable under equivalent simulation context.

---

## Research basis / design lineage

Primary/current engine reference:
- Epic Games, Unreal Engine 5.8, *Using Avoidance With the Navigation System*: RVO and Detour Crowd are dynamic-agent avoidance methods with distinct implementations/limitations, useful for motion but not a substitute for authored combat role/spacing policy. https://dev.epicgames.com/documentation/unreal-engine/using-avoidance-with-the-navigation-system-in-unreal-engine
- Epic Games, Unreal Engine 5.8, EQS/Behavior Tree documentation from Decision #1 remains applicable for candidate-position scoring/local execution.

Comparative problem study:
- Game Developer, *How Naughty Dog defined melee attacks and behaviors in The Last of Us Part II*: melee attacks use explicit starting/ending conditions including range, facing, and motion-line validity; the abstract lesson is that attack eligibility should be established before commitment rather than guaranteed by animation correction. https://www.gamedeveloper.com/design/how-naughty-dog-defined-melee-attacks-and-behaviors-in-i-the-last-of-us-part-ii-i-
- Game Developer's melee-enemy/level-design series emphasizes enemy/space design as part of melee engagement rather than treating AI attack scripts in isolation. https://www.gamedeveloper.com/design/enemy-design-and-enemy-ai-for-melee-combat-systems
- Nintendo's Ocarina Z-targeting development discussion remains lineage context for target-relative readability, while Stillring deliberately does not copy exact orbiting, attack order, enemy spacing, or timings.

No proprietary code, exact distances, timing values, animations, formations, or attack logic is copied.

---

## Why this package is approved
This model gives the baseline melee enemy a clear spatial job without letting navigation, crowd avoidance, animation, or target lock quietly become combat design.

It protects the most important player-facing result: Neris can create a miss through movement, can see why an enemy is threatening, and can navigate a group without enemies becoming either a single-file queue or a physics mob.

---

## Player-facing acceptance
Decision #2 passes when:
1. melee enemies use meaningful pressure bands rather than one exact orbit radius;
2. several melee enemies use distinct approach occupancy and do not pile into one lane;
3. denied enemies remain active without false urgent telegraphs;
4. attack requests require honest current starting conditions;
5. committed attacks can genuinely miss and do not magnetically track Neris;
6. Guard/Evade/Perfect Guard keep their existing player authority;
7. target lock does not change enemy movement/commit priority;
8. cramped geometry reduces feasible pressure instead of causing clipping/swarming;
9. Recovery/Yield creates consequence and group handoff;
10. Combat/Encounter IDE can explain spacing, attack eligibility, commit, correction, and whiff behavior.

---

## Next enemy / encounter decision
**Decision #3 — ranged enemy pressure / line-of-fire / reposition model.**

Research independently before approval, including whether any representative ranged attack earns `PressureCommit` status under Decision #1 rather than competing for the single `MajorCommit` lane.

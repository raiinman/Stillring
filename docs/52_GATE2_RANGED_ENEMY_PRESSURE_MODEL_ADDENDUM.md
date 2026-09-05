# 52 — Gate 2 Ranged Enemy Pressure / Line-of-Fire Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #3 for GitHub Issue #104. Defines the representative Gate 2 ranged enemy's gameplay job, positioning, projectile threat, line-of-fire discipline, reposition behavior, and eligibility for the encounter `PressureCommit` lane.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Ranged pressure principle:
> **Make distance matter without letting distance cheat.**

---

## Decision #3 — ranged pressure / line-of-fire / reposition model — LOCKED

### Gameplay job
The representative ranged enemy exists to make Neris manage **space and attention**, not to turn Stillring into a precision-aim shooter.

Its job is to:
- maintain a useful farther pressure region;
- seek honest line of fire through actual world geometry;
- force movement/Guard/Evade decisions with readable projectiles;
- reposition when too close, blocked, crowded, or strategically stale;
- interact with Decision #1's shared attack bandwidth rather than running an independent firing timer;
- remain answerable by ordinary movement, target lock, Guard, Perfect Guard, Evade, and later tool/combat verbs.

### Baseline attack is a visible projectile, not hitscan
The Gate 2 representative ranged enemy uses a **traveling projectile** for its baseline attack.

Reason:
- visible travel creates a readable world-space threat;
- projectile motion supports Guard/Evade timing without generic precision-aim mode;
- a projectile can miss because Neris moved;
- walls, props, and bodies can honestly block it;
- projectile travel provides meaningful reaction evidence before impact.

Gate 2 does not use an invisible instant hitscan attack for this representative archetype.

Future weapons/enemies may earn different ranged grammars through separate decisions.

### No baseline homing
The representative projectile is **not homing** after launch.

Aim may use a bounded launch solution sampled from observable current gameplay state, including current Neris position and recent/current velocity where justified.

After launch:
- no target seeking;
- no curving around cover;
- no late correction because Neris Evaded;
- no future-input reading;
- no speed increase just because the player created separation.

A clean lateral move may cause a miss.

### Ranged local state families
Required semantics:
1. **Acquire / Evaluate** — establish valid awareness, distance, and line-of-fire context;
2. **SeekPressurePosition** — move toward a useful ranged pressure region using real navigation;
3. **HoldPressure** — maintain threat/readiness without fake urgent telegraphs;
4. **RequestCommit** — request `PressureCommit` or `MajorCommit` only when attack starting conditions are valid;
5. **Telegraph / Fire** — perform the authorized projectile attack;
6. **Recovery** — complete consequence before re-requesting;
7. **Reposition** — leave stale/blocked/too-close/crowded positions;
8. **React / Interrupted** — resolve incoming player action and clean reservation/corridor ownership;
9. **Dead / Disabled** — no threat ownership remains.

### Pressure uses a broad region, not a sniper perch
The ranged enemy has semantic distance bands:
- **TooFar / Ineffective** — may close to a useful range if the fight is otherwise unreachable/unreadable;
- **RangedPressureBand** — useful area for maintaining line of fire and readable projectile travel;
- **TooClose** — should seek separation/reposition rather than firing point-blank by default;
- **NoUsefulLine** — pressure position is invalid despite acceptable raw distance.

It does not maintain one exact radial distance or perfectly mirror Neris's movement.

### Reposition triggers are explicit
The ranged enemy should consider a new pressure position when:
- line of fire is persistently blocked;
- an ally occupies the firing corridor;
- Neris closes into TooClose;
- the current position causes repeated invalid attack opportunities;
- group occupancy makes the current location redundant/crowded;
- the enemy has remained static long enough that encounter pressure becomes trivial or visually dead;
- world geometry invalidates the position.

Reposition is not permission to teleport, phase through collision, or always obtain a flank.

### Fire corridor is gameplay authority
Before requesting a ranged commit, the enemy needs a valid **fire corridor** from attack origin through the projectile's initial travel space.

The eligibility snapshot must consider:
- world blocking geometry;
- Neris as intended gameplay target;
- friendly enemy bodies in the initial corridor;
- required projectile clearance radius, not merely a zero-width ray if the projectile has volume;
- any authored destructible/transparent/penetrable surfaces later approved;
- attack origin not embedded in cover/another actor.

A line trace/sweep may help implementation, but the semantic result is `FireCorridorClear` / rejection reason, not 'raycast says yes so attack is good design.'

### Allies do not become transparent firing props
Baseline ranged projectiles may not simply ghost through friendly enemy bodies to preserve DPS.

Before fire:
- a friendly body blocking the reviewed corridor makes the attack ineligible;
- the ranged enemy should reposition, wait, or seek another honest solution.

If an ally unexpectedly crosses after a committed telegraph begins, collision remains world-honest. Exact friendly-damage consequence may be decided later, but the projectile may not invisibly pass through the ally as though it did not exist.

The encounter coordinator should expose/reserve the firing corridor enough to reduce routine ally-crossing telegraph cancellations.

### Real telegraph begins only after commit permission
As with melee, the ranged enemy may show non-urgent readiness before permission.

The gameplay-significant firing telegraph begins only after the appropriate encounter commit is granted.

This keeps visible draw/charge/weapon-flash cues trustworthy.

### The baseline standard shot earns `PressureCommit` — conditionally
Decision #3 approves one representative **Standard Ranged Shot** as `PressureCommit` compatible, with strict limits.

It may overlap one active `MajorCommit` only when all of these are true:
- no other `PressureCommit` is active;
- attacker has valid line of fire/fire corridor;
- attacker/origin is currently **readability eligible**;
- shot uses the visible non-homing projectile grammar;
- attack is a single discrete projectile rather than a burst/volley;
- the shot is ordinarily Guardable when entering the approved frontal Guard sector;
- it does not carry `HardStagger` or `Death`-special reaction semantics as its baseline threat;
- it has a clear visual telegraph and projectile-travel read;
- its timing does not intentionally collapse onto the exact unavoidable defense instant of the current Major Commit.

If any condition is not met, the Standard Ranged Shot must compete for `MajorCommit` instead or wait/reposition.

### PressureCommit is not free extra damage
The reason the standard shot earns PressureCommit is **readability**, not because ranged enemies deserve a separate DPS budget.

The overlapping shot should ask a different, lower-bandwidth question:
- notice the visible shot;
- Guard it if frontal/appropriate;
- move/Evade around it;
- reposition so the shot misses or collides with world geometry.

It must not require the player to solve two simultaneous high-salience timing puzzles that demand contradictory defensive answers.

### Readability eligibility for PressureCommit
Until the later dedicated offscreen-threat decision expands this contract, the Standard Ranged Shot may use `PressureCommit` only when the attack source/telegraph is reasonably readable in the player's current presentation.

Baseline eligible cases:
- ranged enemy is meaningfully on-screen; or
- the projectile origin/attack telegraph is at the visible edge with clear directional evidence sufficient for human-play validation.

Baseline **not** PressureCommit eligible:
- attacker is fully offscreen with no approved threat communication;
- attacker is hard-occluded behind opaque geometry;
- projectile would first become visible too late for a normal defensive response;
- the camera is severely compressed and the origin cannot be meaningfully interpreted.

Those attacks may wait/reposition or, if later offscreen rules justify them, receive separate authority.

### No shooting through opaque hard cover
If line of fire is blocked by meaningful opaque world geometry, the ranged enemy does not fire at Neris through it.

It may:
- reposition for sight;
- hold pressure;
- lose/reacquire the opportunity;
- later use an explicitly authored indirect attack if a future decision creates one.

EQS may find a vantage point. It does not give wall vision or projectile phasing.

### Target lock is irrelevant to firing permission
Neris locking or not locking the ranged enemy does not:
- make it eligible/ineligible to fire by itself;
- change projectile homing (there is none);
- grant it camera-space aim;
- make it stop pressuring because Neris chose the melee enemy;
- allow it to bypass Decision #1.

The ranged enemy exists in the world, not inside the lock-on UI.

### Aim uses observable state, not controller intent
A launch solution may use current/previous observable Neris movement to avoid deliberately firing every projectile at a stale point.

It may not inspect:
- pending buffered Evade input;
- future movement input;
- hidden aim/camera intent not expressed in gameplay;
- a future target-switch request.

Any velocity lead must be bounded/tunable and frozen at the reviewed firing point. Projectile trajectory is then committed.

### Guard interaction
The Standard Ranged Shot is ordinarily Guardable if:
- impact arrives within Guard's approved front sector;
- attack is not later explicitly classified otherwise;
- Neris is in a valid Guard state.

Ordinary Guard follows Combat #4 consequence rules.

Perfect Guard follows Combat #7 timing rules but **does not automatically reflect the projectile**. Reflection would be a new combat/tool verb and requires separate authority.

### Evade interaction
The projectile participates in Combat #5 collision/immunity rules like an eligible combat hit.

Evade does not make the projectile home away/around Neris. The projectile continues its committed path.

### No point-blank firing default
When Neris closes inside TooClose:
- the ranged enemy prioritizes creating separation/repositioning if possible;
- it does not fire the Standard Ranged Shot directly from inside Neris's collision space;
- it does not gain a hidden instant melee attack in Decision #3;
- if cornered, it may remain vulnerable/pressured until a later archetype decision adds a close-range answer.

This creates a real tactical payoff for closing distance.

### Ranged retreat cannot kite forever
The ranged enemy may reposition away from Neris, but it cannot maintain a perfect faster-than-player escape loop.

Requirements:
- movement obeys real nav/acceleration/world geometry;
- TooClose response seeks a useful new position, not infinite flee-to-max-range behavior;
- repeated retreat into an arena boundary/corner must eventually produce a constrained state rather than path jitter;
- player closing speed/traversal must remain capable of forcing interaction under representative encounter geometry.

Exact speeds remain human-play tuning.

### Recovery remains real
After firing, the ranged enemy has a Recovery state before another request.

It may reposition during an explicitly-approved portion of recovery if readable, but it may not use movement to erase all firing consequence or instantly chain projectiles outside the shared bandwidth rules.

### Projectile lifetime is world-honest
A fired projectile:
- collides with reviewed blocking geometry;
- cannot remain indefinitely alive chasing nothing;
- has bounded lifetime/range;
- is cleaned on encounter/reset/world invalidation according to later reset authority;
- does not silently teleport to Neris after frame hitches or obstruction.

Exact lifetime/speed/size are tuning.

---

## Unreal Engine 5.8 implementation boundary

Epic's `UProjectileMovementComponent` supports ordinary projectile simulation and also offers features such as homing/bounce. Their existence is **not** Stillring policy; baseline Decision #3 explicitly uses visible non-homing travel.

Useful primitives:
- `UProjectileMovementComponent` for projectile travel;
- line/sphere/capsule traces or collision sweeps for fire-corridor checks appropriate to projectile volume;
- EQS/Nav for candidate ranged pressure positions;
- Behavior Tree/StateTree/native C++ for local state execution;
- authoritative encounter coordinator for `PressureCommit`/`MajorCommit` and firing-corridor occupancy.

Gameplay must expose a semantic fire eligibility result and reason rather than hiding all logic in Blueprint trace spaghetti.

---

## Accessibility / readability boundary

Requirements:
- Standard Ranged Shot must have a visual telegraph independent of audio;
- projectile itself must be visually distinguishable against representative environments, with future high-contrast support where applicable;
- audio may supplement direction/timing but cannot be the only warning;
- any future offscreen indicator must be configurable and not rely on color alone;
- projectile speed/telegraph timing can have accessibility/difficulty tuning envelopes, but semantic Guard/Evade/commit rules remain the same;
- camera shake/vibration reductions do not remove threat information;
- no aim-reticle requirement is introduced for defending against ranged enemies.

---

## Combat / Encounter IDE requirements

### Inspect
Per ranged enemy expose:
- semantic local state;
- distance band / pressure-position goal;
- line-of-sight and fire-corridor result;
- exact blocking actor/surface if rejected;
- friendly-body obstruction state;
- current `PressureCommit` / `MajorCommit` request and holder;
- readability eligibility;
- target lock shown separately;
- aim sample: target position/velocity used;
- launch direction and bounded lead value;
- telegraph/fire/recovery state;
- projectile ID, velocity, lifetime, collision result;
- last hit/miss/Guard/PerfectGuard/Evade/world-block result;
- reposition reason.

### Tune
With provenance:
- distance bands;
- reposition thresholds;
- projectile speed/radius/lifetime;
- bounded lead factor/limit;
- telegraph and recovery timings;
- PressureCommit overlap separation/readability timing;
- fire-corridor clearance size;
- position-scoring weights.

No tune surface may enable homing, ally phasing, offscreen PressureCommit, hitscan, or extra PressureCommit concurrency without authority.

### Exercise
Fixtures:
- single ranged enemy open arena;
- Neris stationary/moving laterally/closing;
- wall/pillar occlusion;
- ally crossing firing corridor;
- ranged enemy cornered TooClose;
- ranged + melee MajorCommit overlap;
- two ranged enemies both ready;
- ranged enemy at screen edge / fully offscreen;
- target switching between melee/ranged;
- Guard / Perfect Guard / Evade against projectile;
- projectile blocked by world/ally;
- 30/60/120+ FPS projectile/permission consistency.

### Validate
Detect:
- firing without commit permission;
- PressureCommit granted while another PressureCommit is active;
- PressureCommit granted when readability-ineligible;
- standard projectile homing after launch;
- attack firing through hard cover;
- fire corridor blocked by ally at request/start;
- projectile phasing through friendly body because of enemy-specific ignore list;
- pending player input used in aim solution;
- launch lead changing after projectile fire;
- point-blank standard shot inside forbidden TooClose state;
- ranged enemy infinitely retreating/path-jittering with no constrained resolution;
- Recovery bypassed into unapproved rapid fire;
- stale projectile/reservation after death/despawn/reset.

### Capture
Record:
- pressure-position evaluations;
- LOS/fire-corridor snapshots;
- commit request/grant/deny;
- readability eligibility;
- aim sample and launch solution;
- projectile trajectory/collisions;
- player defensive response;
- Major/Pressure overlap timeline;
- reposition decisions;
- frame/time stamps.

---

## Representative red-team tests

1. Ranged fires at stationary Neris: clean visible telegraph/travel.
2. Neris strafes after launch: projectile does not curve; miss is valid.
3. Neris closes TooClose: ranged repositions instead of point-blank spamming.
4. Melee holds MajorCommit while visible ranged is ready: one approved Standard Ranged Shot may receive PressureCommit.
5. Second ranged requests while PressureCommit active: denied/waits/repositions.
6. Ranged fully offscreen with no approved communication: no PressureCommit.
7. Ally steps into fire corridor before grant: request rejected.
8. Ally unexpectedly crosses after telegraph: collision remains honest; no ghost-through.
9. Wall blocks Neris: ranged seeks position instead of firing through wall.
10. Neris Guards frontal projectile: ordinary Guard rules apply.
11. Perfect Guard projectile: successful timing does not auto-reflect.
12. Neris Evades: immunity/movement can defeat projectile; no homing correction.
13. Target lock remains on melee enemy: ranged pressure still functions without camera authority.
14. Corner ranged enemy: cannot kite infinitely through wall/edge; constrained state is inspectable.
15. 30/60/120+ FPS: equivalent launch snapshot produces stable projectile behavior within simulation tolerances.

---

## Research basis / design lineage

Primary/current:
- Epic Games, Unreal Engine 5.8 `UProjectileMovementComponent`: supports projectile simulation, including optional bounce/homing; Stillring deliberately chooses non-homing baseline. https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UProjectileMovementComponent
- Epic Games, Unreal Engine 5.8 `LineTraceSingle` / sphere trace APIs: collision queries return blocking hits and can support semantic fire-corridor validation. https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UKismetSystemLibrary/LineTraceSingle
- PlayStation, *God of War Ragnarök Accessibility*: official Enemy Off-Screen Indicator conveys direction/type of incoming attacks; useful evidence that ranged/offscreen threat communication deserves explicit UX/accessibility authority rather than being left to camera luck. https://www.playstation.com/en-us/games/god-of-war-ragnarok/accessibility/

Comparative lessons are problem-level only. Stillring does not copy projectile speeds, reticles, indicators, enemy placements, damage, timing, or code from another game.

---

## Why this package is approved
The visible non-homing projectile makes ranged pressure a world-space problem the player can actually solve, not invisible damage delivered from outside the camera.

Granting the single standard shot conditional `PressureCommit` status also prevents the one-Major rule from turning mixed fights into serial melee-then-ranged turns, while strict readability/guardability/projectile limits stop that extra lane from becoming cheap crossfire.

---

## Player-facing acceptance
Decision #3 passes when:
1. baseline ranged threat is a visible non-homing projectile;
2. shots use honest line of fire/fire corridor and do not phase through allies/opaque cover;
3. Standard Ranged Shot may use PressureCommit only under the locked readability/attack constraints;
4. only one PressureCommit exists at a time;
5. offscreen unreadable ranged attacks do not get PressureCommit by default;
6. closing distance creates real tactical pressure on the ranged enemy;
7. ranged retreat does not become infinite perfect kiting;
8. aim uses observable current motion only and freezes at launch;
9. Guard/Perfect Guard/Evade retain their existing semantics, with no automatic projectile reflection;
10. Combat/Encounter IDE can explain every position, line-of-fire, commit, aim sample, projectile outcome, and reposition.

---

## Next enemy / encounter decision
**Decision #4 — shield / armor enemy verb-pressure model.**

Research independently before approval. The archetype must pressure player verb choice without becoming a health sponge, universal frontal invulnerability wall, hidden stamina test, or mandatory precision-aim target.

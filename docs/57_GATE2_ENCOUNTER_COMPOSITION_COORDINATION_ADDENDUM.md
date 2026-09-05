# 57 — Gate 2 Encounter Composition / Coordination Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #8 for GitHub Issue #104. Defines how approved enemy archetypes share space and tactical roles, how compositions scale pressure without unreadable stacking, and what arena/spawn constraints protect the camera and player-control authority.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Composition principle:
> **Combine different problems. Do not pile the same problem higher.**

This decision builds on:
- #1 attack bandwidth;
- #2 melee pressure/occupancy;
- #3 ranged line-of-fire pressure;
- #4 shield verb-pressure;
- #5 telegraph readability;
- #6 offscreen/occluded fairness;
- #7 explicit reaction/resistance.

---

## Decision #8 — archetype coordination + encounter composition — LOCKED

### 1. Compose by tactical role, not rigid party slots
Stillring encounters may contain melee, ranged, shield, duplicate, or later specialist enemies, but the encounter does not require a fixed RPG-style party template.

Each placed/spawned enemy must contribute a clear tactical job such as:
- **Close pressure** — occupy useful attack/approach space and challenge movement timing;
- **Distance pressure** — create readable fire corridors and punish static positioning;
- **Denial / redirection** — shield/armor or later mechanics alter which player verb/angle is efficient;
- **Specialist pressure** — future archetype-specific authored job.

An archetype may cover more than one job, but encounter intent must remain explainable.

### 2. Composition is authored around complementary pressure
Good combinations should create choices rather than simultaneous mandatory reactions.

Examples:
- melee closes space while ranged encourages movement;
- shield alters frontal attack choice while another enemy creates reposition pressure;
- duplicate melee can create spatial compression while still sharing one MajorCommit budget.

Rejected baseline pattern:
- multiple enemies independently demanding the same high-salience defensive response at once;
- several ranged attackers creating crossing unavoidable fire lanes merely because they are ready;
- shield + melee body-blocking all legal escape space;
- enemy variety whose only effect is higher damage/health.

### 3. Existing attack bandwidth remains absolute baseline
Composition does not modify #1's baseline:
- one ordinary `MajorCommit` at a time;
- only separately-approved `PressureCommit` actions may overlap;
- no composition template grants a hidden extra attack lane;
- difficulty does not silently raise MajorCommit concurrency.

### 4. Approach / pressure occupancy is shared encounter space
The encounter coordinator maintains semantic occupancy for useful combat space around Neris.

At minimum distinguish:
- close approach lanes useful for melee/shield pressure;
- ranged firing corridors / useful stand-off positions;
- temporary recovery/yield space;
- blocked/unsafe geometry;
- player escape/movement space that must not be accidentally sealed by crowd collision.

These are not fixed radial slots painted around the player. They are world-aware occupancy concepts.

### 5. Enemies may yield bad lanes instead of jittering for access
When two enemies want the same approach/firing space:
- one may reserve/use it;
- another repositions, waits in active pressure, widens angle, or yields;
- agents must not stack inside each other or oscillate at the same point;
- denied agents remain active rather than freezing.

Reservation/occupancy state must be inspectable.

### 6. Ranged enemies must preserve honest firing topology
A composition with ranged pressure must provide real, readable firing geometry.

Rules:
- ranged enemies seek lanes that are legal under #3/#6;
- multiple ranged agents should avoid unnecessary corridor overlap that visually masks projectile ownership;
- crossing fire may exist only when individual attacks remain attributable and defensive options remain practical;
- a ranged agent blocked by allies/geometry repositions rather than firing through them by rule;
- encounter art/layout must not depend on constant projectile clipping through friendly bodies unless explicitly authored later.

### 7. Shield enemies are redirectors, not mobile walls
Shield archetypes should create directional/verb choice, not erase the arena.

Composition constraints:
- shield enemies may hold useful pressure space but must not combine with allies to form unavoidable body-wall traps;
- shield-facing defense may funnel Neris toward other threats, but at least one practical movement/verb answer must remain;
- another enemy cannot occupy the exact opening created by `ShieldDisplaced` in a way that makes the earned answer meaningless by default;
- cramped arenas with shield enemies require explicit review.

### 8. Duplicate archetypes are valid when they change spatial problem
Duplicates are not forbidden.

Healthy duplicate use:
- two melee enemies approaching from meaningfully different lanes;
- two ranged enemies with separated readable corridors and controlled PressureCommit eligibility;
- two shield enemies in a deliberately spacious encounter that tests angle management.

Weak duplicate use:
- copies standing on the same lane;
- additional bodies whose only purpose is HP inflation;
- repeated archetypes whose attack/readability is indistinguishable and creates visual noise without tactical change.

### 9. Baseline small-group composition guidance
These are design guardrails, not mandatory recipes.

#### One enemy
Should still express its archetype honestly. No coordinator trickery required to make it interesting.

#### Two enemies
Prefer a readable relationship:
- two complementary jobs; or
- duplicate archetypes with clearly different spatial pressure.

Avoid creating an offscreen + on-screen simultaneous response trap merely because there are two actors.

#### Three enemies
This is the first baseline composition where role complement matters strongly.

A useful Gate 2 test mix is:
- one melee pressure enemy;
- one ranged pressure enemy;
- one shield/denial enemy.

This is a test fixture, not a production formula.

#### Five enemies
The encounter must prove that non-holders remain active without creating:
- a waiting circle;
- a body wall;
- indicator spam;
- overlapping fake telegraphs;
- unreadable projectile ownership.

Five enemies are a stress test, not a default room target.

### 10. Arena topology is part of encounter design
Enemy composition cannot be evaluated separately from space.

A valid arena must provide enough meaningful geometry for the intended roles:
- movement routes that respect Evade displacement;
- sufficient room for approach occupancy without body stacking;
- readable ranged sightlines where ranged enemies are used;
- meaningful cover that actually blocks attacks;
- no required camera cheating to reveal threats;
- no long severe camera compression as the default fight state unless intentionally authored and separately reviewed.

### 11. Encounter layout must protect player-owned spacing
Stillring combat does not auto-maintain distance for Neris.

Therefore encounter composition must not rely on:
- enemies automatically pushing Neris to a designed radius;
- invisible crowd forces that maintain an arena center;
- camera zoom making spacing readable after enemies collapse into one mass.

Player spacing remains earned through movement, Guard, Evade, Heavy disruption, and target choice.

### 12. Target lock does not choose encounter roles
Locking one enemy does not:
- promote it to permanent attacker;
- make others passive;
- reserve the best lane for it;
- force ranged enemies to stop pressure;
- alter composition logic beyond honest visibility/positioning inputs already approved.

### 13. Composition should make role attribution possible
The player should be able to learn what each enemy is doing from behavior/presentation.

Encounter failure signs:
- every enemy circles identically;
- shield and melee occupy the same practical behavior envelope;
- ranged enemies spend most of the fight pathing into melee range for no reason;
- non-holders fake urgent attack tells to appear active;
- roles only exist in internal tags, not in visible behavior.

### 14. Difficulty escalates quality before quantity/concurrency
Preferred escalation order:
1. better enemy positioning;
2. less wasted movement / more useful lane selection;
3. stronger but readable archetype combinations;
4. reduced excessive handoff slack;
5. more demanding approved attack timings/angles;
6. additional enemies only when arena/readability supports them;
7. new authored specialists/mechanics;
8. simultaneous MajorCommit exceptions only through separate explicit authority.

Higher difficulty is not permission to turn the encounter into invisible crossfire.

### 15. Reinforcements must enter as readable actors, not instant damage
Decision #8 sets only the composition fairness boundary; full spawn/reset implementation remains #10.

Any reinforcement entering an active fight must:
- become spatially/visually/audibly attributable before its first committed threat;
- not spawn already inside unavoidable melee contact unless explicitly scripted and clearly telegraphed by world fiction;
- obey normal offscreen/occlusion eligibility after entry;
- register with attack-bandwidth/occupancy before attacking;
- not appear solely to punish the player's current camera facing.

### 16. Spawn location cannot be hidden tactical omniscience
Spawn selection may use authored encounter state, valid geometry, and approved placement logic.

It must not:
- read future player input;
- intentionally spawn at the one location the camera is not facing as a difficulty trick;
- place ranged attackers behind hard cover and immediately grant fire through geometry;
- place bodies to close the player's only current escape lane with no arrival warning.

### 17. Encounter composition owns friendly spatial conflict
Baseline enemy collision/steering must prevent allies from accidentally defeating each other's readability.

Examples:
- non-holder cannot stand inside current MajorCommit telegraph silhouette;
- ranged shooter should avoid firing directly through an allied body when that makes source/projectile attribution poor;
- allies should avoid shoving each other/Neris into walls through crowd pressure alone;
- displacement reactions should not create unresolved actor overlap.

### 18. Composition exceptions must be authored, named, and testable
A special encounter may intentionally break a baseline rule for dramatic/tactical reasons, but the exception must state:
- what rule is being exceeded;
- why the player still receives fair information/options;
- which arena geometry supports it;
- which System IDE fixture reproduces it;
- which acceptance test proves it.

No hidden per-room 'just add another attacker' override.

---

## Unreal Engine 5.8 implementation boundary

Useful current primitives include:
- EQS generators/tests/contexts for scoring world positions;
- AI navigation/perception for legal movement/visibility inputs;
- Smart Object-style reservation patterns for exclusive usable slots/activities;
- Behavior Trees/StateTree/native C++ for execution.

Stillring policy remains above those systems.

Recommended split:
- **Encounter coordinator:** role/pressure occupancy, commit lanes, composition facts, fairness reasons;
- **Enemy-local AI:** requests useful movement/attack behavior;
- **EQS/navigation:** proposes/scored positions;
- **reservation layer:** prevents conflicting occupancy;
- **level/encounter data:** authored archetype roster and relevant geometry intent;
- **Combat/Encounter IDE:** proves what each actor is trying to do and why.

EQS's highest-scoring point is not automatically the correct design answer. It must be scored against approved semantic constraints.

---

## Accessibility / readability boundary

Requirements:
- composition may not depend on stereo audio alone to separate threats;
- color-only enemy-role classification is insufficient;
- reduced FX/shake must preserve role/telegraph attribution;
- difficulty assists may reduce enemy count/cadence or strengthen warnings through explicit settings authority, but may not silently change player combat legality;
- body size/contrast and offscreen indicators must not become a substitute for controlled attack bandwidth.

---

## Combat / Encounter IDE requirements

### Inspect
Expose:
- encounter roster and authored role intent;
- each enemy archetype/current tactical job;
- current approach/pressure occupancy;
- desired/requested lane or firing corridor;
- reservation owner / denied request reason;
- current Major/Pressure holder;
- on/offscreen/occlusion state;
- target lock separately;
- current telegraph/action/reaction state;
- ranged corridor and obstruction state;
- player escape/movement-space diagnostics;
- reinforcement registration/arrival state;
- any authored composition exception.

### Tune
With provenance:
- occupancy spacing/envelopes;
- role weighting for candidate movement positions;
- starvation/fairness/positioning weights already permitted by #1;
- duplicate-archetype spacing preferences;
- reinforcement arrival/readability timing inside future #10 authority;
- difficulty composition presets after options authority exists.

### Exercise
Fixtures:
- 1 melee;
- 2 melee duplicates;
- melee + ranged;
- melee + shield;
- ranged + shield;
- canonical 3-enemy melee/ranged/shield mix;
- 3 duplicate melee;
- 2 ranged + melee;
- 2 shield + melee in spacious arena;
- 5-enemy stress ring;
- narrow doorway;
- cramped room;
- open arena with cover;
- vertical/stair arena;
- reinforcement arrival while MajorCommit active;
- player circles outer edge continuously;
- target-switch across every roster member.

### Validate
Detect:
- overlapping occupancy reservations;
- frozen waiting-circle behavior beyond approved hold state;
- ally masking committed telegraph;
- body-wall trapping of Neris;
- ranged fire corridor through ally/meaningful obstruction without authority;
- role tag not reflected in actual behavior;
- composition increasing MajorCommit concurrency;
- excessive simultaneous offscreen indicators;
- reinforcement entering with immediate untelegraphed attack;
- target lock changing commit/role permissions;
- difficulty preset violating readability/attack-bandwidth rules;
- arena lacking practical movement space for approved composition.

### Capture
Record:
- roster/role state;
- desired/claimed/released occupancy;
- commit requests/grants;
- movement targets and rejection reasons;
- firing corridors;
- visibility/occlusion;
- player camera/lock/movement;
- reinforcement entry;
- attacks/reactions;
- frame/time stamps.

A designer must be able to answer:
> **Why are these enemies standing here, and what tactical job is each one contributing right now?**

---

## Representative red-team tests

1. Three enemies request same close lane: exactly one owns it; others reposition/yield without freezing.
2. Melee + ranged: ranged maintains useful legal corridor; melee does not constantly body-block projectile source.
3. Melee + shield: Neris retains practical movement/verb answer; no body-wall trap.
4. Melee/ranged/shield trio: roles are visibly distinct and only approved threat lanes overlap.
5. Three duplicate melee: encounter still looks active without simultaneous MajorCommit dog-pile.
6. Two ranged attackers: projectile ownership remains attributable; PressureCommit rules prevent unfair crossfire.
7. Five-enemy stress test: no waiting circle, collision wall, fake-telegraph soup, or UI pinwheel.
8. Cramped room: composition validator flags cases where approved camera/player movement cannot support roster.
9. Lock onto ranged while melee has MajorCommit: role/commit ownership remains independent of lock.
10. Interrupt current holder with Heavy: reservation handoff remains readable; group does not pounce same-frame.
11. Add one enemy on higher difficulty: only valid if arena/readability still passes; no automatic concurrency increase.
12. Reinforcement enters offscreen: it becomes attributable before first commit; no instant back-hit.
13. 30/60/120+ FPS: occupancy/reservation semantics remain deterministic enough to avoid frame-rate slot races.

---

## Research basis / design lineage

### Current primary engine references
- Epic Games, Unreal Engine 5.8, **Environment Query System User Guide / Quick Start** — EQS can generate/test/weight candidate positions and is explicitly suitable for line-of-sight and distance-driven AI positioning. Stillring uses it as a position proposal tool, not design authority.  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/environment-query-system-user-guide-in-unreal-engine  
  https://dev.epicgames.com/documentation/unreal-engine/environment-query-system-quick-start-in-unreal-engine
- Epic Games, Unreal Engine 5.8, **Smart Objects** — exposes a reservation model for exclusive activities/slots. Stillring may reuse the reservation pattern concept for occupancy, without requiring Smart Objects for combat positions.  
  https://dev.epicgames.com/documentation/unreal-engine/smart-objects-in-unreal-engine

### Shipped-game problem study
- Nintendo, **Iwata Asks — Ocarina of Time 3D** — development discussion explicitly identifies staged multi-opponent sword-fight behavior where surrounding opponents attack in order as a solution to multi-enemy readability. Stillring preserves the attention-budget lesson while using active non-holder positioning, distinct roles, explicit pressure lanes, and modern accessibility/debugging rather than copying encounter timing or enemy behavior.  
  https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/4/4/
- PlayStation, **God of War Ragnarök combat guide** — demonstrates shipped action-adventure combat where different weapon/enemy properties create different tactical answers. Stillring uses only the abstract lesson that variety should alter player decisions, not merely HP totals.  
  https://www.playstation.com/en-us/games/god-of-war-ragnarok/god-of-war-combat-refresher-course/

### IP boundary
No encounter roster, wave layout, slot count, radius, AI timing, spawn pattern, arena shape, attack cadence, or UI expression is copied from another game.

---

## Why this package is approved
The composition contract makes existing enemy decisions work together without introducing a second hidden combat system:
- archetypes contribute distinct tactical jobs;
- spatial occupancy prevents stacking/jitter/body walls;
- attack bandwidth still governs urgent danger;
- ranged/shield behavior retains its own rules;
- arena geometry becomes accountable for combat readability;
- difficulty grows through better composition/positioning before concurrency;
- reinforcements cannot spawn as surprise damage;
- the IDE can explain the group as a system.

---

## Player-facing acceptance
Decision #8 passes when:
1. melee/ranged/shield enemies feel behaviorally distinct in the same fight;
2. combinations create choices rather than simultaneous unavoidable responses;
3. duplicates remain spatially purposeful rather than redundant HP bodies;
4. enemies do not stack/jitter/freeze in a waiting circle;
5. ranged and shield pressure preserve practical movement/readability;
6. target lock does not become encounter-role authority;
7. difficulty does not secretly increase MajorCommit concurrency;
8. reinforcements are attributable before first committed threat;
9. cramped/poor arenas fail composition review rather than being rescued by camera tricks;
10. the IDE explains role, occupancy, and current tactical intent for every enemy.

---

## Next decision
**Enemy / Encounter Decision #9 — disengage / reset / leash / re-entry behavior.**

Research independently before approval. Do not infer chase radius, combat forgetfulness, health reset, respawn, checkpoint integration, or exploit-prevention behavior from navigation defaults.
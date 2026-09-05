# 50 — Gate 2 Encounter Attack-Bandwidth Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #1 for GitHub Issue #104. This file defines how multiple enemies share permission to commit meaningful attacks against Neris before individual melee/ranged/shield behavior is decided.

## Authority
This decision is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Encounter principle:
> **Keep the whole group alive. Keep the actual danger readable.**

Stillring rejects both extremes:
- every enemy independently attacks whenever locally ready;
- every non-selected enemy visibly waits its turn in a dead ring.

---

## Decision #1 — multi-enemy attack bandwidth / aggression coordination — LOCKED

### Core rule: the encounter owns attack permission
An enemy's local AI may decide that it **wants** to attack. That does not mean it is allowed to begin a high-salience commitment.

A shared authoritative encounter coordinator grants and revokes semantic **commit permissions**.

Individual Behavior Trees, StateTrees, animation graphs, or local cooldowns may request permission. They may not bypass the coordinator merely because their attack branch became ready.

### One ordinary Major Commit at a time
For the Gate 2 baseline, an ordinary encounter permits at most **one `MajorCommit`** against Neris at a time.

`MajorCommit` covers an attack that meaningfully dominates the player's immediate defensive attention, such as a future:
- committed melee swing/combo/lunge;
- heavy enemy strike;
- shield/armor power action;
- high-salience ranged shot/volley;
- other attack later authored as requiring primary defensive attention.

This is a semantic budget, not a hidden difficulty stat.

The purpose is not to make enemies polite. It is to ensure the player's Guard/Evade/Perfect Guard decisions remain attributable to readable threats under the camera's actual visual bandwidth.

### A later `PressureCommit` class may overlap one Major Commit
The encounter system supports a second semantic lane named `PressureCommit`, but **no attack is automatically eligible for it**.

A later melee/ranged/shield decision may explicitly designate an attack as pressure-compatible only if it is proven readable while a Major Commit is active.

A pressure-compatible attack must eventually define, at minimum:
- why it does not require the same defensive attention as a Major Commit;
- telegraph requirements;
- visibility/offscreen rules;
- guardability/evadability interaction;
- reaction-force ceiling;
- overlap exclusions with other pressure actions.

Until an attack is individually approved as `PressureCommit`, it competes for the single Major Commit permission.

This prevents Decision #1 from silently inventing ranged crossfire or cheap chip attacks before those archetypes are researched.

### Unlimited local readiness does not mean unlimited simultaneous danger
Any number of enemies may be locally ready to attack. The coordinator decides who may commit.

Non-granted enemies remain active through approved non-commit behavior such as:
- repositioning for a useful angle;
- maintaining or changing distance;
- guarding/covering space where their archetype later supports it;
- seeking line of sight;
- closing or widening an encirclement without clipping through the player/other enemies;
- telegraph-neutral anticipation/stance behavior;
- retreating from overcrowded approach lanes;
- reacting to world/player movement.

They may **not** spam fake attack startups that are visually indistinguishable from real committed attacks merely to look busy.

### No passive waiting circle
An enemy denied commit permission should not simply freeze at an arbitrary ring radius unless its authored archetype genuinely calls for holding position.

Encounter readability must come from coordinated activity, not obvious videogame turn-taking.

The non-attacking group should look like it is:
- trying to improve position;
- protecting its own spacing;
- probing for a future opportunity;
- maintaining pressure through presence and movement;
- yielding a bad attack lane to another enemy.

The player should perceive a dangerous group whose attack timing is controlled, not actors standing on marks waiting for a token.

### Reservation occurs before attack telegraph commitment
A Major Commit reservation must be granted **before** an enemy begins the gameplay-significant attack telegraph/startup.

Reason:
- two enemies must not both visibly enter committed attack startup and only then discover that one lost the permission race;
- aborting a genuine telegraph because another AI won a token creates false reads and trains the player not to trust animation.

Once a committed telegraph begins, the reservation remains owned until that action reaches its reviewed release point or is legitimately canceled/interrupted.

Exact per-attack release timing belongs to the attack/archetype decision, but it cannot release so early that another Major Commit begins while the first attack is still demanding the same immediate defensive attention.

### Permission is not target lock
Neris locking onto an enemy does **not** automatically:
- grant that enemy Major Commit permission;
- deny all other enemies attack permission;
- make the locked enemy the encounter's permanent 'duelist';
- force the coordinator to choose the closest or centered enemy.

Target lock is player tactical/camera state. Encounter attack permission is enemy-group authority.

This preserves Camera #13's rule that secondary enemies do not gain camera authority while still allowing them to become the next actual threat when fair.

### Permission is not damage immunity or action armor
An enemy without a commit reservation may still:
- be hit;
- react;
- move;
- defend where later authority allows;
- be interrupted;
- die.

A granted reservation also does not make the enemy uninterruptible. If player combat/enemy reaction authority later interrupts that attack, the reservation is released through explicit cleanup.

### Scheduler favors fairness and encounter flow, not hidden omniscient optimization
When multiple enemies request the same permission, candidate selection may consider only honest gameplay information available to encounter logic, such as:
- whether the enemy has a valid attack opportunity;
- line of sight / real obstruction;
- distance/range eligibility;
- usable approach/attack lane;
- whether the enemy is already meaningfully visible/readable to the player;
- time since that enemy last held a commit;
- time spent ready but denied;
- archetype role and currently occupied threat lane;
- current encounter composition.

It must not use hidden narrative importance, puzzle solutions, future player input, or a target the camera 'wants' the player to notice.

The scheduler must avoid starvation: one enemy should not monopolize every Major Commit merely because its local attack loop refreshes fastest.

Exact weighting/tie-breaking remains tuning/implementation data and must be inspectable.

### No same-frame dog-pile on permission release
When one Major Commit ends, the coordinator may grant the next reservation promptly, but it must preserve a small **readability handoff boundary** so multiple queued enemies do not effectively begin simultaneous commits on the release frame.

This boundary is semantic, not a mandated long cooldown. Exact time is human-play tuning.

Its purpose is to make the next commitment readable, not to give the player free downtime.

### Escalation changes pressure quality before concurrency
Difficulty, encounter escalation, or later enemy sophistication should first increase challenge through approved dimensions such as:
- better positioning;
- shorter wasted reposition time;
- stronger archetype combinations;
- more demanding but still readable attack properties;
- better reaction to player spacing;
- reduced excessive handoff slack;
- pressure-compatible actions once individually approved;
- arena constraints and encounter composition.

The default difficulty lever is **not** 'let more Major Commits overlap.'

Any encounter that intentionally permits two simultaneous Major Commits is an authored exception requiring its own readability justification and test case. It cannot emerge accidentally from difficulty scaling.

### Offscreen enemies do not receive a cheaper fairness standard
An enemy being offscreen never makes its attack more permissible merely because the player is not looking at it.

Before a future offscreen-capable attack can receive a commit, its archetype/attack contract must establish adequate warning through honest channels such as:
- sufficiently early audible telegraph plus non-audio equivalent;
- directional threat UI where approved/configured;
- visible projectile/travel evidence;
- companion/world callout where narratively appropriate and accessible;
- enough reaction time after the warning becomes interpretable.

A hard-occluded enemy with no honest readable threat path may reposition, but may not launch an unavoidable Major Commit through architecture.

Exact offscreen rules remain a later Issue #104 decision. Decision #1 establishes only that **offscreen is not permission to cheat**.

### Occlusion and geometry remain honest
The coordinator may know that an enemy is occluded for scheduling purposes, but it does not grant wall vision to the enemy.

Commit eligibility must still respect the attack's actual line-of-fire / traversal / reach rules.

EQS or pathfinding may help an enemy find a better position; they do not authorize attacks through blocked geometry.

### Group collision/positioning must protect readable attack lanes
Later archetype decisions must prevent non-committing enemies from:
- standing inside the committed attacker;
- visually masking the active telegraph without an authored reason;
- pushing the player into geometry by crowd collision alone;
- occupying the same approach slot and jittering for access;
- creating accidental body-wall traps that defeat the player's approved Evade displacement.

Decision #1 therefore requires a shared concept of **approach/pressure occupancy** even though exact spatial sectors/radii belong to later positioning decisions.

### No hidden global 'AI pause' after player actions
The encounter does not automatically stop all enemy aggression because Neris:
- begins a combo;
- gets a Perfect Guard;
- switches targets;
- uses Heavy;
- is briefly in Evade immunity.

Enemy permission remains governed by the shared budget and each attack's legal opportunity. Player success may create natural consequences through hit reactions, spacing, interruption, or authored future rules—not a universal courtesy pause.

Death is the exception: player Death ends active player combat and the encounter must stop issuing new player-directed commits according to the later encounter-reset/death integration contract.

---

## Why not literal Ocarina one-at-a-time combat
Nintendo's Ocarina development staff explicitly described using staged sword-fight logic: when surrounded, opponents wait and attack in order so multi-enemy combat does not become a swarm. That is a foundational readability lesson, not Stillring's final expression.

Stillring keeps the underlying insight—**simultaneous threats must be authored around human attention**—but modernizes it:
- non-attacking enemies remain spatially active;
- the permission system is independent of target lock;
- later low-salience pressure may overlap when separately justified;
- offscreen fairness and accessibility are explicit;
- group behavior is debug-visible rather than hidden inside each enemy.

No Nintendo timing, enemy behavior, target rules, animation, code, or encounter composition is copied.

---

## Unreal Engine 5.8 implementation boundary

Epic's current AI stack provides several useful primitives:
- Behavior Trees + Blackboards can execute local AI branches;
- StateTree can represent hierarchical state/transition logic;
- EQS can score/generate candidate positions or actors;
- native C++ can own shared authoritative encounter coordination.

Stillring does **not** select one of those as design authority in this decision.

Recommended responsibility boundary:
- **Encounter coordinator / authoritative gameplay service:** owns commit reservations, lanes, eligibility result, rejection reason, starvation/readability bookkeeping;
- **Enemy-local AI (BT/StateTree/C++):** requests a reservation, performs approved positioning/attack behavior, reports completion/interruption;
- **EQS/navigation:** proposes useful positions/lanes;
- **animation:** presents the already-approved enemy action/telegraph;
- **Combat/Encounter IDE:** exposes exactly why permission was granted/denied.

A Behavior Tree decorator such as `CanAttack` may query the coordinator; it may not become an independent local token implementation on every enemy.

---

## Accessibility / readability boundary

Requirements:
- attack fairness cannot depend only on stereo/surround audio;
- any directional offscreen UI added later must be configurable and have non-color-only semantics where color carries threat class;
- difficulty/accessibility settings may expand reaction/telegraph assistance without secretly changing player Guard/Evade legality;
- reducing camera shake/vibration cannot reduce access to attack information;
- enemies denied Major Commit still communicate presence without flooding the player with fake urgent telegraphs;
- high-contrast/enemy-visibility settings must not alter which enemy is actually permitted to attack.

---

## Combat / Encounter IDE requirements

### Inspect
Expose in real time:
- all enemies registered to the encounter;
- each enemy's archetype, local state, visibility/occlusion, distance, attack readiness;
- requested permission class;
- current Major Commit holder;
- current Pressure Commit holder if later applicable;
- reservation start/release reason;
- each denied request + semantic reason;
- time ready / time since last commit;
- starvation/fairness score inputs;
- current approach/pressure occupancy;
- target-lock identity shown separately from commit holder;
- active attack telegraph/action/phase;
- any offscreen-readability eligibility state;
- any authored exception allowing simultaneous Major Commits.

### Tune
With full canonical/session/staged/promoted provenance:
- readability handoff timing;
- starvation/fairness weights;
- archetype permission priorities after those archetypes are approved;
- future Pressure Commit eligibility/timing;
- positioning occupancy spacing values.

No live tune control may silently change the semantic baseline from one Major Commit to two.

### Exercise
Named scenarios:
- two identical melee enemies;
- three melee enemies around Neris;
- five-enemy pressure ring;
- future melee + ranged mix;
- two enemies both become ready on same frame;
- current attacker interrupted immediately;
- current attacker killed in Startup;
- target switch away from current commit holder;
- commit holder moves offscreen;
- cramped room / low ceiling camera;
- hard wall occlusion;
- player repeatedly circles to change visibility;
- player holds Guard;
- player chains repeated Evades;
- 30/60/120+ FPS scheduling consistency.

### Validate
Detect:
- more than one ordinary Major Commit active without explicit authored exception;
- attack telegraph starting before reservation grant;
- reservation released while the attack still owns primary defensive attention;
- enemy attack beginning without any reservation;
- target lock used as commit permission;
- starvation / same enemy monopolizing commits beyond allowed policy;
- denied enemy frozen in unapproved idle behavior for excessive time;
- two enemies occupying the same approach slot;
- hard-occluded attack granted despite attack needing unobstructed path/line of fire;
- difficulty setting increasing Major Commit concurrency without authority;
- fake urgent attack telegraph from an enemy that has no permission to commit;
- stale reservation after interrupt/death/despawn/reset.

### Capture
Record deterministic encounter timelines with:
- enemy readiness requests;
- grant/deny/release events;
- reason codes;
- visibility/position snapshot;
- target lock;
- active attack telegraph/phase;
- hit/reaction/interruption;
- player defensive actions;
- approach occupancy;
- camera visibility context;
- frame/time stamps.

A designer should be able to answer **'why did those two attacks overlap?'** from structured capture rather than video archaeology.

---

## Representative red-team tests

1. Two melee enemies become attack-ready on the same simulation frame: exactly one receives Major Commit.
2. Three enemies rotate around Neris for 60 seconds: all remain active and none starves indefinitely.
3. Kill/interupt the current commit holder during Startup: reservation cleanup is deterministic and the next handoff remains readable.
4. Lock onto a non-holder: lock identity changes, commit ownership does not magically transfer.
5. Switch targets rapidly while several enemies are ready: no attack-token roulette follows the camera.
6. Put the ready enemy behind hard cover: no impossible commit through geometry.
7. Force current holder offscreen mid-commit: existing approved action resolves under its later offscreen contract; no new invisible cheat is created.
8. Five enemies surround Neris: non-holders reposition/pressure without forming a frozen waiting circle or collision wall.
9. Hold Guard indefinitely: group positioning/flanking may create pressure later, but the coordinator does not violate one-Major baseline merely to defeat Guard.
10. Repeated Evade: enemy commitments continue under the same budget; no courtesy global pause.
11. Mix future melee/ranged candidates: both use the same semantic permission service; ranged AI does not get a separate hidden attack bypass.
12. Toggle accessibility/offscreen indicators/shake: permission semantics remain unchanged.
13. Vary frame rate 30/60/120+: same readiness snapshot/tie-break inputs produce deterministic permission behavior where context is equivalent.

---

## Research basis / design lineage

### Primary / official references
- Nintendo, *Iwata Asks: The Legend of Zelda: Ocarina of Time 3D — Original Development Staff Part 1*: Yoshiaki Koizumi describes observing staged sword fights where surrounding enemies attack in order rather than all at once, and using that clue to solve multi-enemy Z-targeting readability. https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/1/2/
- Nintendo regional mirror of the same development interview. https://www.nintendo.com/en-za/Iwata-Asks/Iwata-Asks-The-Legend-of-Zelda-Ocarina-of-Time-3D/Vol-2-Original-Development-Staff-Part-1/3-Let-s-Go-to-Toei-Kyoto-Studio-Park-/3-Let-s-Go-to-Toei-Kyoto-Studio-Park--231680.html
- Epic Games, Unreal Engine 5.8 Behavior Trees: local AI execution using Behavior Trees/Blackboards. https://dev.epicgames.com/documentation/en-us/unreal-engine/behavior-trees-in-unreal-engine
- Epic Games, Unreal Engine 5.8 StateTree Quick Start/Selectors: hierarchical states/transitions and selection are implementation primitives. https://dev.epicgames.com/documentation/unreal-engine/statetree-quick-start-guide
- Epic Games, Unreal Engine 5.8 EQS User Guide: environment queries generate/test/weight positions or actors and can run from BT/native code. https://dev.epicgames.com/documentation/en-us/unreal-engine/environment-query-system-user-guide-in-unreal-engine
- PlayStation, *God of War Ragnarök Accessibility*: configurable Enemy Off-Screen Indicator communicates direction/type of incoming attack, demonstrating that offscreen threat communication is a deliberate UX/accessibility surface. https://www.playstation.com/en-gb/games/god-of-war-ragnarok/accessibility/

### Comparative problem study
- Game Developer's melee-enemy AI survey and other combat-AI literature document token/coordination patterns as common solutions to multi-enemy overload. Stillring uses none of their code or exact values; the relevant abstract lesson is that independent local attack readiness needs group-level coordination.
- Player discussion around modern close-camera action games repeatedly identifies poorly warned offscreen cross-pressure as a readability failure. This is treated as failure evidence, not authority.

---

## Why this package is approved
The one-Major-Commit baseline preserves the successful readability insight behind classic lock-on combat without freezing the rest of the group into 1998-style obvious turn-taking.

It also gives later decisions a clean extension point: a ranged or special attack must **earn** `PressureCommit` status by proving it can overlap without corrupting Guard/Evade reads.

Most importantly, the system can explain itself. When combat feels unfair, the IDE can show whether the fault was attack permission, positioning, telegraphing, offscreen communication, or a later archetype contract.

---

## Player-facing acceptance
Decision #1 passes when:
1. ordinary encounters never produce two unapproved simultaneous Major Commits;
2. non-attacking enemies stay spatially active rather than freezing in a waiting ring;
3. a real attack telegraph never begins before permission is granted;
4. target lock and commit permission remain independent;
5. a committed attacker can still be interrupted/killed normally;
6. offscreen/occluded enemies receive no hidden fairness exemption;
7. no attack bypasses the shared permission service through a local BT/StateTree/animation path;
8. difficulty does not silently increase Major Commit concurrency;
9. reservation cleanup is deterministic on interrupt/death/despawn/reset;
10. Combat/Encounter IDE can explain every grant, denial, overlap, and handoff.

---

## Next enemy / encounter decision
**Decision #2 — melee enemy pressure / spacing / commitment model.**

Research independently before approval. Define how the representative melee enemy approaches, occupies space, requests Major Commit, attacks, recovers, yields/repositions, responds to lock/unlock and player spacing, avoids orbit/autopilot behavior, and remains dangerous without collision swarming or fake waiting.

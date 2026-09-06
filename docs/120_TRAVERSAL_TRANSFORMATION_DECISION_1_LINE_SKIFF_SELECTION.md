# 120 — Traversal Transformation Decision #1 — Line Skiff Selection

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #10 — Design Stillring traversal transformation and mastery loop  
**Decision:** #1 — evaluate three traversal-transformation concepts against canon, locomotion/camera authority, production cost, puzzle preservation, Hush/Stillness, optional systems, and mastery hooks; select one for prototype

## Decision question

Which midgame traversal transformation should Stillring prototype so that travel becomes faster and more expressive without becoming a horse analogue, universal free-roam vehicle, or puzzle-bypass system?

## Locked selection

**Select the Line Skiff / resonance road-sled concept.**

The Line Skiff is a **network vehicle**, not a mount.

> It makes authored roads newly expressive; it does not replace the world between them.

It operates only on compatible authored route reinforcement strips, junctions, docks, and explicitly supported changed-world route variants. It cannot be summoned anywhere, driven cross-country, used as a general combat mount, or treated as universal fast travel.

This decision formalizes and reconciles the Line Skiff already seeded across existing story/progression/completion authority.

---

# Existing canon that constrains the decision

The repository already establishes all of the following:

- Graymile foreshadows a mothballed Line Skiff before Grand Ring;
- Tessa's route history is tied to that infrastructure;
- after Grand Ring, Tessa arrives during a moving window using the seeded Line Skiff;
- Neris acquires usable Line Skiff traversal and `pattern.roadhand_pulse` on the changed-world return;
- Roadhand Pulse briefly wakes or identifies old route reinforcement strips without asking a central route bell for permission;
- Roadhand Pulse explicitly does **not** summon a vehicle from anywhere or turn every road into a fast-travel rail;
- Line Skiff traversal supports the 12 Drift Knots;
- Trial 05 `trial.circuit.line_skiff_relay_run` already tests acceleration, coasting, route reading, junction choice, and Roadhand Pulse;
- Drift Knot eligibility is 10 reconciled Resonance Faults plus existing story/Line Skiff prerequisites;
- the progression blueprint already names Line Skiff as authored fast-route traversal and world-travel mastery.

Issue #10 therefore does not begin from a blank slate. It must either formally validate this direction or prove that replacing it is worth the resulting story/content churn.

---

# Fresh research conclusions

## Reusing a known world with a new travel layer

Nintendo's Tears of the Kingdom developer interviews emphasize that radically different traversal methods are especially powerful when players already know the underlying world. Faster/new travel changes how a remembered place is read rather than making the player skip an unknown place.

Stillring's timing is structurally compatible with that principle: the Line Skiff is acquired **after** the player has already traveled the bell roads and visited the major regional cultures before Grand Ring.

The lesson used here is the design problem only. Stillring does not copy Zelda's vehicle construction, controls, visuals, physics, or content structure.

## Authored traversal highways

Ubisoft's postmortem material on Assassin's Creed Mirage describes deliberately built but visually natural traversal "highways" through the environment, with focused polish passes needed to make high-speed routes readable and reliable.

That supports Stillring's route-network direction: fast travel becomes a authored layer designers can reason about, test, polish, and combine with route choices rather than a universal physics vehicle that must work everywhere.

## Higher speed increases camera/world-system cost

Insomniac's GDC material on Spider-Man and Spider-Man 2 emphasizes that increasing traversal speed forces changes across camera behavior and existing movement systems, not merely player velocity.

Therefore Stillring should constrain its high-speed transformation to a network where camera envelopes, collision/readability, streaming, junction sightlines, and failure recovery can be authored and regression-tested.

## Infrastructure itself can be compelling traversal content

Death Stranding/Death Stranding 2 developer interviews show that players can value travel infrastructure such as highways and monorails as gameplay in itself, rather than viewing infrastructure only as an inconvenience between objectives.

Stillring's network is not player-built and does not imitate Death Stranding's social systems, but the broader lesson supports making route infrastructure a meaningful authored object with history, repair states, and mastery rather than merely a hidden fast-travel menu.

## Ambition has ripple cost

Solar Ash development commentary highlights how high-speed/anti-gravity traversal created large production ripple effects. This reinforces the need to avoid choosing the concept with the largest traversal envelope merely because it sounds spectacular.

---

# Candidate A — Line Skiff / resonance road-sled

## Core identity

A compact Orra-native courier/maintenance vehicle that couples to old route reinforcement strips embedded through selected bell roads and service corridors.

It is physically present, parked/docked, acquired through Tessa and Graymile infrastructure, and operated through local route relationships rather than a centralized summon service.

## Why it fits Stillring

- already foreshadowed in canonical story;
- tied to Tessa's existing identity and courier history;
- uses Roadhand Pulse, an already canonical Cantor pattern;
- turns old infrastructure into changed-world traversal rather than adding unrelated fantasy transport;
- supports Drift Knots directly;
- supports an existing mastery trial directly;
- makes return travel meaningfully faster while preserving authored junctions/route reading;
- its network can change under Stillness/Hush without becoming generic alternate-world duplication;
- it has a silhouette, fiction, acquisition, and operating grammar distinct from a horse.

## Movement/camera fit

The Line Skiff may receive its own explicit traversal camera state, but it remains compatible with current camera principles:

- the world remains the visual priority;
- player manual camera input retains authority;
- route sightlines and footing/junction readability remain important;
- stronger travel-direction assistance may be tuned for sustained high-speed route travel, but no hard camera theft is implied;
- reduced shake/motion effects must be supported;
- high speed is constrained to authored corridors that can be camera-tested.

Exact Skiff camera behavior is a later Issue #10 decision and is not silently invented here.

## Production cost

**Moderate and bounded.**

Major costs:

- Skiff movement/controller state;
- one vehicle presentation/animation set;
- mount/dismount equivalent docking/boarding interactions, without animal locomotion;
- route reinforcement-strip data;
- junction/switch logic;
- collision/failure/recovery;
- high-speed camera state;
- route authoring/validation tooling;
- save/reload and changed-world variants;
- Hush/Stillness route state;
- accessibility and deterministic fixtures.

Cost stays bounded because the Skiff is not required to solve arbitrary off-road terrain.

## Puzzle/exploration preservation

Strongest candidate.

The Skiff cannot enter every space. It does not replace:

- on-foot close exploration;
- authored climbing/ledge/ladder grammar;
- tool-gated traversal;
- dungeons/interiors unless a route is explicitly authored there;
- local environmental puzzles;
- terrain between route nodes;
- Vane, Anchor, Glasslung, Mirror, seam, or other distinct traversal verbs.

## Optional/mastery fit

Excellent.

Already supports:

- 12 Drift Knots;
- Trial 05 Relay Run;
- courier route work;
- Route Listener end-state service;
- later tool-combination route variants.

## Verdict

**SELECT.**

---

# Candidate B — Wind-rig / updraft travel system

## Core identity considered

A deployable wind-supported rig that uses authored updraft lanes, bell-road air channels, or regional lift currents to increase cross-region mobility.

## Strengths

- potentially expressive and visually distinctive;
- strong fit with High Aerie's wind language;
- could produce skillful momentum/route reading;
- could create attractive vertical shortcuts and graceful descent travel.

## Conflicts

### Overlaps the Vane Cloak

High Aerie already owns a later wind traversal transformation through the Vane Cloak and Motion discovery.

Making wind travel the major midgame world-travel system would steal mechanical/thematic territory from that later acquisition and flatten progression differentiation.

### Weak acquisition timing

If acquired before High Aerie, the fiction needs a second major wind technology before the region whose identity is specifically wind/suspension. If acquired at High Aerie, it arrives too late to serve the intended changed-world return and early Drift Knot/cross-region transformation role without restructuring substantial existing canon.

### Puzzle bypass risk

Free or semi-free vertical movement increases the chance of bypassing:

- authored cliffs;
- route gates;
- Anchor/Vane-specific problems;
- intended approach compositions;
- vertical environmental puzzles.

Constraining the wind-rig enough to prevent this would effectively turn it into another authored-lane system, at which point the Line Skiff already fits existing canon better.

### Camera/world cost

Three-dimensional high-speed travel requires a larger camera/streaming/collision/readability envelope than route-bound ground travel.

## Production cost

**High.**

Requires larger 3D route volumes, airborne collision/failure recovery, vertical camera behavior, landing rules, world-edge/puzzle-bypass protection, and extensive region-by-region traversal audit.

## Verdict

**REJECT as the Issue #10 midgame transformation.**

Wind remains valuable through the already distinct Vane Cloak and High Aerie traversal language.

---

# Candidate C — Maintenance Strider

## Core identity considered

A mechanical articulated walking platform used by route crews for maintenance access and longer travel.

## Strengths

- could feel materially grounded in Orra's repair culture;
- potentially useful on damaged routes;
- offers an obvious fiction for carrying tools or traversing uneven terrain.

## Conflicts

### Horse-analogue risk

Even without being an animal, a rideable walking machine can easily function like a conventional mount:

- acquire vehicle;
- call/find vehicle;
- mount;
- steer freely across ordinary terrain;
- dismount near destinations.

That reproduces the behavioral role Issue #10 explicitly wants to avoid.

### Production burden

Articulated terrain locomotion creates substantial complexity:

- foot placement / IK;
- uneven terrain adaptation;
- slopes/steps;
- collision snagging;
- narrow spaces;
- turning radius;
- boarding/dismounting on variable ground;
- ledge/drop handling;
- animation/procedural presentation;
- terrain validation throughout the world.

### Weak puzzle-preservation boundary

If the Strider can handle enough terrain to be satisfying as a cross-region transformation, designers must continuously answer why it cannot simply step over or around authored traversal barriers.

If heavily constrained to marked routes, it becomes more expensive than the Line Skiff without gaining a stronger gameplay identity.

## Production cost

**High to very high.**

It solves a terrain-generalization problem Stillring does not otherwise need.

## Verdict

**REJECT.**

---

# Comparative decision matrix

| Criterion | Line Skiff | Wind-rig | Maintenance Strider |
|---|---|---|---|
| Existing story foreshadowing | Excellent | Poor | Poor |
| Midgame timing fit | Excellent | Weak/conflicts with High Aerie | Possible but unsupported |
| Orra-native fiction | Excellent | Good | Good |
| Horse-analogue avoidance | Excellent | Excellent | Weak |
| Preserves authored on-foot space | Excellent | Risky | Risky |
| Camera scope | Bounded high-speed corridor | Large 3D envelope | Terrain-generalized |
| Production cost | Moderate/bounded | High | High/very high |
| Drift Knot fit | Existing direct fit | Requires redesign | Requires redesign |
| Mastery-trial fit | Existing Trial 05 | New trial needed/redundant with Vane | New trial needed |
| Hush/Stillness route-state potential | Excellent | Possible but broad | Possible but expensive |
| Existing canon churn | Minimal | Major | Major |
| Prototype recommendation | **YES** | No | No |

---

# Locked Line Skiff identity

## Network vehicle, not mount

The Line Skiff:

- travels only on compatible authored reinforcement strips/routes;
- starts/parks at compatible authored route points using Roadhand Pulse;
- may use authored junctions, splits, dormant maintenance lanes, and changed-world route variants;
- cannot be called/summoned to arbitrary player location;
- cannot become a pocket inventory item;
- cannot travel freely over arbitrary fields, cliffs, forests, wetlands, roofs, or dungeon geometry;
- cannot convert all ordinary roads into Skiff routes;
- does not replace the Line Skiff dock/network with a menu-only fast-travel system;
- is not baseline combat locomotion;
- does not grant universal traversal eligibility merely because it is owned.

## No consumable travel tax

Ordinary Line Skiff traversal does not use a stamina meter, fuel grind, consumable ticket, repair tax, or battery resource merely to limit normal use.

Route access is controlled by authored infrastructure state, story/world state, route compatibility, and player route decisions—not by forcing the player to farm travel currency.

Damage/failure consequences may exist where authored later, but must not turn normal cross-region use into maintenance busywork.

## Familiar-world transformation

The Line Skiff is intentionally acquired after substantial on-foot familiarity with Orra.

It should make the player recognize:

> "I know this road, but I can read it differently now."

It is not intended to make the player think:

> "I never need to look at this road again."

## Relationship/foreshadow authority

The canonical foreshadow/acquisition relationship remains Tessa + Graymile:

- First Circuit: player sees the mothballed Skiff and learns enough of Tessa's route history for the object to register as real infrastructure rather than a future gadget pedestal;
- changed-world return: Tessa arrives using the same infrastructure during a moving window;
- tutorial/acquisition: Roadhand Pulse makes local reinforcement strips usable without central route-bell authority;
- first playable stretch must include a period where traversal is simply enjoyable rather than immediately becoming another crisis timer.

---

# Hush / Stillness boundary at concept-selection level

Detailed route-state behavior remains later Issue #10 authority, but concept selection locks these limits:

- Stillness may change which reinforcement strips are usable, moving, phase-locked, damaged, or locally wakeable;
- Roadhand Pulse can interact only with authored compatible route infrastructure;
- Hush does not create a universal phantom road network;
- Waking/Hush route differences must use explicit authored semantic state and source ownership;
- Hush-bleeding route variants may exist for Drift Knots or authored story routes;
- no generic "enter Hush and drive anywhere" behavior;
- later world changes may reroute a network while preserving recoverable connectivity and completion-safe Drift Knot variants.

---

# System IDE requirement

Issue #10 must build a dedicated Line Skiff / Route Network workbench inside the shared in-game System IDE shell.

At minimum future decisions must make it capable of exposing:

- route semantic ID;
- reinforcement-strip state;
- junction graph;
- compatible entry/park nodes;
- current Skiff state;
- velocity/momentum/coasting state;
- active Roadhand Pulse result;
- route eligibility failure reason;
- world-state/Hush/Stillness variant;
- Drift Knot integration;
- camera state;
- accessibility modifiers;
- save/reload state;
- deterministic route fixtures;
- invalid bypass/cut detection.

The workbench must use authoritative traversal/world services, not a second debug-only network model.

---

# Decision #1 deterministic evaluation fixtures

The later prototype must eventually prove at least:

1. Skiff cannot leave an authored compatible network under normal control;
2. Skiff cannot be summoned to arbitrary off-network player location;
3. a known pre-Grand-Ring road becomes meaningfully faster/more expressive post-acquisition;
4. nearby on-foot secret/puzzle space remains intentionally inaccessible from the Skiff unless an authored route says otherwise;
5. a broken/phase-locked route produces an explicit unavailable reason rather than invisible failure;
6. Roadhand Pulse starts/parks/wakes only compatible route infrastructure;
7. manual camera control remains authoritative during high-speed travel;
8. reduced motion/shake support preserves route readability;
9. Drift Knot route integration functions without random spawning;
10. Trial 05 can exercise momentum/junction reading rather than simple top-speed racing;
11. save/load restores to a stable route state without duplicating traversal rewards or stranding the Skiff;
12. changed-world route variants remain semantically identifiable and testable;
13. no ordinary stamina/fuel/consumable tax blocks normal Skiff travel;
14. owning the Skiff does not silently alter baseline on-foot traversal eligibility.

---

# Rejection conditions

Revisit this decision if implementation drifts into any of the following:

- summon-anywhere mount behavior;
- free-roam cross-country vehicle behavior;
- universal route bypass;
- high-speed traversal that requires redesigning every exterior space for vehicle access;
- ordinary use gated by stamina/fuel grinding;
- combat effectiveness becoming the Skiff's primary identity;
- camera hard-locking that removes manual viewing authority;
- Hush automatically providing roads everywhere;
- Drift Knots becoming random vehicle collectibles;
- Vane Cloak losing distinct traversal purpose because the Skiff gained broad airborne freedom;
- route network becoming a glorified loading-screen fast-travel menu;
- high-speed corridors repeatedly skipping authored encounters, puzzles, or ordinary-life spaces that are supposed to be experienced on foot.

---

# Research basis

Fresh design-problem references used for this decision:

- Nintendo developer interviews on Tears of the Kingdom: new traversal methods gain meaning when applied to a world players already know, and traversal freedom requires strong affordance/readability rules;
- GDC 2024 Insomniac `Higher, Faster, Farther: Evolving Traversal in Marvel's Spider-Man 2`: higher traversal speed forces supporting movement/camera/system evolution;
- Ubisoft Assassin's Creed Mirage postmortem material: deliberately authored traversal "highways" require route readability and polish rather than being accidental geometry;
- PlayStation/Kojima Productions Death Stranding 2 interviews: players can value traversal infrastructure such as roads/monorails as gameplay rather than merely a shortcut;
- Heart Machine Solar Ash development commentary: ambitious high-speed/anti-gravity traversal creates wide production ripple effects.

These are design references only. Stillring's fiction, routes, mechanics, names, controls, vehicle form, content, and implementation remain original.

## Approval

**APPROVED / LOCKED under the owner's prior locomotion/traversal delegation and current instruction to proceed.**

## Final locked statement

> **Stillring's Issue #10 prototype concept is the Line Skiff: a physically present Orra-native network vehicle bound to authored route reinforcement strips, junctions, and compatible changed-world variants. It is not a horse analogue, summonable mount, free-roam vehicle, universal fast-travel rail, combat platform, or fuel/stamina economy. It is acquired through the already seeded Tessa/Graymile relationship after the player knows Orra on foot, then makes familiar roads faster and more expressive while preserving authored exploration, puzzle gates, and later traversal verbs. Wind-rig and Maintenance Strider are rejected as the primary midgame transformation due to progression overlap, puzzle-bypass risk, horse-analogue behavior, and substantially higher production scope.**

## Next decision

Issue #10 Decision #2 — **Line Skiff route/network grammar:** exact route eligibility, boarding/parking/dismount boundaries, junctions, acceleration/coasting/steering ownership, off-network failure prevention, route readability, camera state, and how the system preserves on-foot exploration while still feeling transformative.

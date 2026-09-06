# 121 — Traversal Transformation Decision #2 — Line Skiff Route / Network Grammar

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #10 — Design Stillring traversal transformation and mastery loop  
**Parent:** `docs/120_TRAVERSAL_TRANSFORMATION_DECISION_1_LINE_SKIFF_SELECTION.md`  
**Decision:** #2 — semantic route graph, player-control grammar, junctions, boarding/parking, failure/recovery, camera/readability boundaries, persistence, and System IDE requirements

## Locked control principle

> **The authored network owns the Skiff's macro route; the player owns momentum, lateral placement, junction intent, and moment-to-moment execution.**

The Line Skiff is neither a free-roam vehicle nor an automatic rail ride.

Its route corridor constrains where the vehicle can physically travel, while the player retains meaningful control over:

- acceleration;
- coasting;
- braking;
- low-speed reverse;
- bounded lateral positioning inside the route corridor;
- route/junction commitment;
- Roadhand Pulse use;
- momentum management;
- camera/look direction.

No GPS autopilot, quest-marker steering, automatic race line, or objective-driven branch selection is canonical.

---

# 1. Semantic route-network authority

## Route IDs

Every persistent/authored route segment has a stable semantic identity.

Recommended format:

`skiff.route.<region>.<slug>`

Examples:

- `skiff.route.circuit.graymile_outer`
- `skiff.route.rootmere.low_road`
- `skiff.route.saltreach.breakwater`

Every persistent/authored functional node has a stable semantic identity.

Recommended format:

`skiff.node.<region>.<slug>`

Examples:

- `skiff.node.circuit.graymile_shed`
- `skiff.node.cairnspire.outer_loop_junction`
- `skiff.node.rootmere.lowroad_service_pullout`

Spline component names, Actor names, World Partition cells, Blueprint node names, coordinates, display labels, and map asset paths are not route identity.

## Node classification

A route node may carry one or more authored functional classifications, including:

- Park / Dock;
- Standard Junction;
- Legacy Transfer;
- Service / Recovery;
- Story Gate;
- Route Variant Boundary;
- Hunt / Drift Knot support node;
- authored inspection / maintenance stop.

Classification does not replace semantic node identity.

## Segment definition

Every route segment must be able to declare at least:

- semantic segment ID;
- endpoint node IDs;
- route class / presentation family;
- current semantic world-state variant;
- normal supported directionality;
- authored speed envelope;
- allowed lateral corridor envelope;
- clearance/camera envelope requirements;
- compatible entry/park nodes;
- supported standard junctions;
- supported legacy-transfer relationships;
- required progression/tool state if any;
- Roadhand Pulse interaction state;
- Stillness/Hush compatibility metadata;
- changed-world replacement/variant references;
- Drift Knot/hunt compatibility where relevant;
- safe-stop/recovery guarantees.

The gameplay route graph is semantic data. Geometry/splines present and resolve that graph in the world; they do not become its persistence authority.

---

# 2. Coupling and physical movement model

## Route coupling

The Skiff couples to compatible route reinforcement infrastructure.

While coupled:

- the route defines the legal macro travel corridor and longitudinal path family;
- the Skiff does not become a full six-degree/free-surface physics vehicle;
- player steering modifies bounded lateral placement and local approach within that corridor;
- orientation follows the route's valid travel frame smoothly enough that the player does not need to manually trace every road curve like a car simulator;
- player input still matters for speed, obstacle handling, route position, junction preparation, and momentum.

The control target is **expressive constrained traversal**, not train automation and not open-world driving simulation.

## Longitudinal control

### Accelerate
Player input commands acceleration toward the segment's supported speed envelope.

There is no universal instant max-speed toggle.

### Coast
Releasing acceleration preserves useful momentum and allows natural decay rather than snapping immediately to a fixed cruising speed.

Coasting is a first-class mastery behavior and part of Trial 05 authority.

### Brake
Brake provides deliberate speed reduction and prepares for junctions, obstacles, park nodes, and route-state uncertainty.

Brake must be responsive enough that readable upcoming information can be acted on without requiring route memorization from a prior failed attempt.

### Low-speed reverse
Reverse is permitted only as a low-speed recovery/positioning behavior while the route state supports it.

It is not a second full-speed travel mode and does not turn the Skiff into a general vehicle for arbitrary backtracking anywhere.

## No ordinary boost

Roadhand Pulse is **not a speed boost**.

No default turbo/nitro mechanic is implied by this system.

Future implementation may tune acceleration profiles, slopes, drafting-like route relationships, or world-driven momentum where fictionally justified, but the baseline route grammar must not require an expendable boost resource to feel fun.

---

# 3. Lateral micro-control

## Corridor width

A valid Skiff route is not a one-pixel rail.

Where route art/fiction supports it, the player receives enough lateral authority to:

- choose a cleaner line;
- avoid obstacles/debris;
- prepare for junctions/transfers;
- align with maintenance interactions;
- interact with moving-fault/hunt elements;
- experience handling skill rather than passive transport.

Exact corridor width is authored/tuned per route family and is not one global number.

## Edge behavior

Pushing toward the edge of a valid corridor should produce readable physical resistance such as:

- lateral scrub;
- traction/guide resistance;
- momentum loss;
- visual/surface feedback;
- optional haptic feedback.

The primary experience must not be invisible billiard-wall bouncing.

Normal steering cannot intentionally eject the Skiff from a supported reinforcement strip.

## Invalid route boundary

If geometry/world state ahead makes the route truly invalid rather than merely difficult, the system must enter an authored safe-braking/blocked behavior.

It must not rely on:

- launching the Skiff into a void;
- physics derailment as normal validation;
- invisible teleport correction with no explanation;
- player death because an unloaded/invalid route segment existed.

---

# 4. Junction grammar

## Standard junctions

At a readable authored fork, the player selects a route using directional branch intent during an approach window.

The junction must communicate available branches early enough that a first-time player traveling at a reasonable supported speed can react.

Quest objectives never silently choose the branch for the player.

## Default continuation

If the player provides no branch intent and a clear continuation of the current route remains valid, the Skiff continues along that current/mainline path.

This avoids making every ordinary fork into a mandatory quick-time event.

## No safe default

If a junction has no legitimate default continuation, insufficient/ambiguous input must result in a readable safe deceleration/stop before irreversible branch commitment.

The system must not randomly choose a route.

## Commitment

Once the player passes an authored branch-commit threshold, the selected branch becomes the current macro route.

Late input beyond the safe physical transfer window does not teleport the Skiff sideways to honor an impossible choice.

Missing a junction costs route efficiency/position, not arbitrary instant failure.

---

# 5. Legacy transfers and Switchshoe

The existing `upgrade.lineskiff.switchshoe` authority remains intact.

## Before Switchshoe

At a compatible marked legacy transfer between adjacent reinforcement strips, the player may need to:

- decelerate;
- stop/park at the supported transfer node;
- reposition/re-couple;
- then continue on the adjacent strip.

Exact presentation may vary by site.

## After Switchshoe

At explicitly compatible legacy junctions, Switchshoe allows **at-speed transfer between adjacent reinforcement strips without stopping**.

This is a new route-handling possibility, not a stat increase.

Switchshoe does not:

- increase global top speed merely because equipped;
- permit arbitrary lane-hopping between non-adjacent routes;
- permit off-network movement;
- convert every visual nearby strip into a transfer target;
- act as a free lateral dash on ordinary roads.

Transfer eligibility is authored and explainable in the System IDE.

---

# 6. Roadhand Pulse grammar

`pattern.roadhand_pulse` remains a route-infrastructure interaction pattern.

It may:

- wake a compatible dormant reinforcement strip where authored;
- identify a compatible strip/node;
- start/park/couple the Skiff at compatible route points;
- reveal authored split/legacy junction relationships;
- expose dormant maintenance lanes;
- participate in courier/hunt route logic.

It does not:

- boost speed;
- summon the Skiff;
- create reinforcement strips out of ordinary terrain;
- auto-select a route;
- repair every broken segment instantly;
- reveal unrelated secrets/collectibles;
- replace required Anchor/Glasslung/Temper/Vane/Mirror/seam interactions on authored routes.

Pulse response must identify why a requested route interaction succeeded or failed through redundant feedback and System IDE explanation.

---

# 7. Boarding / parking / leaving the Skiff

## Compatible nodes only

Normal boarding and intentional dismount occur only at compatible authored semantic nodes.

This protects:

- route continuity;
- world staging;
- on-foot puzzle boundaries;
- save/reload safety;
- vehicle recovery;
- production scope.

The player cannot hop off at arbitrary high-speed positions between nodes merely to bypass geometry.

## Parking request

A player-issued Park/Leave request causes the Skiff to seek the **next reachable valid safe park node on the current route logic**, then perform a controlled deceleration/parking sequence.

The player should receive clear indication that the request was accepted and where the upcoming safe stop lies at the level of route readability needed to avoid confusion.

## Park-node density

Routes that pass near authored on-foot content expected to be visited from that road must include practical safe access points.

A route is invalid content design if it repeatedly shows the player meaningful nearby spaces but provides no reasonable way to stop and reach them.

Conversely, parking nodes must not be placed every few seconds merely to compensate for poor network planning, because that would reduce the Skiff to a sequence of menu-like stops.

## Emergency stop

Blocked/failure states may stop at a semantic service/recovery point even if it is not an ordinary player-selected park node.

Emergency recovery may not be used as an intentional bypass into normally inaccessible on-foot spaces.

## No routine high-speed dismount

There is no baseline `jump from Skiff at full speed` traversal trick.

This avoids:

- accidental geometry exploits;
- traversal-gate bypass;
- large landing-animation/damage edge-case scope;
- turning Skiff ejection into an unintended movement verb.

A specific authored story sequence could override this only through a later explicit reviewed contract; it is not baseline capability.

---

# 8. On-foot exploration preservation

The network must be designed so Skiff ownership does not invalidate Stillring's existing adventure grammar.

## Skiff should bypass dead travel, not meaningful content

A route may accelerate travel through:

- roads the player already knows;
- long cross-region connectors;
- changed-world courier corridors;
- deliberately authored high-speed route sequences;
- moving-fault hunt spaces.

It should not routinely bypass:

- first-time ordinary-life regional introductions;
- critical environmental storytelling;
- dungeons;
- tool-gated puzzle spaces;
- expected on-foot social hubs;
- short exploration areas where walking/looking is the content;
- cliffs/gates intentionally reserved for later traversal verbs.

## Nearby optional content

Skiff routes may intentionally show side paths, structures, Faults, characters, or secrets that require parking and continuing on foot.

This is positive design when stopping is practical and the Skiff improves route literacy rather than deleting curiosity.

---

# 9. Combat boundary

The Line Skiff is not a standard combat platform.

Baseline authority:

- Neris does not receive a Skiff-specific attack tree;
- target-lock combat does not become mounted combat merely because the Skiff exists;
- authored route hazards may require steering/braking/momentum/timing;
- route pressure may include avoiding enemies or environmental danger where readable;
- encounters intended to use ordinary combat should provide a safe park/dismount transition or another explicit authored state.

The game must not grow a second vehicle-combat balance problem merely to justify the Skiff.

---

# 10. Collision / failure / recovery

## Minor contact

Minor collision/contact should normally:

- shed some momentum;
- give clear audiovisual/haptic feedback;
- preserve control;
- avoid arbitrary total failure.

This aligns with Trial 05 authority: collisions do not automatically fail the mastery trial.

## Major obstruction

A major authored obstruction or invalid route state produces controlled braking/blocked-safe-stop behavior where possible.

The player should understand whether the problem is:

- insufficient route state;
- story/world blockage;
- missing tool interaction;
- wrong route choice;
- temporary changed-world condition;
- actual driving error.

## No debris pinball

Ordinary small props/debris must not routinely:

- launch the Skiff;
- flip it;
- ragdoll Neris;
- force long reloads;
- create physics chaos disproportionate to their visual importance.

## Recovery cost

Failure should primarily cost:

- momentum;
- a missed branch;
- route position;
- a short recovery;
- opportunity within an authored challenge window.

It should not normally cost a multi-minute replay through already-solved travel.

---

# 11. Camera state

The Skiff receives a dedicated traversal camera state subordinate to locked camera principles in `docs/22_GATE1_CAMERA_SPECIFICATION.md`.

## Composition

The Skiff camera remains:

- medium-wide / world-first;
- route-readable;
- able to show upcoming junctions/obstacles with enough anticipation;
- visually stable rather than continuously zoom-pumping with speed.

A modest distance/forward-look adjustment may be appropriate relative to ordinary on-foot framing, but exact FOV, boom distance, offsets, interpolation, and speed scaling remain prototype tuning.

## Manual authority

Manual yaw/pitch input remains authoritative.

- player camera input immediately suppresses/cancels ordinary Skiff yaw-follow assistance;
- the player may look sideways/backward while traveling;
- camera assistance never chooses a route branch;
- camera orientation never changes traversal eligibility.

## Soft follow

Sustained high-speed Skiff travel may use stronger conditional soft travel-direction follow than careful on-foot movement because route anticipation matters more at speed.

It still cannot hard snap or visibly fight manual camera intent.

## Recenter

Manual recenter remains an explicit recovery command.

While coupled to a valid route, recenter targets the stable current route-travel direction rather than an arbitrary vehicle mesh facing artifact.

## Motion comfort

Accessibility/presentation must support:

- reduced camera shake;
- reduced speed-line/intensity effects where used;
- stable horizon;
- readable junction lookahead;
- no essential route cue communicated only through camera shake.

---

# 12. Route readability

## Physical language

Compatible reinforcement strips need persistent physical/art language even while dormant.

The player should be able to learn what a Skiff route looks like without requiring Roadhand Pulse to paint every route continuously like an objective line.

## State readability

At minimum, the player must be able to distinguish authored states such as:

- compatible/usable;
- dormant but wakeable;
- blocked/invalid;
- transfer-capable;
- parking/service node;
- changed-world/Hush-affected where relevant.

Essential state identity may not be audio-only.

Use redundant combinations of:

- physical strip behavior/material response;
- visual indicators;
- route fixtures/signage;
- Roadhand/Cantor response;
- optional haptics;
- audio;
- map/journal topology where discovered.

## Junction anticipation

Branch information must become readable far enough before commitment to support first-attempt decisions at intended travel speed.

Skill may reward earlier recognition and better momentum, but basic route selection cannot depend on memorizing an unreadable surprise turn.

## Map/journal

Discovered network topology may be represented on the map/journal.

This does not authorize:

- permanent objective-colored racing lines;
- automatic navigation to every destination;
- exact Drift Knot GPS tracking;
- universal unexplored-route revelation.

---

# 13. Accessibility

Accessibility accommodations retain full route/mastery/completion authority.

Supported options must be capable of including, where implementation proves useful:

- remappable throttle/brake/branch/Pulse/Park controls;
- configurable analog dead zones/sensitivity consistent with input authority;
- steering assistance that helps remain centered in the valid corridor without choosing route branches;
- widened junction-intent windows;
- stronger branch/edge contrast;
- reduced relative challenge speed where appropriate;
- reduced camera shake/motion effects;
- visual/haptic equivalents for audio route-state cues;
- simplified hold/toggle behavior for sustained acceleration where compatible with control accessibility.

Assistance may reduce motor burden. It may not silently solve route-choice or semantic tool decisions for the player.

No accessibility accommodation invalidates completion, Trial 05 rewards, Drift Knot resolution, or Switchshoe eligibility.

---

# 14. Persistence / save-load boundary

## Persist durable semantic state

Persist as required by Save/World-State authority:

- Skiff acquired/available fact;
- upgrades such as Switchshoe;
- authoritative route/network state changes;
- current stable parked/recovery node when needed for resume;
- world-route variant where needed;
- relevant story/service unlocks;
- settled hunt/trial/reward facts through their owning systems.

## Do not require frame-perfect travel persistence

Baseline design does not require saving:

- exact spline coordinate;
- exact wheel/guide contact;
- exact lateral centimeter offset;
- exact frame velocity;
- transient collision state.

If saving occurs during active travel, a load may restore to a deterministic safe semantic resume/recovery point rather than replaying an unsafe partially simulated frame.

Any later decision to support exact mid-run resume must prove it does not increase save corruption, collision, world-streaming, or route-variant risk beyond its player value.

## Safety

Save/load must never:

- duplicate the Skiff;
- strand it on an incompatible route;
- place Neris off-network unintentionally;
- bypass a route gate;
- duplicate Trial/Drift Knot rewards;
- erase a legitimate route-state change.

---

# 15. Suggested runtime control state model

These are runtime/control states, not automatically persisted narrative facts:

1. `Unboarded`
2. `Boarding`
3. `ParkedReady`
4. `CoupledTravel`
5. `BranchCommit`
6. `BrakingToPark`
7. `BlockedSafeStop`
8. `Recovering`

Implementation may refine internal substates without changing the player-facing authority above.

Forbidden state design includes relying on dozens of unrelated booleans such as `IsOnRail`, `CanTurn`, `AtFork`, `WantsExit`, `BrokenAhead`, `IsParking`, `WasHit`, etc. with no reconciled state ownership.

---

# 16. Line Skiff / Route Network System IDE

A dedicated workbench is required in the shared in-game development shell.

At minimum expose:

## Semantic graph

- route segment IDs;
- node IDs/types;
- endpoints;
- directionality;
- currently available world-state variant;
- source owner for block/availability facts;
- supported transfers and park/recovery nodes.

## Live control

- Skiff control state;
- current semantic segment/node;
- longitudinal speed;
- throttle/coast/brake request;
- supported speed envelope;
- lateral corridor offset;
- lateral steering request;
- edge scrub/correction state;
- current branch window;
- player branch intent;
- branch-commit result;
- current Park request / target safe node.

## Tool/upgrade

- Roadhand Pulse request;
- candidate infrastructure;
- accepted/rejected result and reason;
- Switchshoe owned/equipped/eligible state;
- candidate transfer relationship;
- transfer success/failure reason.

## Camera/readability

- active camera state;
- travel direction frame;
- follow-assist state;
- recent manual override state;
- junction lookahead/readability volume;
- active motion/accessibility settings.

## World integration

- Stillness/Hush/current route variant;
- changed-world replacement relationships;
- Drift Knot integration state;
- Trial 05 fixture state;
- save/resume node;
- invalid bypass/audit warnings.

## Authoring/debug actions

At minimum:

- visualize semantic graph over world presentation;
- select/teleport to safe node in dev builds;
- force segment world-state variant;
- simulate blocked/dormant/active route;
- exercise every branch from both approach directions;
- exercise pre/post-Switchshoe transfer;
- run Park reachability audit;
- run unreachable-safe-node audit;
- run off-network-bypass detection;
- run camera/junction visibility fixture;
- run save/load resume fixture;
- run accessibility route fixture.

The IDE uses the same authoritative route/traversal/world services as gameplay.

---

# 17. Deterministic Decision #2 fixtures

At minimum future implementation evidence must prove:

1. accelerate/coast/brake remain player-controlled on a valid segment;
2. route macro direction constrains travel while lateral micro-control remains meaningful;
3. normal steering cannot eject the Skiff from the authored network;
4. route-edge pressure causes readable scrub/resistance rather than invisible billiard bounce;
5. minor contact costs momentum without automatic failure;
6. major invalid obstruction produces a controlled safe stop;
7. standard junction branch input selects the authored branch;
8. no-input junction continues a valid mainline where one is declared;
9. junction with no safe default stops rather than choosing randomly;
10. quest marker/objective state cannot auto-select a branch;
11. Park request reaches the next valid safe park node;
12. routes near intended on-foot content have practical dismount access;
13. arbitrary high-speed dismount is unavailable;
14. Roadhand Pulse wakes/identifies compatible infrastructure but does not boost or create routes;
15. before Switchshoe, marked legacy transfer requires stop/re-couple behavior;
16. after Switchshoe, the same supported transfer can occur at speed;
17. Switchshoe cannot transfer to unsupported/off-network geometry;
18. player manual camera input overrides Skiff follow immediately;
19. recenter uses stable route travel direction;
20. reduced-motion mode preserves full route usability;
21. save/load during active travel resolves to a stable semantic resume state;
22. load cannot duplicate or strand the Skiff;
23. owning Skiff never changes baseline on-foot traversal eligibility;
24. Trial 05 remains about momentum/junction reading rather than top-speed-only racing.

---

# 18. Rejection conditions

Reject/revise implementation if:

- the Skiff auto-drives toward objectives;
- player steering/momentum input is mostly cosmetic;
- branch choices are made by quest markers;
- normal steering can free-roam off the network;
- invisible hard-wall bouncing is the primary route constraint;
- arbitrary high-speed dismount becomes a generic traversal exploit;
- Roadhand Pulse becomes a boost;
- Switchshoe becomes primarily a speed-stat upgrade;
- there are too few safe park nodes to access intentionally nearby on-foot content;
- there are so many mandatory stops that travel becomes stop-start menu rail;
- small debris routinely launches/flips the vehicle;
- collision failure forces long repeat travel;
- camera hard-locks behind the Skiff and rejects manual looking;
- camera selects route branches;
- essential branch/state cues are audio-only;
- route semantic identity uses spline/Actor/map path;
- save/load duplicates or strands the vehicle;
- ordinary travel requires stamina/fuel/consumable grind;
- high-speed routes routinely bypass first-time authored content they were supposed to preserve.

---

# Research basis

Decision #2 is informed by design-problem research into high-speed authored traversal and existing Stillring authority, including:

- Insomniac GDC traversal/camera work: faster traversal requires camera and supporting-system behavior to evolve rather than merely increasing velocity;
- Ubisoft Assassin's Creed Mirage postmortem material on authored traversal highways and readability/polish passes;
- Sunset Overdrive GDC material on route/grind-network traversal and the streaming/world-production implications of sustained speed;
- existing Stillring camera authority preserving manual orbit and conditional follow rather than camera theft;
- existing Roadhand Pulse, Switchshoe, Relay Run, and Drift Knot contracts.

These sources inform problems and production constraints only. Stillring does not copy exact route geometry, control values, animations, camera numbers, UI, or traversal expression from another game.

## Approval

**APPROVED / LOCKED under the owner's prior locomotion/traversal delegation and instruction to continue.**

## Final locked statement

> **The Line Skiff uses a stable semantic authored route graph. The network owns legal macro travel while the player owns acceleration, coasting, braking, bounded lateral placement, junction intent, Roadhand Pulse use, momentum, and camera. Standard junctions use readable player branch intent; Switchshoe adds authored at-speed adjacent-strip transfers rather than speed stats. Boarding and intentional dismount occur at compatible safe nodes, with practical access to nearby on-foot content. Roadhand Pulse is infrastructure interaction, not a boost. Collision/failure costs momentum and short recovery rather than long replay. Camera remains world-first and manually controllable. Save/load restores durable semantic route state and a stable resume point rather than requiring unsafe frame-perfect vehicle persistence.**

## Next decision

Issue #10 Decision #3 — **Stillness / Hush / changed-world route-state authority:** exact route-state ownership, which route properties can differ across Waking/Hush/Stillness, how transitions occur while traveling, route repair/reroute semantics, failure/recovery, and how changed-world roads remain completion-safe for Drift Knots and ordinary traversal.

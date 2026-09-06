# 122 — Traversal Transformation Decision #3 — Stillness / Hush / Changed-World Route-State Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #10 — Design Stillring traversal transformation and mastery loop  
**Parents:** `docs/120_TRAVERSAL_TRANSFORMATION_DECISION_1_LINE_SKIFF_SELECTION.md`, `docs/121_TRAVERSAL_TRANSFORMATION_DECISION_2_ROUTE_NETWORK_GRAMMAR.md`  
**Cross-authority:** Gate 4 Hush authority `docs/70`–`docs/79`; Save/World-State authority `docs/82`–`docs/88`; Drift Knot authority `docs/100`; Completion reconciliation `docs/104`  
**Decision:** #3 — route-state ownership, Waking/Hush expression, Stillness/world-pulse changes, in-flight transition continuity, repair/reroute semantics, changed-world variants, save/reload, completion safety, and System IDE requirements

## Locked principle

> **A road may look, behave, or connect differently across Stillness and Hush, but its truth is never inferred from loaded geometry. World systems own durable route facts; the Line Skiff network derives legal traversal from those facts and the currently authoritative world layer.**

A second principle governs transitions while riding:

> **The Skiff is a transform-owning traversal state. A Waking↔Hush shift while riding is legal only where the current route explicitly declares a deterministic paired continuation. No route contract, no shift.**

Stillness and Hush are not interchangeable concepts:

- **Stillness / changed-world state** is durable story/world history affecting infrastructure and local physical conditions;
- **Waking / Hush** is the currently active semantic expression of one authored place;
- the Line Skiff route service consumes both authorities but owns neither global story history nor the Hush layer itself.

---

# 1. Authority separation

## Story / World State owns durable changed-world facts

Examples include:

- Grand Ring / Stillness has occurred;
- a bridge/road section was damaged;
- a reinforcement strip was repaired;
- a local route was permanently disconnected/reconnected;
- a community opened a replacement corridor;
- an infrastructure project changed route availability;
- a road segment's physical support is destroyed/preserved;
- a route correction from a Drift Knot has settled.

The Line Skiff system does not shadow-copy these facts as generic `RouteBroken=true` booleans when the source system already owns the semantic cause.

## Hush / World-Layer service owns active semantic layer

The authoritative layer is exactly one of:

- `Waking`
- `Hush`

Runtime Data Layers, streaming state, Actor activation, visibility, and collision representation are downstream implementation details.

The Skiff network reads the current semantic layer and the Hush identity/physical-authority contracts. It never decides the active layer itself.

## Line Skiff Route Network owns traversal derivation

The route service owns:

- semantic route graph definitions;
- route-expression definitions per supported layer/world variant;
- derived route eligibility;
- current coupled segment/node;
- branch/park/transfer traversal state;
- deterministic mapping between compatible paired route expressions;
- safe-stop/recovery behavior;
- route-specific traversal continuity contracts.

It does not become owner of Story, Hush, NPC, Quest, Drift Knot resolution, or source infrastructure history.

---

# 2. Route identity versus route expression

## Stable route identity survives expression changes

A route semantic ID such as:

`skiff.route.circuit.graymile_outer`

may have different authored physical expressions across:

- pre-Grand-Ring Waking;
- post-Grand-Ring Waking;
- Hush;
- post-repair Waking;
- late Unringing state.

Those expressions do not automatically become separate persistent route IDs merely because geometry, collision, dressing, or usable path shape changes.

## When one route ID is appropriate

Keep one semantic route ID when the expressions remain the same meaningful route relationship, for example:

- the same road corridor is cracked after Stillness;
- one side of the strip is phase-locked but the route still connects the same semantic endpoints;
- a repaired version follows a slightly shifted physical line while retaining the same civic/route identity;
- Waking and Hush are paired expressions of the same authored road.

## When a new route ID is required

Create a distinct semantic route segment when the later path is genuinely a different route relationship, for example:

- a new community bypass is built with different endpoints;
- an old road is permanently abandoned and a new service corridor replaces it;
- a Hush-exclusive path is related to but not the same historical road;
- two paths coexist and can be chosen independently.

Do not collapse meaningfully distinct routes into one ID merely to reduce data count.

---

# 3. Route expression classes across Waking/Hush

Route expressions adopt the same semantic discipline as Gate 4 paired entities.

A segment may declare one of these relationship classes where Hush matters:

## Shared Invariant

The route is intentionally identical enough across Waking/Hush that one shared physical/traversal expression remains authoritative.

Use sparingly and only where collision/route behavior truly is intentionally invariant.

## Paired Expression

The same semantic route has an authored Waking expression and Hush expression.

Each expression may differ in:

- geometry presentation;
- corridor width;
- obstacles;
- local route interactions;
- reinforcement-strip visibility;
- supported speed envelope;
- park-node presentation;
- environmental hazards.

But a layer shift while riding is allowed only if the current location has an explicit safe paired-continuation mapping.

## Layer Exclusive

The route segment is usable/present only in one semantic layer.

If no paired destination route exists, shifting layers while coupled to it is rejected.

Layer-exclusive does not mean the source history is duplicated; the route's existence/meaning still follows semantic authority.

## Related Distinct

A Waking route and a Hush route may be narratively/physically related but are not the same semantic segment.

They receive distinct route IDs and an explicit relationship rather than pretending they are one paired path.

This is appropriate when endpoints, function, or historical identity materially differ.

---

# 4. Derived route eligibility

A segment's current traversal status is derived from authoritative facts and active expression.

The route service should be able to answer at minimum:

- **Usable** — currently legal for normal coupled travel;
- **DormantWakeable** — compatible infrastructure exists and Roadhand Pulse may legally wake it;
- **Blocked** — currently illegal because an authoritative world condition prevents travel;
- **RequiresAuthoredInteraction** — route may become usable only after a named tool/repair/story interaction;
- **LayerUnsupported** — current semantic layer has no legal expression;
- **TransitionUnsupportedHere** — route is usable, but current position/segment has no paired seam-continuation contract;
- **RepresentationNotReady** — gameplay says a route is legal, but approved engine representation is not yet ready to commit/use it;
- **InvalidDefinition/AuditFailure** — authoring/runtime mismatch makes legality unsafe to infer.

These are explanatory outcomes, not a requirement to serialize one giant route-state enum as canonical truth.

The IDE must show the source facts and reason chain producing the result.

---

# 5. Roadhand Pulse versus changed-world authority

Roadhand Pulse can only interact with route states that explicitly allow it.

It may wake or identify **compatible dormant infrastructure**.

It cannot override:

- a destroyed structural support;
- a story-locked route;
- a route requiring Anchor/Glasslung/Temper/Vane/Mirror/seam work;
- a Hush-incompatible segment;
- a community/world-state decision that intentionally removed connectivity;
- a segment whose destination expression is physically unsafe;
- a missing semantic route definition.

The rule is:

> **Roadhand Pulse can wake a valid road. It cannot make an invalid road true.**

A failed Pulse request reports why the route cannot wake rather than producing a generic `nothing happened` response.

---

# 6. Waking↔Hush seam request while riding

Gate 4 Hush transition authority remains primary.

The Line Skiff declares itself a traversal state that owns player/vehicle transform while coupled.

## Default

A seam request while actively coupled is **not automatically legal**.

The route service returns a compatibility result to the Hush transition service.

## Legal in-flight shift requirements

A riding seam request may commit only when all of the following are true:

1. the Hush service says the area allows player shifting;
2. the current Skiff traversal state is transition-compatible;
3. the current semantic route has a valid destination expression or explicit related-route handoff;
4. the current travel location lies inside an authored paired-continuation envelope;
5. destination corridor occupancy can be established deterministically;
6. current branch/transfer/park interaction is in a state that can continue without contradiction;
7. destination representation can become physically authoritative within the approved transition contract;
8. no source-owned world fact makes the destination route illegal.

If any requirement fails, the seam rejects before semantic commit.

Representative rejection reason:

`Rejected_SkiffRouteNoDestinationContract`

Other specific reasons should identify occupancy, route blockage, active transfer, invalid destination state, or representation readiness as appropriate.

## Skiff and Neris transition together

A valid seam shift never changes Neris into Hush while leaving the currently controlled Skiff as a Waking-only gameplay object, or vice versa.

The traversal ownership contract covers the player + currently controlled Skiff relationship atomically.

Presentation may use paired Actors/components internally, but semantic continuity is one Skiff traversal state.

---

# 7. In-flight paired continuation

For a legal paired route shift, the destination contract declares how current traversal maps across the commit.

## Preserve semantic progress

Where possible preserve:

- route semantic position/progress relationship;
- travel direction;
- player throttle/brake intent;
- existing longitudinal momentum;
- normalized lateral corridor position;
- current camera ownership/manual input;
- current Drift Knot/hunt relationship if that hunt explicitly supports the layer shift.

## Do not replay acceleration

The seam does not provide:

- a speed boost;
- a momentum reset exploit;
- free braking;
- free collision immunity;
- a fresh acceleration impulse;
- an automatic branch change.

## Corridor mismatch

If the destination paired corridor is narrower/differently shaped, occupancy may use the Hush authority's smallest deterministic correction inside a narrowly authored safe envelope.

Prefer mapping a normalized lateral position into the destination corridor rather than preserving an impossible absolute offset.

If a safe mapping cannot be guaranteed, reject before commit.

## Junction/transfer states

A seam shift during `BranchCommit`, Switchshoe transfer, boarding, parking commit, or another short transform-critical substate is legal only if that exact substate declares a deterministic destination continuation.

Otherwise reject until ordinary coupled travel or another compatible state resumes.

No seam request may auto-complete a junction or Switchshoe transfer.

---

# 8. Layer transition does not reset route history

Waking↔Hush shift does not reset:

- route repairs;
- community route decisions;
- Skiff ownership;
- Switchshoe ownership;
- Roadhand-discovered route facts where those discoveries are persistent;
- Drift Knot resolution;
- Trial completion;
- current source-owned story/world facts.

Returning to a layer reconstructs the expression from the same semantic history.

A Hush route is not a disposable second save state.

---

# 9. Stillness / world-pulse route changes

Stillness and later world-pulse events may change route infrastructure while Neris is elsewhere.

The route graph must therefore be able to derive changed-world variants without assuming the player witnessed the change.

Examples:

- a route becomes phase-locked;
- a strip remains locally wakeable while central routing fails;
- a bridge support breaks;
- an alternate service strip becomes usable;
- a community repairs a junction;
- an Unringing project opens a replacement connector;
- a previously safe corridor gains an authored moving-window condition.

The source world/story fact commits under its owning system. Route eligibility then recomputes from that fact.

---

# 10. Occupied-segment stability rule

A nontrivial world-state event must never silently invalidate the physical route underneath an actively traveling Skiff with no continuity contract.

## Deferrable route mutation

If the source event can legitimately wait until the vehicle clears an affected segment, it may defer its route-affecting commit to a declared safe boundary.

The source system—not the Skiff—must own that deferral rule.

## Non-deferrable world event

If a story/world event must commit immediately while the player could be on an affected route, that event must provide an explicit **Occupied-Segment Continuity Contract**.

It must define a deterministic safe result such as:

- current route remains physically valid long enough for a controlled stop at a specific semantic emergency node because that is part of the authored event;
- the route transitions to an explicitly authored changed-world expression that preserves occupancy;
- a scripted but gameplay-consistent emergency handoff moves the Skiff through a defined route transition without arbitrary nearby teleport search.

The event may not simply deactivate collision/geometry under the Skiff and hope physics resolves it.

## No story block by parked exploit

Critical non-deferrable story progression must not become permanently blockable because the player parked a Skiff on a route segment.

If such a story event exists, its occupied-segment contract is mandatory before content sign-off.

---

# 11. Route repair semantics

A route repair is a source-owned semantic world fact, not merely restored spline collision.

Examples:

- `world.route.graymile_outer.support_repaired = true`
- equivalent stable semantic fact under the owning infrastructure/world service.

The exact schema remains Save/World-State implementation authority.

## Repair settlement

A route-changing repair should commit atomically enough that downstream route derivation can answer one coherent result.

Do not allow a persisted half-state where:

- visual bridge is repaired;
- route graph says blocked;
- Skiff collision says usable;
- Drift Knot thinks old variant is active.

If a multi-step physical repair takes time, only the reviewed semantic milestones may affect route eligibility.

## Roadhand Pulse is not repair

Pulse may activate compatible intact infrastructure after its prerequisites are satisfied.

It does not replace a real structural/mechanical repair fact.

## Tool integration

Anchor, Glasslung, Temper, Vane, Mirror, seam mode, or another tool may change a route only through its own authoritative interaction contract.

The route service consumes the resulting semantic fact.

---

# 12. Reroutes and replacement connectivity

Changed-world progression may replace an old path with another.

## Same semantic route, new expression

Use a route variant when the meaningful connection remains the same road relationship despite physical reconfiguration.

## New semantic route

Use a new route ID when the community/story creates a genuinely distinct connector.

The graph may then record relations such as:

- replaces;
- supplements;
- bypasses;
- requires;
- reconnects.

Do not mutate history to pretend the new bypass was always the old road.

## Player-facing discovery

A replacement route may become known through:

- natural travel;
- Tessa/courier information;
- local route signs/work;
- Roadhand Pulse where compatible;
- world-state storytelling.

No universal automatic map reveal is implied.

---

# 13. Drift Knot completion safety

The 12 Drift Knots retain stable `hunt.*` identities under `docs/100`.

A changed-world road may not brick a Knot.

For every Knot, authored route integration must declare:

- eligible route segment(s)/variant(s);
- what happens if an original corridor is changed/closed/rebuilt;
- changed-world replacement route where needed;
- Hush support class where relevant;
- reacquisition path;
- safe resolution window;
- source route state prerequisites.

Rules:

- road destruction does not auto-complete the Knot;
- road destruction does not silently delete the Knot;
- a replacement route preserves the same semantic Knot ID and its core tool/reference test;
- changing layer does not reset a resolved Knot;
- a hunt that permits seam shifting must explicitly author route/layer continuity;
- a hunt that does not support seam shifting rejects the shift while the relevant traversal state owns continuity.

Completion remains derived from the settled route-correction fact, not current route geometry.

---

# 14. Ordinary traversal completion safety

Changed-world routes must also preserve main-story and completion access.

A later route change cannot silently make required regions or completion-bearing content unreachable unless another authored route/access method replaces it.

Route validation must cross-check:

- main-story destinations;
- required repair contracts;
- required Setup/Payoff resolutions;
- Drift Knots;
- refuges/services where road access is expected;
- community projects;
- mastery trial access;
- late cleanup routes.

This does not mean every destination always has Skiff access.

It means changes to the Skiff network cannot accidentally remove the intended **overall game access path**.

On-foot routes and other traversal verbs remain legitimate replacements.

---

# 15. Save / reload

Save/World-State and Hush authority remain primary.

## Save snapshot

A durable snapshot may include through owning systems:

- active semantic Waking/Hush layer;
- source-owned durable route/world facts;
- Skiff ownership/upgrades;
- current stable Skiff park/recovery node;
- discovered/settled route facts where legitimately persistent;
- Drift Knot/Trial/reward facts.

Do not persist Data Layer activation or Actor visibility as route truth.

## Save during seam transition

Hush authority already forbids saving a half-transition.

If save is requested during Waking↔Hush route transition, save waits for a save-stable semantic layer/Skiff state or uses the established deferral rule.

## Reload ordering

Conceptually:

1. validate/migrate save schema;
2. restore durable world/story facts;
3. restore active semantic layer;
4. restore Skiff ownership/upgrades;
5. derive semantic route graph and active expressions;
6. prepare required representation;
7. restore/resolve the stable Skiff park/recovery node;
8. validate route/node legality under current world/layer facts;
9. establish physical authority;
10. reconstruct transient camera/control state;
11. validate convergence before releasing control.

## Invalid saved node after migration/world evolution

If a saved stable node is no longer valid due to a legitimate schema migration or authored world-state change, the route definition must provide a deterministic migration/recovery mapping.

Do not search for the nearest arbitrary Actor/node at runtime.

The mismatch is visible in the System IDE/audit trail.

---

# 16. Engine representation boundary

Current Gate 4 prototype direction uses World Partition + Runtime Data Layers, but this remains representation under semantic services.

Epic UE5.8 documentation confirms Runtime Data Layers can load/unload/activate gameplay/environment Actor sets and are useful for complex transitions, but they remain engine mechanisms rather than Stillring save/semantic identity.

Therefore:

- Data Layer activation may prepare/present a Waking/Hush route expression;
- route eligibility does not become true merely because its Data Layer is Active;
- a route does not become false merely because an inactive expression is unloaded;
- semantic commit does not come from a Data Layer callback;
- route IDs do not equal Data Layer names;
- streaming performance/readiness is measured separately from gameplay legality.

World Partition streaming must be validated at Skiff speed. A route design that outruns required world/route representation is a production failure, not permission to slow the player artificially with hidden wait gates unless such gating is authored and visible.

---

# 17. Accessibility / presentation

Changed-world and Hush route distinctions must remain readable under accessibility settings.

Required principles:

- route availability is not color-only;
- Hush route identity remains readable with reduced Hush effects;
- route/layer transition does not require flashes/strobes;
- a rejected seam while riding receives a restrained multimodal reason cue;
- reduced camera effects do not alter route legality;
- navigation/route-state audio receives visual/haptic alternatives where essential;
- accessibility may widen safe seam/route readability timing where motor burden is involved without inventing route eligibility.

---

# 18. System IDE additions

The Line Skiff / Route Network workbench from Decision #2 must integrate directly with Hush / World-Layer and Save/World-State workbenches.

## Route expression inspection

Expose:

- route semantic ID;
- current active semantic layer;
- current world/story phase relevant to route;
- expression relationship class: Shared Invariant / Paired / Layer Exclusive / Related Distinct;
- current expression/variant ID;
- source facts driving availability;
- derived eligibility result/reason;
- representation readiness separately;
- paired route mapping if any;
- safe seam-continuation envelopes.

## In-flight seam inspection

Expose:

- current Skiff traversal state;
- seam eligibility response;
- rejection reason;
- source/destination route expression;
- semantic progress mapping;
- lateral mapping;
- velocity before/after;
- occupancy validation;
- semantic commit frame/time;
- representation convergence.

## Changed-world graph inspection

Expose:

- pre/post world-state route graph diff;
- source owner/event causing each change;
- replacement/supplement/bypass relations;
- occupied-segment continuity contract;
- safe recovery nodes;
- impacted Drift Knots;
- impacted story/completion access;
- route migration rules.

## Authoring validators

At minimum:

- paired expression missing destination mapping;
- seam-permitted segment with no occupancy-safe envelope;
- Layer Exclusive segment incorrectly marked shift-compatible;
- route state depending directly on Data Layer/Actor visibility;
- Roadhand Pulse bypassing a non-wakeable block;
- non-deferrable world event affecting an occupied route without continuity contract;
- route repair visual/semantic mismatch;
- changed-world route graph orphaning a required destination;
- Drift Knot lacking a valid changed-world route variant;
- saved node without migration/recovery mapping;
- duplicate semantic route IDs;
- related-distinct paths incorrectly sharing one route ID.

---

# 19. Deterministic Decision #3 fixtures

Future implementation evidence must prove at minimum:

1. Waking/Hush route truth comes from semantic services, not Data Layer activation;
2. Shared Invariant route remains lawful through layer shift where authored;
3. Paired Expression route maps current travel safely across a legal seam;
4. Layer Exclusive route rejects seam while coupled with explicit reason;
5. Related Distinct route cannot masquerade as automatic paired continuation;
6. valid in-flight seam preserves route progress/direction and legitimate momentum;
7. seam does not grant speed, braking, invulnerability, or branch reset;
8. destination corridor mismatch uses only bounded deterministic correction or rejects pre-commit;
9. seam during unsupported BranchCommit/Switchshoe transfer rejects cleanly;
10. Neris and the controlled Skiff cannot end in different active semantic layers;
11. Roadhand Pulse wakes a dormant compatible segment;
12. Roadhand Pulse cannot wake a destroyed/story-blocked/tool-gated segment;
13. changed-world source fact recomputes route eligibility deterministically;
14. deferrable occupied-route mutation settles only at its declared safe boundary;
15. non-deferrable occupied-route event uses its explicit continuity contract;
16. route repair becomes usable only after authoritative semantic repair settlement;
17. same-route changed expression keeps semantic route ID;
18. genuinely new bypass uses a new semantic route ID and explicit relation;
19. every affected Drift Knot remains available on a valid authored route variant;
20. changed road does not silently auto-complete a Knot;
21. layer shifting does not reset resolved Knot/Trial/reward facts;
22. save during seam defers until save-stable state;
23. reload restores semantic layer/world facts before deriving route representation;
24. invalid saved node uses deterministic authored recovery/migration mapping;
25. reduced Hush effects preserves route-state readability;
26. Skiff-speed streaming/readiness is measurable separately from semantic route legality.

---

# 20. Rejection conditions

Reject/revise implementation if:

- route legality is inferred from loaded/visible Actors or Data Layer state;
- Waking and Hush maintain duplicate persistent route histories for the same fact;
- seam while riding is generically allowed everywhere;
- seam creates a destination road that was never authored;
- Neris changes layer while the controlled Skiff remains semantically in the source layer;
- seam resets speed/branch/failure state for player advantage without an owning rule;
- an invalid destination causes arbitrary nearby teleport search;
- Roadhand Pulse overrides structural/story/tool-gated route truth;
- a global world event removes route collision under a traveling Skiff without a continuity contract;
- parking a Skiff can permanently block critical story world-state transitions;
- a route repair is considered complete because visual geometry appeared while authoritative facts disagree;
- a later bypass rewrites history by impersonating the original route ID despite being genuinely distinct;
- a changed-world road permanently bricks a Drift Knot or required game access;
- a changed-world road auto-completes a Knot merely because its original presentation vanished;
- save records Data Layer/Actor visibility as semantic route truth;
- load uses nearest-arbitrary-node recovery;
- accessibility/reduced effects make Hush/route-state distinctions unreadable;
- high-speed travel outruns required world representation and the solution is an unexplained invisible throttle.

---

# Research basis

Decision #3 reconciles existing Stillring Hush, Save/World-State, Drift Knot, and route-network authority with current UE5.8 representation guidance.

Relevant external design/engine reference:

- Epic Games UE5.8 World Partition Data Layers documentation: Runtime Data Layers can organize and dynamically activate gameplay/environment Actors, and excessive use can affect streaming performance. Stillring therefore treats Data Layers as replaceable runtime representation beneath semantic route/Hush services rather than persistence truth.
- Epic Games UE5.8 World Partition documentation: high-speed traversal must be evaluated against streaming-source/cell readiness rather than assuming ordinary walking-speed streaming behavior is sufficient.

External material informs representation constraints only. Stillring's semantic layer, route identities, transition contracts, Skiff behavior, world-state rules, and content remain original project authority.

## Approval

**APPROVED / LOCKED under the owner's prior locomotion/traversal delegation and current instruction to continue.**

## Final locked statement

> **Stillness/world history, Hush semantic layer, and Line Skiff traversal are separate authorities. Durable route changes belong to their source world systems; the route network derives current legal traversal from those facts and the active semantic layer. A Waking↔Hush shift while riding is legal only where an explicit paired route-continuation contract guarantees destination occupancy and traversal continuity; otherwise it rejects before commit. Roadhand Pulse may wake compatible dormant infrastructure but cannot override destroyed, story-blocked, tool-gated, or layer-invalid roads. Changed-world routes preserve stable semantic identity where the relationship remains the same, use new IDs for genuinely new connectors, and may never strand required content or Drift Knots. Engine Data Layers/streaming express these truths but never define them.**

## Next decision

Issue #10 Decision #4 — **mastery/acquisition loop:** exact first-use tutorial, Roadhand Pulse teaching, momentum/junction mastery progression, Trial 05 Relay Run, Switchshoe reward/acquisition, failure/retry, accessibility, player-facing skill growth, and the rule preventing mastery from degenerating into time-trial grind.

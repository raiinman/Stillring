# 62 — Gate 3 Anchor Line Base Physical Verb / Compatible-Target Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115 — Gate 3 Cantor Key and field-tool prototype system  
**Decision:** #3 — Anchor Line base physical verb and compatible-target contract

## Decision

The Anchor Line's base physical verb is:

> **Establish one authored load path, take up slack, and apply/hold/release tension along that path.**

Traversal, combat pressure, puzzle manipulation, and bracing must all emerge from this same physical relationship rather than from unrelated contextual actions hidden behind one tool button.

Core philosophy:

> **The line does not know the puzzle. It only knows load.**

## Base load-path model

A live Anchor Line relationship has two semantic endpoints:
- a **source endpoint** owned by Neris/the launcher or by one already-set static brace endpoint;
- a **target load point** explicitly authored to accept Anchor load.

The line applies force only along the resolved load path between those endpoints.

The target's authored mobility/constraint contract determines the consequence of tension. The tool does not choose an arbitrary canned animation because an object happens to be interactive.

## One base verb, several legitimate responses

A compatible load point declares one of a small semantic response families.

### 1. Movable load
The target may translate toward the source while tension is applied, subject to its authored mass/track/collision limits.

Examples later may include:
- a service crate;
- a ferry mechanism;
- a hanging counterweight;
- a movable cover/component.

### 2. Fixed traversal anchor
The world endpoint is effectively immovable under Anchor load. If a later approved traversal action commits to that relationship, Neris may move toward the anchor instead.

Decision #3 establishes only the physical asymmetry. Exact traversal eligibility, motion envelope, launch behavior, air control, and camera handling remain Decision #5.

### 3. Constrained mechanism load
The target moves only along its authored allowed degree of freedom: track, hinge, slider, suspension arc, tension band, or other explicit mechanism constraint.

The Anchor Line supplies load; the mechanism owns what motion is physically permitted.

### 4. Detachable / releasable component
A component may resist load until its explicit release/detachment condition is met.

The target owns:
- whether it is detachable;
- allowable pull direction/cone;
- load threshold or semantic release condition;
- combat/state legality;
- post-detachment result.

The Anchor Line does not magically classify armor, weak points, puzzle pieces, or quest objects from appearance alone.

### 5. Static brace relationship
A compatible structure/load may be held under tension against one valid authored brace/cleat relationship.

Base Anchor Line supports **one committed static brace relationship at a time**.

This is consistent with the later canonical Split Cleat mastery upgrade, which expands the possibility space to two simultaneous static brace points rather than merely increasing a number with no semantic meaning.

Exact player input for setting/reclaiming a brace belongs to Decision #4.

## Compatibility is explicit gameplay data

A target is Anchor-compatible only because authoritative gameplay data says it can participate in an Anchor load relationship.

Compatibility must not be inferred solely from:
- mesh shape;
- physics simulation enabled/disabled;
- collision channel;
- material name;
- Actor class family;
- quest relevance;
- proximity;
- an artist-placed generic interactable flag with no load semantics.

A compatible target must expose stable semantic data sufficient to explain:
- target/load-point ID;
- response family;
- allowed source/target relationship;
- allowed pull direction or angular cone if restricted;
- current load state;
- mobility/constraint state;
- whether a valid static brace endpoint exists when relevant;
- current rejection reason;
- gameplay-state restrictions;
- reset identity.

Gameplay Tags/interfaces/data assets may represent these semantics in implementation, but no specific Unreal representation is locked here.

## Straight, honest load path

Base Anchor Line does **not** simulate arbitrary rope wrapping around world geometry.

The authoritative load path is a direct relationship between the active endpoints unless an explicitly authored redirection/pulley node later says otherwise.

Hard blocking geometry crossing that direct load path invalidates or interrupts effective tension according to later input/recovery rules.

This avoids:
- invisible force passing through walls;
- dynamic rope-wrap edge cases deciding puzzle outcomes;
- chaotic snagging becoming mandatory traversal behavior;
- presentation cable shape becoming gameplay authority.

A rendered cable may sag or animate for readability, but its visual spline is not the authoritative physics rule.

## Tension, not generic telekinesis

The Anchor Line may:
- shorten effective distance / take up slack;
- maintain a loaded relationship;
- transfer bounded force along the line;
- hold one approved static brace;
- release/reclaim the relationship.

It may not by default:
- push objects away;
- freely rotate objects in 3D;
- levitate objects;
- attach arbitrary objects together;
- create arbitrary construction joints;
- pull through solid geometry;
- move an object sideways without an authored constraint/geometry causing that motion;
- suspend unlimited mass because it is tagged compatible;
- convert every fixed surface into a traversal anchor.

## Deterministic force boundary

Stillring should not make the Anchor Line's basic reliability depend on uncontrolled Chaos outcomes.

Authoritative gameplay state determines whether a target is:
- within working load envelope;
- resisting but valid;
- constrained at a limit;
- overload/ineligible;
- releasable/detachable;
- successfully moved/released/braced.

Physics simulation may realize motion where appropriate, but gameplay results must remain explainable and reproducible.

### Valid-load rule
A valid ordinary Anchor relationship should not randomly snap the cable because solver noise spikes for one frame.

If a design needs overload failure, target breakage, or forced release, that must be an explicit authored state with readable thresholds/conditions and deterministic capture evidence.

## Directionality and reaction force

The same tension law applies regardless of which endpoint is allowed to move.

- Movable target + stable Neris footing: target tends toward source.
- Fixed anchor + approved traversal ownership: Neris may tend toward target.
- Constrained mechanism: mechanism moves only along allowed degree(s) of freedom.
- Detachable component: tension accumulates only toward its legal release condition.
- Static brace: neither endpoint performs active travel after the brace is committed; the relationship holds load within authored limits.

This prevents the tool from secretly switching to bespoke animation logic for each use category.

## World-honesty rule

Mass, leverage, geometry, and visible attachment should matter semantically.

The player should be able to form useful expectations from the world:
- a tiny loose service panel may move;
- a rooted stone pier probably will not;
- a marked maintenance eye can accept a line;
- a structure under visible tension can plausibly be braced/released;
- a removable enemy component needs an actual attachment/load relationship.

The UI may clarify compatibility but must not replace world readability with glowing arbitrary sockets everywhere.

## Interaction with locked camera/combat authority

Decision #3 does not grant any automatic camera control, combat target change, or Neris locomotion override.

The physical contract must respect:
- player-owned camera;
- target-lock identity remaining separate from Anchor target identity;
- Gate 2 action commitment/rejection semantics;
- encounter readability and attack bandwidth;
- camera collision/occlusion authority;
- death/reset cleanup.

Later Decisions #4–#6 decide when a physical Anchor relationship may be entered from specific player states.

## Accessibility / readability constraints

Compatible load points eventually require:
- non-color-only readability;
- clear attached / slack / loaded / constrained / invalid / brace-set states;
- audible/text-equivalent cues for important state changes;
- no requirement to infer exact numerical force;
- no precision mouse-only placement;
- optional/reducible haptics;
- stable indication when a target is physically compatible but currently state-blocked.

Exact reticle/input presentation remains Decision #4.

## Comparative design research

### Horizon Forbidden West — useful contrast
Guerrilla's published description of the Pullcaster explicitly gives it separate grapple and winch functions. That demonstrates a production-proven value: one physical tool can support both movement and environmental manipulation.

Stillring deliberately does **not** adopt its exact two-mode grammar, grapple launch, traversal chain, vent/chest interactions, controls, or animation.

Instead, Stillring unifies its jobs under one semantic rule: whichever endpoint is permitted to move reacts to tension in the same authored load relationship.

### Tears of the Kingdom — rejected breadth
Nintendo's Ultrahand demonstrates how a broad manipulation verb can create traversal/problem-solving variety. Stillring keeps the reusable-verb lesson but rejects unrestricted move/rotate/attach construction because it would overwhelm authored load reasoning and duplicate a different game's expressive center.

## Unreal Engine 5.8 feasibility boundary

Epic's Physics Constraint system supports:
- constrained endpoint relationships;
- free/limited/locked linear motion;
- soft limits, stiffness and damping;
- breakable constraints;
- linear motors/drive force limits.

Those primitives are technically compatible with a prototype of authored load relationships.

But:
- Chaos constraint parameters are implementation/tuning, not player-facing policy;
- engine break thresholds must not become canonical game balance by default;
- simulated motion must be reconciled back to semantic gameplay state;
- a target's compatible response family remains Stillring gameplay authority.

## Tool / Puzzle System IDE contract created by Decision #3

### Inspect
Expose:
- active line ID;
- source endpoint ID;
- target load-point ID;
- target response family;
- target compatibility data/tags;
- direct load-path clear/blocked state;
- current slack/effective length;
- semantic tension/load band;
- allowed direction/cone;
- constrained degree of freedom / current limit state;
- brace eligibility/current brace ID;
- detachable/release eligibility;
- rejection reason;
- current physics realization values separately from semantic authority.

### Exercise
Fixtures must include:
- movable free load;
- immovable fixed anchor;
- track-constrained mechanism;
- hinge/suspension-constrained mechanism;
- detachable component;
- valid one-point static brace;
- incompatible visually plausible object;
- compatible target behind hard obstruction;
- overload/ineligible target;
- reset with an active line and active brace.

### Validate
Catch:
- target moves outside authored degree of freedom;
- force passes through invalid blocking geometry;
- incompatible target accepts line;
- target compatibility depends on quest-object status;
- cable render/spline position changes gameplay authority;
- stale line/brace survives reset or destroyed endpoint;
- random solver break changes an otherwise valid semantic outcome;
- two static braces active before Split Cleat authority exists.

### Capture
Record:
request → endpoints → compatibility → load-path validation → semantic load state → physical response → constraint/limit/release result → exit/reset.

## IP boundary

No exact grapple points, iconography, reticles, animations, control bindings, traversal launch behavior, object taxonomies, physics values, or puzzle layouts are copied from Horizon, Zelda, or another title.

Stillring's protected expression is a compact repairer's maintenance cable whose reusable language is **authored load and tension** inside Orra's infrastructure.

## Locked statement

> **Anchor Line creates one honest authored load path. The player changes tension; the endpoints' real semantic constraints decide what moves, holds, releases, or refuses.**

## Research basis

Primary/current technical sources:
- Epic Games — Unreal Engine 5.8 Physics Constraint Reference.
- Epic Games — Unreal Engine 5.8 Physics Damping documentation.
- Epic Games — Unreal Engine 5.8 linear drive / constraint APIs.

Comparative shipped-game source:
- Guerrilla / PlayStation Blog — *Horizon Forbidden West* Pullcaster description, used only for the general multi-domain physical-tool problem.
- Nintendo official *Tears of the Kingdom* ability description, used only as a breadth contrast.

Repository authority:
- `docs/story/02_ACT_ONE_WAYBELLS.md`
- `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md`
- `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`
- `docs/60_GATE3_TOOL_SELECTION_ADDENDUM.md`
- `docs/61_GATE3_CANTOR_BASE_LOOP_ADDENDUM.md`
- Gate 1 movement/camera authority
- Gate 2 combat/encounter authority

## Next decision

**Gate 3 Decision #4 — Anchor Line targeting / input / cancel / recovery behavior.**

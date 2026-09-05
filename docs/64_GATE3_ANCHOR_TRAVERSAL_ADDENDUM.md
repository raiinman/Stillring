# 64 — Gate 3 Anchor Line Traversal Use Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115  
**Decision:** #5 — traversal use contract

## Decision

Anchor traversal is a **short, authored pull-to-anchor traversal** to explicit fixed traversal load points. It extends route vocabulary without becoming a universal grapple, swing system, aerial launch chain, or substitute for ordinary movement.

> **The Anchor Line crosses a gap the world prepared for it; it does not erase the world's height.**

## Eligibility

A traversal pull may begin only when all are true:
- the latched target is explicitly `FixedTraversalAnchor` compatible under Decision #3;
- direct load path is clear;
- destination approach/arrival volume is authored safe enough for the move;
- Neris is in an allowed locomotion state;
- no higher-priority combat/traversal/world state owns movement;
- distance/angle fall inside the authored traversal envelope.

Ordinary walls, trees, roofs, cliffs, enemy bodies, and arbitrary Anchor-compatible mechanism points do not become traversal anchors by implication.

## Motion

Committing traversal temporarily gives the Anchor traversal state authoritative control of Neris's translation along the validated load path.

The move is:
- short;
- fast enough to feel useful, not like slow winching;
- bounded by collision and destination validation;
- directed toward the fixed anchor with a controlled arrival profile;
- not a ballistic slingshot;
- not a pendulum/swing;
- not a teleport.

The gameplay capsule/path owns truth. Animation presents that displacement. Root Motion or Motion Warping may align presentation, but may not secretly decide endpoint legality or path clearance. Epic's UE5.8 locomotion stack supports Character Movement, custom movement/state handling, Root Motion, and Motion Warping; these are implementation options, not policy.

## Player control during pull

Once committed:
- player cannot steer the pull sideways into a different route;
- camera remains player-owned subject to existing collision constraints;
- Reclaim/Cancel may abort early only while a safe-abort window exists;
- Jump does not convert the pull into a launch;
- Sprint/evade/attack inputs obey explicit state rejection/buffering rules rather than canceling arbitrarily.

Exact safe-abort window and input buffering remain tuning/implementation detail consistent with locked state authority.

## Arrival

Each traversal anchor declares an authored arrival family:
- **Ground/Ledge Arrival** — deposit into valid standing/mantle/ledge state;
- **Pass-Through Arrival** — pull reaches a clear route continuation without auto-stopping on decorative geometry;
- **Hang Arrival** — only where existing ledge/hang authority recognizes a valid hang surface.

Anchor traversal may hand off to already-approved mantle/ledge behavior. It may not invent a new hidden climb grammar.

If arrival validation becomes invalid after commit, the system uses a deterministic safe fallback: earliest valid stop/ledge/fall state along the path. It never clips Neris through blocking geometry to honor the animation.

## Ground versus air start

### Grounded
Grounded use is the ordinary case and receives the widest authored eligibility.

### Airborne
Airborne activation is allowed only for explicit traversal anchors whose authored envelope says `AirStartAllowed` and only while Neris remains within a bounded correction window. This supports deliberate jump-to-anchor combinations without turning every fall into grapple recovery.

Air start does not:
- reset a failed jump indefinitely;
- grant repeated midair chain pulls by default;
- cancel severe fall consequences after an arbitrary late latch;
- create free vertical gain beyond the authored anchor route.

One traversal pull must resolve before another traversal pull can begin.

## Meaningful height gates

Gate 1 requires meaningful height gates to remain blocked until a real route/tool capability solves them. Anchor Line is one such capability only where the world visibly provides an authored Anchor route.

Production rules:
- do not place traversal anchors so densely that ordinary cliffs become cosmetic;
- no universal ceiling/wall sockets;
- route anchors should read as maintenance/infrastructure/load points, not glowing game-design dots;
- old spaces reopened by Anchor should produce the intended “I remember where that matters” revisit effect;
- absence of an Anchor route remains a legitimate boundary.

## Combat boundary

Traversal pull is not a combat evade.

During hostile encounters:
- it may be used only at authored traversal anchors that remain readable under encounter pressure;
- it does not grant broad invulnerability by default;
- enemy attack resolution continues according to Gate 2 unless a later explicit traversal immunity rule is justified;
- encounter design may use an anchor as repositioning terrain, but must not require camera-blind escape spam.

Decision #6 owns Anchor combat-pressure use against enemy/components; this decision only governs Neris-to-fixed-anchor traversal.

## Camera

No traversal-specific cinematic camera grammar:
- no forced look-at anchor;
- no hidden recenter;
- no FOV kick required;
- no automatic orbit;
- camera follows existing vertical/collision/close-quarters authority;
- composition may use ordinary traversal continuity tuning, not a mini-cutscene.

## Accessibility/readability

- traversal-compatible anchors have non-color-only readiness cues while Anchor is readied;
- valid/invalid arrival is readable before commitment where practical;
- no precision motion gesture;
- candidate forgiveness settings apply without expanding physical eligibility;
- a failed request gives a semantic reason rather than silently firing and retracting;
- motion/camera effects remain reducible under existing accessibility policy.

## Comparative research boundary

Horizon Forbidden West demonstrates that a physical cable tool can support authored grappling as well as manipulation. Stillring keeps only that generic cross-domain lesson. It rejects launch-chain traversal, exact grapple presentation, controls, target language, and animation expression.

The important Stillring distinction is that traversal remains a consequence of Decision #3's load law: **the world endpoint is fixed, so the permitted moving endpoint is Neris.**

## Tool / Puzzle System IDE

### Inspect
Expose:
- traversal-anchor ID;
- air-start permission;
- path start/end;
- clearance result;
- arrival family and resolved arrival state;
- movement ownership;
- progress along path;
- abort eligibility;
- collision/fallback result;
- rejected request reason.

### Exercise
Fixtures:
- short horizontal gap;
- modest vertical gain;
- grounded-to-ledge;
- jump-to-air-start anchor;
- invalid arbitrary wall;
- anchor path blocked after candidate acquisition;
- obstruction introduced mid-pull;
- low ceiling/camera compression;
- combat-pressure reposition anchor;
- repeated-chain attempt that must reject.

### Validate
Catch:
- arbitrary fixed Anchor point becoming traversal-enabled;
- repeated midair chain pull without authority;
- pull through collision;
- arrival inside geometry;
- camera forced toward target;
- animation/root motion deciding legality;
- traversal silently grants invulnerability;
- traversal bypasses an authored height gate lacking an Anchor route.

## Locked statement

> **Anchor traversal is one short authored pull to a fixed maintenance/load point. It expands routes deliberately; it does not turn Orra into a grapple-anywhere playground.**

## Research basis
- Epic Games — Unreal Engine 5.8 Movement Components / Character Movement / Locomotion / Motion Warping documentation.
- Epic Games — Unreal Engine 5.8 comparison of Mover and Character Movement; Mover remains experimental and does not become authority merely because it exists.
- Guerrilla / PlayStation — Horizon Forbidden West Pullcaster as a functional comparison only.
- Locked Gate 1 locomotion/camera authority.
- `docs/62_GATE3_ANCHOR_PHYSICAL_CONTRACT_ADDENDUM.md`
- `docs/63_GATE3_ANCHOR_INPUT_TARGETING_ADDENDUM.md`

## Next decision

**Gate 3 Decision #6 — Anchor Line combat / pressure use contract.**

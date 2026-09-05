# 60 — Gate 3 Tool Selection Addendum

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115 — Gate 3 Cantor Key and field-tool prototype system  
**Decision:** #1 — select the first multi-use field tool for Gate 3

## Decision

Gate 3 will prototype the **Anchor Line** as Stillring's first multi-use field tool alongside the Cantor Key.

This is a selection decision only. It does not yet lock the Anchor Line's full physical verb, targeting/input grammar, traversal behavior, combat use, puzzle use, or combination rules; those remain Decisions #3–#10 in Issue #115.

## Why Anchor Line is the correct first prototype

### 1. It is already the first canonical major field tool
`docs/09_STILLRING_PROGRESSION_BLUEPRINT.md` places the Anchor Line in Rootmere / Root Cathedral before Glasslung Reed, Temper Gauntlet, Vane Cloak, and Mirror Nail. Gate 3 should prove the production interaction architecture with the earliest major reusable tool rather than inventing a prototype around a later capability.

### 2. Canon already demands cross-domain usefulness
Existing project authority already assigns Anchor Line responsibility across:
- traversal / structural access;
- puzzle and machinery tension work;
- combat pressure / component interaction;
- later cross-tool synthesis;
- revisit content and mastery upgrades.

The Gate 3 exit condition requires one tool to prove traversal, combat/pressure, and puzzle value. Anchor Line already carries all three obligations without rewriting canon.

### 3. Its identity is physically legible and bounded
Anchor Line's useful design space is **tension, restraint, bracing, pulling, catching, and controlled load transfer on compatible authored targets**.

That is broad enough to create reusable verbs, but narrow enough to avoid becoming:
- a universal telekinesis system;
- a freeform construction sandbox;
- a generic grapple-anywhere locomotion shortcut;
- a context-key that performs arbitrary authored actions under one button.

The tool should make the player reason about **what is under load, what can accept an anchor, and what changes when tension is applied**.

### 4. It fits Stillring's player-control philosophy
Locked movement/camera authority says the player should not be dragged around by hidden assists or engine defaults. Anchor Line therefore starts from a world-facing manipulation tool, not an auto-traversal device that silently overrides locomotion.

Its later traversal contract may reposition Neris only through explicit authored behavior approved in Decision #5. Until then, tool selection grants no freeform grappling, swinging, magnetic pull-to-point, or traversal teleport.

### 5. It fits Gate 2 combat without replacing combat
Gate 2 establishes readable, commitment-based combat and bounded encounter pressure. Anchor Line can provide a tactical pressure verb around explicit compatible components/objects without becoming another light attack, ranged damage weapon, universal crowd-control beam, or target-lock autopilot.

Exact combat legality remains Decision #6.

## Comparative design research

### Multi-use tool lesson
Modern systemic adventure games demonstrate the value of one verb producing multiple classes of solution. For example, Nintendo describes Ultrahand in *Tears of the Kingdom* as one ability that can move, rotate, and attach objects for traversal and construction. Stillring adopts only the **functional lesson that a reusable verb should cross problem categories**; it must not copy freeform construction, presentation, controls, object taxonomy, or protected expression.

Anchor Line deliberately chooses a narrower authored relationship: tension/load rather than unrestricted object manipulation.

### Engine feasibility boundary
Unreal Engine 5.8 provides Physics Constraint Components capable of constraining physics bodies, plus configurable linear/angular limits and related constraint behavior. Those facilities make authored tension/load prototypes technically feasible.

However:
- Chaos / Physics Constraint behavior is implementation machinery, not Stillring policy;
- compatible-target semantics must be explicit gameplay data;
- deterministic gameplay state and rejection reasons remain authoritative C++ concerns;
- visual cable simulation may not own gameplay truth;
- a Cable Component, if used at all, is presentation and must not become the authoritative tension solver merely because it exists.

## Rejected prototype candidates

### Glasslung Reed
Strong systemic potential, but it enters canon later and is more dependent on pressure-source/intake/discharge semantics that should be tested after the shared tool architecture is proven.

### Temper Gauntlet
Useful cross-domain verb, but thermal state introduces persistence, material-response, damage, and audiovisual-readability complexity earlier than necessary for the first tool architecture proof.

### Vane Cloak
Its strongest identity is traversal/airflow. It is a weaker first proof of one verb spanning traversal + combat pressure + puzzle manipulation without prematurely deciding airborne locomotion details.

### Mirror Nail
Extremely important later, but its state/perception semantics depend heavily on changed-world/Hush-era authority and would pull Gate 4/late-story representation questions forward.

## IP boundary

No Nintendo, Valve, or other shipped game's exact controls, timings, object-selection rules, visuals, construction grammar, physics values, target indicators, sound language, puzzle layouts, or animation behavior are copied.

The adopted design problem is generic: **choose one mechanically coherent tool whose base relationship can produce traversal, combat/pressure, and puzzle consequences.** Stillring's expression is the Anchor Line's authored tension/load relationship inside Orra's repair culture.

## Accessibility and readability requirements inherited by later decisions

The selected tool architecture must eventually support:
- non-color-only compatible/incompatible target feedback;
- remappable inputs;
- readable rejection reasons;
- no requirement for precision motion gestures;
- controllable camera effects/haptics where applicable;
- rapid cancel/recovery;
- stable behavior under camera compression and target-lock states;
- System IDE visualization of candidate targets, compatibility, load/tension state, accepted/rejected requests, and active ownership.

These are constraints on future decisions, not yet final input/timing rules.

## Puzzle / Tool System IDE requirements created by this decision

The Gate 3 workbench must reserve first-class inspection for Anchor Line prototype data:
- current equipped/selected tool;
- candidate compatible targets and rejection reason;
- semantic anchor/load capability tags;
- current line ownership/state;
- source and destination attachment identities when later applicable;
- authoritative tension/load state when later defined;
- active traversal/combat/puzzle fixture ID;
- canonical vs session override vs staged/proposed values;
- deterministic reset and capture hooks.

No debug action may silently grant compatibility or bypass gameplay-state rejection without visibly declaring a development override.

## Representative future fixtures

This selection requires later decisions to prove the same tool in at least:
1. one structural/traversal fixture;
2. one combat-pressure/component fixture;
3. one mechanism/puzzle fixture;
4. one invalid-target fixture proving fast readable rejection;
5. one mixed-state fixture near wall/camera compression;
6. one reset/retry fixture proving no stale line ownership survives reset.

## Locked statement

> **Gate 3's first field tool is the Anchor Line. Its core design territory is authored tension/load relationships—not universal grappling or freeform telekinesis.**

## Research basis

Primary/current technical research:
- Epic Games, Unreal Engine 5.8 Physics Constraint Component User Guide.
- Epic Games, Unreal Engine 5.8 Physics Constraint Reference.
- Epic Games, Unreal Engine 5.8 Cable Component API (presentation option only).

Comparative design reference:
- Nintendo official *The Legend of Zelda: Tears of the Kingdom* ability description for the general lesson of a reusable verb crossing traversal/construction/problem-solving categories. No exact expression is adopted.

Repository authority:
- `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md`
- `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
- `ROADMAP.md`
- Gate 1 movement/camera authority
- Gate 2 combat/encounter authority

## Next decision

**Gate 3 Decision #2 — Cantor Key base interaction / targeting / diagnostic loop.**

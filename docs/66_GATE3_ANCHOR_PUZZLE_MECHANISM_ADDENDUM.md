# 66 — Gate 3 Anchor Line Puzzle / Mechanism Use Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115  
**Decision:** #7 — puzzle / mechanism use contract

## Decision

Anchor puzzles are **world mechanisms whose existing physical state changes under the same load/tension rules used everywhere else**. There is no separate “puzzle Anchor” behavior, no invisible sequence key, and no context prompt that substitutes a bespoke solution animation.

> **A mechanism should be solvable because the player understands its load, not because the game recognized the correct socket.**

## Puzzle grammar

Every Anchor puzzle must expose at least one observable relationship involving:
- what carries load;
- what can move;
- what is constrained;
- where tension can be applied;
- where a brace can hold state;
- what changes when a load is released or redirected.

The Anchor Line contributes only the verbs already locked:
- latch;
- take up slack/apply tension;
- pull a compatible movable load;
- drive a compatible constrained mechanism along its allowed degree of freedom;
- release an authored releasable relationship;
- commit/reclaim one valid static brace.

Puzzle logic may combine those consequences with ordinary world systems, but may not secretly change what Anchor itself does.

## Mechanism state must be authoritative and observable

Mechanisms expose semantic physical states such as:
- open/closed;
- latched/unlatched;
- loaded/unloaded;
- aligned/misaligned;
- counterweighted/unbalanced;
- braced/unbraced;
- within/outside safe travel;
- tensioned/slack.

These states must have world-facing evidence: position, motion, sound, deformation, gauge, visible linkage, local feedback, or other readable consequence.

A hidden Boolean named `PuzzleSolved` may summarize completion internally, but it may not be the only reason an Anchor operation succeeds.

## No arbitrary socket/keycard model

A visually identical Anchor point must not behave differently solely because one instance is “the puzzle solution.”

If two load points differ, the world/data contract must explain the difference through properties such as:
- response family;
- pull direction;
- mobility constraint;
- load capacity;
- connection topology;
- brace eligibility;
- current mechanical state;
- known Cantor relationship.

The solution cannot be encoded as “attach Anchor to Node C because objective says so” with no physical distinction.

## Puzzle state topology

Puzzle authoring should be built from explicit mechanism relationships rather than monolithic scripted sequences.

Representative components:
- constrained movable load;
- latch/release mechanism;
- counterweight pair;
- single brace opportunity;
- route obstruction linked to a load state;
- timed/self-returning load where the physical cause is visible;
- local Cantor-readable relationship when diagnosis is needed.

A mechanism may have a preferred authored solution, but if another state sequence satisfies the same explicit physical invariants without violating canon/production constraints, it should not be rejected merely because the designer expected a different click order.

This is bounded systemic design, not full freeform physics construction.

## One-brace consequence

Base Anchor has one static brace. Puzzle design must treat that as a meaningful resource of attention/state, not a generic inventory charge.

Consequences:
- holding one mechanism may free Neris to manipulate another with ordinary movement/Cantor interactions;
- choosing where to commit the brace can create order-of-operations decisions;
- reclaiming the brace returns the mechanism to whatever its own physics/state says should happen;
- puzzles requiring two simultaneous static braces are invalid before the canonical Split Cleat upgrade.

No puzzle may temporarily grant an invisible second brace because the room needs it.

## Failure and recovery

Puzzle failure should alter mechanism state, not punish with long replay.

Default recovery principles:
- releasing the wrong load produces a readable mechanical consequence;
- unsafe/invalid requests reject before destructive nonsense where Neris could plainly predict that result;
- recoverable objects/mechanisms remain recoverable through the same verbs;
- a named local reset is available for genuine deadlock/debug/test and for player-facing cases where authored machinery can become irrecoverable;
- reset restores mechanism baseline deterministically without replaying an area traversal or encounter unless that is explicitly the challenge.

Puzzle resets may not silently erase unrelated world/quest choices.

## Cantor relationship

Cantor Key and Anchor Line remain distinct:
- Cantor diagnoses relationships/procedures;
- Anchor physically changes load.

A puzzle may require Cantor diagnosis before the player knows what relationship is abnormal or which procedure applies, but Cantor must not simply highlight the Anchor point that solves the room.

Examples of legitimate synthesis setup:
- Cantor reveals that two braces carry conflicting load histories; Anchor lets the player unload one;
- Cantor identifies that a mechanism is stable but referenced incorrectly; Anchor changes its physical state only after the player understands the issue;
- Anchor exposes a hidden-but-physically-present maintenance surface, after which Cantor can diagnose it.

Decision #8 will lock direct synthesis rules.

## Time pressure

Base puzzle understanding should not depend on twitch timing.

Timed mechanisms are allowed only when:
- their return/change cause is visible and physically understandable;
- the timing window is generous enough to plan and execute with remapped/controller input;
- accessibility can relax timing without changing the underlying relationship where appropriate;
- failure resets quickly.

No rapid Anchor-mashing sequences.

## World readability

Anchor puzzle points should look like part of Orra's maintenance/infrastructure language:
- eyes, cleats, braces, tracks, counterweights, service frames, tension members, removable hardware;
- material wear/load deformation and local mechanism behavior support understanding;
- restrained tool-ready cues confirm eligibility when the Anchor is readied.

Do not wallpaper rooms with glowing sockets.

## Comparative research boundary

Portal's enduring puzzle lesson is consistency: new chambers can become complex while the core portal relationship remains stable. Tears of the Kingdom demonstrates the expressive breadth possible when a reusable physical verb interacts with world objects. Stillring adopts only the general lesson that **puzzle complexity should emerge from combinations of stable rules**. It does not copy portal surfaces/layouts, Ultrahand construction, controls, visuals, object taxonomies, or solution expression.

Unreal Engine 5.8 Physics Constraints support data-driven joints with limited motion and forces. That is useful for realization, but a Chaos setup is not sufficient puzzle authority: semantic mechanism state and deterministic reset/validation remain C++/data-owned.

## Tool / Puzzle System IDE

### Inspect
Expose:
- fixture/puzzle ID;
- every mechanism node ID and semantic state;
- load-point compatibility/response family;
- constraint/degree-of-freedom state;
- active line/brace;
- mechanism relationship graph/topology;
- current invariant satisfaction;
- Cantor diagnostic state separately;
- completion condition and why it is/is not satisfied;
- reset baseline and dirty state.

### Author/Tune
Allow reviewed live tuning of:
- movement limits;
- semantic load bands;
- return rates/damping where they do not change the core rule;
- timing windows;
- readable cue thresholds.

All edits carry canonical/session/staged/promoted provenance.

Do not expose a generic `Solve Puzzle` authoring shortcut as the production interaction model.

### Exercise
Fixtures:
- one movable load opening a route;
- counterweight balance;
- one-brace order-of-operations;
- constrained hinge/slider;
- releasable foreign brace;
- wrong-order but recoverable state;
- timed self-return mechanism;
- Cantor diagnosis + Anchor manipulation setup;
- invalid two-brace requirement;
- reset from every intermediate state.

### Validate
Catch:
- solution depending on hidden objective metadata;
- identical semantic targets behaving differently without data explanation;
- second base brace required;
- scripted object motion violating declared constraint;
- Anchor behavior changing only because fixture is a puzzle;
- irrecoverable deadlock without explicit justified reset;
- color-only critical mechanism cue;
- completion flag true while physical invariants are false;
- reset leaking into unrelated world state.

### Capture
Record deterministic mechanism timeline:
player/tool requests → accepted/rejected load relationships → mechanism state transitions → Cantor observations → brace ownership → invariant changes → completion/failure/reset.

## Locked statement

> **Anchor puzzles are machines, not keyholes. The room changes because load changed under rules the player already knows.**

## Research basis
- Epic Games — Unreal Engine 5.8 Physics Constraints / Constraints User Guide.
- Valve — Portal 2 official product description, used only for the generic stable-rule puzzle-combination lesson.
- Nintendo — Tears of the Kingdom official Ultrahand description, used only for the generic reusable-physical-verb lesson.
- `docs/62`–`docs/65` — locked Anchor authority.
- `docs/61_GATE3_CANTOR_BASE_LOOP_ADDENDUM.md`.

## Next decision

**Gate 3 Decision #8 — Cantor Key + Anchor Line combination / synthesis rules.**

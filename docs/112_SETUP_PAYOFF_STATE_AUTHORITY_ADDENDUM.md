# 112 — Setup/Payoff Decision #1 — State Model and Authority

**Status:** FINAL OWNER APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #9 — Design cross-state setup and payoff framework  
**Decision:** #1 — semantic state model, ownership, persistence/recovery, completion safety, authoring contract, and System IDE inspection

## Decision question

How does Stillring represent an early authored action that creates a later changed-world consequence without reducing the relationship to loose quest booleans, duplicating world truth, creating a procedural second timeline, or allowing save/order edge cases to silently destroy completion?

## Locked principle

A **Setup/Payoff Chain is a stable-ID authored semantic state machine**. It observes authoritative facts owned by other systems and records only state that belongs specifically to the chain.

> **Source systems own facts. Setup/Payoff evaluates them. It does not copy them.**

The system is not a generic alternate-timeline generator and is not permission for arbitrary one-off quest scripting.

## Identity

Canonical chain IDs use:

`setup.<region>.<slug>`

Display names, localized strings, Actor paths, map paths, coordinates, trigger names, runtime instance IDs, Blueprint node names, and scene/node paths are never persistence identity.

A semantic ID may change after save compatibility matters only with an explicit migration alias/rule.

## Lifecycle

The canonical normal lifecycle is:

1. **Dormant** — the authored relationship exists in data but its priming predicate is not yet satisfied.
2. **Primed** — the relevant setup relationship has become semantically present/eligible.
3. **Committed** — the early-world history that matters to this chain has crossed its authored commit boundary.
4. **Payoff Available** — the later-world predicates for an authored consequence are satisfied and the player can meaningfully encounter/resolve it.
5. **Resolved** — one valid authored payoff outcome has durably settled and the chain's completion predicate is satisfied.

Exceptional availability classifications:

- **Unavailable** — current canonical world state temporarily prevents access to the payoff; the chain is not erased, failed, or resolved.
- **Superseded** — a later irreversible canonical transition makes the originally staged payoff impossible; an explicitly authored equivalent resolution path must exist rather than silently making a canonical completion item impossible.

Unavailable and Superseded are explainable semantic classifications, not catch-all error buckets.

## Ownership and observed facts

A chain may observe stable facts from Story, Quest, World State, NPC, Hush, Progression, Tool, Traversal, Encounter, Record, Repair Contract, or other authoritative systems.

Example observed inputs may include:

- `contract.brindle.crooked_fire_bell = locally_tuned`
- `world.stillness.begun = true`
- `npc.mara_pell.available = true`
- `tool.anchor_line.acquired = true`

The Setup/Payoff system must not duplicate those source facts as shadow booleans.

It may own chain-specific facts such as:

- `setup.brindle.crooked_fire_bell.state = payoff_available`
- `setup.brindle.crooked_fire_bell.resolution = moving_pocket_preserved`

Every observed predicate exposed in tooling must identify its authoritative owner.

## Choice and completion safety

The early setup may materially alter the later consequence. Valid branches may change routes, NPC availability, testimony, repair outcomes, services, resources, physical local state, dialogue, or other reviewed authored consequences.

However:

- there is no hidden designer-preferred moral answer required for completion;
- a valid authored early choice cannot unknowingly destroy the player's ability to satisfy that chain's completion item;
- completion requires reaching one valid authored payoff resolution, not selecting a prescribed ethical answer;
- prerequisites do not create bonus Setup/Payoff completion IDs;
- a source Contract and a later Setup/Payoff may each satisfy their own distinct completion item because they are distinct authored outcomes, but no third phantom prerequisite/reward-source item is created.

## Non-intervention and missed setup

Every canonical completion-bearing chain must explicitly author what happens if the player does not perform the optional early intervention.

Before the chain's commit boundary, the setup may remain returnable where fiction and progression permit.

After the commit boundary, non-intervention must produce an authored historical state and later meaningful consequence when that chain is completion-bearing. It may not become an unknowable permanent miss requiring a new save merely because an early conversation, trigger, or optional interaction was skipped.

The twelve canonical Setup/Payoff chains therefore require a reachable authored resolution under every valid supported setup/non-intervention history.

This rule does not make choices cosmetic: consequences may differ substantially. It prevents completion from depending on clairvoyance.

## Save/load and reconciliation

Source systems restore their authoritative facts first.

The Setup/Payoff layer then reconciles chain state from:

1. stable semantic chain identity;
2. authoritative source facts;
3. any chain-owned committed/resolution facts that are legitimately persistent;
4. schema/custom-version migration rules.

Cached presentation, trigger occupancy, spawned Actor state, or a cached global percentage never outranks semantic facts.

If saved chain state contradicts authoritative inputs, the system must expose an audit mismatch and fail conservatively. It must not silently choose whichever boolean or Actor loaded last.

Resolved rewards and completion settlement must be idempotent across save/load/retry. Re-entering a payoff after resolution cannot duplicate one-time rewards or completion credit.

## Unexpected order / sequence break

Chains evaluate semantic conditions rather than assuming a particular scene or trigger fired first.

If the player reaches later prerequisites before seeing the expected setup presentation, the authored chain must deterministically choose one supported behavior, such as:

- expose the missing setup through evidence/dialogue;
- advance through already-satisfied semantic stages;
- present an authored changed payoff variant;
- present an authored 'arrived after the event' history.

An unexpected but valid traversal/order cannot strand the chain in an impossible state merely because a presentation trigger was bypassed.

## Authoring contract

Every canonical chain must declare, in reviewable data/documentation:

1. semantic chain ID;
2. region/subregion and presentation label(s);
3. source systems observed;
4. priming predicate;
5. commit boundary;
6. payoff eligibility predicate;
7. all supported outcome variants;
8. non-intervention outcome;
9. temporary availability/unavailability rules;
10. supersession rule/equivalent resolution if applicable;
11. exact completion predicate;
12. presentation consequences by system (world geometry, NPC, route, dialogue, testimony, service, resource, etc.);
13. persistence owner for every fact involved;
14. schema version/migration aliases where applicable;
15. death/retry, save/load, map reload, interrupted interaction, NPC absence, and unexpected-order recovery;
16. spoiler/discovery presentation limits;
17. System IDE fixtures and expected assertions.

A narrative author must be able to define a chain without hardcoding map/node/Actor paths as persistence logic.

## Player-facing disclosure

The game is not required to expose the internal lifecycle vocabulary to players.

Journal/completion presentation follows existing spoiler authority: undiscovered setup/payoff content may remain neutral/hidden until legitimately known. The system may explain a known unresolved relationship without revealing future NPC outcomes, exact hidden locations, or unchosen alternate consequences.

## Quest / Objective / World-State System IDE

Issue #9 requires a dedicated Setup/Payoff inspector inside the shared in-game developer shell.

For a selected chain it must expose at minimum:

- chain semantic ID;
- current lifecycle state/classification;
- every observed predicate and current value;
- authoritative owner of every observed fact;
- priming predicate with pass/fail explanation;
- commit boundary/status;
- payoff predicate with pass/fail explanation;
- supported outcome variants;
- current resolution, if any;
- completion entitlement/status;
- save schema/custom version;
- migration aliases/history;
- temporary overrides versus canonical values;
- audit findings and repair guidance.

Deterministic exercise presets must cover:

- before setup;
- setup performed;
- setup ignored/non-intervention;
- committed but pre-payoff;
- payoff available;
- every valid payoff outcome;
- source NPC temporarily unavailable;
- unexpected order/sequence break;
- save/reload at every lifecycle boundary;
- superseded-world-state recovery where applicable;
- duplicate reward/re-entry attempt;
- contradictory/orphaned source-fact audit.

The IDE uses authoritative gameplay services. It must not create a second hidden narrative state model.

## Deterministic Decision #1 fixtures

At minimum, implementation evidence for this decision must prove:

1. stable semantic ID survives map/Actor rename;
2. Dormant -> Primed transition from source facts;
3. Primed -> Committed at authored boundary;
4. valid branch A and branch B both retain eventual completion eligibility;
5. non-intervention produces its authored later state;
6. Payoff Available requires its semantic predicates, not trigger history;
7. temporary Unavailable does not erase completion eligibility;
8. Superseded routes to explicit authored equivalent resolution;
9. save/reload at each lifecycle boundary converges to the same semantic state;
10. resolved payoff is idempotent and cannot duplicate reward/credit;
11. out-of-order arrival produces the authored defensive path rather than deadlock;
12. contradictory source/chain state surfaces an audit mismatch;
13. Setup/Payoff does not shadow-copy a source system's authoritative fact;
14. completion ledger receives exactly one item on valid resolution and no prerequisite bonus item;
15. IDE explains why the chain is or is not payoff-eligible.

## Red-team rejection conditions

Reject an implementation if any of the following is true:

- persistent identity depends on Actor/map/node/trigger paths or display strings;
- chains devolve into unrelated custom boolean soup;
- Setup/Payoff duplicates facts owned by Story, Quest, World, NPC, Hush, Progression, or another source system;
- a valid early authored choice permanently prevents 100%;
- completion secretly requires one moral branch;
- skipping an early presentation unknowingly makes a canonical chain permanently impossible;
- save/reload can produce different payoff truth from identical authoritative facts;
- reload/re-entry can duplicate one-time rewards or completion credit;
- later world progression silently deletes a completion-bearing chain;
- valid sequence breaking creates an impossible/dead state;
- a writer must hardcode runtime scene paths to author persistence;
- the System IDE cannot explain why a chain is or is not available;
- the system generates generic alternate-world/timeline copies rather than explicit authored consequences.

## Relationship to existing authority

- Issue #4 / Save-World-State authority remains the owner of stable persistence, schema/versioning, migration, and source-fact rules.
- Completion Decision #16 remains the owner of global completion weighting/reporting. Setup/Payoff contributes one of twelve items only when its exact chain resolution predicate is satisfied.
- Hush/World-Layer authority remains the owner of Waking/Hush semantic world-layer behavior. A Setup/Payoff chain may observe those facts but does not redefine them.
- Repair Contracts, NPC state, tools, traversal, records, and story retain ownership of their respective facts.
- `docs/11_QUEST_AND_COMPLETION_LEDGER.md` remains an authored-content source for the twelve chains, subject to later Issue #9 reconciliation and newer authority.

## Runtime evidence boundary

This decision is design authority only. It does not claim UE5.8 runtime implementation, save/reload proof, System IDE execution, or human play acceptance.

## Owner approval

Approved by the owner on 2026-09-05.

# 113 — Setup/Payoff Decision #2 — Commit Boundary Authority

**Status:** FINAL OWNER APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #9 — Design cross-state setup and payoff framework  
**Parent:** `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`  
**Decision:** #2 — semantic commit boundaries, reversibility, death/retry, Hush, global transitions, NPC availability, atomic persistence, and IDE provenance

## Locked principle

A Setup/Payoff chain commits only at an explicitly authored **semantic boundary** where a physical, social, operational, or catastrophe-state fact becomes legitimate history for downstream systems.

> Save operations, dialogue endings, map transitions, Hush transitions, checkpoints, autosaves, cutscene completion, and global story beats are never implicit commit mechanisms.

A presentation event may coincide with a commit only because an authored semantic event occurred there.

## Meaning of commit

Before commit, a Primed setup may remain reversible/revisable where fiction and physical state permit.

After commit, downstream systems may rely on the committed variant as historical truth. Later events may change the present, but they do not casually rewrite the committed past.

A commit boundary therefore answers:

- what fact became historical;
- which authoritative source owns that fact;
- exactly what semantic event made it durable;
- which variant was committed;
- which downstream systems may consume that history.

## Canonical boundary classes

### Physical Commit
A persistent physical-world change becomes durable and consequential.

Examples include an installed brace, sealed/preserved bypass, redirected sluice, removed support, or constructed manual relay.

The owning world/interaction system owns the physical fact; Setup/Payoff records the chain-specific committed history.

### Social Commit
Information, responsibility, agreement, attribution, or a promise has propagated far enough that the world may reasonably react to it.

Examples include formally submitted evidence, public attribution, community adoption of a plan, or a courier actually departing with a report.

Selecting a dialogue option or reaching the end of a conversation is not automatically a Social Commit.

### Operational Commit
A repaired/reconfigured system is placed into service.

Examples include reopening a route, activating a local signalling procedure, placing a ferry linkage into operation, or starting an independent dispatch network.

### Catastrophe Commit
An explicitly named irreversible story/world transition evaluates the authored setup state that exists at that moment and turns it into historical input for a later payoff.

Stillness may be a Catastrophe Commit for specific chains, but only where that chain explicitly declares it.

## Global-transition rule

No global story transition implicitly commits every Setup/Payoff chain.

Forbidden behavior includes an operation equivalent to `commit all current setup values` when Stillness, Motion, Unringing, credits, Hush entry, or another global phase begins.

Each chain declares its own commit boundary. Different chains may legitimately commit at different semantic moments even if their later payoffs occur in the same world phase.

## Reversibility before commit

A player may inspect, test, temporarily manipulate, discuss, or preview possible setup states without committing history unless the authored boundary says those actions themselves create an irreversible consequence.

Example pattern:

- inspect damaged mechanism — no commit;
- test brace A/B — no commit;
- temporarily install a reversible test configuration — no commit if authorship says it remains reversible;
- perform final service verification / return mechanism to public operation — Operational or Physical Commit.

The game must not use an arbitrary dialogue choice as a hidden early lock when the fiction still shows the decision as physically/socially reversible.

## Death, retry, checkpoint, and save authority

Death is not an independent narrative undo system.

If death/retry restores an authoritative checkpoint/save transaction that predates the semantic commit, the chain returns to the valid pre-commit state represented by that transaction.

If the authoritative checkpoint/save transaction includes the committed history, ordinary combat death does not roll it backward.

Narrative history therefore follows the existing authoritative save/checkpoint transaction model rather than treating death itself as a commit or rollback signal.

Saving the game never creates a commit that did not already semantically occur.

## Atomic commit/recovery

A semantic commit must reconcile atomically.

After crash, quit, power loss, interrupted streaming, or reload, the world must converge to one valid state:

- pre-commit; or
- committed with one exact committed variant.

A half-state where physical truth, NPC memory, Setup/Payoff history, completion state, and later payoff predicates disagree is invalid.

If persisted/source facts contradict after recovery, the System IDE/save audit must expose the mismatch and the runtime must fail conservatively rather than silently choosing whichever Actor/boolean loaded last.

One-time settlement/reward side effects remain idempotent.

## Hush interaction

Hush entry and exit do not inherently commit Setup/Payoff history.

A Hush-specific interaction may participate in a commit only if:

1. Hush authority permits that interaction to create an explicit persistent semantic fact; and
2. the chain names the resulting semantic event as its commit boundary.

Waking/Hush presentation changes may reveal, conceal, or contextualize committed history but may not secretly select or rewrite it.

## NPC availability

NPC presence is not a substitute for the semantic commit definition.

If a physical/operational commit has already been earned, later NPC relocation, death, schedule change, or temporary unavailability cannot erase it merely because a final acknowledgement conversation did not occur.

Conversely, if the authored commit genuinely requires social propagation — for example, a report being delivered — completing the physical repair alone does not fabricate that Social Commit.

Every chain must distinguish acknowledgement/presentation from the actual boundary.

## Committed-history rule

Ordinary later player interaction does not directly rewrite committed historical facts.

Where history matters, later change is represented as a new semantic fact rather than mutation of the old event.

Preferred conceptual form:

- `bell.initial_service_configuration = locally_tuned`
- later `bell.post_stillness_rebuild = distributed_brace`

rather than changing the initial historical fact to pretend the earlier configuration never existed.

This preserves testimony, NPC memory, credits logic, debugging, and payoff provenance.

## Meaningful-variant rule

A committed variant must justify its authoring complexity through downstream meaning.

If two proposed committed variants have no meaningful distinction in world behavior, dialogue, routes, NPC state, testimony, gameplay, payoff, or another reviewed consequence, they should normally collapse into one semantic variant rather than create fake branching complexity.

This rule does not require every consequence to be mechanically advantageous/disadvantageous. Social, spatial, narrative, service, testimony, or presentation consequences may be meaningful when deliberately authored.

## Commit transaction semantics

The semantic persistence contract must be able to identify at minimum:

- chain semantic ID;
- commit-boundary semantic ID;
- committed variant;
- required source-fact references/owners;
- relevant schema/custom version.

Example conceptual record:

- chain: `setup.brindle.crooked_fire_bell`
- boundary: `service_verification_ring`
- variant: `locally_tuned`

Runtime storage shape remains an implementation decision, but human-readable quest titles, Actor paths, coordinates, trigger names, and Blueprint node names cannot be the authority.

## Player-facing permanence

The retail game does not expose internal `Committed` terminology merely for engineering clarity.

Where possible, permanence is communicated diegetically and through ordinary journal language:

- mechanism enters service;
- worker/courier departs with the report;
- community adopts the procedure;
- route reopens;
- bell/system behaves differently;
- responsibility becomes publicly acknowledged;
- journal text shifts from active work to historical/completed language.

A player should be able to understand that something meaningful settled without a developer-state banner.

## System IDE additions

The Setup/Payoff inspector defined by Decision #1 must additionally expose:

- authored boundary class;
- boundary semantic ID;
- boundary predicate/event explanation;
- whether commit has fired;
- exact semantic event that fired it;
- committed variant;
- authoritative source facts captured/referenced at commit;
- current source facts;
- differences between current state and committed history;
- authoritative save/checkpoint transaction containing the commit when inspectable;
- all known downstream consumers of the committed history;
- atomic-recovery/audit state.

The downstream-consumer view is required so a developer can determine whether committed history currently drives NPC dialogue, route geometry, testimony, services, completion, credits, or other systems without hunting through unrelated Blueprints.

## Deterministic Decision #2 fixtures

At minimum implementation evidence must prove:

1. dialogue selection/end does not commit unless explicitly authored as the semantic event;
2. reversible physical testing remains pre-commit;
3. the authored service/physical/social event commits the exact variant;
4. Stillness commits only chains that explicitly declare Stillness/the relevant catastrophe event as their boundary;
5. unrelated chains remain uncommitted across that global transition;
6. Hush entry/exit does not implicitly commit;
7. a permitted Hush interaction commits only through its explicit persistent source fact and declared boundary;
8. NPC relocation after an already-earned physical/operational commit does not erase history;
9. a chain requiring report delivery does not commit merely from physical repair completion;
10. death/retry to an authoritative pre-commit checkpoint restores pre-commit history;
11. death after an authoritative committed transaction preserves committed history;
12. crash/reload during commit converges atomically to pre-commit or one exact committed variant;
13. map/Actor rename does not alter committed semantic history;
14. later modification appends/owns a later fact without rewriting the meaningful committed past;
15. `Committed` alone does not satisfy the Setup/Payoff completion item before actual payoff resolution;
16. IDE identifies exact boundary event, variant, source owners, and downstream consumers;
17. duplicate/replayed boundary event remains idempotent;
18. contradictory source/commit history produces an explicit audit mismatch rather than silent repair.

## Red-team rejection conditions

Reject implementation if:

- saving/autosaving itself commits narrative history;
- map unload, checkpoint creation, cutscene end, or dialogue end is used as an implicit generic commit;
- Stillness or another global phase automatically commits all chains;
- Hush entry/exit implicitly selects a historical branch;
- combat death rolls history backward independently of authoritative checkpoint/save state;
- NPC disappearance erases a semantically completed setup;
- commit/recovery can leave authoritative systems disagreeing;
- current Actor state is used to infer historical committed variant when semantic history should already exist;
- later present-day changes overwrite meaningful historical facts;
- meaningless cosmetic duplicates are represented as separate committed branches without reviewed downstream purpose;
- the IDE cannot identify what semantic event committed the chain;
- the IDE cannot identify known downstream consumers of the committed history.

## Relationship to Decision #1

Decision #1 defines the chain lifecycle, fact ownership, completion safety, save reconciliation, authoring contract, and Setup/Payoff IDE baseline.

Decision #2 defines exactly what `Committed` means and how a chain crosses into durable history.

Decision #2 does not alter the rule that completion is earned at valid authored payoff resolution, not merely at setup commit.

## Runtime evidence boundary

This is design authority only. It does not claim UE5.8 execution, atomic save proof, Hush runtime proof, checkpoint proof, System IDE implementation, or human play acceptance.

## Owner approval

Approved by the owner on 2026-09-05.

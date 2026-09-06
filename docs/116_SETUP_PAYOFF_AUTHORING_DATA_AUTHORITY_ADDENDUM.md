# 116 — Setup/Payoff Decision #5 — Authoring and Data Authority

**Status:** FINAL OWNER APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #9 — Design cross-state setup and payoff framework  
**Parents:** `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`, `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`, `docs/114_SETUP_PAYOFF_PAYOFF_MATERIALITY_AUTHORITY_ADDENDUM.md`, `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`  
**Decision:** #5 — authoring source, runtime history, predicates, semantic events, variant/resolution contracts, provider escape hatches, dependency validation, and System IDE authoring workflow

## Locked principle

Each Setup/Payoff chain has **one canonical authored definition**, **minimal durable runtime history**, and **source-owned downstream consequences**.

> Authored definition is not live state. Runtime history is not a copy of the world. Setup/Payoff never steals fact ownership from the systems that actually own those facts.

The initial Unreal Engine implementation target is one stable-semantic-ID Setup/Payoff Primary Data Asset per chain, discovered through the Asset Manager. Runtime history is stored separately through the project's authoritative save/world-state services.

A secondary hand-maintained registry of the same definitions is forbidden. If a Data Registry or generated index is later introduced for performance/discovery reasons, it must be generated from or otherwise consume the same canonical definitions rather than become another authoring authority.

## Canonical definition asset

Each chain is authored as one definition conceptually equivalent to:

`USetupPayoffDefinition : UPrimaryDataAsset`

The implementation name may change, but the semantic contract does not.

The asset contains what the chain **means**, not what happened on a particular save.

Required authoring sections:

1. Identity
2. Source facts
3. Priming predicate
4. Commit boundary
5. Supported variants
6. Explicit non-intervention
7. Payoff eligibility
8. Payoff outcomes / exact resolution
9. Manifestation contracts
10. Supersession / equivalent resolution
11. Presentation references / spoiler rules
12. Persistence schema / migration metadata
13. Recovery rules
14. Deterministic fixtures
15. Portfolio metadata used by Decision #4 audits

## Semantic identity

The chain's persistent identity is its semantic ID:

`setup.<region>.<slug>`

The asset filename, package path, class name, display name, localized string, Actor path, level path, coordinates, Blueprint graph, node name, trigger volume, scene object, or array position never becomes chain identity.

The implementation should derive/override the Unreal Primary Asset identity from the stable semantic chain ID or a deterministic representation of it so that moving or renaming an asset does not silently create a new gameplay identity.

Semantic ID changes after save compatibility require explicit migration aliases/rules.

## Definition versus runtime history

### Definition owns

The definition asset may author:

- chain ID;
- schema/custom version;
- region and portfolio classification;
- story-mandatory versus story-optional status;
- conceptual question;
- all observed source facts and their owners/types;
- priming predicate;
- commit boundary class and semantic boundary ID;
- commit trigger/event/predicate contract;
- supported committed variants;
- non-intervention variant;
- payoff eligibility predicate;
- valid outcome/resolution definitions;
- manifestation dependencies;
- supersession/equivalent resolution;
- presentation metadata;
- migration aliases/rules;
- recovery contract;
- deterministic fixtures.

### Definition never owns

The definition asset must not contain mutable save-specific truth such as:

- current chosen variant;
- `PayoffAvailable=true`;
- current NPC availability;
- current route state;
- current Story phase;
- whether a reward was already settled;
- cached Completion Ledger satisfaction.

Those are runtime/source-system facts or derived state.

## Minimal durable runtime history

Do not blindly persist the whole Setup/Payoff lifecycle.

`Dormant`, `Primed`, `Payoff Available`, and ordinary `Unavailable` classifications are normally derived from current authoritative source facts plus durable chain history.

The irreversible historical facts are represented through durable semantic receipts/equivalent records.

### Commit receipt

Conceptually includes:

- ChainId
- CommitBoundaryId
- CommittedVariantId
- definition/schema version at settlement
- enough semantic provenance/reference information to reconcile against authoritative source facts

### Resolution receipt

Conceptually includes:

- ChainId
- OutcomeId / ResolutionId
- definition/schema version at settlement
- idempotent settlement/completion information as required by the owning save/completion systems

Exact C++/serialization shape remains an implementation decision.

A save must not maintain shadow copies of every source fact just to reconstruct Setup/Payoff state.

## Lifecycle derivation

Current lifecycle is reconciled from:

1. the canonical definition;
2. current authoritative source facts;
3. legitimate durable commit history;
4. legitimate durable resolution history;
5. schema/migration rules.

A persisted cache may exist for performance only if it is disposable and never outranks the semantic inputs above.

Identical authoritative inputs plus identical durable history must converge to identical Setup/Payoff truth after load.

## Source-fact references

Every observed fact declaration identifies:

- semantic fact ID;
- authoritative owner/system;
- expected type/domain;
- permitted comparison semantics.

Examples:

- owner `Contract`, fact `contract.brindle.crooked_fire_bell`, enum/value `locally_tuned`;
- owner `Story`, fact `world.stillness.begun`, boolean `true`;
- owner `NPC`, fact `npc.mara_pell.availability`, state/enum;
- owner `Tool`, fact `tool.anchor_line.acquired`, boolean/state.

A missing owner is a validation error.

Setup/Payoff may observe these facts. It does not copy or become their owner.

## Declarative predicate model

The default authoring path uses a deterministic declarative predicate tree rather than bespoke Blueprint graphs.

Required composition operators:

- ALL
- ANY
- NOT

Required common leaf comparisons:

- equals;
- not equals;
- true/false;
- exists / not exists;
- contains where the source type legitimately supports membership;
- numeric threshold/range where legitimately required;
- state/enum membership.

A predicate leaf must identify the source owner and semantic fact being tested.

Gameplay Tags may be used for classification, hierarchical vocabulary, or queries where they match the source system's actual data model; they do not become a universal untyped bag replacing authoritative facts.

## Bespoke predicate/provider escape hatch

Arbitrary per-chain Blueprint callbacks are forbidden as authority.

The generic authoring model may call a bespoke condition only through an explicitly named semantic provider, conceptually:

`predicate_provider.<owning_system>.<semantic_name>`

A provider must:

- belong to a named authoritative system;
- expose/document its semantic inputs;
- be deterministic for identical authoritative inputs;
- expose a human-readable true/false explanation to the System IDE;
- have deterministic tests/fixtures;
- participate in dependency auditing;
- never hide mutable state that is unavailable to save/reconciliation authority.

A provider exists because the normal predicate vocabulary is insufficient, not because an author finds a Blueprint graph more convenient.

## Semantic commit events

Commit boundaries are identified by semantic IDs/events/predicate transitions.

Allowed conceptual form:

`event.infrastructure.fire_bell.returned_to_service`

Forbidden authority:

`BP_BellActor.OnComponentOverlap`

A source system may emit/settle a semantic event when its own authoritative state changes. Setup/Payoff evaluates the authored commit contract and resolves the exact committed variant from authoritative facts.

Repeated delivery of the same boundary event must be idempotent.

## Commit definition

Every chain declares:

- CommitBoundaryId;
- boundary class from Decision #2;
- semantic trigger/event/predicate;
- source owner(s) relevant to boundary truth;
- variant resolver;
- behavior if event arrives unexpectedly/out of presentation order;
- duplicate-event behavior;
- crash/reload reconciliation.

A level unload, save operation, cutscene ending, generic dialogue ending, map transition, or Hush transition cannot substitute for the declared semantic boundary.

## Variant definitions

Every supported committed history has a semantic variant ID.

Examples may conceptually resemble:

- `variant.standardized`
- `variant.locally_tuned`
- `variant.non_intervention`

The exact namespace convention may be refined later, but array indexes such as `0`, `ChoiceA`, or presentation ordering are never persistent identity.

Each variant declares:

- exact validity predicate/source facts;
- whether/how it can commit;
- allowed payoff outcomes;
- migration aliases where required;
- completion-safe route/equivalent resolution.

## Non-intervention is first-class

Every completion-bearing canonical chain declares explicit non-intervention data rather than relying on a generic `else` branch.

The contract includes:

- semantic non-intervention history/variant;
- when/how it becomes historical;
- later payoff behavior;
- exact completion resolution;
- player-facing manifestation/legibility;
- supersession recovery if ordinary payoff presentation becomes impossible.

Non-intervention is authored content, not an error path.

## Payoff eligibility versus resolution

A definition always separates:

### Payoff eligibility
Whether the later consequence can currently be encountered.

### Resolution
The exact semantic event/predicate proving the player has encountered/settled the authored payoff strongly enough for the chain to become `Resolved` and contribute its one Completion Ledger item.

`Payoff Available` never implies completion.

The completion system consumes exact semantic resolution truth and does not infer completion from entering a volume, receiving a quest marker, or merely loading the payoff area.

## Manifestation contracts and source ownership

The definition may describe every downstream manifestation needed to explain the causal chain.

Each manifestation identifies:

- semantic downstream fact/event;
- actual authoritative source owner;
- relationship to the committed variant/payoff;
- whether it is the primary manifestation or a supporting echo;
- player-facing evidence/legibility where relevant.

Example conceptual dependency:

`setup.brindle.crooked_fire_bell committed_variant=locally_tuned`

may be consumed by World State to derive/settle:

`world.brindle.fire_bell.motion_state=irregular_pocket`

Setup/Payoff owns the chain history. World State owns the world fact.

The definition documents the causal contract without stealing ownership.

## Source systems may consume chain history

Named source systems may legitimately consume stable Setup/Payoff historical facts when deriving their own states.

Dependency direction must be explicit and visible to the IDE.

Conceptual example:

Contract source fact
→ Setup/Payoff commit receipt
→ World State consequence
→ NPC/route/presentation consequence
→ Setup/Payoff payoff-resolution predicate
→ Completion Ledger derived satisfaction

No participating system may maintain an undocumented private shadow boolean for the same history.

## Dependency graph and cycle safety

The authoring validator must construct a dependency graph across:

- source facts;
- providers;
- chain commit predicates;
- committed history;
- manifestation facts;
- payoff eligibility;
- payoff resolution;
- cross-chain prerequisites.

Circular eligibility/authority dependencies are invalid.

Intentional narrative callbacks and later references are permitted; they are not the same as a cycle where A cannot resolve without B and B cannot resolve without A.

Cycle validation must run before production sign-off.

## Presentation references

Soft references may exist for presentation/dev convenience, including:

- dialogue assets;
- journal/localization records;
- icons;
- VO/audio;
- environmental presentation packages;
- cinematics;
- preview images;
- debug/IDE teleport fixtures.

Presentation references never determine semantic chain truth.

Moving a presentation asset must not alter commit/payoff/resolution facts.

## No per-chain Blueprint authority subclasses

Writers author instances of the shared Setup/Payoff definition system.

Production should not create one-off authority classes such as:

- `BP_CrookedBellSetupLogic`
- `BP_GraymileSetupLogic`
- `BP_GreenSpanSetupLogic`

with hidden bespoke state/overrides.

Bespoke behavior belongs to the appropriate source system or an explicitly named deterministic semantic provider that remains visible to the shared authoring/IDE model.

## Writer authoring contract

A production-ready chain must fill out all of the following.

### 1. Identity

- ChainId
- schema version
- region
- story-mandatory/story-optional classification
- completion-bearing status
- conceptual portfolio question

### 2. Source facts

- every observed semantic fact
- authoritative owner
- expected type/domain

### 3. Priming

- exact predicate
- presentation/discovery relationship

### 4. Commit

- boundary semantic ID
- boundary class
- semantic trigger/event/predicate
- exact variant resolver

### 5. Variants

- all supported committed histories
- explicit non-intervention

### 6. Payoff eligibility

- exact predicate tree
- temporary unavailability rules
- supersession rules

### 7. Payoff outcomes

- semantic outcome/resolution IDs
- exact resolution predicates/events
- completion entitlement behavior

### 8. Manifestations

- primary manifestation
- supporting echoes where useful
- actual source owner for every manifested fact
- player-facing legibility contract

### 9. Supersession

- irreversible later world progression that can replace original payoff presentation
- explicit equivalent authored resolution

### 10. Presentation

- discovery/spoiler policy
- journal/dialogue/environmental references

### 11. Persistence/migration

- custom/schema version
- aliases
- split/merge/tombstone rules where required

### 12. Recovery

- death/retry
- save/load
- map reload/streaming
- interrupted interaction
- NPC absence
- unexpected progression/order

### 13. Fixtures

- deterministic validation fixtures covering all relevant Decision #1–#5 contracts

A chain that omits a required section remains authoring-incomplete.

## Writer workflow

Target shared-tool workflow:

1. Create Setup/Payoff definition.
2. Assign stable semantic ID first.
3. Declare source facts and owners.
4. Build predicates from shared typed controls.
5. Define semantic commit boundary.
6. Define supported variants and non-intervention.
7. Define payoff eligibility and resolution.
8. Declare downstream manifestations and owners.
9. Define recovery/supersession.
10. Add deterministic fixtures.
11. Run `Validate Chain`.
12. Preview/exercise in the Setup/Payoff System IDE.
13. Run portfolio/dependency audits.

Writers must not need to type level/Actor/Blueprint paths to author save-safe narrative state.

## System IDE — authoring mode

In addition to the runtime inspector already required by Decisions #1–#4, the Setup/Payoff workbench requires an Authoring Inspector showing:

- semantic identity/schema;
- portfolio metadata/conceptual question;
- all source dependencies and owners;
- predicate trees with typed leaves;
- commit boundary/event/variant resolver;
- variants/non-intervention;
- payoff eligibility;
- outcome/resolution definitions;
- manifestations and actual owners;
- supersession/equivalent resolution;
- migration aliases;
- deterministic fixtures;
- dependency graph;
- validation/audit state.

Required development actions include:

- `Validate Chain`
- `Exercise All Variants`
- `Save/Reload Every Boundary`
- `Run Unexpected-Order Matrix`
- `Run Portfolio Similarity Audit`
- `Trace Dependency Graph`
- `Find Orphan Semantic References`
- `Explain Current State`

The workbench must use the same gameplay/source services as production runtime rather than maintaining an editor-only duplicate state model.

## Explain Current State contract

For a selected chain the IDE must be able to explain, in human-readable terms:

- current derived lifecycle;
- current durable commit/resolution history;
- every predicate leaf and current value;
- the authoritative owner for each value;
- exact missing predicates preventing priming/commit/payoff/resolution;
- current variant;
- known downstream manifestations;
- supersession/equivalent-resolution state;
- migration history;
- dependency/audit errors.

A chain whose current state cannot be explained is not production-ready.

## Validation failures

At minimum validation rejects or blocks production sign-off for:

- duplicate ChainId;
- missing/unknown source fact;
- missing source owner;
- type/operator mismatch;
- missing commit boundary;
- Actor/map/Blueprint/presentation path used as semantic authority;
- arbitrary per-chain Blueprint callback used as predicate/commit authority;
- duplicate or ambiguous variant identity;
- supported variant with no completion-safe payoff path;
- missing non-intervention path;
- Payoff Available used as completion itself;
- unreachable completion-bearing outcome;
- dependency/eligibility cycle;
- downstream manifestation with no actual source owner;
- consequence that fails Decision #3 materiality/legibility/causality/history requirements;
- conflicting migration aliases;
- orphaned semantic references;
- incomplete required fixture coverage;
- S07 reverting to the superseded redundant moving-pocket portfolio concept;
- S10 collapsing into a mere duplicate-record-survived payoff instead of distributed agency;
- inability to explain runtime state through the IDE.

## Deterministic Decision #5 fixtures

At minimum future implementation evidence must prove:

1. moving/renaming a definition asset preserves semantic identity;
2. definition content contains no save-specific mutable truth;
3. transient lifecycle classifications recompute from source facts/history after load;
4. commit receipt survives save/load and does not duplicate on repeated event delivery;
5. resolution receipt settles exactly once;
6. source fact changes alter derived availability without stale saved `PayoffAvailable` truth winning;
7. predicate leaf exposes its source owner/current value;
8. unsupported arbitrary Blueprint callback is rejected;
9. named deterministic provider produces explainable pass/fail output;
10. presentation asset/path changes do not affect semantic state;
11. non-intervention path validates as first-class authored content;
12. missing owner/semantic fact blocks validation;
13. dependency cycle is detected before runtime;
14. cross-system manifestation keeps source-system ownership;
15. completion receives one item only after exact resolution;
16. authoring IDE and runtime inspector agree because both use authoritative services;
17. Explain Current State identifies exact blocker for a deliberately unavailable payoff;
18. portfolio similarity/dependency audits operate on definition metadata without becoming runtime authority.

## Rejection conditions

Reject the implementation if:

- definition filenames/package paths become persistence identity;
- mutable save history is stored in the canonical definition assets;
- Setup/Payoff saves copies of every observed source fact;
- transient `PayoffAvailable`/`Primed` booleans outrank source facts after load;
- chain behavior depends on bespoke hidden Blueprint subclasses;
- an arbitrary callback can decide canonical narrative truth without named ownership/testing/explanation;
- non-intervention is an untyped fallback rather than authored content;
- presentation references control semantic truth;
- a second manually authored Data Registry or table becomes competing authority;
- dependency cycles are permitted to ship;
- System IDE authoring/runtime views maintain a second hidden state model;
- a writer must know runtime Actor or node paths to author the chain;
- runtime state cannot be human-explained from source facts and durable history.

## Relationship to Unreal implementation

The selected implementation direction is compatible with Unreal Engine's Primary Data Asset/Asset Manager model for authored definitions and the SaveGame/world-state model for runtime progression.

This document locks semantic architecture, not exact class/member names or serialization layout. C++/Blueprint/editor-tool implementation may evolve if it preserves every authority and validation rule above.

## Runtime evidence boundary

This is design/architecture authority only. It does not claim:

- UE5.8 class implementation;
- Asset Manager configuration;
- SaveGame serialization proof;
- predicate/provider runtime proof;
- editor customization;
- System IDE implementation;
- performance proof;
- human writer/usability acceptance.

Those require later implementation evidence.

## Owner approval

Approved by the owner on 2026-09-05.

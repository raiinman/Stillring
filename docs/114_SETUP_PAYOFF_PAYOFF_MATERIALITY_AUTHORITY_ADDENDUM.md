# 114 — Setup/Payoff Decision #3 — Payoff Materiality Authority

**Status:** FINAL OWNER APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #9 — Design cross-state setup and payoff framework  
**Parents:** `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`, `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`  
**Decision:** #3 — payoff eligibility, materiality, legibility, causality, persistence, reconvergence, prevention, and validation

## Locked principle

Each canonical Setup/Payoff chain must produce at least one meaningful, player-perceivable downstream difference in authoritative game state that is causally attributable to its committed history.

Consequence strength is **qualitative**, not determined by a required number of affected systems, presentation surfaces, rewards, or mechanical changes.

> A payoff is load-bearing when removing it would make the later world lose meaningful information about what the player previously did.

## No arbitrary consequence quota

There is no canonical rule that a payoff must affect two systems, include a traversal change, create a service, award loot, or generate a fixed number of dialogue/world-state echoes.

One excellent consequence may be sufficient when it is material, legible, causal, and historically retained.

Supporting echoes are encouraged when they improve attribution, emotional force, or world coherence, but they are never mandatory padding.

## Payoff eligibility

`Committed` does not imply `Payoff Available`, and `Payoff Available` does not imply `Resolved`.

A payoff becomes available only when its authored semantic prerequisites are true. These may include:

- committed setup history;
- story/world phase;
- Waking/Hush semantic state where relevant and already permitted by Hush authority;
- NPC or community availability;
- traversal/tool access;
- local infrastructure state;
- prerequisite contract/community/world facts;
- authored later-world or revisit conditions.

Expected scene order is not authority. If the semantic facts are satisfied through a valid unexpected route/order, the chain must evaluate those facts deterministically.

The System IDE must explain every failed or satisfied payoff predicate and identify each predicate's authoritative source owner.

## Resolution

A payoff resolves only when its exact authored resolution predicate is satisfied.

Depending on the chain, resolution may mean encountering, using, understanding, repairing, stabilizing, documenting, choosing within, surviving, or otherwise meaningfully settling the later consequence.

Completion is not awarded merely because the early setup committed or because the payoff became available.

## Four mandatory payoff tests

Every canonical payoff must pass all four tests below.

### 1. Materiality

At least one authoritative fact must genuinely differ because of committed history.

Qualifying differences may be spatial, operational, social, epistemic, relational, service/resource, encounter, repair, decision-space, Hush/Waking, or other reviewed authored state.

Examples:

- a route exists or is inaccessible for a causally authored reason;
- infrastructure behaves differently;
- an NPC has a different role, trust, availability, or knowledge state;
- a community uses a different procedure;
- evidence/testimony becomes available or unavailable;
- a fact can be established that otherwise could not be established;
- a later legitimate choice exists, disappears, or changes meaning;
- a local system survived, failed, or transformed differently.

A changed line of presentation text with no genuine underlying state difference does not pass Materiality.

### 2. Legibility

The player must have a reasonable ordinary-play path to perceive that the later state differs.

Stillring may trust the player to infer and connect consequences. It must not require knowledge that exists only in a design spreadsheet or System IDE.

Legibility may be environmental, mechanical, social, evidentiary, auditory, journal-based, dialogic, spatial, or systemic.

The retail game does not need to announce `YOUR CHOICE MATTERED` or expose internal lifecycle vocabulary.

### 3. Causality

The payoff must have a defensible authored causal trace:

`early state -> committed history -> later circumstances -> consequence -> resolution/aftermath`

The player need not receive a technical explanation of every link, but the relationship must make sense when understood.

Arbitrary branch-token substitution is forbidden. A prior decision cannot change an unrelated NPC/world outcome without authored causal justification.

### 4. Historical persistence

Once the payoff occurs, the game's authoritative history must retain that it occurred and why.

Historical persistence does **not** require permanent scenery or permanent present-day manifestation.

A route may later be rebuilt, an NPC may later relocate, or infrastructure may later be replaced. The present may reconverge or evolve while the historical facts, completion settlement, testimony dependencies, NPC memory dependencies, and later narrative provenance remain correct.

> Persistence applies to historical truth, not permanent scenery.

## Load-bearing consequence classes

The following classes are examples, not quotas.

### Spatial
Routes, structures, access, refuges, hazards, geometry, or traversal conditions differ.

### Operational
Infrastructure or a local service behaves differently.

### Social / relational
NPC/community role, trust, availability, coordination, responsibility, or behavior differs.

### Epistemic
The player/world can establish, preserve, challenge, or correctly interpret information that otherwise would not be available.

Epistemic consequences are first-class in Stillring. They do not need a fake traversal or reward layer to qualify.

### Decision-space
A later legitimate choice exists, is absent, changes context, or changes meaning because of earlier history.

### Other authored classes
Additional consequence forms may qualify when they pass Materiality, Legibility, Causality, and Historical Persistence and do not conflict with another system's authority.

## Dialogue and presentation

Dialogue, journal text, ambient lines, records, signage, audio, visual dressing, or credits can be meaningful manifestations of a payoff.

They qualify only when they express or expose a genuine underlying authoritative difference.

Example distinction:

- `Thanks for helping earlier.` with no changed state: callback only.
- NPC trust/knowledge state changed, which grants access to testimony or changes a later decision, expressed through dialogue: potentially material payoff.

Dialogue can be the **medium** of consequence without being the only underlying truth.

## Rewards

Currency, crafting materials, Pulse Shards, collectibles, upgrades, or other rewards may accompany a payoff.

They do not make an otherwise empty callback meaningful.

If removing the reward removes the entire reason the payoff matters, the authored consequence requires rework.

## Prevention outcomes

A valid setup may prevent a later failure or danger.

Prevention qualifies only when enough counterfactual evidence exists for the player to understand that something meaningful was avoided.

Evidence may include neighboring failures, physical stress/damage signs, NPC/community interpretation, records, expected failure models, or the player's own established diagnostic knowledge.

The game need not display an alternate timeline to prove prevention.

## Negative outcomes

A valid authored early choice may produce a difficult, harmful, inconvenient, or tragic later consequence without becoming the hidden wrong answer.

Completion remains based on reaching and resolving/understanding the authored payoff, not predicting a designer-approved future.

Consequences may have teeth without converting setup choices into morality quizzes.

## Non-intervention

Every canonical completion-bearing chain retains Decision #1's non-intervention requirement.

A valid supported non-intervention history must have an authored later payoff and completion-valid resolution path.

Its consequence must pass the same four payoff tests as active-intervention variants.

## Asymmetry

Valid payoff variants do not need equal loot, equal convenience, identical route value, identical social outcomes, or numerically matched rewards.

They must be authored, causally coherent, completion-valid, and worth encountering.

Forced outcome flattening is forbidden when it destroys the meaningful difference between histories.

## Reconvergence

Branches may diverge meaningfully during the payoff and later reconverge to a shared present-day state.

Reconvergence is allowed and often desirable for production containment.

Example pattern:

- reinforced bypass -> tunnel rescue;
- sealed bypass -> exterior rescue;
- both -> survivors later return to Graymile and regional content rejoins.

The shared later state may unify the present, but it may not falsify the past.

> Reconvergence may unify the present. It may not erase or rewrite historical truth.

The save/history layer must retain which route occurred, which resolution settled, and any downstream facts that legitimately depend on that history.

## Consequence distance

Issue #9 exists to create remembered cross-state relationships, not merely immediate quest reactions.

No fixed real-time delay is required.

A canonical chain must include enough semantic/narrative/world separation between setup and payoff that the later state is experienced as the world remembering prior history rather than merely executing the next quest step.

Different chains may use different distances: pre-/post-Stillness, regional departure/revisit, later Unringing, permitted Hush consequences, or another meaningful authored transition.

Portfolio-level pacing/diversity belongs to later Issue #9 decisions.

## Primary manifestation and ownership

Each chain should identify its **primary payoff manifestation** for authoring, review, testing, and player-facing legibility.

This does **not** create a new primary payoff owner.

Every underlying fact remains owned by its authoritative source system under Decision #1.

Setup/Payoff observes and evaluates those facts; it does not steal ownership because a consequence is important to the chain.

Secondary echoes may span multiple systems, each retaining its own authority.

## Causal trace contract

Every chain must document:

1. setup fact(s);
2. committed historical variant;
3. later enabling facts;
4. primary payoff manifestation;
5. authoritative source owner(s) of consequence facts;
6. player-facing legibility method;
7. exact resolution predicate;
8. historical facts retained afterward;
9. reconvergence point, if any;
10. any supporting echoes.

If this trace cannot be written cleanly, the chain is not ready for implementation.

## Cross-chain dependencies

A payoff may depend on another stable authored fact or chain when semantically justified.

Dependencies must be explicit, IDE-visible, cycle-checked, and completion-safe.

Hidden recursive/spaghetti dependencies are forbidden.

Circular prerequisites between completion-bearing chains are invalid.

## System IDE additions

The Setup/Payoff inspector must expose for each payoff:

- payoff eligibility predicates with pass/fail reasons;
- every predicate's authoritative source owner;
- primary payoff manifestation;
- material authoritative fact delta(s);
- legibility method(s);
- causal trace from setup through resolution;
- historical facts retained after resolution;
- supporting echoes;
- reconvergence point/state, if any;
- dependency graph and cycle status;
- exact completion resolution predicate;
- mismatch/audit findings.

The IDE must not report a failure merely because a chain has only one consequence surface.

## Meaningful Payoff Audit

Validation must flag at minimum:

- presentation-only callback with no authoritative state delta;
- reward-only payoff;
- consequence that is not reasonably player-perceivable;
- consequence with no defensible causal relationship to committed history;
- prevention branch with no legible counterfactual evidence;
- missing non-intervention payoff;
- completion awarded at commit rather than resolution;
- history lost after reconvergence;
- hidden/circular completion dependency;
- Setup/Payoff claiming ownership of another system's facts;
- payoff truth dependent on expected scene order rather than semantic predicates.

Validation must **not** require an arbitrary minimum number of affected systems or presentation surfaces.

## Deterministic Decision #3 fixtures

At minimum implementation evidence must prove:

1. committed setup alone does not make payoff available;
2. semantic payoff prerequisites can make payoff available regardless of expected scene order;
3. a presentation-only callback fails materiality validation;
4. a loot-only event fails materiality validation;
5. one strong epistemic payoff can pass without a fabricated traversal/service consequence;
6. a social/relationship payoff can pass when an underlying authoritative relationship/availability/knowledge fact genuinely changes;
7. dialogue can express a valid underlying consequence without becoming the authority itself;
8. prevention branch exposes enough evidence to be legible;
9. valid negative payoff remains completion-eligible;
10. non-intervention variant has an authored completion-valid payoff;
11. payoff availability does not award completion until resolution predicate settles;
12. resolved historical result survives save/load;
13. physical/world manifestation may later evolve without erasing historical payoff truth;
14. divergent payoff variants may reconverge to a shared present while retaining distinct history;
15. asymmetric rewards/outcomes remain valid;
16. hidden/circular dependencies fail validation;
17. IDE traces exact setup -> commit -> later facts -> payoff -> resolution -> aftermath;
18. IDE shows authoritative owner for every consequence fact;
19. one-surface payoff is not rejected solely for being one-surface;
20. supporting echoes can disappear or change without changing the authoritative resolution unless explicitly owned as required facts.

## Red-team rejection conditions

Reject implementation/content if:

- it uses an arbitrary surface-count quota as proof of quality;
- it requires every payoff to alter traversal or provide a service regardless of story/system fit;
- a callback or reward is treated as meaningful without an underlying authoritative difference;
- the player cannot reasonably perceive the consequence through ordinary play;
- cause and effect are arbitrary or unsupported;
- prevention is indistinguishable from content that never existed;
- a valid negative outcome is treated as completion failure merely for being negative;
- non-intervention creates an unfinishable canonical chain;
- reconvergence deletes/falsifies historical truth;
- present-day scenery is kept permanently frozen only because history must persist;
- Setup/Payoff invents ownership over facts belonging to World, NPC, Quest, Hush, Story, Records, Traversal, or another source system;
- implementation pads a subtle strong payoff with meaningless extra systems merely to satisfy a checklist;
- IDE cannot explain materiality, legibility, causality, historical persistence, and exact resolution.

## Relationship to existing twelve-chain content

Existing authored chains in `docs/11_QUEST_AND_COMPLETION_LEDGER.md` include physical, operational, social, and epistemic consequences. This decision explicitly preserves that diversity.

Examples such as Wren's Margin, distributed records, personal provenance, and the uncorrected lens are not required to fabricate a route or service change when their epistemic consequence is already load-bearing.

Older completion-count literals in doc 11 remain subordinate to Completion Decision #16 and its cleanup routing authority.

## Runtime evidence boundary

This decision is design authority only. It does not claim UE5.8 execution, payoff validation tooling, save/reconvergence proof, System IDE implementation, or human play acceptance.

## Owner approval

Reanalyzed after owner request and approved for lock by the owner on 2026-09-05.

# 104 — Completion Decision #16 — Completion Ledger Reconciliation and Reporting Authority

**Status:** FINAL OWNER APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #16 — completion aggregation, legacy-count reconciliation, late-game reporting, persistence/migration, audit behavior, System IDE, and Issue #8 closure authority

## Decision question

How should Stillring reconcile the now-locked completion taxonomy into one truthful save-file percentage and one auditable Completion Ledger without letting high-count collectible families dominate the number, double-counting nested mastery work, spoiling undiscovered content, or turning late-game completion help into a universal treasure radar?

## Fresh research conclusion

Stillring should use a **category-balanced completion model** backed by stable semantic facts and derived reporting.

The Completion Ledger is not the owner of world facts. It is a deterministic reconciliation/read model over authoritative story, quest, progression, mastery, traversal, record, and world-state facts.

The governing principle is:

> **Completion reports authored meaning, not raw object count.**

Current accessibility guidance supports reviewable objectives/progress and graded assistance rather than forcing one difficulty of recall or navigation on every player. UE5.8 supports explicit custom serialization/versioning, which reinforces a versioned semantic migration contract rather than positional or display-string save keys.

## Locked shipping taxonomy

The following sixteen top-level completion categories are canonical:

1. Main Story — 1 complete route;
2. Local Repair Contracts — 24;
3. Cross-state Setup/Payoff chains — 12;
4. Bellwright Refuges — 11;
5. Resonance Faults — 36;
6. Pulse Shards — 18;
7. Cantor Patterns — 9;
8. Tool Mastery Upgrades — 14;
9. Skill Trials — 9;
10. Micro-vaults / maintenance cavities — 24;
11. Testimonies / Records — 32;
12. The Unstandard Tool prestige quest — 1 completion-bearing quest family built from 12 authored internal stages;
13. Drift Knots — 12;
14. Optional Elite Encounters — 8;
15. Community Disconnection Projects — 6;
16. Broken Standard Yard — 1 completion-bearing mastery complex built from 7 authored internal commissions.

Repeatable scores, ordinary currency/materials, random drops, mutually exclusive dialogue variants, personal bests, and replay optimization are non-completion-bearing.

### Superseded legacy literals

The following old planning literals are no longer authority anywhere they remain in older documents:
- 48 Resonance Faults -> **36**;
- 28 Pulse Shards -> **18**;
- 30 Micro-vaults -> **24**;
- Prestige quest `12 stages` as twelve global percentage items -> **one quest-family item**, with all 12 stages retained internally;
- Broken Standard Yard internal commissions as possible global items -> **one mastery-complex item**, with all 7 commissions retained internally.

Any older table or prose that conflicts with this addendum is mechanically stale and subordinate to Decisions #1–#16 until edited in place.

## Fault milestone reconciliation — K01 / K02

The 36-Fault track now owns exact implementation thresholds:

- `upgrade.cantor.field_memory` / K01 Field Memory: **6 reconciled Resonance Faults**;
- `upgrade.cantor.fine_fork` / K02 Fine Fork: **24 reconciled Resonance Faults**.

Rationale:
- 6/36 remains an unmistakably early broad-exploration milestone and preserves the existing tutorial cadence without making the reward immediate;
- 24/36 is exactly two-thirds of the track, making Fine Fork a genuinely late diagnostic mastery reward while leaving meaningful Fault work after acquisition;
- no implementation may retain old `30/48` assumptions.

## Drift Knot unlock reconciliation

The old fixed **13-Fault** Drift Knot unlock is superseded.

The authored Drift Knot hunt becomes eligible at **10 reconciled Resonance Faults**, plus its existing story/Line Skiff prerequisites.

Ten of thirty-six closely preserves the old intended first-quarter cadence while respecting the reduced Fault track. It is an eligibility threshold, not a completion requirement layered on top of the twelve Knot facts.

## Exact global aggregation

Stillring has **16 top-level completion buckets**. Each bucket contributes exactly **1/16 = 6.25%** of the global completion percentage.

Within a multi-item bucket, every canonical item in that bucket contributes an equal fraction of that bucket.

Examples:
- each Resonance Fault contributes `6.25 / 36` percentage points;
- each Repair Contract contributes `6.25 / 24`;
- each Record contributes `6.25 / 32`;
- each Community Project contributes `6.25 / 6`.

This is intentionally **not raw-ID weighting**. Thirty-six Faults do not deserve thirty-six times the global influence of the Broken Standard Yard merely because the exploration family contains more discrete authored entries.

### Main Story bucket

The Main Story bucket is completion-bearing as one route outcome:
- `0/1` before credits;
- `1/1` when the canonical story-complete fact settles.

Story chapter/beat progress may be displayed separately for orientation, but it does not subdivide the global 6.25% story bucket unless a future explicit story-completion authority changes this contract.

### Nested content / anti-double-counting

Nested anatomy is never promoted into extra global items unless explicitly listed as its own top-level category.

Locked examples:
- The Unstandard Tool stages 1–11 are internal progress; Stage 12/final settlement satisfies one prestige quest-family item;
- Broken Standard Yard commissions 1–7 persist independently for retry/resume, but only all-seven + final settlement satisfies one global mastery item;
- a Community Project prerequisite contract remains a Contract item because it is independently authored content, but the prerequisite relation itself creates no bonus completion item;
- an upgrade earned from a Contract can satisfy both its real Contract semantic ID and its real Upgrade semantic ID because those are two distinct authored outcomes; no third `reward source` completion ID is created;
- critical-path acquisition of a Pattern may satisfy the Pattern item and later Story completion may satisfy the separate Story route bucket; the story bucket is not a sum of those acquisitions.

## Percentage truth and rounding

Internally, completion is computed from exact rational bucket/item fractions or equivalent deterministic integer/rational arithmetic. Floating-point display rounding is never authoritative.

Player-facing global display:
- one decimal place, e.g. `73.4%`;
- category pages show exact `resolved / total` counts;
- **100.0% appears only when all sixteen buckets are fully satisfied and the story-complete fact is settled**;
- any mathematically incomplete state that would round upward is displayed at no more than **99.9%**;
- save/load/migration cannot change the percentage unless an authoritative completion fact or schema definition actually changes.

The UI may also offer a percentage-hidden presentation while preserving exact category ledgers.

## Known, unknown, and unresolved reporting

The ledger distinguishes at least:

1. **Undiscovered / not yet catalogued** — the player has not earned knowledge that this specific item exists;
2. **Known unresolved** — the item is known and still incomplete;
3. **Resolved** — authoritative completion predicate satisfied;
4. **Unavailable by current state** — known content exists but a legitimate story/world prerequisite is currently unmet;
5. **Audit mismatch** — development/save reconciliation detected contradictory or orphaned state; never presented to retail players as ordinary lore.

Early game may conceal exact item identity and even exact regional totals where discovery is part of exploration.

By Unringing, the completion network may reveal **category counts by region/subregion** for categories whose fiction/support network can reasonably know them. This turns memory burden into a reviewable record without dropping precise coordinates onto every secret.

## Completion-assist ladder

Completion help is progressive and bounded.

### Tier 0 — natural discovery
- authored world cues;
- journal entries for things already encountered;
- no automatic treasure-map behavior.

### Tier 1 — regional accounting
Once the relevant Refuge/courier/archive infrastructure is established, the journal may show remaining counts by category for that region, e.g. `Faults: 2 unresolved`, without revealing exact coordinates or undiscovered names.

### Tier 2 — authored physical hints
Late-game specialists/services may give a bounded clue tied to world language, route sector, environmental state, or known landmark.

Example form:
> “One unresolved fault remains downstream of the widow's ferry under high river load.”

### Tier 3 — accessibility / player-chosen stronger assistance
Supported accessibility/navigation settings may strengthen map or directional guidance. Using them never invalidates completion, rewards, achievements under Stillring's own authority, or mastery legitimacy.

### Route Listener boundary
The Route Listener remains a reward after all 12 Drift Knots. It does **not** help locate those twelve already-required Knots retroactively. Its valid function is post-hunt route-network service: on entering a road sector it may report whether that sector still contains an unresolved **route-class Fault** or incomplete courier service. It is not a universal collectible radar.

### D06 / Report the Drift boundary
The D06 community service may contribute late-game **regional/category accounting** where its fiction establishes a functioning report network. It may say that a region has unresolved work in a category and, where authored, identify a broad subregion/sector. It may not reveal every secret coordinate, hidden room entrance, or exact solution.

## Spoiler limits

The completion interface must not spoil:
- undiscovered quest titles whose names reveal future story states;
- unknown NPC survival/outcome states;
- exact hidden-room locations before the relevant discovery/help tier;
- Null Meridian solution order;
- alternate outcomes the current save did not choose merely to show a checklist.

Allowed spoiler-safe placeholders include category totals, broad region counts, and neutral entries such as `Unknown Contract` only after the save has legitimately unlocked that level of accounting.

The ledger reports **what remains**, not every possible narrative branch the player could have seen in another playthrough.

## Persistence ownership

The Completion Ledger is a derived system with a small persistent compatibility envelope.

Authoritative facts remain owned by their source systems:
- story progression;
- Quest/Contract state;
- World State / Refuges / Faults / Vaults / Community state;
- player progression / Pulse / Patterns / Upgrades;
- mastery / Trials / Yard;
- traversal / Drift Knots;
- encounter state / Elites;
- record archive.

The ledger may persist:
- `CompletionLedgerSchemaVersion`;
- stable semantic-ID discovery/visibility state where discovery itself is not owned elsewhere;
- migration aliases/tombstones required to interpret old saves;
- last successful reconciliation/audit metadata for diagnostics.

It must **recompute satisfaction from authoritative facts** on load rather than trusting a cached percentage.

## Versioning and migration

Implementation must use an explicit project custom version / schema version compatible with UE5.8 serialization practices.

Every schema-changing release must classify completion-ID changes as one of:
- unchanged;
- renamed with explicit alias migration;
- split with deterministic migration rule;
- merged with deterministic source-set rule;
- retired with explicit tombstone/non-bearing treatment;
- newly added with a documented compatibility policy.

Forbidden migration behavior:
- matching by display string;
- matching by actor path or map coordinate;
- silently deleting unknown IDs;
- awarding completion because an old percentage happened to be high enough;
- resetting the whole ledger because one category changed.

Migration is idempotent: loading/saving the same migrated state repeatedly yields the same semantic result.

## Corruption / mismatch audit behavior

Development builds and the System IDE must classify reconciliation problems rather than silently normalizing them.

Audit classes:
- **Missing source fact** — ledger/discovery references a semantic item whose authoritative owner has no valid state;
- **Orphaned source fact** — owner contains a completion-bearing semantic ID absent from the current taxonomy/migration table;
- **Contradictory fact** — mutually impossible source states are simultaneously asserted;
- **Duplicate semantic identity** — two authored objects claim one canonical completion ID;
- **Nested leakage** — an internal prestige stage/Yard commission incorrectly contributes global percentage;
- **Version mismatch** — save custom version requires a migration path that is missing;
- **Count mismatch** — authored category registry total differs from canonical shipping count.

Retail behavior must fail conservatively: do not manufacture 100%, duplicate permanent rewards, or destroy the save. Preserve recoverable data, surface a safe user-facing load/recovery error only when necessary, and retain diagnostics for development/support builds.

## Completion / World / Quest System IDE

The shared in-game System IDE must expose a Completion Ledger workbench with:
- all 16 canonical buckets and exact weights;
- registry count versus canonical count;
- every semantic item ID;
- source owner/system;
- discovered/known/resolved/unavailable state;
- authoritative predicate inputs;
- nested-parent relationship where applicable;
- global contribution and category contribution;
- current exact rational total and rendered percentage;
- K01/K02 and Drift Knot threshold state;
- active completion-assist tier and why it is available;
- save schema/custom version;
- migration aliases/tombstones applied;
- audit findings with owning system and repair guidance;
- a one-command **Canonical Missing-Item Audit**.

The workbench must support filtering by region, subregion, category, source system, known/unknown, resolved/unresolved, nested/global, and audit state.

## Required deterministic fixtures

1. empty/new-game ledger with no accidental completion;
2. one completion item in every multi-item category and exact fractional contribution check;
3. 35/36 Faults does not complete the Fault bucket;
4. K01 settles exactly at 6 Faults and never duplicates;
5. K02 settles exactly at 24 Faults and never duplicates;
6. Drift Knot hunt eligibility remains false at 9 Faults and true at 10 when story/Skiff gates are also valid;
7. prestige Stage 11 contributes no prestige global item; Stage 12 final settlement contributes exactly one;
8. Yard 6/7 contributes no mastery global item; 7/7 + settlement contributes exactly one;
9. prerequisite Contract + Community Project produce their two real semantic outcomes and no phantom prerequisite item;
10. accessibility-enhanced completion guidance changes no completion entitlement;
11. early undiscovered item remains spoiler-hidden while category accounting rules remain correct;
12. Unringing late-game regional count service reveals counts without exact coordinates;
13. Route Listener reports route-class unresolved service only after 12/12 Drift Knots;
14. save/load recomputes the same exact percentage from source facts;
15. old-ID rename migration maps once and remains idempotent;
16. orphan/duplicate/nested-leak audit is detected and does not manufacture progress;
17. mathematically incomplete value that would round to 100 displays 99.9%;
18. only fully satisfied 16/16 buckets display 100.0%;
19. post-credits pre-Null cleanup checkpoint preserves all completion facts consistently;
20. canonical missing-item audit returns exactly the intentionally omitted semantic IDs in a seeded fixture.

## Vertical-slice miniature completion test

Before production-scale content is trusted, a vertical slice must prove the ledger with a deliberately small but cross-system registry containing at least:
- one story-complete surrogate flag;
- two Contracts;
- one Setup/Payoff chain;
- one Refuge;
- three Faults;
- two Pulse Shards;
- one Pattern;
- one Tool Mastery Upgrade;
- one Skill Trial;
- two Micro-vaults;
- two Records;
- a three-stage miniature nested prestige quest that contributes one global item;
- two Drift Knot surrogates;
- one Optional Elite;
- one Community Project with a prerequisite Contract;
- a two-commission miniature Yard surrogate that contributes one global item.

The slice passes only if category weighting, nested-item exclusion, save/load, migration, assist tiers, unknown/known reporting, and the missing-item audit all behave exactly as this contract specifies.

## Red-team / rejection conditions

Reject the implementation if:
- global percentage is raw semantic-ID count divided by total IDs;
- Faults/Vaults/Records dominate the number simply through quantity;
- prestige stages or Yard commissions leak into global weighting;
- cached percentage can disagree with authoritative facts after load;
- 99.x rounds to displayed 100.0 while something remains;
- old 48/28/30 literals are used by runtime logic;
- K02 remains hardcoded at 30 Faults;
- Drift Knot unlock remains hardcoded at 13 Faults;
- late-game assistance becomes an always-on exact-coordinate radar;
- accessibility assistance invalidates completion;
- a renamed semantic ID loses legitimate completion with no migration;
- duplicate/orphaned IDs are silently ignored;
- the System IDE cannot explain why an item is or is not counted.

## Research basis

Fresh review used:
- the locked Stillring Completion Decisions #1–#15 and their provenance addenda;
- Microsoft Xbox Accessibility Guidelines on objective clarity, reviewable progress, configurable difficulty/accessibility, and consistent UI context;
- Epic's Unreal Engine 5.8 documentation on custom/object-level versioning and serialization compatibility;
- the existing Stillring save/world-state, quest, traversal, mastery, and System IDE contracts.

These references inform accessibility, persistence, and reporting problems only. Stillring's taxonomy, weights, thresholds, fiction, semantic IDs, UI behavior, and implementation contract remain original project authority.

## Approval

**APPROVED / LOCKED by the owner on 2026-09-05.**

### Final locked statement

> **Stillring's 100% percentage is category-balanced across sixteen equal 6.25% buckets and derived from authoritative semantic facts. The locked totals are 36 Faults, 18 Pulse Shards, 24 Micro-vaults, 24 Contracts, 12 Setup/Payoff chains, 11 Refuges, 32 Records, 9 Patterns, 14 Upgrades, 9 Trials, one 12-stage prestige quest-family item, 12 Drift Knots, 8 Elites, 6 Community Projects, one seven-commission Yard item, and one completed story route. K01 settles at 6 Faults, K02 at 24, and Drift Knot eligibility at 10 plus its existing story/Skiff gates. Nested stages never leak into global weight; 100.0% is shown only for a truly complete save; late-game assistance exposes bounded counts/hints rather than a universal radar; accessibility assistance has equal authority; and the Completion Ledger recomputes from versioned source facts with explicit migration and audit behavior.**

## Issue #8 closure condition

Design authority is coherent and complete under Decisions #1–#16. Issue #8 may close once the mechanically stale literals in docs 10–14 are edited to reflect this authority and the decision register/handoff are updated. Runtime UE5.8 implementation and human acceptance remain separate, unverified work.

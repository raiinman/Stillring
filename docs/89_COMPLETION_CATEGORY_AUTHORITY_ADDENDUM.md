# 89 — Completion Decision #1 — Completion-Bearing Category Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #1 — which authored categories truly own 100%, what each category measures, and how that authority maps to persistent semantic state

## Decision question

Which proposed categories in `docs/10_COMPLETION_MODEL.md` are real shipping 100%-bearing requirements, and what does completion mean for each without turning Stillring into an icon vacuum, grind ledger, or imitation of another game's checklist?

## Research basis

Fresh research for this decision focused on completion-system behavior rather than copying another game's category names or counts.

Relevant shipped-game lessons:
- Nintendo's current Zelda Notes explicitly separates achievement progress by elements such as shrines and Koroks and provides stronger navigation assistance for players who want full completion. The useful lesson is category legibility and late assistance, not the Zelda category structure itself.
- Nintendo's own Breath of the Wild completion guidance also shows the failure mode of a very large repeated discovery track dominating player perception of "100%." Stillring's 48 Faults therefore cannot become the semantic definition of completion merely because they are numerous.
- Published analysis of Marvel's Spider-Man's district tracker shows why regional progress chunks are useful: they create understandable intermediate goals and let players choose whether to clear by region or activity type. The risk is obvious too: if exposed too aggressively, the tracker can turn exploration into district-cleaning behavior.
- Across completion-heavy action/adventure games, the strongest practical distinction is between authored finite outcomes and repeatable/open-ended activity. Stillring already rejects random drops, repeated grind, arbitrary currency accumulation, and score optimization beyond one authored mastery threshold; this decision preserves that boundary.

These references inform design problems only. Stillring's categories, semantics, fiction, counts, IDs, presentation, and rewards remain project-owned.

## Locked philosophy

> **100% counts authored meaning, not map debris.**

A completion-bearing entry must have:
1. a finite authored semantic identity;
2. one clear completion predicate owned by gameplay authority;
3. a deterministic persistence record;
4. no random-drop or repeatable-grind requirement;
5. a reason to exist beyond increasing a percentage;
6. a player-auditable late-game status;
7. a clean migration story under the locked save contract.

Raw POI discovery, incidental dialogue, ordinary materials, repeatable score optimization, ambient secrets with no authored completion contract, and random drops do not become 100%-bearing merely because the game can track them.

## Shipping category authority

| Category | 100% bearing? | Canonical completion measure | Scope |
|---|---|---|---|
| Main story | YES | **Resolution** — credits reached through the canonical story route | Global |
| Local Repair Contracts | YES | **Resolution** — each contract reaches any legitimate authored resolved state | Regional + global rollup |
| Cross-state Setup/Payoff chains | YES | **Authored outcome** — later payoff state reached; no preferred moral branch required | Regional + global rollup |
| Bellwright Refuges | YES | **Discovery + activation/resolution** — refuge becomes a functioning known service/record, not merely map-revealed | Regional + global rollup |
| Resonance Faults | YES | **Resolution** — each authored fault is diagnosed/reconciled according to its finite contract | Regional + global rollup |
| Pulse Shards | YES | **Acquisition** — each unique authored shard is acquired once | Regional + global rollup |
| Cantor Patterns | YES | **Acquisition/learning** — each authored operational pattern is learned and cataloged | Global catalog |
| Tool Mastery Upgrades | YES | **Acquisition** — each finite authored mastery upgrade is permanently earned | Global by tool |
| Skill Trials | YES | **Mastery threshold** — first clear at the authored completion threshold; later score/time improvement does not count | Regional + global rollup |
| Micro-vaults / maintenance cavities | YES | **Resolution** — each authored compact challenge reaches its completion state; entering/discovering alone is insufficient | Regional + global rollup |
| Testimonies / field records | YES | **Acquisition** — every shipping authored record is obtained; set-level presentation may group them | Regional/set + global rollup |
| Prestige craft quest — The Unstandard Tool | YES | **Resolution** — Stage 12 complete and Freehand Frame assembled | Global staged quest |
| Drift Knot traversal hunt | YES | **Resolution** — each deterministic authored target is reconciled | Regional + global rollup |
| Optional elite encounters | YES | **Resolution** — each unique authored elite is cleared once | Regional + global rollup |
| Community disconnection projects | YES | **Resolution** — each of six community projects reaches a legitimate complete state | Regional + global rollup |
| Broken Standard Yard mastery complex | YES | **Mastery threshold** — authored synthesis threshold cleared once | Global |
| Repeatable score improvement | NO | Supporting record only | Activity-local |
| Currency / ordinary materials | NO | Supporting economy state only | Inventory/economy |
| Random drops | NO | Never completion authority | N/A |
| Ordinary map POIs / ambient discovery | NO | May be journal/map support, never percentage authority unless separately promoted through explicit change control | Regional support only |
| Dialogue variants / mutually exclusive branch variants | NO | Narrative history/supporting state only | Quest/story |

## Why all sixteen authored shipping categories remain 100%-bearing

The existing sixteen finite authored categories survive this review because each has a distinct gameplay/narrative job and a deterministic terminal predicate:
- story resolves the journey;
- contracts/community projects resolve people-and-place problems;
- setups/payoffs prove persistent causality;
- refuges establish useful world infrastructure;
- Faults/Pulse/Vaults create exploration/revisit work with different verbs and rewards;
- Patterns/Upgrades represent learned capability;
- Trials/Yard represent mastery rather than collection;
- Records deepen history and unlock systemic context;
- Prestige/Drift/Elites provide authored optional long-form or high-skill synthesis.

However, **retaining the categories is not an endorsement of every current count**. Counts, density, weighting, access gates, staged rewards, and final percentage math remain later Issue #8 decisions and must be individually justified.

## Category ownership and persistence

The locked save/world-state contract remains authoritative:
- **Completion Ledger** owns completion-bearing semantic facts.
- Other systems may own the gameplay truth that causes completion (Quest/Story, Inventory/Tool Progression, Encounter State, World State, etc.).
- Completion Ledger records/recomputes the completion consequence from settled semantic transactions; it does not duplicate or contradict another owner's gameplay fact.
- A completion-bearing entry uses a stable project-owned semantic identity and survives display-name, map, Blueprint, package, or representation changes.
- Percentage/category summaries are **derived**, never duplicated canonical truth.

Examples:
- a Tool Mastery Upgrade's ownership lives in Inventory/Tool Progression; Completion Ledger derives that its completion ID is satisfied after the upgrade transaction settles;
- an elite's encounter result lives in Encounter State; Completion Ledger derives the elite completion record from the settled unique-clear fact;
- a Repair Contract's authored resolution lives in Quest/Story State; Completion Ledger counts whichever legitimate resolved outcome was reached.

## Global versus regional authority

Regional progress is an **audit view**, not a second source of truth.

Categories with authored regional allocation expose regional completed/total summaries where useful. Global-only categories expose catalog/stage/global state. No entry is persisted twice just to support both screens.

Late-game regional summaries may reveal outstanding counts without revealing exact coordinates. Earlier presentation remains intentionally less checklist-like under `docs/10` completion-assist policy.

## Anti-grind / anti-busywork hard rules

Reject any future content-budget proposal that makes 100% require:
- random spawn/drop luck;
- arbitrary enemy kill totals;
- repeated currency/material farming after meaningful purchases are complete;
- repeatable score/time optimization after an authored mastery clear;
- opening every ordinary container;
- exhausting every dialogue branch;
- collecting procedurally generated or infinitely repeatable content;
- mutually exclusive outcomes on one save;
- external websites to identify what category remains.

If a finite authored entry proves boring in playtest, cut/rework the entry and update the content budget. Do not keep bad content to protect a round number.

## IP distinction

Stillring does not define 100% as "find all equivalents of shrines/hearts/Koroks/dungeons." Its completion grammar is built around:
- repair resolution;
- remembered-space revisit work;
- persistent setup/payoff causality;
- community disconnection projects;
- bellwright operational knowledge;
- Hush/Waking historical reinterpretation;
- authored mastery thresholds;
- deterministic regional infrastructure and world consequences.

Comparative adventure games may teach progress-legibility and auditability problems. Their category expression, object identities, exact counts, reward cadence, map presentation, and completion formula are not authority.

## Completion / System IDE requirements introduced by Decision #1

The eventual Completion workbench must be able to inspect:
- every completion-bearing category and semantic entry ID;
- canonical measure type: `Resolution`, `Acquisition`, `DiscoveryActivation`, `AuthoredOutcome`, or `MasteryThreshold`;
- owning gameplay domain and source fact;
- Completion Ledger satisfied/unsatisfied state;
- regional/global rollups as derived views;
- why an entry is or is not satisfied;
- duplicate/orphan/missing semantic IDs;
- category records that incorrectly depend on random/repeatable state;
- completion summary recomputation from authoritative owner snapshots;
- migration behavior when category/item taxonomy changes.

Named fixtures must include at least:
1. fresh save / zero optional completion;
2. one resolved item from each measure family;
3. legitimate alternate Repair Contract outcome that still counts;
4. setup recorded but payoff not reached;
5. trial attempted but below mastery threshold;
6. refuge discovered but not yet activated/resolved;
7. repeatable high score that does **not** change 100%;
8. completion recomputation after save/load;
9. old taxonomy fixture migrated after a controlled category/item change;
10. 99%-style missing-entry fixture whose exact unsatisfied semantic ID is explainable in Development builds.

Shipping excludes developer semantic-ID inspection, arbitrary completion mutation, fixture injection, raw ownership diagnostics, and any external model/API dependency.

## Failure cases / red-team

### One large category dominates perception
Faults have more IDs than any other single exploration category. Their raw count may not determine percentage weight by simple item count. Percentage weighting remains a later decision.

### Discovery accidentally equals completion
Refuges and Vaults explicitly reject map reveal / doorway entry as sufficient completion when their authored contract requires activation/resolution.

### Branch choice blocks 100%
Repair Contracts and Setup/Payoff chains count legitimate authored resolution, not a preferred branch.

### Inventory duplicates completion truth
Upgrades/Pulse ownership remains under progression/inventory authority; Completion Ledger derives satisfaction rather than becoming another inventory database.

### Completion UI becomes an icon vacuum
Regional/category counts may strengthen late, but exact-coordinate assistance is separately governed by completion-assist policy and accessibility. Decision #1 does not authorize always-on map pin saturation.

### Taxonomy changes break old saves
Released taxonomy evolution must use the already-locked explicit migration framework. Removed/split/merged completion IDs require deterministic disposition; earned durable entitlements are not silently erased.

## Acceptance tests for this decision

Design/implementation must eventually prove:
- every 100%-bearing entry belongs to exactly one approved category;
- every approved category has exactly one completion measure type;
- every entry has a stable semantic ID;
- no random/repeatable-supporting record can increase 100%;
- alternate legitimate quest resolution can satisfy the same authored completion obligation;
- regional/global summaries recompute from the same underlying semantic entries;
- save/reload/migration preserves or deterministically translates completion meaning;
- Development IDE can explain any unsatisfied entry without relying on display strings or object paths.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring's 100% is a finite ledger of authored semantic outcomes. Categories count resolution, acquisition, discovery-plus-activation, authored payoff, or mastery thresholds; raw POIs, random drops, repeatable grind, currency, dialogue exhaustion, and branch perfection never count. Regional/global progress are derived audit views over one Completion Ledger, not competing truth.**

## Next decision

Completion Decision #2 — **Resonance Fault authority: target count, regional density, access gates, staged rewards, and whether 48 remains justified.**

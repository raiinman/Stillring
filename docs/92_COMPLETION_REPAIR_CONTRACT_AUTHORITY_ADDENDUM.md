# 92 — Completion Decision #4 — Local Repair Contract Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #4 — Repair Contract target count, scope, pacing, resolution semantics, rewards, persistence, accessibility, IDE, and anti-fetch-quest constraints

## Decision question

Does the current 24-contract plan earn its place in a roughly 20–30 hour authored adventure, and what separates a real Stillring Repair Contract from generic side interaction, a cross-state Setup/Payoff chain, or a Community Project?

## Fresh research conclusion

**Keep the shipping target at 24 Local Repair Contracts.**

Unlike the old Fault and Pulse counts, the 24-contract ledger is not merely a numeric placeholder: C01–C24 are already individually authored around named people, local infrastructure, region-specific work, later consequences, and distinct mechanical/social problems. The current regional taper — 5 / 4 / 4 / 4 / 3 / 2 / 2 / 0 — also matches the desired pacing: dense human-scale work early, fewer but more integrated contracts as the plot and systemic burden increase.

Current Nintendo adventure design provides a useful high-level comparison: optional quests can unlock meaningful systems/services rather than paying only currency, while smaller errands can exist as light texture. Stillring intentionally draws a harder boundary than that broad model: **completion-bearing Repair Contracts are the authored substantial tier; ordinary errands/interactions remain non-bearing unless they genuinely meet this contract.**

## Locked philosophy

> **A Repair Contract starts with somebody's real problem and ends with a changed local reality.**

The mechanic is bellwright work in service of a person/community problem. The NPC is not a vending machine attached to a puzzle, and the puzzle is not arbitrary busywork attached to dialogue.

## Shipping target — 24

The current 24-contract target is **CONFIRMED**.

Canonical regional allocation remains:

| Region / phase | Contracts |
|---|---:|
| Brindle / Cairnspire / First Circuit | 5 |
| Rootmere | 4 |
| Saltreach | 4 |
| Emberstep | 4 |
| High Aerie | 3 |
| Mireglass | 2 |
| Cairnfall | 2 |
| Still-Cairn / Null Meridian | 0 |
| **Total** | **24** |

Why no final-region contracts: the late game already carries community projects, synthesis/mastery work, unresolved earlier relationships, and finale pressure. Null Meridian should not introduce fresh neighborhood errands merely to preserve regional symmetry.

## Critical-path versus optional split

Two existing contracts are explicitly canonical critical-path obligations and therefore count automatically when the story reaches their resolved state:
- **C02 — Twelve Minutes Missing**;
- **C06 — The Root That Isn't Sick**.

The remaining **22 are optional completion-bearing contracts**, even when strongly integrated with regional story, later unlocks, credits, or community projects.

A future story revision may promote/demote a contract only through explicit coordinated story/completion change control. Implementation must not infer "mandatory" merely because a contract gates a useful optional reward or sits near a main-route objective.

## Pacing budget

Twenty-two optional contracts across a 20–30 hour game is acceptable only because they are distributed and mostly compact.

Production target:
- **standard contract:** roughly 8–15 minutes of active authored play once accepted;
- **deep contract:** roughly 15–25 minutes, reserved for contracts with meaningful multi-stage investigation, traversal, or relationship consequence;
- **light contract:** roughly 5–8 minutes when the value is observation/choice/local texture rather than mechanical complexity.

Hard guardrail: no more than roughly one third of the optional set should become deep 15–25 minute contracts. If production estimates push the 22 optional contracts toward a second campaign's worth of content, cut/recombine weak contracts rather than inflating the 20–30 hour target.

## What qualifies as a Repair Contract

A completion-bearing Repair Contract must contain all of:
1. a named person, group, or locally legible community need;
2. a concrete infrastructure/material/signal/access problem;
3. at least one meaningful player action beyond dialogue/menu selection;
4. evidence/constraints that make the solution understandable in-world;
5. a finite authored resolved state;
6. a local consequence that can be observed, used, remembered, or referenced later;
7. a reward/consequence package that makes sense for the work rather than generic loot.

### Not a Repair Contract — ordinary side interaction
A short conversation, favor, visual gag, ambient help, small delivery, or ordinary-life beat can be valuable without becoming completion-bearing. `docs/story/17_SIDE_INTERACTION_REBALANCE.md` remains authority that not every interaction receives percentage/reward/stat progression.

### Not a Repair Contract — Setup/Payoff chain
A Setup/Payoff chain's defining completion grammar is an earlier action whose later changed-world consequence must be reached. A Repair Contract may **feed** a setup, but the contract completes when its local work reaches a legitimate resolution; the later payoff is a separately tracked obligation.

### Not a Repair Contract — Community Project
A Community Project is a major regional Unringing-scale collective disconnection effort requiring multiple prior systems/relationships. It is not merely a large side quest and does not absorb ordinary contracts into one mega-objective.

## Resolution semantics

Completion requires an authored `Resolved` outcome, not a preferred moral answer.

Each contract defines:
- `Available`;
- `Accepted` where acceptance is explicit/meaningful;
- authored in-progress semantic stages;
- one or more legitimate terminal `Resolved.<outcome>` states;
- optional `Failed/Closed` only where the fiction genuinely permits an irreversible non-completing outcome.

### No morality lock
If a contract offers multiple legitimate solutions, **all legitimate authored resolved outcomes satisfy the one contract completion obligation**. Credits/world consequences may differ.

### Missability rule
Ordinary player choice must not permanently make 100% impossible without clear advance warning and an intentional project-level reason. Prefer alternate later resolution/recovery over silent missability.

A contract may become unavailable because the world changes, but if it is required for 100% there must normally be one of:
- a changed-world version of the work;
- a recovery/payoff route;
- an explicit pre-lock warning when the missability is meaningful enough to justify it.

No contract quietly disappears because an NPC streamed out, a story phase changed, or the player walked past the wrong trigger.

## Reward discipline

A contract's best reward is often changed access, service, relationship, testimony, local world state, later option, or bespoke component — not a universal stat pickup.

Hard rules:
- **Pulse Shards may not become the default Repair Contract reward.** After the 28→18 Shard reconciliation, retain Shards only where the fiction/source is especially strong.
- currency/materials may supplement but cannot be the only reason a completion-bearing contract exists;
- no random reward tables;
- no major critical-path verb is awarded by an optional contract;
- bespoke access/services/pattern clues/relationship consequences are preferred when appropriate;
- one contract should not redundantly pay every progression currency/system.

## Anti-fetch-quest rule

"Bring X ordinary things to NPC Y" is not sufficient gameplay for a completion-bearing Repair Contract.

A transport/material task can qualify only when the interesting problem is the transport/material constraint itself — load, route, state, timing, fabrication, diagnosis, social consequence, or world condition — and the player meaningfully engages that problem.

Reject:
- arbitrary kill quotas;
- generic gather-N chores;
- repeated courier loops with no route/mechanical change;
- dialogue-only errands dressed as technical work;
- copy/paste repair minigames;
- contracts that repeat the central thesis without adding human/local specificity.

## Narrative variety requirement

The 24-contract set must preserve the existing side-interaction rebalance: not every contract exists to say "centralization bad."

Across the set, production review should maintain a mixture of:
- practical repair;
- labor/institutional friction;
- family/memory;
- local expertise;
- safety tradeoffs;
- grief/ritual;
- teaching/apprenticeship;
- route/access;
- evidence/history;
- ordinary community usefulness;
- disagreement where neither answer is a morality meter.

If two contracts use the same mechanical problem **and** the same emotional/thematic function, one should be reworked or cut.

## Persistence ownership

Quest / Story State owns each contract's durable semantic stage/outcome.

Completion Ledger derives satisfaction of `contract.<region>.<slug>` only after the Quest/Story transaction settles into a legitimate resolved outcome.

Rules:
- stable semantic IDs, never display strings/Actor paths;
- one contract completion obligation regardless of legitimate branch outcome;
- rewards/world facts settle transactionally with their authoritative owners before autosave snapshot;
- reload/retry cannot duplicate one-shot contract rewards;
- regional/global completion summaries derive from the same contract IDs;
- migration maps renamed/split/merged/retired contracts explicitly.

## Player-facing auditability

Early game:
- journal shows known/accepted contracts and meaningful local clues;
- undiscovered optional work does not need to appear as a giant map checklist.

Late game / Unringing:
- regional contract completed/total counts become auditable;
- Bellwright/Tessa/community records can point toward an unresolved person/place/subregion;
- stronger accessibility assistance may show clearer map guidance;
- no external wiki is required to learn which completion-bearing contract remains.

Branch outcome details may remain visible in journal/history without implying one is the "correct" completion state.

## Accessibility

Contracts may not require inaccessible evidence with no alternative path. Critical information based on audio pitch, color, fine visual texture, rapid timing, or dense text must have appropriate equivalent presentation/assist.

Dialogue-heavy contracts need:
- readable objective recap;
- conversation log/subtitle support consistent with project accessibility;
- clear distinction between flavor dialogue and actionable evidence;
- no timed dialogue-selection pressure unless explicitly justified and accessible.

## Contract / Completion System IDE

The development workbench must expose:
- contract semantic ID / region;
- current Quest/Story semantic state;
- legitimate terminal outcomes;
- completion satisfied state and reason;
- required/optional story classification;
- prerequisite/gate facts;
- source/reward transactions and owning domains;
- branch chosen / branch availability;
- missability/recovery policy;
- downstream setup/community/credits references;
- duplicate/missing/orphan ID validation;
- regional/global derived counts.

Required fixtures:
1. unaccepted optional contract;
2. accepted/in-progress contract;
3. each legitimate branch outcome counts;
4. critical-path C02/C06 auto-count behavior;
5. changed-world recovery route for a pre-change unresolved contract;
6. one-shot reward survives save/load without duplication;
7. contract feeds Setup/Payoff but completes independently;
8. contract prerequisite to Community Project without conflating their completion IDs;
9. accessibility alternate evidence path;
10. 23/24 late audit fixture that explains the missing contract.

## Red-team / rejection conditions

Reject a contract if:
- the NPC could be removed and nothing meaningful about the activity changes;
- the player's only substantive action is collecting generic quantity X;
- the only reward is percentage/currency;
- it silently vanishes and bricks 100%;
- one moral branch counts and another legitimate authored branch does not;
- it exists only to restate the main thesis;
- it duplicates another contract's mechanics/theme with only names/biome changed;
- it should actually be a small ordinary interaction, Setup/Payoff chain, Fault, Vault, or Community Project;
- production cost threatens the project's 20–30 hour target without corresponding value.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring keeps 24 Local Repair Contracts: 2 critical-path and 22 optional. A completion-bearing contract is named human/community work with meaningful bellwright action and an observable local resolution; legitimate branches all count, generic chores do not, rewards stay bespoke, and optional work must remain auditable without becoming an icon checklist.**

## Next decision

Completion Decision #5 — **Micro-vault authority: validate the 30-vault target, regional density, 1–5 minute scope, reward overlap, gating/revisit rules, and anti-reskin constraints.**

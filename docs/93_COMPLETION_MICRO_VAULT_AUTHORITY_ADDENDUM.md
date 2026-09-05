# 93 — Completion Decision #5 — Micro-vault Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #5 — Micro-vault target count, scope, regional density, gating, rewards, completion semantics, accessibility, IDE, and anti-reskin constraints

## Decision question

Does Stillring need 30 completion-bearing Micro-vaults, and what keeps these compact spaces from becoming repeated cave icons or one-room reward boxes?

## Fresh research conclusion

**Reduce the shipping target from 30 to 24 Micro-vaults.**

The existing 30-entry ledger contains strong authored premises, but the total completion taxonomy is already broad. A 30-vault category layered over 36 Faults, 24 Contracts, 18 Pulse Shards, records, trials, elites, refuges, setup/payoffs, community projects, and prestige content creates too much pressure to populate every corner with a named activity.

Comparative research supports two useful design lessons:
- Nintendo's Tears of the Kingdom makes caves numerous, discoverable world features and even provides map-state cues for explored caves. That works in a much larger exploration sandbox; Stillring's tighter 20–30 hour authored game should not inherit that density simply because caves are enjoyable. citeturn692805search3turn692805search0
- Open-world design analysis distinguishes exploration-led spaces from activity-led maps where visible tasks pull the player around. Stillring's Micro-vaults should reward curiosity and remembered affordances rather than turn Orra into a checklist of pocket dungeons. citeturn692805search10

## Locked philosophy

> **A Micro-vault is one strong compact idea, not a small dungeon quota.**

## Shipping target — 24

The former 30 target is **SUPERSEDED**.

Canonical regional allocation:

| Region / phase | Micro-vaults |
|---|---:|
| Brindle / Cairnspire / First Circuit | 5 |
| Rootmere | 4 |
| Saltreach | 3 |
| Emberstep | 3 |
| High Aerie | 3 |
| Mireglass | 2 |
| Cairnfall | 2 |
| Still-Cairn / Null Meridian | 2 |
| **Total** | **24** |

The reduction deliberately cuts density where repeated compact spaces would compete with contracts/Faults and late story urgency.

## Scope boundary — 1 to 5 minutes

A Micro-vault's **core authored challenge** should normally take about **1–5 minutes** once the player has reached/entered it and understands the relevant verb.

That timing excludes:
- travel to discover the vault;
- optional observation before entry;
- player experimentation that naturally runs longer;
- accessibility pacing.

Hard rule: if a vault routinely requires multiple rooms, several combat waves, extended narrative scenes, or 8–15 minutes of intended core play, it should be reclassified as a larger side-space/quest/trial rather than stretching the Micro-vault category.

## What qualifies

A completion-bearing Micro-vault must provide:
1. one compact authored spatial/mechanical proposition;
2. a legible fiction as maintenance cavity, service pocket, sealed workspace, route void, structural chamber, archive niche, etc.;
3. a meaningful entry/access condition or discovery clue;
4. a finite solved state;
5. a reward or world-use payoff proportionate to its size;
6. a distinct enough idea that its identity survives without relying on a unique art skin alone.

### Vault versus Fault
A **Fault** is an observable world defect whose grammar is diagnose → reconcile. A **Micro-vault** is a contained space whose grammar is gain access → understand one compact spatial/mechanical idea → solve/clear it.

A Vault may contain evidence of a Fault or reward a clue, but it cannot count as both completion IDs for doing one identical action unless two genuinely separate authored obligations exist.

### Vault versus hidden cache
A hidden chest/material stash with no authored challenge is **not** a completion-bearing Micro-vault. Ordinary caches may exist without percentage weight.

### Vault versus Trial
A Skill Trial evaluates execution/mastery against an authored threshold. A Vault asks for understanding/access/solution, not performance scoring.

## Variation requirements

The 24-vault set must be reviewed as a **matrix of ideas**, not only a list of locations.

Required family coverage across the set should include a healthy mixture of:
- route/access geometry;
- load/tension manipulation;
- pressure/fluid interaction;
- thermal/material-state use;
- traversal sequencing;
- Hush/Waking reinterpretation;
- observation/diagnostic clue use;
- multi-tool combination;
- mechanical timing without twitch/QTE dependence;
- world-state/history consequence.

Hard constraints:
- no single puzzle template may account for more than **4 of 24** vaults without explicit review;
- no two vaults in the same region may be near-identical templates with only art/coordinates changed;
- a vault needs a distinct one-sentence design proposition in the content ledger;
- "same room, different switch order" is one template, not several ideas.

## Discovery and gating

Micro-vaults support remembered-space exploration.

Each vault declares:
- semantic ID;
- region;
- earliest observable phase;
- earliest accessible/solvable phase;
- required verb/state;
- discovery cue;
- solution family tag;
- completion predicate;
- reward class.

At least half of verb-gated vaults should be **visible, hinted, or physically suggested before they are solvable**.

New verbs do not reveal every newly accessible vault on the map. The player is encouraged to remember odd architecture, sealed service spaces, unreachable apertures, flooded pockets, echo contradictions, and other physical promises.

Late completion assistance may narrow missing vaults to subregion and eventually stronger map guidance; secrecy is not protected at the expense of a miserable 99% cleanup.

## Reward discipline

A Micro-vault reward must fit a 1–5 minute authored challenge and should reinforce exploration without becoming mandatory progression.

Preferred reward classes:
- bespoke upgrade component;
- testimony/record;
- Fault clue or route knowledge;
- prestige component/clue;
- useful deterministic material cache;
- occasional Pulse Shard where especially justified under the reduced 18-Shard budget;
- shortcut/service/world interaction where appropriate.

Hard rules:
- no random loot table as the reason to clear a completion-bearing vault;
- no major critical-path verb;
- no mandatory combat power needed to beat later story encounters;
- no Pulse Shard in every third hole simply because a universal reward is convenient;
- a reward may overlap another completion category only when the player performs two genuinely distinct authored obligations or the acquisition itself is the separate completion fact.

## Completion semantics and persistence

A Micro-vault completes when its authored compact challenge reaches `Resolved/Cleared`, **not** when the entrance icon is discovered or the player crosses the doorway.

World State owns persistent physical resolution where relevant; Quest/Content state may own authored puzzle completion depending on implementation boundary. Completion Ledger derives `vault.<region>.<slug>` from the settled authoritative solved fact.

Rules:
- stable semantic ID; no map/path/Actor identity;
- reopening/reloading a solved vault reconstructs its resolved world state appropriately;
- one-shot rewards cannot duplicate after save/load/retry;
- discovered, entered, solved, and reward-claimed are distinct semantic facts when the design needs them;
- completion summaries derive from solved IDs, never raw map exploration percentage;
- removed 30→24 IDs receive explicit migration/retirement dispositions before released save compatibility.

## Accessibility

Vaults may not make their single core idea dependent solely on:
- color discrimination;
- pitch recognition;
- tiny visual detail;
- spatial audio;
- controller vibration;
- rapid mashing or inaccessible timing.

Where the puzzle uses those channels, provide an equivalent readable representation/assist without replacing the underlying relationship with a "solve" button by default.

Navigation/camera/collision inside compact spaces must obey the locked locomotion/camera cramped-space rules; a clever puzzle does not excuse fighting the camera.

## Late auditability

Early:
- undiscovered vaults can remain unlisted/unknown;
- discovered entrances may be journaled without auto-solving their gate.

Late / Unringing:
- regional vault completed/total counts become available;
- local specialists/refuge records can give subregion/physical clues;
- accessibility assist may escalate to explicit map-area guidance;
- external websites are not required to identify a missing completion-bearing vault.

## Vault / Completion System IDE

The development workbench must expose:
- vault semantic ID / region;
- discovery / entered / resolved state;
- earliest observable/solvable gates;
- solution family/template tag;
- owning gameplay/world fact;
- Completion Ledger reconciliation;
- reward class/transaction and claim state;
- expected core-play duration class;
- accessibility evidence channels;
- duplicate/template-density validation;
- regional/global derived summaries.

Required fixtures:
1. visible but inaccessible vault;
2. discovered but unsolved vault;
3. solved vault with reward unclaimed where supported;
4. resolve → save/load with reconstructed state;
5. duplicate reward attempt rejected;
6. Hush/Waking reinterpretation vault;
7. template-density validator failure;
8. compact-space camera/collision test;
9. accessibility alternate cue path;
10. 23/24 late audit fixture.

## Red-team / rejection conditions

Reject a Micro-vault if:
- it is a chest behind a cracked wall with no real authored idea;
- it is a reskinned copy of an existing vault;
- its intended core challenge regularly exceeds Micro-vault scope;
- its reward is the only reason it exists;
- it should instead be a Fault, Trial, Contract, or ordinary hidden cache;
- map icon reveal is the primary intended discovery from the start;
- it depends on a single inaccessible sensory channel;
- it exists only to keep the old count at 30.

## Documentation reconciliation debt

`docs/10`, `docs/11`, and `docs/12` still contain the superseded **30** target and all 30 current vault IDs. `docs/93` is immediate detailed authority for a **24**-vault shipping budget. During Issue #8 cumulative reconciliation, choose the strongest 24 existing concepts, update regional totals/rewards together, and deterministically retire/remap the six removed IDs.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring ships 24 Micro-vaults. Each is a compact 1–5 minute authored space built around one strong idea, discovered through the world rather than an activity-map flood. Vaults complete on resolution, not doorway discovery; repeated templates and reward-only holes are cut rather than preserved for count.**

## Next decision

Completion Decision #6 — **Testimony / field-record authority: validate the 32-record target, set structure, acquisition grammar, systemic/story payoff, readability/accessibility, and anti-lore-note clutter.**
